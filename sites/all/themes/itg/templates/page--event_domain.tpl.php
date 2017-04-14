<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 */

global $base_url;
$arg = arg();
if (!empty($arg[1]) && is_numeric($arg[1]) && $arg[0] == 'node') {
  $host_node = node_load($arg[1]);
}elseif($arg[0] == 'event' && !empty($arg[0])){
  //$path = drupal_lookup_path("source", $arg[0].'/'.$arg[1]);
  $path = drupal_lookup_path("source", $arg[1].'/'.$arg[2]);
  $host_node = menu_get_object("node", 1, $path);
  if((!empty($arg[2]) && $arg[2] == 'registration') && empty($host_node)){ // unpublish condition
    $nid = explode('/', $path);
    $host_node = node_load($nid[1]);
    
  }
}

/*$host_detail = itg_event_backend_get_redirect_record('redirect', $base_url);
if (empty($host_detail) && $arg[0] == 'event') {
  $path = drupal_lookup_path("source", $arg[0].'/'.$arg[1]);
  $host_node = menu_get_object("node", 1, $path);
} elseif(empty($host_detail) && is_numeric($arg[1])){
  $host_node = node_load($arg[1]);
} else {
  $host_node_arr = explode('/', $host_detail['source']);
  $host_node = node_load($host_node_arr[1]);
}*/
//$banner_image = $base_url.'/'.str_replace('public://', 'sites/default/files/', $host_node->field_e_event_banner[LANGUAGE_NONE][0]['uri']);
$banner_image = file_create_url($host_node->field_e_event_banner[LANGUAGE_NONE][0]['uri']);
$banner_image = $host_node->field_e_event_banner[LANGUAGE_NONE][0]['uri'] ? $banner_image : $base_url.'/'.drupal_get_path('module', 'itg_event_backend').'/event_banner.jpeg';
$menu_background_color = $host_node->field_e_menu_bck_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_menu_bck_color[LANGUAGE_NONE][0]['rgb'] : '#000';
?>
<div id="page">
  <div class="event-sidebar">
    <header class="header" id="header" role="banner">
            <section class="header-top">
                <div class="event-header-banner" style="background: url(<?php echo $banner_image; ?>) no-repeat center top">
<!--                <img src="<?php //echo $banner_image; ?>" alt="" />-->
              <div class="event-add-header">
                
              <?php 
                //print itg_event_backend_header_add_block();
               $block = block_load('itg_ads', ADS_HEADER);
               $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
               print render($render_array);
                                      
              ?>
              </div>   
              </div>
               
              <div class="container header-logo">
                <?php if ($logo): ?>
                  <div class="logo"></div>
                <?php endif; ?>                    
              </div>
                <?php if ($site_name || $site_slogan): ?>
                    <div class="header__name-and-slogan" id="name-and-slogan">
                        <?php if ($site_name): ?>
                            <h1 class="header__site-name" id="site-name">
                                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
                            </h1>
                        <?php endif; ?>
                        <?php if ($site_slogan): ?>
                            <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
                        <?php endif; ?>
                    </div>
                <?php endif; ?>
                
              <div class="event-menu" style="background: <?php print $menu_background_color; ?>"> <?php print render($page['header_event']); ?></div>
                    
            </section>
        </header>
    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second_event']);
    ?>
    <?php 
      $cls = 'col-md-12';
      if ($sidebar_first || $sidebar_second):
        $cls = 'col-md-8';
    endif; ?>
  <?php print render($page['top']); ?>
  <?php print render($page['my_cart']); ?>
  <main id="main" class="container">
    <div class="row">
    <section id="content" class="<?php echo $cls;?>" role="main">
      <?php print render($page['highlighted']); ?>
      <?php if(arg(0)!= 'user'): print $breadcrumb; ?>
      <?php endif; ?>
     
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php //print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content_event']); ?>
      <?php print render($page['content_bottom']); ?>
      <?php print render($page['personalization']); ?>
      <?php //print $feed_icons; ?>
    </section>
    <?php if (false): ?>
    <div id="navigation">

      <?php if ($main_menu): ?>
        <nav id="main-menu" role="navigation" tabindex="-1">
          <?php
          // This code snippet is hard to modify. We recommend turning off the
          // "Main menu" on your sub-theme's settings form, deleting this PHP
          // code block, and, instead, using the "Menu block" module.
          // @see https://drupal.org/project/menu_block
          print theme('links__system_main_menu', array(
            'links' => $main_menu,
            'attributes' => array(
              'class' => array('links', 'inline', 'clearfix'),
            ),
            'heading' => array(
              'text' => t('Main menu'),
              'level' => 'h2',
              'class' => array('element-invisible'),
            ),
          )); ?>
        </nav>
      <?php endif; ?>

      <?php print render($page['navigation']); ?>

    </div>
    <?php endif; ?>
      
    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars col-md-4">
        <?php print $sidebar_first; ?>
         <?php 
                //print itg_event_backend_header_add_block();
               $block = block_load('itg_ads', ADS_RHS1);
               $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
               print render($render_array);
                                      
              ?>
        <?php print $sidebar_second; ?>
         <?php 
                //print itg_event_backend_header_add_block();
               $block = block_load('itg_ads', ADS_RHS2);
               $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
               print render($render_array);
                                      
              ?>
      </aside>
    <?php endif; ?>
    </div>
  </main>

  <?php print render($page['footer']); ?>
</div>
</div>

<?php print render($page['bottom']); ?>
<?php global $base_url; ?>
<div id="widget-ajex-loader" style="display: none">
    <img class="widget-loader" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itgadmin') . '/images/loader.svg'; ?>" alt="Loading..." />
</div>
<?php
drupal_add_js("jQuery(document).ready(function(){
    jQuery('.top-tab li').eq(0).addClass('active');
    jQuery('.top-tab li').click(function(){        
        jQuery('.top-tab li').removeClass('active');
        jQuery(this).addClass('active');        
        jQuery('.common-class').hide();
        var getVal = jQuery(this).attr('data-tag');        
        jQuery('.'+getVal).show();
    });
    
    jQuery('#block-views-event-photo-slider-block .view-event-photo-slider .view-event-photo-slider ul').slick({
        infinite: true,    
        autoplay:true,
        dots: false,
        variableWidth:true,
        prevArrow: '<i class=\"fa fa-angle-left slick-prev\"></i>',
        nextArrow: '<i class=\"fa fa-angle-right slick-next\"></i>'
    });
});", array('type' => 'inline', 'scope' => 'footer'));
?>