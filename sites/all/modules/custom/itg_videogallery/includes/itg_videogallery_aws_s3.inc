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
 * @argument struing $bitrate_url, $video_name
 * @return $result array
 */

function itg_video_send_dm_to_s3($bitrate_url, $video_name) {
  $bucket = variable_get('aws_bucket');
  $aws_access_key = variable_get('aws_access_key');
  $aws_secret_key = variable_get('aws_secret_key');
  $aws_region = variable_get('aws_region');
  $aws_video_dir = variable_get('aws_video_dir');
  $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
  $result = $s3->putObject(array(
    'Bucket' => $bucket,
    'Key' => $aws_video_dir . $video_name,
    'Body' => file_get_contents($bitrate_url),
    'ACL' => 'public-read'
  ));
  return $result['ObjectURL'];
}
?>