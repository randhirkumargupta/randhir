<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>

      <?php if (!empty($links)): ?>
        <div class='<?php print $hook ?>-links clearfix'>
          <?php print render($links) ?>
        </div>
      <?php endif; ?>

      <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      </div></div>
  <?php endif; ?>

  <?php if ($layout): ?>
    <div class='column-main'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($title_prefix)) print render($title_prefix); ?>

      <?php if (!empty($title) && !$page): ?>
        <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
          <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
          <a href="<?php print $node_url ?>"><?php print $title ?></a>
        </h2>
      <?php endif; ?>

      <?php if (!empty($title_suffix)) print render($title_suffix); ?>

      <?php if (!empty($content)): ?>
        <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
          <?php //print render($content)  ?>

          <?php if ($view_mode == 'full'): ?>
            <div class="content-node-view">
              <h2>Basic Details</h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label">Title</div>
                  <div class="field-items"><?php print $title; ?></div>
                </div>

                <?php
                $content_type = render($content['field_recipe_content_type']);
                if (!empty($content_type)):
                  print render($content['field_recipe_content_type']);
                  ?>
                <?php endif; ?>
                <?php
                $strap = render($content['field_recipe_strap_headline']);
                if (!empty($strap)):
                  print $strap;
                  ?>
                <?php endif; ?>
                <?php
                $long_headline = render($content['field_recipe_long_headline']);
                if (!empty($long_headline)):
                  print render($content['field_recipe_long_headline']);
                  ?>
                <?php endif; ?>

                <?php
                $wap_headline = render($content['field_recipe_wap_headline']);
                if (!empty($wap_headline)):
                  print render($content['field_recipe_wap_headline']);
                  ?>
                <?php endif; ?>

                <?php
                $kicker = render($content['field_recipe_kicker_headline']);
                if (!empty($kicker)):
                  print render($content['field_recipe_kicker_headline']);
                  ?>
                <?php endif; ?>

                <?php
                $byline = render($content['field_recipe_byline']);
                if (!empty($byline)):
                  ?>    
                  <?php print render($content['field_recipe_byline']); ?>
                <?php endif; ?>
                <?php
                $courtesy = render($content['field_recipe_courtesy']);
                if (!empty($courtesy)):
                  ?>    
                  <?php print render($content['field_recipe_courtesy']); ?>
                <?php endif; ?>
                <?php
                $city = render($content['field_recipe_city']);
                if (!empty($city)):
                  ?>    
                  <?php print render($content['field_recipe_city']); ?>
                <?php endif; ?>
              </div>
            </div>

            <div class="content-node-view">
              <h2>Recipe Details</h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label">Description / Procedure</div>
                  <div class="field-items"> <?php $description = render($content['field_recipe_description'][0]['#markup']);
            $short_des = render($content['field_label']);
                ?>
                    <?php if (!empty($description)): ?>
                      <div class="breaking-content-details"><?php print render($content['field_recipe_description'][0]['#markup']); ?></div> 
    <?php endif; ?></div>
                </div>                  

                <?php
                $cuisine_type = render($content['field_recipe_cuisine_type']);
                if (!empty($cuisine_type)):
                  print $cuisine_type;
                  ?>
                <?php endif; ?>
                <?php
                $meal_for = render($content['field_recipe_meal_for']);
                if (!empty($meal_for)):
                  print render($content['field_recipe_meal_for']);
                  ?>
                <?php endif; ?>

                <?php
                $calorie_type = render($content['field_recipe_calorie_type']);
                if (!empty($calorie_type)):
                  print render($content['field_recipe_calorie_type']);
                  ?>
                <?php endif; ?>
                <?php
                $calorie_count = render($content['field_recipe_calorie_count']);
                if (!empty($calorie_count)):
                  print render($content['field_recipe_calorie_count']);
                  ?>
                <?php endif; ?>
                <?php
                $time = render($content['field_recipe_time']);
                if (!empty($time)):
                  ?>    
                  <?php print render($content['field_recipe_time']); ?>
                <?php endif; ?>
                <?php
                $ailment = render($content['field_recipe_ailment']);
                if (!empty($ailment)):
                  ?>    
                  <?php print render($content['field_recipe_ailment']); ?>
                <?php endif; ?>
                <?php
                $meal_type = render($content['field_recipe_meal_type']);
                if (!empty($meal_type)):
                  print render($content['field_recipe_meal_type']);
                  ?>
                <?php endif; ?>
                <?php
                $festivals = render($content['field_recipe_festivals']);
                if (!empty($festivals)):
                  ?>    
                  <?php print render($content['field_recipe_festivals']); ?>
                <?php endif; ?>
                <?php
                $ingredients = render($content['field_recipe_ingredient']);
                if (!empty($ingredients)):
                  ?>    
                  <?php print render($content['field_recipe_ingredient']); ?>
    <?php endif; ?>

              </div>
            </div>

            <?php
            $browsemedialarge = render($content['field_recipe_upload_large_image']);
            $browsemediamedium = render($content['field_recipe_medium_image']);
            $browsemediasmall = render($content['field_recipe_small_image']);
            $browsemediamobile = render($content['field_recipe_mobile_image']);
            if (!empty($browsemedialarge) || !empty($browsemediamedium) || !empty($browsemediasmall) || !empty($browsemediamobile)):
              ?>
              <div class="content-node-view">
                <h2>Recipe Images</h2>
                <div class="content-details">
                  <?php print render($content['field_recipe_upload_large_image']); ?>
                  <?php print render($content['field_recipe_medium_image']); ?>
      <?php print render($content['field_recipe_small_image']); ?>
              <?php print render($content['field_recipe_mobile_image']); ?>
                </div>
              </div>
            <?php endif; ?>

            <?php
          // end of view mode full condition
          endif;
          ?>
          <div class="content-node-view">
            <h2>Syndication</h2>
            <div class="content-details">      
              <?php
              $syndication = render($content['field_recipe_syndication']);
              $client_title = render($content['field_recipe_client_title']);
              ?>

                <?php if (!empty($syndication) || !empty($client_title)): ?>
                <div class="description-details content-box">
                  <?php
                  if (!empty($syndication)):
                    print render($content['field_recipe_syndication']);
                    ?>
                  <?php endif; ?>
                <?php if (!empty($client_title)): ?>
                    <div class="breaking-content-details"><?php print render($content['field_recipe_client_title']); ?></div> 
    <?php endif; ?>
                </div>
  <?php endif; ?>
            </div>

          </div>
          <div class="content-node-view">
            <h2>Recipe Section</h2>
            <div class="content-details">
              <?php
              $section = render($content['field_recipe_section']);
              if (!empty($section)):
                ?>    
    <?php print render($content['field_recipe_section']); ?>
  <?php endif; ?>
            </div>
          </div>


        </div>
  <?php endif; ?>

<?php if ($layout): ?>
      </div></div>
<?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

