<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
issue_mapping();

function issue_date_update() {
  $path = 'sites/default/files/migrate/xml_file/issue-supplement-scp/issue-suppliments/indiatoday_issue_2017.xml';
  $xml = simplexml_load_file($path, 'SimpleXMLElement');
  foreach ($xml->issue as $xml_data) {
    $source_id = (int) $xml_data->id;
    echo $source_id . ', ';
    $source_cid = (int) $xml_data->id;
    $issue_nid = get_itg_destination_id('migrate_map_itgissue', $source_cid);
    $node = node_load($issue_nid);
    $issue_date = (int) $xml_data->issue_date;
    if (!empty($issue_date)) {
      $mod_time = $issue_date;
      $modi_time = date('Y-m-d 00:00:00', $mod_time);
      $node->field_issue_title[LANGUAGE_NONE][0]['value'] = $modi_time;
      field_attach_update('node', $node);

      db_update('node') // Update title in node table
          ->fields(array(
            'title' => $modi_time,
          ))
          ->condition('nid', $node->nid, '=')
          ->execute();

      db_update('node_revision') // Update title in node revision
          ->fields(array(
            'title' => $modi_time,
          ))
          ->condition('nid', $node->nid, '=')
          ->execute();
    }
  }
}

function issue_mapping() {
  $xml_path = 'sites/default/files/migrate/xml_file/26-Aug-TO-10-sept/issue-suppliment/indiatoday_issue_2017.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');
  $issue_nid = '';
  foreach ($xml as $xm) {
    if (isset($xm->supplements->supplement) && !empty($xm->supplements->supplement)) {
      $issue_nid = get_itg_destination_id('migrate_map_itgissue', (int) $xm->id);
      $suppliment_org_id = array();
      foreach ($xm->supplements->supplement as $final_supplement) {
        $supp_id_concat = $final_supplement . 'A' . (int) $xm->id;
        $suppliment_org_id[]['target_id'] = get_itg_destination_id('migrate_map_itgsupplements', $supp_id_concat);
      }
      if(!empty($suppliment_org_id[0]['target_id'])) {
        $node = node_load($issue_nid);
        unset($node->field_issue_supplement[LANGUAGE_NONE]);
        $node->field_issue_supplement[LANGUAGE_NONE] = $suppliment_org_id;
        field_attach_update('node', $node);
      }
      pr($issue_nid);
      pr($xm->id);
    }
  }
}

?>