<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
global $base_url;
$banner_img = drupal_get_path('module', 'itg_event_backend').'/event_banner.png';
?>

<div id="page">
  <div class="event-sidebar">
    <header class="header" id="header" role="banner">
            <section class="header-top">
                <div class="container header-logo">
              <?php if ($logo): ?>
                <div class="logo">
                  <a href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="<?php echo $base_url.'/'.$banner_img; ?>" width="100%"/></a>
<!--                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>-->
                </div>
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
                
                <?php print render($page['header_event']); ?>
                    
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
      <?php print $feed_icons; ?>
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
        <?php print $sidebar_second; ?>
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
    <img class="widget-loader" align="center" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itgadmin') . '/images/loader.svg'; ?>" alt="Loading..." />
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
    
    jQuery('.view-event-photo-slider ul').slick({
        infinite: true,    
        autoplay:true,
        dots: false,
        prevArrow: false,
        nextArrow: false
    });
});", array('type' => 'inline', 'scope' => 'footer'));
?>