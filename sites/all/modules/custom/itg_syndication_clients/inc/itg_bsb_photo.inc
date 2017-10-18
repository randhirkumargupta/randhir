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
 * menu callback for bsb story syndication
 */
function itg_genrate_bsb_photo_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_terms_name_by_ids(array($section_id));
    $section_name = $section_name[0]['name'];
    $type = array('photogallery');
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');

    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
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

function generate_photo_detail_xml($nid, $title, $section_id, $section_name, $photo_detail_file_name) {
  global $base_url;

  $gallery_img_fc = get_all_associated_photos($nid);
  $image_count = count($gallery_img_fc);
<<<<<<< HEAD

=======
  
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
  $content_url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
  $photo_xml .= '<Root>';
  $photo_xml .= '<idgallery>' . $nid . '</idgallery>';
  $photo_xml .= '<gallery><![CDATA[' . $title . ']]></gallery>';
  $photo_xml .= '<idsection>' . $section_id . '</idsection>';
  $photo_xml .= '<section>' . $section_name . '</section>';
  $photo_xml .= '<totalpics>' . $image_count . '</totalpics>';
  $photo_xml .= '<weburl><![CDATA[' . $content_url . ']]></weburl>';

<<<<<<< HEAD

=======
 
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
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

/**
 * Function is used to get all gallery images.
 * @param int $nid
 * @return array
 */
function get_all_associated_photos($nid) {
  $query = db_select('field_data_field_gallery_image', 'gi');
  $query->join('field_data_field_images', 'fi', 'fi.entity_id=gi.field_gallery_image_value');
  $query->leftjoin('field_data_field_photo_small_image', 'gsi', 'gsi.entity_id=gi.field_gallery_image_value');
  $query->leftjoin('field_data_field_image_caption', 'ic', 'ic.entity_id=gi.field_gallery_image_value');
  $query->leftjoin('field_data_field_photo_byline', 'pb', 'pb.entity_id=gi.field_gallery_image_value');
  $query->leftjoin('node', 'byline', 'byline.nid=pb.field_photo_byline_target_id');
  $query->condition('gi.entity_id', $nid, '=');
  $query->condition('gi.entity_type', 'node', '=');
  $query->condition('gi.bundle', 'photogallery', '=');
  $query->fields('gi', array('field_gallery_image_value'));
  $query->fields('fi', array('field_images_fid'));
  $query->fields('gsi', array('field_photo_small_image_fid'));
  $query->fields('byline', array('title'));
  $query->fields('ic', array('field_image_caption_value'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}
