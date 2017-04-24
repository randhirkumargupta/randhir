<?php

/**
 * Called file form node_insert and node_update
 * @file create_issue_xml.inc
 * Create issue using xml
 */

function _create_issue_using_xmlfile($node, $op) {
  //Add check for supplement and issue
  if ($node->type == 'supplement') {
    $magazine = $node->field_supp_select_magazine[LANGUAGE_NONE][0]['target_id'];
    $supplement = $node->nid;
    $file = $node->field_supp_import_xml[LANGUAGE_NONE];
    $issue_date = $node->field_supp_issue[LANGUAGE_NONE][0]['value'];
  }
  if ($node->type == 'issue') {
    $magazine = $node->field_issue_magazine[LANGUAGE_NONE][0]['target_id'];
    $supplement = $node->field_issue_supplement[LANGUAGE_NONE][0]['target_id'];
    $file = $node->field_field_issue_import_xml[LANGUAGE_NONE];
    $issue_date = $node->field_issue_title[LANGUAGE_NONE][0]['value'];
  }

  //Parent node(issue/supplement) info
  $node_info = array(
      'source_nid' => $node->nid,
      'source_title' => $node->title,
      'source_type' => $node->type,
      'magazine' => $magazine,
      'supplement' => $supplement,
      'issue_date' => $issue_date
  );

  //Segregation update and insert case
  if ($op == 'update') {
    $existing_fids = itg_msi_get_associated_fid_node($node, NULL);
    foreach ($file as $result) {
      if (!in_array($result['fid'], $existing_fids)) { //Allow only xml file to create story which is new.
        _create_issue_process($result['fid'], $node_info, $node);
      }
    }
  } else {
    if (!empty($file)) {
      foreach ($file as $result) {
        sleep(1);
        _create_issue_process($result['fid'], $node_info, $node);
      }
    }
  }
}

/**
 * Create issue using XML file
 * @global Array $user
 * @param Int $fid
 * @param Array $node_info
 * @param string $context
 */
function _create_issue_process($fid, $node_info, $parent_node) {
  global $user;
  $xml_file = file_load($fid);
  $fileuri = file_create_url($xml_file->uri);
  $xml = simplexml_load_file($fileuri, 'SimpleXMLElement', LIBXML_NOCDATA);

  if (!empty($xml)) {
    //Get XML unique UID
    foreach ($xml->attributes() as $key => $value) {
      $xml_uid = $value;
    }

    //Get City
    $city = trim((string) $xml->City);
    $city_tid = itg_msi_get_term_from_name($city, 'city');

    //Get Parent Category
    $section = trim((string) $xml->Section);
    $section_tid = itg_msi_get_term_from_name($section, 'category_management');

    //Get kicker, headline, byline and body from this array($xml_other)
    foreach ($xml as $key => $value) {
      $xml_other[strtolower($key)] = $value;
    }


    $byline_id = itg_msi_get_nid_using_title_type(trim($xml_other['byline']->p), 'reporter');

    $headline = htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $xml_other['headline']->p))));
    //$kicker =  htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', $xml_other['kicker']->p)))); 
    
    //Prepare kicker
    foreach ($xml_other['kicker']->p as $kickerr) {
      $kick = (string) $kickerr;
        $kicker .= htmlentities(strip_tags(trim(preg_replace('/\s+/', ' ', (string) $kickerr)))); ;
    }


    $issue_date_xml = str_replace('/', '-', trim($xml->IssueDate));
    if(!empty($issue_date_xml)){
      $issue_date = date('Y-m-d 00:00:00', strtotime($issue_date_xml));
    }
    if(!empty($node_info['issue_date'])){
      $node_issue_date = date('Y-m-d 00:00:00', strtotime($node_info['issue_date']));
      
    }
    
    //Prepare body
    foreach ($xml_other['body']->p as $bodyTxt) {
      $bodyTxtt = (string) $bodyTxt;
        $body .= '<p>' . ucfirst(htmlentities($bodyTxtt)) . '</p>';
    }
    //Set values to node
    $node = new stdClass();
    $node->title = trim($headline);
    $node->type = "story";
    node_object_prepare($node);

    $node->language = LANGUAGE_NONE;
    $node->uid = $user->uid;
    $node->status = 1;
    $node->promote = 0;
    $node->comment = 0;
    $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim($headline) ? trim($headline) : 'NA';
    $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim($headline) ? trim($headline) : 'NA';
    $node->body[$node->language][0]['value'] = $body ? $body : 'NA';
    if(!empty($city_tid)) {
      $node->field_stroy_city[LANGUAGE_NONE][0]['tid'] = $city_tid; // 58: New Delhi
    }
    $node->field_story_issue_date[LANGUAGE_NONE][0]['value'] = !empty($issue_date) ? $issue_date : $node_issue_date;
    //Issue, magazine and supplement
    $node->field_story_magazine_story_issue[LANGUAGE_NONE][0]['value'] = 'magazine_issue_story';
    if ($node_info['magazine']) {
      $node->field_story_select_magazine[LANGUAGE_NONE][0]['target_id'] = $node_info['magazine'];
    }
    if ($node_info['supplement']) {
      $node->field_story_select_supplement[LANGUAGE_NONE][0]['target_id'] = $node_info['supplement'];
    }

    $publish_date = date('Y-m-d');
    $exp_date = strtotime('+90 years', strtotime($publish_date));
    $exp_date = date('Y-m-d', $exp_date);

    //Insert Kicker
    $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'] = $kicker ? $kicker : 'NA';
    //$node->field_story_magazine_kicker_text[LANGUAGE_NONE][0]['value'] = $kicker ? $kicker : 'NA';

    //Insert Author(Byline)
    if(!empty($byline_id)){
      $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'] = $byline_id;
    }

    //Insert Section and sub-section
    if(!empty($section_tid)) {
      $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $section_tid;
      $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $section_tid;
    }


    //Set source variables in to story content type
    $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = $node_info['source_type'];
    $node->field_story_source_id[LANGUAGE_NONE][0]['value'] = $node_info['source_nid'];
    $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $publish_date;
    $node->field_story_expiry_date[LANGUAGE_NONE][0]['value'] = $exp_date;
    $node->revision = 1;
    $node->log = 'State Changed to published';
    $node->workbench_moderation_state_new = workbench_moderation_state_published();
    $node = node_submit($node); // Prepare node for saving
    node_save($node); // Finally save node

    if ($node->nid) {
      db_insert('itg_msi_node_xml') // Table to store file and node info
              ->fields(array(
                  'nid' => $node_info['source_nid'],
                  'uid' => $user->uid,
                  'xml_uid' => $xml_uid,
                  'fid' => $fid,
                  'filename' => $xml_file->filename,
                  'type' => $node_info['source_type'],
                  'created' => time()
              ))
              ->execute();
    }
  }
}
