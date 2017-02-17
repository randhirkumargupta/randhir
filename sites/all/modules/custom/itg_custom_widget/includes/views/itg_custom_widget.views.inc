<?php

function itg_custom_widget_views_data() {
  $data['itg_custom_widgets_data']['table']['group'] = t('Itg custom widget');
  $data['itg_custom_widgets_data']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Itg custom widget'),
    'help' => t('Node form ids are saved into database.'),
    'weight' => -10,
  );

  $data['itg_custom_widgets_data']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['itg_custom_widgets_data']['widget'] = array(
    'title' => t('Widget'),
    'help' => t('Widget name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['itg_custom_widgets_data']['tid'] = array(
    'title' => t('id'),
    'help' => t('id.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['itg_custom_widgets_data']['extra'] = array(
    'title' => t('extra'),
    'help' => t('extra.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['itg_custom_widgets_data']['weight'] = array(
    'title' => t('weight'),
    'help' => t('Weight.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Node ID table field.
  $data['itg_custom_widgets_data']['nid'] = array(
    'title' => t('Node id to be refered'),
    'help' => t('Node id to be refered'),
    'relationship' => array(
      'base' => 'node', // The name of the table to join with.
      'base field' => 'nid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Node table relationship'),
      'title' => t('itg_custom_widgets_data nid Title'),
      'help' => t('More information on this relationship'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  return $data;
}
