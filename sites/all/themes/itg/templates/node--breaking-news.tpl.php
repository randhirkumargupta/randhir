<?php

/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
global $base_url;
$share_page_link = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
$short_url = shorten_url($share_page_link, 'goo.gl');
$share_desc = '';
$share_image = '';
?>
	
<div class="live-block">

<?php

if (!empty($content)):
    $type = $node->field_type['und']['0']['value'];
    if ($type == 'Live Blog' || $type == 'Breaking News') {
      if(!empty($node->field_story_snap_post[LANGUAGE_NONE][0]['value'])) {
        $title = '<h1><span>'.$node->field_story_snap_post[LANGUAGE_NONE][0]['value'].'</span>: '.$node->title.'</h1>';
      } else {
        $title = '<h1><span>'.$type.'</span>: '.$node->title.'</h1>';
      }
        //$title = $node->title;
        //$share_title = $type.':'.$title;
        $share_title = $node->title;
        ?>
    <!--<h1><?php if($type == 'Breaking News') { ?><span><?php print ($type) ?></span>: <?php } print ($title) ?></h1>-->
    <?php print ($title) ?>
    <p class="short-discription"> <?php print ($node->field_label['und']['0']['value'])?></p>
    <div class="social-share">
        <ul>
            <li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li>
            <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop('<?php print $share_page_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $share_image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
            <li><a title="share on twitter" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" class="user-activity twitter def-cur-pointer" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
            <li><a title="share on google+" class="user-activity google def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $share_page_link; ?>')"></a></li>
            
        </ul>
    </div>
     
        <?php
        if ($type == 'Live Blog')
        {
          $useragent = $_SERVER['HTTP_USER_AGENT'];
          if (function_exists(itg_live_tv_company))
          {
            if(!empty($node->field_story_expires['und']['0']['value']) && $node->field_story_expires['und']['0']['value'] == 'Yes') {
            ?>
            <div class="iframe-video">
                <?php
                if (preg_match('/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i', $useragent) || preg_match('/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i', substr($useragent, 0, 4)))
                {
                  $current_device = 'Web Mobile';
                }
                else
                {
                  $current_device = 'Web';
                }
                $device = itg_live_tv_company($current_device);
                if (!empty($device[0]))
                {
                  $live_tv_get_details = node_load($device[0]);
                  $live_url = $live_tv_get_details->field_ads_ad_code[LANGUAGE_NONE][0]['value'];
                  if (filter_var($live_url, FILTER_VALIDATE_URL))
                  {
                    ?>

                    <iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="<?php print $live_url; ?>"></iframe>

                    <?php
                  }
                  else
                  {

                    print $live_url;
                  }
                }
                ?>
            </div>
        <?php
      }
          }
      ?>
      
    <!--<iframe width="100%" height="360" frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="http://livestream.com/accounts/11965022/events/4086327/player?width=640&amp;height=360&amp;autoPlay=true&amp;mute=false"></iframe>-->
    
    <div class="live-hightlight">
              <?php if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                <h3>Highlights</h3>
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
    <h3>Timeline</h3>
    <div id="slider-range"></div>
        <!--<span id="time"></span>-->
   </div>
    <?php
        if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
            $breaking_output.= '';
            foreach ($node->field_breaking_content_details['und'] as $blog_item) {
                $field_collection_ids[] = $blog_item['value'];
            }
            rsort($field_collection_ids);
            
            foreach ($field_collection_ids as $breaking_item) {
                $breaking_output.= '<div class="breaking-section">';
                $field_collection_id = $breaking_item;
                $entity = entity_load('field_collection_item', array($field_collection_id));
                $html = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $entity[$field_collection_id]->field_breaking_tile['und'][0]['value']);
                $fb_title = $string = preg_replace('/\s+/', ' ', itg_common_only_text_string($html));
                $pub_time = date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
                $pub_display_time = date("H:i A", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
                $pub_time2 = str_replace(":","",$pub_time);
                $current_time =  str_replace(":", "", date('H:i'));
                if(!empty($entity[$field_collection_id]->field_breaking_redirection_url['und'][0]['value'])) {
                  $url = preg_replace('#^https?://#', '', $entity[$field_collection_id]->field_breaking_redirection_url['und'][0]['value']);
                  $redirection_url = l($entity[$field_collection_id]->field_breaking_tile['und'][0]['value'], 'http://'.$url, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
                } else {
                  $redirection_url = $entity[$field_collection_id]->field_breaking_tile['und'][0]['value'];
                }
                if($pub_time2 < $current_time) {
                $breaking_output.= '<div class="dwrap" timevalue="'.$pub_time2.'" tcount="'.count($field_collection_ids).'"><div class="breaking-date">' . $pub_display_time . ' PDT</div>';
                $breaking_output.= '<div class="breaking-discription">' . $redirection_url . '</div><div class="social-share"><ul><li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li><li><a title="share on facebook" onclick="fbpop('."'".$share_page_link."'".', '."'".  $fb_title."'".', '."'".  $share_desc."'".', '."'".  $share_image."'".')" class="facebook def-cur-pointer"><i class="fa fa-facebook"></i></a></li><li><a title="share on twitter" rel="'.$node->nid.'" data-tag="'.$node->type.'" data-activity="twitter_share" data-status="1" onclick="twitter_popup('."'".urlencode($fb_title)."'".', '."'".urlencode($short_url)."'".')" class="user-activity twitter def-cur-pointer"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" rel="'.$node->nid.'" data-tag="'.$node->type.'" data-activity="google_share" data-status="1" onclick="return googleplusbtn('."'".$share_page_link."'".')" class="user-activity google def-cur-pointer"></a></li></ul></div>';
                $breaking_output.= '</div></div>';
                }
            }
            $breaking_output .= '<span class="no-record" style="display:none">'.t('No Record Found').'</span>';
            print $breaking_output;
        }
    }
    
endif;
?>
</div>
