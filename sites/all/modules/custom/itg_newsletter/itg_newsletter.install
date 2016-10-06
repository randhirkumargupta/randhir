<?php
/**
 * @file
 * Install functions for newsletter.
 */

/**
 * Implements hook_schema()
 * Defining table structure to store newsletter information
 * @return array
 */
function itg_newsletter_schema() {
  $schema['itg_cron_newsletter'] = array(
      'description' => 'Table for itg_newsletter module',
      'fields' => array(
          'id' => array(
              'description' => 'The Primary Id',
              'type' => 'serial',
              'unsigned' => TRUE,
              'not null' => TRUE,
          ),
          'nid' => array(
              'description' => 'Node Id',
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
              'default' => 0,
          ),
          'type' => array(
              'description' => 'Node Type',
              'type' => 'varchar',
              'length' => 255,
              'not null' => TRUE,
              'default' => '',
          ),
          'scheduled_time' => array(
              'description' => 'Cron Scheduled Time',
              'type' => 'varchar',
              'length' => 255,
              'not null' => TRUE,
              'default' => '',
          ),
         'frequency' => array(
              'description' => 'Frequency',
              'type' => 'varchar',
              'length' => 255,
              'not null' => TRUE,
              'default' => '',
          ),
          'status' => array(
              'description' => 'Status',
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
              'default' => 0,
          ),
          'created' => array(
              'type' => 'int',
              'not null' => TRUE,
              'default' => 0
          ),
      ),
      'primary key' => array('id'),
  );
  
   //schema for itg_syndication_manual_feed_details
  
  $schema['itg_newslatter_update_details'] = array(
    'description' => 'The base table for newslatter.',
    'fields' => array(
      'id' => array(
        'description' => 'The primary identifier for a node.',
        'type' => 'serial',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'name' => array(
        'description' => 'User name.',
        'type' => 'varchar',
        'length' => '128',
        'not null' => TRUE,
        'default' => '',
      ),
      'email' => array(
        'description' => 'User email.',
        'type' => 'varchar',
        'length' => '255',
        'not null' => TRUE,
        'default' => '',
      ),
      'mobile' => array(
        'description' => 'User mobile.',
        'type' => 'varchar',
        'length' => '255',
        'not null' => TRUE,
        'default' => '',
      ),
      'section' => array(
        'description' => 'Newslatter Section : send mail by section.',
        'type' => 'varchar',
        'length' => '255',
        'not null' => TRUE,
        'default' => '',
      ),
      'created' => array(
        'description' => 'The created date for the single record',
        'type' => 'int',
        'not null' => TRUE,
        'default' => 0
       ),
    ),
    'primary key' => array('id'),
  );
  

  return $schema;
}
