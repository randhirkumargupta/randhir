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
<div class="anchor-landing autohorsectonpage">
  <?php
     if(isset($anchor['field_celebrity_pro_occupation']) && strtolower($anchor['field_celebrity_pro_occupation']) == 'anchor'):?>
      <div class="anchor-video-wrapper clearfix mb-20">
        <div id="anc-placeholder" style="display:none"></div>
   
        <script src="https://smedia2.intoday.in/aajtak/at_2.21.06.18/resources/chat/custom.js"></script>
        <script>
        window.lib = lib || {};
        lib.setup({
                'site':'IT',
                'playerPlacement':'jwplayerRef',
                'commentPlacement':'commentRef',
                'anchorId':<?php print $nid; ?>
        });
        </script>
        <div class="anchors-col">
          <div id="anchors_container" class="anchors-container">
            <div id="anchor_title"></div>
            <div id="jwplayerRef"></div>
          </div>
        </div>
        <div id="commentRef" class="comment-col"></div>
      </div>

  <?php  endif; ?>
  <div class="anchor">
    <div class="anchor-left">
      <?php
      if(isset($anchor['field_story_extra_large_image'])) {
        echo '<div class="reporter-image-responsive-css">'.$anchor['field_story_extra_large_image'].'</div>';
         if(isset($anchor['field_celebrity_pro_occupation']) && strtolower($anchor['field_celebrity_pro_occupation']) == 'people'){
          echo '<div class="people-img-title">'.$anchor['title'].'</div>';
        }
        preg_match('/(src=["\'](.*?)["\'])/', $anchor['field_story_extra_large_image'], $match);  //find src="X" or src='X'
        $split = preg_split('/["\']/', $match[0]); // split by quotes
        $src = $split[1]; // X between quotes
      }
      else {
        ?>
      <img width="370" height="208" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');?>" alt="" title=""/>
         <?php if(isset($anchor['field_celebrity_pro_occupation']) && strtolower($anchor['field_celebrity_pro_occupation']) == 'people'){echo $anchor['title'];}?>
      <?php } ?>
    </div>
    <div class="anchor-right" >

      <?php  if (isset($anchor['field_celebrity_pro_occupation']) && !empty($anchor['field_celebrity_pro_occupation']) && strtolower($anchor['field_celebrity_pro_occupation']) == 'people') : ?>

          <div class="full-content">
            <?php echo $anchor['body']; ?>
          </div>
      <?php else: ?>
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
                  <a class="user-activity def-cur-pointer" rel="<?php print $anchor['nid']; ?>" data-tag="anchor-listing" data-activity="twitter_share" data-status="1" title="share on twitter" onclick="twitter_popup('<?php print urlencode($fb_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i><?php print (strtolower($anchor['field_celebrity_pro_occupation']) == 'reporter')?'':t('Twitter'); ?></a>
              </li>
              <li>
                <a class="def-cur-pointer" title="share on facebook" onclick='fbpop("<?php print $actual_link; ?>", "<?php print urlencode($fb_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $src; ?>")'><i class="fa fa-facebook"></i><?php print (strtolower($anchor['field_celebrity_pro_occupation']) == 'reporter')?'':t('Facebook'); ?></a>
              </li>
          </ul>
        </div>
      <?php endif;?>
    </div>
  </div>
</div>
<style type="text/css">
.node-type-reporter.section-author h1{display: none;}
.node-type-reporter.section-author .container>a:after{content: '/';padding: 0 3px;text-decoration: none;}
.node-type-reporter.section-author .social-icon ul{margin-top:10px;}
.node-type-reporter.section-author .social-icon ul li{border:0; background:none;}
.node-type-reporter.section-author .social-icon ul li:first-child{visibility:hidden; width:1px;}
.node-type-reporter.section-author .social-icon ul li a{letter-spacing:-9999px; margin-right:18px;}
.node-type-reporter.section-author .social-icon ul li a::first-letter{display:none;}
.node-type-reporter.section-author .social-icon ul li a{text-indent:-9999;}
.node-type-reporter.section-author ul.author-story-wrapper{list-style:none; padding:0; margin:30px 0 0 0;}
.node-type-reporter.section-author ul.author-story-wrapper li{margin-bottom:30px;}
.node-type-reporter.section-author ul.author-story-wrapper li:first-child{padding-left:0;}
.node-type-reporter.section-author ul.author-story-wrapper li span{display: block;font-size: 12px; color: #b1b1b1;padding: 8px 0 5px;}
.node-type-reporter.section-author ul.author-story-wrapper li a{color:##494949; font:400 15px/20px "OpenSans-Regular";}

.node-type-reporter.section-people h1{display: none;}
.node-type-reporter.section-people .container>a:after{content: '/';padding: 0 3px;text-decoration: none;}
.node-type-reporter.section-people .anchor{box-shadow:none !important; margin-bottom:40px;}
.node-type-reporter.section-people .anchor-left{position:relative;}
.node-type-reporter.section-people .people-img-title{position: absolute;bottom: 0;background: #000;width: 100%;color: #fff;font-size: 15px;line-height: 20px;padding: 3px 8px;
box-sizing: border-box;}
.node-type-reporter.section-people .people-img-title a{color: #fff;font-size: 17px;font-weight: bold;}
.node-type-reporter.section-people .people-story-wrapper{}
.node-type-reporter.section-people .main-story-wrapper,.node-type-reporter.section-people .main-video-wrapper,.node-type-reporter.section-people .main-photo-wrapper{float:left; width:100%; margin-bottom:30px;}
.node-type-reporter.section-people .main-story-wrapper ul,.node-type-reporter.section-people .main-video-wrapper ul,.node-type-reporter.section-people .main-photo-wrapper ul{list-style:none; padding:0; margin:0}
.node-type-reporter.section-people .main-story-wrapper h3{color: #9c9c9c;margin-bottom: 10px;}
.node-type-reporter.section-people .main-story-wrapper ul{background-color: #f7f7f7;display: inline-block;width: 100%; padding:10px 0;}
.node-type-reporter.section-people .main-story-wrapper ul li figure{float:left; margin-right:10px;}
.node-type-reporter.section-people .main-story-wrapper ul li .tile{border-bottom: 1px dotted #4a4a4a;display: inline-block;width: 100%;padding-bottom: 10px;margin-bottom: 10px;}

.node-type-reporter.section-people .main-video-wrapper h3,.node-type-reporter.section-people .main-photo-wrapper h3{color: #bc0a0a;margin-bottom: 10px; position:relative;}
.node-type-reporter.section-people .main-video-wrapper h3:before,.node-type-reporter.section-people .main-photo-wrapper h3:before{content: '';position: absolute;left: 0;width: 100%;bottom:9px;height: 5px;margin-top: -2px;background: #ddd;}
.node-type-reporter.section-people .main-video-wrapper h3 span,.node-type-reporter.section-people .main-photo-wrapper h3 span{padding: 20px 10px 2px 0px;background: #fff;position: relative;z-index: 1;}

.node-type-reporter.section-people .main-video-wrapper ul li .title,.node-type-reporter.section-people .main-photo-wrapper ul li .title{margin-bottom:30px;}
.node-type-reporter.section-people .main-video-wrapper ul li .title figure,.node-type-reporter.section-people .main-photo-wrapper ul li .title figure{position:relative; margin-bottom:7px;}
.node-type-reporter.section-people .main-video-wrapper ul li .title figcaption,.node-type-reporter.section-people .main-photo-wrapper ul li .title figcaption{position: absolute;bottom: 0;background: rgba(0,0,0,0.6);color: #fff;padding: 0 5px;font-size: 12px;}
.node-type-reporter.section-people .main-video-wrapper ul li .title figcaption i,.node-type-reporter.section-people .main-photo-wrapper ul li .title figcaption i{margin-right: 5px;font-size: 15px;line-height: 20px;}
.node-type-reporter.section-people .main-video-wrapper .posted-on,.node-type-reporter.section-people .main-photo-wrapper .posted-on{color:#b1b1b1; font-size:12px;}

@media screen and (max-width:900px){
	.node-type-reporter.section-author .tile{float:left; width:100%; margin-bottom:20px;}
	.node-type-reporter.section-author .tile figure{float:left; margin-right:20px;}
	.node-type-reporter.section-author ul.author-story-wrapper li:first-child{padding-left:15px}
	.node-type-reporter.section-author ul.author-story-wrapper li{margin-bottom: 30px;width: 25%;float: left;height: auto; overflow-y:inherit;}	
}
@media screen and (max-width:767px){
	.node-type-reporter.section-author ul.author-story-wrapper li{margin-bottom: 30px;width: 50%;float: left;height: 193px;overflow-y: hidden;}	
}
@media screen and (max-width:680px){
	.node-type-reporter.section-author ul.author-story-wrapper li{margin-bottom: 30px;width: 33%;float: left;height: 193px;overflow-y: hidden;}	
}
@media screen and (max-width:480px){
	.node-type-reporter.section-author ul.author-story-wrapper li{margin-bottom: 30px;width: 50%;float: left;height: 193px;overflow-y: hidden;}	
}

</style>
