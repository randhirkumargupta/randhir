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
if ($theme != 'itgadmin') {
    ?>

    <!--------------------------------Code for Front tpl---------------------------------------->

    <div id="page">
        <header class="header" id="header" role="banner">
            <section class="header-top">
                <div class="container">
                <div class="header-ads mhide">
                    <img src="<?php print base_path() . path_to_theme() ?>/images/header-ads.png" alt="ads">
                </div>
                
                <?php if ($logo): ?>
                <div class="logo">
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
                </div>
                <?php endif; ?>
                <div class="lgn desktop-hide">
                    <a href="/user">Login</a>
                </div> 
                
                <nav class="nav">
                        <ul class="social-nav mhide">
                            <li><a href="#" title=""><i class="fa fa-facebook"></i></a></li>
                            <li><a href="#" title=""><i class="fa fa-twitter"></i></a></li>
                            <li><a href="#" title=""><i class="fa fa-google-plus"></i></a></li>
                            <li><a href="#" title=""><i class="fa fa-rss"></i></a></li>
                            <li><a href="#" title=""><i class="fa fa-mobile"></i></a></li>
                            <li><a href="#" title=""><i class="fa fa-volume-up"></i></a></li>
                            <li><a href="#" title=""><i class="fa fa-search"></i></a></li>
                            <li><a href="user" title="">Login</a></li>
                        </ul>
                        <ul class="main-nav">
                            <li class="desktop-hide"><a href="#" title=""><i class="fa fa-bars" ></i></a></li>
                            <li><a href="#" class="active" title="">News</a></li>
                            <li><a href="#" title="">tv</a></li>
                            <li><a href="#" title="">MAGAZINE</a></li>
                        </ul>
                </nav>
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
                    </div>
            </section>
            
            <section class="navigation">
                <div class="container">
                    <ul class="menu no-bullet">
                        <li><a href="#">Make In India</a></li>
                        <li><a href="#">Make In India</a></li>
                        <li><a href="#">Make In India</a></li>
                        <li><a href="#">Make In India</a></li>
                        <li><a href="#">Make In India</a></li>
                    </ul>
                </div>   
            </section>
            
            
            
            
            
        </header>
        <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
        ?>
        <?php
        $cls = 'col-md-12';
        if ($sidebar_first || $sidebar_second):
            $cls = 'col-md-9';
        endif;
        ?>
        <main id="main" class="container">
            <div class="row">
                <section id="content" class="<?php echo $cls; ?>" role="main">
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
                    <?php //print render($page['content']); ?>
<!--                        ####################################################-->

<div id="front-contener">
    <div class="itg-row">
        <div class="row">
            <div class="col-md-12">
                <div class="droppable big-news" id="itg-block-1">
                  <span><?php print $widget_data['itg-block-1']['block_title']; ?></span>
                    <?php print $widget_data['itg-block-1']['widget']; ?>
                </div>                
            </div>
        </div>
    </div>
    <div class="itg-row">
        <div class="row">
            <div class="col-md-3 col-sm-3 col-xs-12">
                <div class="droppable top-n-most-popular-stories" id="itg-block-2">
                    <span><?php print $widget_data['itg-block-2']['block_title']; ?></span>
                    <?php print $widget_data['itg-block-2']['widget']; ?>
                </div>            
            </div>
            <div class="col-md-5 col-sm-5 col-xs-12">
                <div class="droppable top-news" id="itg-block-3">
                    <span><?php print $widget_data['itg-block-3']['block_title']; ?></span>
                    <?php print $widget_data['itg-block-3']['widget']; ?>
                </div>            
            </div>
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable video-n-magazine" id="itg-block-4">
                    <span><?php print $widget_data['itg-block-4']['block_title']; ?></span>
                    <?php print $widget_data['itg-block-4']['widget']; ?>
                </div>            
            </div>
        </div>
    </div>
    <div class="itg-row">
        <div class="row">
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable common-news" id="itg-block-5">
                   <span><?php print $widget_data['itg-block-5']['block_title']; ?></span>
                   <?php print $widget_data['itg-block-5']['widget']; ?>
                </div>            
            </div>
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable common-news" id="itg-block-6">
                    <span><?php print $widget_data['itg-block-6']['block_title']; ?></span>
                    <?php print $widget_data['itg-block-6']['widget']; ?>
                </div>            
            </div>
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable common-news" id="itg-block-7">
                   <span><?php print $widget_data['itg-block-7']['block_title']; ?></span>
                   <?php print $widget_data['itg-block-7']['widget']; ?>
                </div>            
            </div>
        </div>
    </div>
</div>                        
<!--                        #####################################################-->
                        
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
            </div>
        </main>

        <?php print render($page['footer']); ?>

    </div>

    <?php print render($page['bottom']); ?>

<?php } else { ?>
    <!--------------------------------Code for Admin tpl---------------------------------------->

<div id="<?php print $_GET['template_name'] ?>-contener">
    <div class="itg-row">
        <div class="row">
            <div class="col-md-12">
                <div class="droppable big-news" id="itg-block-1">
                    <?php print $widget_data['itg-block-1']['widget']; ?>
                </div>
                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id">            
            </div>
        </div>
    </div>
    <div class="itg-row">
        <div class="row">
            <div class="col-md-3 col-sm-3 col-xs-12">
                <div class="droppable top-n-most-popular-stories" id="itg-block-2">
                    <?php print $widget_data['itg-block-2']['widget']; ?>
                </div>
            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id">            
            </div>
            <div class="col-md-5 col-sm-5 col-xs-12">
                <div class="droppable top-news" id="itg-block-3">
                    <?php print $widget_data['itg-block-3']['widget']; ?>
                </div>
            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-3']['block_title']; ?>" name="itg-block-3" class="block_title_id">            
            </div>
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable video-n-magazine" id="itg-block-4">
                    <?php print $widget_data['itg-block-4']['widget']; ?>
                </div>
            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-4']['block_title']; ?>" name="itg-block-4" class="block_title_id">            
            </div>
        </div>
    </div>
    <div class="itg-row">
        <div class="row">
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable common-news" id="itg-block-5">
                   <?php print $widget_data['itg-block-5']['widget']; ?>
                </div>
            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id">            
            </div>
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable common-news" id="itg-block-6">
                    <?php print $widget_data['itg-block-6']['widget']; ?>
                </div>
            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id">            
            </div>
            <div class="col-md-4 col-sm-4 col-xs-12">
                <div class="droppable common-news" id="itg-block-7">
                   <?php print $widget_data['itg-block-7']['widget']; ?>
                </div>
            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id">            
            </div>
        </div>
    </div>
</div>

<?php 
}

