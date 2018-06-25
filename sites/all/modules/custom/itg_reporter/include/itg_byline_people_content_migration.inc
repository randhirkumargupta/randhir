<?php
//module_load_include('php', 'itg_videogallery', 'vendor/autoload');
/**
 * Implement itg_people_migration
 */
function itg_people_migration() {
  drupal_page_is_cacheable(FALSE);
  global $user;
  $term_id = get_itg_variable('occupation_people_termid');
  if($term_id){
    $file_path = drupal_get_path('module', 'itg_reporter') . '/include/people-data.xml';
    if(file_exists($file_path)) {
      $xml = simplexml_load_file($file_path);
      $json_string = json_encode($xml);
      $result_array = json_decode($json_string, TRUE);
      // print_r($result_array);
      // die;
      if(!empty($result_array)){
        foreach ($result_array['row'] as $key=>$value){
            $node = new stdClass();
            $node->title = trim($value['headline']);
            $node->type = "reporter";
            node_object_prepare($node);
            $node->language = LANGUAGE_NONE;
            $node->uid = 1;
            $node->promote = 0;
            $node->comment = 0;

            $node->body[$node->language][0]['value'] = $value['main_text'] ? $value['main_text'] : '';
            $node->body[$node->language][0]['format'] = 'full_html';
            $node->field_celebrity_pro_occupation[LANGUAGE_NONE][0]['tid'] = $term_id;;
            $node->metatags[LANGUAGE_NONE]['title']['value'] = '';

            if(!empty($value['metatitle'])){
              $node->metatags[LANGUAGE_NONE]['title']['value'] = $value['metatitle'];
            }
            if(!empty($value['metadesc'])){
              $node->metatags[LANGUAGE_NONE]['description']['value'] = $value['metadesc'];
            }
            if(!empty($value['metakey'])){
              $node->metatags[LANGUAGE_NONE]['keywords']['value'] = $value['metakey'];
            }

            $node->created = $value['created'];
            //$node->changed = $value['modified'];
            $existing_filepath = 'http://media2.intoday.in/indiatoday/images/stories/'.$value['kicker_image'];
            try{
              $drupal_file = file_save_data(@file_get_contents($existing_filepath), 'public://'.$value['kicker_image']);
              if(!empty($value['kicker_image_alt_text'])){
                $drupal_file->alt = $value['kicker_image_alt_text'];
                $drupal_file->title = $value['kicker_image_alt_text'];
              }
              // Assign the file object to the node, as an array
              $node->field_story_extra_large_image[$node->language][0] = get_object_vars($drupal_file);
            }catch(Exception $e){
              echo $key.'. Failed image migration:'.$value['id'].' --- '.$e->getMessage() . "<br><br>";
            }

            try{
              node_save($node); // Finally save node
              db_update('node') // Table name no longer needs {}
                  ->fields(array(
                    'changed' =>  $value['modified'],
                  ))
                  ->condition('nid', $node->nid, '=')
                  ->execute();
              echo $key.'. Success: Drupal-'.$node->nid. '     XML-'. $value['id']."<br><br>";
            }catch (Exception $e) {
              echo $key.'. Failed Migration id:'.$value['id'].' --- '.$e->getMessage() . "<br><br>";
            }
          //die;
        }
      }
      else {
      echo "Failure: Empty XML file";
       // watchdog('Agency_configuration_warning', 'Enable agency feed from configuration');
      }
    }
    else{
      echo "Failure: File not exist";
    }
  }
  else{
    echo "Failure: People Term id is empty!";
  }
}
