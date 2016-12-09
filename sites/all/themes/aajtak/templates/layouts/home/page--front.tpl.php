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
<?php if ($theme != 'itgadmin') { ?>
  <div id="page">
    <header class="header" id="header" role="banner">
      <div class="logo-n-three-bar">
        <div class="three-bar"><span></span></div>
  <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
        <?php endif; ?>
      </div>
        <?php print render($page['header']); ?>
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
      <div class="aajtak-layout-container <?php echo $itg_class; ?>">
      <?php if (isset($widget_data['big_story'])) : ?>
          <div class="row">
            <div class="col-md-12">
          <?php print $widget_data['big_story']; ?>
            </div>    
          </div>
            <?php endif; ?>
        <!--1-- Aajtak row starts here--> 
        <?php if (isset($widget_data['itg-block-1']['widget_name']) || $theme == 'itgadmin') { ?>
        <div class="row">
          <div class="col-md-12">
            <div class="aajtak-widget aajtak-slide">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-container <?php print $widget_data['itg-block-1']['widget_name']; ?>">
                 <div class="data-holder" widget-style="aajtak-slider" id="itg-block-1" >
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-1']['block_title'])) { ?>
                     <h2 class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></h2>
                  <?php } ?>
                     <!-- for admin  -->
                     <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                     <div class="layout-heading-wrapper">
                         <div class="layout-heading">
                            <?php if (isset($widget_data['itg-block-1']['block_title'])) {?>
                            <h2 class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></h2>
                            <?php } ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id" placeholder="Enter Title" />
                         </div>
                         <span class="edit-trigger">Edit</span>
                     </div>
                    <?php } ?> 
                    <?php print $widget_data['itg-block-1']['widget']; ?>
                 </div>
                  </div>             
                </div>               
            </div>
          </div>
        </div>
        <?php } ?>
        <!-- End of Aajtak row-->
        
        <!--2-- Aajtak row starts here-->
        <?php if (isset($widget_data['itg-block-2']['widget_name']) || isset($widget_data['itg-block-3']['widget_name']) || $theme == 'itgadmin') { ?>
        <div class="row">
          <div class="col-md-8">
            <div class="aajtak-widget aajtak-slide">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-container <?php print $widget_data['itg-block-2']['widget_name']; ?>">
                 <div class="data-holder" widget-style="aajtak-slider" id="itg-block-2" >
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-2']['block_title'])) { ?>
                     <h2 class="widget-title"><?php print $widget_data['itg-block-2']['block_title']; ?></h2>
                  <?php } ?>
                     <!-- for admin  -->
                     <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                     <div class="layout-heading-wrapper">
                         <div class="layout-heading">
                            <?php if (isset($widget_data['itg-block-2']['block_title'])) {?>
                            <h2 class="widget-title"><?php print $widget_data['itg-block-2']['block_title']; ?></h2>
                            <?php } ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                         </div>
                         <span class="edit-trigger">Edit</span>
                     </div>
                    <?php } ?>
                    <?php print $widget_data['itg-block-2']['widget']; ?></div>
                  </div>             
                </div>               
            </div>
          </div>
          <div class="col-md-4">
            <div class="aajtak-widget aajtak-stack">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-container <?php print $widget_data['itg-block-3']['widget_name']; ?>">
                 <div class="data-holder grey-bg" widget-style="stack-card-0" id="itg-block-3" >
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-3']['block_title'])) { ?>
                     <h2 class="widget-title"><?php print $widget_data['itg-block-3']['block_title']; ?></h2>
                  <?php } ?>
                    <!-- for admin  -->
                     <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                     <div class="layout-heading-wrapper">
                         <div class="layout-heading">
                            <?php if (isset($widget_data['itg-block-3']['block_title'])) {?>
                            <h2 class="widget-title"><?php print $widget_data['itg-block-3']['block_title']; ?></h2>
                            <?php } ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-3']['block_title']; ?>" name="itg-block-3" class="block_title_id" placeholder="Enter Title" />
                         </div>
                         <span class="edit-trigger">Edit</span>
                     </div>
                    <?php } ?>
                    <?php print $widget_data['itg-block-3']['widget']; ?>
                 </div>
                  </div>             
                </div>               
            </div>
          </div>
        </div>
        <?php } ?>
        <!--End of Aajtak row-->
        
        <!--3-- Aajtak row starts here--> 
        <?php if (isset($widget_data['itg-block-4']['widget_name']) || $theme == 'itgadmin') { ?>
        <div class="row">
          <div class="col-md-12">
            <div class="aajtak-widget aajtak-slide">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-container <?php print $widget_data['itg-block-4']['widget_name']; ?>">
                 <div class="data-holder" widget-style="aajtak-slider" id="itg-block-4" >
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-4']['block_title'])) { ?>
                     <h2 class="widget-title"><?php print $widget_data['itg-block-4']['block_title']; ?></h2>
                  <?php } ?>
                     <!-- for admin  -->
                     <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                     <div class="layout-heading-wrapper">
                         <div class="layout-heading">
                            <?php if (isset($widget_data['itg-block-4']['block_title'])) {?>
                            <h2 class="widget-title"><?php print $widget_data['itg-block-4']['block_title']; ?></h2>
                            <?php } ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-4']['block_title']; ?>" name="itg-block-4" class="block_title_id" placeholder="Enter Title" />
                         </div>
                         <span class="edit-trigger">Edit</span>
                     </div>
                    <?php } ?>
                  
                    <?php print $widget_data['itg-block-4']['widget']; ?></div>
                  </div>             
                </div>               
            </div>
          </div>
        </div>
        <?php } ?>
        <!--End of Aajtak row-->
        
        <!--4-- Aajtak row starts here-->
        <?php if (isset($widget_data['itg-block-5']['widget_name']) || isset($widget_data['itg-block-6']['widget_name']) || $theme == 'itgadmin') { ?>
        <div class="row">
          <div class="col-md-8">
            <div class="aajtak-widget aajtak-slide">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-container <?php print $widget_data['itg-block-5']['widget_name']; ?>">
                 <div class="data-holder" widget-style="aajtak-slider" id="itg-block-5" >
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-5']['block_title'])) { ?>
                     <h2 class="widget-title"><?php print $widget_data['itg-block-5']['block_title']; ?></h2>
                  <?php } ?>
                    <!-- for admin  -->
                     <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                     <div class="layout-heading-wrapper">
                         <div class="layout-heading">
                            <?php if (isset($widget_data['itg-block-5']['block_title'])) {?>
                            <h2 class="widget-title"><?php print $widget_data['itg-block-5']['block_title']; ?></h2>
                            <?php } ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />
                         </div>
                         <span class="edit-trigger">Edit</span>
                     </div>
                    <?php } ?>
                    <?php print $widget_data['itg-block-5']['widget']; ?></div>
                  </div>             
                </div>               
            </div>
          </div>
          <div class="col-md-4">
            <div class="aajtak-widget aajtak-stack">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-container <?php print $widget_data['itg-block-6']['widget_name']; ?>">
                 <div class="data-holder grey-bg" widget-style="stack-card-1" id="itg-block-6" >
                 <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-6']['block_title'])) { ?>
                     <h2 class="widget-title"><?php print $widget_data['itg-block-6']['block_title']; ?></h2>
                  <?php } ?>
                     <!-- for admin  -->
                     <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                     <div class="layout-heading-wrapper">
                         <div class="layout-heading">
                            <?php if (isset($widget_data['itg-block-6']['block_title'])) {?>
                            <h2 class="widget-title"><?php print $widget_data['itg-block-6']['block_title']; ?></h2>
                            <?php } ?>
                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />
                         </div>
                         <span class="edit-trigger">Edit</span>
                     </div>
                    <?php } ?>
                    <?php print $widget_data['itg-block-6']['widget']; ?></div>
                  </div>             
                </div>               
            </div>
          </div>
        </div>
        <?php } ?>
        <!--End of Aajtak row-->
        
        
        
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
    <?php //print $sidebar_second; ?>
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

<div class="activate-message">
  <div class="message-body">
    <span class="close-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
    <p>Your Account Activated Sucessfully!</p>
  </div>
</div>