<?php

module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks.sections.rss');

/**
 * Function which gives rss of photogallery CT which are filed under given category.
 * 
 * @param int $section_tid
 */
function itg_sitemap_chunks_get_rss_of_photo_with_order_category() {
  $arg = arg();
  if (!empty($arg[1])) {
    $section_tid = $arg[1];
    if ((int) $section_tid != 0) {
      $xml = itg_sitemap_chunks_common_rss($section_tid, 'photogallery');
      if (!is_null($xml)) {
        header('Content-Type: text/xml');
        $dom = new DOMDocument;
        $dom->preserveWhiteSpace = false;
        $dom->formatOutput = true;
        $dom->loadXML($xml);
        echo $dom->saveXML();
        //echo trim($xml);
        drupal_exit();
      } else {
        return drupal_not_found();
      }
    } else {
      return drupal_not_found();
    }
  } else {
    // If section is not given then photosection will be used.
    itg_sitemap_chunks_get_rss_of_photo_with_order();
    drupal_exit();
  }
}

/**
 * Function which provide rss of photogallery CT under photos section.
 * 
 * @global string $base_url
 * @return string
 */
function itg_sitemap_chunks_get_rss_of_photo_with_order() {
  global $base_url;
  $photo_tid = variable_get('photo_category_tid');
  if (!empty($photo_tid) && !is_null($photo_tid) && (int) $photo_tid) {
    $xml = itg_sitemap_chunks_common_rss($photo_tid, 'photogallery');
    if (!is_null($xml)) {
      header('Content-Type: text/xml');
      echo trim($xml);
      drupal_exit();
    } else {
      return drupal_not_found();
    }
  } else {
    drupal_set_message(t('Setting is required for photo category tid. <a href="@setting">Click Here</a>', array("html" => TRUE, "@setting" => $base_url . '/admin/config/search/itg-multiple-sitemap/general-setting')), "error");
    return drupal_not_found();
  }
}
