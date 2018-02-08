<?php

/**
 * @file
 * The ITG Syndication clients for westbengal election
 */
function itg_rss_rsselections2016_westbengal_syndication() {
  $sections = getelections2016_westbenga_sections();
  foreach ($sections as $key => $value) {
    itg_genrate_rsselections2016_westbengal_syndication($key, $value);
  }
}

/**
 * Function for generate ections2016 westbengal xml feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_rsselections2016_westbengal_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);
    $type = array('story');
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->condition('ti.tid', $section_id, '=');
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_rsselections2016_westbengal_syndication_xml($result, $section_id, $section_name);
    $xml_path = 'public://elections2016/stories/';
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
 * @param int $section_id
 * @param string $section_name
 * @return string
 */
function genrate_rsselections2016_westbengal_syndication_xml($result = NULL, $section_id, $section_name) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<Root>';
    $xml .= '<idsection>' . $section_id . '</idsection>';
    $xml .= '<section>' . $section_name . '</section>';
    $xml .= '<totalarticle>' . count($result) . '</totalarticle>';
    $xml .= '<start_index>0</start_index>';
    $xml .= '<end_index>' . count($result) . '</end_index>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $publish_date = date("M d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $create_datetime = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $related = related_content_node_type($nid, 'story');
      $xml .= '<article>';
      $xml .= '<title>' . $value['title'] . '</title>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<kickerimage><![CDATA[' . $medium_img['imag_url'] . ']]></kickerimage>';
      $xml .= '<url>' . $url . '</url>';
      $xml .= '<create_date>' . $publish_date . '</create_date>';
      $xml .= '<create_datetime>' . $create_datetime . '</create_datetime>';
      $xml .= '<relateds>';
      $xml .= '<photos>' . $related['photos'] . '</photos>';
      $xml .= '<videos>' . $related['videos'] . '</videos>';
      $xml .= '<stories>' . $related['stories'] . '</stories>';
      $xml .= '</relateds>';
      $xml .= '</article>';
    }
    $xml .= '</Root>';
  }
  return $xml;
}
