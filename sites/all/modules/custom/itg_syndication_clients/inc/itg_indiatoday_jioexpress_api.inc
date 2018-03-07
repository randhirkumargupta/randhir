<?php
function itg_indiatoday_jioexpress_api(){

  $sid = 1206643;
  
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
	$query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('dbody', array('body_value'));
  $query->fields('smi', array('field_story_medium_image_fid'));
  
  //~ $days_ago = strtotime(date('Y-m-d', strtotime('-60 days')));
  //~ $query->condition('n.created', $days_ago, '>=');  
  $query->condition('ti.tid', $sid, '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 10);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = generate_jioexpress_feeds($result, $sid);
  $xml_path = 'public://rss-feeds/xml_data/syndications/';
	$file_path = $xml_path . 'jio-express.xml';
	$fp = fopen($file_path, "w");
	fwrite($fp, $xml);
	fclose($fp);
}


function generate_jioexpress_feeds($result, $sid){
	$xml = '';
  if (!empty($result)) {
    global $base_url;
    $logo = theme_get_setting('logo');
    $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $sid);
    $xml .= '<rss xmlns:atom10="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ India Today Latest News]]></title>';
    $xml .= '<description>India Today</description>';
    $xml .= '<link><![CDATA[ ' . FRONT_URL . ']]></link>';
    
    $xml .= '<image>';
    $xml .= '<url>' . $logo . '</url>';
    $xml .= '<title><![CDATA[ India Today Latest News ]]></title>';
    $xml .= '<link><![CDATA[' . FRONT_URL . ']]></link>';
    $xml .= '</image>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $pub_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $body = stripInvalidXml($body);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $byline = get_byline_name_by_nid($value['nid']);
      $xml .= '<item>';
      $xml .= '<title>' . stripInvalidXml($value['title']) . '</title>';
      $xml .= '<description><![CDATA[' . $body . ']]></description>';
      $xml .= '<pubDate>' . $pub_date . '+0000</pubDate>';
      $xml .= '<link>' . $url . '</link>';
      $xml .= '<image>' . $medium_img["imag_url"] . '</image>';
      $xml .= '<author>' . $byline . '</author>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
    return $xml;
  }
}
