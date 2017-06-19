<?php
/**
 * @file
 * Theme implementation for Live TV Video page.
 * 
 */
$share_title = 'India Today Live TV';
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$useragent = $_SERVER['HTTP_USER_AGENT'];
$current_device = 'Web';
if (function_exists('mobile_user_agent_switch')) {
  $flag = mobile_user_agent_switch();
  if ($flag) {
    $current_device = 'Web Mobile';
  }
}
if (function_exists('itg_live_tv_company')) {
  $device = itg_live_tv_company($current_device);
  $live_tv_get_details = itg_get_live_tv_code($device[0]);
}
?>
<div class="program-livetv">
    <div class="live_tv_video">
        <?php print $data; ?>
    </div>
    <div class="social-icon">
        <ul>
            <li><a class="def-cur-pointer" title="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
            <li><a class="def-cur-pointer" title="share on twitter" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span>Tweet</span></a></li>
            <li class="show-embed-code-link"><a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i> <span>Embed</span></a>
                <div class="show-embed-code-div">
                    <div class="copy-sample-code">
                        <textarea readonly>
                            <?php if (filter_var($live_tv_get_details, FILTER_VALIDATE_URL)) { 
                              if (is_bool(is_youtube_url($live_tv_get_details))) {
                                  echo '<iframe frameborder="0" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="' . $live_tv_get_details . '"></iframe>';
                                }
                                elseif (is_string(is_youtube_url($live_tv_get_details))) {
                                  echo '<iframe frameborder="0" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="https://www.youtube.com/embed/' . is_youtube_url($live_tv_get_details) . '"></iframe>';
                                }
                            }
                            else {
                              print $live_tv_get_details;
                            }
                            ?>
                        </textarea>  
                    </div>
                </div>
            </li>
            <li class="light-off-on-tab light-on-active">
                <a href="javascript:;">
                    <i class="fa fa-lightbulb-o"></i> 
                    <span class="light-off-text"><?php print t('Light off'); ?></span>
                    <span class="light-on-text"><?php print t('Light on'); ?></span>
                </a>
            </li>         
        </ul>
    </div>
</div>
<?php
$current_time_program_tid = '';
if (function_exists('itg_live_tv_page_video_category')) {
  $current_time_program_tid = itg_live_tv_page_video_category();
}
?>
<div class="latest-livetv-video"><h4><?php print t('Latest Videos'); ?></h4><?php print views_embed_view('programme_content_live_tv', 'block_1', $current_time_program_tid); ?></div>
