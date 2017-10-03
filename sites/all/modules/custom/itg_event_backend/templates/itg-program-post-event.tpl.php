<?php
/**
 * @file
 * Theme implementation for poll form in tab display. 
 */
global $base_url;
$arg = arg();

if (!empty($arg[1]) && is_numeric($arg[1]) && $arg[0] == 'node') {
  $host_node = node_load($arg[1]);
}

$current_date = strtotime(date('Y-m-d  H:i:s'));
if (!empty($host_node) && ($host_node->type == 'event_backend')) {
  $event_start_date = strtotime($host_node->field_event_start_date[LANGUAGE_NONE][0]['value']);
  $event_close_date = strtotime($host_node->field_event_close_date[LANGUAGE_NONE][0]['value']);

  // Css variables
  $heading_background_color = $host_node->field_e_heading_bck_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_heading_bck_color[LANGUAGE_NONE][0]['rgb'] : '#eee';
  $font_color = $host_node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] : '#ef2a24';
  $content_font_color = $host_node->field_e_content_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_content_font_color[LANGUAGE_NONE][0]['rgb'] : '#000';
  $program_title_font_color = $host_node->field_e_program_title_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_program_title_color[LANGUAGE_NONE][0]['rgb'] : '#000';
  $tab_highlighted_color = $host_node->field_e_tab_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_tab_color[LANGUAGE_NONE][0]['rgb'] : '#eee';

  if (!empty($data)) {
    ksort($data);
    $count = 0;
    foreach ($data as $key => $value) {
      $val = array_shift(array_slice($value, 0, 1));
      $event_final_date = '';
      $event_day_date = $val['daywise'];
      $event_day_dat = explode(':', $event_day_date);
      $event_date_timestamp = strtotime($event_day_dat[1]);
      $event_final_date = date('D M d, Y', $event_date_timestamp);
      $word_key = itg_event_backend_convert_number_to_words($key);
      $tabs .= '<li data-tag="Day-' . $key . '" class="event-program-tabs Day-' . $key . '"><span style="background: ' . $tab_highlighted_color . '">Day ' . t(ucfirst($word_key)) . '</span><i class="date"> ' . $event_final_date . '</i></li>';

      $count++;
    }

    print '<div class="top-tab"><ul>' . $tabs . '</ul></div>';
    foreach ($data as $key => $value) {
      ?>
      <div class="<?php print 'Day-' . $key; ?> event-listing common-class">
          <?php
          $session_result = '';

          foreach ($value as $program) {
            $media = $program["daywise"] . '--' . $program["session_title"] . '--' . $program["start_time"] . '--' . $program["end_time"];
            $session_result = itg_event_backend_get_session_photo_video($media);
            $story_title = itg_event_backend_get_session_story_title($media, $content_font_color);
            $output_story_title = '';

            foreach ($story_title['story_title'] as $title) {
              if (!empty($title)) {
                $output_story_title = '<p style = color:' . $font_color . '>' . $title . '</p>';
              }
            }
            // story body
            $output_story_img = '';
            $output_story_kicker = '';
            foreach ($story_title['story_details'] as $detail) {
              if (!empty($detail['uri'])) {
                $story_img = theme('image_style', array(
                  'style_name' => 'event_post_364x205',
                  'path' => $detail['uri'],
                    )
                );
              }
              else {
                $story_img = "<img width='364' height='205'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/event_post_default.jpg' alt='' />";
              }
              if (!empty($detail['nid'])) {
                $output_story_img = l($story_img, 'node/' . $detail['nid'], array('html' => TRUE));
              }
              else {
                $output_story_img = $story_img;
              }

              $output_story_kicker = '';
              if (!empty($detail['kicker'])) {
                $output_story_kicker = $detail['kicker'];
              }
            }

            $output_media = '';
            $max = max(array(count($session_result['photo']), count($session_result['video']), count($session_result['audio'])));
            for ($i = 0; $i < $max; $i++) {
              if (!empty($session_result['photo'][$i])) {
                $output_media .= l('<i class="fa fa-camera"></i> ' . t('Session Photo'), $base_url . '/' . drupal_get_path_alias('node/' . $session_result['photo'][$i]), array("attributes" => array("target" => "_blank", "style" => "color: $font_color"), 'html' => TRUE));
              }
              if (!empty($session_result['video'][$i])) {
                $output_media .= l('<i class="fa fa-video-camera"></i> ' . t('Session Video'), $base_url . '/' . drupal_get_path_alias('node/' . $session_result['video'][$i]), array("attributes" => array("target" => "_blank", "style" => "color: $font_color"), 'html' => TRUE));
              }
              if (!empty($session_result['audio'][$i])) {
                $output_media .= l('<i class="fa fa-headphones"></i> ' . t('Session Audio'), $base_url . '/' . drupal_get_path_alias('node/' . $session_result['audio'][$i]), array("attributes" => array("target" => "_blank", "style" => "color: $font_color"), 'html' => TRUE));
              }
              $output_media .= '<br>';
            }
            if (empty($output_story_img)) {
              $story_img = "<img width='364' height='205'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/event_post_default.jpg' alt='' />";
              $output_story_img = $story_img;
            }
             if (!empty($session_result) ||  !empty($output_story_title)) {
            ?>
            <div class="content-detail">
                <div class="side-left"><?php print $output_story_img; ?></div>
                <div class="side-right"><p class="small-title"><?php print $program["session_title"]; ?></p><div class="title"><?php print $output_story_title; ?></div> 
                    <div class="listing-detail"><div class="section-part"><?php print $output_story_kicker . ' <div class="bottom-links">' . $output_media . '</div>'; ?></div>

                    </div>
                </div>              
            </div>
            <?php
          }
           }
          print '</div>';
        }
      }
    }
    ?>