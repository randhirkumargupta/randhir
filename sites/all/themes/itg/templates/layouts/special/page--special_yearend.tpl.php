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

<?php
    $itg_class = 'itg-admin';
    if ($theme != 'itgadmin') {
      $itg_class = 'itg-front';
    }
   
?>
<div class="itg-layout-container <?php echo $itg_class; ?>"> 
    <!-- Breaking news band -->    
    <?php if (!empty($page['breaking_news'])): ?>
    <div class="row">
        <div class="col-md-12">
          <?php print render($page['breaking_news']); ?>
        </div>      
    </div>    
    <?php endif; ?>
    <div class="row yearend-page">
        <div class="col-md-8 col-sm-12 col-sx-12 left-side">
          <div class="widget-help-text"><?php print t('Special widgets');?> ( <strong><?php print t('Yearender featured'); ?></strong> )</div>
            <div class="itg-643">
                
                <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">                                  
                    <div class="data-holder" id="itg-block-1">
                      <?php
                        if (isset($widget_data['itg-block-1']['widget'])) {
                          print $widget_data['itg-block-1']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Yearender featured').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
                
            </div> 
            <div class="itg-1550 mt-50">
                <div class="widget-help-text"><?php print t('Special widgets');?> ( <strong><?php print t('Yearender Galleries'); ?></strong> )</div>
              <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-2']['widget_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-2']['block_title'])) { ?>
                   <h4 class="heading"><?php print $widget_data['itg-block-2']['block_title']; ?></h4>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <?php if (!empty($widget_data['itg-block-2']['block_title'])) {?>
                        <span class="widget-title" data-id="itg-block-2"><?php print $widget_data['itg-block-2']['block_title']; ?></span>
                        <?php } ?>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-block-2">
                      <?php
                        if (isset($widget_data['itg-block-2']['widget'])) {
                          print $widget_data['itg-block-2']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Year Ender').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
                
            
            
            </div> 
        </div>    
        <div class="col-md-4 col-sm-12 col-sx-12 right-side">    
          <div class="widget-help-text"><?php print t('Non Draggable'); ?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
            <div class="">
              <div class="itg-widget">
                    <div class="ad-widget droppable">
                      <div class="sidebar-ad">
                        <?php
                          $block = block_load('itg_ads', ADS_RHS1);   
                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                          print render($render_array);
                         ?>
                      </div>
                    </div>
                  </div>
                
            </div> 
            <div class="itg-785 mt-50">
              <div class="widget-help-text"><?php print t('Special widgets');?> ( <strong><?php print t('Top News'); ?></strong> )</div>
                <div class="itg-widget">
                    <div class="droppable <?php print $gray_bg_layout; ?>">
                        <div class="widget-wrapper <?php print $widget_data['itg-block-3']['widget_name']; ?>">
                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-3']['block_title'])) { ?>
                                <h4 class="heading"><?php print $widget_data['itg-block-3']['block_title']; ?></h4>
                            <?php } ?>
                            <!-- for admin  -->
                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-settings">
                                    <div class="widget-title-wrapper">
                                        <?php if (!empty($widget_data['itg-block-3']['block_title'])) { ?>
                                            <span class="widget-title" data-id="itg-block-3"><?php print $widget_data['itg-block-3']['block_title']; ?></span>
                                        <?php } ?>
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
                                  print '<div class="widget-placeholder"><span>'.t('Top news').'</span></div>';
                                } 
                              ?>
                            </div>
                        </div>             
                    </div>               
                </div>  
                
                
            </div> 
            <div class="mt-50">
              <div class="widget-help-text"><?php print t('Non Draggable');?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
                <div class="itg-widget">
                    <div class="ad-widget droppable">
                      <div class="sidebar-ad">
                        <?php
                          $block = block_load('itg_ads', ADS_RHS2);   
                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                          print render($render_array);
                        ?></div>
                    </div>
                  </div>
            </div> 
            
            <div class="itg-628 mt-50">
               <div class="widget-help-text"><?php print t('Special widgets');?> ( <strong><?php print t('Top videos'); ?></strong> )</div>
                <div class="itg-widget">
                    <div class="droppable <?php print $gray_bg_layout; ?>">
                        <div class="widget-wrapper <?php print $widget_data['itg-block-4']['widget_name']; ?>">
                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-4']['block_title'])) { ?>
                                <h4 class="heading"><?php print $widget_data['itg-block-4']['block_title']; ?></h4>
                            <?php } ?>
                            <!-- for admin  -->
                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                <div class="widget-settings">
                                    <div class="widget-title-wrapper">
                                        <?php if (!empty($widget_data['itg-block-4']['block_title'])) { ?>
                                            <span class="widget-title" data-id="itg-block-4"><?php print $widget_data['itg-block-4']['block_title']; ?></span>
                                        <?php } ?>
                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-4']['block_title']; ?>" name="itg-block-4" class="block_title_id" placeholder="Enter Title" />
                                    </div>
                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                </div>
                            <?php } ?>  

                            <div class="data-holder" id="itg-block-4">
                              <?php
                                if (isset($widget_data['itg-block-2']['widget'])) {
                                  print $widget_data['itg-block-2']['widget']; 
                                } else{
                                  print '<div class="widget-placeholder"><span>'.t('Top videos').'</span></div>';
                                } 
                              ?>
                            </div>
                        </div>             
                    </div>               
                </div>
            </div>                 
        </div>    
    </div>

<!--End of Common add more section-->  

  
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