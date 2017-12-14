<?php

/**
 * This function use for get video bitrate url
 * 
 */
function itg_videogallery_get_video_bitrate_by_url($url, $nid, $used_on, $external = NULL) {
  $return_array = array();
  $query = db_select('itg_video_transcoding', 'ivt');
  $query->fields('ivt');
  $query->condition('nid', $nid, ' = ');
  $query->condition('video_url', $url, ' = ');
  $query->condition('bitrate_status', 1, ' = ');
  $query->orderby('bitrate_ordering', 'ASC');
  $video_data1 = $query->execute()->fetchAll();
  $parts = parse_url($url);
  $getbucket_setting = itg_videogallery_get_video_setting_by_bucket_name($parts['host']);
  if (!empty($getbucket_setting)) {
    $return_array['file_url'] = $getbucket_setting[0]->field_progressive_domain_value . '/' . $parts['path'];
  }
  else {
    $return_array['file_url'] = $url;
  }
  foreach ($video_data1 as $key => $vid) {
    $bitrate[] = $vid->bitrate;
  }

  if (!empty($getbucket_setting[0]->field_hls_domain_value)) {
    $bitrate_url = itg_videogallery_make_bitrate_url_migtate($parts['path'], $bitrate, $getbucket_setting[0]->field_hls_domain_value);
    $return_array['bitrate_url'] = $bitrate_url;
  }
  else {
    $return_array['bitrate_url'] = "";
  }
  $dfp_data = itg_videogallery_get_dfp_tags($video_data1[0]->website, $video_data1[0]->transcoding_source);
  $return_array['dfp_tags'] = JWPLAYER_DFP_TAG;
  if (!empty($dfp_data) && !empty($dfp_data[0]->dfp_tags)) {
    if ($used_on == 'video') {
      $retrun_array['dfp_tags'] = $dfp_data[0]->dfp_tags;
    }
    else {
      if ($external == 1) {
        $retrun_array['dfp_tags'] = $dfp_data[0]->dfp_tags_external;
      }
      else {
        $retrun_array['dfp_tags'] = $dfp_data[0]->dfp_tags_internal;
      }
    }
  }
    if (!empty($dfp_data)) {
      if ($used_on == 'embed' && !empty($dfp_data[0]->ga_tag_extarnal)) {
        $return_array['ga_code'] = $dfp_data[0]->ga_tag_extarnal;
      }
      else {
        $return_array['ga_code'] = ITG_GA_CODE;
      }
      if ($used_on != 'embed' && !empty($dfp_data[0]->ga_tag_internal)) {
        $return_array['ga_code'] = $dfp_data[0]->ga_tag_internal;
      }
      else {
        $return_array['ga_code'] = ITG_GA_CODE;
      }
    }
    return $return_array;
  }

  /**
   * This function use for make video bitrate url:
   */
  function itg_videogallery_make_bitrate_url_migtate($video_url, $bitrates, $hls) {
    $withoutExt = substr($video_url, 0, (strrpos($video_url, ".")));
     asort($bitrates);
    if (count($bitrates) == 1) {
      $with_hls_url = $hls . '/i' . $withoutExt;
      $returnstring = $with_hls_url . ',,.mp4.csmil/master.m3u8';
    }
    else {
      $with_hls_url = substr($withoutExt, 0, strrpos($withoutExt, "_"));
      $with_hls_url = $hls . '/i' . $with_hls_url . '_';
      $returnstring = $with_hls_url . ',' . implode(',', $bitrates) . ',.mp4.csmil/master.m3u8';
    }
    return $returnstring;
  }
  