<?php

/**
 * @file
 *
 * A Views' field handler for editing a node title.
 *
 */
class itg_personalization_field_handler_tid_edit extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = 'tid';
    $this->additional_fields['name'] = 'name';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render the field contents.
   *
   * @param $values
   * @return string
   */
  function render($values) {
    // Render a Views form item placeholder.
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  /**
   * Add to and alter the form.
   */
  function views_form(&$form, &$form_state) {    
    global $base_url;
    // Create a container for our replacements
    $form[$this->options['id']] = array(
      '#type' => 'container',
      '#tree' => TRUE,
    );
    // Iterate over the result and add our replacement fields to the form.
    foreach($this->view->result as $row_index => $row) {
      // Adding a slider field into form.      
      $form[$this->options['id']][$row_index] = array(                
        '#type' => 'slider',
        '#default_value' => 50,        
        '#slider_style' => 'blue',
        '#range' => 'min',
        '#min' => 0,
        '#max' => 100,
        '#step' => 10,
        '#required' => 1,        
        '#display_inputs' => FALSE,
        '#display_values' => TRUE,
        '#slider_length' => '400px',
      );      
    }
    // Submit to the current page if not a page display.
    if ($this->view->display_handler->plugin_name != 'page') {
      $form['#action'] = $base_url . '/personalization/my-preferences';
    }
  }

  /**
   * Form submit method.
   */
  function views_form_submit($form, &$form_state) {    
    // Determine which nodes we need to update.
    $updates = array();
    foreach($this->view->result as $row_index => $row) {
      $value = $form_state['values'][$this->options['id']][$row_index];
      if ($row->{$this->aliases['name']} != $value) {
        $updates[$row->{$this->aliases['tid']}] = $value;
      }
    }    
  }
}