<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
if(isset($row->nid)) {
    $nid = $row->nid;
} elseif(isset($row->node_itg_widget_order_nid)) {
    $nid = $row->node_itg_widget_order_nid;
}
global $base_url, $user;
$arg = arg();

if ($arg[2] != 'story' && $external_url = _is_external_url_story_article($row->nid)) {
  print l($row->_field_data['nid']['entity']->title, $external_url);
} else if ($field->view->name == 'strory_menegment' && $field->view->current_display == 'page' && $row->_field_data['nid']['entity']->type == 'story') {
   print l($row->_field_data['nid']['entity']->title, 'node/' . $row->nid . '/edit', array(
    'query' => drupal_get_destination()
  ));
} else if ($field->view->name == 'speaker_option_for_event' || $field->view->name == 'autocomplete_for_event' || $field->view->name == 'autocomplete_event_photo' || $field->view->name == 'podcast_for_event' || $field->view->name == 'manage_survey' || $field->view->name == 'manage_quiz' || $field->view->name == 'bitrates_videos') {
  
  if ($field->view->name == 'manage_survey') {
    if (($row->_field_data['nid']['entity']->status == 0) || array_key_exists(SITE_ADMIN, $user->roles)) {
      print l($row->_field_data['nid']['entity']->title, 'node/' . $row->nid . '/edit', array(
        'query' => drupal_get_destination()
      ));
    } else {
      echo $row->_field_data['nid']['entity']->title;
    }
  } else {
    print $output;
  }
} elseif ((isset($arg[0]) && $arg[0] == 'itg-custom-widget-content') || isset($row->_field_data['nid']['entity']->type) && ($row->_field_data['nid']['entity']->type == 'itg_funalytics') || $arg[0] == 'menu-manager') {
  print html_entity_decode($output);
} elseif (isset($row->_field_data['nid']['entity']->type) && ($row->_field_data['nid']['entity']->type == 'blog' || $row->_field_data['nid']['entity']->type == 'photogallery' || $row->_field_data['nid']['entity']->type == 'videogallery' || $row->_field_data['nid']['entity']->type == 'mega_review_critic' || $row->_field_data['nid']['entity']->type == 'podcast' || $row->_field_data['nid']['entity']->type == 'story' || $row->_field_data['nid']['entity']->type == 'event_backend' || $row->_field_data['nid']['entity']->type == 'breaking_news')) {
  
  if (isset($row->_field_data['nid']['entity']->status) && $row->_field_data['nid']['entity']->status == 0) {
    if ($row->_field_data['nid']['entity']->type == 'event_backend') {
      print html_entity_decode(l(strip_tags($output), 'node/' . $row->nid . '/edit', array(
        'attributes' => array(
          'target' => '_blank'
        )
      )));
    } else {
      print html_entity_decode(l(strip_tags($output), 'node/' . $row->nid, array(
        'attributes' => array(
          'target' => '_blank'
        )
      )));
    }
  } else {
    if (BACKEND_URL == $base_url) {
      if ($row->_field_data['nid']['entity']->type == 'event_backend') {
        //$event_url_alias = drupal_get_path_alias($path = 'node/'.$row->nid, $path_language = NULL);
        //$event_register_url = FRONT_URL.'/'.$event_url_alias.'/'.'registration';
        $event_edit_url = BACKEND_URL . '/' . 'node/' . $row->nid . '/edit';
        //print '<a href="' . $event_register_url . '" target="_blank">' . html_entity_decode(strip_tags($output)) . '</a>';
        print '<a href="' . $event_edit_url . '" target="_blank">' . html_entity_decode(strip_tags($output)) . '</a>';
      } else {
        $alias_url = drupal_get_path_alias('node/' . $row->nid);
        $node_url = FRONT_URL . '/'.$alias_url;
        print '<a href="' . $node_url . '" target="_blank">' . html_entity_decode(strip_tags($output)) . '</a>';
      }
    } else {
      if (is_widget_views($view)) {
        print html_entity_decode(l(strip_tags($output), 'node/' . $nid . '/edit', array(
          'attributes' => array(
            'target' => '_blank'
          )
        )));
      } else {
        //print l(strip_tags($output) , 'node/' . $row->nid , array('attributes' => array('target' => '_blank')));
        print html_entity_decode(strip_tags($output));
      }
    }
  }
} else {
     if (is_widget_views($view)) {
         print html_entity_decode(l(strip_tags($output), 'node/' . $nid . '/edit', array(
          'attributes' => array(
            'target' => '_blank'
          )
        )));
     } else {
        print html_entity_decode(strip_tags($output));
     }
}
