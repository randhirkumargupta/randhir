<?php

/**
 * @file
 * ITG Videogallery inc.
 */
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
    } catch (S3Exception $e) {
        echo $e->getMessage() . "\n";
    }
    return $data_video;
}

/**
 * 
 * @return $data_video array
 */
function itg_video_get_sitemap_xmls() {
    $xml_dot_gz_files = array();
    $bucket = variable_get('aws_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');

    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    try {
        $objects = $s3->getIterator('ListObjects', array(
            'Bucket' => $bucket,
            "Prefix" => BUCKET_FOLDER.'/' . SITEMAP_BUCKET . '/'
        ));
        foreach ($objects as $object) {
            if (end(explode('.', $object['Key'])) == 'gz') {
                $xml_dot_gz_files['file_url'][] = $s3->getObjectUrl($bucket, $object['Key']);
                $xml_dot_gz_files['last_mod'][] = date('c', strtotime($object['LastModified']));
            }
        }
    } catch (S3Exception $e) {
        echo $e->getMessage() . "\n";
    }
    return $xml_dot_gz_files;
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
    } catch (S3Exception $e) {
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
        'Key' => $aws_video_dir . date('Ym') . '/' . $video_name,
        'Body' => file_get_contents($bitrate_url),
        'ACL' => 'public-read'
    ));
    return $result['ObjectURL'];
}

/**
 * Sending S3 to Daily motion
 * @argument struing $bitrate_url, $video_name
 * @return $result array
 */
function itg_video_send_dm_to_s3_for_octopus($bitrate_url, $video_name) {
    $bucket = variable_get('aws_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');
    $aws_video_dir = variable_get('aws_video_dm_data');
    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    $success_data = array();
    try {
        $result = $s3->putObject(array(
            'Bucket' => $bucket,
            'Key' => $aws_video_dir . date('Ym') . '/' . $video_name,
            'Body' => file_get_contents($bitrate_url),
            'ACL' => 'public-read'
        ));
        $success_data['url'] = $result['ObjectURL'];
        $success_data['success'] = 'yes';
        $success_data['msg'] = 'S3 file have been successfully sent to Daily Motion';
    } catch (Exception $e) {
        $success_data['url'] = $result['ObjectURL'];
        $success_data['success'] = 'no';
        $success_data['msg'] = $e->getMessage();
    }
    return $success_data;
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

/**
 * Function which is used to return array of readed csv file.
 * For tag import functionality.
 * 
 * @param string $filename
 * @return array
 */
function itg_tag_import_from_file($filename) {
    $bucket = variable_get('aws_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');
    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    $s3->registerStreamWrapper();
    $url = "s3://{$bucket}/s3fs-public/$filename";
    // Read CSV with fopen
    $file = fopen($url, 'r');
    $file_rows = array();
    while (($data = fgetcsv($file, 0, ',', '"')) !== FALSE) {
            $file_rows[] = $data;
    }
    return $file_rows;
}
