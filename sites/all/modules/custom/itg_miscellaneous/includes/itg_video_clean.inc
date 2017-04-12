<?php
/**
 * Implement function for create index.xml
 */
function create_index_xml(){
  $xml_path = 'sites/default/files/xml_file_chunk/';
  $foldername = 'story/';
  $path = $xml_path.$foldername;
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $rest = substr($filename, -4);
    if($rest == ".xml"){
      $xml_file = $filename->getFilename();
      //$files = end(explode($foldername, (string) $filename));
      $xml_id = explode('.xml', $xml_file);
      $file_id[$xml_id[0]] = $xml_id[0];
    }        
  }
  ksort($file_id);
  $domDocument = new DOMDocument('1.0', "UTF-8");
  $domElement = $domDocument->createElement('content');
  $domDocument->appendChild($domElement);
  foreach($file_id as $new_file){
      $domElement1 = $domDocument->createElement('sourceid', $new_file);
      $domElement->appendChild($domElement1);
  }
  //echo count($file_id);
  //p($file_id);
  $domDocument->save($xml_path.'index/index.xml');
}

/**
 * Callback for story xml cleanup
 * @param 
 */
function create_video_xml_clean() {
 $file_name = 'indiatoday_video_2016-06.xml';
  
  $xml_path = 'sites/default/files/xml_file_chunk/';
  $xml = simplexml_load_file($xml_path . $file_name, 'SimpleXMLElement');  
  $i = 0;
  foreach ($xml->videogallery as $stories) {
    $xml_city_id = (array) $stories->cities->city;
    $original_id = array();
    
    // Map byline
    _map_xml_byline($stories);
    
    // Map anchor
    _map_xml_anchor($stories);
    
    // Map createdby
    _map_xml_user($stories, 'createdby');

    // Map modifiedby
    _map_xml_user($stories, 'modifiedby');
    
    // Map primary category.
    _map_xml_primary_category($stories);//###
    
    // map city
    _map_xml_city($xml_city_id, $stories);

    
    // _map_xml_category($stories);
    _map_xml_all_category($stories);

    

    // Map tags.
    _map_xml_tags($stories);

    
    
    if (!empty($folder_name)) {
      $stories->asXml($xml_path . $folder_name . '/' . $stories->id . '.xml');
    }
    else {
      $stories->asXml($xml_path . 'story/' . $stories->id . '.xml');
    }    
    ++$i;
  }

  return 'hi';
}

/**
 * Map byline with DataBase.
 *
 * @param type $stories
 */
function _map_xml_byline(&$stories) {
  if (isset($stories->bylines->byline) && !empty($stories->bylines->byline)) {
    $i = 0;
    foreach ($stories->bylines->byline as $final_byline) {
      $source_bid = (string) $final_byline;
      if (!empty($source_bid)) {
        $orignal_byline = get_itg_destination_id('migrate_map_itgbyline', $source_bid);
        $stories->bylines->byline[$i] = $orignal_byline;
        ++$i;
      }
    }
  }
}

/**
 * Map tag name.
 *
 * @param stdObject $stories
 */
function _map_xml_tags(&$stories) {
  if (isset($stories->tags->tag) && !empty($stories->tags->tag)) {
    $i = 0;
    foreach ($stories->tags->tag as $final_tags) {
      $source_tags = (string) $final_tags;
      try {
        $orignal_tag = get_itg_destination_id('migrate_map_itgtags', $source_tags);
      }
      catch (Exception $ex) {
        drupal_set_message($ex->getMessage(), 'error');
      }
      $stories->tags->tag[$i] = $orignal_tag;
      ++$i;
    }
  }
}

/**
 * Map primary category.
 *
 * @param stdObject $stories
 */
function _map_xml_primary_category(&$stories) {
  if (isset($stories->primarycategory) && !empty($stories->primarycategory)) {
    $source_cid = (string) $stories->primarycategory;
    $pcategory_array = explode('#', $source_cid);
    $parray_count = count($pcategory_array);
    $table_name = itg_migrate_category_table($parray_count);
    $last_value = end($pcategory_array);
    $source_cid = (string) $last_value;
    $orignal_pcategory = get_itg_destination_id($table_name, $source_cid);
    $stories->primarycategory = $orignal_pcategory;
  }
}

/**
 * Map category to original category.
 * 
 * @param stdObject $stories
 */
function _map_xml_category(&$stories, $pti_section = NULL) {
  $data_category = '';
  if (isset($stories->categories->category) && !empty($stories->categories->category)) {
    $i = 0;
    foreach ($stories->categories->category as $final_category) {
      $category_array = explode('#', $final_category);
      $array_count = count($category_array);
      $table_name = itg_migrate_category_table($array_count);
      $last_value = end($category_array);
      $source_cid = (string) $last_value;      
      if ($pti_section != NULL) {
        $table_name = 'migrate_map_itgsection';
        $source_cid = $pti_section;
        $orignal_category = get_itg_destination_id($table_name, $source_cid);
      }
      else {
        $orignal_category = get_itg_destination_id($table_name, $source_cid);
      }      
      $stories->categories->category[$i] = $orignal_category;
      ++$i;
    }    
  }
}

/**
 * get all category destid1 with # 
 */
/**
 * Map category to original category.
 * 
 * @param stdObject $stories
 */
function _map_xml_all_category(&$stories, $pti_section = NULL) {
  $data_category = '';
 
  if (isset($stories->categories->category) && !empty($stories->categories->category)) {
    $i = 0;
     $str = '';
    foreach ($stories->categories->category as $final_category) {
      $category_array = explode('#', $final_category);
      $k = 1;
      $orignal_category = array();
      foreach($category_array as $individal_cat) {

        $array_count = $k;
        $source_cid = (string) $individal_cat;      
        if ($pti_section != NULL) {
          $table_name = 'migrate_map_itgsection';
          $source_cid = $pti_section;
          $orignal_category[] = get_itg_destination_id($table_name, $source_cid);
        }
        else {
          $table_name = itg_migrate_category_table($array_count);
          if ($k != 1) {
            $str = '#';
          }
          
          //$orignal_category .= $str.get_itg_destination_id($table_name, $source_cid);
          $orignal_category[] = get_itg_destination_id($table_name, $source_cid);
          //$orignal_category[] = implode('#', $orignal_category);
        }
        $k++;
      } 
       //$stories->categories->category[$i] = $orignal_category;   
      $stories->categories->category[$i] = implode('#', $orignal_category);
      ++$i;
    }    
  }
}

/**
 * Map Author id to original DB id.
 *
 * @param stdObject $stories
 */
function _map_xml_user(&$stories, $op) {
  // manage created user
  if (isset($stories->{$op}) && !empty($stories->{$op})) {

    $created_uid = (string) $stories->{$op};
    try {
      $orignal_crated_uid = get_itg_destination_id('migrate_map_itguser', $created_uid);
    }
    catch (Exception $ex) {
      drupal_set_message($ex->getMessage(), 'error');
    }
    $stories->{$op} = $orignal_crated_uid;
  }
  else {
    $stories->{$op} = 0;
  }
}

/**
 * Map city to original id.
 *
 * @param array $xml_city_id
 * @param stdObject $stories
 */
function _map_xml_city($xml_city_id, &$stories) {
  // Get city original id.
  $errors = array_filter($xml_city_id);
  if (!empty($errors)) {
    foreach ($xml_city_id as $source_city) {
      $original_id[] = get_itg_destination_id('migrate_map_itgcity', $source_city);
    }

    // Map xml city id from databaase city id.
    $j = 0;
    foreach ($stories->cities->city as $key => $new_city) {
      $stories->cities->city[$j] = $original_id[$j];
      ++$j;
    }
  }
}

function _map_xml_anchor($stories) {
  if (isset($stories->anchor) && !empty($stories->anchor)) {
    $source_aid = (string) $stories->anchor;
    $data_anchor = get_itg_destination_id('migrate_map_itgbyline', $source_aid);
  }
  
  $stories->anchor = $data_anchor;
}