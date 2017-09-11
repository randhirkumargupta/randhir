<?php

global $base_url;
$arg = arg();
if (!empty($arg1) && is_numeric($arg1)) {
  $host_node = node_load($arg1);
}elseif($arg[0] == 'event'){
  $path = drupal_lookup_path("source", $arg[0].'/'.$arg[1]);
  $host_node = menu_get_object("node", 1, $path);
}
$actual_host_name = itg_event_get_host_name();

if($actual_host_name) {
  $baseurl = $actual_host_name.'/';
}
// Css variables
$heading_background_color = $host_node->	field_e_heading_bck_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->	field_e_heading_bck_color[LANGUAGE_NONE][0]['rgb'] : '#eee';
$font_color = $host_node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] : '#ef2a24';
$content_font_color = $host_node->field_e_content_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_content_font_color[LANGUAGE_NONE][0]['rgb'] : '#000';
$program_title_font_color = $host_node->field_e_program_title_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_program_title_color[LANGUAGE_NONE][0]['rgb'] : '#000';

drupal_add_js("jQuery(document).ready(function() { jQuery('.program-schedule-content a').css('color', '".$content_font_color."'); });",'inline');
?>


<div class="program-sub-title" style="color: <?php print $program_title_font_color;?>; background: <?php print $heading_background_color; ?>"><?php echo t('Programme Schedule'); ?></div>
<div class="row">
  <?php $output_left = '';
  $output_right = '';
  ?>
<?php foreach ($rows as $index => $row): ?>
<!--<div class="col-md-6">-->
  <?php
  $media = '';
     $media = $row['field_daywise_event'].'--'.$row['field_story_expert_name'].'--'.$row['field_start_time_1'].'--'.$row['field_start_time_2'];
     $sponsors_data = itg_event_backend_get_session_sponsor($media);
     $sponsor_all_data = "";
     $sponsor_tags = "";
      if(!empty($sponsors_data)) {
         $sponsor_all_data = node_load($sponsors_data['sponsor']);
     }
    
     if($sponsor_all_data->field_sponser_logo[LANGUAGE_NONE][0]['uri'] != "") {
         $sponsor_img = '<img src=' . image_style_url("sponsor85___33", $sponsor_all_data->field_sponser_logo[LANGUAGE_NONE][0]['uri']) . ' alt="" />';
         $sponsor_tags = '<div class="program-sch-sponcor"><div class="div-sponcor"><span>'.t("Powered By").'</span>'.l($sponsor_img,$baseurl.'sponsor-details',  array('attributes' => array('target' => '_blank'),'query' => array('sponsor' => $sponsor_all_data->nid), 'html' => true)).'</div></div>';
     }
     
     $row_count = count($rows);
    if ($index <= ((round($row_count / 2)) - 1)) {
    $output_left .= $sponsor_tags.'<div class="content-list" style="background:'.$heading_background_color.'">';
    $output_left .= '<div style="color:'.$content_font_color .'">'.$row['field_start_time'].'</div>';
    $output_left .= '<div class="story-expert-name" style="color:'.$font_color.'">'.$row['field_story_expert_name'].'</div>';
    $output_left .= '<div class="program-schedule-content" style="color:'.$content_font_color.'">'.$row['view'].'</div></div>';
    }else{
    $output_right .= $sponsor_tags.'<div class="content-list" style="background:'.$heading_background_color.'">';
    $output_right .= '<div style="color:'.$content_font_color .'">'.$row['field_start_time'].'</div>';
    $output_right .= '<div class="story-expert-name" style="color:'.$font_color.'">'.$row['field_story_expert_name'].'</div>';
    $output_right .= '<div class="program-schedule-content" style="color:'.$content_font_color.'">'.$row['view'].'</div></div>';
    }
    ?>
<!--  </div>  -->
<?php endforeach; ?>
<?php
if(!empty($output_left)){
  print '<div class ="left-side-event-content col-md-6">'.$output_left.'</div>';
}
if(!empty($output_right)){
  print '<div class ="right-side-event-content col-md-6">'.$output_right.'</div>';
}
?>
</div>