<?php

/**
 * @file
 * The ITG Syndication clients for factiva Story
 */
function syndication_interface_cms() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'issue');
  $query->orderBy('n.nid', "DESC");
  $query->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  itgd_genrate_factiva_syndication($result);
}

/**
 * Function is used to generate factiva Story XML
 * @param int $section_id
 * @param string $file_name
 */
function itgd_genrate_factiva_syndication($issue_result) {
  if (!empty($issue_result)) {
    $issue_title = date('F d, Y', strtotime($issue_result[0]['title']));
    $title = $issue_result[0]['title'];
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('field_data_field_story_issue_date', 'isuue', 'n.nid=isuue.entity_id');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->condition('isuue.field_story_issue_date_value', $title, '=');
    $query->condition('n.type', 'story', '=');
    $query->groupBy('n.nid');
    $query->orderBy('n.created', 'DESC');
    $query->fields('dbody', array('body_value'));
    $query->fields('pc', array('field_primary_category_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    genrate_factiva_latest_issue_xml($result, $issue_title, $issue_result);
    genrate_para_text_latest_issue_xml($result, $issue_title, $issue_result);
    genrate_syndication_xml_latest_issue_xml($result, $issue_title, $issue_result);
    
    //1206735 xml
    genrate_syndication_xml_cat_1206735();
  }
  genrate_indiatoday_lifestyle_monthly_1206567_xml();
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_factiva_latest_issue_xml($result, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<artical>';
    $xml .= '<magazine>India Today</magazine>';
    $xml .= '<frequency>Weekly</frequency>';
    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $publish_date = date("F d, Y", strtotime($issue_title));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section>' . $primary_cat . '</section>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<headline>' . $value['title'] . '</headline>';
      $xml .= '<introtext>' . $kicker_text . '</introtext>';
      $xml .= '<bodytext>' . $body;
      $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
      $xml .= '</bodytext>';
    }
    $xml .= '</artical>';
  }
  $xml_path = 'public://rss-feeds/xml_data/syndications/';
  $file_path = $xml_path . 'factiva-latest-issue.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_para_text_latest_issue_xml($result, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;



    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $publish_date = date("F d, Y", strtotime($issue_title));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<article>';
      $xml .= '<magazine>India Today</magazine>';
      $xml .= '<articletype>' . $primary_cat . '</articletype>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<page></page>';
      $xml .= '<frequency>Weekly</frequency>';
      $xml .= '<author></author>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<volumenumber></volumenumber>';
      $xml .= '<intellectualpropertyowner>Living Media India Limited</intellectualpropertyowner>';
      $xml .= '<headline>' . $value['title'] . '</headline>';
      $xml .= '<secondaryheadline>' . $kicker_text . '</secondaryheadline>';
      $xml .= '<bodytext>' . $body . '</bodytext>';
      $xml .= '</article>';
    }
  }
  $xml_path = 'public://rss-feeds/xml_data/syndications/';
  $file_path = $xml_path . 'para-feed.txt';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_syndication_xml_latest_issue_xml($result, $issue_title, $issue_result) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $publish_date = date("F d, Y", strtotime($issue_title));
    $xml = '<?xml version="1.0" encoding="ISO-8859-1"?>';
    $xml .= '<root>';
    $xml .= '<magazine>India Today</magazine>';
    $xml .= '<frequency>Weekly</frequency>';
    $xml .= '<edition>' . $publish_date . '</edition>';
    $xml .= '<items>';
    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? 'IndiaToday.in' : $byline;
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section name="' . $primary_cat . '">';
      $xml .= '<article>';
      $xml .= '<headline>' . $value['title'] . '</headline>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<introtext>' . $kicker_text . '</introtext>';
      $xml .= '<bodytext>' . $body . '</bodytext>';
      $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
      $xml .= '</article>';
      $xml .= '</section>';
    }
    $xml .= '</items>';
  }
  $xml .= '</root>';
  $xml_path = 'public://rss-feeds/xml_data/syndications/';
  $file_path = $xml_path . 'syndication-xml-latest-issue.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}
/**
 * genrate_syndication_xml_cat_1206735
 * @return string
 */
function genrate_syndication_xml_cat_1206735() {
    $xml = '';
    $tid = 1206735;
    $end_date = $start_date = date("Y-m-d", time());    
    $start_date_timestamp = strtotime($start_date . " 00:00:00");
    $end_date_timestamp = strtotime($end_date . " 23:59:00");
    // select node belong from current term id or child term id
    
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'n.nid=ti.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
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
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));
    $query->fields('li', array('field_story_large_image_fid'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('pc', array('field_primary_category_value'));
    //end

	$query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $tid, '=');    
    $query->condition('n.created', $start_date_timestamp, '>=');
    $query->condition('n.created', $end_date_timestamp, '<=');
    $query->condition('n.status', 1)->condition('n.type', 'story', '=')->orderBy('n.created', 'DESC')->groupBy('n.nid');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    if (!empty($result)) { 
        global $base_url;
        $publish_date = date("F d, Y", time());
        $xml = '<?xml version="1.0" encoding="ISO-8859-1"?>';
        $xml .= '<root>';
        $xml .= '<magazine>India Today Television</magazine>';
        $xml .= '<frequency>Daily</frequency>';
        $xml .= '<edition>' . $publish_date . '</edition>';
        $xml .= '<items>';
        foreach ($result as $key => $value) {
            //$primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
            $prime_cat = getNodePrimeCatByNid($value['nid']);
            $byline = get_byline_name_by_nid($value['nid']);
            $byline = empty($byline) ? 'IndiaToday.in' : $byline;
            $body = remove_extra_tag_in_body($value["body_value"]);
            $body = itg_replace_token_with_data($body, $value['nid']);
            $body = itg_remove_tags_from_body($body);
            $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

            $xml .= '<section name="' . $prime_cat->name . '">';
            $xml .= '<article>';
            $xml .= '<headline>' . $value['title'] . '</headline>';
            $xml .= '<byline>' . $byline . '</byline>';
            $xml .= '<introtext>' . $kicker_text . '</introtext>';
            $xml .= '<bodytext>' . $body . '</bodytext>';
            $xml .= '<copyright>Reproduced From India Today Online. Copyright ' . date("Y") . '. LMIL. All rights reserved.</copyright>';
            $xml .= '</article>';
            $xml .= '</section>';
        }
        $xml .= '</items>';
    }
    $xml .= '</root>';
    $xml_path = 'public://rss-feeds/xml_data/syndications/';
    $file_path = $xml_path . 'India_Today_Television_'.$start_date.'.xml';
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
}


/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $category
 * @return string
 */
function genrate_indiatoday_lifestyle_monthly_1206567_xml() {
  $xml = '';
  $tid = 1206567;
  // select node belong from current term id or child term id
  $query = db_select('node', 'n');
  $query->join('taxonomy_index', 'ti', 'n.nid=ti.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  //join  for field value
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
  $query->fields('dbody', array('body_value'));
  $query->fields('pc', array('field_primary_category_value'));
  //end
  $days_ago = strtotime(date('Y-m-d', strtotime('-1 month')));
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('ti.tid', $tid, '=');
  $query->condition('n.status', 1)->condition('n.type', 'story', '=')->orderBy('n.created', 'DESC')->groupBy('n.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<artical>';
    $xml .= "<magazine>Women's Health</magazine>";
    $xml .= '<frequency>--</frequency>';
    foreach ($result as $key => $value) {
      $primary_cat = get_term_name_by_tid($value['field_primary_category_value']);
      $byline = get_byline_name_by_nid($value['nid']);
      $byline = empty($byline) ? '' : $byline;
      $publish_date = date("F d, Y", strtotime($value['field_itg_content_publish_date_value']));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_tags_from_body($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));

      $xml .= '<section>' . $primary_cat . '</section>';
      $xml .= '<edition>' . $publish_date . '</edition>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<headline>' . stripInvalidXml($value['title']) . '</headline>';
      $xml .= '<introtext>' . stripInvalidXml($kicker_text) . '</introtext>';
      $xml .= '<bodytext>' . stripInvalidXml($body);
      $xml .= "<copyright>Reproduced From Women's Health. Copyright " . date('Y') . ". LMIL. All rights reserved.</copyright>";
      $xml .= '</bodytext>';
    }
    $xml .= '</artical>';
  }
  $xml_path = 'public://rss-feeds/xml_data/syndications/';
  $file_path = $xml_path . 'indiatoday-lifestyle.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}
