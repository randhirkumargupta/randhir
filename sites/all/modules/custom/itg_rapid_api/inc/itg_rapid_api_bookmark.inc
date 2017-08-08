<?php

/*
 * Bookmark responce data basd on user id 
 * @param $user_id
 * @return array of All the stories which is make bookmark/Read later ,  
 */

function bookmark_responce_data($user_id) {

  $output_array = array();
  $data_array = array();
  $updated_datetime = "";

  // list array building
  $data = bookmark_responce_datalist($user_id);


  if ($data['lcount'] > 0) {
    $output_array['status_code'] = "1";
    $output_array['status_message'] = "";
  }
  else {
    $output_array['status_code'] = "0";
    $output_array['status_message'] = "customised_message";
  }

  //data array building
  $data_array['news'] = $data['data'];
  $output_array['data'] = $data_array;

  return $output_array;
}

/*
 * Set Bookmark Stories based on user id 
 * @param $user_id , $node_id
 * @return array of All the stories which is bookmarked/Read later ,  
 */

function bookmark_set_data_responce($user_id, $node_id) {

  $output_array = array();
  $data_array = array();
  $updated_datetime = "";
  $data = array();

  $dtag = '';
  $user_activity = 'read_later';
  $activity_date = date('d-m-Y');
  $activity_date_time = date('d-m-Y h:i:s');

  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con) {
      $people = $con->front_user_activity;
      $actual_data = node_load($node_id);
      $get_previous_info = itg_get_front_activity_info($node_id, $actual_data->type, $user_id, $user_activity, $status = '');

      if (empty($get_previous_info['nid'])) {
        $actual_data = node_load($node_id);

        $primary_cat_id = $actual_data->field_primary_category[LANGUAGE_NONE][0]['value'];
        $primary_cat_name = taxonomy_term_load($actual_data->field_primary_category[LANGUAGE_NONE][0]['value']);
        $extra_image = $actual_data->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
        $path = $actual_data->path['source'];
        $qry = array("nid" => $node_id, "uid" => $user_id, "title" => $actual_data->title, "path" => $path, "image" => $extra_image, "primary_category_id" => $primary_cat_id, "primary_category_name" => $primary_cat_name->name, "ntype" => $actual_data->type, "activity" => $user_activity, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "status" => $dstatus, "timestamp" => time());
        $result = $people->insert($qry);
        $response = array('success' => $dstatus, 'activity' => $user_activity, 'type' => $actual_data->type);
        //print json_encode($response);
      }
      else {

        $newdata = array('$set' => array("status" => $dstatus, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "timestamp" => time()));
        $people->update(array("nid" => $node_id, "activity" => $user_activity, "uid" => $user_id), $newdata);
        $response = array("success" => $dstatus, 'activity' => $user_activity, 'type' => $actual_data->type);
        //print json_encode($response);
      }
    }
  }

  // list array building
  //$data = bookmark_set_responce_datalist($user_id);
  $output_array = bookmark_responce_data($user_id);

//    if ($data['lcount'] > 0) {
//        $output_array['status_code'] = "1";
//        $output_array['status_message'] = "";
//    } else {
//        $output_array['status_code'] = "0";
//        $output_array['status_message'] = "customised_message";
//    }
//
//    //data array building
//    $data_array['content'] = $data['data'];
//    $output_array['data'] = $data_array;

  return $output_array;
}

/*
 * Delete Bookmark Stories based on user id 
 * @param $user_id , $node_id
 * @return array of All the stories which is bookmarked/Read later ,  
 */

function bookmark_del_data_responce($user_id, $node_id) {

  $output_array = array();
  $data_array = array();
  $updated_datetime = "";

  $dtag = '';
  $user_activity = 'read_later';
  $activity_date = date('d-m-Y');
  $activity_date_time = date('d-m-Y h:i:s');

  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con) {
      $people = $con->front_user_activity;
      $qry = array("nid" => $node_id, "uid" => $user_id, 'activity' => 'read_later');
      $result = $people->remove($qry);
    }
  }

  // list array building
  $output_array = bookmark_responce_data($user_id);
  //$data = bookmark_set_responce_datalist($user_id);
//    if ($data['lcount'] > 0) {
//        $output_array['status_code'] = "1";
//        $output_array['status_message'] = "";
//    } else {
//        $output_array['status_code'] = "0";
//        $output_array['status_message'] = "customised_message";
//    }
//
//    //data array building
//    $data_array['content'] = $data['data'];
//    $output_array['data'] = $data_array;

  return $output_array;
}

/*
 * Function to return all the stories bookmarked by user
 */

function bookmark_set_responce_datalist($user_id) {

  $user_id = isset($user_id) ? $user_id : '';
  $news = array();
  $news2 = array();

  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->front_user_activity;
      $bookmark_data = $people->find(array('uid' => $user_id, 'activity' => 'read_later'));

      foreach ($bookmark_data as $book_data) {

        $news['id'] = $book_data["nid"];
        $news2[] = $news;
      }
      //print_r($news2);
    }
  }

  $data['data'] = $news2;
  $data['lcount'] = count($news2);
  return $data;
}

/*
 * return all the bookmark stories which is bookmarked by individual user
 */

function bookmark_responce_datalist($user_id) {

  $user_id = isset($user_id) ? $user_id : '';
  $news = array();
  $news2 = array();

  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->front_user_activity;
      $bookmark_data = $people->find(array('uid' => $user_id, 'activity' => 'read_later'));

      foreach ($bookmark_data as $book_data) {

        //to get some more details about the code
        $query = db_select('node', 'n');
        $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
        $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
        $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
        $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
        $query->fields('n', array('changed'));
        $query->fields('si', array('field_story_small_image_fid'));
        $query->fields('li', array('field_story_large_image_fid'));
        $query->condition('n.nid', $book_data["nid"]);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result as $k => $dd) {

          $changed = $dd['changed'];
          if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
          }
          else {
            $changed_datetime = "";
          }
          $file_small_img_url = completeFilePath($dd['field_story_small_image_fid']);
          $file_large_img_url = completeFilePath($dd['field_story_large_image_fid']);
        }


        $news['n_id'] = isset($book_data["nid"]) ? $book_data["nid"] : "";
        $news['n_type'] = isset($book_data["ntype"]) ? $book_data["ntype"] : "";
        $news['n_title'] = isset($book_data["title"]) ? t($book_data["title"]) : "";
        $news['n_small_image'] = "$file_small_img_url";
        $news['n_large_image'] = "$file_large_img_url";
        $news['n_updated_datetime'] = "$changed_datetime";

        $news2[] = $news;
      }
      //print_r($news2);
    }
  }

  $data['data'] = $news2;
  $data['lcount'] = count($news2);
  return $data;
}
