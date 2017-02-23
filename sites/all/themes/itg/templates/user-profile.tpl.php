<?php
/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */

  ?>
<div class="user-profile-div">
<div class="user-details">
    <?php if (!array_key_exists(FRONT_USER, $elements['#account']->roles)) { ?>
    <?php print render($user_profile['field_first_name']); ?>
    <?php print render($user_profile['field_last_name']); ?>
    <?php print render($user_profile['field_mobile_number']); ?>
    
    <div class="field">
      <div class="field-label"><?php print t('User name'); ?>:</div>
      <div class="field-items"><?php print $elements['#account']->name; ?></div>
    </div> 
    <div class="field">
      <div class="field-label"><?php print t('Email'); ?>:</div>
      <div class="field-items"><?php print $elements['#account']->mail; ?></div>
    </div>
    <div class="field">
      <div class="field-label"><?php print t('Role'); ?>:</div>
      <div class="field-items"><?php 
      // get role array
      $role_display=$elements['#account']->roles;
      // skip key for authenticated user
      $role_display=array_slice($role_display,1);
      // get value in comma seprated
      $role_display = implode(',', $role_display);
      
      print $role_display;?></div> 
    </div>
    <div class="field">
      <div class="field-label"><?php print_r($user_profile['summary']['member_for']['#title']); ?>:</div>
      <div class="field-items"><?php print_r($user_profile['summary']['member_for']['#markup']); ?></div>
    </div>
      <?php } ?>    
  </div>
</div>
