<?php
/**
 * Rename "Add Term" to "Add Category"
 * Remove primary local task link (Edit and manage fields links from right top side)
 */
global $base_url, $user;
if(!in_array('administrator', $user->roles)){
  if(arg(3) == 'category_management'){
      //$action_links = '<li><a href="'.$base_url.'/admin/structure/taxonomy/category_management/add">Add Category</a></li>';
      $primary_local_tasks = '';
  }
  
  //Tag Management
  if( arg(3) == 'tags'){
    $primary_local_tasks = '';
    $title = 'Create Tag';
  }
  
  //Hide primary local task for others user(except )
  if(arg(1) == 'people' && arg(2) == 'create'){
     $primary_local_tasks = '';
  }
}

if (theme_get_setting('rubik_show_branding')): ?>
<div id='branding'><div class='limiter clearfix'>
  <div class='breadcrumb clearfix'><?php print $breadcrumb ?></div>
  
  <?php if (!$overlay && isset($secondary_menu)) : ?>
    <?php print theme('links', array('links' => $secondary_menu, 'attributes' => array('class' => 'links secondary-menu'))) ?>
  <?php endif; ?>
  <div class="user-role">User role - <?php 
  // get role array
      $role_display=$user->roles;
      // skip key for authenticated user
      $role_display=array_slice($role_display,1);
      // get value in comma seprated
      $role_display = implode(',', $role_display);
      
      print $role_display;
  
  ?></div>
</div></div>
<?php endif; ?>

<div id='page-title'><div class='limiter clearfix'>
  <div class='tabs clearfix'>
    <?php if ($primary_local_tasks): ?>
      <ul class='primary-tabs links clearfix'><?php print render($primary_local_tasks) ?></ul>
    <?php endif; ?>
  </div>
  <?php print render($title_prefix); ?>
  <h1 class='page-title <?php print $page_icon_class ?>'>
    <?php if (!empty($page_icon_class)): ?><span class='icon'></span><?php endif; ?>
    <?php if ($title) print $title ?>
  </h1>
  <?php if ($action_links): ?>
    <ul class='action-links links clearfix'><?php print render($action_links) ?></ul>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
</div></div>

<?php if ($show_messages && $messages): ?>
<div id='console'><div class='limiter clearfix'><?php print $messages; ?></div></div>
<?php endif; ?>

<div id='page'><div id='main-content' class='limiter clearfix'>
  <?php if ($page['help']) print render($page['help']) ?>
  <?php $cls=''; if (!empty($page['sidebar_second'])): $cls="sidebar-second"; endif;?>
  <div id='content' class='page-content clearfix <?php print $cls;?>'>
    <?php if (!empty($page['content'])) print render($page['content']) ?>
    <?php if (!empty($page['sidebar_second'])) print render($page['sidebar_second']) ?>
  </div>
</div></div>

<div id='footer' class='clearfix'>
  <?php if ($feed_icons): ?>
    <div class='feed-icons clearfix'>
      <label><?php print t('Feeds') ?></label>
      <?php print $feed_icons ?>
    </div>
  <?php endif; ?>
</div>
