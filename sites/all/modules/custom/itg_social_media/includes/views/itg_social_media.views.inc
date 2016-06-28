<?php
/**
 * @file
 * itg_social_media.views.inc file for adding custom table to views.
 */
function itg_social_media_views_data() {  
  $data['itg_social_media_logs']['table']['group'] = t('Social Media Logs');   
  $data['itg_social_media_logs']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Social media Logs'),
    'help' => t('Social media logs are stroed in this table.'),
    'weight' => -10,
  );    
  $data['itg_social_media_logs']['table']['join'] = array(    
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  
  $data['itg_social_media_logs']['nid'] = array(
    'title' => t('Node id of the story'),
    'help' => t('Each nid reference to a full story.'),    
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',      
      'handler' => 'views_handler_relationship',
      'label' => t('Social Media Logs'),
      'title' => t('relate a node to social media post'),
      'help' => t('Social Media custom table'),
    ),
  );
  
  // Example plain text field.
  $data['itg_social_media_logs']['node_title'] = array(
    'title' => t('Node title'),
    'help' => t('Title of the story posted to social media'),
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
  $data['itg_social_media_logs']['username'] = array(
    'title' => t('Username'),
    'help' => t('Name of the user who has posted the content to social media'),
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
  
  $data['itg_social_media_logs']['social_media'] = array(
    'title' => t('Social media'),
    'help' => t('Name of the social media where content has been posted'),
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
  
  $data['itg_social_media_logs']['created'] = array(
    'title' => t('Created time'),
    'help' => t('When the content has been posted to social media.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  $data['itg_social_media_logs']['scheduled_time'] = array(
    'title' => t('Scheduled Time'),
    'help' => t('When the content will publish on social media.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['itg_social_media_logs']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status of the post.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'published-unpublished' => array(t('Published'), t('unpublished')),
      )
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Status'),
      'type' => 'published-unpublished',
      'use equal' => TRUE,
    ),
  );
  
  return $data;
}