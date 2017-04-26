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
      <div class="col-md-12 col-sm-12 col-xs-12">
      <?php $url_get = explode('/',$_SERVER['REQUEST_URI']);?>
      <!-- sponsor for static -->
        <?php
          if($url_get[2] == '2016') {
            print bestcollege_get_sponser_data('Best college Sponser');
          }
        ?>
      <!-- end sponsor for static -->
      </div>






        <div class="col-md-8 col-sm-12 col-xs-12 left-side">
           <?php if (isset($widget_data['itg-block-1']['widget_name']) || isset($widget_data['itg-block-2']['widget_name']) || isset($widget_data['itg-block-3']['widget_name']) || $theme == 'itgadmin') { ?>
            <div class="row">
              <?php if ($theme == 'itgadmin') { ?>

                <div class="col-md-12 itg-h747-section">
                    <div class="itg-widget">
                      <div class="droppable <?php print $gray_bg_layout; ?>">
                      <?php
                        if (array_filter(views_get_view_result('best_college_image_slider', 'block'))) {
                            print views_embed_view('best_college_image_slider', 'block');
                        }
                      ?>

                        </div>
                    </div>
                </div>
              <?php } else {
                      if($url_get[2] != '2014' && $url_get[2] != '2013') {
                          if (array_filter(views_get_view_result('best_college_image_slider', 'block'))) {
                              print views_embed_view('best_college_image_slider', 'block');
                          }
                      } else {
                          print bestcollege_get_sponser_data('Best college graph');

                      }

               } ?>

        <div>

  <div class="clearfix"></div>      <!--- list / grid -->
<div class="col-sm-12 col-xs-12 view1">

<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("Best of The Best ") . $url_get[2]; ?></div>
        <div class="right_Section pull-right  col-md-6  col-sm-6 col-xs-12 text-right hidden-xs">
        <strong>view as</strong>
        <div class="btn-group">
            <a href="#" class="btn btn-default btn-sm grid"><span class="fa fa-th"></span> Grid</a>
            <a href="#" class="btn btn-default btn-sm active_btn list"><span class="fa fa-th-list"></span> List</a>
        </div>
        </div>
</div>
<!--- list / grid -->
<div class="clearfix"></div>
<div class="col-md-12 itg-h625-section">
  <div class="itg-widget">
    <div class="col-sm-12 remove_padd_right">
      <div class="row list-group college">
        <div class="clr_chn">
          <?php if ($theme == 'itgadmin') { ?>

          <div class="droppable <?php print $gray_bg_layout; ?>">

          <?php
          if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-3']['block_title'])) {
              if (array_filter(views_get_view_result('best_college_image_slider', 'block_1', $url_get[2])))
              {
                print views_embed_view('best_college_image_slider', 'block_1', $url_get[2]);
              }
          }
          ?>

            <div class="data-holder" id="itg-block-3">
              <?php print $widget_data['itg-block-3']['widget']; ?>
            </div>

          </div>
          <?php } else {
            if (array_filter(views_get_view_result('best_college_image_slider', 'block_1', $url_get[2])))
            {
                print views_embed_view('best_college_image_slider', 'block_1', $url_get[2]);
            }
          }
        ?>



        </div>
      </div>
    </div>

  </div>
</div>


        </div>



     </div>
  <?php } ?>

        </div>


        <div class="col-md-4 col-sm-12 col-xs-12 right-side">

          <div class="col-md-12 mt-50 itg-h1735-section">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-4']['widget_name'].$widget_data['itg-block-4']['widget_display_name']; ?>">
                    <div class="data-holder" id="itg-block-4" widget-style="oscar-news best-news">

                                <div class="ad-widget">
                                    <div class="sidebar-ad">
                                      <?php
                                        $block = block_load('itg_ads', ADS_RHS1);
                                        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                        if(is_array($render_array)) {
                                          print render($render_array);
                                        } else {
                                           if (!empty($itg_ad['200*200_right_bar_ad1'])) {
                                            print $itg_ad['200*200_right_bar_ad1'];
                                          }
                                        }




                                       ?></div>
                                </div>

                    <?php
                          $block = block_load('itg_bestcolleges', 'bestcollege_rhssearch');
                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                          print $output = render($render_array);

                          // static html block
                          $block1 = block_load('itg_bestcolleges', 'bestcollege_rhsstatic');
                          $render_rhsstatic = _block_get_renderable_array(_block_render_blocks(array($block1)));
                          print render($render_rhsstatic);

                          // RHS Video
                          $block_video = block_load('itg_bestcolleges','bestcollege_rhs_videos_widget');
                          $render_video = _block_get_renderable_array(_block_render_blocks(array($block_video)));
                          print render($render_video);


                          // RHS Adds 2
                          $block1 = block_load('itg_ads', ADS_RHS2);
                          $render_array1 = _block_get_renderable_array(_block_render_blocks(array($block1)));
                          print render($render_array1);

                    ?>
                    </div>
                  </div>
                </div>
            </div>
        </div>


            <?php if (isset($widget_data['itg-block-4']['widget_name']) || isset($widget_data['itg-block-5']['widget_name']) || $theme == 'itgadmin') { ?>
            <div class="row">
                <div class="col-md-12">
                        <div class="itg-widget-parent">
                            <div class="itg-widget">
                                <div class="ad-widget">
                                    <div class="sidebar-ad">
                                      <?php
                                        if (!empty($itg_ad['200*200_right_bar_ad1'])) {
                                          print $itg_ad['200*200_right_bar_ad1'];
                                        }
                                        ?></div>
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
