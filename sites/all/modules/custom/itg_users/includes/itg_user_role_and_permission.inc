<?php

/* 
 * Returns the string as user roles and thier permissions
 */

function itg_user_role_and_permissions(){
  
  $rol_per = NULL;
  $rol_per .= '<div class="token-table">
                <div class="itgadmin-popup-wrapper" id="mail-templates-token" style="display:none">
                <div class="itgadmin-popup">
                <span class="close-itgadmin-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
                <h2>'.t('Permissions According to Roles').'</h2>
                <div class="mail-table">';
  
  $query = db_select('role', 'r');
  $query->fields('r', array('rid', 'name'));
  $query->condition('r.rid', array(1, 2, 3), 'NOT IN');
  $result = $query->execute();
  $records_role = $result->fetchAll();
  foreach ($records_role as $rk => $rv) {
    $query = db_select('role_permission', 'rp');
    $query->fields('rp', array('permission'));
    $query->condition('rp.rid', $rv->rid);
    $result = $query->execute();
    $records_permission = $result->fetchAll();
    foreach ($records_permission as $rpk => $rpv) {
      if ($rpk == 0) {
        $class = '<b>'; 
      } else {
        $class = '<b class="hide" style="display:none;">'; 
      }
      $rol_per .= $class . $rv->name . "</b>";
      $rol_per .= "<ul><li>" . ucwords($rpv->permission) . "</li></ul>";
    }
  }
  $rol_per .= "</div>";
  $rol_per .= "</div>";
  $rol_per .= "</div>";
  return $rol_per;
}