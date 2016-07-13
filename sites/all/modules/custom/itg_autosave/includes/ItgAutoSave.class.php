<?php

/**
 * ItgAutoSave contains member function and member used for autosave 
 * functionality.
 *
 * @author ITG
 */
class ItgAutoSave {
  private $itg_query;
  public $itg_result;
  public $data;
  private $settings;
  
  /**
   * Insert form ids to database
   * @param array $pre_save
   */
  public function itg_save_form_id($pre_save) {
    $is_duplicate = $this->itg_save_is_duplicate($pre_save);
    if ($is_duplicate) {
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
    $this->itg_query = db_select('itg_autosave_forms', 'itg');
    $this->itg_query->condition('form_name', $pre_save['form_name']);
    $this->itg_query->fields('itg', array('form_name'));
    $this->itg_result = $this->itg_query->execute()->fetchField();
    
    if ($pre_save['form_name'] == $this->itg_result) {
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
    $this->itg_query = db_select('itg_autosave_forms', 'itg');
    $this->itg_query->fields('itg', array('form_name', 'autosave_time'));
    $this->itg_result = $this->itg_query->execute()->fetchAll();
    // Prepare array list form settings
    foreach ($this->itg_result as $row) {
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
    ), 
    array(
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
    $this->itgResult = array();
    foreach ($inputs as $key => $value) {
      $this->itgQuery = field_info_field($key);
      $this->itgResult[] = array(
        'fieldName' => $this->itgQuery['field_name'],
        'fieldType' => $this->itgQuery['type'],
      );
    }
    
    return $this->itgResult;
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
      $this->data = array();
      $this->data['fid'] = $value['und'][0]['fid'];
      $this->data['display'] = $value['und'][0]['display'];
      $this->data['description'] = $value['und'][0]['description'];
    }    
    
    return $this->data;
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
      $this->data = '';
      $this->data = $value['und'][0]['value'];
    }    
    
    return $this->data;
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
      $this->data = '';
      $this->data = $value['und'];
    }    
    
    return $this->data;
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
      $this->data = array();
      $this->data['value'] = strtotime($value['und'][0]['value']['date']);;
      $this->data['value2'] = strtotime($value['und'][0]['value2']['date']);
    }
        
    return $this->data;
  }
  
  /**
   * Prepare presave array for datetime field.
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_datetime($op, $value) {
    if ($op == 'insert') {
      $this->data = '';
      $this->itg_query = $value['und'][0]['value']['date'];
      $this->itg_result = date("Y-m-d H:i:s", strtotime($this->itg_query));
      $this->data = $this->itg_result;
    }    
    
    return $this->data;
  }
  
  /**
   * Prepare presave array for long text field.
   * 
   * @param string $op
   * @param array $value
   * @return string
   */
  public function itg_save_field_text_long($op, $value) {
    if ($op == 'insert') {
      $this->data = '';
      $this->data = $value['und'][0]['value'];
    }    
    
    return $this->data;
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
      $this->data = array();
      $this->data['fid'] = $value['und'][0]['fid'];
      $this->data['alt'] = $value['und'][0]['alt'];
      $this->data['title'] = $value['und'][0]['title'];
    }    
    
    return $this->data;
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
      $this->data = '';
      $this->data = $value['und'][0]['value'];
    }    
    
    return $this->data;
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
      $this->data = '';
      $this->data = $value['und'];
    }    
    
    return $this->data;
  }
  
  /**
   * Save form data into database to fullfill need of autosave.   
   * 
   * @global stdObject $user
   * @param array $pre_save
   * @param int $nid
   * @param string $ctype
   */
   
  public function itg_save_form_data($pre_save, $nid, $ctype) {
    global $user;        
    $this->itg_query = array(
      'nid' => $nid,
      'username' => $user->name,
      'node_type' => $ctype,
      'created' => REQUEST_TIME,
      'form_data' => $pre_save,
    );
    drupal_write_record('itg_autosave_node_data', $this->itg_query);
  }
  
  /**
   * Retrieve data from database.
   * 
   * @param int $nid
   * @param string $ctype
   * @return array
   */
  public function itg_save_retrieve_form_data($nid, $ctype) {
    $this->itg_query = db_select('itg_autosave_node_data', 'itg');
    $this->itg_query->fields('itg')
        ->condition('node_type', $ctype);
    if ($nid > 0) {
      $this->itg_query->condition('nid', $nid);
    }
    $this->itg_query->orderBy('id', 'DESC')
        ->range(0, 1);
    $this->itg_result = $this->itg_query->execute()->fetchObject();
    
    return $this->itg_result;
  }
  
  /**
   * Prepare retrieve data arrar for node.
   * 
   * @param array $form
   * @param string $field_name
   * @param string $field_value
   * @param string $type
   */
  public function itg_save_prepare_retrieve_array(&$form, $field_name, $field_value, $type) {
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
        if (is_array($field_value)) {
          $form[$field_name]['und']['#default_value'] = $field_value;
        }
        else {
          $form[$field_name]['und']['#default_value'][0] = $field_value;
        }
        break;
      
      case 'field_collection':
        //$pre_save[] = $itg_auto_save->itg_save_field_field_collection($field);
        break;
      
      case 'text_long':
        $form[$field_name]['und'][0]['value']['#default_value'] = strip_tags($field_value);
        break;
      
      case 'image':       
        $form[$field_name]['und'][0]['#default_value']['fid'] = $field_value['fid'];
        $form[$field_name]['und'][0]['#default_value']['alt'] = $field_value['alt'];
        $form[$field_name]['und'][0]['#default_value']['title'] = $field_value['title'];
        break;
      
      case 'file':        
        $form[$field_name]['und'][0]['#default_value']['fid'] = $field_value['fid'];
        $form[$field_name]['und'][0]['#default_value']['description'] = $field_value['description'];
        $form[$field_name]['und'][0]['#default_value']['display'] = $field_value['display'];
        break;
      
      case 'text_with_summary':
        //$pre_save[$field['fieldName']] = $itg_auto_save->itg_save_field_text_with_summary('insert', $_POST[$field['fieldName']]);
        break;
      case 'list_text':
        $form['field_astro_frequency']['und']['#default_value'] = $field_value;
    }
  }
}
