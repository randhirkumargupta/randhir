<?php if (!empty($content)):
   global $base_url;
  ?>
<?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) { 
            $class_buzz = 'buzz-feedback';
        }
?>
<div class="story-section <?php print $class_buzz;?>">
  <div class='<?php print $classes ?>'>
      <?php //pr($node); ?>      
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
                      print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                      ?>
                  </div>
              <div class="profile-detail">
                  <ul>
                      <li class="title"><?php print $reporter_node->title; ?></li>
                      <li class="twitter"><?php print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value']; ?></li>                
                  </ul>
                  <ul>
                      <li class="mailto mhide"><i class="fa fa-envelope-o"></i> &nbsp;<?php
                              $email = $reporter_node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
                              print "<a href='mailto:$email'>Mail To Author</a>";
                              ?></li>
                      <li class="mhide"><span class="share-count">4.5K</span>SHARES</li>
                      <li><?php print  date('F j, Y', $node->created); ?>   </li>
                      <li>UPDATED <?php print  date('H:i', $node->changed); ?> IST</li>
                      <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name;  ?></li>
                  </ul>
                  </div>
                  </div>
                  <div class="briefcase">
                      <h4><?php print t('Briefcase'); ?></h4>
                      <ul>
                          <?php
                          foreach ($node->field_story_highlights['und'] as $high) {
                              print '<li>' . $high['value'] . '</li>';
                          }
                          ?>
                      </ul>
                  </div>
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
                      print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                      ?>
                  </div>
              <div class="profile-detail">
                  <ul>
                      <li class="title"><?php print $reporter_node->title; ?></li>
                      <li class="twitter"><?php print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value']; ?></li>                
                  </ul>
                  <ul>
                      <li>Nov 13, 2014  </li>
                      <li>UPDATED 11:04 IST</li>
                      <li>New Delhi</li>
                  </ul>
                  </div>
              </div>
          <!-- For buzzfeed section end -->
         <?php } ?>
          
      <div class="stryimg"><?php print render($content['field_story_extra_large_image']); ?>
      <div class="photoby"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?></div>
      </div>
      
      <div class="image-alt"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?></div>
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
            $img = '<img src="' . image_style_url("thumbnail", $buzz_imguri) . '">';
            $buzz_output.= '<h1><span>'.$buzz.'</span>' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</h1>';
            $buzz_output.= '<div class="buzz-img">' . $img . '</div>';
            $buzz_output.= '<div class="buzz-discription">' . $entity[$field_collection_id]->field_buzz_description['und'][0]['value'] . '</div>';
            $buzz_output.= '</div>';
             $buzz++;
          }
         
          print $buzz_output;
        }
        ?>
      
      <!-- condition for buzz end -->
      
      
      <div class="section-left-bototm">

              <div class="snap-post">
                  <div class="discription"><?php print $node->field_story_snap_post[LANGUAGE_NONE][0]['value']; ?></div>

                  <div class="agbutton"><button>Agree</button> <button>DisAgree</button> <a href="<?php echo $base_url;?>/snappost">More from Snap post</a></div>
              </div>

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
      
      
      <div class="vukkul-comment">

            <div id="vuukle_div"></div>
            <?php
            if (array_key_exists("vukkul",$content)){
        print drupal_render($content["vukkul"]);
}
?>
        </div>

  </div>
</div>
<?php endif; ?>
