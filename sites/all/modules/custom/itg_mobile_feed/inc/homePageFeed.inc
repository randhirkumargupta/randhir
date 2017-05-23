<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate home page xml feed
 *
 * @return array
 */
$home_list_count = 0;
function homePageFeed() {
   //check into redis
   $redis_key = "itgd_homePageFeed";
   $result_get = getRedis($redis_key);

   if($result_get['key_value'] !=""){
       $output = $result_get['key_value'];
       //echo "redis get - ". $output; exit();
   }
   else{
  // variable declation
  global $home_list_count;
  $ttl = 300;
  $output = "";
  // xml feed tag for big story ...
  $bigStoryWidgetData = bigStoryWidgetData();
  // xml feed tag for home page features ...
  $homePageFeaturesWidgetData = homePageFeaturesWidgetData();
  // xml feed tag for home page top stories widget ...
  $topStoriesWidgetData = topStoriesWidgetData();

  //home page feed writing...
  //call function getMobileFeedXmlHeader
  $output .= getMobileFeedXmlHeader();
  // xml feed static tag...
  $output .= "<idsection>120</idsection><section>Home</section><totalarticle>" . $home_list_count . "</totalarticle><start_index>0</start_index><end_index>" . $home_list_count . "</end_index>";
  $output .= $bigStoryWidgetData;
  $output .= $homePageFeaturesWidgetData;
  $output .= $topStoriesWidgetData;

  //call function getMobileFeedXmlFooter
  $output .= getMobileFeedXmlFooter();
  // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
   }

  //home page feed file writing
  if ($output) {
    $feed_file_path = getcwd() . "/sites/default/files/xml_it/stories";
    //$feed_file_path = "public://xml_it/stories";
    //file_prepare_directory($feed_file_path, FILE_CREATE_DIRECTORY);

    $feed_file_name = "home.xml";
    $return_flag = writeFeedFile($feed_file_path, $feed_file_name, $output);
  }
  //return $return_flag;
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;  die();
}

/**
 * function for get story from Big Story widget
 *
 * @return string
 */
function bigStoryWidgetData() {
  // variable declation
  global $home_list_count;

  $output = "";
  $big_story_block_data = array();
  $widget_name = "big_story_format_widget";
  if (!empty($widget_name)) {
    $query = db_select('itg_widget_order', 'iwo')->fields('iwo', array('nid', 'extra'))->orderBy('iwo.weight', 'ASC')->condition('widget', $widget_name);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $big_story_data) {
      if ($big_story_data['extra'] == 'big_story_live_tv_active' && $big_story_data['nid'] == 0) {
        $big_story_block_data[] = array("is_live_tv" => TRUE);
      }
      elseif ($big_story_data['nid']) {
        $big_story_block_data[] = array("node_load_data" => node_load($big_story_data['nid']));
      }
    }

  }
  // varibale for feed tag
  $title = $big_story_block_data[1]['node_load_data']->title;
  $type = $big_story_block_data[1]['node_load_data']->type;
  $nid = $big_story_block_data[1]['node_load_data']->nid;
  $created = $big_story_block_data[1]['node_load_data']->created;
  // file url
  $file_small_img_url = completeFilePath($big_story_block_data[1]['node_load_data']->field_story_small_image['und'][0]['fid']);
  $file_medium_img_url = completeFilePath($big_story_block_data[1]['node_load_data']->field_story_medium_image['und'][0]['fid']);

  //related content
  $related = relatedContentNodeType($big_story_block_data[1]['node_load_data']->field_common_related_content['und'][0]['value'], $type);

  // create date formating
  $create_date = date("F d, Y", $created);
  $create_datetime = date(DATE_ATOM, $created);
  //xml tag writing
  if ($type == "story") {
    $home_list_count++;
    $output .= "<article><type1>" . $type . "</type1><title><![CDATA[" . $title . "]]></title><thumbimage><![CDATA[" . $file_small_img_url . "]]></thumbimage><kickerimage><![CDATA[" . $file_medium_img_url . "]]></kickerimage><url>story" . $nid . ".xml</url><create_date>" . $create_date . "</create_date><create_datetime>" . $create_datetime . "</create_datetime><relateds><photos>" . $related['photos'] . "</photos><videos>" . $related['videos'] . "</videos><stories>" . $related['stories'] . "</stories></relateds></article>";
    // generate story detail page
    $fl = generateStoryDetailPageFeed($nid);

  }

  return $output;
}

/**
 * function for get story from Home Page Features widget
 *
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 *
 * @return array
 */
function homePageFeaturesWidgetData() {
  // variable declation
  global $home_list_count;

  $output = "";
  $widget_name = "home_page_feature_widget";
  $range_max = 10 - $home_list_count;
  $range_min = 0;
  $order_by = 'ASC';

  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  //join  for field value
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
  $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
  $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

  $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');

  $query->fields('eli_file', array('uri'));
  $query->fields('li_file', array('uri'));
  $query->fields('mi_file', array('uri'));
  $query->fields('si_file', array('uri'));
  $query->fields('esi_file', array('uri'));

  $query->fields('mi', array('field_story_medium_image_fid'));
  $query->fields('si', array('field_story_small_image_fid'));
  $query->fields('rc', array('field_common_related_content_value'));

  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));


  //end
  $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  // xml tag wring for features widget..
  foreach ($result as $key => $value) {
    //print_ar($value, "looping data");exit();

    // varibale for feed tag
    $title = $value['title'];
    $type = $value['type'];
    $nid = $value['nid'];
    $created = $value['created'];
    // file url
    $file_small_img_url = completeFilePath($value['field_story_small_image_fid']);
    $file_medium_img_url = completeFilePath($value['field_story_medium_image_fid']);

    //related content
    $related = relatedContentNodeType($value['field_common_related_content_value'], $type);

    // create date formating
    $create_date = date("F d, Y", $created);
    $create_datetime = date(DATE_ATOM, $created);
    //xml tag writing
    if ($type == "story") {
      $home_list_count++;
      $output .= "<article>
                        <type>" . $type . "</type>
                        <title><![CDATA[" . $title . "]]></title>
                        <thumbimage><![CDATA[" . $file_small_img_url . "]]></thumbimage>
                        <kickerimage><![CDATA[" . $file_medium_img_url . "]]></kickerimage>
                        <url>story" . $nid . ".xml</url>
                        <create_date>" . $create_date . "</create_date>
                        <create_datetime>" . $create_datetime . "</create_datetime>
                        <relateds>
                            <photos>" . $related['photos'] . "</photos>
                            <videos>" . $related['videos'] . "</videos>
                            <stories>" . $related['stories'] . "</stories>
                        </relateds>
                    </article>";
      // generate story detail page
    $fl = generateStoryDetailPageFeed($nid);
    }
  }

  return $output;
}

/**
 * function for get story from Top Stories widget
 *
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 *
 * @return array
 */
function topStoriesWidgetData() {
  // variable declation
  global $home_list_count;

  $output = "";
  $widget_name = "top_stories_widget";
  $range_max = 10 - $home_list_count;
  $range_min = 0;
  $order_by = 'ASC';

  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  //join  for field value
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
  $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
  $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

  $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');

  $query->fields('eli_file', array('uri'));
  $query->fields('li_file', array('uri'));
  $query->fields('mi_file', array('uri'));
  $query->fields('si_file', array('uri'));
  $query->fields('esi_file', array('uri'));

  $query->fields('mi', array('field_story_medium_image_fid'));
  $query->fields('si', array('field_story_small_image_fid'));
  $query->fields('rc', array('field_common_related_content_value'));

  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));


  //end
  $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  // xml tag wring for features widget..
  foreach ($result as $key => $value) {


    // varibale for feed tag
    $title = $value['title'];
    $type = $value['type'];
    $nid = $value['nid'];
    $created = $value['created'];
    // file url
    $file_small_img_url = completeFilePath($value['field_story_small_image_fid']);
    $file_medium_img_url = completeFilePath($value['field_story_medium_image_fid']);

    //related content
    $related = relatedContentNodeType($value['field_common_related_content_value'], $type);

    // create date formating
    $create_date = date("F d, Y", $created);
    $create_datetime = date(DATE_ATOM, $created);
    //xml tag writing
    if ($type == "story") {
      $home_list_count++;
      $output .= "<article>
                        <type>" . $type . "</type>
                        <title><![CDATA[" . $title . "]]></title>
                        <thumbimage><![CDATA[" . $file_small_img_url . "]]></thumbimage>
                        <kickerimage><![CDATA[" . $file_medium_img_url . "]]></kickerimage>
                        <url>story" . $nid . ".xml</url>
                        <create_date>" . $create_date . "</create_date>
                        <create_datetime>" . $create_datetime . "</create_datetime>
                        <relateds>
                            <photos>" . $related['photos'] . "</photos>
                            <videos>" . $related['videos'] . "</videos>
                            <stories>" . $related['stories'] . "</stories>
                        </relateds>
                    </article>";
      // generate story detail page
    $fl = generateStoryDetailPageFeed($nid);
    }
  }

  return $output;
}
