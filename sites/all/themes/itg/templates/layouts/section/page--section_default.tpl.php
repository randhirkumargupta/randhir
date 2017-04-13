<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
//$preview = $widget_data['preview'];
//p($widget_data);
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
                <!--  
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
                -->
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
            <?php //print render($page['content']);  ?>
            <?php
            $itg_class = 'itg-admin';
            if ($theme != 'itgadmin') {
                $itg_class = 'itg-front';
            }
            ?>
            <div class="itg-layout-container <?php echo $itg_class; ?> default-section">
                <!-- Breaking news band -->    
                <?php if (!empty($page['breaking_news'])): ?>
                    <div class="row">
                        <div class="col-md-12">
                            <?php print render($page['breaking_news']); ?>
                        </div>      
                    </div>    
                <?php endif; ?>
                <?php if (isset($widget_data['big_story'])) : ?>
                    <div class="row">
                        <div class="col-md-12">
                            <?php print $widget_data['big_story']; ?>
                        </div>    
                    </div>
                <?php endif; ?>

                <div class="row itg-top-section">        
                    <div class="row">
                        <div class="col-md-8 col-sm-12 col-sx-12 left-side">
                            <div class="top-colum-2">
                              <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-help-text">Template widgets ( <strong>Automated Top Story</strong> )</div>
                                  <?php } ?>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div id="defalt-section-top-block" class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-1']['block_title'])) { ?>
                                                <span class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></span>
                                            <?php } ?>
                                            <!-- for admin  -->
                                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <?php if (!empty($widget_data['itg-block-1']['block_title'])) { ?>
                                                            <span class="widget-title" data-id="itg-block-1"><?php print $widget_data['itg-block-1']['block_title']; ?></span>
                                                        <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                </div>
                                            <?php } ?>  
                                            <div class="data-holder" id="itg-block-1">
                                              <?php
                                                if (isset($widget_data['itg-block-1']['widget'])) {
                                                  print $widget_data['itg-block-1']['widget']; 
                                                } else{
                                                  print '<div class="widget-placeholder"><span>Featured Story</span></div>';
                                                } 
                                              ?>
                                            </div>
                                        </div>                     
                                    </div>
                                </div>
                            </div>

                        </div>

                        <div class="col-md-4 col-sm-12 col-sx-12 left-side">  

                            <div class="top-colum-3">
                                <div class="itg-widget-parent m-bottom40">
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-help-text">Non Draggable ( <strong>Ad widget</strong> )</div>
                                  <?php } ?>
                                    <div class="itg-widget">
                                        <div class="ad-widget">
                                            <div class="sidebar-ad droppable">
                                                <?php
                                                $block = block_load('itg_ads', 'ads_medium_rectangl_rhs1_300x250');
                                                $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                                print render($render_array);
                                                ?>
                                            </div>
                                        </div>              
                                    </div>
                                </div>
                                <div class="itg-widget trending-list">
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-help-text">Template widgets ( <strong>Trending Videos & Top Takes</strong> )</div>
                                  <?php } ?>
                                    <div class="tab-buttons">
                                        <span data-class="itg-block-5" data-id="tab-data-1" class="active">
                                            <?php
                                            if (!$widget_data['itg-block-5']['block_title']) {
                                                print 'Tab 1';
                                            }
                                            else {
                                                print $widget_data['itg-block-5']['block_title'];
                                            }
                                            ?>
                                        </span>
                                        <span data-class="itg-block-6" data-id="tab-data-2">
                                            <?php
                                            if (!$widget_data['itg-block-6']['block_title']) {
                                                print 'Tab 1';
                                            }
                                            else {
                                                print $widget_data['itg-block-6']['block_title'];
                                            }
                                            ?>
                                        </span>
                                    </div>
                                    <div class="itg-widget-child tab-data tab-data-1">
                                        <div class="droppable <?php print $gray_bg_layout; ?>">
                                            <div class="widget-wrapper <?php print $widget_data['itg-block-5']['widget_name']; ?>">
<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
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
                                                      print '<div class="widget-placeholder"><span>Trending videos</span></div>';
                                                    } 
                                                  ?>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="itg-widget-child tab-data tab-data-2 hide">
                                        <div class="droppable <?php print $gray_bg_layout; ?>"> 
                                            <div class="widget-wrapper <?php print $widget_data['itg-block-6']['widget_name']; ?>"> 
<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                    </div>  
<?php } ?>                   
                                                <div class="data-holder" id="itg-block-6">
                                                  <?php
                                                    if (isset($widget_data['itg-block-6']['widget'])) {
                                                      print $widget_data['itg-block-6']['widget']; 
                                                    } else{
                                                      print '<div class="widget-placeholder"><span>Top takes</span></div>';
                                                    } 
                                                  ?>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                        </div>
                    </div>
                </div>

                <!--Common section strat here-->
<?php if (isset($widget_data['itg-block-7']['widget_name']) || isset($widget_data['itg-block-8']['widget_name']) || isset($widget_data['itg-block-9']['widget_name']) || $theme == 'itgadmin') { ?>
                    <div class="row itg-common-section">

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-help-text">Section Card</div>
                              <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-7']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-7']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-7']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-7"><?php print $widget_data['itg-block-7']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-7">
                                          <?php
                                            if (isset($widget_data['itg-block-7']['widget'])) {
                                              print $widget_data['itg-block-7']['widget']; 
                                            } else{
                                              print '<div class="widget-placeholder"><span>Section card</span></div>';
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>  
                        </div>

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-help-text">Section Card</div>
                              <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-8']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-8']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-8']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-8"><?php print $widget_data['itg-block-8']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-8']['block_title']; ?>" name="itg-block-8" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-8">
                                          <?php
                                            if (isset($widget_data['itg-block-8']['widget'])) {
                                              print $widget_data['itg-block-8']['widget']; 
                                            } else{
                                              print '<div class="widget-placeholder"><span>Section card</span></div>';
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>
                        </div>

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-help-text">Section Card</div>
                              <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-9']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-9']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-9']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-9"><?php print $widget_data['itg-block-9']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-9']['block_title']; ?>" name="itg-block-9" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-9">
                                          <?php
                                            if (isset($widget_data['itg-block-9']['widget'])) {
                                              print $widget_data['itg-block-9']['widget']; 
                                            } else{
                                              print '<div class="widget-placeholder"><span>Section card</span></div>';
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>          
                        </div>

                    </div>
<?php } ?>
                <!--End of Common section-->

                <!--Common section strat here-->
<?php if (isset($widget_data['itg-block-17']['widget_name']) || isset($widget_data['itg-block-18']['widget_name']) || isset($widget_data['itg-block-19']['widget_name']) || $theme == 'itgadmin') { ?>
                    <div class="row itg-common-section">

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-help-text">Section Card</div>
                              <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-17']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-17']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-17']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-17"><?php print $widget_data['itg-block-17']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-17']['block_title']; ?>" name="itg-block-17" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-17">
                                          <?php
                                            if (isset($widget_data['itg-block-17']['widget'])) {
                                              print $widget_data['itg-block-17']['widget']; 
                                            } else{
                                              print '<div class="widget-placeholder"><span>Section card</span></div>';
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>  
                        </div>

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-help-text">Section Card</div>
                              <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-18']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-18']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-18']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-18"><?php print $widget_data['itg-block-18']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-18']['block_title']; ?>" name="itg-block-18" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-18">
                                          <?php
                                            if (isset($widget_data['itg-block-18']['widget'])) {
                                              print $widget_data['itg-block-18']['widget']; 
                                            } else{
                                              print '<div class="widget-placeholder"><span>Section card</span></div>';
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>
                        </div>
                        
                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-help-text">Section Card</div>
                              <?php } ?>
                            <div class="itg-widget">
                              
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-19']['widget_name']; ?>">
                                    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-19']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-19']['block_title']; ?></span>
                                    <?php } ?>
                                        <!-- for admin  -->
                                   <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-19"><?php print $widget_data['itg-block-19']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-19']['block_title']; ?>" name="itg-block-19" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
                                    <?php } ?>  

                                        <div class="data-holder" id="itg-block-19">
                                          <?php
                                            if (isset($widget_data['itg-block-19']['widget'])) {
                                              print $widget_data['itg-block-19']['widget']; 
                                            } else{
                                              print '<div class="widget-placeholder"><span>Section card</span></div>';
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>          
                        </div>
                        

                    </div>
<?php } ?>
                <!--End of Common section-->

                <!--Don't miss and Ad section starts here-->
                                    <?php if (isset($widget_data['itg-block-10']['widget_name']) || $theme == 'itgadmin') { ?>  
                    <div class="row itg-h321-section">
                        <div class="col-md-8 col-sm-12 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-help-text">Template widgets ( <strong>Don't Miss</strong> )</div>
                                  <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-10']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-10']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-10']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-10"><?php print $widget_data['itg-block-10']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-10']['block_title']; ?>" name="itg-block-10" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-10">
                                          <?php
                                            if (isset($widget_data['itg-block-10']['widget'])) {
                                              print $widget_data['itg-block-10']['widget']; 
                                            } else{
                                              print "<div class='widget-placeholder'><span>Don't miss</span></div>";
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>  
                        </div>
                        <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                    <div class="widget-help-text">Non Draggable ( <strong>Ad Widget</strong> )</div>
                                  <?php } ?>
                            <div class="itg-widget">
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
<?php } ?>
                <!--End of Don't miss and Ad section-->  

                <!--Photo slider and Watch now section starts here-->
                                    <?php if (isset($widget_data['itg-block-12']['widget_name']) || isset($widget_data['itg-block-13']['widget_name']) || $theme == 'itgadmin') { ?>
                    <div class="row itg-h450-section">
                        <div class="col-md-8 col-sm-12 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Template widgets ( <strong>Photo Carousel</strong> )</div>
                          <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-12']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-12']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-12']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-12"><?php print $widget_data['itg-block-12']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-12']['block_title']; ?>" name="itg-block-12" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-12">
                                          <?php
                                            if (isset($widget_data['itg-block-12']['widget'])) {
                                              print $widget_data['itg-block-12']['widget']; 
                                            } else{
                                              print "<div class='widget-placeholder'><span>Photo carousel</span></div>";
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>  
                        </div>
                        <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Template widgets ( <strong>Watch Right Now</strong> )</div>
                          <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-13']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-13']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-13']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-13"><?php print $widget_data['itg-block-13']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-13']['block_title']; ?>" name="itg-block-13" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-13">
                                          <?php
                                            if (isset($widget_data['itg-block-13']['widget'])) {
                                              print $widget_data['itg-block-13']['widget']; 
                                            } else{
                                              print "<div class='widget-placeholder'><span>Watch</span></div>";
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>  
                        </div>
                    </div>
<?php } ?>
                <!--Photo slider and Watch now section starts here-->   

                <!--Common section strat here-->
<?php if (isset($widget_data['itg-block-14']['widget_name']) || isset($widget_data['itg-block-15']['widget_name']) || isset($widget_data['itg-block-16']['widget_name']) || $theme == 'itgadmin') { ?>
                    <div class="row itg-common-section">

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Section Card</div>
                          <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-14']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-14']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-14']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-14"><?php print $widget_data['itg-block-14']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-14']['block_title']; ?>" name="itg-block-14" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-14">
                                          <?php
                                            if (isset($widget_data['itg-block-14']['widget'])) {
                                              print $widget_data['itg-block-14']['widget']; 
                                            } else{
                                              print "<div class='widget-placeholder'><span>Section card</span></div>";
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>  
                        </div>

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-itg-block-15">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Section Card</div>
                          <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-15']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-15']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-15']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-15"><?php print $widget_data['itg-block-15']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-15']['block_title']; ?>" name="itg-block-15" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-15">
                                          <?php
                                            if (isset($widget_data['itg-block-15']['widget'])) {
                                              print $widget_data['itg-block-15']['widget']; 
                                            } else{
                                              print "<div class='widget-placeholder'><span>Section card</span></div>";
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>
                        </div>

                        <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-itg-block-16">
                          <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Section Card</div>
                          <?php } ?>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-16']['widget_name']; ?>">
    <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-16']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-16']['block_title']; ?></span>
    <?php } ?>
                                        <!-- for admin  -->
    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <span class="widget-title" data-id="itg-block-16"><?php print $widget_data['itg-block-16']['block_title']; ?></span>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-16']['block_title']; ?>" name="itg-block-16" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                            </div>
    <?php } ?>  

                                        <div class="data-holder" id="itg-block-16">
                                          <?php
                                            if (isset($widget_data['itg-block-16']['widget'])) {
                                              print $widget_data['itg-block-16']['widget']; 
                                            } else{
                                              print "<div class='widget-placeholder'><span>Section card</span></div>";
                                            } 
                                          ?>
                                        </div>
                                    </div>             
                                </div>               
                            </div>          
                        </div>
                        <div class="load-more-wrapper"><a href="javascript:void(0)" class="add-more-block"><?php echo t('Load More'); ?></a></div>
                    </div>
                <?php } ?>
                <!--Common section add more strat here-->
                <?php if ($theme == 'itgadmin') {
                    $count_widget = 19;
                    ?>
                    <?php
                    $last_val = 0;
                    $divcounter = 1;
                    $divcou = 0;
                    ?>
                    <?php for ($count = 1; $count <= EXTRA_SECTION_CARDS; $count+=3) { ?>
                        <?php
                        $widget_name1 = 'itg-block-' . ($count_widget + 1);
                        $widget_name2 = 'itg-block-' . ($count_widget + 2);
                        $widget_name3 = 'itg-block-' . ($count_widget + 3);
                        ?>

                        <?php if (!empty($widget_data[$widget_name1]['widget_name']) || !empty($widget_data[$widget_name2]['widget_name']) || !empty($widget_data[$widget_name3]['widget_name']) || $theme == 'itgadmin') { ?>
                            <?php
                            $display_style = 'style="display:none"';
                            if ($widget_data[$widget_name1]['widget_name'] != null || $widget_data[$widget_name2]['widget_name'] != null || $widget_data[$widget_name3]['widget_name'] != null) {
                                $last_val++;
                                $display_style = 'style="display:block"';
                            }
                            if ($theme != 'itgadmin') {
                                $display_style = 'style="display:none"';
                            }
                            ?>
                            <div class="row itg-common-section mt-50 show-on-add" <?php echo $display_style; ?> id="content-section-widget-<?php print $divcounter; ?>">

                                <div class="col-md-4 col-sm-4 col-xs-12 sectioncart" id="section-cart-<?php echo $widget_name1; ?>">
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Section Card</div>
                          <?php } ?>
                                    <div class="itg-widget">
                                        <div class="droppable <?php print $gray_bg_layout; ?>">
                                            <div class="widget-wrapper <?php print $widget_data[$widget_name1]['widget_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data[$widget_name1]['block_title'])) { ?>
                                                    <span class="widget-title"><?php print $widget_data[$widget_name1]['block_title']; ?></span>
                                                <?php } ?>
                                                <!-- for admin  -->
            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="<?php print $widget_name1; ?>"><?php print $widget_data[$widget_name1]['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data[$widget_name1]['block_title']; ?>" name="<?php print $widget_name1; ?>" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="<?php print $widget_name1; ?>"><i class="fa fa-times"></i></a></span>
                                                    </div>
            <?php } ?>  

                                                <div class="data-holder" id="<?php print $widget_name1; ?>"><?php print $widget_data[$widget_name1]['widget']; ?></div>
                                            </div>             
                                        </div>               
                                    </div>  
                                </div>

                                <div class="col-md-4 col-sm-4 col-xs-12 sectioncart" id="section-cart-<?php echo $widget_name2; ?>">
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Section Card</div>
                          <?php } ?>
                                    <div class="itg-widget">
                                        <div class="droppable <?php print $gray_bg_layout; ?>">
                                            <div class="widget-wrapper <?php print $widget_data[$widget_name2]['widget_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data[$widget_name2]['block_title'])) { ?>
                                                    <span class="widget-title"><?php print $widget_data[$widget_name2]['block_title']; ?></span>
                                                <?php } ?>
                                                <!-- for admin  -->
            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="<?php print $widget_name2; ?>"><?php print $widget_data[$widget_name2]['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data[$widget_name2]['block_title']; ?>" name="<?php print $widget_name2; ?>" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="<?php print $widget_name2; ?>"><i class="fa fa-times"></i></a></span>
                                                    </div>
            <?php } ?>  

                                                <div class="data-holder" id="<?php print $widget_name2; ?>"><?php print $widget_data[$widget_name2]['widget']; ?></div>
                                            </div>             
                                        </div>               
                                    </div>
                                </div>

                                <div class="col-md-4 col-sm-4 col-xs-12 sectioncart" id="section-cart-<?php echo $widget_name3; ?>">
                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                            <div class="widget-help-text">Section Card</div>
                          <?php } ?>
                                    <div class="itg-widget">
                                        <div class="droppable <?php print $gray_bg_layout; ?>">
                                            <div class="widget-wrapper <?php print $widget_data[$widget_name3]['widget_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data[$widget_name3]['block_title'])) { ?>
                                                    <span class="widget-title"><?php print $widget_data[$widget_name3]['block_title']; ?></span>
                                                <?php } ?>
                                                <!-- for admin  -->
            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="<?php print $widget_name3; ?>"><?php print $widget_data[$widget_name3]['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data[$widget_name3]['block_title']; ?>" name="<?php print $widget_name3; ?>" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="<?php print $widget_name3; ?>"><i class="fa fa-times"></i></a></span>
                                                    </div>
            <?php } ?>  

                                                <div class="data-holder" id="<?php print $widget_name3; ?>"><?php print $widget_data[$widget_name3]['widget']; ?></div>
                                            </div>             
                                        </div>               
                                    </div>          
                                </div>
                                    <?php $divcou = 3 + $divcou; ?><div class="load-more-wrapper">
                                    <?php if ((EXTRA_SECTION_CARDS != $divcou) && ($divcou != $last_val)) { ?>
                                        <a href="javascript:void(0)" class="add-more-block">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
                                    <?php } if ($theme == 'itgadmin') { ?>

                                        <a href="javascript:void(0)" class="removes-more-block">Less <i class="fa fa-chevron-circle-up" aria-hidden="true"></i></a>
            <?php } ?>
                                </div>
                            </div>

                        <?php } ?>

        <?php $count_widget = 3 + $count_widget;
        $divcounter++; ?>
    <?php }
} ?>
                 <?php
          if ($theme != 'itgadmin') {
            print '<div id="second-section-card"></div>';
            if (!empty($widget_data['itg-block-20']['widget']) || !empty($widget_data['itg-block-21']['widget']) || !empty($widget_data['itg-block-22']['widget'])) {
              ?>
              <div class="load-more-wrapper-front">
                <a href="javascript:void(0)" class="add-more-block-front">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
              </div>
  <?php
  }
}?>
                <!--End of Common section-->
                <div class="no-more-card" style="display:none">No More Result Found.</div>

                <!--Load More Loader
                <div class="load-more">
                  <img src="<?php //echo base_path() ?>sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />
                </div>
                <!--End of Loader-->

<?php //print render($page['content']);  ?>
                <!--Start third party widgets -->
                <div>
                    <!--
                    <div class="vukkul-comment">
                    <div id="vuukle_div"></div>            
                    <?php
                    if (function_exists('vukkul_view')) {
                        vukkul_view();
                    }
                    ?>     
                    </div>
                  </div>
                    -->  
                    <!--End third party widgets -->


                </div>
                <!--------------------------------Code for Front tpl---------------------------------------->
        <?php if ($theme != 'itgadmin') { ?>
    <?php //print $feed_icons;   ?>
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
        <?php //print $sidebar_first;  ?>
            <?php //print $sidebar_second;  ?>
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
<?php
}
if ($theme != 'itgadmin') {
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
<?php if ($_SERVER['HTTP_HOST'] == PARENT_SSO) { ?>
    <script>
        window.addEventListener("message", function(ev) {
            if (ev.data.message === "requestResult") {
                // ev.source is the opener
                ev.source.postMessage({message: "deliverResult", result: true}, "*");
            }
        });

    </script>
<?php } ?>

<div class="activate-message" style="display:none">
    <div class="message-body">
        <span class="close-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
        <p>Your Account Activated Successfully!</p>
    </div>
</div>