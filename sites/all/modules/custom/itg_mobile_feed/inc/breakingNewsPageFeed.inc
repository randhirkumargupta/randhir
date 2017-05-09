<?php
/**
 * Inc file contains the functions
 */

/**
 * main function for generate breakingNewsPage xml feed
 *
 * @return array
 */
function breakingNewsPageFeed() {
   //check into redis
   $redis_key = "itgd_breakingNewsPageFeed";
   $result_get = getRedis($redis_key);
   
   if($result_get['key_value'] !=""){
       $output = $result_get['key_value'];
       //echo "redis get - ". $output; exit();
   }
   else{
    // variable declation  
    global $base_url;
    $img_base = "http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public";
    $output = "";
    $ttl = 300;
    $output .= getMobileFeedXmlHeader();
    // call breaking news view
    $view_result = views_get_view_result('breaking_news', 'block_1');
    $nid = $view_result[0]->nid;
    // select breaking news..
    $alias = drupal_get_path_alias('node/'.$nid.'');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('dbody', array('body_value'));
    $query->condition('n.nid', $nid);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $title = $result[0]['title'];
    $body = $result[0]['body_value'];
    // create date formating
    $create_date = date("F d, Y", $result[0]['created']);
    $create_datetime = date(DATE_ATOM, $result[0]['created']);
    // file url
    $file_medium_img_url = completeFilePath($result[0]['field_story_medium_image_fid']);
    $field_story_small_image_fid = completeFilePath($result[0]['field_story_small_image_fid']);
    $web_url = $base_url ."/". $alias;

    $city = getCityByNid($nid);

    //print_ar($result, "home page breaking news");exit();

    $output .= "\n<item>
                  <enable>1</enable>
                  <id>" . $nid . "</id>
                  <title>" . $title . "</title>
                  <credit></credit>
                  <createddate>" . $create_date . "</createddate>
                  <createdtime>" . $create_datetime . "</createdtime>
                  <city>" . $city . "</city>
                  <courtesy></courtesy>
                  <thumbimage>" . $file_medium_img_url . "</thumbimage>
                  <longdescription>" . $body . "</longdescription>
                  <weburl>" . $web_url . "</weburl>
                  <url></url>
                  </item>";
    //call function getMobileFeedXmlFooter
    $output .= getMobileFeedXmlFooter();
    // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
   }
  
  //breaking news page feed file writing
  if ($output) {
    //$feed_file_path = getcwd() . "/sites/all/modules/custom/itg_mobile_feed/xml_it/stories";
    $feed_file_path = "public://xml_it/stories";
    file_prepare_directory($feed_file_path, FILE_CREATE_DIRECTORY);
    
    $feed_file_name = "breakingnews.xml";
    $return_flag = writeFeedFile($feed_file_path, $feed_file_name, $output);
  }
  //return $return_flag;
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;  die();
}

