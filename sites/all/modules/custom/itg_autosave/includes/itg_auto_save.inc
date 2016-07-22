<?php

/**
 * @file
 * Itg_auto_save contains member function and member used for autosave
 * functionality.
 *
 * @author ITG
 */

/**
 * Class have logic to save and retrieve autosave data.
 */
class itg_auto_save {

  /**
   * Insert form ids to database.
   *
   * @param array $pre_save
   */
  public function itg_save_form_id($pre_save) {
    $this->is_duplicate = $this->itg_save_is_duplicate($pre_save);
    if ($this->is_duplicate) {
      $this->itg_save_form_id_update($pre_save);
      drupal_set_message('Form id has been updated.', 'status');
    }
    else {
      $this->itg_save_form_id_insert($pre_save);
      drupal_set_message('Form id has been inserted.', 'status');
    }
  }

  /**
   * Check duplicate form id.
   *
   * @param array $pre_save
   *
   * @return bool
   */
  private function itg_save_is_duplicate($pre_save) {
    $this->dup_query = db_select('itg_autosave_forms', 'itg');
    $this->dup_query->condition('form_name', $pre_save['form_name']);
    $this->dup_query->fields('itg', array('form_name'));
    $this->dup_result = $this->dup_query->execute()->fetchField();

    if ($pre_save['form_name'] == $this->dup_result) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Insert form data.
   *
   * @param array $pre_save
   */
  private function itg_save_form_id_insert($pre_save) {
    $this->itg_query = db_insert('itg_autosave_forms')
        ->fields($pre_save)
        ->execute();
  }

  /**
   * Update form data.
   *
   * @param array $pre_save
   */
  private function itg_save_form_id_update($pre_save) {
    $this->itg_query = db_update('itg_autosave_forms')
        ->fields($pre_save)
        ->condition('form_name', $pre_save['form_name'])
        ->execute();
  }

  /**
   * Pass form ids to js file.
   *
   * @param int $nid
   * @param string $c_type
   */
  public function itg_save_set_form_ids($nid, $c_type) {
    global $base_url;
    $this->fid_query = db_select('itg_autosave_forms', 'itg');
    $this->fid_query->fields('itg', array('form_name', 'autosave_time'));
    $this->fid_result = $this->fid_query->execute()->fetchAll();
    // Prepare array list form settings.
    foreach ($this->fid_result as $row) {
      $this->data[$row->form_name] = array(
        $row->form_name,
        $row->autosave_time,
      );
    }
    // Pass data to js file.
    drupal_add_js(array(
      'itg_autosave' => array(
        'auto_settings' => $this->data,
        'base_url' => $base_url,
        'nid' => $nid,
        'c_type' => $c_type,
      ),
    ), array(
      'type' => 'setting',
    ));
  }

  /**
   * Extract field type available on any content type.
   *
   * @param array $inputs
   *
   * @return array
   */
  public function itg_save_extract_fieldtype($inputs) {
    $this->field_type_result = array();
    foreach ($inputs as $key => $value) {
      $this->field_type_query = field_info_field($key);
      $this->field_type_result[] = array(
        'fieldName' => $this->field_type_query['field_name'],
        'fieldType' => $this->field_type_query['type'],
      );
    }

    return $this->field_type_result;
  }

  /**
   * Prepare presave array for file field.
   *
   * @param array $value
   *
   * @return array
   */
  public function itg_save_field_file($value) {
    $this->file_arr = array();
    $this->file_arr['fid'] = $value['und'][0]['fid'];
    $this->file_arr['display'] = $value['und'][0]['display'];
    $this->file_arr['description'] = $value['und'][0]['description'];
    
    return $this->file_arr;
  }

  /**
   * Prepare presave arrave for text field.
   *
   * @param array $value
   *
   * @return string
   */
  public function itg_save_field_text($value) {
    $this->text_arr = '';
    $this->text_arr = $value['und'][0]['value'];
    
    return $this->text_arr;
  }

  /**
   * Prepare presave array for field collection type field.
   *
   * @param array $value
   * @param stdObject $node
   * @param string $field_name
   * @param array $fc_ids
   *   Serialized array contaning field collections ids.
   *
   * @return array
   */
  public function itg_save_field_field_collection($value, &$node, $field_name, $fc_ids) {    
    $this->field_collection = array();
    $this->field_collection_data = array();   

    foreach ($value['und'] as $key => $fc_value) {      
      $this->field_collection_data = $this->itg_save_extract_fieldtype($fc_value);      
      //if (!isset($node->nid)) {
        // Create entity of type field collection        
        $this->fc_item = entity_create('field_collection_item', array('field_name' => $field_name));
        $this->fc_item->setHostEntity('node', $node);
        $this->itg_autosave_prepare_presave($this->field_collection_data, $fc_value, $node, 'fc', $field_name, $key, $this->fc_item);            
        $this->fc_item->save(TRUE);
        $node->{$field_name}[$node->language][$key]['value'] = $this->fc_item->item_id;
//      }
//      else {                         
//        $this->arr = $this->itg_autosave_update_field_collection($fc_value, $this->field_collection_data);        
//        $this->itg_save_update_field_collection($node, $field_name, $this->arr, $key);
//      }
   }    
  }
  
  
function itg_save_update_field_collection($node, $collection, $fields = Array(), $index = 0) {
    if ($node && $collection && !empty($fields)) {
        // Get the field collection ID
        $eid = $node->{$collection}[LANGUAGE_NONE][$index]['value'];

        // Load the field collection with the ID from above
        $entity = entity_load_single('field_collection_item', array($eid));

        // Wrap the loaded field collection which makes setting/getting much easier
        $node_wrapper = entity_metadata_wrapper('field_collection_item', $entity);

        // Loop through our fields and set the values
        foreach ($fields as $field => $data) {
            $node_wrapper->{$field}->set($data);
        }

        // Once we have added all the values we wish to change then we need to 
        // save. This will modify the node and does not require node_save() so
        // at this point be sure it is all correct as this will save directly
        // to a published node 
        $node_wrapper->save(true);
    }
}

  public function itg_autosave_update_field_collection($fc_value, $data) {    
    $this->arr = array();
    foreach ($data as $value) {
      switch ($value['fieldType']) {
        case 'taxonomy_term_reference':          
          $this->arr[$value['fieldName']] = $fc_value[$value['fieldName']]['und'];
          
          break;
        case 'text_long':          
          $this->arr[$value['fieldName']] = $fc_value[$value['fieldName']]['und'][0]['value'];
      }
    }
    
    return $this->arr;
  }

  /**
   * Prepare presave array for datestamp field.
   *   
   * @param array $value
   *
   * @return array
   */
  public function itg_save_field_datestamp($value) {
    $this->datestamp_arr = array();
    $this->datestamp_arr['value'] = strtotime($value['und'][0]['value']['date']);
    $this->datestamp_arr['value2'] = strtotime($value['und'][0]['value2']['date']);
    
    return $this->datestamp_arr;
  }

  /**
   * Prepare presave array for datetime field.
   *
   * @param array $value
   *
   * @return string
   */
  public function itg_save_field_datetime($value) {
    $this->datetime_result = '';
    if ($value['und'][0]['value']['date'] != '') {      
      $this->datetime_value = $value['und'][0]['value']['date'];
      $this->datetime_result = array(
        'value' => date("Y-m-d H:i:s", strtotime($this->datetime_value)),
        'timezone' => date_default_timezone(),
        'timezone_db' => date_default_timezone(),
      );
    }

    return $this->datetime_result;
  }

  /**
   * Prepare presave array for long text field.
   * 
   * @param array $value
   *
   * @return string
   */
  public function itg_save_field_text_long($value) {
    $this->text_long = '';    
    $this->text_long = $value['und'][0]['value'];           
    
    return $this->text_long;
  }

  /**
   * Prepare presave array for image field.
   *
   * @param string $op
   * @param array $value
   *
   * @return array
   */
  public function itg_save_field_image($op, $value) {
    if ($op == 'insert') {
      $this->image_arr = array();
      $this->image_arr['fid'] = $value['und'][0]['fid'];
      $this->image_arr['alt'] = $value['und'][0]['alt'];
      $this->image_arr['title'] = $value['und'][0]['title'];
    }

    return $this->image_arr;
  }

  /**
   * Prepare presave array for image field.
   *
   * @param array $value
   *
   * @return string
   */
  public function itg_save_field_text_with_summary($value) {
    $this->text_with_summary = '';
    $this->text_with_summary = $value['und'][0]['value'];
    
    return $this->text_with_summary;
  }

  /**
   * Prepare presave array for list text field.
   *
   * @param string $op
   * @param array $value
   *
   * @return string
   */
  public function itg_save_field_list_text($value) {
    $this->list_text = '';
    $this->list_text = $value['und'];
    
    return $this->list_text;
  }

  /**
   * Save form data into database to fullfill need of autosave.
   *
   * @global stdObject $user
   * @param array $pre_save
   * @param int $nid
   * @param string $c_type
   */
  public function itg_save_form_data($pre_save, $nid, $c_type) { 
    //pr($pre_save);
    //pr($nid);
    //p($c_type);
    global $user;
    $this->data = 0;
    // Check if unique id is already in database
    $this->dup_query = db_select('itg_autosave_node_data', 'itg');
    $this->dup_query->condition('itg_identity', $pre_save['unique_id']);
    $this->dup_query->fields('itg', array('itg_identity'));
    $this->dup_result = $this->dup_query->execute()->fetchField(); 
   
    // If unique id is not exist then insert. 
    if ($this->dup_result !== $pre_save['unique_id']) {      
      $this->pre_save_form = array(
        'nid' => $nid,
        'username' => $user->name,
        'node_type' => $c_type,
        'created' => REQUEST_TIME,
        'itg_identity' => $pre_save['unique_id'],
        'field_collection' => isset($pre_save['field_collection']) ? $pre_save['field_collection'] : '',
      );      
      $this->data = drupal_write_record('itg_autosave_node_data', $this->pre_save_form);
    }
    else {            
      $this->pre_save_form['field_collection'] = isset($pre_save['field_collection']) ? count($pre_save['field_collection']) > 0 ? serialize($pre_save['field_collection']) : array('empty') : array('empty');            
      //pr($this->pre_save_form['field_collection']);
      //p($this->pre_save_form);
      $this->data = db_update('itg_autosave_node_data');
      $this->data->fields($this->pre_save_form);
      $this->data->condition('itg_identity', $pre_save['unique_id']);
      $this->data->execute();      
    }
    //print $this->data;
  }

  /**
   * Retrieve data from database.
   *
   * @global stdObject $user
   * @param int $nid
   * @param string $c_type
   * @return array
   */
  public function itg_save_retrieve_form_data($nid, $c_type) {
    global $user;
    $this->retrieve_query = db_select('itg_autosave_node_data', 'itg');
    $this->retrieve_query->fields('itg')
        ->condition('node_type', $c_type);
    if ($nid > 0) {
      $this->retrieve_query->condition('nid', $nid);
    }
    else {
      $this->retrieve_query->condition('nid', 0);
    }
    $this->retrieve_query->condition('username', $user->name);
    $this->retrieve_query->orderBy('id', 'DESC')
        ->range(0, 1);
    $this->retrieve_result = $this->retrieve_query->execute()->fetchObject();

    return $this->retrieve_result;
  }

  /**
   * Prepare retrieve data arrar for node.
   *
   * @param array $form
   * @param string $field_name
   * @param string $field_value
   * @param string $type
   * @param string $fc
   * @param string $fc_name
   * @param int $delta
   */
  public function itg_save_prepare_retrieve_array(&$form, $field_name, $field_value, $type, $fc = NULL, $fc_name = NULL, $delta = NULL) {
    switch ($type) {
      case 'datestamp':
        $form[$field_name]['und'][0]['#default_value']['value'] = $field_value['value'];
        $form[$field_name]['und'][0]['#default_value']['value2'] = $field_value['value2'];
        break;

      case 'datetime':
        $form[$field_name]['und'][0]['#default_value']['value'] = $field_value;
        break;

      case 'text':
        $form[$field_name]['und'][0]['value']['#default_value'] = $field_value;
        break;

      case 'taxonomy_term_reference':
        if ($fc == 'fc') {
          if (is_array($field_value)) {
            $form[$fc_name]['und'][$delta][$field_name]['und']['#default_value'] = $field_value;
          }
          else {
            $form[$fc_name]['und'][$delta][$field_name]['und']['#default_value'][0] = $field_value;
          }
        }
        else {
          if (is_array($field_value)) {
            $form[$field_name]['und']['#default_value'] = $field_value;
          }
          else {
            $form[$field_name]['und']['#default_value'][0] = $field_value;
          }
        }

        break;

      case 'text_long':
        if ($fc == 'fc') {
          $form[$fc_name]['und'][$delta][$field_name]['und'][0]['value']['#default_value'] = strip_tags($field_value);
        }
        else {
          $form[$field_name]['und'][0]['value']['#default_value'] = strip_tags($field_value);
        }
        break;

      case 'image':
        $form[$field_name]['und'][0]['#default_value']['fid'] = $field_value['fid'];
        $form[$field_name]['und'][0]['#default_value']['alt'] = $field_value['alt'];
        $form[$field_name]['und'][0]['#default_value']['title'] = $field_value['title'];
        break;

      case 'file':
        if ($fc == 'fc') {
          $form[$fc_name]['und'][$delta][$field_name]['und'][0]['#default_value']['fid'] = $field_value['fid'];
          $form[$fc_name]['und'][$delta][$field_name]['und'][0]['#default_value']['description'] = $field_value['description'];
          $form[$fc_name]['und'][$delta][$field_name]['und'][0]['#default_value']['display'] = $field_value['display'];
        }
        else {
          $form[$field_name]['und'][0]['#default_value']['fid'] = $field_value['fid'];
          $form[$field_name]['und'][0]['#default_value']['description'] = $field_value['description'];
          $form[$field_name]['und'][0]['#default_value']['display'] = $field_value['display'];
        }

        break;

      case 'text_with_summary':
        // $pre_save[$field['fieldName']] = $itg_auto_save->itg_save_field_text_with_summary('insert', $_POST[$field['fieldName']]);.
        break;

      case 'list_text':
        $form['field_astro_frequency']['und']['#default_value'] = $field_value;
    }
  }

  /**
   * Prepare presave array for all fields.
   *
   * @param array $data
   *   Array containing field name and field type.
   * @param array $inputs
   *   Submitted form data in aarray format.
   * @param stdObject $node
   *   Node object which will be saved.
   * @param string $fc
   *   This is a flag for field collection field.
   * @param string $field_name
   *   Name of the field collection field.
   * @param int $delta
   *   Delta value of field collection field.
   *
   * @return array
   */
  public function itg_autosave_prepare_presave($data, $inputs, &$node, $fc = NULL, $field_name = NULL, $delta = NULL, &$fc_item = NULL) {
    $this->temp = array();
    foreach ($data as $field) {      
      switch ($field['fieldType']) {
        case 'datestamp':
          $node->{$field['fieldName']}['und'][0] = $this->itg_save_field_datestamp($inputs[$field['fieldName']]);          
          break;

        case 'datetime':
          $node->{$field['fieldName']}['und'][0] = $this->itg_save_field_datetime($inputs[$field['fieldName']]);          
          break;

        case 'text':
          $node->{$field['fieldName']}['und'][0]['value'] = $this->itg_save_field_text($inputs[$field['fieldName']]);
          break;

        case 'taxonomy_term_reference':
          $this->value = $inputs[$field['fieldName']]['und'];
          if ($fc === 'fc') {
            $fc_item->{$field['fieldName']}[$node->language][0]['tid'] = $this->value;
          }
          else {            
            if (is_array($this->value)) {
              foreach ($this->value as $key => $tid) {
                $node->{$field['fieldName']}[$node->language][$key]['tid'] = $tid;
              }
            }
            else {
              $node->{$field['fieldName']}[$node->language][0]['tid'] = $this->value;
            }
          }          
          break;

        case 'field_collection':
          $this->temp[] = $field['fieldName'];
          break;

        case 'text_long':
          if ($fc === 'fc') {            
            $fc_item->{$field['fieldName']}[$node->language][0]['value'] = $this->itg_save_field_text_long($inputs[$field['fieldName']]);            
          }
          else {
            $node->{$field['fieldName']}[$node->language][0] = $this->itg_save_field_text_long($inputs[$field['fieldName']]);
          }          
          break;

        case 'image':
          //$this->temp[$field['fieldName']] = $this->itg_save_field_image('insert', $inputs[$field['fieldName']]);
          break;

        case 'file':          
          //$node->$field['fieldName'][$node->language][0] = $this->itg_save_field_file($inputs[$field['fieldName']]);
          break;

        case 'text_with_summary':
          //$node->$field['fieldName'] = $this->itg_save_field_text_with_summary($inputs[$field['fieldName']]);
          break;

        case 'list_text':
          $node->{$field['fieldName']}['und'][0]['value'] = $this->itg_save_field_list_text($inputs[$field['fieldName']]);
          break;
      }
    }   
    
    return $this->temp;
  }

  /**
   * Retrieve form data for field collection fields.
   *
   * @param array $form
   * @param string $field_name
   * @param array $field_values
   */
  public function itg_save_retrieve_fcollection(&$form, $field_name, $field_values) {
    $this->temp = 0;
    foreach ($field_values as $key => $field) {
      $this->field_collection = $this->itg_save_extract_fieldtype($field);
      $this->flag = 0;
      foreach ($field as $key => $main_field) {
        $this->itg_save_prepare_retrieve_array($form, $key, $main_field, $this->field_collection[$this->flag]['fieldType'], 'fc', $field_name, $this->temp);
        ++$this->flag;
      }
      ++$this->temp;
    }    
  }
  
  /**
   * Remove field collection values based on other input.
   *
   * @param string $c_type
   *   Name of the content type.
   * @param type $inputs
   *   Submitted form values.
   */
  public function itg_save_remove_fcollection($c_type, &$inputs) {
    switch ($c_type) {
      case 'astro':
        if ($inputs['field_astro_type']['und'] == 224) {
          unset($inputs['field_astro_numerology_values']);
          unset($inputs['field_astro_zodiac']);
        }
        elseif ($inputs['field_astro_type']['und'] == 225) {
          unset($inputs['field_astro_zodiac']);
        }
        elseif ($inputs['field_astro_type']['und'] == 227) {
          unset($inputs['field_astro_numerology_values']);
        }
        else {
          unset($inputs['field_astro_numerology_values']);
          unset($inputs['field_astro_zodiac']);
        }        
        break;      
    }
  }
}
