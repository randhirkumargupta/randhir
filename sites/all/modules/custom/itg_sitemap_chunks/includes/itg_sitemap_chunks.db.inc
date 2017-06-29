<?php

/**
 * @file
 * Contain database function for multiple sitemap.
 */

/**
 * Save records into database.
 *
 * @param array $input
 *   Having input data.
 * @param int $update_ms_id
 *   Multiple sitemap id.
 *
 * @return int
 *   Ms id.
 */
function itg_sitemap_chunks_save_record($input = array(), $update_ms_id = NULL) {
  $ms_id = NULL;
  if (is_null($update_ms_id) && !empty($input)) {
    // Insert new record.
    try {
      $ms_id = db_insert('itg_sitemap_chunks')
          ->fields(array(
            'file_name' => $input['file_name'],
            'custom_links' => $input['custom_links'],
          ))
          ->execute();
    }
    catch (Exception $e) {
      drupal_set_message(t('File name already exist'), 'error');
    }
  }
  return $ms_id;
}

/**
 * Get records for give ms id.
 *
 * @param int $ms_id
 *   Having ms id.
 *
 * @return array
 *   Having existing records for given ms id.
 */
function itg_sitemap_chunks_get_record($ms_id = NULL) {
  $subrecords = array();
  $query = db_select('itg_sitemap_chunks_content', 'ms');
  $query->fields('ms');
  $results = $query->execute();
  if (!empty($results)) {
    foreach ($results as $result) {
      $subrecords[] = $result;
    }
  }

  $records['content'] = $subrecords;
  return $records;
}

/**
 * Insert new sub records for content type, menu type and vocab type.
 *
 * @param string $record_type
 *   Record type (content, menu, vocab).
 * @param int $ms_target_id
 *   Multiple sitemap id.
 * @param array $subrecords
 *   Having sub records.
 */
function itg_sitemap_chunks_save_sub_record($record_type = NULL, $ms_target_id = NULL, $subrecords = array()) {

  // Insert new records.
  if (!is_null($ms_target_id) && !is_null($record_type) && !empty($subrecords)) {

    // Record types.
    $record_types = array('content', 'menu', 'vocab');

    // Check existence of record type.
    if (in_array($record_type, $record_types)) {
      foreach ($subrecords as $subrecord) {
        // Insert each record.
        try {
          db_insert('itg_sitemap_chunks_' . $record_type)
              ->fields(array(
                'target_ms_id' => $ms_target_id,
                $record_type . '_type' => $subrecord['name'],
                'priority' => $subrecord['priority'],
                'changefreq' => $subrecord['changefreq'],
              ))
              ->execute();
        }
        catch (Exception $e) {
          drupal_set_message(t('Record already exist'), 'error');
        }
      }
    }
    else {
      drupal_set_message(t('Recors type does not exist'), 'error');
    }
  }
}

/**
 * Delete the sub records.
 *
 * @param string $record_type
 *   Record type name.
 * @param int $ms_target_id
 *   Target ms id.
 */
function itg_sitemap_chunks_delete_sub_record($record_type = NULL, $ms_target_id = NULL) {
  // Insert new records.
  if (!is_null($ms_target_id) && !is_null($record_type)) {

    // Record types.
    $record_types = array('content', 'menu', 'vocab');

    // Check existence of record type.
    if (in_array($record_type, $record_types)) {
      try {

        db_delete('itg_sitemap_chunks_' . $record_type)
            ->condition('target_ms_id', $ms_target_id, '=')
            ->execute();
      }
      catch (Exception $e) {
        drupal_set_message(t('Record is not deleted'), 'error');
      }
    }
  }
}

/**
 * Get all files name.
 *
 * @return array
 *   Having all file name.
 */
function itg_sitemap_chunks_get_files_name() {
  $records = array();
  $query = db_select('itg_sitemap_chunks', 'ms');
  $query->fields('ms', array('ms_id', 'file_name'));
  $results = $query->execute();
  if (!empty($results)) {
    foreach ($results as $result) {
      $records[$result->ms_id] = $result->file_name;
    }
  }

  return $records;
}

/**
 * Get links from content types.
 *
 * @param array $contents
 *   Having content details.
 *
 * @return array
 *   Having content links.
 */
function itg_sitemap_chunks_get_content_links($contents = array()) {
  $content_links = array();
  $excluded_nodes = array();
  $content_types = array();
  if (!empty(variable_get('itg_sitemap_exclude_nid'))) {
    $excluded_nodes = explode(",", variable_get('itg_sitemap_exclude_nid'));
  }

  if (!empty($contents)) {
    // Prepare array of content type which is saved from setting form.
    // These content type only will be avaiable for xml sitemap.
    foreach ($contents as $content) {
      $content_types[] = $content->content_type;
    }
    $limit = variable_get('itg_sitemap_chunks_number', 50000);
    // Get the all links for given type.
    $query = db_select('node', 'n')->extend('PagerDefault')->limit($limit);
    $query->fields('n', array('nid', 'type'));
    $query->condition('type', $content_types, 'IN');
    $query->condition('status', 1);
    // Exclude node
    if (!empty($excluded_nodes)) {
      foreach ($excluded_nodes as $nid) {
        $query->condition('nid', $nid, "!=");
      }
    }
    $query->orderBy('n.nid', 'DESC');
    $results = $query->execute()->fetchAll();
    // prepare result for xml with pagination.
    foreach ($results as $i => $data) {
      $tag_data = itg_sitemap_chunk_get_tags_data($contents, $data->type);
      $path = url(drupal_get_path_alias('node/' . $data->nid), array('absolute' => TRUE));
      $content_links[$i]['link'] = $path;
      $content_links[$i]['priority'] = $tag_data->priority;
      $content_links[$i]['changefreq'] = $tag_data->changefreq;
    }
  }
  return $content_links;
}
