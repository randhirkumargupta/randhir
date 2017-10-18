<?php

/**
 * @file
 * The ITG Syndication clients for MSN Story
 */
function itg_msn_feed_story_syndication() {
  $sections = getmsn_story_section_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_msn_feed_story_syndication($section_id, $file_name);
  }
}

/**
 * menu callback for bsb story syndication
 */
function itg_genrate_msn_feed_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_terms_name_by_ids(array($section_id));
    $section_name = $section_name[0]['name'];
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
<<<<<<< HEAD

=======
    
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
<<<<<<< HEAD

=======
    
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6

    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 20);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
<<<<<<< HEAD

=======
    
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
    $xml = genrate_msn_feed_story_syndication_xml($result, $section_name);
//    header( 'content-type: text/xml' );
//    print $xml;die;
    $xml_path = 'public://feeds/msnfeeds/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_msn_feed_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $current_date = date("Ymd\THisP");
    $xml = '<NewsML>';
    $xml .= '<NewsEnvelope>';
    $xml .= '<DateAndTime>' . $current_date . '</DateAndTime>';
    $xml .= '</NewsEnvelope>';
<<<<<<< HEAD

    foreach ($result as $key => $value) {

=======
    
    foreach ($result as $key => $value) {
      
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
      $nid = $value['nid'];
      $publish_date = date("Ymd\THisP", $value['created']);
      $modify_date = date("Ymd\THisP", $value['changed']);
      $reporter = get_byline_name_by_nid($nid);
<<<<<<< HEAD
      if (empty($reporter)) {
        $reporter = 'IndiaToday.in';
      }
=======
      if(empty($reporter)){
        $reporter = 'IndiaToday.in';
      }      
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);

      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $title = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['title']));
<<<<<<< HEAD

=======
      
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
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
      $xml .= '</NewsItem>';
    }
    $xml .= '</NewsML>';
  }
  return $xml;
}
