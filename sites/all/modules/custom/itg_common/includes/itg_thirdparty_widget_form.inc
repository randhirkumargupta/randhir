<?php
/**
 * Administrative settings.
 *
 * @return array
 *   An array containing form items to place on the module settings page.
 */
function third_party_widget_form_setting() {
  $widgets = array(
    'pti' => "PTI",
    "business" => "BUSINESS TODAY",
    'aajtak' => "AAJTAK",
  );
  $form['widget-choice'] = array(
    '#type' => 'checkboxes',
    '#options' => $widgets,
    '#title' => t('Select option'),
    '#description' => t(''),
    '#default_value' => variable_get('widget-choice', array()),
  );
  
  return system_settings_form($form);
}