<?php

/*
 * Get the list of stories of a particular author
 */

function author_story_list($author_id = 0, $story_type = 0) {
  // variable decalartion

  $output_array = array();
  $data_array = array();
  $updated_datetime = "";

  // list array building
  if ($story_type == '0') { // latest story 
    $data = author_latest_storylist($author_id);
  }
  elseif ($story_type == '1') { //popular story
    $data = author_popular_storylist($author_id);
  }
  else {
    $data = '';
  }


  if ($data['lcount'] > 0) {
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

  $data_array['author_id'] = "$author_id";
  $data_array['news_count'] = "$datacount";
  $data_array['news_display_count'] = "0";
  $data_array['news_pagination_cap'] = "10";


  $data_array['news'] = $data['data'];
  $output_array['data'] = $data_array;

  return $output_array;
}

function author_latest_storylist($author_id) {
  global $base_url;

  $data = array();
  $type = array("videogallery", "photogallery", "story");
  
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id = n.nid');
  $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = pc.field_primary_category_value');
  $query->leftJoin('field_data_field_story_kicker_text', 'sk', 'sk.entity_id = n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
  $query->leftJoin('field_data_field_story_rating', 'sr', 'sr.entity_id = n.nid');

  $query->fields('n', array('nid', 'title', 'type', 'created'));
  $query->fields('td', array('tid', 'name'));
  $query->fields('sk', array('field_story_kicker_text_value'));
  $query->fields('si', array('field_story_small_image_fid'));
  $query->fields('li', array('field_story_large_image_fid'));

  $query->fields('si_file', array('uri'));
  $query->fields('li_file', array('uri'));
  $query->fields('sr', array('field_story_rating_value'));

  $query->condition('n.type', $type, 'IN');
  $query->condition('n.status', 1);
   $query->condition('bl.field_common_by_line_reporter_id_value', '%'.db_like($author_id).'%','LIKE');
  $query->orderBy('n.nid', 'DESC');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);


  $news = array();
  foreach ($result as $k => $res) {

    $comment_cont = getCommentsCount($res['nid']);
    $changed = $res['changed'];
    $n_view_count = getNodeViewCount($res['nid']);
    $n_share_count = getNodeShareCount($res['nid']);
    $file_small_img_url = file_create_url($res['uri']);
    $file_large_img_url = file_create_url($res['li_file_uri']);

    $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
    $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);

    if ($changed) {
      $changed_datetime = date("Y-m-d H:i:s", $changed);
    }
    else {
      $changed_datetime = "";
    }

    $news['n_id'] = $res['nid'];
    $new['n_type'] = $res['type'];
    $news['n_is_sponsored'] = "";
    $news['n_share_link'] = get_node_firebase_weburl($res['nid']);
    $news['n_title'] = $res['title'];
    $news['n_short_desc'] = $res['field_story_kicker_text_value'];
    $news['n_pcategory_id'] = $res['tid'];
    $news['n_pcategory_name'] = $res['name'];

    $news['n_rating'] = isset($res['field_story_rating_value']) ? $res['field_story_rating_value'] : '';
    $news['n_comment_count'] = "$comment_cont";
    $news['n_share_count'] = $n_share_count;
    $news['n_view_count'] = "$n_view_count";
    $news['n_small_image'] = $file_small_img_url;
    $news['n_large_image'] = $file_large_img_url;
    $news['n_updated_datetime'] = "$changed_datetime";
    $news2[] = $news;
  }

  $data['data'] = $news2;
  $data['lcount'] = count($result);
  return $data;
}

/*
 * function for get popular story based on max page visit and most shared stories
 *  i.e which has maximum loyality points
 *  @ args
 */

function author_popular_storylist($author_id) {
  global $base_url;

  $type = array("videogallery", "photogallery", "story");
  $data = array();
    
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.type', $type, 'IN');
  $query->condition('n.status', 1);
  $query->condition('bl.field_common_by_line_reporter_id_value', '%'.db_like($author_id).'%','LIKE');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  
  $popular_res = array();
  foreach ($result as $k => $res) {
    $popular_res[$res['nid']] = analytics_node_data($res['nid'], 'total');
  }
  //Sort Desc by total analytics count
  arsort($popular_res);

  $news = array();
  foreach ($popular_res as $pop_res_k => $pop_res_v) {

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_common_by_line_reporter_id', 'bl', 'bl.entity_id = n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id = n.nid');
    $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = pc.field_primary_category_value');
    $query->leftJoin('field_data_field_story_kicker_text', 'sk', 'sk.entity_id = n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('field_data_field_story_rating', 'sr', 'sr.entity_id = n.nid');
    //$query->leftJoin('itg_lrp_loyalty_points', 'lp', 'lp.node_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'created'));
    $query->fields('td', array('tid', 'name'));
    $query->fields('sk', array('field_story_kicker_text_value'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('li', array('field_story_large_image_fid'));

    $query->fields('si_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('sr', array('field_story_rating_value'));
    $query->condition('n.nid', $pop_res_k);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $k => $res) {

      $analy_data = analytics_node_data($res['nid']);
      $comment_cont = isset($analy_data['data_count_node_comment']) ? $analy_data['data_count_node_comment'] : '';
      $n_view_count = isset($analy_data['node_view_count']) ? $analy_data['node_view_count'] : '';
      $n_share_count = isset($analy_data['data_count_node_share']) ? $analy_data['data_count_node_share'] : '';

      $changed = $res['changed'];
      $file_small_img_url = completeFilePath($res['field_story_small_image_fid']);
      $file_large_img_url = completeFilePath($res['field_story_large_image_fid']);

      if ($changed) {
        $changed_datetime = date("Y-m-d H:i:s", $changed);
      }
      else {
        $changed_datetime = "";
      }

      $news['n_id'] = $res['nid'];
      $news['n_type'] = $res['type'];
      $news['n_is_sponsored'] = "";
      $news['n_share_link'] = get_node_firebase_weburl($res['nid']);
      $news['n_title'] = $res['title'];
      $news['n_short_desc'] = $res['field_story_kicker_text_value'];
      $news['n_pcategory_id'] = $res['tid'];
      $news['n_pcategory_name'] = $res['name'];

      $news['n_rating'] = isset($res['field_story_rating_value']) ? $res['field_story_rating_value'] : '';
      $news['n_comment_count'] = "$comment_cont";
      $news['n_share_count'] = $n_share_count;
      $news['n_view_count'] = "$n_view_count";
      $news['n_small_image'] = $file_small_img_url;
      $news['n_large_image'] = $file_large_img_url;
      $news['n_updated_datetime'] = "$changed_datetime";
      $news2[] = $news;
    }
  }

  $data['data'] = $news2;
  $data['lcount'] = count($result);
  return $data;
}


