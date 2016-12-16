<?php
if (!empty($data)) :
  global $base_url;
  $db_node = $data['node_data'];
  $cls = '';
  if(is_mobile()) {
    $cls = 'mobile';
  } else{
    $cls = 'not-mobile';
  }
  ?>
<div class="big-story-format-layout <?php echo $cls ?> ">
  <div class="big-story-wrapper">
    <div class="extra-large-image">
      <?php if (!empty($db_node->field_story_extra_large_image['und'][0]['uri'])) { ?>
        <a href='<?php echo $base_url . '/' . drupal_get_path_alias("node/{$db_node->nid}") ?>'>
          <img src="<?php print image_style_url("at_big_story", $db_node->field_story_extra_large_image['und'][0]['uri']); ?>" />
        </a>  
        <?php
        // prepare configuration for sharing
        $image = file_create_url($data['node_data']->field_story_extra_large_image['und'][0]['uri']);
      }
      else {
        $default_image = array(
          '#theme' => 'image_style_outside_files',
          '#style_name' => 'at_big_story',
          '#path' => drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
        );
        print l(render($default_image), "node/$db_node->nid", array("html" => true));
      }
      ?>
    </div>
    <div class="big-story-text">
      <div class="big-story-title">
        <?php print l($db_node->title, "node/$db_node->nid"); ?>
      </div>
      <div class="reported-by">
        <span class="name">
          <?php
          $user_data = user_load($db_node->uid);
          print l($user_data->name, "user/$user_data->uid");
          unset($user_data);
          ?>
        </span>
        <span class="date">
          <?php
          print date("h:s", $db_node->changed) . " " . t("IST");
          ?>
        </span>
      </div>
      <?php if(is_mobile()) { ?>
        <div class="icon-related show-related">
          <span></span>
          <span></span>
          <span></span>
        </div>
      <?php } ?>
    </div>
  </div>
  <?php
  $default_image_src = $base_url . "/" . drupal_get_path('theme', 'aajtak') . "/images/default_for_all.png";
  $default_image_fornt = "<img src='" . $default_image_src . "' alt='Images'>";
  $front_page_promoted_nodes = itg_widget_at_get_big_story_front_content_data();
  ?>
  <div class="big-story-related-content">
    <?php foreach ($front_page_promoted_nodes as $front_promoted_data):?>
      <div class="big-story-related-content-list">
        <div class="tile">
          <?php if(is_mobile()) { ?>
            <div class="category-name">
              <?php
              if (!empty($front_promoted_data['field_primary_category_value'])) {
                $term_data = taxonomy_term_load($front_promoted_data['field_primary_category_value']);
                print $term_data->field_cm_display_title['und'][0]['value'];
              }
              ?>
            </div>
          <?php } ?>
          <div class="pic">
            <?php if(!empty($front_promoted_data['uri'])) : ?>
            <?php echo $default_image_fornt; ?>
            <?php else : ?>
            <?php
             print image_style_url("at_big_story_front_promoted_image", $front_promoted_data['uri']);
             $image = '<img src="'.$image_src.'" />';
             print l($image , 'node/'.$front_promoted_data['nid'] , array('html' => TRUE)); ?>
            <?php endif; ?>
          </div>
          <?php if(!is_mobile()) { ?>
          <div class="details">
            <div class="category-name">
              <?php
              if (!empty($front_promoted_data['field_primary_category_value'])) {
                $term_data = taxonomy_term_load($front_promoted_data['field_primary_category_value']);
                print $term_data->field_cm_display_title['und'][0]['value'];
              }
              ?>
            </div> 
            <?php } ?>
            <div class="title">
              <?php print l(mb_strimwidth($front_promoted_data['title'], 0, 65, ".."), 'node/' . $front_promoted_data['nid']); ?>
            </div>
            <div class="reported-by">
              <span class="name">
                <?php 
                if(isset($front_page_promoted_data['uid']) && !empty($front_page_promoted_data['uid'])) {
                  $user_load_data = user_load($front_page_promoted_data['uid']);
                  print $user_load_data->name;
                }
                ?>
              </span>
              <span class="date">
              <?php print date('m:s' , time($front_page_promoted_data['created']));?>
              <?php print t("IST"); ?>
              </span>
            </div>
            <?php if(!is_mobile()) { ?>
          </div>
            <?php } ?>
        </div>
      </div>
    <?php endforeach; ?>
  </div>
  <?php if(is_mobile()) { ?> <div class="big-story-related-content-popup"></div> <?php } ?>
</div>
<?php endif; ?>