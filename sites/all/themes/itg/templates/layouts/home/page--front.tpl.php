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
$arg = arg();
if (arg(2) == 'preview') {
  $preview = 'preview';
}
$gray_bg_layout = '';
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
      <main id="main" class="container">
          <?php print render($page['vertical_menu']); ?>
          <section id="content" role="main">
              <?php print render($page['highlighted']); ?>
              <?php print $breadcrumb; ?>
              <a id="main-content"></a>
              <?php print render($title_prefix); ?>
              <?php if ($title): ?>
                <h1 class="page__title title front-title-hide" id="page-title"><?php  print t('News'); ?></h1>
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
            <div class="itg-layout-container <?php echo $itg_class; ?>">    
                <!-- Breaking news band -->         
                <?php if (!empty($page['breaking_news'])): ?>    
                  <div class="row">
                      <div class="col-md-12">
                          <?php print render($page['breaking_news']); ?>
                      </div>      
                  </div>    
                <?php endif; ?>
                <?php if ((isset($widget_data['itg-block-0']['widget']) && !empty($widget_data['itg-block-0']['widget'])) || ($theme == 'itgadmin')) { ?>
                  <div class="home-election" data-tb-region="homeElection">
                      <div class="widget-help-text"><?php print t('Template widgets'); ?> ( <strong><?php print t('Home Page Election'); ?></strong> )</div>
                      <div class="itg-widget">
                          <div class="droppable <?php print $gray_bg_layout; ?>">
                              <div class="widget-wrapper <?php print $widget_data['itg-block-0']['widget_name']; ?>">
                                  <div class="data-holder" id="itg-block-0">
                                      <?php
                                      if (isset($widget_data['itg-block-0']['widget'])) {
                                        print $widget_data['itg-block-0']['widget'];
                                      }
                                      else { ?>
                                        <div class="widget-placeholder"><span><?php print t('Home Election'); ?></span></div>
                                     <?php }
                                      ?>
                                  </div>
                              </div>
                          </div>
                      </div>
                  </div>
                <?php } ?>
                <!-- End of Breaking news band -->
                <?php if (isset($widget_data['big_story'])) : ?>
                  <div class="row">
                      <div class="col-md-12">
                          <?php print $widget_data['big_story']; ?>
                      </div>            
                  </div>
                <?php endif; ?>
                <div class="row itg-top-section">
                    <div class="top-block">
                        <div class="col-sm-8 col-md-8 col-lg-5 home-top-featured" data-tb-region="homeTopFeatured">
                            <div class="widget-help-text">Template widgets ( <strong>Home Page Feature</strong> )</div>
                            <div class="itg-widget">
                                <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                      <div class="widget-settings">
                                          <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-1"><i class="fa fa-times"></i></a></span>
                                      </div>  
                                    <?php } ?>   
                                    <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">
                                        <div class="data-holder" id="itg-block-1">
                                            <?php
                                            if (isset($widget_data['itg-block-1']['widget'])) {
                                              print $widget_data['itg-block-1']['widget'];
                                            }
                                            else {
                                              print '<div class="widget-placeholder"><span>Home Featured</span></div>';
                                            }
                                            ?>
                                        </div>
                                    </div>                     
                                </div>
                            </div>
                        </div>
                        <div class="col-sm-4 col-md-4 col-lg-3 home-top-story" data-tb-region="homeTopStory">
                            <div class="widget-help-text">Template widgets (<strong>Top Story</strong>)</div>
                            <div class="itg-widget">
                                <div class="top-n-most-popular-stories">
                                    <div class="itg-widget-child tab-data tab-data-1">
                                        <div class="droppable <?php print $gray_bg_layout; ?>">
                                            <div class="widget-wrapper <?php print $widget_data['itg-block-2']['widget_name']; ?>">
                                                <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-2']['block_title'])) { ?>
                                                  <span class="widget-title"><?php print $widget_data['itg-block-2']['block_title']; ?></span>
                                                <?php } ?>
                                                <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                  <div class="widget-settings">
                                                      <div class="widget-title-wrapper">
                                                          <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                                                      </div>
                                                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                      <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-2"><i class="fa fa-times"></i></a>
                                                    </span>
                                                      
                                                  </div>  
                                                <?php } ?>                   
                                                <div class="data-holder" id="itg-block-2">
                                                    <?php
                                                    if (isset($widget_data['itg-block-2']['widget'])) {
                                                      print $widget_data['itg-block-2']['widget'];
                                                    }
                                                    else {
                                                      print '<div class="widget-placeholder"><span>Top Story</span></div>';
                                                    }
                                                    ?>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col-sm-12 col-md-12 col-lg-4 top-rhs-add">
                          <div class="row">
                            <div class="widget-help-text">Non Draggable ( <strong>Ad widget</strong> )</div>
                            <div class="col-xs-12 col-sm-6 col-md-5 col-lg-12 top-rhs-add-child">
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
                            <!-- replace home-trending-video if webcast enable -->
                            <?php if (function_exists('get_itg_variable') && !empty(get_itg_variable('itg_webcast_status', 0))):?>
															<div class="col-xs-12 col-sm-6 col-md-7 col-lg-12 home-trending-video">
                                <?php if (!empty(get_itg_variable('itg_webcast_url'))) { ?>
                                <span class="widget-title"><h3><?php print l(get_itg_variable('itg_webcast_title'), get_itg_variable('itg_webcast_url'), array('attributes' => array('target' => '_blank'))); ?></h3></span>
                                <?php }else { ?>
                                <span class="widget-title"><h3><?php print get_itg_variable('itg_webcast_title') ?></h3></span>
                                <?php } ?>
                                <div class='live-webcast-coverage'>
                                  <?php print get_itg_variable('itg_webcast_iframe'); ?>
                                </div>
                                <?php if (!empty(get_itg_variable('itg_content_webcast_url'))) { ?>
                                <div class="webcast_link webcast_title"><h3><?php print l(get_itg_variable('itg_content_webcast_title'), get_itg_variable('itg_content_webcast_url'), array('attributes' => array('target' => '_blank'))); ?></h3></div>
                                <?php }else { ?>
                                <div class="webcast_title"><h3><?php print get_itg_variable('itg_content_webcast_title') ?></h3></div>
                                <?php } ?>
															</div>
                            <!-- replace home-trending-video if webcast enable end here -->
                            <?php else: ?>
                            <div class="col-xs-12 col-sm-6 col-md-7 col-lg-12 home-trending-video">
                                <div class="widget-help-text">Template widgets(<strong>Trending Videos &amp; Top Takes</strong>)</div>
                                <div class="tab-buttons">
                                    <span data-class="itg-block-5" data-id="tab-data-1" class="active">
                                        <?php
                                        if (!$widget_data['itg-block-5']['block_title']) {
                                          print 'Tab 1';
                                        }
                                        else {
                                        ?>
                                      <a href="#<?php print trim(str_replace(" ", "",$widget_data['itg-block-5']['block_title'])); ?>" onclick="ga('send', 'event', '<?php print trim(str_replace(" ", "",$widget_data['itg-block-5']['block_title']))."Tab"; ?>', 'click','1', 1, {'nonInteraction': 1});return true;">
                                        <?php  
                                        print $widget_data['itg-block-5']['block_title']; 
                                        ?>
                                      </a>
                                      <?php
                                        }
                                        ?>
                                    </span>
                                    <span data-class="itg-block-6" data-id="tab-data-2">
                                        <?php
                                        if (!$widget_data['itg-block-6']['block_title']) {
                                          print 'Tab 1';
                                        }
                                        else {
                                        ?>
                                      <a href="#<?php print trim(str_replace(" ", "",$widget_data['itg-block-6']['block_title'])); ?>" onclick="ga('send', 'event', '<?php print trim(str_replace(" ", "",$widget_data['itg-block-6']['block_title']))."Tab"; ?>', 'click','1', 1, {'nonInteraction': 1});return true;">
                                        <?php  
                                        print $widget_data['itg-block-6']['block_title']; 
                                        ?>
                                      </a>
                                        <?php
                                        }
                                        ?>
                                    </span>
                                </div>
                                <div class="itg-widget-child tab-data tab-data-1" data-tb-region="homeTrendingVideo">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-5']['widget_name']; ?>">
                                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-5"><i class="fa fa-times"></i></a></span>                                                  
                                              </div>  
                                            <?php } ?>                   
                                            <div class="data-holder" id="itg-block-5">
                                                <?php
                                                if (isset($widget_data['itg-block-5']['widget'])) {
                                                  print $widget_data['itg-block-5']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>Trending videos</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="itg-widget-child tab-data tab-data-2 hide" data-tb-region="homeTopTakes">
                                    <div class="droppable <?php print $gray_bg_layout; ?>"> 
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-6']['widget_name']; ?>"> 
                                            <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-6"><i class="fa fa-times"></i></a></span>
                                                  
                                              </div>  
                                            <?php } ?>                   
                                            <div class="data-holder" id="itg-block-6">
                                                <?php
                                                if (isset($widget_data['itg-block-6']['widget'])) {
                                                  print $widget_data['itg-block-6']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>Watch right now</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <?php endif;?>
                        </div>
                    </div>
                  </div>
                </div>
                <?php
                /*if ($user->uid == 0 && $arg[0] != "itg-layout-manager") {
                  if (isset($_COOKIE['recomended_for_you'])) {
                    $value = itg_user_log_get_sections($_COOKIE['recomended_for_you']);
                    $recomended_array_count = count(explode(",", $value));
                    if ($recomended_array_count >= 4) {
                      ?>
                      <section class="recommended-for-you" data-tb-region="homeRecommendedForYouNonPersonlization">
                          <div class="container"><span class="widget-title">RECOMMENDED FOR YOU</span> <?php print $widget_data['non_personlization'] ?></div>
                      </section>
                      <?php
                    }
                  }
                }
                ?>
                <?php if (!empty($user->uid) && $arg[0] != "itg-layout-manager") { ?>
                  <section class="recommended-for-you" data-tb-region="homeRecommendedForYouPersonlization">
                      <div class="container"><span class="widget-title">RECOMMENDED FOR YOU</span> <?php print $widget_data['personlization'] ?></div>
                  </section>
                <?php }*/ ?>
                <div class="itg-layout-container itg-front">
                    <!--Common section strat here-->
                    <?php if (isset($widget_data['itg-block-7']['widget_name']) || isset($widget_data['itg-block-8']['widget_name']) || isset($widget_data['itg-block-9']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="row itg-common-section">        
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-7']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-7"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-7">
                                              <?php
                                              if (isset($widget_data['itg-block-7']['widget'])) {
                                                print $widget_data['itg-block-7']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>  
                          </div>
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-8']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-8"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-8">
                                              <?php
                                              if (isset($widget_data['itg-block-8']['widget'])) {
                                                print $widget_data['itg-block-8']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>
                          </div>
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-9']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-9"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-9">
                                              <?php
                                              if (isset($widget_data['itg-block-9']['widget'])) {
                                                print $widget_data['itg-block-9']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
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
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-17']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-17"><i class="fa fa-times"></i></a>
                                            </span>                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-17">
                                              <?php
                                              if (isset($widget_data['itg-block-17']['widget'])) {
                                                print $widget_data['itg-block-17']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>  
                          </div>
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-18']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-18"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-18">
                                              <?php
                                              if (isset($widget_data['itg-block-18']['widget'])) {
                                                print $widget_data['itg-block-18']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>
                          </div>
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-19']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-19"><i class="fa fa-times"></i></a>
                                            </span>                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-19">
                                              <?php
                                              if (isset($widget_data['itg-block-19']['widget'])) {
                                                print $widget_data['itg-block-19']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
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
                          <div class="col-md-8 col-sm-6 col-xs-12 mt-50" data-tb-region="HomeDoNotMiss">
                              <div class="widget-help-text">Template widgets ( <strong>Don't Miss</strong> )</div>
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
                          <div class="col-md-4 col-sm-6 col-xs-12 mt-50">
                              <div class="widget-help-text">Non Draggable ( <strong>Ad Widget</strong> )</div>
                              <div class="itg-widget">
                                  <div class="ad-widget">
                                      <div class="sidebar-ad">
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
                          <div class="col-md-8 col-sm-7 col-xs-12 col-lg-8 mt-50" data-tb-region="HomePhotoCarousel">
                              <div class="widget-help-text">Template widgets ( <strong>Photo Carousel</strong> )</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-12"><i class="fa fa-times"></i></a>
                                            </span>                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-12">
                                              <?php
                                              if (isset($widget_data['itg-block-12']['widget'])) {
                                                print $widget_data['itg-block-12']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Photo Carousel</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>  
                          </div>
                          <div class="col-md-4 col-sm-5 col-xs-12 col-lg-4 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-13']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section card ( <strong>Watch</strong> )</div>
                              <div class="itg-widget">
                                  <div class="droppable <?php print $gray_bg_layout; ?>">
                                      <div class="widget-wrapper watch-video-home <?php print $widget_data['itg-block-13']['widget_name']; ?>">
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-13"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-13" data-widget-style="home-watch">
                                              <?php
                                              if (isset($widget_data['itg-block-13']['widget'])) {
                                                print $widget_data['itg-block-13']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Home Watch</span></div>';
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
                    <?php
                    if ($theme != 'itgadmin') {
                      // print '<div id="second-section-card">';
                    }
                    ?>
                    <!--Common section strat here-->
                    <?php if (isset($widget_data['itg-block-14']['widget_name']) || isset($widget_data['itg-block-15']['widget_name']) || isset($widget_data['itg-block-16']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="row itg-common-section" >
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-14']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                    <?php if (isset($widget_data['itg-block-14']['block_title'])) { ?>
                                                      <span class="widget-title" data-id="itg-block-14"><?php print $widget_data['itg-block-14']['block_title']; ?></span>
                                                    <?php } ?>
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-14']['block_title']; ?>" name="itg-block-14" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-14"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-14" >
                                              <?php
                                              if (isset($widget_data['itg-block-14']['widget'])) {
                                                print $widget_data['itg-block-14']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>  
                          </div>
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-15']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-15"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-15">
                                              <?php
                                              if (isset($widget_data['itg-block-15']['widget'])) {
                                                print $widget_data['itg-block-15']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>
                          </div>
                          <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-itg-block-16" data-tb-region="<?php echo itg_get_dive_region_name($widget_data['itg-block-16']['block_title'], 'Home');?>">
                              <div class="widget-help-text">Section Card</div>
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
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-16"><i class="fa fa-times"></i></a>
                                            </span>
                                                
                                            </div>
                                          <?php } ?>
                                          <div class="data-holder" id="itg-block-16" data-widget-style="home-shows">
                                              <?php
                                              if (isset($widget_data['itg-block-16']['widget'])) {
                                                print $widget_data['itg-block-16']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>Home shows</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div>          
                          </div>
                          <!--<?php if ($theme == 'itgadmin') { ?>
                            <div class="load-more-wrapper">
                                <a href="javascript:void(0)" class="add-more-block">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
                            </div>
                            <?php
                          }
                          ?>-->
                      </div>
                    <?php } ?>
                    <!--End of Common section-->                    
                    <!--Common section add more strat here-->
                    <?php
                   // if ($theme == 'itgadmin') {
                      $count_widget = 19;
                      ?>
                      <?php
                      $last_val = 0;
                      $divcounter = 1;
                      $divcou = 0;
                      
                      ?>
                      <?php for ($count = 1; $count <= EXTRA_SECTION_CARDS; $count += 3) { ?>
                        <?php
                        $widget_name1 = 'itg-block-' . ($count_widget + 1);
                        $widget_name2 = 'itg-block-' . ($count_widget + 2);
                        $widget_name3 = 'itg-block-' . ($count_widget + 3);
                        ?>
                        <?php if (!empty($widget_data[$widget_name1]['widget_name']) || !empty($widget_data[$widget_name2]['widget_name']) || !empty($widget_data[$widget_name3]['widget_name']) || $theme == 'itgadmin') { ?>
                          <?php
                        //  $display_style = 'style="display:none"';
                          if ($widget_data[$widget_name1]['widget_name'] != null || $widget_data[$widget_name2]['widget_name'] != null || $widget_data[$widget_name3]['widget_name'] != null) {
                            $last_val++;
                           // $display_style = 'style="display:block"';
                          }
                          if ($theme != 'itgadmin') {
                           // $display_style = 'style="display:none"';
                          }
                          ?>
                          <div class="row itg-common-section mt-50 show-on-add" <?php echo $display_style; ?> id="content-section-widget-<?php print $divcounter; ?>">
                              <div class="col-md-4 col-sm-4 col-xs-12 sectioncart" data-tb-region="<?php echo itg_get_dive_region_name($widget_data[$widget_name1]['block_title'], 'Home');?>" id="section-cart-<?php echo $widget_name1; ?>">
                                  <div class="widget-help-text">Section Card</div>
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
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                    <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="<?php print $widget_name1; ?>"><i class="fa fa-times"></i></a>
                                                </span>
                                                    
                                                </div>
                                              <?php } ?>
                                              <div class="data-holder" id="<?php print $widget_name1; ?>">
                                                  <?php
                                                  if (isset($widget_data[$widget_name1]['widget'])) {
                                                    print $widget_data[$widget_name1]['widget'];
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                                  }
                                                  ?>
                                              </div>
                                          </div>             
                                      </div>               
                                  </div>  
                              </div>
                              <div class="col-md-4 col-sm-4 col-xs-12 sectioncart" data-tb-region="<?php echo itg_get_dive_region_name($widget_data[$widget_name2]['block_title'], 'Home');?>" id="section-cart-<?php echo $widget_name2; ?>">
                                  <div class="widget-help-text">Section Card</div>
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
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                    <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="<?php print $widget_name2; ?>"><i class="fa fa-times"></i></a>
                                                </span>
                                                    
                                                </div>
                                              <?php } ?>
                                              <div class="data-holder" id="<?php print $widget_name2; ?>">
                                                  <?php
                                                  if (isset($widget_data[$widget_name2]['widget'])) {
                                                    print $widget_data[$widget_name2]['widget'];
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                                  }
                                                  ?>
                                              </div>
                                          </div>             
                                      </div>               
                                  </div>
                              </div>
                              <div class="col-md-4 col-sm-4 col-xs-12 sectioncart" data-tb-region="<?php echo itg_get_dive_region_name($widget_data[$widget_name3]['block_title'], 'Home');?>" id="section-cart-<?php echo $widget_name3; ?>">
                                  <div class="widget-help-text">Section Card</div>
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
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i>
                                                    <a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="<?php print $widget_name3; ?>"><i class="fa fa-times"></i></a>
                                                </span>
                                                    
                                                </div>
                                              <?php } ?>
                                              <div class="data-holder" id="<?php print $widget_name3; ?>">
                                                  <?php
                                                  if (isset($widget_data[$widget_name3]['widget'])) {
                                                    print $widget_data[$widget_name3]['widget'];
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>Section Card</span></div>';
                                                  }
                                                  ?>
                                              </div>
                                          </div>             
                                      </div>               
                                  </div>          
                              </div>
                              <?php $divcou = 3 + $divcou; ?>
<!--                              <div class="load-more-wrapper">
                              <?php if ((EXTRA_SECTION_CARDS != $divcou) && ($divcou != $last_val)) { ?>
                                    <a href="javascript:void(0)" class="add-more-block">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
                                  <?php } if ($theme == 'itgadmin') { ?>
                                    <a href="javascript:void(0)" class="removes-more-block">Less <i class="fa fa-chevron-circle-up" aria-hidden="true"></i></a>
                                  <?php } ?>
                              </div>-->
                          </div>
                        <?php } ?>
                        <?php
                        $count_widget = 3 + $count_widget;
                        $divcounter++;
                        ?>
                        <?php
                      }
                   // }
                    ?>
                    <!--End of Common section-->
                    <div class="no-more-card" style="display:none">No More Result Found.</div>
                    <!--Common section strat here-->
                    <?php if (isset($widget_data['itg-block-14']['widget_name']) || isset($widget_data['itg-block-15']['widget_name']) || isset($widget_data['itg-block-16']['widget_name']) || $theme == 'itgadmin') { ?>
                      <?php
                      // get configuration for widget
                      $widget_choice = variable_get('widget-choice');
                      if ($widget_choice['aajtak'] != '0' || $widget_choice['business'] != '0' || $widget_choice['pti'] != '0') {
                        ?>
                        <div class="row itg-common-section itg-third-party-section" >
                            <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="HomeLatestFromAajtak">
                                <div class="widget-help-text">Third Party</div>
                                <div class="itg-widget">
                                    <div class="widget-wrapper">
                                        <?php
                                        if ($widget_choice['aajtak'] != '0') {
                                          $block = block_load('itg_front_end_common', 'latest_from_aajtak');
                                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                          print render($render_array);
                                        }
                                        ?>
                                    </div>             
                                </div>               
                            </div>
                            <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="HomeLatestFromBusinessToday">
                                <div class="widget-help-text">Third Party</div>
                                <div class="itg-widget">
                                    <div class="widget-wrapper">
                                        <?php
                                        if ($widget_choice['business'] != '0') {
                                          $block = block_load('itg_front_end_common', 'latest_from_businesstoday');
                                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                          print render($render_array);
                                        }
                                        ?>
                                    </div>             
                                </div>               
                            </div>
                            <div class="col-md-4 col-sm-4 col-xs-12 mt-50" data-tb-region="HomeLatestFromPTI">
                                <div class="widget-help-text">Third Party</div>
                                <div class="itg-widget">
                                    <div class="widget-wrapper">
                                        <?php
                                        if ($widget_choice['pti'] != '0') {
                                          $block = block_load('itg_front_end_common', 'latest_from_pti');
                                          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                          print render($render_array);
                                        }
                                        ?>
                                    </div>             
                                </div>               
                            </div>
                        </div>
                        <?php
                      }
                    }
                    ?>
                    <!--<?php
                    if ($theme != 'itgadmin') {
                      print '<div id="second-section-card"></div>';
                      if (!empty($widget_data['itg-block-20']['widget']) || !empty($widget_data['itg-block-21']['widget']) || !empty($widget_data['itg-block-22']['widget'])) {
                        ?>
                        <div class="load-more-wrapper-front">
                            <a href="javascript:void(0)" class="add-more-block-front">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
                        </div>
                        <?php
                      }
                    }
                    ?> -->
                    
                </div>
            </div>
            <!--------------------------------Code for Front tpl---------------------------------------->
            <?php if ($theme != 'itgadmin') { ?>
              <?php //print $feed_icons;   ?>
          </section>
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
    window.addEventListener("message", function (ev) {
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
        <p><?php print t('Your Account Activated Successfully!'); ?></p>
    </div>
</div>
<?php 
$ipl_triangle_status = itg_ipl_triangle_status(); 
if ($ipl_triangle_status == 1) {
?>
<style type="text/css">
  .crosscloseif{position: absolute;top: 28px;right: 17px;color: #fff;font-size: 12px;font-family: arial;height: 20px;width: 20px;text-align: center;cursor: pointer;
  z-index: 99;background: #000;line-height: 20px;border-radius: 100%;}
</style>
<script type="text/javascript">
  if (navigator.appName == 'Microsoft Internet Explorer' ||  !!(navigator.userAgent.match(/Trident/) || navigator.userAgent.match(/rv:11/)) || (typeof jQuery.browser !== "undefined" && jQuery.browser.msie == 1))
    {
      document.getElementById('twister').style.display='none';
    }
    	
  jQuery(document).ready(function(){
   jQuery(".crosscloseif").click(function(){
    jQuery("#twisstiframe").fadeOut(500)
    jQuery(this).fadeOut(500); 
   })  
 })
</script>
<div id="twister" style="position: fixed;right: 0px;bottom: -8px;z-index: 99999;"><span class="crosscloseif">X</span><iframe name="crbz_scag_frame" width="190" scrolling="no" height="180" src="https://feeds.intoday.in/xml_it/commentary/cube_ipl6.html" frameborder="0" id="twisstiframe"></iframe></div>
<?php } ?>
