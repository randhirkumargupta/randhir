<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
global $base_url;
$share_page_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($share_page_link, 'goo.gl');
$share_desc = '';
$share_image = '';
?>

<div class="live-block">

    <?php
    if (!empty($content)):
      $type = $node->field_type['und']['0']['value'];
      if ($type == 'Live Blog' || $type == 'Breaking News') {
        if (!empty($node->field_constituancy[LANGUAGE_NONE][0]['value'])) {
          $title = '<h1><span>' . $node->field_constituancy[LANGUAGE_NONE][0]['value'] . '</span>: ' . $node->title . '</h1>';
        }
        else {
          $title = '<h1><span>' . $type . '</span>: ' . $node->title . '</h1>';
        }

        $share_title = $node->title;
        ?>
        <!--<h1><?php if ($type == 'Breaking News') { ?><span><?php print ($type) ?></span>: <?php } print ($title) ?></h1>-->
        <?php print ($title) ?>
        <p class="short-discription"> <?php print ($node->field_common_short_description[LANGUAGE_NONE][0]['value']) ?></p>
        <div class="social-share">
            <ul>
                <li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li>
                <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop('<?php print $share_page_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $share_image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on twitter" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" class="user-activity twitter def-cur-pointer" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li><a title="share on google+" class="user-activity google def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $share_page_link; ?>')"></a></li>

            </ul>
        </div>

        <?php
        if ($type == 'Live Blog') {
          $useragent = $_SERVER['HTTP_USER_AGENT'];
          if (function_exists(itg_live_tv_company)) {
            if (!empty($node->field_story_expires['und']['0']['value']) && $node->field_story_expires['und']['0']['value'] == 'Yes') {
              ?>
              <div class="iframe-video">
              <?php
              $current_device = 'Web';
              if (function_exists('mobile_user_agent_switch')) {
                $flag = mobile_user_agent_switch();
                if ($flag) {
                  $current_device = 'Web Mobile';
                }
              }
              $device = itg_live_tv_company($current_device);
              if (!empty($device[0])) {
                $live_tv_get_details = node_load($device[0]);
                $live_url = $live_tv_get_details->field_ads_ad_code[LANGUAGE_NONE][0]['value'];
                if (filter_var($live_url, FILTER_VALIDATE_URL)) {
                  ?>

                      <iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="<?php print $live_url; ?>"></iframe>

                      <?php
                    }
                    else {

                      print $live_url;
                    }
                  }
                  ?>
              </div>
                  <?php
                }
              }
              ?>


          <div class="live-hightlight">
          <?php if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                <h3><?php print t('Highlights'); ?></h3>
          <?php } ?>
              <ul>
      <?php
      $h_count = 1;
      foreach ($node->field_story_highlights['und'] as $high) {
        print '<li>' . $high['value'] . '</li>';
        $h_count++;
      }
      ?>

              </ul>
          </div>
                <?php } ?>
        <div class="timeline">
            <h3><?php print t('Timeline'); ?></h3>
            <input id="slider-range" class="irs-hidden-input" readonly="">
    <?php
    if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
      $breaking_output .= '';
      foreach ($node->field_breaking_content_details['und'] as $blog_item) {
        $field_collection_ids[] = $blog_item['value'];
      }
      rsort($field_collection_ids);

      foreach ($field_collection_ids as $breaking_item) {
        $breaking_output .= '<div class="breaking-section">';
        $field_collection_id = $breaking_item;
        $entity = entity_load('field_collection_item', array($field_collection_id));
        $html = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $entity[$field_collection_id]->field_breaking_tile['und'][0]['value']);
        $fb_title = $string = preg_replace('/\s+/', ' ', itg_common_only_text_string($html));
        $pub_time = date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
        $pub_display_time = date("H:i A", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
        $pub_time2 = str_replace(":", "", $pub_time);
        $current_time = str_replace(":", "", date('H:i'));
        if (!empty($entity[$field_collection_id]->field_breaking_redirection_url['und'][0]['value'])) {
          $url = preg_replace('#^https?://#', '', $entity[$field_collection_id]->field_breaking_redirection_url['und'][0]['value']);
          $redirection_url = l($entity[$field_collection_id]->field_breaking_tile['und'][0]['value'], 'http://' . $url, array("attributes" => array("target" => "_blank", "title" => $entity[$field_collection_id]->field_breaking_tile['und'][0]['value']), 'html' => TRUE));
        }
        else {
          $redirection_url = $entity[$field_collection_id]->field_breaking_tile['und'][0]['value'];
        }
        if ($pub_time2 < $current_time) {
          $breaking_output .= '<div class="dwrap" timevalue="' . $pub_time2 . '" tcount="' . count($field_collection_ids) . '"><div class="breaking-date">' . $pub_display_time . ' PDT</div>';
          $breaking_output .= '<div class="breaking-discription">' . $redirection_url . '</div><div class="social-share"><ul><li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li><li><a title="share on facebook" onclick="fbpop(' . "'" . $share_page_link . "'" . ', ' . "'" . $fb_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $share_image . "'" . ')" class="facebook def-cur-pointer"><i class="fa fa-facebook"></i></a></li><li><a title="share on twitter" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="twitter_share" data-status="1" onclick="twitter_popup(' . "'" . urlencode($fb_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')" class="user-activity twitter def-cur-pointer"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="google_share" data-status="1" onclick="return googleplusbtn(' . "'" . $share_page_link . "'" . ')" class="user-activity google def-cur-pointer"></a></li></ul></div>';
          $breaking_output .= '</div></div>';
        }
      }
      $breaking_output .= '<span class="no-record" style="display:none">' . t('No Record Found') . '</span>';
      print $breaking_output;
    }
  }

endif;
?>
    </div>
