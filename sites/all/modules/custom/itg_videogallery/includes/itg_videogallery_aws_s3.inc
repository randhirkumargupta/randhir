<?php

require 'vendor/autoload.php';

use Aws\S3\S3Client;
use Aws\S3\Exception\S3Exception;
use Aws\Common\Credentials\Credentials;

/**
 * 
 * @return $data_video array
 */
function itg_video_get_s3_video() {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $aws_video_dir = variable_get('aws_video_dir');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
  $data_video = array();
  try {
    $objects = $s3->getIterator('ListObjects', array(
      'Bucket' => $bucket, "Prefix" => $aws_video_dir
    ));
    foreach ($objects as $object) {
      if (end(explode('.', $object['Key'])) == 'mp4') {

        $data_video['video'][] = $s3->getObjectUrl($bucket, $object['Key']);
        $data_video['size'][] = $object['Size'];
      }
    }
  }
  catch (S3Exception $e) {
    echo $e->getMessage() . "\n";
  }
  return $data_video;
}

/**
 * 
 * @return $data_video array
 */
function itg_video_get_s3_video_del($path) {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $aws_video_dir = variable_get('aws_video_dir');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
  $data_video = array();
  try {
    $objects = $s3->getIterator('ListObjects', array(
      'Bucket' => $bucket, "Prefix" => $path
    ));
    foreach ($objects as $object) {
      $result_delete = $s3->deleteObject(array(
        'Bucket' => $bucket,
        'Key' => $object['Key']
      ));
    }
  }
  catch (S3Exception $e) {
    echo $e->getMessage() . "\n";
  }
 
}

/**
 * @argument struing $bitrate_url, $video_name
 * @return $result array
 */
function itg_video_send_dm_to_s3($bitrate_url, $video_name) {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $aws_video_dir = variable_get('aws_video_dm_data');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
  $result = $s3->putObject(array(
    'Bucket' => $bucket,
    'Key' => $aws_video_dir . $video_name,
    'Body' => file_get_contents($bitrate_url),
    'ACL' => 'public-read'
  ));
  return $result['ObjectURL'];
}

/**
 * @argument struing $bitrate_url, $video_name
 * @return $result array
 */
function itg_video_copy_onfile_to_anoter($video_name, $folder) {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $aws_video_dir = variable_get('aws_video_dir');
  $aws_video_dir_to_move = variable_get('aws_video_dir_to_move');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
  $result = $s3->copyObject(array(
    'Bucket' => $bucket,
    'Key' => urldecode($aws_video_dir_to_move . $folder . '/' . $video_name),
    'CopySource' => urldecode($bucket . '/' . $aws_video_dir . $video_name),
  ));
  if (!empty($result)) {
    $keyvalue = urldecode($aws_video_dir . $video_name);
    $result_delete = $s3->deleteObject(array(
      'Bucket' => $bucket,
      'Key' => $keyvalue
    ));
  }
}

function itg_video_check_file_existance($filename) {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
  return $s3->doesObjectExist($bucket, 's3fs-public/' . $filename);
}

function itg_video_check_delete_sitemap_xml($filename) {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));

  $result_delete = $s3->deleteObject(array(
    'Bucket' => $bucket,
    'Key' => urldecode($filename)
  ));
  return $result_delete;
}

?>