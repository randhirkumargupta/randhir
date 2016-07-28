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
          <div class="login-link desktop-hide">
            <a href="/user">Login</a>
          </div> 
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
          <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
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
          </nav>
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
    <main id="main" class="container">
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
 <?php //print render($page['content']); ?>
<?php
    $itg_class = 'itg-admin';
    if ($theme != 'itgadmin') {
      $itg_class = 'itg-front';
    }
?>
<div class="itg-layout-container <?php echo $itg_class; ?>">

    <div class="row">
        <div class="top-block mt-50">

            <div class="top-colum-2">
                <div class="itg-widget">
                    <div class="droppable" id="itg-block-1">
                        <?php if ($theme != 'itgadmin') { ?>
                    <?php if (isset($widget_data['itg-block-1']['block_title'])) {?>
                        <span class="widget-title">
                           <?php print $widget_data['itg-block-1']['block_title'];?>
                        </span>
                    <?php } ?>
                    <?php } ?>
                        <?php print $widget_data['itg-block-1']['widget']; ?>
                    </div>
                    <?php if ($theme == 'itgadmin') { ?>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id" placeholder="Enter Title" />
                    <?php } ?>
                </div>
            </div>

            <div class="top-colum-1">
                <div class="itg-widget">
                    <div class="top-n-most-popular-stories">
                        <div class="tab-buttons">
                            <span data-id="tab-data-1" class="active">
                                <?php if (!$widget_data['itg-block-2']['block_title']) { 
                                    print 'Tab 1';
                                } else {
                                    print $widget_data['itg-block-2']['block_title'];
                                } ?>
                            </span>
                            <span data-id="tab-data-2"><?php print 'Tab 2'; ?></span>
                        </div>
                        <div class="itg-widget-child tab-data tab-data-1">
                            <div class="droppable" id="itg-block-2">
                            <?php print $widget_data['itg-block-2']['widget']; ?>
                            </div>
                                <?php if ($theme == 'itgadmin') { ?>
                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                                <?php } ?>
                        </div>
                        <div class="itg-widget-child tab-data tab-data-2 hide">
                            <div class="droppable" id="itg-block-3">
                            <?php print $widget_data['itg-block-2']['widget']; ?>
                            </div>
                            <?php if ($theme == 'itgadmin') { ?>
                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-3']['block_title']; ?>" name="itg-block-3" class="block_title_id" placeholder="Enter Title" />
                            <?php } ?>
                        </div>
                    </div>
                </div>
            </div>

            <div class="top-colum-3">
                <div class="itg-widget-parent">
                    <div class="itg-widget">
                        <div class="droppable" id="itg-block-4">                          
                            <?php print $widget_data['itg-block-4']['widget']; ?>
                        </div>
                        <?php if ($theme == 'itgadmin') { ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-4']['block_title']; ?>" name="itg-block-4" class="block_title_id" placeholder="Enter Title" />
                        <?php } ?>
                    </div>
                </div>
                    <div class="itg-widget">
                        <div class="tab-buttons">
                            <span data-id="tab-data-1" class="active"><?php print 'Tab 1'; ?></span>
                            <span data-id="tab-data-2"><?php print 'Tab 2'; ?></span>
                        </div>
                        <div class="itg-widget-child">
                            <div class="droppable tab-data tab-data-1" id="itg-block-5">                               
                                <?php print $widget_data['itg-block-5']['widget']; ?>
                            </div>
                            <?php if ($theme == 'itgadmin') { ?>
                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />  
                            <?php } ?>    
                        </div>
                        <div class="itg-widget-child hide">
                            <div class="droppable tab-data tab-data-2" id="itg-block-6">
                                <?php if ($theme != 'itgadmin') { ?>
                                    <span class="widget-title">
                                        <?php print $widget_data['itg-block-6']['block_title'];?>
                                    </span>
                                <?php } ?>
                                <?php print $widget_data['itg-block-6']['widget']; ?>
                            </div>
                            <?php if ($theme == 'itgadmin') { ?>
                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />    
                            <?php } ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    <div class="row itg-common-section">

        <div class="col-md-4 col-sm-4 col-xs-12">
            <div class="itg-widget mt-50">
                <div class="droppable common-news" id="itg-block-7">
                   <?php if ($theme != 'itgadmin') { ?>
                    <?php if (isset($widget_data['itg-block-7']['block_title'])) {?>
                        <span class="widget-title">
                           <?php print $widget_data['itg-block-7']['block_title'];?>
                        </span>
                    <?php } ?>
                    <?php } ?>
                    <?php print $widget_data['itg-block-7']['widget']; ?>
                </div>
                <?php if ($theme == 'itgadmin') { ?>
                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id" placeholder="Enter Title" />  
                <?php } ?>
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12">
            <div class="itg-widget mt-50">
                <div class="droppable" id="itg-block-8">
                    <?php if ($theme != 'itgadmin') { ?>
                    <?php if (isset($widget_data['itg-block-8']['block_title'])) {?>
                        <span class="widget-title">
                           <?php print $widget_data['itg-block-8']['block_title'];?>
                        </span>
                    <?php } ?>
                    <?php } ?>
                    <?php print $widget_data['itg-block-8']['widget']; ?>
                </div>
                <?php if ($theme == 'itgadmin') { ?>
                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-8']['block_title']; ?>" name="itg-block-8" class="block_title_id" placeholder="Enter Title" />     
                <?php } ?>
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12">
            <div class="itg-widget mt-50">
                <div class="droppable" id="itg-block-9">
                    <?php if ($theme != 'itgadmin') { ?>
                    <?php if (isset($widget_data['itg-block-9']['block_title'])) {?>
                        <span class="widget-title">
                           <?php print $widget_data['itg-block-9']['block_title'];?>
                        </span>
                    <?php } ?>
                    <?php } ?>
                    <?php print $widget_data['itg-block-9']['widget']; ?>
                </div>
                <?php if ($theme == 'itgadmin') { ?>
                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-9']['block_title']; ?>" name="itg-block-9" class="block_title_id" placeholder="Enter Title" />  
                <?php } ?>
            </div>          
        </div>

    </div>
    
     <div class="row itg-common-section m-top">
        <div class="col-md-8 col-sm-8 col-xs-12">
            <div class="itg-widget mt-50">
                <div class="droppable" id="itg-block-10">
                    <?php if ($theme != 'itgadmin') { ?>
                    <?php if (isset($widget_data['itg-block-10']['block_title'])) {?>
                        <span class="widget-title">
                           <?php print $widget_data['itg-block-10']['block_title'];?>
                        </span>
                    <?php } ?>
                    <?php } ?>
                    <?php print $widget_data['itg-block-10']['widget']; ?>
                </div>
                <?php if ($theme == 'itgadmin') { ?>
                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-10']['block_title']; ?>" name="itg-block-10" class="block_title_id" placeholder="Enter Title" />  
                <?php } ?>
            </div>  
        </div>
         <div class="col-md-4 col-sm-4 col-xs-12">
            <div class="itg-widget mt-50">
                <div class="droppable" id="itg-block-11">
                    <?php if ($theme != 'itgadmin') { ?>
                    <?php if (isset($widget_data['itg-block-11']['block_title'])) {?>
                        <span class="widget-title">
                           <?php print $widget_data['itg-block-11']['block_title'];?>
                        </span>
                    <?php } ?>
                    <?php } ?>
                    <?php print $widget_data['itg-block-11']['widget']; ?>
                </div>
                <?php if ($theme == 'itgadmin') { ?>
                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-11']['block_title']; ?>" name="itg-block-11" class="block_title_id" placeholder="Enter Title" />  
                <?php } ?>
            </div>  
        </div>
     </div>    
    
    
    
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
          <?php print $sidebar_first; ?>
          <?php print $sidebar_second; ?>
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
<?php } ?>