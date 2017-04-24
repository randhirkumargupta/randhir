<?php
/**
 * @file : itg-quiz-form.tpl.php
 */
global $base_url;
$node = $form['node']['#value'];
$from_story = $form['from_story']['#value'];
$byline_node = node_load($node->field_story_reporter[LANGUAGE_NONE][0]['target_id']);

$byline_name = $byline_node->title;
$byline_twitter_handler = $byline_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
//$byline_image = file_create_url($byline_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
$created_date = date('M d, Y', $node->created);
$updated_date = date('h:i', $node->created);

if($form['question_format']['#value'] == 'All questions at a time') {
  $form_class = 'survey-form-wrapper-all';
}
else {
  $form_class = 'survey-form-wrapper-one';
}

$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $node->title);
$fb_share_title= 'Quiz: '.htmlentities($search_title, ENT_QUOTES);    
$short_url = shorten_url($actual_link, 'goo.gl');
$share_desc = '';
$src = '';
$comment_value = variable_get('COMMENT_CONFIG');
$config_name = $comment_value[0]->config_name;
?>
<div class="survey-form-main-container" style="margin:10px 0px 10px 0px;">
  <h1 class="survey-title"><?php echo 'Quiz: '. $node->title; ?></h1>
  <div class="survey-description"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
  <div class="byline">
    <div class="profile-pic">
       <?php
       if (!empty($byline_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
         $byline_uri = file_create_url($byline_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
       ?>
        <img src="<?php echo $byline_uri; ?>" alt="" title=""/>
        <?php
       }
       else {
         $file = 'default_images/user-default.png';
         print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
       }
       ?>
    </div>
    <div class="profile-detail">
      <ul>
        <li class="title" style="line-height: 15px"><?php echo $byline_name; ?></li>
         <?php
          $twitter_handle = str_replace('@', '', $byline_twitter_handler);
          if (!empty($twitter_handle)) {
            ?>
          <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script></li>                
          <?php } ?>
      </ul>
      <ul class="date-update">
        <li><?php echo $created_date; ?> | </li>
        <li>UPDATED <?php echo $updated_date; ?> IST </li>
      </ul>
    </div>
    <div class="social-info">
      <span>
          <a title="share on facebook" class= "facebook def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_share_title; ?>', '<?php print $share_desc; ?>', '<?php print $src; ?>')"><i class="fa fa-facebook" aria-hidden="true"></i></a>
        <!--<dfn>1522</dfn>-->
      </span>
      <span>
          <a title="share on twitter" class= "twitter def-cur-pointer" onclick="twitter_popup('<?php print 'Quiz :'.urlencode($node->title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter" aria-hidden="true"></i></a>
      </span>
      <span>
          <a title="share on google+" class= "google def-cur-pointer" onclick="return googleplusbtn('<?php print $actual_link; ?>')"> <i class="fa fa-google-plus" aria-hidden="true"></i></a>
      </span>
      <span>
          <?php
          if ($config_name == 'vukkul') {
            ?> 
            <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>
          <?php } if ($config_name == 'other') { ?> 
            <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>
          <?php } ?>
     </span>
      
    </div>
  </div>
  
  <!-- Render survey form -->
  <div class="<?php echo $form_class; ?>" style="margin-bottom: 30px">
    <?php print drupal_render_children($form); ?>
  </div>
  
  <?php
  if ($from_story != 'yes') {
    if (function_exists('taboola_view')) {
      taboola_view();
    }
  }
  
  if ($config_name == 'vukkul') {
    ?>
    <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

    </div>
    <?php
  }
  if ($config_name == 'other') {
    ?>
    <div id="other-comment">
        <?php
        $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
        print render($block['content']);
        ?>
    </div>
  <?php } ?>
</div>
