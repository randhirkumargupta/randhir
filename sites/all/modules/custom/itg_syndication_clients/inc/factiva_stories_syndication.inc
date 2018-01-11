<?php

/**
 * @file
 * The ITG Syndication clients for factiva Story
 */
function factiva_stories_syndication() {
  $sections = get_factiva_sections();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_factiva_story_syndication($section_id, $file_name);
  }
}

/**
 * Function is used to generate BSB Story XML
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_factiva_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sheadline', 'sheadline.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

    if ($section_id != -1) {
      $query->condition('ti.tid', $section_id, '=');
      if ($days_ago = get_content_fetch_time($section_id)) {
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }

    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('sheadline', array('field_story_short_headline_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 30);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_factiva_story_syndication_xml($result, $section_name);
    $xml_path = 'public://factiva/stories/';
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
function genrate_factiva_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<artical>';
    $xml .= '<magazine>India Today Online</magazine>';
    $xml .= '<frequency>Daily</frequency>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_remove_tags_from_body($body);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section>India Today Online</section>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<headline>' . $value['field_story_short_headline_value'] . '</headline>';
      $xml .= '<introtext>' . $kicker_text . '</introtext>';
      $xml .= '<bodytext>' . $body . '</bodytext>';
      $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
    }
    $xml .= '</artical>';
  }

  return $xml;
}
