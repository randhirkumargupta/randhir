<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 */
global $base_url;
$arg = arg();
if (!empty($arg[1]) && is_numeric($arg[1]) && $arg[0] == 'node') {
  $nid = $arg[1];
}
elseif ($arg[0] == 'event' && !empty($arg[0])) {
  $path = drupal_lookup_path("source", $arg[1] . '/' . $arg[2]);
  $nid_id = explode('/', $path);
  $nid = $nid_id[1];
  if ((!empty($arg[2]) && $arg[2] == 'registration') && empty($host_node)) { // unpublish condition
    $nid_id = explode('/', $path);
    $nid = $nid_id[1];
  }
}
$event_section = itg_event_backend_section_detail($nid);
$flag = TRUE;
$node_value = itg_event_backend_page_domain($nid);
$banner_image_uri = $node_value[0]->uri;
$menu_color = $node_value[0]->field_e_menu_bck_color_rgb;
$banner_image = (!empty($banner_image_uri) ? file_create_url($banner_image_uri) : $base_url . '/' . drupal_get_path('module', 'itg_event_backend') . '/event_banner.jpeg');
$menu_background_color = (!empty($menu_color) ? $menu_color : '#000');
?>
<div id="page">
    <div class="event-sidebar">
        <header class="header" id="header" role="banner">
            <?php if(isset($event_section) && !empty($event_section)):?>
            <?php
              $tpl_name = 'section_header_' . $event_section . '_block';
              if(!empty(theme($tpl_name))){
              $menu_data = get_event_menu($nid);
              $data['menu_manager'] = $menu_data;
              $return_data['data'] = $data;
              $return_data['is_event'] = TRUE;
              $return_data['template_name'] = $tpl_name;
              print  theme($tpl_name, array('data' => $return_data));
              $flag = FALSE;
              }
            ?>
          <?php endif;?>
          <?php if($flag):?>  
            <section class="header-top">
                <div class="event-header-banner">
                    <img src="<?php echo $banner_image; ?>" alt="" title="">
                    <div class="event-add-header">

                        <?php
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
          <?php endif;?>
        </header>
        <?php
        $sidebar_second = render($page['sidebar_second_event']);
        ?>
        <?php
        $cls = 'col-md-8';
        if ($sidebar_second):
          $cls = 'col-md-8';
        endif;
        ?>
        <?php print render($page['top']); ?>
        <?php print render($page['my_cart']); ?>
        <main id="main" class="container">
            <div class="row">
                <section id="content" class="<?php echo $cls; ?>" role="main">
                    <?php print render($page['highlighted']); ?>
                    <?php if (arg(0) != 'user'): print $breadcrumb; ?>
                    <?php endif; ?>

                    <a id="main-content"></a>
                    <?php print render($title_prefix); ?>
                    <?php if ($title): ?>
                      <h1 class="page__title title element-hidden" id="page-title"><?php print $title;  ?></h1>
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
                            ));
                            ?>
                        </nav>
                      <?php endif; ?>

  <?php print render($page['navigation']); ?>

                  </div>
                <?php endif; ?>

                    <?php //if ($sidebar_first || $sidebar_second) { ?>
                    <?php if ($sidebar_second) { ?>
                  <aside class="sidebars col-md-4">
                      <?php
                      $block = block_load('itg_ads', ADS_RHS1);
                      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                      print render($render_array);
                      ?>
                      <?php print $sidebar_second; ?>
                      <?php
                      $block = block_load('itg_ads', ADS_RHS2);
                      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                      print render($render_array);
                      ?>
                  </aside>
                    <?php }
                    else { ?>
                  <aside class="sidebars col-md-4">
                  <?php
                  $block = block_load('itg_ads', ADS_RHS1);
                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                  print render($render_array);
                  print '<section class="region region-sidebar-second-event column sidebar"></section>';
                  $block = block_load('itg_ads', ADS_RHS2);
                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                  print render($render_array);
                  ?>
                  </aside>
                <?php } ?>    
            </div>
        </main>

        <?php print render($page['footer']); ?>
    </div>
</div>

<?php print render($page['bottom']); ?>
<?php global $base_url; ?>
<div id="widget-ajex-loader" style="display: none">
    <img class="widget-loader" src="<?php echo file_create_url(file_default_scheme() . '://../sites/all/themes/itgadmin/images/loader.svg'); ?>" alt="Loading..." />
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