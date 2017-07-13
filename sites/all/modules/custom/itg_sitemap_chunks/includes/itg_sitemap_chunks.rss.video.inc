<?php

module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks.sections.rss');

/**
 * Function which gives rss of videogallery CT which are filed under given category.
 * 
 * @param int $section_tid
 */
function itg_sitemap_chunks_get_rss_of_video_with_order_category() {
  $arg = arg();
  $is_section_wise = TRUE;
  if (empty($arg[1])) {
    $is_section_wise = FALSE;
  }
  if ($is_section_wise) {
    $section_tid = $arg[1];
    if ((int) $section_tid != 0) {
      $xml = itg_sitemap_chunks_common_rss($section_tid, 'videogallery');
      if (!is_null($xml)) {
        header('Content-Type: text/xml');
        echo trim($xml);
        drupal_exit();
      } else {
        return drupal_not_found();
      }
    } else {
      return drupal_not_found();
    }
  } else {
    header('Content-Type: text/xml');
    echo itg_sitemap_chunks_get_rss_of_video_with_order();
    drupal_exit();
  }
}

/**
 * Function which gices rss for video section for videogallery content type as per section widget.
 * 
 * @global string $base_url
 * @return string
 */
function itg_sitemap_chunks_get_rss_of_video_with_order() {
  global $base_url;
  $video_tid = variable_get('video_category_tid');
  if (!empty($video_tid) && !is_null($video_tid) && (int) $video_tid) {
    $xml = itg_sitemap_chunks_common_rss($video_tid, 'videogallery');
    if (!is_null($xml)) {
      return trim($xml);
    } else {
      return drupal_not_found();
    }
  } else {
    drupal_set_message(t('Setting is required for video category tid. <a href="@setting">Click Here</a>', array("html" => TRUE, "@setting" => $base_url . '/admin/config/search/itg-multiple-sitemap/general-setting')), "error");
    return drupal_not_found();
  }
}
