<?php
global $base_url, $user;
$anchor = $rows[0];
$nid = $anchor['nid'];
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
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
        <img width="370" height="208" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image370x208.jpg" alt=""/>
      <?php } ?>
    </div>
    <div class="anchor-right" >
      <?php echo $anchor['title']; ?>
      <div class="less-content">
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
          <li>
            <a class="user-activity def-cur-pointer" rel="<?php print $anchor['nid']; ?>" data-tag="anchor-listing" data-activity="twitter_share" data-status="1" title="share on twitter" onclick="twitter_popup('<?php print urlencode($fb_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>
          </li>
          <li>
            <a class="def-cur-pointer" title="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $src; ?>')"><i class="fa fa-facebook"></i></a>
          </li>
        </ul>
      </div>
      <div class="follow-social">
          <?php $user->uid  = 615; if ($user->uid > 0) {
            $follow_status = itg_get_front_activity_info($nid, '', $user->uid, 'follow_anchor', '');
    
           if (!empty($follow_status['nid']) && $follow_status['status'] == '1') { ?>  
              <li class="mhide follow-anchor"><a title = "Unfollow Anchor" href="javascript:" id="user-activity" data-rel="<?php print $nid; ?>" data-tag="follow_anchor" data-activity="follow_anchor" data-status="0" class="def-cur-pointer">Unfollow Anchor</a></li>
            <?php } else { ?>
              <li class="mhide follow-anchor"><a title = "Follow the Anchor" href="javascript:" id="user-activity" data-rel="<?php print $nid; ?>" data-tag="follow_anchor" data-activity="follow_anchor" data-status="1" class="def-cur-pointer">Follow the Anchor</a></li>
          <?php          }
          } else {
          ?>
              <li class="mhide">
                <a title="follow anchor" href="http://<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri;?>">
                  <?php print t('follow anchor'); ?>
                </a>
              </li>
          <?php } ?>

      </div>
    </div>
  </div>
</div>