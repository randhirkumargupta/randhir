<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate photoCategoryPage xml feed
 *
 * @return array
 */
function photocategoryPageFeed() {
  // variable declation  
  $output = "";
  // tid conf function
  $conf_array = tidConfig();
  $storytag = array();
  $section_list = array();  
  // check tid argument
  $tid_arg = arg(1);
  if($tid_arg && is_numeric($tid_arg)){
    //$section_list = categoryManagerSectionTid('photogallery');
    $section_list[] = $tid_arg;
  }
  else{
      $section_list = $conf_array['photo_sec_tid'];
  }
  $list_count = 0;
  $catFile = "";
  //$term_feed_path = getcwd() . "/sites/all/modules/custom/itg_mobile_feed/xml_it/photos";
  $term_feed_path = "public://xml_it/photos";
  file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
  
  $return_flag = "";
  // loop on section
  foreach ($section_list as $key => $value) {
    
    // check section is photogallery
    $node_count = customNodeCount('photogallery', $value);
    // loop on category
    if ($node_count > 0 ) {
     
        $cattid = $value;
        $term = taxonomy_term_load($value);
        $term_name = $term->name;
        // get story list tag
        $storytag = generatePhotoCategoryPage($cattid);
        $list_count = $storytag['lcount'];
        $catFile = "";
        // cat xml feed file name
        $catFile = drupal_strtolower(str_replace(" ", "-", $term_name));
        $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
        $catFile = $catFile . "_photo.xml";
        // generate cat xml file string
        if ($storytag['data'] != "") {
          $output = "";
          $output .= getMobileFeedXmlHeader();
          $output .= "\n<idsection>" . $cattid . "</idsection>
                                <section>" . $term_name . "</section>
                                <totalgalleries>" . $list_count . "</totalgalleries>
                                <start_index>0</start_index>
                                <end_index>" . $list_count . "</end_index>\n";
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
 * function for generate photoCategoryPage xml feed
 *
 * @return array
 */
function generatePhotoCategoryPage($tid) {
  //check into redis
   $redis_key = "itgd_generatePhotoCategoryPages".$tid;
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
  $ttl = 300;
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 20;
  $range_min = 0;
  $order_by = 'ASC';
  $type = "photogallery";


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
      $output .= "<item> 
                        <title><![CDATA[" . $title . "]]></title>  
                        <thumbimage><![CDATA[" . $file_medium_img_url . "]]></thumbimage>
                        <url>photo" . $nid . ".xml</url>
                        <create_date>" . $create_date . "</create_date>
                        <create_datetime>" . $create_datetime . "</create_datetime>
                        <is_favorite>" . $is_fav . "</is_favorite>
                        <relateds>
                            <photos>" . $related['photos'] . "</photos>
                            <videos>" . $related['videos'] . "</videos>
                            <stories>" . $related['stories'] . "</stories>
                        </relateds>
                        <weburl><![CDATA[" . $weburl . "]]></weburl>
                    </item>";
      // generate photo detail page
    $fl = generatePhotoDetailPageFeed($nid);
    }
  }
  $data['lcount'] = $listcount;
  $data['data'] = $output;
  $data_fi = $listcount."##listcount##".$output;
 // print_r($data);exit();
  // set into redis
    $result_set = setRedis($redis_key, $data_fi, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
   }
  
  return $data;
}

