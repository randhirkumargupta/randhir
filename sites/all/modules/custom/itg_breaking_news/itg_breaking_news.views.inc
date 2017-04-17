<?php

/**
 * @file
 * Views related hooks and handlers for Views Current Path.
 */

/**
 * Implements hook_views_data().
 */
function itg_breaking_news_views_data() {
  $data['views']['dynamic_band_link'] = array(
    'title' => t('Dynamic Band Link'),
    'help' => t('The path of the page currently being viewed.'),
    'field' => array(
      'handler' => 'itg_breaking_news_views_handler_field_dynamic_band_link',
    ),
  );
  return $data;
}

/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_breaking_news_views_handler_field_dynamic_band_link extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  function query() {
    // Do nothing -- to override the parent query.
  }

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  function render($values) {
    global $base_url;
//    if (isset($values->field_field_breaking_redirection_url[0]['raw']['value']) && !empty($values->field_field_breaking_redirection_url[0]['raw']['value'])) {
//      $url = preg_replace('#^https?://#', '', $values->field_field_breaking_redirection_url[0]['raw']['value']);
//      $title = l($values->field_field_breaking_tile[0]['raw']['value'], $values->field_field_breaking_redirection_url[0]['raw']['value'], array('html' => TRUE, 'external' => TRUE));
//      $title = l(t(trim($values->field_field_breaking_tile[0]['raw']['value'])), 'http://'.$url, array(
//        'html' => TRUE,
//        'external' => TRUE,
//        'attributes' => array(
//          'title' => t(trim($values->field_field_breaking_tile[0]['raw']['value'])),
//        ),
//      ));
//    }
//    else {
      $title = l(trim($values->field_field_breaking_tile[0]['raw']['value']), 'node/' . $values->nid, array('html' => TRUE));
   // }
    return $title;
  }

}
