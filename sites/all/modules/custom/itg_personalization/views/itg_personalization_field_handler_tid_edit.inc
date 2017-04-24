<?php

/**
 * @file
 *
 * A Views' field handler for editing a node title.
 *
 */
module_load_include('inc', 'itg_widget', 'includes/itg_widget_personalization');

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
    global $base_url , $user;
    // Create a container for our replacements
    $form[$this->options['id']] = array(
      '#type' => 'container',
      '#tree' => TRUE,
    );
    // Iterate over the result and add our replacement fields to the form.
    foreach ($this->view->result as $row_index => $row) {
      // Adding a slider field into form.      
      $tid_weight = get_personalization_saved_value($row->tid , $user->uid);
      $default_value = isset($tid_weight->weight) ? $tid_weight->weight : 50;
      $form['markup'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="personalization-low-high"><span>Low</span><span>High</span></div>',
      );
      $form[$this->options['id']][$row_index] = array(                
        '#type' => 'slider',
        '#default_value' => $default_value,        
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
    // Add reset button.
    $form['reset'] = array(
      '#type' => 'button',
      '#button_type' => 'reset',
      '#value' => t('Reset'),
      '#weight' => 9,
      '#validate' => array(),
      '#attributes' => array(
            'onclick' => 'jQuery(".sliderfield").find(".ui-slider-range").css("width", "50%");
              jQuery(".sliderfield-value-field").val("50");
        jQuery(".sliderfield").find(".ui-slider-handle").css("left", "50%");
        jQuery(".sliderfield").find(".sliderfield-display-values-field").text(50); return false;',
          
          ),
    );
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
    foreach ($this->view->result as $row_index => $row) {
      $value = $form_state['values'][$this->options['id']][$row_index];
      if ($row->{$this->aliases['name']} != $value) {
        $updates[$row->{$this->aliases['tid']}] = $value;
      }
    }
    save_itg_widget_personalization_data($updates);
  }
}