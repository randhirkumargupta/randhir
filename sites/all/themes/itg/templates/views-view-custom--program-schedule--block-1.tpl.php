<?php


global $base_url;
$actual_host = explode('://', $base_url);
$host_node = itg_event_backend_get_host_node($actual_host[1]);

// Css variables
$heading_background_color = $host_node->field_ec_heading_bck_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_ec_heading_bck_color[LANGUAGE_NONE][0]['rgb'] : '#eee';
$font_color = $host_node->field_ec_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_ec_font_color[LANGUAGE_NONE][0]['rgb'] : '#ef2a24';
$content_font_color = $host_node->field_ec_content_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_ec_content_font_color[LANGUAGE_NONE][0]['rgb'] : '#000';
drupal_add_js("jQuery(document).ready(function() { jQuery('.program-schedule-content a').css('color', '".$content_font_color."'); });",'inline');
?>


<div class="program-sub-title" style="background: <?php print $heading_background_color; ?>">Program Schedule</div>
<div class="row">
<?php foreach ($rows as $index => $row): ?>
<div class="col-md-6">
    <div class="content-list" style="background: <?php print $heading_background_color; ?>">
    <div style="color:<?php print $content_font_color; ?>"><?php print $row['field_start_time']; ?></div>
        <div class="story-expert-name" style="color: <?php print $font_color; ?>"> <?php print $row['field_story_expert_name']; ?></div>
    <?php //print $row['field_daywise_event']; ?>
              
     <?php //print $row['title']; ?>
   <div class="program-schedule-content" style="color:<?php print $content_font_color; ?>"><?php print $row['view']; ?></div>
   
  </div>
</div>    
<?php endforeach; ?>
</div>