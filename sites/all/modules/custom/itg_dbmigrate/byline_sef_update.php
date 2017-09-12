<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

byline_sef_update();

function byline_sef_update() {
  $path_xml = 'sites/default/files/migrate/xml_file/';
  $file_name = 'byline-master.xml';
  $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');

  foreach ($xml_data->row as $xml) {
    $node_sef = '';
    $node_sef_byline = '';
    $title = '';
    $newpath = '';
    $path = '';
    $nid = _return_nid_by_xml_ids($xml->id);

    if (!empty($nid)) {
      $node = node_load($nid);
      /* URl Alias Update Work */
      //if (!empty($xml->sef_url)) {
//Delete old sef url
        $nid = $node->nid;
        update_alias_deletes($nid);
        $node_sef_byline = (string) $xml->sef_url;
        if (!empty($node_sef_byline)) {
          $node_sef = $node_sef_byline;
        }
        if (empty($node_sef_byline)) {
          $title = (string) $xml->author_name;
          $node_sef = itg_common_custompath_insert_val($title);
        }
//$node_new_sefurl = itg_migrate_new_custompath($node, $published_dates, $node_sef);
        $newpath = itg_custompath_migrated_url_alias_byline($node, $published_dates, $node_sef);
        $path = array(
          'source' => "node/{$node->nid}",
          'alias' => $newpath, // Any alias that you want to set.
        );
        path_save($path);
        echo $xml->id . ', ';
      }
    //}
  }
}

function _return_nid_by_xml_ids($xml_id) {
  $query = db_select('migrate_map_itgbyline', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function update_alias_deletes($nid) {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua', array('pid'));
  $query->condition('source', "node/$nid", '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    path_delete($rel->pid);
  }
}

/**
 * Implement function for url alias
 */
function itg_custompath_migrated_url_alias_byline($node, $published_dates, $node_sef_url) {
  if (!empty($node_sef_url)) {
    $node_sef = $node_sef_url;
  }

  if ($node->type == 'reporter') {
    $occupation_tid = $node->field_celebrity_pro_occupation['und'][0]['tid'];
    $occupation = _occupation_from_tid_for_sef_url_new($occupation_tid);
    $pathdata = $occupation . '/' . $node_sef_url;
    $newpath = itg_common_custompath_insert_val($pathdata);
    return $newpath;
  }
}

/**
 * Implements _occupation_from_tid_for_sef_url.
 * {@inheritdoc}
 */
function _occupation_from_tid_for_sef_url_new($tid) {
  $term_data = taxonomy_term_load($tid);
  return $term_data->name;
}

?>
