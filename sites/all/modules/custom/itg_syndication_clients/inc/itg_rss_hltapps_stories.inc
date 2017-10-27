<?php

/**
 * @file
 * The ITG Syndication clients for Hltapps
 */
function itg_rss_hltapps_stories() {
  $sections = get_hltapps_sections('story');
  foreach ($sections as $file_name => $section_id) {
    itg_genrate_hltapps_stories_syndication($section_id, $file_name);
  }
}

/**
 * menu callback for Hltapps story syndication
 */
function itg_genrate_hltapps_stories_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    if ($section_id != -1) {
      $section_name = get_term_name_by_tid($section_id);
    }
    else {
      $section_name = 'Latest News';
    }

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

    if (!empty($section_id) && $section_id != -1) {
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->condition('ti.tid', $section_id, '=');
    }else{
      $section_id = 1;
    }

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_large_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('pc', array('field_primary_category_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 20);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_hltapps_stories_xml($result, $section_name, $section_id);
    $xml_path = 'public://hltapps/stories/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_hltapps_stories_xml($result = NULL, $category, $section_id) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<root>';
    $xml .= '<id>1</id>';
    $xml .= '<title><![CDATA[ ' . $category . ' ]]></title>';
    $xml .= '<itemcount>' . count($result) . '</itemcount>';
    foreach ($result as $key => $value) {
      $nid = $value['nid'];
      $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml_story_file = 'story' . $nid . '.xml';
      $xml .= '<item>';
      $xml .= '<title><![CDATA[ ' . $value["title"] . ' ]]></title>';
      $xml .= '<shortdescription><![CDATA[ ' . $kicker_text . ' ]]></shortdescription>';
      $xml .= '<thumbimage><![CDATA[ ' . $small_img["imag_url"] . ' ]]></thumbimage>';
      $xml .= '<url>' . $xml_story_file . '</url>';
      $xml .= '<weburl><![CDATA[ ' . $url . ' ]]></weburl>';
      $xml .= '<createddate> ' . $publish_date . ' </createddate>';
      $xml .= '</item>';
      genrate_hltapps_stories_detail_xml($value, $category, $xml_story_file, $section_id);
    }
    $xml .= '</root>';
  }
  return $xml;
}

function genrate_hltapps_stories_detail_xml($value, $category, $xml_story_file, $section_id) {
  $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
  $updated_date = date("H:i e", strtotime($value['changed']));
  $byline = get_byline_name_by_nid($value['nid']);
  $place = get_content_city($value['nid']);
  $body = remove_extra_tag_in_body($value["body_value"]);
  $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
  $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
  $xml_detail = '<root>';
  $xml_detail .= '<item>';
  $xml_detail .= '<id>'.$value["nid"].'</id>';
  $xml_detail .= '<sectionid>'.$section_id.'</sectionid>';
  $xml_detail .= '<sectionname>'.$category.'</sectionname>';
  $xml_detail .= '<title><![CDATA[ ' . $value["title"] . ' ]]></title>';
  $xml_detail .= '<credit><![CDATA[ ' . $byline . ' ]]></credit>';
  $xml_detail .= '<createddate> ' . $publish_date . ' </createddate>';
  $xml_detail .= '<updateddate> ' . $updated_date . ' </updateddate>';
  $xml_detail .= '<city><![CDATA[' . $place . ' ]]></city>';
  $xml_detail .= '<courtesy><![CDATA[' . $place . ' ]]></courtesy>';
  $xml_detail .= '<longdescription><![CDATA[' . $body . ' ]]></longdescription>';
  $xml_detail .= '<images>';
  $xml_detail .= '<image>';
  $xml_detail .= '<thumbimage><![CDATA[' . $small_img["imag_url"] . ' ]]></thumbimage>';
  $xml_detail .= '<largeimage><![CDATA[' . $large_img["imag_url"] . ' ]]></largeimage>';
  $xml_detail .= '</image>';
  $xml_detail .= '</images>';
  $xml_detail .= get_comment_xml_tag($value['nid']);
  $xml_detail .= '</item>';
  $xml_detail .= '</root>';
  $xml_path = 'public://hltapps/stories/';
  $file_path = $xml_path . $xml_story_file;
  $fpd = fopen($file_path, "w");
  fwrite($fpd, $xml_detail);
  fclose($fpd);
}
