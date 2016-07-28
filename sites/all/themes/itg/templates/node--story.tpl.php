<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
      <?php //pr($node); ?>
      <div class="longheadline"><?php print $node->title; ?></div>
      <div class="stryimg"><?php print render($content['field_story_extra_large_image']); ?></div>
      <div class="photoby"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?></div>
      <div class="photoby"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?></div>
      <div class="description"><?php print render($content['body']); ?></div>
      <div class="byline"><?php
          $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
          $reporter_node = node_load($byline_id);
          ?>
          <div class="rtitle"><?php print $reporter_node->title; ?></div>
          <div class="rimage"><?php $file = $reporter_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
        print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
        ?></div>
      </div>
      <div class="rtwitter"><?php print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value']; ?></div>
      <div class="remail"><?php
        $email = $reporter_node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
        print "<a href='mailto:$email'>Mail To Author</a>";
        ?>
      </div>

      <div class="briefcase"><?php
          foreach ($node->field_story_highlights['und'] as $high) {
            print '<div class="field"><div class="field-items">' . $high['value'] . '</div></div>';
          }
          ?></div>

      <div class="snap-post"><?php print $node->field_story_snap_post[LANGUAGE_NONE][0]['value']; ?>

          <div class="agbutton"><button>Agree</button> <button>DisAgree</button> <a href="#">More from Snap post</a></div>
      </div>

      <div class="tags">Tags : <?php
          foreach ($node->field_story_itg_tags['und'] as $tags) {
            $term = taxonomy_term_load($tags['tid']);
            $t_name = $term->name;
            $comma_sep_tag[] = $t_name;
            print '<div class="field"><div class="field-items">#' . $t_name . '</div></div>';
          }
          
          ?></div>
      
          <div class="vukkul-comment">
              <input type="hidden" name="nid" id="nid" value=<?php print $node->nid; ?>>
              <input type="hidden" name="tags" id="tags" value=<?php print implode(',', $comma_sep_tag); ?>>
                <input type="hidden" name="title" id="title" value="<?php print $title." - India Today"; ?>">
              <div id="vuukle_div"></div><script src="http://vuukle.com/js/vuukle.js" type="text/javascript"></script><script type="text/javascript">

               var UNIQUE_ARTICLE_ID = jQuery('#nid').val();

               var SECTION_TAGS =  jQuery('#tags').val();

               var ARTICLE_TITLE = jQuery('#title').val();

               var GA_CODE = "UA-795349-17";

               var VUUKLE_API_KEY = "dc34b5cc-453d-468a-96ae-075a66cd9eb7";

               var TRANSLITERATE_LANGUAGE_CODE = ""; //"en" for English, "hi" for hindi

               var VUUKLE_COL_CODE = "d00b26";

               var ARTICLE_AUTHORS = 'JTVCJTdCJTIwJTIybmFtZSUyMjolMjAlMjJJbmRpYVRvZGF5LmluJTIwJTIyLCUyMCUyMCUyMCUyMmVtYWlsJTIyOiUyMCUyMmRlc2staXRnZEBpbnRvZGF5LmNvbSUyMCUyMiwlMjAlMjAlMjAlMjJ0eXBlJTIyOiUyMCUyMkFnZW5jeSUyMCUyMiU3RCU1RA==';

               create_vuukle_platform(VUUKLE_API_KEY, UNIQUE_ARTICLE_ID, "0", SECTION_TAGS, ARTICLE_TITLE, TRANSLITERATE_LANGUAGE_CODE , "1", "", GA_CODE, VUUKLE_COL_CODE, ARTICLE_AUTHORS);

               </script>

 
      </div>

  </div>
  <?php
  // code for comment hide and show based on condition

  //if ($node->field_story_configurations[LANGUAGE_NONE][0]['value'] == 'comment') {
    ?>
    <?php //if (!empty($node->field_story_comment_question[LANGUAGE_NONE][0]['value'])) { ?>
     <!-- <div class="node comm-ques"> <?php print render($content['field_story_comment_question']); ?></div> -->
    <?php //} ?>
    <?php
   // print render($content['comment_form']);
    //print render($content['comments']);
 // }
  ?>
<?php endif; ?>