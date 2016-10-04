<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
ksort($data);
foreach ($data as $key => $value) {
  $tabs .= '<li data-tag="Day-' . $key . '" class="Day-' . $key . '">Day ' . $key . '</li>';
}
?>
<div class="program-sub-title">Program Schedule</div>
<?php
print '<div class="top-tab"><ul>' . $tabs . '</ul></div>';
foreach ($data as $key => $value) {
  ?>
  <div class="<?php print 'Day-'.$key; ?> event-listing common-class">
    <?php
    $session_result = '';
    foreach ($value as $program) {
      $media = $program["daywise"] . '--' . $program["session_title"] . '--' . $program["start_time"] . '--' . $program["end_time"];
      $session_result = itg_event_backend_get_session_photo_video($media);
      $output_photo = '';
      foreach ($session_result['photo'] as $session) {
        if (!empty($session)) {
          $output_photo = l('<i class="fa fa-camera"></i> ' . t('Session Photo'), 'node/' . $session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
        }
      }
      $output_video = '';
      foreach ($session_result['video'] as $session) {
        if (!empty($session)) {
          $output_video = l('<i class="fa fa-video-camera"></i> ' . t('Session Video'), 'node/' . $session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
        }
      }
      $output_audio = '';
      foreach ($session_result['audio'] as $session) {
        if (!empty($session)) {
          $output_audio = l('<i class="fa fa-headphones"></i> ' . t('Session Audio'), 'node/' . $session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
        }
      }
      ?>
      <div class="side-right"><div class="title"><?php print $program["session_title"]; ?></div> 
        <div class="listing-detail"><div class="section-part"><?php print $output_photo . ' ' . $output_video . ' ' . $output_audio; ?></div>
          <div class="profile-detail">
            <?php
            foreach ($program['speaker'] as $speaker) {
              $spk_detail = itg_event_backend_get_speaker_details($speaker['target_id']);
              print '<div class="profile-loop"><label>Speaker:</label>';
              $spk_title = '<div class="speaker-title">' . l(t($spk_detail[0]->title), "node/" . $spk_detail[0]->nid, array("attributes" => array("target" => "_blank"))) . '</div>';
              $img = '<img src=' . image_style_url("event_speaker_program_72x72", $spk_detail[0]->uri) . '/>';
              print '<div class="speaker-image">' . l($img, "node/" . $spk_detail[0]->nid, array("attributes" => array("target" => "_blank"), "html" => TRUE)) . '</div>';
              print '<div class="speaker-designation">' . $spk_title . $spk_detail[0]->field_story_new_title_value . '</div></div>';
            }
            ?>
          </div></div></div> 
      <div class="side-left"><div class="time"><?php print $program["start_time"] . ' to ' . $program["end_time"]; ?> </div></div>
      <?php
    }
    print '</div>';
  }

  drupal_add_js("jQuery(document).ready(function(){
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
});", array('type' => 'inline', 'scope' => 'footer'));
  ?>
