<?php

/**
 * @file
 * Views field handler. Outputs a checkbox for selecting a row for email sending.
 * Implements the Views Form API.
 */
class itg_row_selector_field_handler_row_selector extends views_handler_field {

  /**
   * If the view is using a table style, provide a
   * placeholder for a "select all" checkbox.
   */
  function label() {
    if ($this->view->style_plugin instanceof views_plugin_style_table) {
      return '<!--itg-row-selector-select-all-->';
    }
    else {
      return parent::label();
    }
  }

  function query() {
    // Do nothing.
  }

  /**
   * Render checkbox in each row.
   * @param array $values
   * @return string
   */
  function render($values) {
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  /**
   * The form which replaces the placeholder from render().   * 
   * @param array $form
   * @param array $form_state
   * @return 
   */
  function views_form(&$form, &$form_state) {
    $arg = arg();
    // The view is empty, abort.
    if (empty($this->view->result)) {
      return;
    }
    if (!empty($arg[1]) && !empty($arg[2]) && $arg[1] == 'loyalty' && $arg[2] == 'lrp-sold-item-history') {
      // Add custom submit function to mark a product as complete.      
      $form['#submit'][] = 'itg_row_selector_complete_product';
    }

    $form[$this->options['id']] = array(
      '#tree' => TRUE,
    );
    foreach ($this->view->result as $row_index => $row) {
      if (!empty($arg[1]) && !empty($arg[2]) && $arg[1] == 'loyalty' && $arg[2] == 'lrp-sold-item-history') {
        if ($row->itg_loyalty_reward_order_status == 0) {
          $form[$this->options['id']][$row_index] = array(
            '#type' => 'checkbox',
            '#return_value' => $row->order_id,
            '#default_value' => FALSE,
            '#attributes' => array('class' => array('itg-row-selector-select')),
          );
        }
      }
      else {
        $form[$this->options['id']][$row_index] = array(
          '#type' => 'checkbox',
          '#return_value' => $row->nid,
          //'#default_value' => FALSE,
          '#attributes' => array('class' => array('itg-row-selector-select')),
        );
        $form[$this->options['id'] . '_client'] = array(
          '#type' => 'hidden',
          '#default_value' => $_GET['client_title'] != '_none' ? check_plain($_GET['client_title']) : NULL,
        );
        $form[$this->options['id'] . '_web_property'] = array(
          '#type' => 'hidden',
          '#default_value' => $_GET['type'] != '_none' ? check_plain($_GET['type']) : NULL,
        );
        $form[$this->options['id'] . '_issue'] = array(
          '#type' => 'hidden',
          '#default_value' => !empty($_GET['issue']) && $_GET['issue'] != '_none' ? check_plain($_GET['issue']) : NULL,
        );
      }      
    }
  }

  /**
   * views form validate function to validate checkbox
   * @param array $form
   * @param array $form_state
   */
  function views_form_validate($form, &$form_state) {    
    $field_name = $this->options['id'];
    if (!empty($form_state['values'][$field_name])) {
      $selection = array_filter($form_state['values'][$field_name]);
    }
    
    if (empty($selection)) {
      form_set_error($field_name, t('Please select at least one item.'));
    }
  }
}
