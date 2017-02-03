<?php

function itg_workflow_views_data() {
  $data['itg_workflow_preview_log']['table']['group'] = t('Itg preview node log.');
  $data['itg_workflow_preview_log']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Preview listing'),
    'weight' => -10,
  );
  $data['itg_workflow_preview_log']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['itg_workflow_preview_log']['nid'] = array(
    'title' => t('Node Id'),
    'help' => t('Node Id'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Preview Logs'),
      'help' => t('More information on this relationship'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['itg_workflow_preview_log']['uid'] = array(
    'title' => t('User Id'),
    'help' => t('User ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
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
