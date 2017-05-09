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
if (preg_match('/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i', $useragent) || preg_match('/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i', substr($useragent, 0, 4)))
{
$current_device = 'Web Mobile';
}
else
{
$current_device = 'Web';
}
if(function_exists('itg_live_tv_company')) {
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
                      <?php
                         if (filter_var($live_tv_get_details, FILTER_VALIDATE_URL))
                         {
                           ?>
                        <iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="<?php print $live_tv_get_details; ?>">
                        </iframe>
                           <?php
                         } else {
                         ?>
                         <?php
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
                <span class="light-off-text">Light off</span>
                <span class="light-on-text">Light on</span>
              </a>
            </li>         
        </ul>
    </div>
</div>
<?php
  $current_time_program_tid ='';
  if(function_exists('itg_live_tv_page_video_category')) {
    $current_time_program_tid = itg_live_tv_page_video_category();
  }?>
<div class="latest-livetv-video"><h4><?php print t('Latest Videos'); ?></h4><?php print views_embed_view('programme_content_live_tv', 'block_1', $current_time_program_tid); ?></div>
