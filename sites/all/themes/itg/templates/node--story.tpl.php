<?php if (!empty($content)):
   global $base_url;
  ?>

<div class="story-section">
  <div class='<?php print $classes ?>'>
      <h1><?php print $node->title; ?></h1>
      
      <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
      <div class="stryimg"><?php $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                      print theme('image_style', array('style_name' => 'story_image', 'path' => $story_image)); ?>
          
                <?php } if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
      <!--<div class="photoby"><?php //print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?></div>-->
              <?php } ?>
      </div>
      
      <!--<div class="image-alt"><?php //if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'])) { print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; } ?></div>-->
      <?php
      // get byline detail
        $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
        $reporter_node = node_load($byline_id);
      
      ?>
      <div class="byline">
          <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
        <div class="byline-pic"><?php $byline_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                      print theme('image_style', array('style_name' => '50_50', 'path' => $byline_image)); ?></div>
          <?php } ?>
        <div class="byline-detail">
            <ul>
              <li class="title"><?php
                print $reporter_node->title;
                ?></li>
              <?php
              $twitter_handle = $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
              $twitter_handle = str_replace('@', '', $twitter_handle);
              if (!empty($twitter_handle)) {
                ?>
                <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value']; ?></li>                
              <?php } ?>
            </ul>
            <ul class="date-update">
              <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></li>
              <li><?php print make_hin_str(date('j F, Y', $node->created)); ?>   </li>
              <li>अपडेटेड <?php print make_hin_str(date('H:i', $node->changed)); ?> IST</li>
            </ul>
          </div>
          
          
      </div>
      <div class="description">
        <?php print $node->body['und'][0]['value']; ?>
      </div>
      
      <div class="previous-next">
        <?php
        $view_name = 'photo_gallery_management';
        $view_display = 'page_1';
        $vvid = itg_front_end_node_weight(1683, $view_name, $view_display);
        ?>
        <div id="previous">
            <a href="#">Previous</a>
            <div class="prev-details">
              <?php
              $previous = node_load(itg_get_previousnext_weight($vvid - 1, $view_name, $view_display));
              ?>
              <h4>
                <?php
                $pre_url = url('node/' . $previous->nid, array('absolute' => TRUE));
                print l($previous->title, $pre_url);
                ?>
              </h4>
              <?php
              $pre_image = $previous->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];

              if (!empty($pre_image)) {
                print theme('image_style', array('style_name' => '98x55', 'path' => $pre_image));
              }
              ?>
            </div>
          </div>
        <div id="next">
            <a href="#">Next</a>
            <div class="prev-details">
              <?php
              $next = node_load(itg_get_previousnext_weight($vvid + 1, $view_name, $view_display));
              ?>
              <h4>
              <?php
              $next_url = url('node/' . $next->nid, array('absolute' => TRUE));
              print l($next->title, $next_url);
              ?>
              </h4>
              <?php
              $nxt_image = $next->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
              if (!empty($nxt_image)) {
                print theme('image_style', array('style_name' => '98x55', 'path' => $nxt_image));
              }
              ?>
            </div>
          </div>
          </div>
      <div class="tags">
        <h3>टैग्स</h3> 
        <ul>      
          <?php
          foreach ($node->field_story_itg_tags['und'] as $tags) {
            $term = taxonomy_term_load($tags['tid']);
            $t_name = $term->name;
            $comma_sep_tag[] = $t_name;
            print '<li># ' . $t_name . '</li>';
          }
          ?>
        </ul>
      </div>
      
      <div id="ads-place">Ads goes here</div>
      <div id="api-place">Third party api goes here</div>
      <?php 
           if (function_exists(global_comment_last_record)) {
                 $last_record = global_comment_last_record();
                 $config_name = trim($last_record[0]->config_name);
               }
               if($config_name == 'vukkul') {
               ?>
      <div class="vukkul-comment">
            <div id="vuukle-emote"></div>
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
      <div class="story-photos">
        <div class="half-grey-bg">
        <h3>फोटोज</h3>
        <?php print views_embed_view('related_photogallery','page', $node->field_primary_category[LANGUAGE_NONE][0]['value']); ?>
        </div>
      </div>
      <div class="popular-videos">
        <div class="half-grey-bg">
          <h3>पॉपुलर वीडियोज़</h3>
          <div id="video-place"><?php print views_embed_view('related_photogallery','page_1', $node->field_primary_category[LANGUAGE_NONE][0]['value']); ?></div>
        </div>
      </div>
     </div>
</div>
<?php endif; ?>
