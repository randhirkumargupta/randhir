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
   */
  public function itg_save_set_form_ids() {
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
    drupal_add_js(array('itg_autosave' => array('auto_settings' => $this->data)), array('type' => 'setting'));
  }
}
