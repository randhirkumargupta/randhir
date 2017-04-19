<?php
/**
 * @file
 * mail_templates.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mail_templates_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ask_an_expert|node|mail_templates|form';
  $field_group->group_name = 'group_ask_an_expert';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ask an Expert',
    'weight' => '7',
    'children' => array(
      0 => 'field_ask_an_expert_case',
      1 => 'field_mail_subject_expert',
      2 => 'field_mail_body_expert',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ask-an-expert field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_ask_an_expert|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cms_mail_template|node|mail_templates|form';
  $field_group->group_name = 'group_cms_mail_template';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CMS mail template',
    'weight' => '8',
    'children' => array(
      0 => 'field_cms_mail_template_category',
      1 => 'field_mail_subject_cms_mail',
      2 => 'field_mail_body_cms_mail',
      3 => 'field_cms_status',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cms-mail-template field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cms_mail_template|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_follow_story|node|mail_templates|form';
  $field_group->group_name = 'group_follow_story';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Follow Story',
    'weight' => '6',
    'children' => array(
      0 => 'field_mail_subject_follwo_story',
      1 => 'field_mail_body_follow_story',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Follow Story',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-follow-story field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_follow_story|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_loyalty_points|node|mail_templates|form';
  $field_group->group_name = 'group_loyalty_points';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Loyalty Points',
    'weight' => '11',
    'children' => array(
      0 => 'field_mail_subject_loyalty',
      1 => 'field_mail_body_loyalty',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-loyalty-points field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_loyalty_points|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_password_changed|node|mail_templates|form';
  $field_group->group_name = 'group_password_changed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Password Changed',
    'weight' => '14',
    'children' => array(
      0 => 'field_mail_subject_password_chan',
      1 => 'field_mail_body_password_changed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-password-changed field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_password_changed|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_print_team|node|mail_templates|form';
  $field_group->group_name = 'group_print_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Print Team',
    'weight' => '12',
    'children' => array(
      0 => 'field_mail_subject_print_t',
      1 => 'field_mail_body_print_team',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-print-team field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_print_team|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_expiration|node|mail_templates|form';
  $field_group->group_name = 'group_product_expiration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Expiration',
    'weight' => '10',
    'children' => array(
      0 => 'field_product_expiration_status',
      1 => 'field_mail_subject_product_expir',
      2 => 'field_mail_body_product_expirati',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product-expiration field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_product_expiration|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sign_up|node|mail_templates|form';
  $field_group->group_name = 'group_sign_up';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sign Up',
    'weight' => '13',
    'children' => array(
      0 => 'field_mail_subject_sign_up',
      1 => 'field_mail_body_sign_up',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sign-up field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sign_up|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_idea|node|mail_templates|form';
  $field_group->group_name = 'group_task_idea';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Task/Idea',
    'weight' => '9',
    'children' => array(
      0 => 'field_new_task_status',
      1 => 'field_mail_subject_task_idea',
      2 => 'field_mail_subject_body',
      3 => 'field_to_assigner',
      4 => 'field_to_assignee',
      5 => 'field_mail_body_task_idea_assign',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-task-idea field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_task_idea|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ugc|node|mail_templates|form';
  $field_group->group_name = 'group_ugc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'UGC',
    'weight' => '5',
    'children' => array(
      0 => 'field_mail_subject',
      1 => 'field_ugc_comments_status',
      2 => 'field_mail_body_ugc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'UGC',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-ugc field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_ugc|node|mail_templates|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ask an Expert');
  t('CMS mail template');
  t('Follow Story');
  t('Loyalty Points');
  t('Password Changed');
  t('Print Team');
  t('Product Expiration');
  t('Sign Up');
  t('Task/Idea');
  t('UGC');

  return $field_groups;
}
