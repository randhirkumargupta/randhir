<?php

function itg_db_migrate_related_content() {
  //itg_db_migrate_source_id_for_byline('migrate_map_itgbyline', 'byline');
  itg_db_migrate_source_id_for_category('migrate_map_itgsection', 'section');
  exit;
  
  //Code for related content
  
  //code for XML read  
  /*$xml_dir = 'test-related-story/';
  
  $path_xml = 'sites/default/files/migrate/xml_file/'.$xml_dir;  
  
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {    
    $file_name = $filename->getFilename();    
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }    
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');    
    $c_type = '';    
    foreach ($xml_data->relatedcontents as $xml) {      
      $content_id = get_itg_destination_id('migrate_map_itgstorylist', (int) $xml->id);
      if (!empty($content_id)) {
        $related_content_with_title_val = '';
        $related_content_val = '';
        $content_revision_id = get_node_revision_id($content_id);        
        foreach ($xml->relatedcontent as $relatedcontent_data) {
          $relatedcontent_type = (string) $relatedcontent_data->relatedcontenttype;
          if ($relatedcontent_type == 'text') {
            $relatedcontentid = get_itg_destination_id('migrate_map_itgstorylist', (int) $relatedcontent_data->relatedcontentid);
            $c_type = 'Story';
          } else if ($relatedcontent_type == 'photo') {
              $relatedcontentid = get_itg_destination_id('migrate_map_itgphotogallery', (int) $relatedcontent_data->relatedcontentid);
              $c_type = 'photogallery';
          } else if ($relatedcontent_type == 'video') {
              $relatedcontentid = get_itg_destination_id('migrate_map_itgvideogallery', (int) $relatedcontent_data->relatedcontentid);
              $c_type = 'Video';
          }
          if (!empty($relatedcontentid)) {            
            $relatedcontenttitle = (string) $relatedcontent_data->relatedcontenttitle;
            $related_content_val .= 'IT_'.$relatedcontentid.',';
            //$related_content_with_title_val .= 'IT_'.$relatedcontentid.'@'.$c_type.'@'.$relatedcontenttitle.'!#!';
            $related_content_with_title_val .= 'IT_'.$relatedcontentid.'@'.$c_type.'@'.$relatedcontenttitle.',';
          } else {
              //failed related content
              db_insert('itg_not_migrated_content')->fields(array(
                'xml_content_id' => $content_id ,
                'related_content_xml_id' => (int) $relatedcontent_data->relatedcontentid ,
                'xml_name' => $file_name ,
                'c_type' => $c_type))->execute();
          }
          
        }
        if (!empty($related_content_val)) {
          $related_content_insert_val =  rtrim($related_content_val,',');
          $related_content_insert_title_val =  rtrim($related_content_with_title_val,',');

          //insert data in Related Content field
          itg_data_insert_in_field($content_id, $content_revision_id, 'field_common_related_content', 'story', 'node', $related_content_insert_val);
          itg_data_insert_in_field($content_id, $content_revision_id, 'field_cm_related_content_detail', 'story', 'node', $related_content_insert_title_val);
          //echo $content_id.'</br>';//update content id 
        }
        
      } else {
         //not update related content
         db_insert('itg_not_update_related_content')->fields(array(
          'xml_content_id' => $content_id ,
          'xml_name' => $file_name ,
          'c_type' => 'story'))->execute();
      }
    }    
  } */  
    
}


function itg_data_insert_in_field($nid, $revision_id, $field_name, $bundle, $entity_type, $data) {
 
  /*db_insert('field_data_'.$field_name)->fields(array(
    'entity_type' => $entity_type ,
    'bundle' => $bundle ,
    'deleted' => 0 ,
    'entity_id' => $nid ,
    'revision_id' => $revision_id,
    'language' => 'und',
    'delta' => 0,
    $field_name.'_value' => $data))->execute();
  
  db_insert('field_revision_'.$field_name)->fields(array(
    'entity_type' => $entity_type ,
    'bundle' => $bundle ,
    'deleted' => 0 ,
    'entity_id' => $nid ,
    'revision_id' => $revision_id,
    'language' => 'und',
    'delta' => 0,
    $field_name.'_value' => $data))->execute();*/
  
  $tb1 = 'field_data_'.$field_name;
  $field = $field_name.'_value';
  $tb2 = 'field_revision_'.$field_name;
  $la = 'und';
 
  //######################################################################################
  
    db_query("INSERT INTO {$tb1} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, $field) VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_dt)", array(':entity_type' => $entity_type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $nid, ':revision_id' => $revision_id, ':language' => $la, ':delta' => 0, ':field_dt'=>$data));
    db_query("INSERT INTO {$tb2} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, $field) VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_dt)", array(':entity_type' => $entity_type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $nid, ':revision_id' => $revision_id, ':language' => $la, ':delta' => 0, ':field_dt'=>$data));
  
  //######################################################################################
  

 //db_delete('field_data_'.$field_name)->condition('entity_id', $nid)->execute();
 //db_delete('field_revision_'.$field_name)->condition('entity_id', $nid)->execute();
}


/**
 * get new content id of itg by old content id
 * @param int $sourceid
 * @return int destination id
 */
function get_node_revision_id($nid) {
  $query = db_select('node', 'n');
  $query->fields('n', array('vid'));  
  $query->condition('nid', $nid);
  
  return $query->execute()->fetchField();
}


function itg_db_migrate_source_id_for_byline($table_name, $pre) {
  
  //code for XML read  
  $xml_dir = 'xml_script/';  
  $path_xml = 'sites/default/files/migrate/'.$xml_dir;
  
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {    
    $file_name = $filename->getFilename();    
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }    
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');    
    $c_type = '';    
    foreach ($xml_data->row as $xml) {      
      $content_id = get_itg_destination_id($table_name, (int) $xml->id);
      if (!empty($content_id)) {       
        $content_revision_id = get_node_revision_id($content_id);        
        $source_id_val = $pre.'-'.(int) $xml->id;        
        itg_data_insert_in_field($content_id, $content_revision_id, 'field_old_content_source_id', 'reporter', 'node', $source_id_val);
        echo (int) $xml->id.'-'.$content_id.'</br>';//update content id
      }
    }
  }
  
}

function itg_db_migrate_source_id_for_category($table_name, $pre) {
  
  //code for XML read  
  $xml_dir = 'xml_category/';  
  $path_xml = 'sites/default/files/migrate/'.$xml_dir;
  
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {    
    $file_name = $filename->getFilename();    
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }    
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');    
    $c_type = '';    
    foreach ($xml_data->row as $xml) {      
      $content_id = get_itg_destination_id($table_name, (int) $xml->id);
      if (!empty($content_id)) {
        $source_id_val = $pre.'-'.(int) $xml->id;        
        itg_data_insert_in_field($content_id, $content_id, 'field_old_content_source_id', 'category_management', 'taxonomy_term', $source_id_val);
        echo $source_id_val.'@'.$content_id.'</br>';//update content id
      }
    }
  }
  
}