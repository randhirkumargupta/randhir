<?php

/**
 * @file
 * The ITG Syndication clients for MSN Photo
 */

/**
 * menu callback
 * Function for generate msn photo feed
 */
function itg_rss_msn_photos_feed() {
  $type = array('photogallery');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
  $query->fields('sli', array('field_story_large_image_fid'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'photogallery', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = genrate_msn_photo_syndication_xml($result);
  $xml_path = 'public://msn/photos/';
  $file_path = $xml_path . 'gallery_msn.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function genrate_msn_photo_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml .= '<Root>';
    foreach ($result as $value) {
      $nid = $value['nid'];
      $created_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $xml .= '<item>';
      $xml .= '<gallery_id>' . $nid . '</gallery_id>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<image><![CDATA[' . $small_img['imag_url'] . ']]></image>';
      $xml .= '<largeimage><![CDATA[' . $large_img['imag_url'] . ']]></largeimage>';
      $xml .= '<caption><![CDATA[' . $large_img['caption'] . ']]></caption>';
      $xml .= '<create_datetime>' . $created_date . '</create_datetime>';
      $xml .= '<galleries>' . get_msn_photo_gallery_xml($nid) . '</galleries>';
      $xml .= '<weburl><![CDATA[' . $url . ']]></weburl>';
      $xml .= '</item>';
    }
    $xml .= '</Root>';
  }
  return $xml;
}

/**
 * Function for get xml tag of photo
 * @param int $nid
 * @return string
 */
function get_msn_photo_gallery_xml($nid) {
  $photo_xml = '';
  $gallery_img_fc = get_all_associated_photos($nid);
  foreach ($gallery_img_fc as $photo) {
    $small_image = '';
    if (!empty($photo['field_photo_small_image_fid'])) {
      $small_image = get_image_info_by_fid($photo['field_photo_small_image_fid']);
    }
    $photo_xml .= '<gallery>';
    $photo_xml .= '<image><![CDATA[' . $small_image['imag_url'] . ']]></image>';
    $photo_xml .= '<caption><![CDATA[' . $photo['field_image_caption_value'] . ']]></caption>';
    $photo_xml .= '</gallery>';
  }
  return $photo_xml;
}
