<?php
global $base_url;
if ($widget_style == 'aajtak-slider') {?>
    <ul class="widget-list-wrapper slider-container">
        <?php foreach($data as $values) : ?>
        <li class="widget-list-row">
          <div class="tile">
            <?php if(isset($values->field_primary_category['und'][0]['tid'])) : ?>
            <div class="cateogry-name">
             <?php 
             $tid = $values->field_primary_category['und'][0]['tid'];
             $term_data = taxonomy_term_load($tid);
             print l($term_data->name , "taxonomy/term/$tid");
             ?>
            </div>
            <?php endif; ?>
            <div class="pic">
              <?php
              $extra_large_image_url = $base_url . '/' . drupal_get_path('theme', 'aajtak') . "/images/default_for_all.png";
              if(isset($values->field_story_extra_large_image['und'][0]['uri'])) {
                $extra_large_image_uri = $values->field_story_extra_large_image['und'][0]['uri'];
                $extra_large_image_url = file_create_url($extra_large_image_uri);
              }
              print "<img src='".$extra_large_image_url."'>";
              ?>
            </div>
            <div class="title"><?php print $values->title ?></div>
            <div class="reported-by">
              <span class="name">
                <?php 
                 $user_data = user_load($values->uid);
                 print l($user_data->name , "user/$user_data->uid") 
                ?>
              </span>
              <span class="date"><?php print date("h:s", $values->created) ?> <?php print t("IST"); ?></span>
            </div>
          </div>
        </li>
        <?php endforeach; ?>
      </ul>

<?php } else if ($widget_style == 'stack-card-0' || $widget_style == 'stack-card-1' || $widget_style == 'stack-card-2') { ?>

        <ul id="<?php echo $widget_style; ?>" class="stack stack--krisna">
          <?php foreach($data as $values) : ?>
        <li class="stack__item">
          <div class="tile">
            <?php if(isset($values->field_primary_category['und'][0]['tid'])) : ?>
            <div class="cateogry-name">
             <?php 
             $tid = $values->field_primary_category['und'][0]['tid'];
             $term_data = taxonomy_term_load($tid);
             print l($term_data->name , "taxonomy/term/$tid");
             ?>
            </div>
            <?php endif; ?>
            <div class="pic">
              <?php
              $extra_large_image_url = $base_url . '/' . drupal_get_path('theme', 'aajtak') . "/images/default_for_all.png";
              if(isset($values->field_story_extra_large_image['und'][0]['uri'])) {
                $extra_large_image_uri = $values->field_story_extra_large_image['und'][0]['uri'];
                $extra_large_image_url = file_create_url($extra_large_image_uri);
              }
              print "<img src='".$extra_large_image_url."'>";
              ?>
            </div>
            <div class="title"><?php print $values->title ?></div>
            <div class="reported-by">
              <span class="name">
                <?php 
                 $user_data = user_load($values->uid);
                 print l($user_data->name , "user/$user_data->uid") 
                ?>
              </span>
              <span class="date"><?php print date("h:s", $values->created) ?> <?php print t("IST"); ?></span>
            </div>
          </div>
        </li>
        <?php endforeach; ?>
        </ul>
      <div class="controls">
      <button class="button button--sonar button--reject" data-stack="<?php echo $widget_style; ?>">Reject</button>
      <button class="button button--sonar button--accept" data-stack="<?php echo $widget_style; ?>">Accept</button>
    </div>


<?php }