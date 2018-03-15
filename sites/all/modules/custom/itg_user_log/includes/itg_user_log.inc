<?php
/**
 * Function to get json output for name.
 * @param string $name
 */
function itg_users_output_for_report($name) {
  $roles = user_roles();
  $fornt_user_role_id = array_search('Front User' , $roles);
  $query = db_select('users' , 'u');
  $query->leftJoin('users_roles' , 'ur' , 'ur.uid = u.uid');
  $query->fields('u' , array('name'));
  $query->condition('u.name' , '%' . db_like($name) . '%' , 'LIKE');
  $query->condition('status' , 1);
  $query->condition('ur.rid' , $fornt_user_role_id);
  $query->range(0 , 20);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach($result as $record) {
    $options[$record['name']] = $record['name'];
  }

  drupal_json_output($options);
}


/**
 * Function to get json output for email.
 * @param string $name
 */
function itg_users_email_output_for_report($name) {
  $roles = user_roles();
  $fornt_user_role_id = array_search('Front User' , $roles);
  $query = db_select('users' , 'u');
  $query->leftJoin('users_roles' , 'ur' , 'ur.uid = u.uid');
  $query->fields('u' , array('mail'));
  $query->condition('u.mail' , '%' . db_like($name) . '%' , 'LIKE');
  $query->condition('status' , 1);
  $query->condition('ur.rid' , $fornt_user_role_id);
  $query->range(0 , 20);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  
  foreach($result as $record) {
    $options[$record['mail']] = $record['mail'];
  }

  drupal_json_output($options);
}