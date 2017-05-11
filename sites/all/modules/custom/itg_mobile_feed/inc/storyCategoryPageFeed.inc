<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate storyCategoryPage xml feed
 *
 * @return array
 */
function storyCategoryPageFeed() {
  // variable declation
  $output = "";
  $storytag = array();
  $section_list = categoryManagerSectionTid('story');
  $list_count = 0;
  $catFile = "";
  //$term_feed_path = getcwd() . "/sites/all/modules/custom/itg_mobile_feed/xml_it/stories";
  $term_feed_path = "public://xml_it/stories";
  file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
  $return_flag = "";
  // loop on section
  foreach ($section_list as $key => $value) {
    
    // check section is story
    $node_count = customNodeCount('story', $value);
    // loop on category
    if ($node_count > 0 ) {
      
        $cattid = $value;
        $term = taxonomy_term_load($value);
        $term_name = $term->name;
        // get story list tag
        $storytag = generateStoryCategoryPage($cattid);
        $list_count = $storytag['lcount'];
        $catFile = "";
        // cat xml feed file name
        $catFile = drupal_strtolower(str_replace(" ", "-", $term_name));
        $catFile = $catFile . ".xml";
        // generate cat xml file string
        if ($storytag['data'] != "") {
          $output = "";
          $output .= getMobileFeedXmlHeader();
          $output .= "\n<idsection>".$cattid."</idsection>
                        <section>".$term_name."</section>
                        <totalarticle>".$list_count."</totalarticle>
                        <start_index>0</start_index>
                        <end_index>".$list_count."</end_index>\n";
          $output .= $storytag['data'];
          $output .= "\n" . getMobileFeedXmlFooter();
          // xml file writing..
          if ($output) {
            
            $return_flag .= writeFeedFile($term_feed_path, $catFile, $output);
          }
        }
     // }
    }
  }
  //return $return_flag;
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;  die();
}

/**
 * function for generate storyCategoryPage xml feed
 *
 * @return array
 */
function generateStoryCategoryPage($tid) {
  //check into redis
   $redis_key = "itgd_generateStoryCategoryPage".$tid;
   $result_get = getRedis($redis_key);
   
   if($result_get['key_value'] !=""){
       $data_str = $result_get['key_value'];       
        //echo "redis get - ". $output; exit();
       $data_ar = explode("##listcount##",$data_str);
       $data['lcount'] = $data_ar[0];
       $data['data'] = $data_ar[1];
   }
   else{
  // variable declaration
  global $base_url;
  $node_count = "";
  $ttl = 300;
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 20;
  $range_min = 0;
  $order_by = 'ASC';
  $type = "story";


{
    $listcount = 0;


    // select node belong from current term id or child term id

    $query = db_select('taxonomy_index', 'ti');
    $query->leftJoin('node', 'n', 'n.nid=ti.nid');
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
    $query->condition('ti.tid', $tid_list, 'IN')->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->range($range_min, $range_max);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {

      // node feed tag
      $listcount++;

      $title = $resvalue['title'];
      $type = $resvalue['type'];
      $nid = $resvalue['nid'];
      $created = $resvalue['created'];
      $is_fav = getNidIsFavorite($nid);
      //$weburl = $base_url . "/node/" . $nid;
      $alias = drupal_get_path_alias('node/'.$nid.'');
      $weburl = $base_url ."/". $alias;
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value'], $type);

      // create date formating
      $create_date = date("F d, Y", $created);
      $create_datetime = date(DATE_ATOM, $created);
      $output .= "<article> 
                    <title>".$title."</title>
                    <thumbimage><![CDATA[".$file_small_img_url."]]></thumbimage>
                    <kickerimage><![CDATA[".$file_medium_img_url."]]></kickerimage> 
                    <url>story".$nid.".xml </url>
                    <create_date>".$create_date."</create_date>
                    <create_datetime>".$create_datetime."</create_datetime>
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
  $data['lcount'] = $listcount;
  $data['data'] = $output;
  $data_fi = $listcount."##listcount##".$output;
  // set into redis
    $result_set = setRedis($redis_key, $data_fi, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
   }
  return $data;
}

