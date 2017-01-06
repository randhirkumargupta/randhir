<?php

/**
 * @file
 * Itg_social_media.views.inc file for adding custom table to views.
 */

/**
 * Implements hook_views_data().
 *
 * {@inheritdoc}.
 */
function itg_widget_views_data() {
    $data['itg_widget_order']['table']['group'] = t('Section wise ordering content');
    $data['itg_widget_order']['table']['base'] = array(
        'field' => 'nid',
        'title' => t('Section wise ordering content'),
        'help' => t('Node form ids are saved into database.'),
        'weight' => -10,
    );

    // Plain text field.
    $data['itg_widget_order']['cat_id'] = array(
        'title' => t('Category'),
        'help' => t('Category tid'),
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

    // Example timestamp field.
    $data['itg_widget_order']['content_type'] = array(
        'title' => t('Content type'),
        'help' => t('Content type which is saved in database'),
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

    $data['itg_widget_order']['widget'] = array(
        'title' => t('Widget'),
        'help' => t('Widget name.'),
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
    $data['itg_widget_order']['state'] = array(
        'title' => t('state'),
        'help' => t('state name.'),
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
      $data['itg_widget_order']['id'] = array(
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
       $data['itg_widget_order']['id'] = array(
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
       $data['itg_widget_order']['nid'] = array(
        'title' => t('nid'),
        'help' => t('nid.'),
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
    
      $data['itg_widget_order']['extra'] = array(
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
    
    $data['itg_widget_order']['constituency'] = array(
        'title' => t('constituency'),
        'help' => t('constituency field value'),
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

    $data['itg_widget_order']['weight'] = array(
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

    $data['itg_widget_order']['table']['join'] = array(
        'node' => array(
            'left_field' => 'nid',
            'field' => 'nid',
        ),
    );

    // Node ID table field.
    $data['itg_widget_order']['nid'] = array(
        'title' => t('Node id to be refered'),
        'help' => t('Node id to be refered'),
        'relationship' => array(
            'base' => 'node', // The name of the table to join with.
            'base field' => 'nid', // The name of the field on the joined table.
            // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
            'handler' => 'views_handler_relationship',
            'label' => t('Node table relationship'),
            'title' => t('itg_widget_order nid Title'),
            'help' => t('More information on this relationship'),
        ),
    );

    return $data;
}
