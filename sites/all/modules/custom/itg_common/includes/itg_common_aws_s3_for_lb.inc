<?php

/**
 * @file
 * ITG Videogallery inc.
 */
require 'vendor/autoload.php';

use Aws\S3\S3Client;
use Aws\ElasticLoadBalancingV2\ElasticLoadBalancingV2Client;
use Aws\ElasticLoadBalancing\ElasticLoadBalancingClient;
use Aws\Ec2\Ec2Client;

/**
 * 
 * @return $data_video array
 */
function insert_private_ip_in_varnish() {

  $varnish_type = variable_get('varnish_aws_type', '');
  if ($varnish_type == 'target') {
    $client = new ElasticLoadBalancingV2Client(array(
      'version' => 'latest',
      'region' => variable_get('varnish_aws_region', ''),
      'credentials' => array(
        'key' => variable_get('varnish_aws_access_key', ''),
        'secret' => variable_get('varnish_aws_secret_key', '')
      )
    ));
    $result = $client->describeTargetHealth(array(
      'TargetGroupArn' => variable_get('varnish_aws_target_id', ''),
    ));
  
    $instance = array();
    if (!empty($result['TargetHealthDescriptions'])) {
      foreach ($result['TargetHealthDescriptions'] as $target) {
        
        if (strtolower($target['TargetHealth']['State']) == 'healthy') {
          $instance[] = $target['Target']['Id'];
        }
      }
    }
    
    if (!empty($instance)) {
      try {
        $clientEC = new Ec2Client(array(
          'version' => 'latest',
          'region' => variable_get('varnish_aws_region', ''),
          'credentials' => array(
            'key' => variable_get('varnish_aws_access_key', ''),
            'secret' => variable_get('varnish_aws_secret_key', '')
          )
        ));
        $resultEC = $clientEC->describeInstances(array(
          'InstanceIds' => $instance,
        ));
        $ec_private_ip = array();
        if (!empty($resultEC['Reservations'])) {
          foreach ($resultEC['Reservations'] as $ec_details) {
            if (isset($ec_details['Instances']) && !empty($ec_details['Instances'])) {
              foreach ($ec_details['Instances'] as $ec_instance) {
                if (isset($ec_instance['NetworkInterfaces']) && !empty($ec_instance['NetworkInterfaces'])) {
                  foreach ($ec_instance['NetworkInterfaces'] as $ec_network_id) {
                    $ec_private_ip[] = $ec_network_id['PrivateIpAddress'] . ':6082';
                  }
                }
              }
            }
          }
        }
      }
      catch (Exception $e) {
        echo 'Caught exception: ', $e->getMessage(), "\n";
      }
    }
  }
  else {


    $client = new ElasticLoadBalancingClient(array(
      'version' => 'latest',
      'region' => variable_get('varnish_aws_region', ''),
      'credentials' => array(
        'key' => variable_get('varnish_aws_access_key', ''),
        'secret' => variable_get('varnish_aws_secret_key', '')
      )
    ));
    try {
      $result = $client->describeLoadBalancers(array(
      ));
      $instance = array();
      if (!empty($result['LoadBalancerDescriptions'])) {
        foreach ($result['LoadBalancerDescriptions'] as $lbdetails) {
          if ($lbdetails['DNSName'] == variable_get('varnish_DNSName', '')) {
            if (!empty($lbdetails['Instances'])) {
              foreach ($lbdetails['Instances'] as $instances_list) {
                $instance[] = $instances_list['InstanceId'];
              }
            }
          }
        }
      }
    }
    catch (Exception $e) {
      echo 'Caught exception: ', $e->getMessage(), "\n";
    }
    if (!empty($instance)) {

      $clientEC = new Ec2Client(array(
        'version' => 'latest',
        'region' => variable_get('varnish_aws_region', ''),
        'credentials' => array(
          'key' => variable_get('varnish_aws_access_key', ''),
          'secret' => variable_get('varnish_aws_secret_key', '')
        )
      ));
      $resultEC = $clientEC->describeInstances(array(
        'InstanceIds' => $instance,
      ));
      $ec_private_ip = array();
      if (!empty($resultEC['Reservations'])) {
        foreach ($resultEC['Reservations'] as $ec_details) {
          if (isset($ec_details['Instances']) && !empty($ec_details['Instances'])) {
            foreach ($ec_details['Instances'] as $ec_instance) {
              if (isset($ec_instance['NetworkInterfaces']) && !empty($ec_instance['NetworkInterfaces'])) {
                foreach ($ec_instance['NetworkInterfaces'] as $ec_network_id) {
                  $ec_private_ip[] = $ec_network_id['PrivateIpAddress'] . ':6082';
                }
              }
            }
          }
        }
      }
    }
  }
  if (!empty($ec_private_ip)) {
    $unique_ip = array_unique($ec_private_ip);
    $unique_ip = implode(' ', $unique_ip);

    variable_set('varnish_control_terminal', $unique_ip);
    $varnish_value = variable_get('varnish_control_terminal', '127.0.0.1:6082');
    print $varnish_value;
  }
}
