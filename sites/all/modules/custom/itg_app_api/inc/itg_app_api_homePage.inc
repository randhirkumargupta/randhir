<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate homePageJson array
 *
 * @return array
 */
function homePageJson() {
  $data = array();
  $data_packagelist = array();
  $data_topstories = array();
  $data_news = array();
  $data_magazine = array();

  //$data_packagelist = homePageJsonPackagelist();
  $data_topstories = homePageJsonTopstories();
  $data_news_india = homePageJsonNewslist_india();
  $data_news_world = homePageJsonNewslist_world();
  $data_magazine = homePageJsonMagazine();

  $data['status_code'] = "1";
  $data['status_message'] = "customised_message";

  //$data['data'][0] = $data_packagelist;
  $data['data'][0] = $data_topstories;
  $data['data'][1] = $data_news_india;
  $data['data'][2] = $data_news_world;
  $data['data'][3] = $data_magazine;

  return $data;
}

/**
 * main function for generate homePageJsonPackagelist array
 *
 * @return array
 */
function homePageJsonPackagelist() {
  $data_packagelist = array();
  $data_newslist = array();
  $n_photo = array();
  $n_video = array();
  $n_polls = array();
  $n_rating = array();

  $n_photo = getPhotolist($nid);
  $n_video = getVideolist($nid);
  $n_polls = getPolllist($node);
  $n_rating = getRating($node);
  $n_magazine = getMagazineList($node);

  $data_packagelist['id'] = "1";
  $data_packagelist['order'] = "1";
  $data_packagelist['type'] = "packagelist";
  $data_packagelist['title'] = "Assembly Election 2017";
  $data_packagelist['label'] = "LABEL See full coverage";
  $data_packagelist['show_label'] = "0";
  // news list

  $data_newslist[0]['n_id'] = "1";
  $data_newslist[0]['n_template_id'] = "1";
  $data_newslist[0]['n_type'] = "story";
  $data_newslist[0]['n_is_developing'] = "true";
  $data_newslist[0]['n_is_sponsored'] = "false";
  $data_newslist[0]['n_share_link'] = "universal_link";
  $data_newslist[0]['n_title'] = "title";
  $data_newslist[0]['n_description'] = "description";
  $data_newslist[0]['n_pcategory_id'] = "1";
  $data_newslist[0]['n_pcategory_name'] = "tag_name";
  $data_newslist[0]['n_comment_count'] = "100";
  $data_newslist[0]['n_small_image'] = "";
  $data_newslist[0]['n_large_image'] = "";
  $data_newslist[0]['n_image_credit'] = "";
  $data_newslist[0]['n_updated_datetime'] = "2017-03-05 23:42:09";
  $data_newslist[0]['n_photo'] = $n_photo;
  $data_newslist[0]['n_video'] = $n_video;
  $data_newslist[0]['n_polls'] = $n_polls;
  $data_newslist[0]['n_rating'] = $n_rating;
  $data_newslist[0]['n_magazine'] = "";

  $data_packagelist['news'] = $data_newslist;
  return $data_packagelist;
}

/**
 * main function for generate homePageJsonTopstories array
 *
 * @return array
 */
function homePageJsonTopstories() {
  // variable declation
  $data_topstories = array();
  $data_newslist = array();
  $n_photo = array();
  $n_video = array();
  $n_polls = array();
  $n_rating = array();
  $home_list_count = 0;
  $widget_name = "top_stories_widget";
  $range_max = 10;
  $range_min = 0;
  $order_by = 'ASC';

  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->leftJoin('taxonomy_index', 'ti', 'n.nid=ti.nid');
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
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
  $query->fields('ti', array('tid'));


  //end
  $query->condition('iwo.widget', $widget_name)->condition('n.status', 1)->condition('n.type', 'story')->groupBy('n.nid')->orderBy('iwo.weight', $order_by)->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $data_topstories['id'] = "2";
  $data_topstories['order'] = "2";
  $data_topstories['type'] = "newslist";
  $data_topstories['title'] = "Top Stories";
  $data_topstories['label'] = "Customized - Edit team will put it in Text Field";
  $data_topstories['show_label'] = "0";

  // xml tag wring for features widget..
  foreach ($result as $key => $value) {
    // varibale for json tag
    $title = $value['title'];
    $type = $value['type'];
    $nid = $value['nid'];
    $created = $value['created'];
    $changed = $value['changed'];
    $tid = $value['tid'];
    $field_story_kicker_text_value = $value['field_story_kicker_text_value'];

    $term = taxonomy_term_load($tid);
    $term_name = $term->name;

    // file url
    $file_small_img_url = completeFilePath($value['field_story_small_image_fid']);
    $file_medium_img_url = completeFilePath($value['field_story_medium_image_fid']);
    $comment_cont = getCommentsCount($nid);

    // create date formating
    $firebase_url = get_node_firebase_weburl($nid);

    if ($created) {
      $create_datetime = date("Y-m-d H:i:s", $created);
      $create_date = date("Y-m-d H:i:s", $created);
    }
    else {
      $create_datetime = "";
      $create_date = "";
    }
    if ($changed) {
      $changed_datetime = date("Y-m-d H:i:s", $changed);
    }
    else {
      $changed_datetime = "";
    }
    //json tag writing
    if ($type == "story") {
      // news list
//      $n_photo = getPhotolist($nid);
//      $n_video = getVideolist($nid);
//      $n_polls = getPolllist($node);
      $n_rating = getRating($node);
      $n_magazine = array();

      // custom function for get img caption
      $caption = getImgCaption($value['field_story_medium_image_fid']);
      // custom function for get img byline
      $byline = getImgByline($value['field_story_medium_image_fid']);

      $data_newslist[$home_list_count]['n_id'] = "$nid";
      $data_newslist[$home_list_count]['n_template_id'] = "1";
      $data_newslist[$home_list_count]['n_type'] = "story";
      $data_newslist[$home_list_count]['n_is_developing'] = "true";
      $data_newslist[$home_list_count]['n_is_sponsored'] = "false";
      $data_newslist[$home_list_count]['n_share_link'] = "$firebase_url";
      $data_newslist[$home_list_count]['n_title'] = "$title";
      $data_newslist[$home_list_count]['n_description'] = "$field_story_kicker_text_value";
      $data_newslist[$home_list_count]['n_pcategory_id'] = "$tid";
      $data_newslist[$home_list_count]['n_pcategory_name'] = "$term_name";
      $data_newslist[$home_list_count]['n_comment_count'] = "$comment_cont";
      $data_newslist[$home_list_count]['n_small_image'] = "$file_small_img_url";
      $data_newslist[$home_list_count]['n_large_image'] = "$file_medium_img_url";
      $data_newslist[$home_list_count]['n_image_credit'] = "$byline";
      $data_newslist[$home_list_count]['n_updated_datetime'] = "$changed_datetime";
      $data_newslist[$home_list_count]['n_photo'] = $n_photo;
      $data_newslist[$home_list_count]['n_video'] = $n_video;
      $data_newslist[$home_list_count]['n_polls'] = $n_polls;
      $data_newslist[$home_list_count]['n_rating'] = $n_rating;
      $data_newslist[$home_list_count]['n_magazine'] = $n_magazine;
      $home_list_count++;
    }
  }

  $data_topstories['news'] = $data_newslist;
  return $data_topstories;
}

/**
 * main function for generate homePageJsonNewslist_india array
 *
 * @return array
 */
function homePageJsonNewslist_india() {
  global $base_url;
  $data_news = array();
  $data_newslist = array();
  $n_photo = array();
  $n_video = array();
  $n_polls = array();
  $n_rating = array();
  $tid = HOME_PAGE_JSON_NEWS_LIST_INDIA;
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 10;
  //$photolist = array();
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }
  else {
    $range_min = 0;
  }
  $order_by = 'ASC';
  $type = array("videogallery", "photogallery", "story");
  $news_list_array = array();
  $photolist = array();
  $videolist = array();
  $loop_count = 0; {
    $listcount = 0;
    // code vid=14  start
    if ($tid > 0) {
      $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
    }
    else {
      $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, 0, $max_depth = NULL, $load_entities = FALSE);
    }
    $term_tree_count = count($term_tree);
    if ($term_tree_count) {
      foreach ($term_tree as $key => $value) {
        $tid_list[] = $value->tid;
      }
    }

    // code vid=14  end

    $data_news['id'] = "3";
    $data_news['order'] = "3";
    $data_news['type'] = "newslist";
    $data_news['title'] = "India";
    $data_news['label'] = "Customized - Edit team will put it in Text Field";
    $data_news['show_label'] = "0";


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
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));


    //end

    if (count($tid_list) > 0) {
      $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

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
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = $base_url . "/" . $alias;
      $field_video_duration_value = $resvalue['field_video_duration_value'];
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
      $comment_cont = getCommentsCount($nid);

      // create date formating
      $firebase_url = get_node_firebase_weburl($nid);

      if ($created) {
        $create_datetime = date("Y-m-d H:i:s", $created);
        $create_date = date("Y-m-d H:i:s", $created);
      }
      else {
        $create_datetime = "";
        $create_date = "";
      }
      if ($changed) {
        $changed_datetime = date("Y-m-d H:i:s", $changed);
      }
      else {
        $changed_datetime = "";
      }

      // custom function for get img caption
      $caption = getImgCaption($resvalue['field_story_medium_image_fid']);
      // custom function for get img byline
      $byline = getImgByline($resvalue['field_story_medium_image_fid']);

      $data_newslist[$listcount]['n_id'] = "$nid";
      $data_newslist[$listcount]['n_template_id'] = "1";
      $data_newslist[$listcount]['n_type'] = "$type";
      $data_newslist[$listcount]['n_is_developing'] = "true";
      $data_newslist[$listcount]['n_is_sponsored'] = "0";
      $data_newslist[$listcount]['n_share_link'] = "$firebase_url";
      $data_newslist[$listcount]['n_title'] = "$title";
      $data_newslist[$listcount]['n_description'] = "$field_story_kicker_text_value";
      $data_newslist[$listcount]['n_pcategory_id'] = "$tid";
      $data_newslist[$listcount]['n_pcategory_name'] = "India";
      $data_newslist[$listcount]['n_comment_count'] = "$comment_cont";
      $data_newslist[$listcount]['n_small_image'] = "$file_small_img_url";
      $data_newslist[$listcount]['n_large_image'] = "$file_medium_img_url";
      $data_newslist[$listcount]['n_image_credit'] = "$byline";
      $data_newslist[$listcount]['n_updated_datetime'] = "$changed_datetime";

      // photo list array

      if ($type == "photogallery") {
        $photolist = getPhotolist($nid);
      }
      $data_newslist[$listcount]['n_photo'] = $photolist;
      // re-insalize photolist
      $photolist = array();

      // video list array

      if ($type == "videogallery") {
        $videolist = getVideolist($nid);
      }
      $data_newslist[$listcount]['n_video'] = $videolist;
      // re-insalize vediolist
      $videolist = array();

      $n_polls = getPolllist($node); // homepage.inc
      $n_rating = getRating($node); // story.inc
      $n_magazine = array(); // homepage.inc

      $data_newslist[$listcount]['n_polls'] = $n_polls;
      $data_newslist[$listcount]['n_rating'] = $n_rating;
      $data_newslist[$listcount]['n_magazine'] = $n_magazine;

      $listcount++;
    }
  }

  $data_news['news'] = $data_newslist;

  return $data_news;
}

/**
 * main function for generate homePageJsonNewslist_world array
 *
 * @return array
 */
function homePageJsonNewslist_world() {
  global $base_url;
  $data_news = array();
  $data_newslist = array();
  $n_photo = array();
  $n_video = array();
  $n_polls = array();
  $n_rating = array();
  $tid = HOME_PAGE_JSON_NEWS_LIST_WORLD;
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 10;
  //$photolist = array();
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }
  else {
    $range_min = 0;
  }
  $order_by = 'ASC';
  $type = array("videogallery", "photogallery", "story");
  //$type = "videogallery, photogallery, story";
  $news_list_array = array();
  $photolist = array();
  $videolist = array();
  $loop_count = 0; {
    $listcount = 0;
    // code vid=14  start
    if ($tid > 0) {
      $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
    }
    else {
      $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, 0, $max_depth = NULL, $load_entities = FALSE);
    }
    $term_tree_count = count($term_tree);
    //echo "count:".$term_tree_count."<pre>"; print_r($term_tree);echo "</pre>";exit();
    if ($term_tree_count) {
      foreach ($term_tree as $key => $value) {
        $tid_list[] = $value->tid;
      }
    }

    // code vid=14  end

    $data_news['id'] = "4";
    $data_news['order'] = "4";
    $data_news['type'] = "newslist";
    $data_news['title'] = "World";
    $data_news['label'] = "Customized - Edit team will put it in Text Field";
    $data_news['show_label'] = "0";


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
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));


    //end

    if (count($tid_list) > 0) {
      $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->condition('n.status', 1)->condition('n.type', $type, 'IN')->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

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
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = $base_url . "/" . $alias;
      $field_video_duration_value = $resvalue['field_video_duration_value'];
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
      $comment_cont = getCommentsCount($nid);

      // create date formating
      $firebase_url = get_node_firebase_weburl($nid);

      if ($created) {
        $create_datetime = date("Y-m-d H:i:s", $created);
        $create_date = date("Y-m-d H:i:s", $created);
      }
      else {
        $create_datetime = "";
        $create_date = "";
      }
      if ($changed) {
        $changed_datetime = date("Y-m-d H:i:s", $changed);
      }
      else {
        $changed_datetime = "";
      }

      // custom function for get img caption
      $caption = getImgCaption($resvalue['field_story_medium_image_fid']);
      // custom function for get img byline
      $byline = getImgByline($resvalue['field_story_medium_image_fid']);

      $data_newslist[$listcount]['n_id'] = "$nid";
      $data_newslist[$listcount]['n_template_id'] = "1";
      $data_newslist[$listcount]['n_type'] = "$type";
      $data_newslist[$listcount]['n_is_developing'] = "true";
      $data_newslist[$listcount]['n_is_sponsored'] = "0";
      $data_newslist[$listcount]['n_share_link'] = "$firebase_url";
      $data_newslist[$listcount]['n_title'] = "$title";
      $data_newslist[$listcount]['n_description'] = "$field_story_kicker_text_value";
      $data_newslist[$listcount]['n_pcategory_id'] = "$tid";
      $data_newslist[$listcount]['n_pcategory_name'] = "World";
      $data_newslist[$listcount]['n_comment_count'] = "$comment_cont";
      $data_newslist[$listcount]['n_small_image'] = "$file_small_img_url";
      $data_newslist[$listcount]['n_large_image'] = "$file_medium_img_url";
      $data_newslist[$listcount]['n_image_credit'] = "$byline";
      $data_newslist[$listcount]['n_updated_datetime'] = "$changed_datetime";

      // photo list array

      if ($type == "photogallery") {
        $photolist = getPhotolist($nid);
      }
      $data_newslist[$listcount]['n_photo'] = $photolist;
      // re-insalize photolist
      $photolist = array();

      // video list array

      if ($type == "videogallery") {
        $videolist = getVideolist($nid);
      }
      $data_newslist[$listcount]['n_video'] = $videolist;
      // re-insalize vediolist
      $videolist = array();

      $n_polls = getPolllist($node); // homepage.inc
      $n_rating = getRating($node); // story.inc
      $n_magazine = array(); // homepage.inc

      $data_newslist[$listcount]['n_polls'] = $n_polls;
      $data_newslist[$listcount]['n_rating'] = $n_rating;
      $data_newslist[$listcount]['n_magazine'] = $n_magazine;

      $listcount++;
    }
  }

  $data_news['news'] = $data_newslist;

  return $data_news;
}

/**
 * main function for generate homePageJsonMagazine array
 *
 * @return array
 */
function homePageJsonMagazine() {
  $data_magazine = array();
  $data_newslist = array();
  $n_photo = array();
  $n_video = array();
  $n_polls = array();
  $n_rating = array();

  $n_magazine = getMagazineList(); // homepage.inc


  $data_magazine['id'] = "5";
  $data_magazine['order'] = "5";
  $data_magazine['type'] = "magazine";
  $data_magazine['title'] = "From The Magazine";
  $data_magazine['label'] = "Customized - Edit team will put it in Text Field";
  $data_magazine['show_label'] = "0";
  // news list


  $data_newslist[0]['n_id'] = "";
  $data_newslist[0]['n_template_id'] = "";
  $data_newslist[0]['n_type'] = "";
  $data_newslist[0]['n_is_developing'] = "";
  $data_newslist[0]['n_is_sponsored'] = "";
  $data_newslist[0]['n_share_link'] = "";
  $data_newslist[0]['n_title'] = "";
  $data_newslist[0]['n_description'] = "";
  $data_newslist[0]['n_pcategory_id'] = "";
  $data_newslist[0]['n_pcategory_name'] = "";
  $data_newslist[0]['n_comment_count'] = "";
  $data_newslist[0]['n_small_image'] = "";
  $data_newslist[0]['n_large_image'] = "";
  $data_newslist[0]['n_image_credit'] = "";
  $data_newslist[0]['n_updated_datetime'] = "";
  $data_newslist[0]['n_photo'] = $n_photo;
  $data_newslist[0]['n_video'] = $n_video;
  $data_newslist[0]['n_polls'] = $n_polls;
  $data_newslist[0]['n_rating'] = $n_rating;
  $data_newslist[0]['n_magazine'] = $n_magazine;

  $data_magazine['news'] = $data_newslist;

  return $data_magazine;
}

/**
 * function for generate getPolllist array
 *
 * @return array
 */
function getPolllist($node) {
  $poll = array();
  return $poll;
}

/**
 * function for generate getMagazineList array
 *
 * @return array
 */
function getMagazineList() {
  $magazine = array();
  $issue = array();
  $story = array();

  $loop_count = 0;
  $range_min = 0;
  $range_max = 5;
  // issue list query..

  $query_issue = db_select('node', 'n');
  $query_issue->leftJoin('field_data_field_issue_large_cover_image', 'fsli', 'fsli.entity_id=n.nid');
  $query_issue->leftJoin('field_data_field_issue_small_cover_image', 'fssi', 'fssi.entity_id=n.nid');
  $query_issue->leftJoin('field_data_field_issue_title', 'fsit', 'fsit.entity_id=n.nid');

  $query_issue->fields('fsli', array('field_issue_large_cover_image_fid'));
  $query_issue->fields('fssi', array('field_issue_small_cover_image_fid'));
  $query_issue->fields('fsit', array('field_issue_title_value'));
  $query_issue->fields('n', array('nid'));

  $query_issue->condition('n.status', 1)->condition('n.type', 'issue')->orderBy('n.created', 'DESC')->range($range_min, $range_max);
  $result_issue = $query_issue->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result_issue as $reskey => $resvalue) {

    //issue node 
    $issueid = $resvalue['nid'];
    $field_issue_large_cover_image_fid = $resvalue['field_issue_large_cover_image_fid'];
    $issue_cover_image = $field_issue_large_cover_image_url = completeFilePath($field_issue_large_cover_image_fid);

    $field_issue_small_cover_image_fid = $resvalue['field_issue_small_cover_image_fid'];
    $issue_digitalmag_url = $field_issue_small_cover_image_url = completeFilePath($field_issue_small_cover_image_fid);

    $issue_date = $resvalue['field_issue_title_value'];
    $issue_nid = $resvalue['nid'];

    $story = getMagazineStory($issue_date);

    $issue[$loop_count]['issue_id'] = "$issue_nid";
    $issue[$loop_count]['i_issue_date'] = "$issue_date";
    $issue[$loop_count]['issue_cover_image'] = "$issue_cover_image";
    $issue[$loop_count]['story'] = $story;
    $loop_count++;
  }


  $magazine['issue'] = $issue;

  //echo "<pre>magazine";  print_r($magazine);echo "</pre>";exit();

  return $magazine;
}

/**
 * function for generate getMagazineStory array
 *
 * @return array
 */
function getMagazineStory($issue_date) {
  $story = array();

  // select issue stories
  $range_min = 0;
  $range_max = 5;

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
  //field_data_field_itg_common_by_line_name
  $query->leftJoin('field_data_field_itg_common_by_line_name', 'fsbl', 'fsbl.entity_id=n.nid');
  //field_data_field_reporter_unique_id
  $query->leftJoin('field_data_field_reporter_unique_id', 'fsri', 'fsri.entity_id=n.nid');
  //field_data_field_primary_category
  $query->leftJoin('field_data_field_primary_category', 'fci', 'fci.entity_id=n.nid');

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

  $query->fields('fsbl', array('field_itg_common_by_line_name_value'));
  $query->fields('fsri', array('field_reporter_unique_id_value'));
  $query->fields('fci', array('field_primary_category_value'));

  //end
  $query->condition('n.status', 1)->condition('n.type', 'story')->condition('fsid.field_story_issue_date_value', $issue_date)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $loop_count = 0;

  foreach ($result as $reskey => $resvalue) {

    $title = $resvalue['title'];
    $type = $resvalue['type'];
    $nid = $resvalue['nid'];
    $created = $resvalue['created'];
    $changed = $resvalue['changed'];
    $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
    $alias = drupal_get_path_alias('node/' . $nid . '');
    $weburl = $base_url . "/" . $alias;
    $field_video_duration_value = $resvalue['field_video_duration_value'];
    // file url
    $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
    $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

    //related content
    $comment_cont = getCommentsCount($nid);

    // create date formating
    $firebase_url = get_node_firebase_weburl($nid);

    if ($created) {
      $create_datetime = date("Y-m-d H:i:s", $created);
      $create_date = date("Y-m-d H:i:s", $created);
    }
    else {
      $create_datetime = "";
      $create_date = "";
    }
    if ($changed) {
      $changed_datetime = date("Y-m-d H:i:s", $changed);
    }
    else {
      $changed_datetime = "";
    }
    $conf = getStoryConfigVal($nid);
    $is_lock = 0;
    if (in_array("lock_story", $conf)) {
      $is_lock = 1;
    }

    $field_itg_common_by_line_name_value = $resvalue['field_itg_common_by_line_name_value'];
    $field_reporter_unique_id_value = $resvalue['field_reporter_unique_id_value'];
    $field_reporter_unique_id_value = str_replace("byline_", "", $field_reporter_unique_id_value);

    $field_primary_category_value = $resvalue['field_primary_category_value'];
    $term = taxonomy_term_load($field_primary_category_value);
    $term_name = $term->name;

    $story[$loop_count]['s_id'] = "$nid";
    $story[$loop_count]['s_title'] = "$title";
    $story[$loop_count]['s_share_link'] = "$firebase_url";
    $story[$loop_count]['s_short_desc'] = "$field_story_kicker_text_value";
    $story[$loop_count]['s_comment_count'] = "$comment_cont";
    $story[$loop_count]['s_small_image'] = "$file_small_img_url";
    $story[$loop_count]['s_large_image'] = "$file_medium_img_url";
    $story[$loop_count]['s_updated_datetime'] = "$changed_datetime";
    $story[$loop_count]['s_is_locked'] = "$is_lock";
    $story[$loop_count]['s_author_id'] = "$field_reporter_unique_id_value";
    $story[$loop_count]['s_author_title'] = "$field_itg_common_by_line_name_value";
    $story[$loop_count]['s_pcategory_id'] = "$field_itg_common_by_line_name_value";
    $story[$loop_count]['s_pcategory_title'] = "$term_name";
    $loop_count++;
  }



  return $story;
}
