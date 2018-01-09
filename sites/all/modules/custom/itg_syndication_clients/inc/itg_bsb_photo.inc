<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */
function itg_bsb_photo_syndication() {
  $sections = getbsb_client_photo_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_bsb_photo_syndication($section_id, $file_name);
  }
}

/**
 * function is used to generate BSB story xml
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_bsb_photo_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);
    
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->condition('ti.tid', $section_id, '=');
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->fields('n', array('nid', 'title', 'created'));
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->condition('n.status', 1);
    $query->condition('n.type', 'photogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_bsb_photo_syndication_xml($result, $section_id, $section_name);
    $xml_path = 'public://bsb/photos/';
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
function genrate_bsb_photo_syndication_xml($result = NULL, $section_id, $section_name) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $total_count = count($result);
    $xml .= '<Root>';
    $xml .= '<id>1</id>';
    $xml .= '<title>Photos</title>';
    $xml .= '<count>' . $total_count . '</count>';

    foreach ($result as $photo) {
      $nid = $photo['nid'];
      $url = slugify($photo['title']);
      $photo_detail_file_name = $url . '.xml';
      generate_photo_detail_xml($nid, $photo['title'], $section_id, $section_name, $photo_detail_file_name);
      $xml .= '<item>';
      $xml .= '<id>' . $nid . '</id>';
      $xml .= '<title><![CDATA[' . $photo['title'] . ']]></title>';
      $xml .= '<url><![CDATA[' . $photo_detail_file_name . ']]></url>';
      $xml .= '</item>';
    }
    $xml .= '</Root>';
  }
  return $xml;
}

/**
 * 
 * @global string $base_url
 * @param int $nid
 * @param string $title
 * @param int $section_id
 * @param string $section_name
 * @param string $photo_detail_file_name
 */
function generate_photo_detail_xml($nid, $title, $section_id, $section_name, $photo_detail_file_name) {
  global $base_url;

  $gallery_img_fc = get_all_associated_photos($nid);
  $image_count = count($gallery_img_fc);
  $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
  $photo_xml .= '<Root>';
  $photo_xml .= '<idgallery>' . $nid . '</idgallery>';
  $photo_xml .= '<gallery><![CDATA[' . $title . ']]></gallery>';
  $photo_xml .= '<idsection>' . $section_id . '</idsection>';
  $photo_xml .= '<section>' . $section_name . '</section>';
  $photo_xml .= '<totalpics>' . $image_count . '</totalpics>';
  $photo_xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';
  foreach ($gallery_img_fc as $photo) {
    $byline = $photo['title'];
    $large_image = '';
    if (!empty($photo['field_images_fid'])) {
      $large_image = get_image_info_by_fid($photo['field_images_fid']);
    }
    $small_image = '';
    if (!empty($photo['field_photo_small_image_fid'])) {
      $small_image = get_image_info_by_fid($photo['field_photo_small_image_fid']);
    }
    $photo_xml .= '<item>';
    $photo_xml .= '<imageid>' . $photo['field_gallery_image_value'] . '</imageid>';
    $photo_xml .= '<image><![CDATA[' . $small_image['imag_url'] . ']]></image>';
    $photo_xml .= '<largeimage><![CDATA[' . $large_image['imag_url'] . ']]></largeimage>';
    $photo_xml .= '<caption><![CDATA[' . $photo['field_image_caption_value'] . ']]></caption>';
    $photo_xml .= '<byline>' . $byline . '</byline>';
    $photo_xml .= '</item>';
  }
  $photo_xml .= '</Root>';
  $xml_path = 'public://bsb/photos/';
  $file_path = $xml_path . $photo_detail_file_name;
  $fp = fopen($file_path, "w");
  fwrite($fp, $photo_xml);
  fclose($fp);
}
