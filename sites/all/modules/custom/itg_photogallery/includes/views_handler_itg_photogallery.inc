<?php

/**
 * A handler to provide a field that will return mail templates status whether if there is no status
  .*
 * @ingroup views_field_handlers
 */
class views_handler_itg_photogallery extends views_handler_field {

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
    global $user;
    if (!array_key_exists(INTERN, $user->roles)) {
      $title_data = l($values->node_title, 'node/' . $values->nid . '/edit', array('query' => drupal_get_destination()));
      return $title_data;
    } else if(array_key_exists(INTERN, $user->roles) && ($values->node_uid == $user->uid)) {
      $title_data = l($values->node_title, 'node/' . $values->nid . '/edit', array('query' => drupal_get_destination()));
      return $title_data;
    } else {
      return $values->node_title;
    }
  }

}
