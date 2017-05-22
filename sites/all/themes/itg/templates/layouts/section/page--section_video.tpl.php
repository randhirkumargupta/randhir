<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<?php
global $theme;
$preview = NULL;
if (arg(2) == 'preview') {
  $preview = 'preview';
}

if ($theme == 'itgadmin' && !isset($preview)) {
  $gray_bg_layout = 'gray-bg-layout';
}
?>

<!--------------------------------Code for Front tpl---------------------------------------->
<?php if ($theme != 'itgadmin') { ?>
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
              
              <?php if ($secondary_menu): ?>
          
                <?php
                print theme('links__system_secondary_menu', array(
                  'links' => $secondary_menu,
                  'attributes' => array(
                    'class' => array('links', 'inline', 'clearfix'),
                  ),
                  'heading' => array(
                    'text' => $secondary_menu_heading,
                    'level' => 'h2',
                    'class' => array('element-invisible'),
                  ),
                ));
                ?>
                 
              <?php endif; ?>
              
              <?php print render($page['header']); ?>
              <?php
              // photo_carousel widget
              $block = block_load('itg_widget', 'featured_video_carousel_r');
              $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
              print render($render_array);
              ?>
              <!-- Breaking news band -->            
              <?php if (!empty($page['breaking_news'])): ?>
              <div class="container mt-50">
                <div class="row">
                    <div class="col-md-12">
                        <?php print render($page['breaking_news']); ?>
                    </div>      
                </div> 
               </div>
              <?php endif; ?>
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
      <div class="itg-region">
          <div class="container pos-rel">
              <div class="slide-icon scroll-arrow-right"><i class="fa fa-angle-left ll"></i></div>

              <ul class="video_landing_menu">
                  <?php for ($count = 1; $count < 21; $count++) { ?>
                    <?php $blockid = 'itg-block-' . $count; ?>
                    <?php if ($theme == FRONT_THEME_NAME) { ?>

                      <?php if (isset($widget_data[$blockid]['block_title'])) { ?>
                        <li>                     
                            <?php

                            print l($widget_data[$blockid]['block_title'], 'javascript:void(0)', array(
                              'external' => TRUE,
                              'attributes' => array(
                                'data-anchor' => $widget_data[$blockid]['cat_id'],
                                'class' => 'active',
                              ),

                            )
                            );
                            ?>

                        </li>

       
      <?php } ?>
    <?php } ?>
                  <?php } ?>              
              </ul>
                  <?php
                  drupal_add_js("jQuery('.video_landing_menu li a').live('click', function(){
               var section_id = jQuery(this).attr('data-anchor');
               jQuery('.video_landing_menu li a').removeClass('menu-active');
               jQuery('#edit-field-story-category-tid').val(section_id); 
               jQuery('#edit-field-story-category-tid').trigger('change');
               jQuery(this).addClass('menu-active');
           });", array('type' => 'inline', 'scope' => 'footer'));

                  drupal_add_js("jQuery(document).ready(function(){
               var section_id = jQuery('.video_landing_menu li a:first').attr('data-anchor');
               jQuery('#edit-field-story-category-tid').val(section_id); 
               jQuery('#edit-field-story-category-tid').trigger('change');
               jQuery('.video_landing_menu li a:first').addClass('menu-active');
           });", array('type' => 'inline', 'scope' => 'footer'));
                  ?>
              <div class="slide-icon scroll-arrow-left"><i class="fa fa-angle-right ll"></i></div>
          </div>
      </div>
      <main id="main" class="container">
          <section id="content" role="main">
  <?php print render($page['highlighted']); ?>
  <?php print $breadcrumb; ?>
              <a id="main-content"></a>
              <?php print render($title_prefix); ?>
              <?php if ($title): ?>
              <?php endif; ?>
                  <div class="front-end-breadcrumb">
                  <?php print render($page['front_end_breadcrumb']); ?>
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
            <?php
            $itg_class = 'itg-admin';
            if ($theme != 'itgadmin') {
              $itg_class = 'itg-front';
            }
            ?>
            <div class="itg-layout-container <?php echo $itg_class; ?> default-video">
            <?php if ($theme == 'itgadmin') { ?>
                  <div class="row">
                      <div class="col-md-12">
                          <div class="itg-region">
                              <div class="slide-icon scroll-arrow-right"><i class="fa fa-angle-left ll"></i></div>
                              <ul>
                                  <?php for ($count = 1; $count < 21; $count++) { ?>
                                    <?php 
                                      $blockid = 'itg-block-' . $count; 
                                      $clsli = '';
                                      if (isset($widget_data[$blockid]['block_title'])) {
                                        $clsli = 'active';
                                      } 
                                    ?>  
                                    <li class='<?php print $clsli; ?>'>
                                    <?php 
                                      $blockid = 'itg-block-' . $count; 
                                      $cls = '';
                                      if (isset($widget_data[$blockid]['block_title'])) {
                                        $cls = 'active';
                                      } 
                                    ?>
                                        <a class="droppable <?php print $cls; ?>" data-tabwidget_display="region-section-content" id="<?php print $blockid; ?>" href="javascript:;">
                                            <div class="data-holder" id="<?php print $blockid; ?>">
                                        <?php
                                        if (isset($widget_data[$blockid]['block_title'])) {
                                          print $widget_data[$blockid]['block_title'];
                                        }
                                        else {
                                          echo 'Drag Category';
                                        }
                                        ?>
                                            </div>
                                        </a>
                                    </li>

  <?php } ?>              
                              </ul>
                              <div class="slide-icon scroll-arrow-left"><i class="fa fa-angle-right ll"></i></div>
                          </div>
                      </div>
                  </div>
<?php } ?>
                <div class="row">
                    <div class="col-md-8">
                        <div id="region-section-content" class="region-content">
<?php
if (isset($widget_data['itg-block-1']['widget'])) {
  print $widget_data['itg-block-1']['widget'];
}
else {
  print t("You can't drag any widget in main content area!");
}
?>

                        </div>
                    </div>
                    <div class="col-md-4">
                        <div class="sidebar-section-photo">
                          <div class="itg-widget">
                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                              <div class="widget-help-text"><?php print t('Non Draggable'); ?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
                            <?php } ?>
                            <div class="itg-widget-inner">
                              <div class="ad-widget">
                                <div class="sidebar-ad droppable">
                                  <?php
                                  $block = block_load('itg_ads', ADS_RHS1);
                                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                  print render($render_array);
                                  ?>
                                </div>
                              </div>              
                            </div>              
                          </div>
                          <div class="itg-widget">
                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                              <div class="widget-help-text"><?php print t('Template widgets');?> ( <strong><?php print t('May We Suggest'); ?></strong> )</div>
                            <?php } ?>
                            <div class="itg-widget-inner">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                <div class="widget-wrapper <?php print $widget_data['itg-block-21']['widget_name']; ?>">
                                  <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-21']['block_title'])) { ?>
                                    <span class="widget-title"><?php print $widget_data['itg-block-21']['block_title']; ?></span>
                                  <?php } ?>
                                  <!-- for admin  -->
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-settings">
                                      <div class="widget-title-wrapper">
                                        <span class="widget-title" data-id="itg-block-21"><?php print $widget_data['itg-block-21']['block_title']; ?></span>
                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-21']['block_title']; ?>" name="itg-block-21" class="block_title_id" placeholder="Enter Title" />
                                      </div>
                                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                    </div>
                                  <?php } ?>  

                                  <div class="data-holder" id="itg-block-21">
                                    <?php
                                    if (isset($widget_data['itg-block-21']['widget'])) {
                                      print $widget_data['itg-block-21']['widget'];
                                    } else {
                                      print '<div class="widget-placeholder"><span>'.t('May we suggest').'</span></div>';
                                    }
                                    ?>
                                  </div>
                                </div>             
                              </div>               
                            </div>               
                          </div>
                          <div class="itg-widget">
                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                              <div class="widget-help-text"><?php print t('Template widgets'); ?> ( <strong><?php print t('Watch Right Now'); ?></strong> )</div>
                            <?php } ?>
                            <div class="itg-widget-inner">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                <div class="widget-wrapper <?php print $widget_data['itg-block-22']['widget_name']; ?>">
                                  <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-22']['block_title'])) { ?>
                                    <span class="widget-title"><?php print $widget_data['itg-block-22']['block_title']; ?></span>
                                  <?php } ?>
                                  <!-- for admin  -->
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-settings">
                                      <div class="widget-title-wrapper">
                                        <span class="widget-title" data-id="itg-block-22"><?php print $widget_data['itg-block-22']['block_title']; ?></span>
                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-22']['block_title']; ?>" name="itg-block-22" class="block_title_id" placeholder="Enter Title" />
                                      </div>
                                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                    </div>
                                  <?php } ?>  

                                  <div class="data-holder" id="itg-block-22">
                                    <?php
                                    if (isset($widget_data['itg-block-22']['widget'])) {
                                      print $widget_data['itg-block-22']['widget'];
                                    } else {
                                      print '<div class="widget-placeholder"><span>'.t('Watch right now').'</span></div>';
                                    }
                                    ?>
                                  </div>
                                </div>             
                              </div>               
                            </div>               
                          </div>
                       
                                        <?php if ($theme == 'itg') { ?>
                                          <?php $block_ask_expert = module_invoke('itg_ask_expert', 'block_view', 'custom_ask_expert_form_block');?>
                                          <?php if (!empty($block_ask_expert['content'])) {?>

                                          <?php } ?>
                                        <?php } ?>
                          <div class="itg-widget">
                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                              <div class="widget-help-text"><?php print t('Non Draggable');?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
                            <?php } ?>
                            <div class="itg-widget-inner">
                              <div class="ad-widget">
                                <div class="sidebar-ad droppable">
                                  <?php
                                  $block = block_load('itg_ads', ADS_RHS2);
                                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                  print render($render_array);
                                  ?>
                                </div>
                              </div>              
                            </div>              
                          </div>
                        </div>
                    </div>
                </div>
            </div>
            <!--------------------------------Code for Front tpl---------------------------------------->
            <?php if ($theme != 'itgadmin') { ?>
              
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
                
            </aside>
          <?php endif; ?>
      </main>


      <?php print render($page['footer']); ?>


  </div>

  <?php print render($page['bottom']); ?>

<?php } ?>
<?php if ($theme == 'itgadmin') { ?>
  <div class="itg-ajax-loader">
      <img src="<?php echo base_path() . drupal_get_path('theme', $theme); ?>/images/loader.svg" alt=""/>
  </div>
<?php } ?>