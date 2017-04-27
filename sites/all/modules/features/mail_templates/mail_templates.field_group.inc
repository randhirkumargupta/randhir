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
    'weight' => '4',
    'children' => array(
      0 => 'field_ask_an_expert_case',
      1 => 'field_mail_body_expert',
      2 => 'field_mail_subject_expert',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Ask an Expert',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category ask_an_expert',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_ask_an_expert|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cms_mail_template|node|mail_templates|form';
  $field_group->group_name = 'group_cms_mail_template';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CMS mail template',
    'weight' => '5',
    'children' => array(
      0 => 'field_cms_mail_template_category',
      1 => 'field_cms_status',
      2 => 'field_mail_body_cms_mail',
      3 => 'field_mail_subject_cms_mail',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'CMS mail template',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_mail_body_follow_story',
      1 => 'field_mail_subject_follwo_story',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Follow Story',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category follow_story',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '8',
    'children' => array(
      0 => 'field_mail_body_loyalty',
      1 => 'field_mail_subject_loyalty',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Loyalty Points',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category loyalty_points_expiration',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '11',
    'children' => array(
      0 => 'field_mail_body_password_changed',
      1 => 'field_mail_subject_password_chan',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Password Changed',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category password_changed',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '9',
    'children' => array(
      0 => 'field_mail_body_print_team',
      1 => 'field_mail_subject_print_t',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Print Team',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category print_team',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '7',
    'children' => array(
      0 => 'field_mail_body_product_expirati',
      1 => 'field_mail_subject_product_expir',
      2 => 'field_product_expiration_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Product Expiration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category product_expiration',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '10',
    'children' => array(
      0 => 'field_mail_body_sign_up',
      1 => 'field_mail_subject_sign_up',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sign Up',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category sign_up',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '6',
    'children' => array(
      0 => 'field_mail_body_task_idea_assign',
      1 => 'field_mail_subject_body',
      2 => 'field_mail_subject_task_idea',
      3 => 'field_new_task_status',
      4 => 'field_to_assignee',
      5 => 'field_to_assigner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Task/Idea',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category task_idea',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '2',
    'children' => array(
      0 => 'field_mail_body_ugc',
      1 => 'field_mail_subject',
      2 => 'field_ugc_comments_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'UGC',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'mail-template-category ugc',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
