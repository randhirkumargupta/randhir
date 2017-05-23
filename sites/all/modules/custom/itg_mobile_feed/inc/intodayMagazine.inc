<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate intodayMagazine xml feed
 *
 * @return array
 */
function intodayMagazine() {
   //check into redis
   $redis_key = "itgd_intodayMagazine";
   $result_get = getRedis($redis_key);

   if($result_get['key_value'] !=""){
       $output = $result_get['key_value'];
       //echo "redis get - ". $output; exit();
   }
   else{
  // variable declation
  $output = "";
  $ttl = 300;
  // tid conf function

  $storytag = array();
  // static  tid

  $list_count = 0;
  $catFile = "";

  $return_flag = "";
  // loop on section



      $tid_magazine_section = tidConfig();
      $magazine_tid = $tid_magazine_section['magazine'];

        $cattid = generateIntodayMagazinePage($magazine_tid);
        $term = taxonomy_term_load($cattid);
        $term_name = $term->name;
        $list_count = $storytag['lcount'];
        $catFile = "";
        //xml feed file name


        // generate cat xml file string
        if ($storytag['data'] != "") {
          $output = "";
          $output .= getMobileFeedXmlHeader();
          $output .= "<idsection>".$cattid."</idsection>
                        <section>".$term_name."</section>
                        <totalarticle>".$list_count."</totalarticle>
                        <start_index>0</start_index>
                        <end_index>".$list_count."</end_index>";
          $output .= $storytag['data'];
          $output .= getMobileFeedXmlFooter();
          // xml file writing..

        }
        // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
   }
        if ($output) {
            $term_feed_path = getcwd() . "/sites/default/files/xml_it/stories";
            //$term_feed_path = "public://xml_it/stories";
	    //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
            $catFile = "fromthemagazine.xml";
            $return_flag .= writeFeedFile($term_feed_path, $catFile, $output);
          }
     // }


  //return $return_flag;
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;  die();
}

/**
 * function for generate storyCategoryPage xml feed
 *
 * @return array
 */
function generateIntodayMagazinePage($tid) {
  // variable declaration
  global $base_url;
  $node_count = "";
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
    //condition for magazine based story
    $query->Join('field_data_field_story_source_type', 'fdsst', 'fdsst.entity_id=n.nid');

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
    $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->range($range_min, $range_max);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {

      // node feed tag
      $listcount++;

      $title = $resvalue['title'];
      $type = $resvalue['type'];
      $nid = $resvalue['nid'];
      $created = $resvalue['created'];
      $is_fav = getNidIsFavorite($nid);
      $alias = drupal_get_path_alias('node/'.$nid.'');
      $weburl = $base_url ."/". $alias;
      $loop_file_name = "fromindiatodaymagazine".$nid.".xml";
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
                    <url>".$loop_file_name." </url>
                    <create_date>".$create_date."</create_date>
                    <create_datetime>".$create_datetime."</create_datetime>
                    <relateds>
                        <photos>".$related['photos']."</photos>
                        <videos>".$related['videos']."</videos>
                        <stories>".$related['stories']."</stories>
                    </relateds>
                </article>";
      // generate story detail page
    $fl = generateStoryDetailPageFeed($nid, $loop_file_name);
    }
  }
  $data['lcount'] = $listcount;
  $data['data'] = $output;

  return $data;
}
