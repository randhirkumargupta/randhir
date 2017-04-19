<?php

/**
 * @file
 * Views related hooks and handlers for Views Current Path.
 */

/**
 * Implements hook_views_data().
 */
function itg_story_views_data() {
  $data['views']['story_custom_view_link'] = array(
    'title' => t('Story custom view link'),
    'help' => t('The path of the page currently being viewed.'),
    'field' => array(
      'handler' => 'itg_story_views_handler_field_story_custom_view_link',
    ),
  );
  return $data;
}

/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_story_views_handler_field_story_custom_view_link extends views_handler_field {

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
    
      if (isset($values->_field_data['nid']['entity']->status) && $values->_field_data['nid']['entity']->status == 0 ) {
        $node_url = $base_url . '/node/' . $values->nid;
        $mob_link = '<a class="colorbox-load" href="'.$node_url.'?width=300&amp;height=600&amp;iframe=true">mobile</a>';
        $web_link = l('web' , 'node/' . $values->nid , array('attributes' => array('target' => '_blank')));        
      } else {
          //if (BACKEND_URL == $base_url ) {
            $node_url = FRONT_URL . '/node/' . $values->nid;
            $web_link = '<a href="' . $node_url . '" target="_blank">web</a>';
            $mob_link = '<a class="colorbox-load" href="'.$node_url.'?width=300&amp;height=600&amp;iframe=true">mobile</a>';      
          //}
      }
      $c_link = $web_link.' / '.$mob_link;
    return $c_link;
  }

}
