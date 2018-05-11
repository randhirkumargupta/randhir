<?php

/**
 * @file
 * The ITG Syndication clients for MSN Story
 */
function itg_msn_feed_story_syndication() {
  $sections = getmsn_story_section_array();
  foreach ($sections as $file_name => $section_id) {
    itg_genrate_msn_feed_story_syndication($section_id, $file_name);
  }
}

/**
 * menu callback
 * Function for generate msn static feed
 */
function itg_rss_msnstaticfeeds() {
  itg_generate_msn_static_stories_what_to_expect();
  itg_generate_msn_static_stories_top_news();
  itg_msn_karnataka_election_who_said_what();
}

/**
 * Generate static msn stories feed
 */
function itg_generate_msn_static_stories_what_to_expect() {
  $data = array();
  $xml = theme('msn_static_stories_what_to_expect', array('data' => $data));
  $xml_path = 'public://msn/stories/';
  $file_path = $xml_path . 'what-to-expect-msn.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Generate static msn stories feed
 */
function itg_generate_msn_static_stories_top_news() {
  $data = array();
  $xml = theme('msn_static_stories_top_news', array('data' => $data));
  $xml_path = 'public://msn/stories/';
  $file_path = $xml_path . 'top-news-msn.xml';
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml);
  fclose($fpd);
}

/**
 * Function is used to Generate MSN xml feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_msn_feed_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);
    $type = array('story');
    $query = db_select('node', 'n');
    //$query->leftJoin('itg_widget_order', 'iwo', 'iwo.nid=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    //for media content start
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');    
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    //for media content end
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
     //for media content start
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('mi', array('field_story_medium_image_fid'));
    //for media content end

    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    //$query->condition('iwo.widget', 'section_wise_widget');
    //$query->orderBy('iwo.weight', 'DESC');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 20);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_msn_feed_story_syndication_xml($result, $section_name);
    $xml_path = 'public://';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param Array $result
 * @param string $category
 * @return string
 */
function genrate_msn_feed_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $current_date = date("Ymd\THisP");
    $xml = "<?xml version='1.0' encoding='utf-8'?><NewsML xmlns:media='http://search.yahoo.com/mrss/' xmlns:mi='http://schemas.ingestion.microsoft.com/common/' version='2.0'>";
    $xml .= '<NewsEnvelope>';
    $xml .= '<DateAndTime>' . $current_date . '</DateAndTime>';
    $xml .= '</NewsEnvelope>';

    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $publish_date = date("Ymd\THisP", $value['created']);
      $modify_date = date("Ymd\THisP", $value['changed']);
      $reporter = get_byline_name_by_nid($nid);
      if (empty($reporter)) {
        $reporter = 'IndiaToday.in';
      }
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);

      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $title = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['title']));
      
      ############## prepare media content start ################
      
      $file_medium_img_url = completeFilePath($value['field_story_medium_image_fid']);      
      $file_ext_large_img_url = completeFilePath($value['field_story_extra_large_image_fid']);
      $nObject = new stdClass();
      $nObject->nid = $nid;
      $author = (array) generateAuthorTagStory_syndication($nObject, 1);
      $a_title= $author['a_title'];
      $media_cont = "";
      $media_cont .= '<media:content url="'.$file_ext_large_img_url.'">';
      $media_cont .= '<media:thumbnail url="'.$file_medium_img_url.'"/>';
      $media_cont .= '<media:credit>'.$a_title.'</media:credit>';
      $media_cont .= '<media:title>
                    <![CDATA[
                    '.$title.'
                    ]]>
                    </media:title>';
      $media_cont .= '<media:text>
                    <![CDATA[
                    '.$kicker_text.'
                    ]]>
                    </media:text>';
      $media_cont .= '<mi:focalRegion/>';
      $media_cont .= '<mi:hasSyndicationRights>1</mi:hasSyndicationRights>';
      $media_cont .= '<mi:licenseId>0</mi:licenseId>';
      $media_cont .= '<mi:licensorName/>';
      $media_cont .= '</media:content>';
      
      ############## prepare media content end ################

      $year = date('Y');
      $xml .= '<NewsItem LinkType="normal">';
      $xml .= '<Identification>';
      $xml .= '<NewsIdentifier>';
      $xml .= '<ProviderId>' . $reporter . '</ProviderId>';
      $xml .= '</NewsIdentifier>';
      $xml .= '</Identification>';
      $xml .= '<NewsManagement>';
      $xml .= '<NewsItemType FormalName="News"/>';
      $xml .= '<FirstCreated>' . $publish_date . '</FirstCreated>';
      $xml .= '<ThisRevisionCreated>' . $modify_date . '</ThisRevisionCreated>';
      $xml .= '<Status FormalName="Usable"/>';
      $xml .= '</NewsManagement>';
      $xml .= '<NewsComponent EquivalentsList="no" Essential="no" Duid="' . $nid . '">';
      $xml .= '<NewsLines>';
      $xml .= '<CopyrightLine>' . $year . ' India Today.</CopyrightLine>';
      $xml .= '</NewsLines>';
      $xml .= '<NewsComponent Duid="' . $nid . '">';
      $xml .= '<DateLine>' . $publish_date . '</DateLine>';
      $xml .= '<Author>' . $reporter . '</Author>';
      $xml .= '<NewsComponent>';
      $xml .= '<Role FormalName="Main"/>';
      $xml .= '<NewsLines>';
      $xml .= '<HeadLine>' . $title . '</HeadLine>';
      $xml .= '<SlugLine>' . $kicker_text . '</SlugLine>';
      $xml .= '<MoreLink/>';
      $xml .= '</NewsLines>';
      $xml .= '<ContentItem>';
      $xml .= '<MediaType FormalName="ComplexData"/>';
      $xml .= '<MimeType FormalName="text/vnd.IPTC.NITF"/>';
      $xml .= '<DataContent>';
      $xml .= '<nitf>';
      $xml .= '<body>';
      $xml .= '<body.content><![CDATA[' . $body . ']]></body.content>';
      $xml .= '</body>';
      $xml .= '</nitf>';
      $xml .= '<weburl>' . $url . '</weburl>';
      $xml .= '</DataContent>';
      $xml .= '</ContentItem>';
      $xml .= '</NewsComponent>';
      $xml .= '</NewsComponent>';
      $xml .= '</NewsComponent>';
      //for media content start
      $xml .= $media_cont;
      //for media content start
      $xml .= '</NewsItem>';
    }
    $xml .= '</NewsML>';
  }
  return $xml;
}

/**
 * function for get author list for story
 * @pram object $node
 *
 * @return array
 */
function generateAuthorTagStory_syndication($node, $status) {
  //$byline = itg_common_get_latest_byline($node->nid, $status);
  $byline_data = itg_get_multi_byline_details($node->nid, $status);
  $aid = $byline_data[0]['nid'];
  $a_title = $byline_data[0]['title'];
  $extra_laarge_file = file_load($byline_data[0]['extra_large_image']);
  $a_image = file_create_url($extra_laarge_file->uri);
  $a_twitter_handler = $byline_data[0]['twitter_handle'];
  $output = array();
  $output['a_id'] = "$aid";
  $output['a_title'] = "$a_title";
  $output['a_image'] = "$a_image";
  $output['a_twitter_handler'] = "$a_twitter_handler";
  return $output;
}

/**
 * @file
 * The ITG Syndication Get external story list
 */
function itg_msn_karnataka_election_who_said_what() {
  $section_id = '1790070';
  $file_name  = 'msn/indiatoday/karnataka_election_2018_who_said_what.xml';
  $node_list = karnataka_election_who_said_what_nodelist($section_id);
  itg_generate_karnataka_election_who_said_what_syndication($section_id, $file_name, $node_list);
}

/**
 * @file
 * The ITG Syndication clients for karnataka election
 */
function karnataka_election_who_said_what_nodelist($section_id) {
  $cat_id = $section_id;
  $limit = 15;
  $type = 'who-said-what';
  $node_list = array();
  $result = get_who_said_what_from_cat($cat_id, $limit, $type);
  if(isset($result) && count($result) > 0){
    foreach ($result as $data) {
        $story_path = substr($data->field_story_external_url_value,0,-11);
        $story_id = explode("-",$story_path);
        $node_list[] = end($story_id);
    }
  }
  return $node_list;
}


/**
 * Function is used to Generate Karnataka Election 2018 xml feed
 * @param int $section_id
 * @param string $file_name
 * @param array $node_list
 */
function itg_generate_karnataka_election_who_said_what_syndication($section_id = NULL, $file_name, $node_list) {
  if (!empty($section_id) && !empty($node_list)) {
    $section_name = get_term_name_by_tid($section_id);
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    //for media content start
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');    
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
     //for media content start
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('mi', array('field_story_medium_image_fid'));
    //for media content end
    $query->condition('n.nid', $node_list,'IN');
    $query->range(0, 20);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_msn_feed_story_syndication_xml($result, $section_name);
    $xml_path = 'public://';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}
