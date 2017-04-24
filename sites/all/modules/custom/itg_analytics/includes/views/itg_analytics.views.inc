<?php

/**
 * @file
 * File provide view integration functionality
 */

/**
 * Implements HOOK_view_data.
 * {@inheritdoc}
 */
function itg_analytics_views_data() {
  $data = array();
  $data['itg_node_analytics_count_data']['table']['group'] = t('Itg Analytics');
  $data['itg_node_analytics_count_data']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Itg Analytics'),
    'help' => t('Node analytics data saved into database.'),
    'weight' => -10,
  );

  $data['itg_node_analytics_count_data']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['itg_node_analytics_count_data']['count'] = array(
    'title' => t('Analytics count'),
    'help' => t('Analytics count'),
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

  $data['itg_node_analytics_count_data']['nid'] = array(
    'title' => t('Node id to be refered'),
    'help' => t('Node id to be refered'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Analytics'),
      'title' => t('itg_analytics nid Title'),
      'help' => t('This relationship provide node relation with itg analytics.'),
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
