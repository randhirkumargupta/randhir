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
 

<div class="itg-layout-container <?php echo $itg_class; ?> education-layout-page">

    <div class="row itg-top-section itg-layout-672">
        
        <div class="top-block">
        <div class="col-md-8">
            <div class="">
              <div class="itg-widget">
                  <div class="droppable <?php print $gray_bg_layout; ?>">
                  <div id="education-new-block" class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name'].$widget_data['itg-block-1']['widget_display_name']; ?>">
                      <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-1']['block_title'])) { ?>
                                <span class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></span>
                                 <?php } ?>
                              <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-settings">
                                  <div class="widget-title-wrapper">
                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id" placeholder="Enter Title" />
                                  </div>
                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                </div>  
                              <?php } ?>    
                    <div class="data-holder" id="itg-block-1"><?php print $widget_data['itg-block-1']['widget']; ?></div>
                  </div>                     
                </div>
              </div>
            </div>
        </div>
            <div class="col-md-4">
            <div class="auto-block-3">
                <div class="row">
                <div class="itg-widget-parent m-bottom40 col-md-12 col-sm-6 col-xs-12">
                  <div class="itg-widget">
                    <div class="ad-widget">
                      <div class="sidebar-ad"><?php print ($itg_ad['200*200_right_bar_ad1']);?></div>
                    </div>

                  </div>
                </div>
                    <div class="itg-widget trending-list col-md-12 col-sm-6 col-xs-12">                        
                      <div class="itg-widget-child shadow-on">
                        <div class="droppable <?php print $gray_bg_layout; ?>">
                          <div class="widget-wrapper <?php print $widget_data['itg-block-3']['widget_name'].$widget_data['itg-block-3']['widget_display_name']; ?>">
                             <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-3']['block_title'])) { ?>
                                    <span class="widget-title"><?php print $widget_data['itg-block-3']['block_title']; ?></span>
                                 <?php } ?>
                              <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-settings">
                                  <div class="widget-title-wrapper">
                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-3']['block_title']; ?>" name="itg-block-3" class="block_title_id" placeholder="Enter Title" />
                                  </div>
                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                </div>  
                              <?php } ?>                   
                            <div class="data-holder" widget-style="auto-road-trip" id="itg-block-3"><?php print $widget_data['itg-block-3']['widget']; ?></div>
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
  
  
  
  <?php if (isset($widget_data['itg-block-4']['widget_name']) || isset($widget_data['itg-block-5']['widget_name']) || isset($widget_data['itg-block-19']['widget_name']) || isset($widget_data['itg-block-6']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section itg-layout-565">

        <div class="col-md-4 col-sm-6 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
              
               <div class="widget-wrapper section_wise_order <?php print $widget_data['itg-block-4']['widget_name'].$widget_data['itg-block-4']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-4']['block_title'])) { ?>

                     <span class="widget-title"><?php print $widget_data['itg-block-4']['block_title']; ?></span>
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
                  
                    <div class="data-holder" id="itg-block-4" widget-style="edu-exam"><?php print $widget_data['itg-block-4']['widget']; ?><?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-4']['block_title'])  && ($widget_data['itg-block-4']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-4']['more_url']; ?></span><?php } ?></div>
                  </div> 
                  
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-6 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">

             

               <div class="widget-wrapper section_wise_order <?php print $widget_data['itg-block-5']['widget_name'].$widget_data['itg-block-5']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-5']['block_title'])) { ?>

                     <span class="widget-title"><?php print $widget_data['itg-block-5']['block_title']; ?></span>
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
                  
                    <div class="data-holder" id="itg-block-5"  widget-style="edu-gov-jobs"><?php print $widget_data['itg-block-5']['widget']; ?><?php if (($theme != 'itgadmin' || isset($preview)) && ($widget_data['itg-block-5']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-5']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
            <div class="row">
                <div class="col-md-12 col-sm-6 col-xs-12 m-bottom40">
                        <div class="itg-widget-parent shadow-on">
                            <div class="droppable <?php print $gray_bg_layout; ?>">
                                <div class="widget-wrapper <?php print $widget_data['itg-block-6']['widget_name'] . $widget_data['itg-block-6']['widget_display_name']; ?>">
                                    <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-6']['block_title'])) { ?>
                                        <span class="widget-title"><?php print $widget_data['itg-block-6']['block_title']; ?></span>
                                    <?php } ?>
                                    <!-- for admin  -->
                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <span class="widget-title" data-id="itg-block-6"><?php print $widget_data['itg-block-6']['block_title']; ?></span>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
                                    <?php } ?>  

                                    <div class="data-holder itg-newaletter" id="itg-block-6"><?php $block = module_invoke('itg_newsletter', 'block_view', 'register_for_more_updates');
  print render($block['content']); ?></div>
                                </div>             
                            </div>               
                        </div>
                </div>
                
                <div class="col-md-12 col-sm-6 col-xs-12">
                        <div class="itg-widget-child shadow-on">
                            <div class="droppable <?php print $gray_bg_layout; ?>">
                                <div class="widget-wrapper <?php print $widget_data['itg-block-19']['widget_name'] . $widget_data['itg-block-19']['widget_display_name']; ?>">
                                    <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-19']['block_title'])) { ?>
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

                                    <div class="data-holder ask-question" id="itg-block-19"><?php $block = module_invoke('itg_ask_expert', 'block_view', 'custom_ask_expert_form_block');
  print render($block['content']); ?></div>
                                </div>             
                            </div>               
                        </div>
                    </div>
                
                </div>
        </div>

    </div>
  <?php } ?>
  <?php if (isset($widget_data['itg-block-16']['widget_name']) || isset($widget_data['itg-block-17']['widget_name']) || isset($widget_data['itg-block-18']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section itg-295-layout">

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-16']['widget_name'].$widget_data['itg-block-16']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-16']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-16']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-16"><?php print $widget_data['itg-block-16']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-16']['block_title']; ?>" name="itg-block-16" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-16" widget-style="edu-notification"><?php print $widget_data['itg-block-16']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-16']['block_title'])  && ($widget_data['itg-block-16']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-16']['more_url'];  ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-17']['widget_name'].$widget_data['itg-block-17']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-17']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-17']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-17"><?php print $widget_data['itg-block-17']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-17']['block_title']; ?>" name="itg-block-17" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-17" ><?php print $widget_data['itg-block-17']['widget']; ?></div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-18']['widget_name'].$widget_data['itg-block-18']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-18']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-18']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-18"><?php print $widget_data['itg-block-18']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-18']['block_title']; ?>" name="itg-block-18" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                     <div class="data-holder" id="itg-block-18" widget-style="edu-tips-and-trick"><?php print $widget_data['itg-block-18']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-18']['block_title'])  && ($widget_data['itg-block-18']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-18']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>          
        </div>

    </div>
  <?php } ?>
   <?php if (isset($widget_data['itg-block-7']['widget_name']) || isset($widget_data['itg-block-8']['widget_name']) || isset($widget_data['itg-block-9']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section itg-325-layout">

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-7']['widget_name'].$widget_data['itg-block-7']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-7']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-7']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-7"><?php print $widget_data['itg-block-7']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-7" widget-style="edu-featurefilia"><?php print $widget_data['itg-block-7']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-7']['block_title']) && ($widget_data['itg-block-7']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-7']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-8']['widget_name'].$widget_data['itg-block-8']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-8']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-8']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-8"><?php print $widget_data['itg-block-8']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-8']['block_title']; ?>" name="itg-block-8" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-8" widget-style="edu-jobs-and-career" ><?php print $widget_data['itg-block-8']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-8']['block_title']) && ($widget_data['itg-block-8']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-8']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget-parent">
                  <div class="itg-widget">
                    <div class="ad-widget">
                      <div class="sidebar-ad"><?php print ($itg_ad['200*200_right_bar_ad1']);?></div>
                    </div>
                </div>         
        </div>

    </div>
  <?php } ?>
    </div>
  
   <?php if (isset($widget_data['itg-block-10']['widget_name']) || isset($widget_data['itg-block-11']['widget_name']) || isset($widget_data['itg-block-12']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section itg-345-layout">

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-10']['widget_name'].$widget_data['itg-block-10']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-10']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-10']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-10"><?php print $widget_data['itg-block-10']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-10']['block_title']; ?>" name="itg-block-10" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-10" widget-style="edu-sample-paper"><?php print $widget_data['itg-block-10']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-10']['block_title']) && ($widget_data['itg-block-10']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-10']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-11']['widget_name'].$widget_data['itg-block-11']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-11']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-11']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-11"><?php print $widget_data['itg-block-11']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-11']['block_title']; ?>" name="itg-block-11" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-11" ><?php print $widget_data['itg-block-11']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-11']['block_title']) && ($widget_data['itg-block-11']['widget_name'] != 'custom_html_widget')) { ?><span><?php print $widget_data['itg-block-11']['more_url']; ?></span> <?php } ?></div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50 grey-bg">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-12']['widget_name'].$widget_data['itg-block-12']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-12']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-12']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-12"><?php print $widget_data['itg-block-12']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-12']['block_title']; ?>" name="itg-block-12" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-12"><?php print $widget_data['itg-block-12']['widget']; ?></div>
                  </div>             
                </div>               
            </div>          
        </div>

    </div>
  <?php } ?>
  
  
   <?php if (isset($widget_data['itg-block-13']['widget_name']) || isset($widget_data['itg-block-14']['widget_name']) || isset($widget_data['itg-block-15']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section itg-345-layout">

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-13']['widget_name'].$widget_data['itg-block-13']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-13']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-13']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-13"><?php print $widget_data['itg-block-13']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-13']['block_title']; ?>" name="itg-block-13" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-13" widget-style="edu-from-the-magazine"><?php print $widget_data['itg-block-13']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-13']['block_title']) && ($widget_data['itg-block-13']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-13']['more_url']; ?></span> <?php } ?></div>
                  </div>             
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-14']['widget_name'].$widget_data['itg-block-14']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-14']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-14']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-14"><?php print $widget_data['itg-block-14']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-14']['block_title']; ?>" name="itg-block-14" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-14" widget-style="edu-plan-your-career"><?php print $widget_data['itg-block-14']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-14']['block_title']) && ($widget_data['itg-block-14']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-14']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
            <div class="itg-widget shadow-on">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-15']['widget_name'].$widget_data['itg-block-15']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-15']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-15']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-15"><?php print $widget_data['itg-block-15']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-15']['block_title']; ?>" name="itg-block-15" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-15" ><?php print $widget_data['itg-block-15']['widget']; ?> <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-15']['block_title']) && ($widget_data['itg-block-15']['widget_name'] != 'custom_html_widget')) { ?><span class="more"><?php print $widget_data['itg-block-15']['more_url']; ?></span><?php } ?></div>
                  </div>             
                </div>               
            </div>          
        </div>

    </div>
  <?php } ?>
  
  <!--End of Common section-->
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
