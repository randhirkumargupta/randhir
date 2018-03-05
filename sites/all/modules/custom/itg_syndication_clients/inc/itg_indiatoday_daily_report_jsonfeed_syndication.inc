<?php

/**
 * Function for Generate indiatoday_daily_report xml feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_indiatoday_daily_report_jsonfeed_syndication() {
    $date = date( 'Y-m-d', time());
    $day_before = date( 'Y-m-d', strtotime( $date . ' -1 day' ) );
    //$file_name = date('Y-m-d', time()).".xml";
    $file_name = $day_before.".xml";
    // query for vedio
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'sli', 'sli.entity_id=n.nid');
    $start_date = $day_before;
    $end_date = $start_date;
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $s_time = date(strtotime($start_date_timestamp));
        $e_time = date(strtotime($end_date_timestamp));
        //$query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
        $query->condition('n.created', $s_time, '>=');
        $query->condition('n.created', $e_time, '<=');
    }
    
    //$query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    //$query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_extra_large_image_fid'));
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid');
    //print strtr((string) $query, $query->arguments());die();
    $result_vedio = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    // query for story
    $query = "";
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'sli', 'sli.entity_id=n.nid');
    $start_date = date('Y-m-d', strtotime("-" . $interval . " days"));
    $end_date = $start_date;
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
    }
    
    //$query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    //$query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_extra_large_image_fid'));
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid');
    $result_story = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    // query for gallery
    $query = "";
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'sli', 'sli.entity_id=n.nid');
    $start_date = date('Y-m-d', strtotime("-" . $interval . " days"));
    $end_date = $start_date;
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
    }
    
    //$query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    //$query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_extra_large_image_fid'));
    $query->condition('n.status', 1);
    $query->condition('n.type', 'photogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid');
    $result_gallery = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    $xml = "";
    $xml = '<?xml version="1.0" encoding="UTF-8"?><data>';
    $xml .= vedio_xml($result_vedio);
    $xml .= story_xml($result_story);
    $xml .= gallery_xml($result_gallery);
    $xml .= '</data>';
    $xml_path = 'public://rss-feeds/xml_data/indiatoday/it/daily_report/';
    //$xml_path = 'public://rss-feeds/xml_data/celtick/it/stories/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
   //echo $file_path;echo "<br>";
   //echo $xml;
}

/**
 * 
 * @global string $base_url
 * @param array $result 
 * @return string
 */
function vedio_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;   
    $xml .= '<videos>';
    foreach ($result as $key => $value) {
      
      $nid = $value['nid'];
      $firebase_url = get_node_firebase_weburl($nid);
      $prime_cat = getNodePrimeCatByNid($nid);
      $cmsuser = getCmsUserByNid_dailyReport($nid);
      $metatags = get_node_metatags_by_nid($nid);
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
        $description = $temp['description']['value'];
      }
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = "https://www.indiatoday.in/" . $alias;
      $title = $value['title'];
      $created = $value['created'];
      $publish_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $large_img_ar = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $large_img = completeFilePath($resvalue['field_story_extra_large_image_fid']);
      $byline = get_byline_name_by_nid($nid);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = $value["body_value"];
      $created_datetime = date("Y-m-d H:i:s", $created);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $article_type = slugify(preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($category)));
      $xml .= '<item>';
      $xml .= '<id>'.$nid.'</id>';
      $xml .= '<title>'.$title.'</title>';
      $xml .= '<category>'.$prime_cat->name.'</category>';
      $xml .= '<sub_category>'.$prime_cat->name.'</sub_category>';
      $xml .= '<editor>'.$byline.'</editor>';
      $xml .= '<headline>'.$kicker_text.'</headline>';
      $xml .= '<author>'.$cmsuser.'</author>';
      $xml .= '<creative_url_image>'.$large_img.'</creative_url_image>';
      $xml .= '<meta_key>'.$keywords.'</meta_key>';
      $xml .= '<meta_description>'.$description.'</meta_description>';
      $xml .= '<pv></pv>';
      $xml .= '<uv></uv>';
      $xml .= '<url>'.$weburl.'</url>';
      $xml .= '<date_and_time>'.$created_datetime.'</date_and_time>';
      $xml .= '</item>';
    }
    $xml .= '</videos>';
  }
  
  return $xml;
}
/**
 * 
 * @global string $base_url
 * @param array $result 
 * @return string
 */
function story_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url; 
    $xml .= '<stories>';
    foreach ($result as $key => $value) {
      
      $nid = $value['nid'];
      $firebase_url = get_node_firebase_weburl($nid);
      $prime_cat = getNodePrimeCatByNid($nid);
      $cmsuser = getCmsUserByNid_dailyReport($nid);
      $metatags = get_node_metatags_by_nid($nid);
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
        $description = $temp['description']['value'];
      }
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = "https://www.indiatoday.in/" . $alias;
      $title = $value['title'];
      $created = $value['created'];
      $publish_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $large_img_ar = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $large_img = completeFilePath($resvalue['field_story_extra_large_image_fid']);
      $byline = get_byline_name_by_nid($nid);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = $value["body_value"];
      $created_datetime = date("Y-m-d H:i:s", $created);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $article_type = slugify(preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($category)));
      $xml .= '<item>';
      $xml .= '<id>'.$nid.'</id>';
      $xml .= '<title>'.$title.'</title>';
      $xml .= '<category>'.$prime_cat->name.'</category>';
      $xml .= '<sub_category>'.$prime_cat->name.'</sub_category>';
      $xml .= '<editor>'.$byline.'</editor>';
      $xml .= '<headline>'.$kicker_text.'</headline>';
      $xml .= '<author>'.$cmsuser.'</author>';
      $xml .= '<creative_url_image>'.$large_img.'</creative_url_image>';
      $xml .= '<meta_key>'.$keywords.'</meta_key>';
      $xml .= '<meta_description>'.$description.'</meta_description>';
      $xml .= '<pv></pv>';
      $xml .= '<uv></uv>';
      $xml .= '<url>'.$weburl.'</url>';
      $xml .= '<date_and_time>'.$created_datetime.'</date_and_time>';
      $xml .= '</item>';
    }
    $xml .= '</stories>';
  }
  return $xml;
}
/**
 * 
 * @global string $base_url
 * @param array $result 
 * @return string
 */
function gallery_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    $xml .= '<galleries>';
    global $base_url;    
    foreach ($result as $key => $value) {
      
      $nid = $value['nid'];
      $firebase_url = get_node_firebase_weburl($nid);
      $prime_cat = getNodePrimeCatByNid($nid);
      $cmsuser = getCmsUserByNid_dailyReport($nid);
      $metatags = get_node_metatags_by_nid($nid);
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
        $description = $temp['description']['value'];
      }
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = "https://www.indiatoday.in/" . $alias;
      $title = $value['title'];
      $created = $value['created'];
      $publish_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $large_img_ar = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $large_img = completeFilePath($resvalue['field_story_extra_large_image_fid']);
      $byline = get_byline_name_by_nid($nid);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = $value["body_value"];
      $created_datetime = date("Y-m-d H:i:s", $created);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $article_type = slugify(preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($category)));
      $xml .= '<item>';
      $xml .= '<id>'.$nid.'</id>';
      $xml .= '<title>'.$title.'</title>';
      $xml .= '<category>'.$prime_cat->name.'</category>';
      $xml .= '<sub_category>'.$prime_cat->name.'</sub_category>';
      $xml .= '<editor>'.$byline.'</editor>';
      $xml .= '<headline>'.$kicker_text.'</headline>';
      $xml .= '<author>'.$cmsuser.'</author>';
      $xml .= '<creative_url_image>'.$large_img.'</creative_url_image>';
      $xml .= '<meta_key>'.$keywords.'</meta_key>';
      $xml .= '<meta_description>'.$description.'</meta_description>';
      $xml .= '<pv></pv>';
      $xml .= '<uv></uv>';
      $xml .= '<url>'.$weburl.'</url>';
      $xml .= '<date_and_time>'.$created_datetime.'</date_and_time>';
      $xml .= '</item>';
    }
    $xml .= '</galleries>';
  }
  return $xml;
}
