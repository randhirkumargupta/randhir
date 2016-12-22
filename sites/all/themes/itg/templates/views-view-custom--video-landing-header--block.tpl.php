<?php
// config for sharing
         global $base_url; 
         $nid = check_plain(arg(1)); 
         $video_node = node_load(arg(1));
         $actual_link = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
         $short_url = shorten_url($actual_link, 'goo.gl');
         $fb_title = addslashes($video_node->title);
         $share_desc = '';
         $image = file_create_url($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
?>
<?php foreach ($rows as $row): ?>
  <div class="container">
    <div class ="video-landing-header">
      <div class="row">
        <div class="col-md-12">
          <h2><?php print $row['title']; ?></h2>
        </div>
        <div class="col-md-8 video-header-left">
          <div class="video"><?php
            if (module_exists('itg_videogallery')) {
              $vid = itg_videogallery_get_videoid($row['fid']);
            }
            ?>
            <div class="iframe-video">
              <iframe frameborder="0"
                      src="https://www.dailymotion.com/embed/video/<?php print $vid; ?>?autoplay=0&mute=1&ui-start-screen-info"
                      allowfullscreen></iframe></div></div>
          <div class="social-likes">
            <ul>
              <li><a href="#" title ="Like"><i class="fa fa-heart"></i> <span><?php
              if(function_exists(itg_flag_get_count)) {
              print $like_count = itg_flag_get_count(arg(1), 'like_count');
              }
              ?></span></a></li>
              <li><?php print $row['ops']; ?></li>
              <li><a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link;?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
              <li><a class="def-cur-pointer" title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($video_node->title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span>Twitter</span></a></li>
              <li><a href="mailto:?body=<?php print urlencode($actual_link);?>" title="Email"><i class="fa fa-envelope"></i> <span>Email</span></a></li>
              <li class="mhide"><a href="#" title="Embed"><i class="fa fa-link"></i> <span>Embed</span></a></li>
              <?php
                if (function_exists(global_comment_last_record)) {
                  $last_record = global_comment_last_record();
                  $config_name = trim($last_record[0]->config_name);
                }
                if ($config_name == 'vukkul') {
                  ?>
                <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
                <?php } if ($config_name == 'other') { ?> 
                <li><a href="javascript:void(0)" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
                <?php } ?>
                <?php if($user->uid > 0): ?>
                  <li class="mhide"><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/personalization/my-content/<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                  <?php else: ?>
                  <li class="mhide"><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                  <?php endif; ?>
              <!--<li class="mhide"><a href="#" title="Submit Video"><i class="fa fa-share"></i> <span>Submit Video</span></a></li>-->
            </ul>
          </div>
        </div>
        <div class="col-md-4 video-header-right"><p><?php print $row['field_story_expert_description']; ?></p>
          <p class="upload-date"><?php print $row['timestamp']; ?></p>
           <div class="section-like-dislike">
                                  <div id="btn-div">
                                      <?php
                                      if (function_exists(itg_event_backend_highlights_like_dislike)) {
                                         $val = arg(1);
                                       print itg_event_backend_highlights_like_dislike($val);
                                      }
                                      ?>
                                  </div>
                        
                        </div>
          <div class="ads mhide"></div>
        </div>
      </div>
    </div>
  </div>
<?php endforeach; ?>
