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
          });', array('type' => 'inline', 'scope' => 'footer'));
    
    $ipl_link = "<button class='live-tv'><i class='fa fa-circle'></i> LIVE TV</button>";
    $cat_flag = TRUE;
}else if (arg(0)=='photo-list' || arg(0)=='video-list') {
    $cat_id = variable_get('ipl_for_widget');
     $ipl_link = "<button class='live-tv'><i class='fa fa-circle'></i> LIVE TV</button>";
    $cat_flag = TRUE;
  }
else if ($cat_flag == FALSE) {
  $cat_id = arg(2);
}
if($cat_id==variable_get('ipl_for_widget'))
{
    drupal_add_js('jQuery(document).ready(function() {                  
                        jQuery("body").addClass("section-sport-ipl-bg");
          });', array('type' => 'inline', 'scope' => 'footer'));
    
}

if($cat_id=="")
{
   $node = itg_videogallery_get_term(arg(1));
   
   if(in_array(variable_get('ipl_for_widget'), $node))
   {
   $cat_id=variable_get('ipl_for_widget');
   }  
}

$section_banner_data = taxonomy_term_load($cat_id);
$uri = $section_banner_data->field_cm_category_banner['und'][0]['uri'];
$src = file_create_url($uri);
$field_cm_category_color = ($section_banner_data->field_cm_category_color['und'][0]['rgb']) ? $section_banner_data->field_cm_category_color['und'][0]['rgb'] : "#595959";
?>
 <?php if(!empty($data[0]['db_data']) || (!empty($src) && isset($uri)))
        {?>
<div class="menu-wrapper" style="background: <?php print $field_cm_category_color; ?>">
  <div class="container">
    <div class="row">
      <div class="col-md-4">
        <?php
        if (!empty($src) && isset($uri)) {
          print "<img src='" . $src . "'>";
        }
        ?>
      </div>
        
       
      <div class="col-md-8">
          <?php
          if(!empty($ipl_link) && strlen($ipl_link)>0) {
              print $ipl_link;
          }
        ?>
        <ul class="third-level-menu">
          <?php foreach ($data as $key => $menu_data) : ?>
            <?php            
            $link_url = "";
            $target = "_self";
            $link_text = isset($menu_data['term_load']->name) ? $menu_data['term_load']->name : $menu_data['db_data']['title'];
            $url_type = $menu_data['db_data']['url_type'];
            $db_target = $menu_data['db_data']['target'];
            $tid = $menu_data['db_data']['tid'];
            // if tid is not 0 then its internal url
            if ($tid && $url_type == 'internal') {
              $link_url = "taxonomy/term/$tid";
            }
            else {
              $link_url = $menu_data['db_data']['url'];
            }
            // manage target
            if (trim($db_target) == 'new_window') {
              $target = "_blank";
            }
            $active='';
            if(end(explode('/',$link_url)) ==  arg(1)){
                $active='active';
            }
            
            ?>
            <li class="<?php echo $active;?>"><?php print l($link_text, $link_url, array('attributes' => array('target' => $target, 'class' => array("third-level-child", "third-level-child-$key")))); ?></li>
          <?php endforeach; ?>
        </ul>
      </div>
        
    </div>
  </div>
</div>
<?php } ?>