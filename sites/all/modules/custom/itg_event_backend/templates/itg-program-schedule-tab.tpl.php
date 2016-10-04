<?php

/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
ksort($data);
foreach ($data as $key => $value) {
  $tabs .= '<li data-tag="'. $key .'" class="' . $key . '">' . $key . '</li>';
}
foreach ($data as $key => $value) {
  $output .= '<div class="' . $key . ' event-listing common-class"><div class="side-right">';
  $session_result = '';
  foreach ($value as $program) {
    $media = $program["daywise"].'--'.$program["session_title"].'--'.$program["start_time"].'--'.$program["end_time"];
    $session_result = itg_event_backend_get_session_photo_video($media);
    foreach($session_result['photo'] as $session){
      if(!empty($session)){
        $output_photo = l('<i class="fa fa-camera"></i> '.t('Session Photo'), 'node/'.$session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
      }
    }
    foreach($session_result['video'] as $session){
      if(!empty($session)){
        $output_video = l('<i class="fa fa-video-camera"></i> '.t('Session Video'), 'node/'.$session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
      }
    }
    foreach($session_result['audio'] as $session){
      if(!empty($session)){
        $output_audio = l('<i class="fa fa-headphones"></i> '.t('Session Audio'), 'node/'.$session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
      }
    }
   // $output .= '<div class="daywise">' . $program["daywise"] . '</div>';
   
    $output .= '<div class="title">' . $program["session_title"] . '</div>';
    $output_time = '<div class="side-left"><div class="time">' . $program["start_time"] . ' to ' . $program["end_time"] . '</div></div>';
    
    $output .= '<div class="listing-detail"><div class="section-part">'.$output_photo .' '.$output_video.' '.$output_audio.'</div>';
    
    foreach ($program['speaker'] as $speaker) {
      $spk_detail = itg_event_backend_get_speaker_details($speaker['target_id']);
      $output .= '<div class="profile-detail"><label>Speaker:</label>';
      $spk_title = '<div class="speaker-title">' . l(t($spk_detail[0]->title), "node/".$spk_detail[0]->nid, array("attributes" => array("target" => "_blank"))) . '</div>';
      $img = '<img src=' . image_style_url("event_speaker_program_72x72", $spk_detail[0]->uri).'/>';
      $output .= '<div class="speaker-image">'.l($img ,"node/".$spk_detail[0]->nid, array("attributes" => array("target" => "_blank"), "html" => TRUE)).'</div>';
      $output .= '<div class="speaker-designation">'. $spk_title . $spk_detail[0]->field_story_new_title_value.'</div></div>';
    }
    $output .='</div>'; 
  }
  $output .= '</div>';
  $output .= $output_time . '</div>';
}
?>
<h2>Session wise coverage</h2>
<div class="program-sub-title">Program Schedule</div>
<?php
print '<div class="top-tab"><ul>'.$tabs.'</ul></div>';
print $output;
?>
<script>
jQuery(document).ready(function(){
    jQuery('.top-tab li').eq(0).addClass('active');
    jQuery('.top-tab li').click(function(){        
        jQuery('.top-tab li').removeClass('active');
        jQuery(this).addClass('active');        
        jQuery('.common-class').hide();
        var getVal = jQuery(this).attr('data-tag');        
        jQuery('.'+getVal).show();
    });
    
    jQuery('.view-event-photo-slider ul').slick({
        infinite: true,    
        autoplay:true,
        dots: false,
        prevArrow: false,
        nextArrow: false
    });
});
</script>