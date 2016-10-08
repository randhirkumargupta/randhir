<?php if (!empty($data)) : global $base_url; ?>
  <div class="how-made-it">
    <ul>
      <?php foreach ($data as $key => $node_data) { 
       
          ?>
        <li class="" id="dont-miss-<?php print $key ?>">
          <?php if (!empty($node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <span class="dm-pic">
              <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}") ?>">
                <img src="<?php print image_style_url("widget_very_small", $node_data['node_load_data']->field_story_extra_large_image['und'][0]['uri']); ?>" />
              </a>
            </span>
            <?php
          }
          else {
            ?>
            <span class="dm-pic">
              <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}") ?>">
                 <img height="66" width="88" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
              </a>
            </span>
          <?php } ?>

          <span class="dm-detail">

            <?php $title=$node_data['node_load_data']->title; 
            if (!empty($node_data['custom_label'])) : ?>
            <?php $title= $node_data['custom_label']; ?>
            <?php endif; ?>

            <?php if (!empty($title)) : ?>    
              <p class="title">
                <?php echo l(mb_strimwidth($title, 0, 60, ".."), $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}")) ?>
              </p>
              <p><?php 
                $desc=$node_data['node_load_data']->field_story_kicker_text['und'][0]['value'];
                            if($desc=="")
                            {
                                $desc=$node_data['node_load_data']->body['und'][0]['value'];
                            }
                                
                            echo mb_strimwidth(strip_tags($desc), 0, 70, "..") ;?>
            <?php endif; ?>
              </p>

          </span>
            <span class="more"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_data['node_load_data']->nid}") ?>">More[+]</a></span>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  
<?php endif; ?>