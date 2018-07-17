<?php

/**
 * Return @string value for meta description for each item in Editor's Pick
 *
 * @ingroup views_field_handlers
 */
class views_handler_itg_seo extends views_handler_field {

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
    return $values->_field_data['nid']['entity']->metatags[LANGUAGE_NONE]['description']['value'];
  }

}
