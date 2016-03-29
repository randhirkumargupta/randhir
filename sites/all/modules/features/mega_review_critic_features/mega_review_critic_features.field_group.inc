<?php
/**
 * @file
 * mega_review_critic_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mega_review_critic_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_review_basic_settings|node|mega_review_critic|form';
  $field_group->group_name = 'group_review_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mega_review_critic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_mega_review_director',
      1 => 'field_mega_review_movie_plot',
      2 => 'field_mega_review_photo_gallery',
      3 => 'field_mega_review_twitter',
      4 => 'field_mega_review_video',
      5 => 'field_mega_review_youtube_url',
      6 => 'field_mega_review_cast',
      7 => 'field_mega_review_type',
      8 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-review-basic-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_review_basic_settings|node|mega_review_critic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_review_browse_media|node|mega_review_critic|form';
  $field_group->group_name = 'group_review_browse_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mega_review_critic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Browse Media',
    'weight' => '1',
    'children' => array(
      0 => 'field_story_extra_large_image',
      1 => 'field_story_extra_small_image',
      2 => 'field_story_large_image',
      3 => 'field_story_medium_image',
      4 => 'field_story_small_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-review-browse-media field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_review_browse_media|node|mega_review_critic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_review_movie_review|node|mega_review_critic|form';
  $field_group->group_name = 'group_review_movie_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mega_review_critic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Movie Review',
    'weight' => '2',
    'children' => array(
      0 => 'field_mega_review_review',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-review-movie-review field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_review_movie_review|node|mega_review_critic|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Details');
  t('Browse Media');
  t('Movie Review');

  return $field_groups;
}
