<?php

/**
 * @file
 * Contain database function for multiple sitemap.
 */
function itg_sitemap_chunks_section_save_setting($section_data) {
  try {
    db_insert('itg_sitemap_chunks_sections')
        ->fields(array(
          'section_tid' => $section_data['tid'],
          'frequency' => $section_data['frequency'],
          'frequency_type' => $section_data['frequency_type'],
        ))->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
}

/**
 * Delete section setting.
 */
function itg_sitemap_shunks_section_delete() {
  try {
    db_delete('itg_sitemap_chunks_sections')->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
}

/**
 * Delete section setting.
 */
function itg_sitemap_chunks_section_db_data($section_tid) {
  try {
    $return =  db_select('itg_sitemap_chunks_sections', 'iscs')
            ->fields('iscs')
            ->condition('iscs.section_tid', $section_tid)
            ->execute()->fetchObject();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
  return !empty($return) ? $return : array();
}
