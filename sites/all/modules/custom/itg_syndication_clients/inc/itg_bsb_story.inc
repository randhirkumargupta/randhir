<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */
function itg_bsb_story_syndication() {
  $sections = getbsb_client_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_bsb_story_syndication($section_id, $file_name);
  }
}

/**
 * Function is used to generate BSB Story XML
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_bsb_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);
    
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sheadline', 'sheadline.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_itg_tags', 'story_tags', 'story_tags.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

    if ($section_id == '1206584') {
      $query->condition('ti.tid', array(1206584, 1206567, 1206578, 1206533), 'IN');
    }
    else {
      $query->condition('ti.tid', $section_id, '=');
    }
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('sheadline', array('field_story_short_headline_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_large_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 30);
    
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_bsb_story_syndication_xml($result, $section_name);
    $xml_path = 'public://bsb/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_bsb_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<feed>';
    $xml .= '<provider>indiatoday</provider>';
    $xml .= '<language>en-US</language>';
    $xml .= '<news>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $meta_tags = get_node_metatags_by_nid($value['nid']);
      if ($meta_tags) {
        $keywords = unserialize($meta_tags['data']);
        $keywords = $keywords['keywords']['value'];
        if (!empty($keywords) && (strpos($keywords, "jio") || strpos($keywords, "reliance") || strpos($keywords, "vodafone") || strpos($keywords, "idea") || strpos($keywords, "bsnl") || strpos($keywords, "tata docomo") || strpos($keywords, "aircel") || strpos($keywords, "telenor") || strpos($keywords, "mts"))) {
          continue;
        }
      }

      $publish_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $modify_date = date("Y-m-d\TH:i:sP", $value['changed']);
      $place = get_content_city($value['nid']);
      $keyword = get_content_tags($value['nid'], TRUE);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_tags_from_body($body);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<id>' . $value['nid'] . '</id>';
      $xml .= '<short_title><![CDATA[' . $value['field_story_short_headline_value'] . ']]></short_title>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<publish_date><![CDATA[' . $publish_date . ']]></publish_date>';
      $xml .= '<last_update><![CDATA[' . $modify_date . ']]></last_update>';
      $xml .= '<place><![CDATA[' . $place . ']]></place>';
      $xml .= '<keywords><![CDATA[' . $keyword . ']]></keywords>';
      $xml .= '<url><![CDATA[' . $url . ']]></url>';
      $xml .= '<category>' . $category . '</category>';
      $xml .= '<synopsis><![CDATA[' . $kicker_text . ']]></synopsis>';
      $xml .= '<detail><![CDATA[' . $body . ']]></detail>';

      //xml tag for images
      $xml .= '<multimedia>';
      $xml .= '<images>';
      if (!empty($value['field_story_small_image_fid'])) {
        $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
        $xml .= '<image>';
        $xml .= '<caption><![CDATA[' . $small_img["caption"] . ']]></caption>';
        $xml .= '<items>';
        $xml .= '<item>';
        $xml .= '<width>180</width>';
        $xml .= '<height>118</height>';
        $xml .= '<url><![CDATA[' . $small_img["imag_url"] . ']]></url>';
        $xml .= '<format>' . $small_img["mime_type"] . '</format>';
        $xml .= '</item>';
        $xml .= '</items>';
        $xml .= '</image>';
      }
      if (!empty($value['field_story_large_image_fid'])) {
        $medium_img = get_image_info_by_fid($value['field_story_large_image_fid']);
        $xml .= '<image>';
        $xml .= '<caption><![CDATA[' . $medium_img["caption"] . ']]></caption>';
        $xml .= '<items>';
        $xml .= '<item>';
        $xml .= '<width>300</width>';
        $xml .= '<height>350</height>';
        $xml .= '<url><![CDATA[' . $medium_img["imag_url"] . ']]></url>';
        $xml .= '<format>' . $medium_img["mime_type"] . '</format>';
        $xml .= '</item>';
        $xml .= '</items>';
        $xml .= '</image>';
      }
      $xml .= '</images>';
      $xml .= '<videos></videos>'; // Need to discuss with Santosh Sir
      $xml .= '<audios></audios>'; // Need to discuss with Santosh Sir
      $xml .= '</multimedia>';

      // Code for related content
      $related_nodes = get_releted_content_by_nid($value['nid']);
      if (count($related_nodes) > 0) {
        $xml .= '<related>';
        foreach ($related_nodes as $value) {
          $related_node_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
          $xml .= '<item>';
          $xml .= '<id>' . $value["nid"] . '</id>';
          $xml .= '<title><![CDATA[' . $value["title"] . ']]></title>';
          $xml .= '<url><![CDATA[' . $related_node_url . ']]></url>';
          $xml .= '</item>';
        }
        $xml .= '</related>';
      }
      $xml .= '</item>';
    }
    $xml .= '</news>';
    $xml .= '</feed>';
  }
  return $xml;
}
