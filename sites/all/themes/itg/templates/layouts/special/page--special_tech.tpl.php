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
 

<div class="itg-layout-container <?php echo $itg_class; ?> tech-layout-page">
    <!-- Breaking news band -->    
    <?php if (!empty($page['breaking_news'])): ?>
    <div class="row">
        <div class="col-md-12">
          <?php print render($page['breaking_news']); ?>
        </div>      
    </div>    
    <?php endif; ?>
    <?php // $block = module_invoke('itg_menu_manager', 'block_view', 'third_level_menu');
 // print render($block['content']); ?>
    <?php if(isset($widget_data['big_story'])) : ?>
    <div class="row">
        <div class="col-md-12">
            <?php print $widget_data['big_story']; ?>
        </div>    
    </div>
    <?php endif; ?>

    <div class="row itg-top-section">
         <div class="top-block">
<div class="col-md-8">
  <div class="widget-help-text"><?php print t('Special widgets');?> ( <strong><?php print t('Tech Featured'); ?></strong> )</div>
            <div class="">
              <div class="itg-widget">
                  <div class="droppable itg-layout-672 <?php print $gray_bg_layout; ?>">
                  <div id="tech-new-block" class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name'].$widget_data['itg-block-1']['widget_display_name']; ?>">
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
                    <div class="data-holder" id="itg-block-1">
                      <div class="data-holder" id="itg-block-1">
                        <?php
                          if (isset($widget_data['itg-block-1']['widget'])) {
                            print $widget_data['itg-block-1']['widget']; 
                          } else{
                            print '<div class="widget-placeholder"><span>'.t('Tech Featured').'</span></div>';
                          } 
                        ?>
                      </div>
                    </div>
                  </div>                     
                </div>
              </div>
            </div>

</div>
            <div class="col-md-4">              
            <div class="auto-block-3">
              <div class="widget-help-text"><?php print t('Non Draggable');?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
                <div class="itg-widget-parent m-bottom40">
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
                    <div class="itg-widget trending-list">
                        <div class="widget-help-text">Special widgets ( <strong>Most read</strong> )</div>
                      <div class="itg-widget-child">
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
                            <div class="data-holder"  id="itg-block-3">
                              <?php
                                if (isset($widget_data['itg-block-3']['widget'])) {
                                  print $widget_data['itg-block-3']['widget']; 
                                } else{
                                  print '<div class="widget-placeholder"><span>'.t('Most read').'</span></div>';
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
  <?php if (isset($widget_data['itg-block-4']['widget_name']) || isset($widget_data['itg-block-5']['widget_name']) || isset($widget_data['itg-block-6']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section">

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
          <div class="widget-help-text">Section Card</div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-4']['widget_name'].$widget_data['itg-block-4']['widget_display_name']; ?>">
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
                  
                    <div class="data-holder" id="itg-block-4">
                      <?php
                        if (isset($widget_data['itg-block-4']['widget'])) {
                          print $widget_data['itg-block-4']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('Section Card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-5']['widget_name'].$widget_data['itg-block-5']['widget_display_name']; ?>">
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
                  
                    <div class="data-holder" id="itg-block-5">
                      <?php
                        if (isset($widget_data['itg-block-5']['widget'])) {
                          print $widget_data['itg-block-5']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
          <div class="widget-help-text">Section Card</div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-6']['widget_name'].$widget_data['itg-block-6']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-6']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-6']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-block-6"><?php print $widget_data['itg-block-6']['block_title']; ?></span>
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
                          print '<div class="widget-placeholder"><span>'.t('Section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>          
        </div>

    </div>
  <?php } ?>
  
  
  
  <?php if (isset($widget_data['itg-block-10']['widget_name']) || isset($widget_data['itg-block-11']['widget_name']) || isset($widget_data['itg-block-12']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section">

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
          <div class="widget-help-text">Section Card</div>
            <div class="itg-widget">
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
                  
                     <div class="data-holder" id="itg-block-10">
                       <?php
                        if (isset($widget_data['itg-block-10']['widget'])) {
                          print $widget_data['itg-block-10']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Section card').'</span></div>';
                        } 
                      ?>
                     </div>
                  </div>             
                </div>               
            </div>  
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('Section Card'); ?></div>
            <div class="itg-widget">
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
                  
                    <div class="data-holder" id="itg-block-11">
                      <?php
                        if (isset($widget_data['itg-block-11']['widget'])) {
                          print $widget_data['itg-block-11']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>
        </div>

        <div class="col-md-4 col-sm-4 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('Section Card'); ?></div>
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
                  
                    <div class="data-holder" id="itg-block-12">
                      <?php
                        if (isset($widget_data['itg-block-12']['widget'])) {
                          print $widget_data['itg-block-12']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Section card').'</span></div>';
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
<?php if (isset($widget_data['itg-block-7']['widget_name']) || $theme == 'itgadmin') { ?>  
  <div class="row itg-h321-section">
        <div class="col-md-8 col-sm-12 col-xs-12 mt-50">          
          <div class="widget-help-text"><?php print t('Special card'); ?> ( <strong><?php print t('Reviews');?></strong> )</div>
            <div class="itg-widget">
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
                  
                    <div class="data-holder" id="itg-block-7">
                      <?php
                        if (isset($widget_data['itg-block-7']['widget'])) {
                          print $widget_data['itg-block-7']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Reviews').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
         <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
           <div class="widget-help-text"><?php print t('Non Draggable'); ?> ( <strong><?php print t('Ad widget');?></strong> )</div>
            <div class="itg-widget">
              <div class="ad-widget">
                      <div class="sidebar-ad">
                         <?php
                          $block = block_load('itg_ads', ADS_RHS2);   
                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                          print render($render_array);
                        ?></div>
                    </div>
            </div>  
        </div>
     </div>
<?php } ?>
  <!--End of Don't miss and Ad section-->  
  
  <!--Photo slider and Watch now section starts here-->
  <?php if (isset($widget_data['itg-block-8']['widget_name']) || isset($widget_data['itg-block-9']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-h450-section">
        <div class="col-md-8 col-sm-12 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('Special widgets');?> ( <strong><?php print t('Photo carousel'); ?></strong> )</div>
            <div class="itg-widget">
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
                  
                    <div class="data-holder" id="itg-block-8">
                      <?php
                        if (isset($widget_data['itg-block-8']['widget'])) {
                          print $widget_data['itg-block-8']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Photo carousel').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
         <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
           <div class="widget-help-text"><?php print t('Section card');?> ( <strong><?php print t('Watch'); ?></strong> )</div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-block-9']['widget_name'].$widget_data['itg-block-9']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-9']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-block-9']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
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
                          print '<div class="widget-placeholder"><span>'.t('Watch').'</span></div>';
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
  
<!--  Tech 2nd last row start here-->
 <?php if (isset($widget_data['itg-block-13']['widget_name']) || isset($widget_data['itg-block-14']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-h385-section">
        <div class="col-md-8 col-sm-12 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('Section card');?> ( <strong><?php print t('Buying guides'); ?></strong> )</div>
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
                  
                    <div class="data-holder" id="itg-block-13" data-widget-style="buying-guid" >
                      <?php
                        if (isset($widget_data['itg-block-13']['widget'])) {
                          print $widget_data['itg-block-13']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Buying guides').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
         <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
           <div class="widget-help-text"><?php print t('Section card'); ?> ( <strong><?php print t('Tech Tips'); ?></strong> )</div>
            <div class="itg-widget">
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
                  
                    <div class="data-holder" id="itg-block-14" data-widget-style="tech-tips" >
                      <?php
                        if (isset($widget_data['itg-block-14']['widget'])) {
                          print $widget_data['itg-block-14']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Tech tips').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
     </div>
  <?php } ?>
  <!--Tech 2nd last row End here-->
  
  <!--Tech last row start here-->
 <?php if (isset($widget_data['itg-block-15']['widget_name']) || isset($widget_data['itg-block-16']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-h396-section">
        <div class="col-md-8 col-sm-12 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('Section card'); ?> ( <strong><?php print t('In-Depth'); ?></strong> )</div>
            <div class="itg-widget">
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
                  
                    <div class="data-holder" id="itg-block-15" data-widget-style="in-depth">
                      <?php
                        if (isset($widget_data['itg-block-15']['widget'])) {
                          print $widget_data['itg-block-15']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('In-Depth').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
         <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
            <div class="widget-help-text"><?php print t('Section card');?> ( <strong><?php print t('Talking points'); ?></strong> )</div>
            <div class="itg-widget">
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
                  
                    <div class="data-holder" id="itg-block-16" data-widget-style="talking-point">
                      <?php
                        if (isset($widget_data['itg-block-4']['widget'])) {
                          print $widget_data['itg-block-4']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Talking points').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
     </div>
  <?php } ?>
  <!--  Tech last row End here--> 
  
  
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
