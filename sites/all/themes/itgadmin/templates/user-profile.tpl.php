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
   <?php 
   global $user;
   $edit_link = 'user/'.$user->uid.'/edit';
   ?>
  <?php if ($user_profile): ?>
  <div class="field-name-field-user-picture">
  <div class="field-items">
  <?php
   global $user, $base_url;  
   
   if (isset($elements['#account']->field_user_picture[LANGUAGE_NONE])) {
      $file = $elements['#account']->field_user_picture[LANGUAGE_NONE][0]['uri'];
      print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
    }
    else {
      $file = $base_url . '/sites/all/themes/itgadmin/images/user-default.png';
      print "<img src= $file>";
    }
    ?>
  </div>
  </div>
  <?php endif; ?>
  <div class="user-details">
    <?php print render($user_profile['field_first_name']); ?>
    <?php print render($user_profile['field_last_name']); ?>
    <?php print render($user_profile['field_mobile_number']); ?>
    <div class="field">
      <div class="field-label"><?php print t('User name'); ?>:</div>
      <div class="field-items"><?php print_r($elements['#account']->name); ?></div>
    </div> 
    <div class="field">
      <div class="field-label"><?php print t('Email'); ?>:</div>
      <div class="field-items"><?php print_r($elements['#account']->mail); ?></div>
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
  </div>
</div>
<?php
$view_user_id = $elements['#account']->uid;
if($user->uid == $view_user_id) {
?>
<div class="my-stats-last-details">
     
<?php
      
      // get last node title and type publish by user
      $last_record = itg_last_node_user($elements['#account']->uid);
      $last_record_type = ucfirst(str_replace('_', '', $last_record['type']));
      if(!empty($last_record)) {
      $last_record_display = '<strong>'.t('Last Content Filed:').'</strong> '.$last_record_type.' - '.$last_record['title'];
      }
      else
      {
      $last_record_display = t('Last Content Filed').' : N/A';
      }
      $last_publish_record = itg_last_publish_user_node($elements['#account']->uid,1);
      
      if(!empty($last_publish_record)) {
        $last_type = ucfirst(str_replace('_', '', $last_publish_record['type']));
        $last_record_publish = '<strong>'.t('Last Content Publish:').' </strong>'.ucwords($last_type).' - '.$last_publish_record['title'];
      }
      else
      {
        $last_record_publish = t('Last Content publish : N/A');
      }
      
?>

</div>

<?php 
 $contentlist = array("story","videogallery","photogallery","breaking_news","mega_review_critic","live_tv_integration","podcast","poll","survey","quiz"," print_team_integration","tasks","astro","recipe",);
$node_type = itg_get_all_node_type($elements['#account']->uid);
foreach ($node_type as $final_type) {
     if(in_array($final_type, $contentlist)) {
         $total_posted[]  =  itg_get_all_node($final_type,$elements['#account']->uid);
         $total_publish[] = itg_get_all_publish_node($final_type,$elements['#account']->uid);
     }
}
?>
<div class="my-stats">
<table class="views-table">
  <thead>
    <tr class='my-stats-status'>
      <th><?php print t('My Stats');?></th>
      <th>Total Posted: <?php print array_sum($total_posted);?></th>
      <th>Last Content Posted: <?php print l($last_record['title'], 'node/'.$last_record['nid']);?></th>  
      <th>Total Published: <?php print array_sum($total_publish);?></th>  
      <th>Last Content Published: <?php print l($last_publish_record['title'], 'node/'.$last_publish_record['nid']);?></th>  
    </tr>
    <tr>
      <th><?php print t('Contents');?></th>
      <th><?php print t('Posted');?></th>
      <th><?php print t('Published');?></th>  
      <th></th>  
      <th></th>  
    </tr>
  </thead>
  <tbody>
    <?php
      $contentlist = array("story","videogallery","photogallery","breaking_news","mega_review_critic","live_tv_integration","podcast","poll","survey","quiz"," print_team_integration","tasks","astro","recipe",);
      foreach ($node_type as $final_type) {
          
      $final_type1 = ucfirst(str_replace('_', ' ', $final_type));
      $total  =  itg_get_all_node($final_type,$elements['#account']->uid);
      $publish = itg_get_all_publish_node($final_type,$elements['#account']->uid);
     if(in_array($final_type, $contentlist)) {
    ?>
     
      
    <tr>
      <td><?php print $final_type1; ?></td>
      <td><?php print $total; ?></td>
      <td><?php print $publish; ?></td>
      <td></td>
      <td></td>
    </tr>
     <?php } }?>
  </tbody>
</table>



<?php
      $permissions= user_role_permissions($elements['#account']->roles);
      foreach($permissions as $key => $value) {
        foreach($value as $key1 => $value1) {
          // make create permission array
          if (strstr($key1, 'create')) {
        if (!strstr($key1, 'url')) {
          if (!strstr($key1, 'any')) {
            if (!strstr($key1, 'own')) {
             $create_arr = explode(' ', $key1);
              $final_create_arr[] = ucwords(str_replace('_', ' ', $create_arr[1]));
            }
          }
        }
      }
        
         // make delete permission array
        if(strstr($key1,'delete')) {
          
          if(!strstr($key1,'assign')) {
          $del_arr = explode(' ', $key1);
           if(!empty($del_arr[2]) && $del_arr[1]!= 'terms') {
          $final_del_arr[] = ucwords(str_replace('_', ' ', $del_arr[2]));
          $final_del_arr = array_unique($final_del_arr);
         
           }
          }
        }
        
        // make role permission array
        if(strstr($key1,'assign')) {
          $final_role_arr[] = ucwords($key1);
        }
      }
      }
      
      // conbert array to comma seprated
      $comma_create_arr = implode (", ", $final_create_arr);
      $comma_edit_arr = implode (", ", $final_edit_arr);
      $comma_role_arr = implode (", ", $final_role_arr);
      $comma_del_arr = implode (", ", $final_del_arr);
      
$output = "<h2>".t('My Permissions')."</h2><table class='views-table'>
        <thead>
        <tr>
        <th>".t('Operations')."</th>
        <th>".t('Types')."</th>
              </tr>
              </thead>
<tr>
        <td>".t('Create/Edit')."</td>
        <td>$comma_create_arr</td>
              </tr><tr>
        <td>".t('Delete')."</td>
        <td>$comma_del_arr</td>
          
              </tr>";
$routput = '';
foreach($user->roles as $key=>$value) {
  if($key != 2) {
$user_check = itg_common_check_role_access($key);
  }

}

$output .= $routput."</table>";
print $output;
?>

</div>
<?php
}
?>
