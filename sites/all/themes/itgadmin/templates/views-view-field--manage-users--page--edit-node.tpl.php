<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
global $user;
if (array_key_exists(EDITOR, $user->roles)) {
    $user_array = array(AUTHOR_GUEST=>'Author/Guest', COPY_EDITOR=>'Copy Editor', INTERN=>'Intern', SECTION_EDITOR_ANCHOR=>'Section Editor/Anchor',  SUBEDITOR_SR_SUB=>'Subeditor/Sr.Sub', CO_ORDINATOR => 'Co-ordinator', COPY_DESK => 'Copy Desk', CORRESPONDENT=>'Correspondent', DESIGN_HEAD=>'Design Head', DESIGNER=>'Designer');
  }else if (array_key_exists(SECTION_EDITOR_ANCHOR, $user->roles)) {
    $user_array = array(AUTHOR_GUEST=>'Author/Guest', COPY_EDITOR=>'Copy Editor', INTERN=>'Intern', SUBEDITOR_SR_SUB=>'Subeditor/Sr.Sub' );
  }else if (array_key_exists(COPY_EDITOR, $user->roles)) {
    $user_array = array(AUTHOR_GUEST=>'Author/Guest', INTERN=>'Intern', SUBEDITOR_SR_SUB=>'Subeditor/Sr.Sub' );
  }else if (array_key_exists(SUBEDITOR_SR_SUB, $user->roles)) {
    $user_array = array(AUTHOR_GUEST=>'Author/Guest',INTERN=>'Intern' );
  }else if(array_key_exists(SITE_ADMIN, $user->roles) || array_key_exists(ADMINISTRATOR, $user->roles)) {
    $user_array = array(AUTHOR_GUEST=>'Author/Guest', COPY_EDITOR=>'Copy Editor', CORRESPONDENT=>'Correspondent', CO_ORDINATOR=>'Co-ordinator', COPY_DESK=>'Copy Desk', DESIGN_HEAD=>'Design Head', DESIGNER=>'Designer', EDITOR=>'Editor', EXPERT=>'Expert', INTERN=>'Intern', PHOTO_COORDINATOR=>'Photo Coordinator', PHOTOGRAPHER=>'Photographer', PHOTO_HEAD=>'Photo Head', SECTION_EDITOR_ANCHOR=>'Section Editor/Anchor', SUBEDITOR_SR_SUB=>'Subeditor/Sr.Sub', SEO=>'SEO', UGC_MODERATOR=>'UGC Moderator', FRONT_USER => 'Front User', MARKETING_MANAGER => 'Marketing Manager', SOCIAL_MEDIA => 'Social Media');
  }



$user_role = $row->_field_data['uid']['entity']->roles;
$user_intersec = array_intersect($user_role, $user_array);

if (!empty($user_intersec)) {
  print $output; 
}


?>