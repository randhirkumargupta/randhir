<?php
global $base_url;
$actual_host = explode('://', $base_url);
$host_node = itg_event_backend_get_host_node($actual_host[1]);

// Css variables
$menu_background_color = $host_node->field_ec_menu_background_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_ec_menu_background_color[LANGUAGE_NONE][0]['rgb'] : '#000';
$heading_background_color = $host_node->field_ec_heading_bck_color[LANGUAGE_NONE][0]['rgb'];
$font_color = $host_node->field_ec_font_color[LANGUAGE_NONE][0]['rgb'];
?>


<div class="program-sub-title" style="background: <?php print $heading_background_color; ?>">Program Schedule</div>
<div class="row">
<?php foreach ($rows as $index => $row): ?>
<div class="col-md-6">
    <div class="content-list" style="background: <?php print $heading_background_color; ?>">
    <?php print $row['field_start_time']; ?>
        <div class="story-expert-name" style="color: <?php print $font_color; ?>"> <?php print $row['field_story_expert_name']; ?></div>
    <?php //print $row['field_daywise_event']; ?>
              
     <?php //print $row['title']; ?>
   <?php print $row['view']; ?>
   
  </div>
</div>    
<?php endforeach; ?>
</div>