<?php

/**
 * @file create_issue_xml.inc
 * Create issue using xml
 */

function _create_issue_using_xmlfile($node){

  global $user;
  
  //Add check for supplement and issue
  if ($node->type == 'supplement') {
    $magazine = $node->field_supp_select_magazine[LANGUAGE_NONE][0]['target_id'];
    $supplement = $node->nid;
    $file = $node->field_supp_import_xml[LANGUAGE_NONE];
  }
  if ($node->type == 'issue') {
    $magazine = $node->field_issue_magazine[LANGUAGE_NONE][0]['target_id'];
    $supplement = $node->field_issue_supplement[LANGUAGE_NONE][0]['target_id'];
    $file = $node->field_field_issue_import_xml[LANGUAGE_NONE];
  }

  $node_info = array(
      'source_nid' => $node->nid,
      'source_type' => $node->type,
      'magazine' => $magazine,
      'supplement' => $supplement
  );

  foreach ($file as $result) {
    sleep(2);
    itg_msi_create_issue_batch_process($result['fid'], $node_info);
  }
}