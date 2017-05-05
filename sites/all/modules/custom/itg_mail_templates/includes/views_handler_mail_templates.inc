<?php

/**
 * A handler to provide a field that will return mail templates status whether if there is no status
  .*
 * @ingroup views_field_handlers
 */
class views_handler_mail_templates extends views_handler_field {

  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['alter']['contains']['alter_text'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['alter']['alter_text']);
    unset($form['alter']['text']['#dependency']);
    unset($form['alter']['text']['#process']);
  }

  function render($values) {
    if ($values->_field_data['nid']['entity']->field_mail_templates_category['und'][0]['value'] == 'sign_up') {
      return t('Sign up');
    } 
    elseif ($values->_field_data['nid']['entity']->field_mail_templates_category['und'][0]['value'] == 'follow_story') {
      return t('Follow Story');
    } 
    elseif ($values->_field_data['nid']['entity']->field_mail_templates_category['und'][0]['value'] == 'loyalty_points_expiration') {
      return t('Loyalty Points Expiration');
    }
    elseif ($values->_field_data['nid']['entity']->field_mail_templates_category['und'][0]['value'] == 'password_changed') {
      return t('Password Changed');
    }
    elseif ($values->_field_data['nid']['entity']->field_mail_templates_category['und'][0]['value'] == 'print_team') {
      return t('Print Team');
    }
    elseif ($values->_field_data['nid']['entity']->field_mail_templates_category['und'][0]['value'] == 'quiz_completion') {
      return t('Quiz Completion');
    }
  }

}