<?php
$ipl_link = "";

$cat_flag = FALSE;
if (isset($_GET['section']) && !empty($_GET['section'])) {
  $cat_id = $_GET['section'];
  $cat_flag = TRUE;
}
else if (isset($node_load->field_page_section['und'][0]['tid']) && $node_load->field_page_section['und'][0]['tid'] == variable_get('ipl_for_widget')) {
  $cat_id = variable_get('ipl_for_widget');
  drupal_add_js('jQuery(document).ready(function() {                  
                           jQuery(".live-tv").click(function(){

                   window.location.href=jQuery("#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3)").find("a").attr("href");
                      });
          });' , array('type' => 'inline' , 'scope' => 'footer'));

  $ipl_link = "<button class='live-tv'><i class='fa fa-circle'></i> LIVE TV</button>";
  $cat_flag = TRUE;
}
else if (arg(0) == 'photo-list' || arg(0) == 'video-list') {
  $cat_id = variable_get('ipl_for_widget');
  $ipl_link = "<button class='live-tv'><i class='fa fa-circle'></i> LIVE TV</button>";
  $cat_flag = TRUE;
}
else if ($cat_flag == FALSE) {
  $cat_id = arg(2);
}
if ($cat_id == variable_get('ipl_for_widget') && isset($cat_id)) {
  drupal_add_js('jQuery(document).ready(function() {                  
                        jQuery("body").addClass("section-sport-ipl-bg");
                        
                        jQuery("#block-itg-ads-ad-right-sidebar-1").hide();
                       
          });' , array('type' => 'inline' , 'scope' => 'footer'));
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
              <div class="col-md-3 col-sm-3 col-xs-6">
                  <?php
                  if (!empty($src) && isset($uri)) {
                    print l("<img src='" . $src . "' />" , "taxonomy/term/" . arg(2) , array("html" => TRUE));
                  }
                  ?>
              </div>
              <div class="col-md-9 col-sm-9 col-xs-6">
                  <?php if (!empty($data)) : ?>
                    <div class="select-menu"><?php echo t("Section") ?></div>
                    <ul class="third-level-menu">
                        <?php foreach ($data as $key => $menu_data) : ?>
                          <?php
                          if (function_exists('itg_menu_manager_get_menu')) {
                            // Logic to exclude inactive category.
                            if (!empty($menu_data['term_load'])) {
                              $category_manager_tid = $menu_data['term_load']->tid;
                              $term_state = itg_category_manager_term_state($category_manager_tid);
                              if ($term_state == 0) {
                                continue;
                              }
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
                            ?>
                            <li <?php echo $style_tag; ?> class="<?php print $image_class; ?>"><?php print l($link_text , $link_url , array('html' => true , 'attributes' => array('style' => array("background : $color_value" ),  'target' => $target , 'class' => array("third-level-child" , "third-level-child-$key" , $active , $image_class , $url_type)))); ?></li>
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