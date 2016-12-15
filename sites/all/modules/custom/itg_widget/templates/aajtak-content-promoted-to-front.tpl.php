<?php
  global $base_url;
  $default_image_src = $base_url . "/" . drupal_get_path('theme', 'aajtak') . "/images/default_for_all.png";
  $default_image_fornt = "<img src='" . $default_image_src . "' alt='Images'>";
  $front_page_promoted_nodes = itg_widget_at_get_big_story_front_content_data();
?>

<?php if($is_mobile){ ?>

<div>Code for Mobile</div>

<?php } else { ?>
  <?php
      // Get initial 5 vlaues of array
      $frist_slide_array_data = array_slice($front_page_promoted_nodes,0,5);
      // Remove a portion of the array and replace it with something else
      $rest_slide_array_data = array_splice($front_page_promoted_nodes,5);
  ?>
<div class="promoted-to-front">
  <!-- First slide of banner -->
  <?php if(!empty($frist_slide_array_data)) : ?>
  <div class="promoted-to-front-list">
    <?php foreach($frist_slide_array_data as $frist_slide_key=>$frist_slide_array) : ?>
      <div class="tile-wrapper">
        <div class="tile-inner">
          <div class="icon-list">
            <span></span>
            <span></span>
            <span></span>
          </div>
          <a href="#" class="tile">
            <div class="pic">
              <?php if(!empty($frist_slide_array['uri'])) : ?>
              <?php echo $default_image_fornt; ?>
              <?php else : ?>
              <?php
               $image_src =  image_style_url("at_big_story_front_promoted_image", $frist_slide_array['uri']);
               $image = '<img src="'.$image_src.'" />';
               print l($image , 'node/'.$frist_slide_array['nid'] , array('html' => TRUE)); ?>
              <?php endif; ?>
              <div class="category-name">
                <?php
                    if (!empty($frist_slide_array['field_primary_category_value'])) {
                      $term_data = taxonomy_term_load($frist_slide_array['field_primary_category_value']);
                      print $term_data->field_cm_display_title['und'][0]['value'];
                    }
                    ?>
              </div>
            </div>
            <div class="title">
              <h2>
                <?php
                if($frist_slide_key ==0 ){
                  $limt = 40;
                }
                else {
                    $limt = 22;
                }
                ?>
                <?php print l(mb_strimwidth($frist_slide_array['title'], 0, $limt, ".."), 'node/' . $frist_slide_array['nid']); ?>
              </h2>
            </div>
            <div class="reported-by">
              <span class="name">
                <?php 
                  if(isset($frist_slide_array['uid']) && !empty($frist_slide_array['uid'])) {
                    $user_load_data = user_load($frist_slide_array['uid']);
                    print l($user_load_data->name , 'user/'.$user_load_data->uid);
                  }
                  ?>
              </span>
              <span class="date">
                
                <?php print date('m:s' , time($frist_slide_array['created']));?>
                <?php print t("IST"); ?></span>
            </div>
          </a>
        </div>
      </div>
    <?php endforeach;?>    
  </div>
  <?php endif; ?>
  <!-- Next slides -->
  <?php if(!empty($rest_slide_array_data)) :?>
  <?php 
  // Create array chunk of 8-8 then create slides blocks
  $rest_array_chunk = array_chunk($rest_slide_array_data, 8);
  ?>
  <?php foreach($rest_array_chunk as $rest_array_chunk_data_array) : ?>
    <div class="promoted-to-front-list">
      <?php foreach($rest_array_chunk_data_array as $inner_slides) :?>
      <div class="tile-wrapper">
        <div class="tile-inner">
          <div class="icon-list">
            <span></span>
            <span></span>
            <span></span>
          </div>
          <a href="#" class="tile">
            <div class="pic">
              <?php if(empty($inner_slides['uri'])) : ?>
              <?php echo $default_image_fornt; ?>
              <?php else : ?>
              <?php
               $image_src =  image_style_url("at_big_story_front_promoted_image", $inner_slides['uri']);
               $image = '<img src="'.$image_src.'" />';
               print l($image , 'node/'.$inner_slides['nid'] , array('html' => TRUE)); ?>
              <?php endif; ?>
              <div class="category-name">
                <?php
                    if (!empty($inner_slides['field_primary_category_value'])) {
                      $term_data = taxonomy_term_load($inner_slides['field_primary_category_value']);
                      print $term_data->field_cm_display_title['und'][0]['value'];
                    }
                    ?>
              </div>
            </div>
            <div class="title">
              <h2>
                <?php print l(mb_strimwidth($inner_slides['title'], 0, 20, ".."), 'node/' . $inner_slides['nid']); ?>
              </h2>
            </div>
            <div class="reported-by">
              <span class="name">
                <?php 
                if(isset($inner_slides['uid']) && !empty($inner_slides['uid'])) {
                  $user_load_data = user_load($inner_slides['uid']);
                  print l($user_load_data->name,"user/".$user_load_data->uid);
                }
                ?>
              </span>
              <span class="date">
                <?php print date('m:s' , time($inner_slides['created']));?>
                <?php print t("IST"); ?>
              </span>
            </div>
          </a>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
  <?php endif; ?>
</div>

<?php } ?>