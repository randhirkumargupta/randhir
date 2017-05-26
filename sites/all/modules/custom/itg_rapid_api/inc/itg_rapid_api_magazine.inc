<?php
/**
 * Inc file contains the functions
 */

/**
 * main function for generate magazineEditionPageRerourceValue array
 *
 * @return array
 */


function magazineEditionPageRerourceValue($issueid = 0, $pageno = 0) {
  // magazine story nid - 349676, 349673
    //349714 - supplement node nid
    //349713 - issue node id
    //349712 - magazine node id
    
    //116087 -> cocacolamine magazine of "india today test" magazine
    // field_story_select_magazine & field_story_select_supplement, field_story_issue_date , field_story_magazine_story_issue
  //echo "<pre>"; print_r(node_load(116087)); echo "</pre>";exit();
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();      
    $updated_datetime = "";
    
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;   
    if(!$tid){
        $term_name = "Latest";
    }
    
    // list array building
    $data = magazineEditionPageRerourceValueList($issueid, $pageno);
    
    if($data['issue_nid'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    
    //data array building
     $datacount = $data['lcount'];
     $data_up_time = $data['updated_datetime'];
     
     $issue_date = $data['issue_date'];
     $issue_cover_image = $data['issue_cover_image'];
     $issue_digitalmag_url = $data['issue_digitalmag_url'];
    
    $data_array['issue_id'] = "$issueid";
    $data_array['issue_date'] = "$issue_date";
    $data_array['issue_cover_image'] = "$issue_cover_image";
    $data_array['issue_digitalmag_url'] = "$issue_digitalmag_url";
    $data_array['story_count'] = "$datacount";
    $data_array['story_display_count'] = "10";
    $data_array['story_pagination_cap'] = "7";
    $data_array['updated_datetime'] = "$data_up_time";
    
    $data_array['story'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for generate magazineEditionPageRerourceValueList xml feed
 *
 * @return array
 */
function magazineEditionPageRerourceValueList($issueid, $pageno) {
  // variable declaration
  global $base_url;  
  //issue node 
  $node = node_load($issueid);
  $field_issue_large_cover_image_fid = $node->field_issue_large_cover_image['und'][0]['fid'];
  $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);
  
  $field_issue_small_cover_image_fid = $node->field_issue_small_cover_image['und'][0]['fid'];
  $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);
  
  $issue_date = $node->field_issue_title['und'][0]['value'];
  $issue_nid = $node->nid;
  
  $field_issue_magazine = $node->field_issue_magazine['und'][0]['target_id'];
  
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 10;
  if(!$pageno == 0){
      $range_min = $pageno * $range_max;
  }
  else{
    $range_min = 0;
  }
  $order_by = 'DESC';  
  $story_list_array = array();
  $loop_count = 0;
  
  // select node belong from current term id or child term id

    $query = db_select('node', 'n');    
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
    //field_data_field_story_select_magazine
    $query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
    //field_data_field_story_issue_date
    $query->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
    //field_data_field_story_magazine_story_issue
    $query->leftJoin('field_data_field_story_magazine_story_issue', 'fsms', 'fsms.entity_id=n.nid');

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
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));


    //end
    
    //->condition('fsid.field_story_issue_date_value', $issue_date)
    //->condition('fssm.field_story_select_magazine_target_id', $field_issue_magazine)
    $query->condition('n.status', 1)->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
    //echo $query; exit();
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue) {

            // node feed tag


            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
            //$weburl = $base_url . "/node/" . $nid;
            $alias = drupal_get_path_alias('node/'.$nid.'');
            $weburl = $base_url ."/". $alias;
            $field_video_duration_value = $resvalue['field_video_duration_value'];
            // file url
            $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
            $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

            //related content
            $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
            $comment_cont = getCommentsCount($nid);

            // create date formating
            $firebase_url = get_node_firebase_weburl($nid);

            if($created){
              $create_datetime = date("Y-m-d H:i:s", $created);
              $create_date = date("Y-m-d H:i:s", $created);
            }
            else{
                $create_datetime = "";
                $create_date = "";
            }
            if($changed){
              $changed_datetime = date("Y-m-d H:i:s", $changed);
            }
            else{
                $changed_datetime = "";
            }

          $story_list_array[$listcount]['s_id'] = "$nid";
          $story_list_array[$listcount]['s_title'] = "$title";
          $story_list_array[$listcount]['s_share_link'] = "Universal_link";
          $story_list_array[$listcount]['s_short_desc'] = "$field_story_kicker_text_value";
          $story_list_array[$listcount]['s_comment_count'] = "$comment_cont";
          $story_list_array[$listcount]['s_small_image'] = "$file_small_img_url";
          $story_list_array[$listcount]['s_large_image'] = "$file_medium_img_url";
          $story_list_array[$listcount]['s_updated_datetime'] = "$changed_datetime";
          $story_list_array[$listcount]['s_is_locked'] = "0";
          $story_list_array[$listcount]['s_author_id'] = "id";
          $story_list_array[$listcount]['s_author_title'] = "author_name";
          $story_list_array[$listcount]['s_pcategory_id'] = "1";
          $story_list_array[$listcount]['s_pcategory_title'] = "Cover Story";

          
  
       
        $listcount++;
    }
    
    $data['lcount'] = $listcount;
    $data['data'] = $story_list_array;
    $data['updated_datetime'] = $changed_datetime;

    $data['issue_date'] = $issue_date;
    $data['issue_nid'] = $issue_nid;
    $data['issue_cover_image'] = $issue_cover_image;
    $data['issue_digitalmag_url'] = $issue_digitalmag_url;
  
  
  return $data;
}

//2nd

/**
 * main function for generate magazineCoverstoriesPageRerourceValue array
 *
 * @return array
 */


function magazineCoverstoriesPageRerourceValue() {
    
  
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $issue_list_array = array();      
    $updated_datetime = "";  
    
    
    // list array building
    $data = magazineCoverstoriesPageRerourceValueList();
    
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    
    //data array building
     $datacount = $data['lcount'];
     $data_up_time = $data['updated_datetime'];
    
    
    
    $data_array['issue'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for generate magazineCoverstoriesPageRerourceValueList xml feed
 *
 * @return array
 */
function magazineCoverstoriesPageRerourceValueList() {
  // variable declaration
  global $base_url;  
  $node_count = "";
  $output = "";
  $data = array();  
  $listcount = 0;  
  $data_list_array = array();  
  $loop_count = 0;
  
  // issue list query..
  
  $query_issue = db_select('node', 'n'); 
  $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
  $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
  $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');  
  
  $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
  $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
  $query_issue->fields('fsit', array('field_issue_title_value'));
  $query_issue->fields('n', array('nid'));
  
  $query_issue->condition('n.status', 1)->condition('n.type', 'issue')->range(0, 2);
  $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result_issue as $reskey => $resvalue){
        
        //issue node 
        $issueid = $resvalue['nid'];
        //$node = node_load($issueid);
        $field_issue_large_cover_image_fid = $resvalue['field_issue_large_cover_image_fid'];
        $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);

        $field_issue_small_cover_image_fid = $resvalue['field_issue_small_cover_image_fid'];
        $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);

        $issue_date = $resvalue['field_issue_title_value'];
        $issue_nid = $resvalue['nid'];
        
        $data_list_array[$loop_count]['issue_id'] = "$issueid";
        $data_list_array[$loop_count]['issue_date'] = "$issue_date";
        $data_list_array[$loop_count]['issue_cover_image'] = "$issue_cover_image";
        $data_list_array[$loop_count]['story'] = getCoverstoriesList();
        $loop_count++;
    }

  $data['lcount'] = $loop_count;
  $data['data'] = $data_list_array;
  $data['updated_datetime'] = $changed_datetime;
  
  
  return $data;
}

/**
 * main function for getStoryList array
 *
 * @return array
 */
function getCoverstoriesList(){
    
  $cover_story_list_array = array();
  $loop_count = 0;
  
  // select node belong from current term id or child term id

    $query = db_select('node', 'n');    
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
    //field_data_field_story_select_magazine
    $query->leftJoin('field_data_field_story_select_magazine', 'fssm', 'fssm.field_story_select_magazine_target_id=n.nid');
    //field_data_field_story_issue_date
    $query->leftJoin('field_data_field_story_issue_date', 'fsid', 'fsid.entity_id=n.nid');
    //field_data_field_story_magazine_story_issue
    $query->leftJoin('field_data_field_story_magazine_story_issue', 'fsms', 'fsms.entity_id=n.nid');

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
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));


    //end
    
    //->condition('fsid.field_story_issue_date_value', $issue_date)
    //->condition('fssm.field_story_select_magazine_target_id', $field_issue_magazine)
    $query->condition('n.status', 1)->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range(0, 2);
    //echo $query; exit();
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result as $reskey => $resvalue){
        
            $title = $resvalue['title'];
            $type = $resvalue['type'];
            $nid = $resvalue['nid'];
            $created = $resvalue['created'];
            $changed = $resvalue['changed'];
            $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
            //$weburl = $base_url . "/node/" . $nid;
            $alias = drupal_get_path_alias('node/'.$nid.'');
            $weburl = $base_url ."/". $alias;
            $field_video_duration_value = $resvalue['field_video_duration_value'];
            // file url
            $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
            $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

            //related content
            $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
            $comment_cont = getCommentsCount($nid);

            // create date formating
            $firebase_url = get_node_firebase_weburl($nid);

            if($created){
              $create_datetime = date("Y-m-d H:i:s", $created);
              $create_date = date("Y-m-d H:i:s", $created);
            }
            else{
                $create_datetime = "";
                $create_date = "";
            }
            if($changed){
              $changed_datetime = date("Y-m-d H:i:s", $changed);
            }
            else{
                $changed_datetime = "";
            }
    
        $cover_story_list_array[$loop_count]['s_id'] = "$nid";
        $cover_story_list_array[$loop_count]['s_title'] = "$title";
        $cover_story_list_array[$loop_count]['s_share_link'] = "Universal_link";
        $cover_story_list_array[$loop_count]['s_short_desc'] = "$field_story_kicker_text_value";
        $cover_story_list_array[$loop_count]['s_comment_count'] = "$comment_cont";
        $cover_story_list_array[$loop_count]['s_small_image'] = "$file_small_img_url";
        $cover_story_list_array[$loop_count]['s_large_image'] = "$file_medium_img_url";
        $cover_story_list_array[$loop_count]['s_updated_datetime'] = "$changed_datetime";
        $cover_story_list_array[$loop_count]['s_is_locked'] = "0";
        $cover_story_list_array[$loop_count]['s_author_id'] = "id";
        $cover_story_list_array[$loop_count]['s_author_title'] = "author_name";
        $cover_story_list_array[$loop_count]['s_pcategory_id'] = "1";
        $cover_story_list_array[$loop_count]['s_pcategory_title'] = "Cover Story";

        $loop_count++;
  
}
  
  return $cover_story_list_array;
    
}

// 3rd

/**
 * main function for generate magazineEditionListPageRerourceValue array
 *
 * @return array
 */


function magazineEditionListPageRerourceValue($sdate = 0, $tdate = 0, $cpageno = 0) {
    
  
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();      
    $updated_datetime = "";
    
    
    // list array building
    $data = magazineEditionListPageRerourceValueList($sdate, $tdate, $cpageno);
    
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    
    //data array building
     $datacount = $data['lcount'];
     $data_up_time = $data['updated_datetime'];
    
    $data_array['issue_count'] = "$datacount";   
    $data_array['issue_display_count'] = "10";
    $data_array['issue_pagination_cap'] = "7";
    
    
    $data_array['issue'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for generate magazineEditionListPageRerourceValueList xml feed
 *
 * @return array
 */
function magazineEditionListPageRerourceValueList($sdate, $tdate, $cpageno) {
  // variable declaration
  global $base_url;  
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $issue_list_array = array();
  $listcount = 0;
  $range_max = 10;
  if(!$pageno == 0){
      $range_min = $pageno * $range_max;
  }
  else{
    $range_min = 0;
  }
  
  $loop_count = 0;
  
  // issue list query..
  
  $query_issue = db_select('node', 'n'); 
  $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
  $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
  $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');  
  
  $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
  $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
  $query_issue->fields('fsit', array('field_issue_title_value'));
  $query_issue->fields('n', array('nid'));
  
  $query_issue->condition('n.status', 1)->condition('n.type', 'issue')->range($range_min, $range_max);
  $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($result_issue as $reskey => $resvalue){
        
        //issue node 
        $issueid = $resvalue['nid'];
        //$node = node_load($issueid);
        $field_issue_large_cover_image_fid = $resvalue['field_issue_large_cover_image_fid'];
        $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);

        $field_issue_small_cover_image_fid = $resvalue['field_issue_small_cover_image_fid'];
        $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);

        $issue_date = $resvalue['field_issue_title_value'];
        $issue_nid = $resvalue['nid'];
        $i_story_count = getIssueStoryCount($issue_date);

        //$field_issue_magazine = $node->field_issue_magazine['und'][0]['target_id'];

        $issue_list_array[$loop_count]['i_id'] = "$issue_nid";
        $issue_list_array[$loop_count]['i_issue_date'] = "$issue_date";
        $issue_list_array[$loop_count]['i_story_count'] = "$i_story_count";
        $issue_list_array[$loop_count]['i_issue_cover_image'] = "$issue_cover_image"; 
        $loop_count++;
    }

  $data['lcount'] = $loop_count;
  $data['data'] = $issue_list_array;
  $data['updated_datetime'] = $changed_datetime;
  
  
  return $data;
}

/**
 * function for get count of story on issue
 * @pram $issue_date
 *
 * @return $count
 */

function getIssueStoryCount($issue_date){
    // issue list query..
  $count = 0;
  $query_issue = db_select('node', 'n');   
  $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');   
  $query_issue->fields('n', array('nid'));
  
  $query_issue->condition('n.status', 1)->condition('n.type', 'issue')->condition('fsit.field_issue_title_value', $issue_date);
  $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
  $count = count($result_issue);
  return $count;
}