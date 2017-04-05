<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */


global $theme, $user;
$preview = NULL;

if (arg(2) == 'preview') {
  $preview = 'preview';  
}

if ($theme == 'itgadmin' && !isset($preview)) {
  $gray_bg_layout = 'gray-bg-layout';
}

$itg_class = 'itg-admin';
if ($theme != 'itgadmin') {
  $itg_class = 'itg-front';
}

?>

<!--------------------------------Code for Front tpl---------------------------------------->
<?php if ($theme != 'itgadmin') {?>
  <div id="page">
    <header class="header" id="header" role="banner">
      <section class="header-top">
        <div class="container header-logo">
          <?php if ($logo): ?>
            <div class="logo">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
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

        

        <?php print render($page['header']); ?>

      </section>

    </header>
    <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);

        $cls = 'col-md-12';
        if ($sidebar_first || $sidebar_second):
          $cls = 'col-md-9';
        endif;
    ?>
    <main id="main" class="container pos-rel">
      <?php print render($page['vertical_menu']); ?>
      <section id="content" role="main">
        <?php print render($page['highlighted']); ?>
        <?php print $breadcrumb; ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
         <div class="front-end-breadcrumb">
           <?php print render($page['front_end_breadcrumb']);?>
         </div>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>       
        
<?php } ?>
<!--------------------------------Code for Front tpl and admin tpl---------------------------------------->
 

<div class="itg-layout-container <?php echo $itg_class; ?> oscar-layout-page ">
    <!-- Breaking news band -->    
    <?php if (!empty($page['breaking_news'])): ?>
    <div class="row">
        <div class="col-md-12">
          <?php print render($page['breaking_news']); ?>
        </div>      
    </div>    
    <?php endif; ?>
    <div class="row">
        <div class="col-md-8 col-sm-12 col-xs-12 left-side">
   <?php if (isset($widget_data['itg-block-1']['widget_name']) || isset($widget_data['itg-block-2']['widget_name']) || isset($widget_data['itg-block-3']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row">
        <div class="col-md-12 itg-h747-section">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name'].$widget_data['itg-block-1']['widget_display_name']; ?>">
                    <div class="data-holder" id="itg-block-1">
                      <?php
                        if (isset($widget_data['itg-block-1']['widget'])) {
                          print $widget_data['itg-block-1']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>Special Oscar Featured</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
         <div class="col-md-12 mt-50 itg-h305-section">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-2']['widget_name'].$widget_data['itg-block-2']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-2']['block_title'])) { ?>
                     <h4 class="heading"><?php print $widget_data['itg-block-2']['block_title']; ?></h4>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-2"><?php print $widget_data['itg-block-2']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-2" widget-style="oscar-features">
                      <?php
                        if (isset($widget_data['itg-block-2']['widget'])) {
                          print $widget_data['itg-block-2']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>Oscar features</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
        <div class="col-md-12 mt-50 itg-h625-section">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-3']['widget_name'].$widget_data['itg-block-3']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-3']['block_title'])) { ?>
                     <h4 class="heading"><?php print $widget_data['itg-block-3']['block_title']; ?></h4>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-3"><?php print $widget_data['itg-block-3']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-3']['block_title']; ?>" name="itg-block-3" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-3">
                      <?php
                        if (isset($widget_data['itg-block-3']['widget'])) {
                          print $widget_data['itg-block-3']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>Oscar photos</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
     </div>
  <?php } ?>
            
        </div>
        
        
        <div class="col-md-4 col-sm-12 col-xs-12 right-side">
            <?php if (isset($widget_data['itg-block-4']['widget_name']) || isset($widget_data['itg-block-5']['widget_name']) || $theme == 'itgadmin') { ?>
            <div class="row">
                <div class="col-md-12">                    
                        <div class="itg-widget-parent">
                            <div class="itg-widget">
                                <div class="ad-widget">
                                    <div class="sidebar-ad"> 
                                      <?php
                                        $block = block_load('itg_ads', ADS_RHS1);   
                                        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                        print render($render_array);
                                       ?></div>
                                </div>
                            </div>
                        </div>                    
                    </div>
                
                
            <div class="col-md-12 mt-50 itg-h735-section">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-4']['widget_name'].$widget_data['itg-block-4']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-4']['block_title'])) { ?>
                     <h4 class="heading"><?php print $widget_data['itg-block-4']['block_title']; ?></h4>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-4"><?php print $widget_data['itg-block-4']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-4']['block_title']; ?>" name="itg-block-4" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-4" widget-style="oscar-news">
                      <?php
                        if (isset($widget_data['itg-block-4']['widget'])) {
                          print $widget_data['itg-block-4']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>Oscar news</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
                
            <div class="col-md-12 mt-50 itg-h625-section">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-5']['widget_name'].$widget_data['itg-block-5']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-5']['block_title'])) { ?>
                    <h4 class="heading"><?php print $widget_data['itg-block-5']['block_title']; ?></h4>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-5"><?php print $widget_data['itg-block-5']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-5">
                      <?php
                        if (isset($widget_data['itg-block-5']['widget'])) {
                          print $widget_data['itg-block-5']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>Oscar videos</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
            </div>
            
            <?php } ?>
        </div>
        
    </div>
    
    
    
    

  
</div>

  <?php //print render($page['content']); ?>
  <!--Start third party widgets -->
  <div>
    <!--
    <div class="vukkul-comment">
    <div id="vuukle_div"></div>            
      <?php 
       if(function_exists('vukkul_view')) {
         vukkul_view();
       }
       ?>     
    </div>
  </div>
  -->  
  <!--End third party widgets -->
 
</div>
<!--------------------------------Code for Front tpl---------------------------------------->
        <?php if ($theme != 'itgadmin') {?>
        <?php //print $feed_icons;  ?>
      </section>

      <?php if (false) { ?> 
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
      <?php } ?>

      <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
          <?php //print $sidebar_first; ?>
          <?php //print $sidebar_second; ?>
        </aside>
      <?php endif; ?>
    </main>


    <?php print render($page['footer']); ?>


  </div>

  <?php print render($page['bottom']); ?>

<?php } ?>
<?php if ($theme == 'itgadmin') {?>
<div class="itg-ajax-loader">
  <img src="<?php  echo base_path().drupal_get_path('theme', $theme);?>/images/loader.svg" alt=""/>
</div>
<?php } 
if($theme != 'itgadmin')
{
    drupal_add_js("jQuery(document).ready(function() {
       jQuery('.add-more-block').on('click', function() {
                jQuery(this).hide();
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').slideDown( 1000);
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.removes-more-block').show();
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.add-more-block').show();
                 if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').next('.itg-common-section').is(':visible')) {
                  jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').find('.add-more-block').hide();
                }
            });
            jQuery('.add-more-block').each(function() {

                if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').is(':visible')) {
                    jQuery(this).hide();
                }
                if(jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').html() ==null)
                {
                    jQuery(this).remove();
                }
            });
             jQuery('.removes-more-block').on('click', function() {
                jQuery(this).hide();
                 jQuery(this).parent('.itg-common-section').hide();
                jQuery(this).parent('.itg-common-section').prev('.itg-common-section').find('.add-more-block').show();
            });
      
    });", array('type' => 'inline', 'scope' => 'footer'));
}

?>
