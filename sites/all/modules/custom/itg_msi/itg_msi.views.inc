<?php

/**
 * @file
 * Views related hooks and handlers for Views Current Path.
 */

/**
 * Implements hook_views_data().
 */
function itg_msi_views_data() {
  $data['views']['dynamic_clone_link'] = array(
    'title' => t('Dynamic Clone Link'),
    'help' => t('The path of the page currently being viewed.'),
    'field' => array(
      'handler' => 'itg_msi_views_handler_field_dynamic_clone_link',
    ),
  );
  return $data;
}

/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_msi_views_handler_field_dynamic_clone_link extends views_handler_field {

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
    // Get info about node is locked or active.
    if(function_exists(itg_msi_get_lock_story_status)) {
      $lock_story = itg_msi_get_lock_story_status($values->nid, 'lock_story');
    }
    // Prepare dynamic link on title field.
    if (!empty($lock_story)) {
      $output = l($values->node_title, 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage',array('attributes' => array('class' =>'lock')));
    }
    else {
      $output = l($values->node_title, 'node/' . $values->nid);
    }    
    
    return $output;
  }

}
