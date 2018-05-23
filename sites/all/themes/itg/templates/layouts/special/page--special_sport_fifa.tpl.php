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
$tax_name = '';
if (arg(2) == 'preview') {
  $preview = 'preview';
}
if ($theme == 'itgadmin' || $preview == 'preview') {
  global $conf;
  $conf['preprocess_js'] = 0;
}
$gray_bg_layout = '';
if ($theme == 'itgadmin' && !isset($preview)) {
  $gray_bg_layout = 'gray-bg-layout';
}
$itg_class = 'itg-admin';
if ($theme != 'itgadmin') {
  $itg_class = 'itg-front';
}
if ((arg(0) == 'taxonomy') && (arg(1) == 'term') && (arg(2)) && is_numeric(arg(2)) && !arg(3)) {
  $tax_id = arg(2);
  $tax_name_arr = get_term_name_from_tid($tax_id);
  $tax_name = strtolower($tax_name_arr->name);
}
$hide_widget = '';
?>
<!--------------------------------Code for Front tpl---------------------------------------->
<?php if ($theme != 'itgadmin') { ?>
  <div id="page" class="fifa-wcup">
      <header class="header" id="header" role="banner">
          <section class="header-top">
          
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
            if ($theme == 'itgadmin') {
              print '<div class="sport-main-title">';
              echo l('IPL Pages', $base_url . '/' . drupal_get_path_alias("itg-basic-page-list/{$_GET["section"]}"), array('attributes' => array('class' => 'add-more')));
              print '</div>';
            }
            ?>
            <div class="itg-layout-container <?php echo $itg_class; ?> sport-home-layout-page ">
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
                      <div class="fifa-left-bg">

                        <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Sport Featured'); ?></strong> )</div>
                        <?php if (isset($widget_data['itg-block-1']['widget_name']) || $theme == 'itgadmin') { ?>
                          <div class="row itg-layout-615">
                              <div class="col-md-12">
                                  <div class="">
                                      <div class="itg-widget">
                                          <div class="droppable <?php print $gray_bg_layout; ?>">
                                              <div id="auto-new-block" class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name'] . $widget_data['itg-block-1']['widget_display_name']; ?>">
                                                  <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-1']['block_title'])) { ?>
                                                    <h1 class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></h1>
                                                  <?php } ?>
                                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="itg-block-1"><?php print $widget_data['itg-block-1']['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-1"><i class="fa fa-times"></i></a></span>
                                                        </span>
                                                    </div>  
                                                  <?php } ?>    
                                                  <div class="data-holder" id="itg-block-1">
                                                      <?php
                                                      if (isset($widget_data['itg-block-1']['widget'])) {
                                                        print $widget_data['itg-block-1']['widget'];
                                                      }
                                                      else {
                                                        print '<div class="widget-placeholder"><span>' . t('Sport Featured') . '</span></div>';
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
                        <?php if (isset($widget_data['itg-block-2']['widget_name']) || $theme == 'itgadmin') { ?>            
                          <div class="row itg-layout-225">
                              <div class="col-md-12 mt-50">
                                  <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('FIXTURES'); ?></strong> )</div>
                                  <div class="">
                                      <div class="itg-widget">
                                          <div class="droppable <?php print $gray_bg_layout; ?>">
                                              <div class="widget-wrapper <?php print $widget_data['itg-block-2']['widget_name'] . $widget_data['itg-block-2']['widget_display_name']; ?>">
                                                  <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-2']['block_title'])) { ?>
                                                    <h2 class="widget-title"><?php print $widget_data['itg-block-2']['block_title']; ?></h2>
                                                  <?php } ?>
                                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="itg-block-2"><?php print $widget_data['itg-block-2']['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                       <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-2"><i class="fa fa-times"></i></a></span>
                                                        </span>
                                                    </div>  
                                                  <?php } ?>    
                                                  <div class="data-holder" id="itg-block-2">
                                                      <?php
                                                      if (isset($widget_data['itg-block-2']['widget'])) {
                                                        print $widget_data['itg-block-2']['widget'];
                                                      }
                                                      else {
                                                        print '<div class="widget-placeholder"><span>' . t('FIXTURES') . '</span></div>';
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

                         <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-7']['block_title'])) { ?>
                              <div class="fifa-points-table desktop-hide">
                                <h2 class="widget-title"><?php print $widget_data['itg-block-7']['block_title']; ?></h2>
                                <div class="data-holder" id="itg-block-7">
                                <?php
                                if (isset($widget_data['itg-block-7']['widget'])) {
                                  print $widget_data['itg-block-7']['widget'];
                                }
                                else {
                                  print '<div class="widget-placeholder"><span>' . t('Points tally') . '</span></div>';
                                }
                                ?>
                               </div>
                             </div>
                            <?php } ?>

                        <?php if (isset($widget_data['itg-block-112']['widget_name']) || $theme == 'itgadmin') { ?>            
                          <div class="row itg-layout-225">
                              <div class="col-md-12 mt-50">
                                  <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Top Stories for fifa'); ?></strong> )</div>
                                  <div class="">
                                      <div class="itg-widget">
                                          <div class="droppable <?php print $gray_bg_layout; ?>">
                                              <div class="widget-wrapper <?php print $widget_data['itg-block-112']['widget_name'] . $widget_data['itg-block-112']['widget_display_name']; ?>">
                                                  <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-112']['block_title'])) { ?>
                                                    <h2 class="widget-title"><?php print $widget_data['itg-block-112']['block_title']; ?></h2>
                                                  <?php } ?>
                                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="itg-block-112"><?php print $widget_data['itg-block-112']['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-112']['block_title']; ?>" name="itg-block-112" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                       <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-112"><i class="fa fa-times"></i></a></span>
                                                        </span>
                                                    </div>  
                                                  <?php } ?>    
                                                  <div class="data-holder" id="itg-block-112">
                                                      <?php
                                                      if (isset($widget_data['itg-block-112']['widget'])) {
                                                        print $widget_data['itg-block-112']['widget'];
                                                      }
                                                      else {
                                                        print '<div class="widget-placeholder"><span>' . t('Top Stories for fifa') . '</span></div>';
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
                       
                        <?php if (isset($widget_data['itg-block-5']['widget_name']) || $theme == 'itgadmin') { ?>  
                          <div class="row itg-layout-485">
                              <div class="col-md-12 mt-50">
                                  <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Photo carousel'); ?></strong> )</div>
                                  <div class="">
                                      <div class="itg-widget">
                                          <div class="droppable <?php print $gray_bg_layout; ?>">
                                              <div class="widget-wrapper <?php print $widget_data['itg-block-5']['widget_name'] . $widget_data['itg-block-5']['widget_display_name']; ?>">                      
                                                  <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-5']['block_title'])) { ?>
                                                    <?php if (isset($tax_name)) : ?>  
                                                      <h2 class="widget-title"><?php print $widget_data['itg-block-5']['block_title']; ?></h2>
                                                    <?php else: ?>
                                                      <span class="widget-title"><?php print $widget_data['itg-block-5']['block_title']; ?></span>
                                                    <?php endif; ?>
                                                  <?php } ?>
                                                  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                    <div class="widget-settings">
                                                        <div class="widget-title-wrapper">
                                                            <span class="widget-title" data-id="itg-block-5"><?php print $widget_data['itg-block-5']['block_title']; ?></span>
                                                            <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />
                                                        </div>
                                                        <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-5"><i class="fa fa-times"></i></a></span>
                                                        </span>
                                                    </div>  
                                                  <?php } ?>    
                                                  <div class="data-holder" id="itg-block-5">
                                                      <?php
                                                      if (isset($widget_data['itg-block-5']['widget'])) {
                                                        print $widget_data['itg-block-5']['widget'];
                                                      }
                                                      else {
                                                        print '<div class="widget-placeholder"><span>' . t('Photo carousel') . '</span></div>';
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
                        <!--Don't miss and Ad section starts here-->
                          <?php if (isset($widget_data['itg-block-10']['widget_name']) || $theme == 'itgadmin') { ?>  
                            <div class="row itg-h321-section">
                                <div class="col-md-12 mt-50 fifa-dont-miss-video">  
                                    <div class="widget-help-text">Template widgets ( <strong>Don't Miss</strong> )</div>
                                    <div class="itg-widget">
                                        <div class="droppable <?php print $gray_bg_layout; ?>">
                                            <div class="widget-wrapper <?php print $widget_data['itg-block-10']['widget_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-10']['block_title'])) { ?>
                                                  <h2 class="widget-title"><?php print $widget_data['itg-block-10']['block_title']; ?></h2>
                                                <?php } ?>
                                                <!-- for admin  -->
                                                <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                  <div class="widget-settings">
                                                      <div class="widget-title-wrapper">
                                                          <span class="widget-title" data-id="itg-block-10"><?php print $widget_data['itg-block-10']['block_title']; ?></span>
                                                          <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-10']['block_title']; ?>" name="itg-block-10" class="block_title_id" placeholder="Enter Title" />
                                                      </div>
                                                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                      <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-10"><i class="fa fa-times"></i></a>
                                                  </span>                                                
                                                  </div>
                                                <?php } ?>
                                                <div class="data-holder" id="itg-block-10">
                                                    <?php
                                                    if (isset($widget_data['itg-block-10']['widget'])) {
                                                      print $widget_data['itg-block-10']['widget'];
                                                    }
                                                    else {
                                                      print "<div class='widget-placeholder'><span>Don't  Miss</span></div>";
                                                    }
                                                    ?>
                                                </div>
                                            </div>             
                                        </div>               
                                    </div>  
                                </div>
                               
                            </div>
                          <?php } ?>
                          <!--End of Don't miss and Ad section-->
                     </div>
                    </div>
                    <div class="col-md-4 col-sm-12 col-xs-12 right-side">
                        <div class="row">
                            <div class="col-md-12 col-sm-6">   
                                <div class="widget-help-text"><?php print t('Non Draggable'); ?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
                                <div class="itg-widget-parent">
                                    <div class="itg-widget">
                                        <div class="ad-widget">
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
                            </div>
                            <div class="col-md-12 col-sm-6 itg-layout-195 mt-10">
                                <div class="widget-help-text"><?php print t('Draggable'); ?> ( <strong><?php print t('Scorecard'); ?></strong> )</div>
                                <div class="itg-widget">
                                    <?php									  
                                      if(($theme != 'itgadmin' || isset($preview)) && (!isset($widget_data['itg-block-6']['widget']))){
                                        $hide_widget = 'hide-widget';
                                      }
                                      else{
                                      $hide_widget = '';
                                      }
                                    ?>
                                    <div class="droppable <?php print $gray_bg_layout; ?> <?php print $hide_widget; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-6']['widget_name'] . $widget_data['itg-block-6']['widget_display_name']; ?>">                      
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-6']['block_title'])) { ?>
                                              <h2 class="widget-title"><?php print $widget_data['itg-block-6']['block_title']; ?></h2>
                                            <?php } ?>
                                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
                                                      <span class="widget-title" data-id="itg-block-6"><?php print $widget_data['itg-block-6']['block_title']; ?></span>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-6"><i class="fa fa-times"></i></a></span>
                                                  </span>
                                              </div>  
                                            <?php } ?>    
                                            <div class="data-holder" id="itg-block-6">
                                                <?php
                                                if (isset($widget_data['itg-block-6']['widget'])) {
                                                  print $widget_data['itg-block-6']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Scorecard') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>                     
                                    </div>           
                                </div>  
                            </div>
                        </div>
                        <div class="row">
                              <div class="col-md-12 col-sm-6 itg-layout-260">
                                  <div class="widget-help-text"><?php print t(' Draggable'); ?> ( <strong><?php print t('Points tally'); ?></strong> )</div>
                                  <div class="itg-widget">
                                      <?php									  
                                        if(($theme != 'itgadmin' || isset($preview)) && (!isset($widget_data['itg-block-7']['widget']))){
                                          $hide_widget = 'hide-widget';
                                        }
                                        else{
                                        $hide_widget = '';
                                        }
                                      ?>									
                                      <div class="droppable <?php print $gray_bg_layout; ?> <?php print $hide_widget; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-7']['widget_name'] . $widget_data['itg-block-7']['widget_display_name']; ?>">                      
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-7']['block_title'])) { ?>
                                                <h2 class="widget-title"><?php print $widget_data['itg-block-7']['block_title']; ?></h2>
                                              <?php } ?>
                                              <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <span class="widget-title" data-id="itg-block-7"><?php print $widget_data['itg-block-7']['block_title']; ?></span>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-7"><i class="fa fa-times"></i></a></span>
                                                    </span>
                                                </div>  
                                              <?php } ?>    
                                              <div class="data-holder" id="itg-block-7">
                                                  <?php
                                                  if (isset($widget_data['itg-block-7']['widget'])) {
                                                    print $widget_data['itg-block-7']['widget'];
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>' . t('Points tally') . '</span></div>';
                                                  }
                                                  ?>
                                              </div>
                                          </div>                     
                                      </div> 
                                  </div>
                              </div>
                            
                              <div class="col-md-12 col-sm-6 itg-layout-315">
                                  <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Poll'); ?></strong> )</div>
                                  <div class="itg-widget">
                                      <?php									  
                                        if(($theme != 'itgadmin' || isset($preview)) && (!isset($widget_data['itg-block-9']['widget']))){
                                          $hide_widget = 'hide-widget';
                                        }
                                        else{
                                        $hide_widget = '';
                                        }
                                      ?>
                                      <div class="droppable <?php print $gray_bg_layout; ?> <?php print $hide_widget; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-9']['widget_name'] . $widget_data['itg-block-9']['widget_display_name']; ?>">
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-9']['block_title'])) { ?>
                                                <h2 class="widget-title"><?php print $widget_data['itg-block-9']['block_title']; ?></h2>
                                              <?php } ?>
                                              <!-- for admin  -->
                                              <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <span class="widget-title" data-id="itg-block-9"><?php print $widget_data['itg-block-9']['block_title']; ?></span>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-9']['block_title']; ?>" name="itg-block-9" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>                                                   <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-9"><i class="fa fa-times"></i></a></span>
                                                    </span>
                                                </div>
                                              <?php } ?>  
                                              <div class="data-holder" id="itg-block-9">
                                                  <?php
                                                  if (isset($widget_data['itg-block-9']['widget'])) {
                                                    print $widget_data['itg-block-9']['widget'];
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>' . t('Poll') . '</span></div>';
                                                  }
                                                  ?>
                                              </div>
                                          </div>             
                                      </div>               
                                  </div>  
                              </div>
                        </div>        
                        <div class="row">      
                                <div class="col-md-12 col-sm-6 itg-layout-375">
                                    <div class="widget-help-text"><?php print t(' Draggable'); ?> ( <strong><?php print t('Top performers'); ?></strong> )</div>
                                    <div class="itg-widget">
                                        <?php               
                                          if(($theme != 'itgadmin' || isset($preview)) && (!isset($widget_data['itg-block-8']['widget']))){
                                          $hide_widget = 'hide-widget';
                                          }
                                          else{
                                          $hide_widget = '';
                                          }
                                        ?>
                                        <div class="droppable <?php print $gray_bg_layout; ?> <?php print $hide_widget; ?>">
                                            <div class="widget-wrapper <?php print $widget_data['itg-block-8']['widget_name'] . $widget_data['itg-block-8']['widget_display_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-8']['block_title'])) { ?>
                                                  <h2 class="widget-title"><?php print $widget_data['itg-block-8']['block_title']; ?></h2>
                                                <?php } ?>
                                                <!-- for admin  -->
                                                <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                  <div class="widget-settings">
                                                      <div class="widget-title-wrapper">
                                                          <span class="widget-title" data-id="itg-block-8"><?php print $widget_data['itg-block-8']['block_title']; ?></span>
                                                          <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-8']['block_title']; ?>" name="itg-block-8" class="block_title_id" placeholder="Enter Title" />
                                                      </div>
                                                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-8"><i class="fa fa-times"></i></a></span>
                                                      </span>
                                                  </div>
                                                <?php } ?>  
                                                <div class="data-holder" id="itg-block-8">
                                                    <?php
                                                    if (isset($widget_data['itg-block-8']['widget'])) {
                                                      print $widget_data['itg-block-8']['widget'];
                                                    }
                                                    else {
                                                      print '<div class="widget-placeholder"><span>' . t('Top performers') . '</span></div>';
                                                    }
                                                    ?>
                                                </div>
                                            </div>             
                                        </div>               
                                    </div>  
                                </div>

                                <div class="col-md-12 col-sm-6 itg-layout-340">
                                    <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Tweets'); ?></strong> )</div>
                                    <div class="itg-widget">
                                        <?php                   
                                          if(($theme != 'itgadmin' || isset($preview)) && (!isset($widget_data['itg-block-110']['widget']))){
                                            $hide_widget = 'hide-widget';
                                          }
                                          else{
                                            $hide_widget = '';
                                          }
                                        ?>
                                        <div class="droppable <?php print $gray_bg_layout; ?> <?php print $hide_widget; ?>">
                                            <div class="widget-wrapper <?php print $widget_data['itg-block-110']['widget_name'] . $widget_data['itg-block-110']['widget_display_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-10']['block_title'])) { ?>
                                                  <h2 class="widget-title"><?php print $widget_data['itg-block-110']['block_title']; ?></h2>
                                                <?php } ?>
                                                <!-- for admin  -->
                                                <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                  <div class="widget-settings">
                                                      <div class="widget-title-wrapper">
                                                          <span class="widget-title" data-id="itg-block-110"><?php print $widget_data['itg-block-110']['block_title']; ?></span>
                                                          <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-110']['block_title']; ?>" name="itg-block-110" class="block_title_id" placeholder="Enter Title" />
                                                      </div>
                                                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                        <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-110"><i class="fa fa-times"></i></a></span>
                                                      </span>                                                    
                                                  </div>
                                                <?php } ?>  
                                                <div class="data-holder" id="itg-block-110"><?php
                                                    if (isset($widget_data['itg-block-110']['widget'])) {
                                                      print $widget_data['itg-block-110']['widget'];
                                                    }
                                                    else {
                                                      print '<div class="widget-placeholder"><span>' . t('Tweets') . '</span></div>';
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
