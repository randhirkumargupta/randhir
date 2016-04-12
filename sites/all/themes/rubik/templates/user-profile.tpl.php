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
  <?php if ($user_profile): ?>
    <?php // print render($user_profile['field_user_picture']);
    ?>
  <div class="field-name-field-user-picture">
  <div class="field-items">
  <?php
   global $user, $base_url;  
   
   if (isset($elements['#account']->field_user_picture[LANGUAGE_NONE])) {
      $file = $elements['#account']->field_user_picture[LANGUAGE_NONE][0]['uri'];
      print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
    }
    else {
      $file = $base_url . '/sites/all/themes/rubik/images/user-default.png';
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
    <?php //echo "<pre>";?>
    <?php //print_r ($elements['#account']->name); ?>
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

<div class="my-stats">
<h2> My Stats </h2>
<?php $node_type = itg_get_all_node_type($elements['#account']->uid); ?>
<table class="views-table">
  <thead>
    <tr>
      <th>My Stats</th>
      <th>Published</th>
      <th>Total Created</th>
    </tr>
  </thead>
  <tbody>
    <?php
      foreach ($node_type as $final_type) {
      $final_type1 = ucfirst(str_replace('_', '', $final_type));
      $total  =  itg_get_all_node($final_type,$elements['#account']->uid);
      $publish = itg_get_all_publish_node($final_type,$elements['#account']->uid);
    ?>
    <tr>
      <td><?php print $final_type1; ?></td>
      <td><?php print $publish; ?></td>
      <td><?php print $total; ?></td>
    </tr>
    <?php } ?>
  </tbody>
</table>

<div class="my-stats-last-details">

<?php
      
      // get last node title and type publish by user
      $last_record = itg_last_node_user($elements['#account']->uid);
      $last_record_type = ucfirst(str_replace('_', '', $last_record['type']));
      if(!empty($last_record)) {
      $last_record_display = '<strong>Last Content Filed:</strong> '.$last_record_type.' - '.$last_record['title'];
      print '<div class="my-stats-left">' . $last_record_display . '</div>';
      }
      else
      {
      $last_record_display = 'Last Content Filed : N/A';
      print '<div class="my-stats-left">' . $last_record_display . '</div>';
      }
      $last_publish_record = itg_last_node_published_user($elements['#account']->uid,'1');
      
      if(!empty($last_publish_record)) {
        $last_title = node_load($last_publish_record['nid'], $last_publish_record['vid']);
        $last_record_publish = '<strong>Last Content publish:</strong> '.$last_title->title;
        print '<div class="my-stats-right">' . $last_record_publish . '</div>';
      }
      else
      {
        $last_record_publish = 'Last Content publish : N/A';
        print '<div class="my-stats-right">' . $last_record_publish . '</div>';
      }
      
?>

</div>

<?php
      $permissions= user_role_permissions($elements['#account']->roles);
      foreach($permissions as $key => $value) {
        foreach($value as $key1 => $value1) {
          //pr($key1);
          // make create permission array
         if(strstr($key1,'create')) {
          $create_arr = explode(' ', $key1);
          $final_create_arr[] = ucwords(str_replace('_', ' ', $create_arr[1]));
        }
        
        // make edit permission array
        if(strstr($key1,'edit')) {
          
          if(!strstr($key1,'assign')) {
          $edit_arr = explode(' ', $key1);
           if(!empty($edit_arr[2]) && $edit_arr[1]!= 'terms') {
          $final_edit_arr[] = ucwords(str_replace('_', ' ', $edit_arr[2]));
          $final_edit_arr = array_unique($final_edit_arr);
         
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
          $role_arr = explode(' ', $key1);
          $final_role_arr[] = ucwords(str_replace('_', ' ', $role_arr[1]));
        }
      }
      }
      
      // conbert array to comma seprated
      $comma_create_arr = implode (", ", $final_create_arr);
      $comma_edit_arr = implode (", ", $final_edit_arr);
      $comma_role_arr = implode (", ", $final_role_arr);
      $comma_del_arr = implode (", ", $final_del_arr);
      
$output = "<h2>My Permissions</h2><table style='width:100%'>
        <tr>
        <th>Operations</th>
        <th>Types</th>
              </tr><tr>
        <td>create</td>
        <td>$comma_create_arr</td>
              </tr><tr>
        <td>Edit</td>
        <td>$comma_edit_arr</td>
          
              </tr><tr>
        <td>Delete</td>
        <td>$comma_del_arr</td>
          
              </tr><tr>
        <td>Role</td>
        <td>$comma_role_arr</td>
          
              </tr>";      
$output .= "</table>";

print $output;
?>

</div>

<?php
// query to get count of All node 
function itg_get_all_node($content_type,$uid) {
  
  $query = "SELECT COUNT(*) amount FROM {node} n ".
              "WHERE n.type = :type AND n.uid = :uid";
     $result = db_query($query, array(':type' => $content_type, ':uid' => $uid))->fetch();
     return $result->amount;
}

// query to get count of publsh node 
function itg_get_all_publish_node($content_type,$uid) {
  
  $query = "SELECT COUNT(*) amount FROM {node} n ".
              "WHERE n.type = :type AND n.uid = :uid AND n.status = '1'";
     $result = db_query($query, array(':type' => $content_type, ':uid' => $uid))->fetch();
     return $result->amount;
}

// query to get all node type of user
function itg_get_all_node_type($uid) {
  
  $result = db_select('node', 'n')
          ->fields('n', array('type'))
          ->condition('uid', $uid, '=')
          ->groupBy('type')
          ->execute();
  
  while($record = $result->fetchAssoc()) {
        $type[] = $record['type'];
    }
    
    return $type;
}


// query to get last node created by user
function itg_last_node_user($uid) {
  
  $last_result = db_select('node', 'n')
          ->fields('n', array('title','type'))
          ->condition('uid', $uid, '=')
          ->orderBy('created', 'DESC')//ORDER BY created
          ->range(0,1)
          ->execute();
  
  while ($last_record = $last_result->fetchAssoc()) {
    $last_record_info['title'] = $last_record['title'];
    $last_record_info['type'] = $last_record['type'];
  }
  
    return $last_record_info;
}

// query to get last node published by user
function itg_last_node_published_user($uid,$publish_id) {
  
  $last_publish_result = db_select('workbench_moderation_node_history', 'w')
          ->fields('w', array('nid','vid'))
          ->condition('uid', $uid, '=')
          ->condition('published', $publish_id, '=')
          ->orderBy('stamp', 'DESC')//ORDER BY created
          ->range(0,1)
          ->execute();
  
  while ($last_publish_record = $last_publish_result->fetchAssoc()) {
    $last_publish_record_info['vid'] = $last_publish_record['vid'];
    $last_publish_record_info['nid'] = $last_publish_record['nid'];
  }
  
    return $last_publish_record_info;
}

?>