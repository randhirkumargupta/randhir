<?php if (!empty($content)):
   global $base_url;
  ?>
<?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) { 
            $class_buzz = 'buzz-feedback';
        }

        // prepare url for sharing
         $actual_link = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
         $short_url = shorten_url($actual_link, 'goo.gl');
         $fb_title = addslashes($node->title);
         $share_desc = '';
         $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
        ?>
<div class="story-section <?php print $class_buzz;?>">
  <div class='<?php print $classes ?>'>
      <?php //pr($node); ?> 
      <div class="comment-mobile desktop-hide">
          <ul>
              <li><a href="#"><i class="fa fa-envelope"></i> Mail to author</a></li>
              <li><a href="#"><i class="fa fa-whatsapp"></i></a></li>
              <li><a href="#"><i class="fa fa-comment"></i></a></li>
              <li><a href="#"><i class="fa fa-share-alt"></i></a></li>              
          </ul>
          
      </div>
      <h1><?php print $node->title; ?></h1>
      <div class="story-left-section">
        <?php if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) { ?>
              <div class="story-left">
                  <div class="byline"><?php
                      $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
                      $reporter_node = node_load($byline_id);
                      ?>                      
                      <div class="profile-pic">
                      <?php
                      $file = $reporter_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                      if(!empty($file)) {
                      print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                      }
                      else {
                       $file = 'default_images/user-default.png';
                       print theme('image_style', array('style_name' => 'user_picture', 'path' => $file)); 
                      }
                      ?>
                  </div>
              <div class="profile-detail">
                  <a href="../../../../../../html/itgcms/sites/all/themes/itg/templates/flag--my-saved-content.tpl.php"></a>
                  <ul>
                      <li class="title"><?php print $reporter_node->title; ?></li>
                      <?php  $twitter_handle = $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
                      $twitter_handle = str_replace('@', '', $twitter_handle);
                      if(!empty($twitter_handle)) {
                      ?>
                      <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle;?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value']; ?></li>                
                      <?php } ?>
                  </ul>
                  <ul class="date-update">
                      <li class="mailto mhide"><i class="fa fa-envelope-o"></i> &nbsp;<?php
                              $email = $reporter_node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
                              print "<a href='mailto:$email'>Mail To Author</a>";
                              ?></li>
                      <li class="mhide"><span class="share-count">4.5K</span>SHARES</li>
                      <li><?php print  date('F j, Y', $node->created); ?>   </li>
                      <li>UPDATED <?php print  date('H:i', $node->changed); ?> IST</li>
                      <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name;  ?></li>
                  </ul>
                  <ul class="social-links mhide">
                      <li><a onclick="gogogo('<?php print $actual_link;?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i></a> <!--<span>958</span>--></li>
                      <li><a href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a> <!--<span>8523</span>--></li>
                      <li><a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link;?>')"><i class="fa fa-google-plus"></i></a> <!--<span>7258</span>--></li>
                      <li><a href="#"><i class="fa fa-comment"></i></a> <!--<span>1522</span>--></li>
                      <?php global $user; ?>
                      <?php if ($user->uid > 0): ?>
                         <?php $read_later = flag_create_link('my_saved_content', $node->nid); ?>                      
                         <li><?php print $read_later; ?></li>
                      <?php else: ?>
                         <?php print '<li>' . l('<i class="fa fa-bookmark"></i> READ LATER', 'user/login', array('html' => TRUE)) . '</li>'; ?>
                      <?php endif; ?>                      
                  </ul>
                  </div>
                  </div>
                  <?php if(!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                  <div class="briefcase mhide">
                      <h4><?php print t('Briefcase'); ?></h4>
                      <ul>
                          <?php
                          foreach ($node->field_story_highlights['und'] as $high) {
                              print '<li>' . $high['value'] . '</li>';
                          }
                          ?>
                      </ul>
                  </div>
                  <?php } ?>
              </div>  
          <?php  } ?>
          
          

      <div class="story-right">
          <?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) { ?>
          <!-- For buzzfeed section start -->
          <div class="byline"><?php
                  $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
                  $reporter_node = node_load($byline_id);
                  ?>
                  <div class="profile-pic">
                      <?php
                      $file = $reporter_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                      if(!empty($file)) {
                      print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                      }
                      else {
                       $file = 'default_images/user-default.png';
                       print theme('image_style', array('style_name' => 'user_picture', 'path' => $file)); 
                      }
                      ?>
                  </div>
              <div class="profile-detail">
                  <ul>
                      <li class="title"><?php print $reporter_node->title; ?></li>
                      <?php  $twitter_handle = $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
                      $twitter_handle = str_replace('@', '', $twitter_handle);
                      if(!empty($twitter_handle)) {
                      ?>
                      <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle;?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value']; ?></li>                
                      <?php } ?>
                  </ul>
                  <ul class="date-update">
                     <li><?php print  date('F j, Y', $node->created); ?>   </li>
                      <li>UPDATED <?php print  date('H:i', $node->changed); ?> IST</li>
                      <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name;  ?></li>
                  </ul>
                  </div>
              </div>
          <!-- For buzzfeed section end -->
         <?php } ?>
          <?php if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) { ?>
      <div class="stryimg"><?php $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                      print theme('image_style', array('style_name' => 'story_image', 'path' => $story_image)); ?>
          
          <?php } else {?>
          <div class="stryimg"><?php $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                      print theme('image_style', array('style_name' => 'buzz_image', 'path' => $story_image)); ?>
          <?php } ?>
              <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
      <div class="photoby"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?></div>
              <?php } ?>
      </div>
      
      <div class="image-alt"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?></div>
            
      <?php
      if (empty($node->field_story_template_buzz[LANGUAGE_NONE])){
      if(!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                  <div class="briefcase desktop-hide">
                      <h4><?php print t('Briefcase'); ?></h4>
                      <ul>
                          <?php
                          foreach ($node->field_story_highlights['und'] as $high) {
                              print '<li>' . $high['value'] . '</li>';
                          }
                          ?>
                      </ul>
                  </div>
      <?php } } ?>
      
      
      
      <div class="description"><?php print render($content['body']); ?></div>
      
      </div>
          
    </div>
      
      <!-- condition for buzz  -->
     
      <?php
          if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
          $buzz_output.= '';
          $buzz = 1;
          foreach ($node->field_story_template_buzz['und'] as $buzz_item) {

            $buzz_output.= '<div class="buzz-section">';

            $field_collection_id = $buzz_item['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $buzz_imguri = _itg_photogallery_fid($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
            $file = file_load($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
            $share_uri = $file->uri;
            $share_image = file_create_url($share_uri);
            $img = '<img src="' . image_style_url("buzz_image", $buzz_imguri) . '">';
            if(!empty($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'])) {
            $buzz_output.= '<h1><span>'.$buzz.'</span>' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</h1>';
            if(!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
            $buzz_output.= '<div class="buzz-img"><div class="social-share">
              <ul>
              <li><a href="#" class="share"><i class="fa fa-share-alt"></i></a></li>
              <li><a onclick="gogogo('."'".$actual_link."'".', '."'".  addslashes(htmlspecialchars($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'], ENT_QUOTES))."'".', '."'".$share_desc."'".', '."'".$share_image."'".')" class="facebook"><i class="fa fa-facebook"></i></a></li>
              <li><a href="javascript:" onclick="twitter_popup('."'".urlencode($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'])."'".', '."'".urlencode($short_url)."'".')" class="twitter"><i class="fa fa-twitter"></i></a></li>
              <li><a title="share on google+" href="#" onclick="return googleplusbtn('."'".$actual_link."'".')" class="google"><i class="fa fa-google-plus"></i></a></li>
              </ul>
          </div>' . $img . '</div>';
            }
            if(!empty($entity[$field_collection_id]->field_buzz_description['und'][0]['value'])) {
            $buzz_output.= '<div class="buzz-discription">' . $entity[$field_collection_id]->field_buzz_description['und'][0]['value'] . '</div>';
            }
            $buzz_output.= '</div>';
             $buzz++;
          }
          }
          print $buzz_output;
        }
        
        ?>
      
      <!-- condition for buzz end -->      
      
      <div class="section-left-bototm">
          <div class="social-list">
            <ul>
                <li class="mhide"><a href="#"><i class="fa fa-share"></i></a> <span>Submit Your Story</span></li>
                <li class="mhide"><div id="fb-root"></div><a onclick="gogogo('<?php print $actual_link;?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i></a></li>
                <li class="mhide"><a href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li class="mhide"><a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link;?>')"><i class="fa fa-google-plus"></i></a></li>
                <li class="mhide"><a href="#"><i class="fa fa-comment"></i></a> <span>1522</span></li>
                <li class="mhide"><span class="share-count">4.3k</span> SHARES</li>
                <li><span>Edited by</span> Arunava Chatterjee</li>
                <li><a href="#">follow the Story</a></li>
            </ul>
          </div>
          
              <?php if(!empty($node->field_story_snap_post[LANGUAGE_NONE][0]['value'])) { ?>    
              <div class="snap-post">
                  <div class="discription"><?php print $node->field_story_snap_post[LANGUAGE_NONE][0]['value']; ?></div>

                  <div class="agbutton"><button>Agree</button> <button>DisAgree</button> <a href="<?php echo $base_url;?>/snappost">More from Snap post</a></div>
              </div>
              <?php } ?>
              <div class="tags">
                  <ul>
                      <li><i class="fa fa-tags"></i> Tags :</li>        
                      <?php
                      foreach ($node->field_story_itg_tags['und'] as $tags) {
                          $term = taxonomy_term_load($tags['tid']);
                          $t_name = $term->name;
                          $comma_sep_tag[] = $t_name;
                          print '<li>#' . $t_name . '</li>';
                      }
                      ?>
                  </ul>
              </div>
      </div>
     
             <?php 
              if(function_exists('taboola_view')) {
                taboola_view();
              }
           ?>
      
      <?php 
           if (function_exists(global_comment_last_record)) {
                 $last_record = global_comment_last_record();
                 $config_name = trim($last_record[0]->config_name);
               }
               if($config_name == 'vukkul') {
               ?>
      <div class="vukkul-comment">

            <div id="vuukle_div"></div>
            
             <?php 
              if(function_exists('vukkul_view')) {
                vukkul_view();
              }
              ?>
     
        </div>
               <?php } 
               if($config_name == 'other') {
               ?>
      <div id="other-comment">
        <?php print render($content['comment_form']); ?>
        <?php print render($content['comments']); ?>
        </div>
               <?php } ?>
  </div>
</div>
<?php endif; ?>
<!-- script for facebook sharing -->
<script>(function(d, s, id) {
                        var js, fjs = d.getElementsByTagName(s)[0];
                        if (d.getElementById(id)) return;
                        js = d.createElement(s); js.id = id;
                        js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.8&appId=265688930492076";
                        fjs.parentNode.insertBefore(js, fjs);
                      }(document, 'script', 'facebook-jssdk'));</script>
<script>
function gogogo(linkurl, title, desc, image) {
  FB.ui({
    method: 'feed',
    link: linkurl,
    picture: image,
    name: title,
    //caption: desc,
    description: desc
  });
}
  
</script>
<!-- facebook sharing end here -->

<!-- script for twitter sharing -->
<script type="text/javascript">
  function twitter_popup(title, url) {
    tweetlink = "http://twitter.com/share?text="+title+"&url="+url+"&via=indiatoday";
    newwindow=window.open(tweetlink,'indiatoday','height=500,width=550,left=440,top=250');
    if (window.focus) {newwindow.focus()}
    return false;
  }
</script>
<!-- twitter sharing end here -->

<!-- script for google sharing -->
<script>
function googleplusbtn(url, title, img) {
  sharelink = "https://plus.google.com/share?url="+url;
  newwindow=window.open(sharelink,'indiatoday','height=400,width=600,left=440,top=250');
  if (window.focus) {newwindow.focus()}                                                                                                                                
  return false;
}   
</script>
<!-- google sharing end here -->