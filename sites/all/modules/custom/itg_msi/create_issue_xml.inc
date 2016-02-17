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
    $Supplement = $node->nid;
    $file = $node->field_supp_import_xml[LANGUAGE_NONE];
  }
  if ($node->type == 'issue') {
    $magazine = $node->field_issue_select_magazine[LANGUAGE_NONE][0]['target_id'];
    $Supplement = $node->field_issue_supplement[LANGUAGE_NONE][0]['target_id'];
    $file = $node->field_issue_import_xml[LANGUAGE_NONE];
  }
  
  //Create multiple node
  foreach ($file as $file_detail) {
    $xml_file = file_load($file_detail['fid']);
    $xml_file_path = str_replace('public://', 'sites/default/files/', $xml_file->uri);
    $xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA); // load xml file details using file path(returns in to array format)
    
    
    //Collect kicker, headline, byline and body from this array($xml_other)
    foreach($xml as $key => $value){
      $xml_other[strtolower($key)] = $value; 
    }
    
    //Extract values from XML and set in to varibales
    $city = itg_msi_get_term_from_name(trim($xml->City), 'city');
    $section  = itg_msi_get_term_from_name(trim($xml->Section), 'category_management');
    $sub_section = $xml->SubSection;
    $issue_date_xml = str_replace('/','-',trim($xml->IssueDate));
    $issue_date = date('Y-m-d h:i:s', strtotime($issue_date_xml));
    
//    $magazine = itg_msi_get_nid_using_title_type(trim($xml->MagazineName), 'magazine');
//    $Supplement = itg_msi_get_nid_using_title_type(trim($xml->Supplement), 'supplement');
     
    $kicker = htmlentities(strip_tags(trim($xml_other['kicker']->p)));
    $byline = itg_msi_get_nid_using_title_type(trim($xml_other['byline']->p), 'reporter');;
    $headline = htmlentities($xml_other['headline']->p);
    $comment_question = htmlentities($node->field_story_comment_question[LANGUAGE_NONE][0]['value']);

    //Prepare body
    foreach($xml_other['body']->p as $bodyTxt){
      $body .= '<p>'.htmlentities($bodyTxt).'</p>';
    }

    //Set values to node
    $node = new stdClass();
    $node->title = trim($headline);
    $node->type = "story";
    node_object_prepare($node);

    $node->language = LANGUAGE_NONE; //und
    $node->uid = $user->uid;
    $node->status = 1; //(1 or 0): Published or not
    $node->promote = 0; //(1 or 0): Promoted to front page
    $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
    
    //Headline, body issue date and city
    $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim($headline) ? trim($headline) : 'NA';
    $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim($headline) ? trim($headline) : 'NA';
    $node->body[$node->language][0]['value']   = $body ? $body : 'NA';
    $node->field_stroy_city[LANGUAGE_NONE][0]['tid'] = $city ? $city : 58; // 58: New Delhi
    $node->field_story_schedule_date_time[LANGUAGE_NONE][0]['value'] = $issue_date ? $issue_date : date('Y-m-d h:i:s', time());
    
    //Issue, magazine and supplement
    $node->field_story_magazine_story_issue[LANGUAGE_NONE][0]['value'] = 'magazine_issue_story';
    if($magazine){
      $node->field_story_select_magazine[LANGUAGE_NONE][0]['target_id']= $magazine;
    }
    if($Supplement) {
      $node->field_story_select_supplement[LANGUAGE_NONE][0]['target_id'] = $Supplement; 
    }
    
    //Kicker and byline
    $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'] = $kicker ? $kicker : 'NA';
    $node->field_story_magazine_kicker_text[LANGUAGE_NONE][0]['value'] = $kicker ? $kicker : 'NA';
    $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'] = $byline ? $byline : 29; //29: Rajdeep Sardesai
    $node->field_story_comment_question[LANGUAGE_NONE][0]['value'] = $comment_question ? $comment_question : 'NA';
    
    //Section and sub-section
    if($section){
      $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $section; 
    }
            
    $node = node_submit($node); // Prepare node for saving
    node_save($node); // Finally save node
  }
}