<?php
$data_tb_region_item = '';
if(drupal_is_front_page()){
  $data_tb_region_item = 'data-tb-region-item';  
}else if(isset($_GET['is_home_front']) && $_GET['is_home_front']){
  $data_tb_region_item = 'data-tb-region-item';  
}
global $base_url;
if ($widget_style == 'auto-road-trip') {
  ?>
  <div class="auto-road-trip">
      <ul class="trending-videos">
          <?php
          if (!empty($data)) {

            foreach ($data as $count => $entity) {

              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $nid = $entity['nid'];
              $desc = $entity['title'];
              ?>
              <li <?php echo $data_tb_region_item;?> class="trending-videos-list">
                  <?php
                  if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                    $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                  }
                  ?>

                  <?php if (!empty($extra_large_image_url)) { ?>
                    <a class="pic <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                        <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" />
                    </a>
                    <?php
                  }
                  else {
                    ?>
                    <a class="pic <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                        <img  height="66" width="88" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg'); ?>" alt="" />
                    </a>
                  <?php }
                  ?>

                  <span title = "<?php echo strip_tags($desc); ?>">
                      <?php
                      if (!empty($entity['field_photo_see_pic_link_value'])) {
                        echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                      }
                      ?>
                      <?php
                      if (function_exists('itg_common_get_smiley_title')) {
                        echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 55), "node/" . $nid, array("html" => TRUE));
                      }
                      else {
                        echo l(mb_strimwidth(strip_tags($desc), 0, 55, ".."), "node/" . $nid);
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
  <?php
}
else if ($widget_style == 'auto-tips-and-tricks' || $widget_style == 'edu-tips-and-trick') {
  ?>
  <div class="auto-tips-n-tricks">
      <ul>
          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = "";
              $nid = $entity['nid'];

              if (!empty($entity['field_story_kicker_text_value'])) {
                $desc = $entity['field_story_kicker_text_value'];
              }
              ?><li <?php echo $data_tb_region_item;?>>
                  <p class="title" title = "<?php echo strip_tags($entity['title']); ?>">
                      <?php
                      if (!empty($entity['field_photo_see_pic_link_value'])) {
                        echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                      }
                      ?>
                      <?php
                      if (function_exists('itg_common_get_smiley_title')) {
                        echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 125), "node/" . $nid, array("html" => TRUE));
                      }
                      else {
                        echo l(ucfirst($entity['title']), "node/" . $nid);
                      }
                      ?>
                  </p>

                  <p title = "<?php echo strip_tags($entity['title']); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 150, ".."); ?></p>
              </li>


              <?php
            }
          }
          ?>
      </ul>
  </div>


  <?php
}
else if ($widget_style == 'buying-guid') {
  ?>
  <div class="row buying-guides">
      <div class="col-md-6 col-sm-6">
          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {

              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $nid = $entity['nid'];
              $desc = $entity['title'];

              if ((!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
                $extra_large_image_url = image_style_url("anchors_landing", $entity['mi_file_uri']);
              }
              else {
                $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
              }


              if ($count == 0) {
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>" />
                </a>
                <h3 title="<?php echo $desc; ?>">
                    <?php
                    if (!empty($entity['field_photo_see_pic_link_value'])) {
                      echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                    }
                    ?>
                    <?php
                    if (function_exists('itg_common_get_smiley_title')) {
                      echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 255), "node/" . $nid, array("html" => TRUE));
                    }
                    else {
                      echo l(mb_strimwidth(ucfirst($desc), 0, 255, ".."), "node/" . $nid);
                    }
                    ?>
                </h3>
                </div>
                <?php
              }
              else if ($count == 1) {
                $title = $entity['title'];
                if ($entity['field_story_kicker_text_value'] != "") {
                  $kicker = strip_tags($entity['field_story_kicker_text_value']);
                }
                ?>
                <ul>
                    <li <?php echo $data_tb_region_item;?>>
                        <span class="title" title="<?php //echo $kicker; ?>"><?php //echo l(mb_strimwidth(ucfirst($kicker), 0, 55, ".."), "node/" . $nid); ?></span>
                        <p title="<?php echo $desc; ?>">
                            <?php echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 100, ".."), "node/" . $nid); ?>
                        </p>
                    </li>            
                </ul>
                <?php
              }
            }
          }
          ?>

      </div>

      <div class="col-md-6 col-sm-6">

          <ul>

              <?php
              if (!empty($data)) {
                foreach ($data as $count => $entity) {
                  $nid = $entity['nid'];
                  $desc = $entity['title'];
                  
                  if ($entity['field_story_kicker_text_value'] != "") {
                    $kicker = strip_tags($entity['field_story_kicker_text_value']);
                  }
                  if ($count > 1) {
                    ?>

                    <li <?php echo $data_tb_region_item;?>>
                        <span class="title" title="<?php //echo $kicker; ?>">
                            <?php
                            if (!empty($entity['field_photo_see_pic_link_value'])) {
                              echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                            }
                            ?>
                            <?php //echo l(mb_strimwidth(ucfirst($kicker), 0, 55, ".."), "node/" . $nid); ?>
                           
                        </span>
                        <p title="<?php echo $desc; ?>">
                             <?php
                            if (function_exists('itg_common_get_smiley_title')) {
                              echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 90), "node/" . $nid, array("html" => TRUE));
                            }
                            else {
                              echo l(mb_strimwidth(ucfirst($desc), 0, 100, ".."), "node/" . $nid);
                            }
                            ?>
                            
                        </p>
                    </li>   
                    <?php
                  }
                }
              }
              ?>


          </ul>

      </div>

  </div>


  <?php
}
else if ($widget_style == 'in-depth') {
  ?>
  <div class="row buying-guides tech-in-depth">
      <div class="col-md-6 col-sm-6">
          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $nid = $entity['nid'];
              $desc = $entity['title'];

              if ($count == 0) {
                if ((!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
                  $extra_large_image_url = image_style_url("anchors_landing", $entity['mi_file_uri']);
                }
                else {
                  $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
                }
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>"/> </a></span>

                <h3 title="<?php echo $desc; ?>">
                    <?php
                    if (!empty($entity['field_photo_see_pic_link_value'])) {
                      echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                    }
                    ?>
                    <?php
                    if (function_exists('itg_common_get_smiley_title')) {
                      echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 255), "node/" . $nid, array("html" => TRUE));
                    }
                    else {
                      echo l(mb_strimwidth(ucfirst($desc), 0, 255, ".."), "node/" . $nid);
                    }
                    ?>
                </h3>
                </div>
                <?php
              }
              else if ($count == 1) {
                if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                  $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                }
                else {
                  $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                }
                ?>
                <ul>
                    <li <?php echo $data_tb_region_item;?>>
                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                                <img  height="66" width="88" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" />
                            </a></span>

                        <p  title="<?php echo $desc; ?>">
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
                              echo l(mb_strimwidth(ucfirst($desc), 0, 70, ".."), "node/" . $nid);
                            }
                            ?>
                        </p>
                    </li>            
                </ul>
                <?php
              }
            }
          }
          ?>

      </div>

      <div class="col-md-6 col-sm-6">

          <ul>

              <?php
              if (!empty($data)) {
                foreach ($data as $count => $entity) {
                  $desc = $entity['title'];
                  $nid = $entity['nid'];
                  if ($count > 1) {
                    if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                      $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                    }
                    else {
                      $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                    }
                    ?>

                    <li <?php echo $data_tb_region_item;?>>
                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                                <img  height="66" width="88" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>"/>
                            </a></span>  

                        <p title="<?php echo $desc; ?>">
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
                        </p>
                    </li>   
                    <?php
                  }
                }
              }
              ?>


          </ul>

      </div>

  </div>


  <?php
}
else if ($widget_style == 'movies-celebrities') {
  ?>
  <div class="row buying-guides tech-in-depth">
      <div class="col-md-6 col-sm-6">
          <?php
          if (!empty($data)) {
            $movie_cnt=1;
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $nid = $entity['nid'];
              $desc = $entity['title'];

              if ($count == 0) {
                if ((!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
                  $extra_large_image_url = image_style_url("anchors_landing", $entity['mi_file_uri']);
                }
                else {
                  $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
                }
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>" /> </a>

                <h3 title="<?php echo $desc; ?>">
                    <?php
                    if (!empty($entity['field_photo_see_pic_link_value'])) {
                      echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                    }
                    ?>
                    <?php
                    if (function_exists('itg_common_get_smiley_title')) {
                      echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 255), "node/" . $nid, array("html" => TRUE));
                    }
                    else {
                      echo l(mb_strimwidth(ucfirst($desc), 0, 255, ".."), "node/" . $nid);
                    }
                    ?>
                </h3>
                </div>
                <?php
              }
              else if ($count == 1) {
              print "<ul class='moviesinglelist'>";  
              
              if ((!empty($entity['esi_file_uri']) && file_exists($entity['esi_file_uri']))) {
                $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
              }
              else {
                $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
              }
              ?>
                <li <?php echo $data_tb_region_item;?> title="<?php echo $desc; ?>">
                    <span class="pic  <?php echo $video_class; ?>"> 
                        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                                <img  height="66" width="88" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>"/>
                            </a>
                    </span> 
                    <p title="<?php echo $desc; ?>">
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
                        </p> 
                    
                </li>
                <?php
                    print "</ul>";  
              }
            }
          }
          ?>

      </div>

      <div class="col-md-6 col-sm-6">

          <ul>

              <?php
              if (!empty($data)) {
                foreach ($data as $count => $entity) {
                  $desc = $entity['title'];
                  $nid = $entity['nid'];
                  if ($count > 2) {
                    if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                      $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                    }
                    else {
                      $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                    }
                    ?>

                    <li <?php echo $data_tb_region_item;?>>
                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                                <img  height="66" width="88" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>"/>
                            </a></span>  

                        <p title="<?php echo $desc; ?>">
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
                        </p>
                    </li>   
                    <?php
                  }
                }
              }
              ?>


          </ul>

      </div>

  </div>


  <?php
}
else if ($widget_style == 'movies-lifestyle') {
  ?>
  <div class="row buying-guides tech-in-depth">
      <div class="col-md-6 col-sm-6 section-ordering">
          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];

              if ($count == 0) {
                if ((!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
                  $extra_large_image_url = image_style_url("anchors_landing", $entity['mi_file_uri']);
                }
                else {
                  $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
                }
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>"/> </a>

                <h3 title="<?php echo $desc; ?>">
                    <?php
                    if (!empty($entity['field_photo_see_pic_link_value'])) {
                      echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                    }
                    ?>
                    <?php
                    if (function_exists('itg_common_get_smiley_title')) {
                      echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 255), "node/" . $nid, array("html" => TRUE));
                    }
                    else {
                      echo l(mb_strimwidth(ucfirst($desc), 0, 255, ".."), "node/" . $nid);
                    }
                    ?>
                </h3>
                </div>
                <?php
              }
              else if ($count == 1 || $count == 2) {
                ?>

                <p <?php echo $data_tb_region_item;?> title="<?php echo $desc; ?>">
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
                </p>

                <?php
              }
            }
          }
          ?>

      </div>

      <div class="col-md-6 col-sm-6">

          <ul>

              <?php
              if (!empty($data)) {
                foreach ($data as $count => $entity) {
                  $desc = $entity['title'];
                  $nid = $entity['nid'];
                  if ($count > 2) {
                    if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                      $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                    }
                    else {
                      $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                    }
                    ?>

                    <li <?php echo $data_tb_region_item;?>>
                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                                <img  height="66" width="88" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" />
                            </a></span>  

                        <p title="<?php echo $desc; ?>">
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
                        </p>
                    </li>   
                    <?php
                  }
                }
              }
              ?>


          </ul>

      </div>

  </div>


  <?php
}
else if ($widget_style == 'oscar-news') {
  ?>
  <div class="oscar-news">
      <div class="row">
          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];
              if ($count == 0) {
                if ((!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
                  $extra_large_image_url = image_style_url("anchors_landing", $entity['mi_file_uri']);
                }
                else {
                  $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
                }
                ?>
                <div class="col-md-12" <?php echo $data_tb_region_item;?>>
                    <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                        <span class="pic  <?php echo $video_class; ?>">
                            <img src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>" /></span>
                    </a>
                    <h3 title="<?php echo $desc; ?>">
                        <?php
                        if (!empty($entity['field_photo_see_pic_link_value'])) {
                          echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                        }
                        ?>
                        <?php
                        if (function_exists('itg_common_get_smiley_title')) {
                          echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 255), "node/" . $nid, array("html" => TRUE));
                        }
                        else {
                          echo l(mb_strimwidth(ucfirst($desc), 0, 255, ".."), "node/" . $nid);
                        }
                        ?>
                    </h3>
                </div>
                <?php
              }
              else if ($count > 0) {
                if ((!empty($entity['si_file_uri']) && isset($entity['si_file_uri']))) {
                  $extra_large_image_url = image_style_url("widget_small", $entity['si_file_uri']);
                }
                else {
                  $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');
                }
                ?>
                <div class="col-md-6 col-sm-3 col-xs-6">                   
                    <span class="pic  <?php echo $video_class; ?>"> <a class="pic  <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                            <img  height="127" width="170" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_small_image_alt']; ?>" title="<?php echo $entity['field_story_small_image_title']; ?>" />
                        </a></span>

                    <p <?php echo $data_tb_region_item;?> title="<?php echo $desc; ?>">
                        <?php
                        if (!empty($entity['field_photo_see_pic_link_value'])) {
                          echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                        }
                        ?>
                        <?php
                        if (function_exists('itg_common_get_smiley_title')) {
                          echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 50), "node/" . $nid, array("html" => TRUE));
                        }
                        else {
                          echo l(mb_strimwidth(ucfirst($desc), 0, 60, ".."), "node/" . $nid);
                        }
                        ?>
                    </p>                      
                </div>
                <?php
              }
            }
          }
          ?>

      </div>



  </div>


  <?php
}
else if ($widget_style == 'standpoint') {
  print '<div class="tech-block_5"><div class="flexslider">
      <ul class="slides"> ';
  foreach ($data as $count => $entity) {
    $video_class = "pic-no-icon";
    if (strtolower($entity['type']) == 'videogallery') {
      $video_class = 'video-icon';
    }
    $desc = $entity['title'];
    $nid = $entity['nid'];
    drupal_add_library('flexslider', 'flexslider');
    libraries_load('flexslider');
    module_load_include('inc', 'itg_widget', 'includes/featured_photo_carousel');
    if ((!empty($entity['uri']) && isset($entity['uri']))) {
      $extra_large_image_url = image_style_url("section_ordering_widget", $entity['uri']);
    }
    else {
      $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
    }
    ?>

    <li <?php echo $data_tb_region_item;?>> <img  src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_large_image_alt']; ?>" title="<?php echo $entity['field_story_extra_large_image_title']; ?>" />

        <div class="detail">
            <p class="flex-caption" title="<?php echo $desc; ?>">
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
            </p>
        </div>

    </li>



  <?php }
  ?>
  </ul>
  </div>
  </div>

  <?php
}
else if ($widget_style == 'oscar-features') {
  ?>
  <div class="row oscar-features">

      <?php
      $coun = 1;
      if (!empty($data)) {
        foreach ($data as $count => $entity) {
          $video_class = "pic-no-icon";
          if (strtolower($entity['type']) == 'videogallery') {
            $video_class = 'video-icon';
          }
          $desc = $entity['title'];
          $nid = $entity['nid'];
          if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
            $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
          }
          else {
            $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
          }
          ?>
          <div class="col-md-6 col-sm-6 col-xs-12">
              <span> <a <?php echo $video_class; ?> href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                      <img  height="66" width="88" src="<?php echo $extra_large_image_url; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" />
                  </a></span>

              <p <?php echo $data_tb_region_item;?> title="<?php echo $desc; ?>">
                  <?php
                  if (!empty($entity['field_photo_see_pic_link_value'])) {
                    echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                  }
                  ?>
                  <?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 70), "node/" . $nid, array("html" => TRUE));
                  }
                  else {
                    echo l(mb_strimwidth(ucfirst($desc), 0, 80, ".."), "node/" . $nid);
                  }
                  ?>
              </p>
          </div>
          <?php
          $coun++;
        }
      }
      ?>


  </div>


  <?php
}
else if ($widget_style == 'tech-tips' || $widget_style == 'india-inc-on-budget' || $widget_style == 'budget-reactions' || $widget_style == 'election-other-story') {
  ?>

  <div class="tech-trip">
      <ul class="trending-videos">

          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];
              ?>
              <li <?php echo $data_tb_region_item;?> class="trending-videos-list">
                  <?php
                  if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                    $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                  }
                  else {
                    $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                  }
                  ?>

                  <?php if (!empty($extra_large_image_url)) { ?>

                    <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">  
                            <img  height="66" width="88"  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" /> </a></span>

                  <?php }
                  ?>

                  <span class="detail" title="<?php echo $desc; ?>"> 
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

  <?php
}
else if ($widget_style == 'home-shows') {
  ?>

  <div class="tech-trip home-shows">
      <ul class="trending-videos">

          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];
              ?>
              <li <?php echo $data_tb_region_item;?> class="trending-videos-list">
                  <?php
                  if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                    $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                  }
                  else {
                    $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                  }
                  ?>

                  <?php if (!empty($extra_large_image_url)) { ?>

                    <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">  
                            <img  height="66" width="88" src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" /> </a></span>

                  <?php }
                  ?>

                  <span title="<?php echo $desc; ?>">
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

  <?php
}
else if ($widget_style == 'home-watch') {
  ?>

  <div class="tech-trip osscar-video">
      <div class="home-watch-new">
          <ul class="">
              <?php
              if (!empty($data)) {
                foreach ($data as $count => $entity) {

                  $video_class = "pic-no-icon";
                  if (strtolower($entity['type']) == 'videogallery') {
                    $video_class = 'video-icon';
                  }
                  $desc = $entity['title'];
                  $nid = $entity['nid'];
                  ?>
                  <li <?php echo $data_tb_region_item;?> class="dont-miss-listing">

                      <?php
                      if ((!empty($entity['si_file_uri']) && file_exists($entity['si_file_uri']))) {
                        $extra_large_image_url = image_style_url("image170x127", $entity['si_file_uri']);
                      }
                      else {
                        $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');
                      }
                      ?>

                      <?php if (!empty($extra_large_image_url)) { ?>

                        <span class="dm-pic"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">  
                                <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_small_image_alt']; ?>" title="<?php echo $entity['field_story_small_image_title']; ?>" /> </a> <span><i class="fa fa-play-circle"></i> <?php echo $entity['field_video_duration_value']; ?></span></span>

                      <?php }
                      ?>

                      <span class="dm-detail" title="<?php echo $desc; ?>">
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
      </div></div>

  <?php
}
else if ($widget_style == 'budget-decoded') {
  ?>

  <div class="tech-trip">
      <ul class="slider-budget">
          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];
              ?>
              <li <?php echo $data_tb_region_item;?>>
                  <?php
                  if ((!empty($entity['esi_file_uri']) && isset($entity['si_file_uri']))) {
                    $extra_large_image_url = image_style_url("anchors_landing", $entity['si_file_uri']);
                  }
                  else {
                    $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');
                  }
                  ?>

                  <?php if (!empty($extra_large_image_url)) { ?>

                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>"> 
                        <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" /></a>

                  <?php }
                  ?>

                  <h3 title="<?php echo $desc; ?>">
                      <?php
                      if (!empty($entity['field_photo_see_pic_link_value'])) {
                        echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                      }
                      ?>
                      <?php
                      if (function_exists('itg_common_get_smiley_title')) {
                        echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 55), "node/" . $nid, array("html" => TRUE));
                      }
                      else {
                        echo l(mb_strimwidth(ucfirst($desc), 0, 65, ".."), "node/" . $nid);
                      }
                      ?>
                  </h3>
              </li>
              <?php
            }
          }
          ?>
      </ul>
  </div>        

  <?php
}
else if ($widget_style == 'sport-column') {
  ?>

  <div class="tech-trip">
      <ul class="trending-videos">

          <?php
          if (!empty($data)) {
            foreach ($data as $count => $entity) {
              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $desc = $entity['title'];
              $nid = $entity['nid'];
              ?>
              <li <?php echo $data_tb_region_item;?> class="trending-videos-list">
                  <?php
                  if ((!empty($entity['esi_file_uri']) && isset($entity['esi_file_uri']))) {
                    $extra_large_image_url = image_style_url("widget_very_small", $entity['esi_file_uri']);
                  }
                  ?>

                  <?php if (!empty($extra_large_image_url)) { ?>

                    <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>"> 
                            <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" /> </a></span>

                    <?php
                  }
                  else {
                    ?>
                    <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">  <img  height="66" width="88" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg'); ?>" alt="<?php echo $entity['field_story_extra_small_image_alt']; ?>" title="<?php echo $entity['field_story_extra_small_image_title']; ?>" /> </a></span>

                  <?php }
                  ?>


                  <span title="<?php echo $desc; ?>">
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

  <?php
}
else if ($widget_style == 'election-so-sorry') {
  ?>

  <?php if (!empty($data)) : global $base_url; ?>
    <div class="section-ordering">
        <?php
        if (!empty($data)) {
          $extra_large_image_url = "";
          foreach ($data as $count => $entity) {
            if (strtolower($entity['type']) == 'videogallery') {
              $video_class = 'video-icon';
            }
            $desc = $entity['title'];
            $nid = $entity['nid'];
            if ($count == 0 && (!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
              $extra_large_image_url = image_style_url("section_ordering_widget", $entity['mi_file_uri']);
            }
            ?>
            <?php if ($count == 0) : ?>
              <?php if (!empty($extra_large_image_url)) { ?>
                <div <?php echo $data_tb_region_item;?>>  
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>" />
                </a>
                <?php
              }
              else {
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img  height="208" width="370" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg'); ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>" />
                </a>
              <?php } ?>
              <h3 title="<?php echo $entity['title']; ?>" class="frist-heading heading-<?php echo $nid ?> <?php echo $entity['title'] ?> ">
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
                    echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid);
                  }
                  ?>
              </h3>
              </div>
            <?php endif; ?>

            <?php
          }
        }
        ?>
    </div>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  <?php endif; ?>

  <?php
}
else if ($widget_style == 'talking-point') {
  ?>

  <div class="tech-trip">
      <ul class="trending-videos">

          <?php
          if (!empty($data)) {

            foreach ($data as $count => $entity) {
              $reporter = "";
              $extra_large_image_url = "";
              $video_class = "pic-no-icon";
              if (isset($entity->type) && strtolower($entity->type) == 'videogallery') {
                $video_class = 'video-icon';
              }
              $nid = $entity['nid'];
              $desc = $entity['title'];
              $node_data = node_load($entity['nid']);
              ?>
              <li <?php echo $data_tb_region_item;?> class="trending-videos-list">
                  <?php
                  if ($node_data->field_reporter_publish_id['und'][0]['value'] != "") {
                    $reporter = node_load($node_data->field_reporter_publish_id['und'][0]['value']);
                  }

                  if ((!empty($node_data->field_story_extra_large_image['und'][0]['uri']) && isset($node_data->field_story_extra_large_image['und'][0]['uri']))) {
                    $extra_large_image_url = image_style_url("widget_very_small", $node_data->field_story_extra_large_image['und'][0]['uri']);
                  }
                  else {
                    $extra_large_image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg');
                  }
                  ?>

                  <?php if (!empty($extra_large_image_url)) { ?>

                    <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>"> <img  src="<?php print $extra_large_image_url ?>" alt="" title="" /> </a></span>

                    <?php
                  }
                  else {
                    ?>
                    <span class="pic <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">   <img width="88" height="66" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg'); ?>" alt="" title="" /></a></span>

                  <?php }
                  ?>
                  <?php
                  if (isset($reporter->title) && $reporter->title != "") {
                    print '<h4 title="' . $reporter->title . '">' . ucfirst(mb_strimwidth($reporter->title, 0, 50, "..")) . '</h4>';
                  }
                  ?>
                  <span title="<?php echo $desc; ?>">
                      <?php
                      if (!empty($entity['field_photo_see_pic_link_value'])) {
                        echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                      }
                      ?>
                      <?php
                      if (function_exists('itg_common_get_smiley_title')) {
                        echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 60), "node/" . $nid, array("html" => TRUE));
                      }
                      else {
                        echo l(mb_strimwidth($desc, 0, 70, ".."), "node/" . $nid);
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

  <?php
}
else if ($widget_style == 'edu-exam' || $widget_style == 'edu-gov-jobs') {
  ?>

  <?php if (!empty($data)) : global $base_url; ?>
    <div class="section-ordering">
        <?php
        if (!empty($data)) {
          $extra_large_image_url = "";
          foreach ($data as $count => $entity) {
            $desc = $entity['title'];
            $nid = $entity['nid'];
            if ($count == 0 && (!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
              $extra_large_image_url = image_style_url("section_ordering_widget", $entity['mi_file_uri']);
            }

            $video_class = "pic-no-icon";
            if (strtolower($entity['type']) == 'videogallery') {
              $video_class = 'video-icon';
            }
            ?>
            <?php if ($count == 0) : ?>
              <?php if (!empty($extra_large_image_url)) { ?>
                <div <?php echo $data_tb_region_item;?>>  
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>"/>
                </a>
                <?php
              }
              else {
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img height="208" width="370" src="<?php print image_style_url("anchors_landing", drupal_get_path('theme', 'itg') . '/images/itg_image370x208.jpg'); ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>"/>
                </a>
              <?php } ?>
              <h3 title="<?php echo $entity['title']; ?>" class="frist-heading heading-<?php echo $nid ?> <?php echo $entity['type'] ?> ">
                  <?php echo l($entity['title'] , "node/" . $nid); ?>
              </h3>
              </div>
            <?php endif; ?>
            <?php if ($count != 0) : ?>
              <p title="<?php echo $entity['title']; ?>" class="<?php print $entity['type'] ?> section-order-<?php print $nid ?>">
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
                    echo l(mb_strimwidth($entity['title'], 0, 100, ".."), "node/" . $nid);
                  }
                  ?>
              </p>
            <?php endif; ?>
            <?php
          }
        }
        ?>
    </div>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  <?php endif; ?>

<?php } else if ($widget_style == 'edu-notification' || $widget_style == 'edu-featurefilia' || $widget_style == 'edu-jobs-and-career' || $widget_style == 'edu-sample-paper') { ?>

  <?php if (!empty($data)) : global $base_url; ?>
    <div class="section-ordering">
        <?php
        if (!empty($data)) {
          $extra_large_image_url = "";
          foreach ($data as $count => $entity) {
            $desc = $entity['title'];
            $nid = $entity['nid'];
            ?>


            <p <?php echo $data_tb_region_item;?> title="<?php echo $desc; ?>" class="<?php print $entity['type'] ?> section-order-<?php print $entity['nid'] ?>">
                <?php
                if (!empty($entity['field_photo_see_pic_link_value'])) {
                  echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                }
                ?>
                <?php echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 100), "node/" . $nid, array('html' => TRUE)); ?>
            </p>

            <?php
          }
        }
        ?>
    </div>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  <?php endif; ?>

<?php } else if ($widget_style == 'edu-from-the-magazine') { ?>

  <?php if (!empty($data)) : global $base_url; ?>
    <div class="from-the-magazine">

        <?php
        if (!empty($data)) {
          $extra_large_image_url = "";
          foreach ($data as $count => $entity) {
            $desc = "";
            $nid = $entity['nid'];
            if ($count == 0 && (!empty($entity['uri']) && isset($entity['uri']))) {
              $extra_large_image_url = image_style_url("magazine_rhs_100x140", $entity['uri']);
              if (!empty($entity['field_story_kicker_text_value'])) {
                $desc = $entity['field_story_kicker_text_value'];
              }

              $video_class = "pic-no-icon";
              if (strtolower($entity['type']) == 'videogallery') {
                $video_class = 'video-icon';
              }
            }
            ?>
            <?php if ($count == 0) : ?>
              <div class="magazine-detail" <?php echo $data_tb_region_item;?>>

                  <?php if (!empty($extra_large_image_url)) { ?>
                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                        <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_extra_large_image_alt']; ?>" title="<?php echo $entity['field_story_extra_large_image_title']; ?>" />
                    </a>
                    <?php
                  }
                  else {
                    ?>
                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                        <img class="defalt-placeholder-magazin"  height="140" width="100" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg'); ?>" alt="" title="" />
                    </a>
                  <?php } ?>
                  <div class="small-detail">
                      <h3 title="<?php echo $entity['title']; ?>" class="frist-heading heading-<?php echo $nid ?> <?php echo $entity['type'] ?> ">
                          <?php
                          if (!empty($entity['field_photo_see_pic_link_value'])) {
                            echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                          }
                          ?>
                          <?php
                          if (function_exists('itg_common_get_smiley_title')) {
                            echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 45), "node/" . $nid, array("html" => TRUE));
                          }
                          else {
                            echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid);
                          }
                          ?>
                      </h3>
                      <p title="<?php echo $desc; ?>">
                          <?php
                          if (!empty($entity['field_photo_see_pic_link_value'])) {
                            echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                          }
                          ?>
                          <?php
                          if ($entity['field_story_kicker_text_value'] != "") {
                            echo l($entity['field_story_kicker_text_value'], "node/" . $nid, array("html" => TRUE));
                          }
                          else {
                            echo l(mb_strimwidth($desc, 0, 80, ".."), "node/" . $nid);
                          }
                          ?>
                      </p>
                  </div>
              </div>

            <?php endif; ?>
            <?php if ($count != 0) : ?>
              <p <?php echo $data_tb_region_item;?> title="<?php echo $entity['title']; ?>" class="<?php print $entity['type'] ?> section-order-<?php print $nid ?>">
                  <?php
                  if (!empty($entity['field_photo_see_pic_link_value'])) {
                    echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                  }
                  ?>
                  <?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 25), "node/" . $nid, array("html" => TRUE));
                  }
                  else {
                    echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid);
                  }
                  ?>
              </p>
            <?php endif; ?>
            <?php
          }
        }
        ?>
    </div>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  <?php endif; ?>

<?php } else if ($widget_style == 'news-section') { ?>
  <?php if (!empty($data)) : global $base_url; ?>
    <div class="section-ordering" data-id="<?php print $widget_style; ?>" id="card_<?php print $itg_section_id; ?>_<?php print $block_id; ?>">
        <!--      <div class="itg-ajax-loader">
            loader...
          </div>-->
        <?php
        if (!empty($data)) {
          $extra_large_image_url = "";
          foreach ($data as $count => $entity) {
            $nid = $entity['nid'];
            $video_class = "pic-no-icon";
            if (strtolower($entity['type']) == 'videogallery') {
              $video_class = 'video-icon';
            }
            ?>
            <?php if ($count == 0) : ?>
              <?php if (!empty($entity['field_story_kicker_text_value'])) { ?>
                <div class="kicker"><?php echo $entity['title']; ?></div>
                <?php }
              ?>              
              <h3 <?php echo $data_tb_region_item;?> title="<?php echo $entity['title']; ?>" class="frist-heading heading-<?php echo $nid ?> <?php echo $entity['type'] ?> ">
                  <?php
                  if (!empty($entity['field_photo_see_pic_link_value'])) {
                    echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                  }
                  ?>
                  <?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    echo l(itg_common_get_smiley_title($nid, 0, 45), "node/" . $nid, array("html" => TRUE));
                  }
                  else {
                    echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid);
                  }
                  ?>
              </h3>
            <?php endif; ?>
            <?php if ($count != 0) : ?>
              <p <?php echo $data_tb_region_item;?> title="<?php echo $entity['title']; ?>" class="<?php print $entity['type'] ?> section-order-<?php print $nid ?>">
                  <?php
                  if (!empty($entity['field_photo_see_pic_link_value'])) {
                    echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                  }
                  ?>
                  <?php if ($entity['is_spnoser']): ?>
                    <span class="itg-sponsor-section-title"><?php print t('IMPACT FEATURE'); ?></span>
                  <?php endif; ?>
                  <?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    echo l(itg_common_get_smiley_title($nid, 0, 90), "node/" . $nid, array("html" => TRUE));
                  }
                  else {
                    echo l(mb_strimwidth($entity['title'], 0, 100, ".."), "node/" . $nid);
                  }
                  ?>
              </p>
            <?php endif; ?>
          <?php
          }
        }
        ?>
    </div>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  <?php endif; ?>

<?php } else {
  ?>
  <?php if (!empty($data)) : global $base_url; ?>
    <div class="section-ordering" data-id="<?php print $widget_style; ?>" id="card_<?php print $itg_section_id; ?>_<?php print $block_id; ?>">
        <!--      <div class="itg-ajax-loader">
            loader...
          </div>-->
        <?php
        if (!empty($data)) {
          $extra_large_image_url = "";
          foreach ($data as $count => $entity) {
            $nid = $entity['nid'];
            $video_class = "pic-no-icon";
            if (strtolower($entity['type']) == 'videogallery') {
              $video_class = 'video-icon';
            }
            //pr($entity);
            if ($count == 0 && (!empty($entity['mi_file_uri']) && isset($entity['mi_file_uri']))) {
              // $extra_large_image_url = image_style_url("section_ordering_widget", $entity['li_file_uri']);
              $extra_large_image_url = file_create_url($entity['mi_file_uri']);
            }
            ?>
            <?php if ($count == 0) : ?>
              <?php if (!empty($extra_large_image_url)) { ?>
                <div <?php echo $data_tb_region_item;?>>  
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <!-- <img  src="<?php print $extra_large_image_url ?>" alt="<?php echo $entity['field_story_medium_image_alt']; ?>" title="<?php echo $entity['field_story_medium_image_title']; ?>" /> -->
                    <?php print theme('image', array('path' => $entity['mi_file_uri'], 'alt' => $entity['field_story_medium_image_alt'], 'title' => $entity['field_story_medium_image_title'])); ?>
                </a>
                <?php
              }
              else {
                ?>
                <div <?php echo $data_tb_region_item;?>>
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$nid"); ?>">
                    <img  height="208" width="370" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg'); ?>" alt="" title="" />
                </a>
              <?php } ?>
              <h3 title="<?php echo $entity['title']; ?>" class="frist-heading heading-<?php echo $nid ?> <?php echo $entity['type'] ?> ">
                  <?php
                  if (!empty($entity['field_photo_see_pic_link_value'])) {
                    echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                  }
                  ?>
                  <?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 45), "node/" . $nid, array("html" => TRUE));
                  }
                  else {
                    echo l(mb_strimwidth($entity['title'], 0, 55, ".."), "node/" . $nid);
                  }
                  ?>
              </h3>
              </div>
            <?php endif; ?>
            <?php if ($count != 0) : ?>
              <p <?php echo $data_tb_region_item;?> title="<?php echo $entity['title']; ?>" class="<?php print $entity['type'] ?> section-order-<?php print $nid ?>">
                  <?php
                  if (!empty($entity['field_photo_see_pic_link_value'])) {
                    echo "<span class='see-picture'>" . l($entity['field_photo_see_pic_link_value'], "node/" . $nid) . '</span>';
                  }
                  ?>
                  <?php if ($entity['is_spnoser']): ?>
                    <span class="itg-sponsor-section-title"><?php print t('IMPACT FEATURE'); ?></span>
                  <?php endif; ?>
                  <?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 90), "node/" . $nid, array("html" => TRUE));
                  }
                  else {
                    echo l(mb_strimwidth($entity['title'], 0, 100, ".."), "node/" . $nid);
                  }
                  ?>
              </p>
            <?php endif; ?>
            <?php
          }
        }
        ?>
    </div>
    <?php if (!empty($itg_section_id)): 
			$tname = get_term_name_from_tid($itg_section_id)->name;
    ?>
    <div class="morediv"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("taxonomy/term/$itg_section_id"); ?>">more from <?php echo $tname; ?> <i class="fa fa-chevron-right" aria-hidden="true"></i></a></div>
    <?php endif;?>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
  <?php endif; ?>
<?php } ?>






