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
      
      
      <!-- condition for buzz  -->
      <h3>BUZZ Detail</h3>
      <?php
          if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
          $buzz_output.= '';
          foreach ($node->field_story_template_buzz['und'] as $buzz_item) {

            $buzz_output.= '<div class="buzz-section">';

            $field_collection_id = $buzz_item['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $buzz_imguri = _itg_photogallery_fid($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
            $img = '<img src="' . image_style_url("thumbnail", $buzz_imguri) . '">';
            $buzz_output.= '<div class="field"><div class="field-label">Headline:</div><div class="field-items">' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</div></div>';
            $buzz_output.= '<div class="field"><div class="field-label">Image:</div><div class="field-items">' . $img . '</div></div>';
            $buzz_output.= '<div class="field"><div class="field-label">Description:</div><div class="field-items">' . $entity[$field_collection_id]->field_buzz_description['und'][0]['value'] . '</div></div>';
            $buzz_output.= '</div>';
          }

          print $buzz_output;
        }
        ?>
      
      <!-- condition for buzz end -->
      
      <div class="vukkul-comment">

            <div id="vuukle_div"></div>
            <?php
            if (array_key_exists("vukkul",$content)){
        print drupal_render($content["vukkul"]);
}
?>
        </div>

  </div>
  
<?php endif; ?>