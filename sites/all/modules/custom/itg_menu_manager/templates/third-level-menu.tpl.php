<?php
$ipl_link = "";

$cat_flag = FALSE;
if (isset($_GET['section']) && !empty($_GET['section'])) {
  $cat_id = $_GET['section'];
  $cat_flag = TRUE;
}
else if (isset($node_load->field_page_section['und'][0]['tid']) && $node_load->field_page_section['und'][0]['tid'] == variable_get('ipl_for_widget')) {
  $cat_id = variable_get('ipl_for_widget');
  drupal_add_js(drupal_get_path('module' , 'itg_menu_manager') . '/js/third-level-menu-live-button.js' , array('type' => 'file' , 'scope' => 'footer'));
  $ipl_link = "<button class='live-tv'><i class='fa fa-circle'></i> LIVE TV</button>";
  $cat_flag = TRUE;
}
else if (arg(0) == 'photo-list' || arg(0) == 'video-list') {
  $cat_id = variable_get('ipl_for_widget');
  $ipl_link = "<button class='live-tv'><i class='fa fa-circle'></i> LIVE TV</button>";
  $cat_flag = TRUE;
}
else if(arg(0) == 'node' &&  is_numeric(arg(1))){
  $node = menu_get_object();
  $cat_id = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
  $cat_flag = TRUE;
}
else if ($cat_flag == FALSE) {
  $cat_id = arg(2);
}
if ($cat_id == variable_get('ipl_for_widget') && isset($cat_id)) {
  drupal_add_js(drupal_get_path('module' , 'itg_menu_manager') . '/js/menu-manager-ipl-for-widget.js' , array('type' => 'file' , 'scope' => 'footer'));
}

if ($cat_id == "") {
  if (function_exists('itg_videogallery_get_term')) {
    $node = itg_videogallery_get_term(arg(1));
    if (!empty($node)) {
      if (in_array(variable_get('ipl_for_widget') , $node)) {
        $cat_id = variable_get('ipl_for_widget');
      }
    }
  }
}

if (isset($cat_id) && is_numeric($cat_id)) {
  $section_tids = array_reverse(taxonomy_get_parents_all($cat_id));
  $section_tid = $section_tids[0]->tid;
  $fifa_category_id = !empty(get_itg_variable('fifa_category_id')) ? get_itg_variable('fifa_category_id') : '';
  if(isset($fifa_category_id) && $cat_id == $fifa_category_id){
	  $cat_id = $fifa_category_id;
  }	elseif($cat_id != $section_tid) {
    $cat_id = $section_tid;
  }   
}
$section_banner_data = taxonomy_term_load($cat_id);
	
$uri = !empty($section_banner_data->field_cm_category_banner['und'][0]['uri']) ? $section_banner_data->field_cm_category_banner['und'][0]['uri'] : "";
if (!empty($uri)) {
  $src = file_create_url($uri);
}


$field_cm_category_color = isset($section_banner_data->field_cm_category_color['und'][0]['rgb']) ? $section_banner_data->field_cm_category_color['und'][0]['rgb'] : "#595959";
?>
<?php if (!empty($data[0]['db_data']) || (!empty($src) && isset($uri))) {
  ?>
  <div class="menu-wrapper" style="background: <?php print $field_cm_category_color; ?>">
      <div class="container">
          <div class="row">
              <div class="col-md-6 col-sm-9 col-xs-9">
                  <?php
                  if (!empty($src) && isset($uri)) {
                    print l("<img src='" . $src . "' alt='' title='' />" , "taxonomy/term/" . $cat_id , array("html" => TRUE));
                  }
                  ?>
              </div>
              <div class="col-md-6 col-sm-3 col-xs-3">
                  <?php if (!empty($data)) : ?>
                    <div class="select-menu"><?php echo t("Section") ?></div>
                    <ul class="third-level-menu">
                        <?php foreach ($data as $key => $menu_data) : ?>
                          <?php
                          if (function_exists('itg_menu_manager_get_menu')) {
                            // Logic to exclude inactive category.
                            if (!empty($menu_data['term_load'])) {
                              $category_manager_tid = $menu_data['term_load']->tid;
                            }
                            $menu_link_data = itg_menu_manager_get_menu($menu_data , arg());
                            $image_class = $menu_link_data['image_class'];
                            $link_text = $menu_link_data['link_text'];
                            $link_url = $menu_link_data['link_url'];
                            $target = $menu_link_data['target'];
                            $active = $menu_link_data['active'];
                            $url_type = $menu_link_data['url_type'];
                            $sponsored_class = $menu_link_data['sponsored_class'];
                            $style_tag = '';
                            $color_value = '';
                            if (!empty($sponsored_class)) {
                              $color_value = $menu_data['db_data']['bk_color'];
                            }
                            $background_color_style = ($color_value == '') ? "" : "background : $color_value";
                            
                            if($menu_link_data['url_type'] == 'url-type-external') {
                              if (strpos($link_url, $_SERVER['HTTP_HOST'])) {
                                $attribute_array = array(
                                    'style' => array( $background_color_style ),  
                                    'target' => $target,
                                    'class' => array("third-level-child" , "third-level-child-$key" , $active , $image_class , $url_type)
                                    );
                              } else {
                                $attribute_array = array(
                                    'style' => array( $background_color_style ),  
                                    'target' => $target , 
                                    'rel' => 'nofollow', 
                                    'class' => array("third-level-child" , "third-level-child-$key" , $active , $image_class , $url_type)
                                    );
                              }
                              
                            } else {
                              $attribute_array = array(
                                    'style' => array( $background_color_style ),  
                                    'target' => $target , 
                                    'class' => array("third-level-child" , "third-level-child-$key" , $active , $image_class , $url_type)
                                    );
                            }
                            
                            ?>
                            <li <?php echo $style_tag; ?> class="<?php print $image_class; ?>">
                              <?php print l($link_text , $link_url , 
                                array(
                                  'html' => true , 
                                  'attributes' => $attribute_array,
                                )
                              ); ?></li>
                            <?php
                          }
                        endforeach;
                        ?>
                    </ul>
                  <?php endif; ?>
              </div>

          </div>
      </div>
  </div>
<?php } ?>
