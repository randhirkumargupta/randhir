<?php
  
/**
 * Implement itg_pti_content
 */
function itg_octopus_api_rundown() {
 $file_path = drupal_realpath('public://');
  global $base_url, $user;
  header('Content-Type: text/html; charset=UTF-8');
  $direc = getDirContents($file_path.'/octopus/rundown/');
  foreach ($direc as $xm_file) {
    $xml_file_path = $xm_file;
    $xml_filename = basename($xml_file_path);
    $rundown_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    $rundownId = (string)$rundown_xml->rundown->rundownId;
    $rundownTitle = (string)$rundown_xml->rundown->rundownTitle;
    $rundownStart = (string)$rundown_xml->rundown->rundownType;
    $exported = strtotime((string)$rundown_xml->exported);
    $exportedBy = (string)$rundown_xml->exportedBy;
    $exist_rundown = itg_octopus_api_check_rundown($rundownId);
    if($exist_rundown == ''){
      $nid = db_insert('itg_rundown') // Table name no longer needs {}
        ->fields(array(
          'exported' => $exported,
          'exported_by' => $exportedBy,
          'rundown_id' => $rundownId,
          'rundown_title' => $rundownTitle,
          'rundown_start' => $rundownStart,
          //'created' => REQUEST_TIME,
        ))
        ->execute();
    }
    $count_slug = 0;
    foreach($rundown_xml->rundown->slugs->slug as $key => $slug){
      $storyId = (string)$slug->storyId;
      $storyTitle = (string)$slug->storyTitle;
      $storyStatus = (string)$slug->storyStatus;
      $storyDur = (string)$slug->storyDur;
      $storyCreated = strtotime((string)$slug->storyCreated);
      $storyCreatedBy = (string)$slug->storyCreatedBy;
      $storyModified = strtotime((string)$slug->storyModified);
      $storyModifiedBy = (string)$slug->storyModifiedBy;
      $slugId = (string)$slug->slugId;
      $elementId = (string)$slug->script->main->body->element->elementId;
      $elementType = (string)$slug->script->main->body->element->elementType;
      $elementDur = (string)$slug->script->main->body->element->elementDur;
      $clipName = (string)$slug->script->main->body->element->clip->clipName;
      $clipMosId = (string)$slug->script->main->body->element->clip->clipMosId;
      $clipObjId = (string)$slug->script->main->body->element->clip->clipObjId;
      $clipJobId = (string)$slug->script->main->body->element->clip->clipJobId;
      $clipFilePath = (string)$slug->script->main->body->element->clip->clipFilePath;
      $clipIn = (string)$slug->script->main->body->element->clip->clipIn;
      $clipOut = (string)$slug->script->main->body->element->clip->clipOut;
      $text = htmlentities((string)$slug->script->main->body->element->text);
      // Get story custom value
      foreach ($slug->storyCustom as $key => $value) {
          $arr[(string)$value->attributes()->label] = (string)$value;
          $arr['rundown_id'] = $rundownId;
          $arr['slug_id'] = $slugId;
      }
      $storycustom_details = serialize($arr);
      //$count_slug++;
      //End Get story custom value      
      $slug_exist = itg_octopus_api_check_slug($slugId, $rundownId);
      if(empty($slug_exist)){
         db_insert('itg_octopus_slug')
          ->fields(array(
            'storyid' => $storyId,
            'rundown_id' => $rundownId,
            'slug_id' => $slugId,
            'story_title' => $storyTitle,
            'story_status' => $storyStatus,
            'story_duration' => $storyDur,
            'story_created' => $storyCreated,
            'story_created_by' => $storyCreatedBy,
            'story_modified' => $storyModified,
            'story_modified_by' => $storyModifiedBy,
            //'created' => REQUEST_TIME,
          ))->execute();
         // value insert in itg_element_clip table
         db_insert('itg_element_clip')
          ->fields(array(
            'element_id' => $elementId,
            'rundown_id' => $rundownId,
            'slug_id' => $slugId,
            'element_type' => $elementType,
            'element_dur' => $elementDur,
            'clipname' => $clipName,
            'clipmosid' => $clipMosId,
            'clipobj_id' => $clipObjId,
            'clipjobid' => $clipJobId,
            'clipfilepath' => $clipFilePath,
            'clipin' => $clipIn,
            'clipout' => $clipOut,
            'text' => $text,
            //'created' => REQUEST_TIME,
          ))->execute();
         
        // Value insert in "itg_octopus_slug_storycustom" Table
         
         db_insert('itg_octopus_slug_storycustom')
          ->fields(array(
              'rundown_id' => $rundownId,
              'slug_id' => $slugId,
              'story_custom_data' => $storycustom_details,
              ))->execute();
         
    }else {
      if($slug_exist[0]->story_modified !=  $storyModified){
        db_update('itg_octopus_slug')
          ->fields(array(
              'storyid' => $storyId,
              'rundown_id' => $rundownId,
              'slug_id' => $slugId,
              'story_title' => $storyTitle,
              'story_status' => $storyStatus,
              'story_duration' => $storyDur,
              'story_created' => $storyCreated,
              'story_created_by' => $storyCreatedBy,
              'story_modified' => $storyModified,
              'story_modified_by' => $storyModifiedBy,
          ))
          ->condition('slug_id', $slug_exist[0]->slug_id)       
          ->condition('rundown_id', $rundownId)       
          ->execute();
        echo $slug_exist[0]->slug_id. ' in '. $rundownId . ' updated';
        
        // Update in itg_element_clip table
        //get element id of clip
        $clipid = itg_octopus_api_clip_check($slugId, $rundownId);
        db_update('itg_element_clip')
          ->fields(array(
              'element_id' => $elementId,
              'rundown_id' => $rundownId,
              'slug_id' => $slugId,
              'element_type' => $elementType,
              'element_dur' => $elementDur,
              'clipname' => $clipName,
              'clipmosid' => $clipMosId,
              'clipobj_id' => $clipObjId,
              'clipjobid' => $clipJobId,
              'clipfilepath' => $clipFilePath,
              'clipin' => $clipIn,
              'clipout' => $clipOut,
              'text' => $text,
            ))
          ->condition('slug_id', $clipid[0]->slug_id)      
          ->condition('rundown_id', $clipid[0]->rundown_id)       
          ->execute();
        echo $clipid[0]->slug_id. ' in '. $rundownId . ' updateded clip';
        // UPdate data in itg_octopus_slug_storycustom
        $story_custom = itg_octopus_api_storycustom_check($slugId, $rundownId);
        db_update('itg_octopus_slug_storycustom')
          ->fields(array(
            'rundown_id' => $rundownId,
            'slug_id' => $slugId,
            'story_custom_data' => $storycustom_details,
          ))
          ->condition('slug_id', $story_custom[0]->slug_id)      
          ->condition('rundown_id', $story_custom[0]->rundown_id)       
          ->execute();
        echo $story_custom[0]->slug_id. ' in '. $rundownId . ' updateded storycustom';
      }
    }
   }
  }    
}

/**
 * Implements function for check existing rundown table
 * @param int $rundownId
 * @return int
 */
function itg_octopus_api_check_rundown($rundownId){
  $query = db_select('itg_rundown', 'ir')
          ->fields('ir', array('rundown_id'))
          ->condition('rundown_id', $rundownId, '=');
    $result = $query->execute()->fetchField();
    return $result;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundownId
 * @return array
 */
function itg_octopus_api_check_slug($slugid, $rundownId){
  $query = db_select('itg_octopus_slug', 'ios')
          ->fields('ios', array('slug_id', 'story_modified'))
          ->condition('slug_id', $slugid, '=')
          ->condition('rundown_id', $rundownId, '=');
    $result = $query->execute()->fetchAll();
    return $result;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundownId
 * @return array
 */
function itg_octopus_api_clip_check($slugid, $rundownId){
  $query = db_select('itg_element_clip', 'iec')
          ->fields('iec', array('slug_id', 'element_id', 'rundown_id'))
          ->condition('slug_id', $slugid, '=')
          ->condition('rundown_id', $rundownId, '=');
    $result = $query->execute()->fetchAll();
    return $result;
}

/**
 * Implements function for check existing slug in table
 * @param int $slugid
 * @param int $rundownId
 * @return array
 */
function itg_octopus_api_storycustom_check($slugid, $rundownId){
  $query = db_select('itg_octopus_slug_storycustom', 'ioss')
          ->fields('ioss', array('slug_id', 'rundown_id', 'story_custom_data'))
          ->condition('slug_id', $slugid, '=')
          ->condition('rundown_id', $rundownId, '=');
    $result = $query->execute()->fetchAll();
    return $result;
}

/*
 * Implements function for rundown listing.
 */
function itg_octopus_api_rundown_listing(){
   # configure the table header columns
  $header = array(
    array('data' => 'Slug ID',        'field' => 'slug_id',               'sort' => 'ASC'),
    array('data' => 'Slug Title',        'field' => 'stitle',               'sort' => 'ASC'),
    array('data' => 'Modified Date',     'field' => 'last_updated',       'sort' => 'ASC'),
    array('data' => 'View',     'field' => 'view'),
  );
  $query = db_select('itg_octopus_slug', 'ios')
    ->fields('ios')
    ->range(0, 20);
    $result = $query->execute();
    foreach($result as $row){
      $rows[] = array($row->id,
                    $row->story_title,
                    $row->story_modified,
                    l('Slug Details', 'detail/'.$row->id)
    );
    }
    $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table'))));

  # add the pager
  $output .= theme('pager');

  return $output;
}