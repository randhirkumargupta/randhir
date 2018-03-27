<?php
//global $base_url;
$host_node = itg_event_backend_get_event_node('node');
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
  $key = 1;
  ?>
<?php foreach ($rows as $index => $row): ?>
  <?php
    $daywise_arr = explode(':',$row['field_daywise_event']);
    $daywise[] = $daywise_arr[0];

  $media = '';
     $media = $row['field_daywise_event'].'--'.$row['field_story_expert_name'].'--'.$row['field_start_time_1'].'--'.$row['field_start_time_2'];
     $sponsors_data = itg_event_backend_get_session_sponsor($media, $host_node->nid);
     $sponsor_all_data = "";
     $sponsor_tags = "";
      if(!empty($sponsors_data)) {
         $sponsor_all_data = itg_event_backend_sponsor_details($sponsors_data['sponsor']);
     }
     if($sponsor_all_data[0]->uri != "") {
         $sponsor_img = '<img src=' . image_style_url("sponsor85___33", $sponsor_all_data[0]->uri) . ' alt="" title= "'.$sponsor_all_data[0]->title.'" />';
         $sponsor_tags = '<div class="program-sch-sponcor"><div class="div-sponcor"><span>'.t("Powered By").'</span>'.l($sponsor_img,$baseurl.'sponsor-details',  array('attributes' => array('target' => '_blank'),'query' => array('sponsor' => $sponsor_all_data[0]->nid), 'html' => true)).'</div></div>';
     }

    $daywise_style = ($daywise_arr[0] == 'Day-1') ? 'style="display: block"' : '';
    $output_left .= '<div '.$daywise_style.' class="'.$daywise_arr[0].' common-class  col-lg-12 col-md-12 col-sm-12">';
    $output_left .= $sponsor_tags .'<div class="content-list" style="background:'.$heading_background_color.'">';
    $output_left .= '<div style="color:'.$content_font_color .'"><span class="date-display-single"><div class="date-display-range">'.$row['field_start_time_1'].' to '.$row['field_start_time_2'].'</div></span></div>';
    $output_left .= '<div class="story-expert-name" style="color:'.$font_color.'">'.$row['field_story_expert_name'].'</div>';
    $output_left .= '<div class="program-schedule-content" style="color:'.$content_font_color.'">'.$row['view'].'</div></div></div>';

    $key ++;

    ?>
<?php endforeach; ?>
<?php
  $daywise = array_unique($daywise);
  foreach ($daywise as $key => $value) {
    $tabs .= '<li style="background: ' . $tab_highlighted_color . '" data-tag="' . $value . '" class="event-program-tabs ' . $value . '">' . $value . '</li>';
  }
  if(count($daywise) > 1){
		print '<div class="top-tab col-lg-12 col-md-12 col-sm-12"><ul>' . $tabs . '</ul></div>';
	}  
  print '<div class ="left-side-event-contents col-lg-12 col-md-12 col-sm-12">'.$output_left.'</div>';

?>
</div>

<?php
drupal_add_js("jQuery(document).ready(function(){
    jQuery('.top-tab li').eq(0).addClass('active');
    jQuery('.top-tab li').click(function(){        
        jQuery('.top-tab li').removeClass('active');
        jQuery(this).addClass('active');        
        jQuery('.common-class').hide();
        var getVal = jQuery(this).attr('data-tag');        
        jQuery('.'+getVal).show();
    });
    
});", array('type' => 'inline', 'scope' => 'footer'));
?>
