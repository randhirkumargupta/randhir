<?php

/**
 * @file 
 * itg_auto_save contains member function and member used for autosave 
 * functionality.
 *
 * @author ITG
 */
class itg_auto_save {
  
  /**
   * Insert form ids to database
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
   * Check duplicate form id
   * @param array $pre_save
   * @return boolean
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
   * Insert form data
   * @param array $pre_save
   */
  private function itg_save_form_id_insert($pre_save) {
    $this->itg_query = db_insert('itg_autosave_forms')
        ->fields($pre_save)
        ->execute();
  }

  /**
   * Update form data
   * @param array $pre_save
   */
  private function itg_save_form_id_update($pre_save) {
    $this->itg_query = db_update('itg_autosave_forms')
        ->fields($pre_save)
        ->condition('form_name', $pre_save['form_name'])
        ->execute();
  }

  /**
   * Pass form ids to js file
   * @param int $nid 
   * @param string $c_type
   */
  public function itg_save_set_form_ids($nid, $c_type) {
    global $base_url;
    $this->fid_query = db_select('itg_autosave_forms', 'itg');
    $this->fid_query->fields('itg', array('form_name', 'autosave_time'));
    $this->fid_result = $this->fid_query->execute()->fetchAll();
    // Prepare array list form settings
    foreach ($this->fid_result as $row) {
      $this->data[$row->form_name] = array(
        $row->form_name,
        $row->autosave_time,
      );
    }
    // Pass data to js file
    drupal_add_js(array(
      'itg_autosave' => array(
        'auto_settings' => $this->data,
        'base_url' => $base_url,
        'nid' => $nid,
        'c_type' => $c_type
      )
        ), array(
      'type' => 'setting'
    ));
  }

  /**
   * Extract field type available on any content type
   * 
   * @param array $inputs
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
   * @param string $op
   * @param array $value
   * @return array 
   */
  public function itg_save_field_file($op, $value) {
    if ($op == 'insert') {
      $this->file_arr = array();
      $this->file_arr['fid'] = $value['und'][0]['fid'];
      $this->file_arr['display'] = $value['und'][0]['display'];
      $this->file_arr['description'] = $value['und'][0]['description'];
    }

    return $this->file_arr;
  }

  /**
   * Prepare presave arrave for text field
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_text($op, $value) {
    if ($op == 'insert') {
      $this->text_arr = '';
      $this->text_arr = $value['und'][0]['value'];
    }

    return $this->text_arr;
  }

  /**
   * Prepare presave array for term reference field.
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_taxonomy_term_reference($op, $value) {
    if ($op == 'insert') {
      $this->term_reference = '';
      $this->term_reference = $value['und'];
    }

    return $this->term_reference;
  }

  /**
   * Prepare presave array for field collection type field.
   * 
   * @param type $value
   * @return array
   */
  public function itg_save_field_field_collection($value) {
    $this->field_collection = array();
    $this->field_collection_data = array();
    foreach ($value['und'] as $key => $fc_value) {
      if ($key >= 0) {
        $this->field_collection_data = $this->itg_save_extract_fieldtype($fc_value);
        $this->field_collection[$key] = $this->itg_autosave_prepare_presave($this->field_collection_data, $fc_value, 'fc');
      }
    }

    return $this->field_collection;
  }

  /**
   * Prepare presave array for datestamp field.
   * 
   * @param string $op
   * @param array $value
   * @return array
   */
  public function itg_save_field_datestamp($op, $value) {
    if ($op = 'insert') {
      $this->datestamp_arr = array();
      $this->datestamp_arr['value'] = strtotime($value['und'][0]['value']['date']);
      ;
      $this->datestamp_arr['value2'] = strtotime($value['und'][0]['value2']['date']);
    }

    return $this->datestamp_arr;
  }

  /**
   * Prepare presave array for datetime field.
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_datetime($op, $value) {
    $this->datetime_result = '';
    if ($op == 'insert' && $value['und'][0]['value']['date'] != '') {
      $this->datetime_value = $value['und'][0]['value']['date'];
      $this->datetime_result = date("Y-m-d H:i:s", strtotime($this->datetime_value));
    }

    return $this->datetime_result;
  }

  /**
   * Prepare presave array for long text field.
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_text_long($op, $value) {
    $this->text_long = '';
    if ($op == 'insert') {
      $this->text_long = $value['und'][0]['value'];
    }

    return $this->text_long;
  }

  /**
   * Prepare presave array for image field.
   * 
   * @param string $op
   * @param array $value
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
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_text_with_summary($op, $value) {
    if ($op == 'insert') {
      $this->text_with_summary = '';
      $this->text_with_summary = $value['und'][0]['value'];
    }

    return $this->text_with_summary;
  }

  /**
   * Prepare presave array for list text field.
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_list_text($op, $value) {
    if ($op == 'insert') {
      $this->list_text = '';
      $this->list_text = $value['und'];
    }

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
    global $user;
    $this->pre_save_form = array(
      'nid' => $nid,
      'username' => $user->name,
      'node_type' => $c_type,
      'created' => REQUEST_TIME,
      'form_data' => $pre_save,
    );
    drupal_write_record('itg_autosave_node_data', $this->pre_save_form);
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
        //$pre_save[$field['fieldName']] = $itg_auto_save->itg_save_field_text_with_summary('insert', $_POST[$field['fieldName']]);
        break;
      case 'list_text':
        $form['field_astro_frequency']['und']['#default_value'] = $field_value;
    }
  }

  /**
   * Prepare presave array for all fields.
   * 
   * @param array $data
   * @param array $inputs
   * @return array
   */
  public function itg_autosave_prepare_presave($data, $inputs) {
    $this->temp = array();
    foreach ($data as $field) {
      switch ($field['fieldType']) {
        case 'datestamp':
          $this->temp[$field['fieldName']] = $this->itg_save_field_datestamp('insert', $inputs[$field['fieldName']]);
          break;

        case 'datetime':
          $this->temp[$field['fieldName']] = $this->itg_save_field_datetime('insert', $inputs[$field['fieldName']]);
          break;

        case 'text':
          $this->temp[$field['fieldName']] = $this->itg_save_field_text('insert', $inputs[$field['fieldName']]);
          break;

        case 'taxonomy_term_reference':
          $this->temp[$field['fieldName']] = $this->itg_save_field_taxonomy_term_reference('insert', $inputs[$field['fieldName']]);
          break;

        case 'field_collection':
          $this->temp['fieldCollection'][] = $field['fieldName'];
          break;

        case 'text_long':
          $this->temp[$field['fieldName']] = $this->itg_save_field_text_long('insert', $inputs[$field['fieldName']]);
          break;

        case 'image':
          $this->temp[$field['fieldName']] = $this->itg_save_field_image('insert', $inputs[$field['fieldName']]);
          break;

        case 'file':
          $this->temp[$field['fieldName']] = $this->itg_save_field_file('insert', $inputs[$field['fieldName']]);
          break;

        case 'text_with_summary':
          $this->temp[$field['fieldName']] = $this->itg_save_field_text_with_summary('insert', $inputs[$field['fieldName']]);
          break;
        case 'list_text':
          $this->temp[$field['fieldName']] = $this->itg_save_field_list_text('insert', $inputs[$field['fieldName']]);
          break;
      }
    }

    return $this->temp;
  }
  
  /**
   * Retrieve form data for field collection fields
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
}
