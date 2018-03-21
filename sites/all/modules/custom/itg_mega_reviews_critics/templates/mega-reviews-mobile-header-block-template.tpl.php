<?php
global $user, $base_url;
$node = $data['node'];
$nid = $node->nid;   
$actual_link = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
$short_url = $actual_link;
$fb_title = addslashes($node->title);
$share_desc = '';
$image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
if (function_exists('itg_story_global_comment_last_record')) {      
    $last_record = itg_story_global_comment_last_record();
    $config_name = trim($last_record[0]->config_name);
}
?>
<!--    mobile social share -->
<div class="comment-mobile desktop-hide">
    <ul>
        <li class="mail-to-author"><a title ="Mail to author" href="mailto:support@indiatoday.in"><i class="fa fa-envelope"></i> <?php print t('Mail to author'); ?></a></li>
         <?php 
            $whatsapp = $node->title . " ". $actual_link;
            $whatsapp_text = urlencode($whatsapp); 
          ?>          
          <li><a href="whatsapp://send?text=<?php print $whatsapp_text; ?>" data-text="<?php print $node->title; ?>" data-href="<?php print $actual_link; ?>"><i class="fa fa-whatsapp"></i></a></li>
        <?php
        if ($config_name == 'vukkul') {
            ?>
            <li><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-comments');" title="comment"><i class="fa fa-comment"></i></a></li>
        <?php } if ($config_name == 'other') { ?> 
            <li><a class="def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
        <?php } ?>
        <li><a href="#" title ="share" class="share-icon"><i class="fa fa-share-alt"></i></a>
    </ul>
    <ul class="social-share">
        <li><a title = "share on facebook" class="def-cur-pointer" onclick='fbpop("<?php print $actual_link; ?>", "<?php print urlencode($fb_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $image; ?>", "<?php print $base_url; ?>", "<?php print $nid; ?>")'><i class="fa fa-facebook"></i></a></li>
        <li><a title = "share on twitter" class="user-activity def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:" onclick='twitter_popup("<?php print urlencode($node->title); ?>", "<?php print urlencode($short_url); ?>")'><i class="fa fa-twitter"></i></a></li>
        <li><a title="share on google+" class="user-activity def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="#" onclick='return googleplusbtn("<?php print $actual_link; ?>")'><i class="fa fa-google-plus"></i></a></li>

    </ul> 
</div>
