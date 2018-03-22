<?php
global $base_url;
$anchor = $rows[0];
$nid = $anchor['nid'];
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = $actual_link;
$fb_title = itg_common_only_text_string($anchor['title']);
$src = '';
// prepare url for sharing
$uri = base64_encode($actual_link);
//get follow anchor status
$follow_status = $content["follow_status"];
?>
<div class="anchor-landing">
  <div class="anchor">
    <div class="anchor-left">
      <?php
      if (isset($anchor['field_story_extra_large_image'])) {
        echo $anchor['field_story_extra_large_image'];
        preg_match('/(src=["\'](.*?)["\'])/', $anchor['field_story_extra_large_image'], $match);  //find src="X" or src='X'
        $split = preg_split('/["\']/', $match[0]); // split by quotes
        $src = $split[1]; // X between quotes
      }
      else {
        ?>
      <img width="370" height="208" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');?>" alt="" title=""/>
      <?php } ?>
    </div>
    <div class="anchor-right" >
      <?php echo $anchor['title']; ?>
      <div class="less-content">
          <!-------  followers count -->
        <?php
        if (function_exists('itg_get_followers')) {
          $followers = itg_get_followers($nid);
          if(!empty($followers)) {
            print "<span class='followers-link'>" . $followers . " followers</span>";
          }
        }
        ?>
          <!-------  followers count -->
        <?php 
          echo mb_strimwidth(html_entity_decode(strip_tags($anchor['body'])), 0, 245, ".."); 
          $share_desc = '';
        ?>
        <?php if (strlen($anchor['body']) > 245) { ?>
          <a href="javascript:void(0)" class="anchor-action read-more"> More[+]</a>
        </div>
        <div class="full-content" style="display: none">
          <?php echo $anchor['body']; ?>
          <a href="#" class="anchor-action read-less"> Less[-]</a>
        <?php } ?>
      </div>  
      <div class="social-icon">
        <ul>
              <?php if (function_exists('itg_follow_unfollow_print')) {
                print itg_follow_unfollow_print($nid);
              }
              ?>
            <li>
                <a class="user-activity def-cur-pointer" rel="<?php print $anchor['nid']; ?>" data-tag="anchor-listing" data-activity="twitter_share" data-status="1" title="share on twitter" onclick="twitter_popup('<?php print urlencode($fb_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i><?php print t('Twitter'); ?></a>
            </li>
          <li>
              <a class="def-cur-pointer" title="share on facebook" onclick='fbpop("<?php print $actual_link; ?>", "<?php print urlencode($fb_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $src; ?>")'><i class="fa fa-facebook"></i><?php print t('Facebook'); ?></a>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>
