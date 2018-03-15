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
    $file_name = $day_before.".json";
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
        $s_time = $start_date_timestamp;//date(strtotime($start_date_timestamp));
        $e_time = $end_date_timestamp;//date(strtotime($end_date_timestamp));
        //$query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
        $query->condition('npd.field_itg_content_publish_date_value', $s_time, '>=');
        $query->condition('npd.field_itg_content_publish_date_value', $e_time, '<=');
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
    $start_date = $day_before;
    $end_date = $start_date;
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $s_time = $start_date_timestamp;//date(strtotime($start_date_timestamp));
        $e_time = $end_date_timestamp;//date(strtotime($end_date_timestamp));
        //$query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
        $query->condition('npd.field_itg_content_publish_date_value', $s_time, '>=');
        $query->condition('npd.field_itg_content_publish_date_value', $e_time, '<=');
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
    $start_date = $day_before;
    $end_date = $start_date;
    if($start_date != "na" && $end_date != "na"){
        $start_date_timestamp = $start_date . " 00:00:00";
        $end_date_timestamp = $end_date . " 23:59:00";
        $s_time = $start_date_timestamp;//date(strtotime($start_date_timestamp));
        $e_time = $end_date_timestamp;//date(strtotime($end_date_timestamp));
        //$query->condition('npd.field_itg_content_publish_date_value', array($start_date_timestamp, $end_date_timestamp), 'BETWEEN');
        $query->condition('npd.field_itg_content_publish_date_value', $s_time, '>=');
        $query->condition('npd.field_itg_content_publish_date_value', $e_time, '<=');
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
    
    $xml = array();
    $xml['data'] = array();
    $xml['data']['videos'] = vedio_xml($result_vedio);
    $xml['data']['stories'] = story_xml($result_story);
    $xml['data']['galleries'] = gallery_xml($result_gallery);
    $xml = json_encode($xml);
    $xml_path = 'public://rss-feeds/xml_data/indiatoday/it/daily_report/';
    //$xml_path = 'public://rss-feeds/xml_data/celtick/it/stories/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
    //echo file_create_url($file_path);die;
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
      $weburl = FRONT_URL .'/' . $alias;
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
      $xml['item'][] = array(
																	'id' => $nid,
																	'title' => $title,
																	'category' => $prime_cat->name,
																	'sub_category' => $prime_cat->name,
																	'editor' => $byline,
																	'headline' => $kicker_text,
																	'author' => $cmsuser,
																	'creative_url_image' => $large_img,
																	'meta_key' => $keywords,
																	'meta_description' => $description,
																	'pv' => '',
																	'uv' => '',
																	'url' => $weburl,
																	'date_and_time' => $created_datetime,
															);
      
    }
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
    $xml = array();
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
      $weburl = FRONT_URL .'/'. $alias;
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
      $xml['item'][] = array(
														'id' => $nid,
														'title' => $title,
														'category' => $prime_cat->name,
														'sub_category' => $prime_cat->name,
														'editor' => $byline,
														'headline' => $kicker_text,
														'author' => $cmsuser,
														'creative_url_image' => $large_img,
														'meta_key' => $keywords,
														'meta_description' => $description,
														'pv' => '',
														'uv' => '',
														'url' => $weburl,
														'date_and_time' => $created_datetime,
														
												);
    }
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
    $xml = array();
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
      $weburl = FRONT_URL .'/'. $alias;
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
      
      $xml['item'][] = array(
														'id' => $nid,
														'title' => $title,
														'category' => $prime_cat->name,
														'sub_category' => $prime_cat->name,
														'editor' => $byline,
														'headline' => $kicker_text,
														'author' => $cmsuser,
														'creative_url_image' => $large_img,
														'meta_key' => $keywords,
														'meta_description' => $description,
														'pv' => '',
														'uv' => '',
														'url' => $weburl,
														'date_and_time' => $created_datetime,
														
												);
      
    }
  }
  return $xml;
}

