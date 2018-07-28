<div class="watch-right-now-with-anchor">
<div class="watch-right-now-anchor-flex">
  <?php if (!empty($data['wrn_programmes'])) :?>
    <ul class="anchor-list-slide slides">
      <?php 
      $_program_count = count($data['wrn_programmes']);
      foreach ($data['wrn_programmes'] as $program_key => $program_data) {
        $program_data = (int) $program_data;
        $term = taxonomy_term_load($program_data);
        $term_name = $term->name;
        $p_schedule = $term->field_program_timing_in_days['und'][0]['value'];
        $p_timing = $term->field_user_city['und'][0]['value'];
        $p_time_period = $term->field_time_period['und'][0]['value'];
        $p_category_image_fid = $term->field_programme_category_image['und'][0]['fid'];
        $p_file = file_load($p_category_image_fid);
        
        $_anchor_url = FRONT_URL . '/' . drupal_get_path_alias("taxonomy/term/" . $term->tid);
        $_more_link = FRONT_URL . '/programmes';
       // $_program_link = ($program_key !== ($_program_count -1) ) ? $_anchor_url : $_more_link;
        $_program_link = $_anchor_url;
        ?>
        <li>
          <a  href="<?php print $_program_link; ?>" class="pic">     
			<?php print theme('image_style', array('path' => $p_file->uri, 'style_name' => 'image170x127', 'alt' => $term_name, 'title' => $term_name)); ?> 
          </a>
           <div class="programe-title"> <a href="/programmes/news-today"><?php print $term_name;?></a></div> 
           <div class="programe-timing"> <?php print $p_schedule;?> at <span class="time"> <?php print $p_timing ." ". $p_time_period;?> </span></div> 
        </li>
      <?php }?>  
    </ul>
  <?php endif;?>
</div>
<div class="space-15"></div>
<div class="tech-trip home-shows">
    <span class="feature-programe-title">FEATURED PROGRAMMES</span>
      <ul class="trending-videos">

          <?php
          if (!empty($data['wrn_video'])) {
            foreach ($data['wrn_video'] as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];
              ?>
              <li <?php echo $data_tb_region_item;?> class="trending-videos-list">                  
                <?php  if (!empty($entity['esi_file_uri']) && file_exists($entity['esi_file_uri'])) { ?>
                  <a  href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>" class="pic">
                    <?php print theme('image', array('path' => $entity['esi_file_uri'], 'alt' => $entity['field_story_extra_small_image_alt'], 'title' => $entity['field_story_extra_small_image_title'])); ?>
                  </a>
                  <?php
                }
                else {
                  ?>
                  <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>" class="pic">
                    <img alt="" title="" width='88' height='96'  src='<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');?>' />
                  </a>
                <?php } ?>
               
                  <p class="title" title="<?php echo $desc; ?>">    
                      <?php
                      if (!empty($entity['field_photo_see_pic_link_value'])) {
                        echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                      }
                      ?>
                      <?php
                      if (function_exists('itg_common_get_smiley_title')) {
                        echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 90), "node/" . $nid, array("html" => TRUE));
                      }
                      else {
                        echo l(mb_strimwidth(ucfirst($desc), 0, 100, ".."), "node/" . $nid);
                      }
                      ?>
                  </span>
              </li>
              <?php
            }
          }
          ?>
      </ul>
  </div>
</div>
