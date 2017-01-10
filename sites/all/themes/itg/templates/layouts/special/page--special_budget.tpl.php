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
$live_url = "";
$preview = NULL;
if (arg(2) == 'preview') {
  $preview = 'preview';
}
$highlights = itg_widget_highlights_block_data();


if ($theme == 'itgadmin' && !isset($preview)) {
  $gray_bg_layout = 'gray-bg-layout';
}
$device = itg_live_tv_company('web');
if (!empty($device[0])) {
  $live_tv_get_details = node_load($device[0]);
  $live_url = $live_tv_get_details->field_ads_ad_code[LANGUAGE_NONE][0]['value'];
  if (filter_var($live_url, FILTER_VALIDATE_URL)) {
    $live_url = '<iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="'.$live_url.'"></iframe>';
  }
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
              <?php print render($title_suffix); ?>
              <?php print $messages; ?>
              <?php print render($tabs); ?>
              <?php print render($page['help']); ?>
              <?php if ($action_links): ?>
                <ul class="action-links"><?php print render($action_links); ?></ul>
              <?php endif; ?>       

            <?php } ?>
            <!--------------------------------Code for Front tpl and admin tpl---------------------------------------->
            <?php //print render($page['content']);   ?>
            <?php
            $itg_class = 'itg-admin';
            if ($theme != 'itgadmin') {
              $itg_class = 'itg-front';
            }
            ?>
            <div class="itg-layout-container <?php echo $itg_class; ?> budget-page-layout ">
                <!-- Breaking news band -->    
                <?php if (!empty($page['breaking_news'])): ?>
                  <div class="row">
                      <div class="col-md-12">
                          <?php print render($page['breaking_news']); ?>
                      </div>      
                  </div>    
                <?php endif; ?>
                <?php
                $display_title = "";
                if($widget_data['itg-block-2']['block_title'] == "")
                {
                    $display_title = 'style="display:none"';
                }
               
                  echo '<h1 '.$display_title.' id="display_tit"><span class="highlights-title">' . mb_strimwidth($widget_data['itg-block-2']['block_title'], 0, 90, "..") . '</span><span class="disc-share"><a href="#"><i class="fa fa-share-alt"></i></a></span></h1>';
       
                ?>
                <div class="row itg-325-layout">
                    <?php if ($live_url != "" || !empty($highlights['node_data']->field_story_highlights['und']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class=" <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">
                                     
                                        <h4 class="heading">LIVE TV</h4>
                             
                                      <!-- for admin  -->
                                     

                                      <div class="data-holder" id="itg-block-1"><?php print $live_url; ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class=" droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-2']['widget_name']; ?>">
                                     
                                       <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-2']['block_title'])) { ?>
                   <h4 class="heading"><?php print $widget_data['itg-block-2']['block_title']; ?></h4>
                  <?php } ?>
                   <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <?php if (isset($widget_data['itg-block-2']['block_title'])) {?>
                        <span class="widget-title" data-id="itg-block-2"><?php print $widget_data['itg-block-2']['block_title']; ?></span>
                        <?php } ?>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-2']['block_title']; ?>" name="itg-block-2" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                
                                      <!-- for admin  -->
                                       

<!--                                      <div class="data-holder highlight" id="itg-block-2"> <div class="auto-block-2">
                                              <div class="special-top-news">

                                                  <ul class="itg-listing">   
                                                      <?php
                                                     // foreach ($highlights['node_data']->field_story_highlights['und'] as $index => $row) {

                                                       // $desc = $row['value'];
                                                        ?>
                                                        <li><?php //echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), $base_url . '/' . drupal_get_path_alias("node/{$highlights['node_data']->nid}")) ?></li>

                                                      <?php //} ?>

                                                  </ul>

                                              </div>

                                          </div></div>-->

                    <div class="data-holder" id="itg-block-2"><?php print $widget_data['itg-block-2']['widget']; ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">                    
                          <div class="itg-widget-parent">
                              <div class="itg-widget">
                                  <div class="ad-widget budget-ad">
                                      <div class="sidebar-ad">
                                         <?php
                                        if (!empty($itg_ad['200*200_right_bar_ad1'])) {
                                          print $itg_ad['200*200_right_bar_ad1'];
                                        }
                                        ?>
                                      </div>
                                  </div>
                              </div>
                          </div>                    
                      </div>

                    <?php } ?>
                </div>

                <div class="row itg-530-layout">
                    <?php if (isset($widget_data['itg-block-4']['widget_name']) || isset($widget_data['itg-block-5']['widget_name']) || isset($widget_data['itg-block-6']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-8 mt-50">                                                 
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
                                                <?php if (isset($widget_data['itg-block-4']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-4"><?php print $widget_data['itg-block-4']['block_title']; ?></span>
                                                <?php } ?>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-4']['block_title']; ?>" name="itg-block-4" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
                                      <?php } ?>  

                                      <div class="data-holder" id="itg-block-4"><?php print $widget_data['itg-block-4']['widget']; ?></div>
                                  </div>             
                              </div>
                          </div>                       
                      </div>

                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-6']['widget_name']; ?>">
                                      <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-6']['block_title'])) { ?>
                                        <h4 class="heading"><?php print $widget_data['itg-block-6']['block_title']; ?></h4>
                                      <?php } ?>
                                      <!-- for admin  -->
                                      <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <?php if (isset($widget_data['itg-block-6']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-6"><?php print $widget_data['itg-block-6']['block_title']; ?></span>
                                                <?php } ?>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-6']['block_title']; ?>" name="itg-block-6" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
                                      <?php } ?>  

                                      <div class="data-holder" id="itg-block-6"><?php $block = module_invoke('itg_widget', 'block_view', 'budget_tweets');
                                    print render($block['content']);
                                      ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>

<?php } ?>
                </div>


                <div class="row itg-370-layout">
<?php if (isset($widget_data['itg-block-7']['widget_name']) || isset($widget_data['itg-block-8']['widget_name']) || isset($widget_data['itg-block-9']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-7']['widget_name']; ?>">
                                      <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-7']['block_title'])) { ?>
                                        <h4 class="heading"><?php print $widget_data['itg-block-7']['block_title']; ?></h4>
                                      <?php } ?>
                                      <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <?php if (isset($widget_data['itg-block-7']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-7"><?php print $widget_data['itg-block-7']['block_title']; ?></span>
    <?php } ?>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
  <?php } ?>  

                                      <div class="data-holder" id="itg-block-7" widget-style="india-inc-on-budget"><?php print $widget_data['itg-block-7']['widget']; ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-8']['widget_name']; ?>">
                                      <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-8']['block_title'])) { ?>
                                        <h4 class="heading"><?php print $widget_data['itg-block-8']['block_title']; ?></h4>
                                      <?php } ?>
                                      <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <?php if (isset($widget_data['itg-block-8']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-8"><?php print $widget_data['itg-block-8']['block_title']; ?></span>
    <?php } ?>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-8']['block_title']; ?>" name="itg-block-8" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
  <?php } ?>  

                                      <div class="data-holder" id="itg-block-8" widget-style="budget-decoded"><?php print $widget_data['itg-block-8']['widget']; ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-9']['widget_name']; ?>">
                                      <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-9']['block_title'])) { ?>
                                        <h4 class="heading"><?php print $widget_data['itg-block-9']['block_title']; ?></h4>
                                      <?php } ?>
                                      <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <?php if (isset($widget_data['itg-block-9']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-9"><?php print $widget_data['itg-block-9']['block_title']; ?></span>
    <?php } ?>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-9']['block_title']; ?>" name="itg-block-9" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
  <?php } ?>  

                                      <div class="data-holder" id="itg-block-9" widget-style="budget-reactions"><?php print $widget_data['itg-block-9']['widget']; ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>

<?php } ?>
                </div>


                <div class="row itg-480-layout">
<?php if (isset($widget_data['itg-block-10']['widget_name']) || isset($widget_data['itg-block-11']['widget_name']) || isset($widget_data['itg-block-12']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-8 mt-50">
                          <div class="row">
                              <div class="col-md-12 m-bottom40">
                                  <div class="itg-widget itg-widget-parent">
                                      <div class="droppable <?php print $gray_bg_layout; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-10']['widget_name']; ?>">
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-10']['block_title'])) { ?>
                                                <h4 class="heading"><?php print $widget_data['itg-block-10']['block_title']; ?></h4>
                                              <?php } ?>
                                              <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <?php if (isset($widget_data['itg-block-10']['block_title'])) { ?>
                                                          <span class="widget-title" data-id="itg-block-10"><?php print $widget_data['itg-block-10']['block_title']; ?></span>
    <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-10']['block_title']; ?>" name="itg-block-10" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                </div>
  <?php } ?>  

                                              <div class="data-holder" id="itg-block-10"><?php print $widget_data['itg-block-10']['widget']; ?></div>
                                          </div>             
                                      </div>
                                  </div>
                              </div>

                              <div class="col-md-12">
                                  <div class="itg-widget itg-widget-child">
                                      <div class="droppable <?php print $gray_bg_layout; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-11']['widget_name']; ?>">
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-11']['block_title'])) { ?>
                                                <h4 class="heading"><?php print $widget_data['itg-block-11']['block_title']; ?></h4>
                                              <?php } ?>
                                              <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <?php if (isset($widget_data['itg-block-11']['block_title'])) { ?>
                                                          <span class="widget-title" data-id="itg-block-11"><?php print $widget_data['itg-block-11']['block_title']; ?></span>
    <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-11']['block_title']; ?>" name="itg-block-11" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                </div>
  <?php } ?>  

                                              <div class="data-holder" id="itg-block-11"><?php print $widget_data['itg-block-11']['widget']; ?></div>
                                          </div>             
                                      </div>
                                  </div>
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">
                          <div class="itg-widget">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-12']['widget_name']; ?>">
                                      <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-12']['block_title'])) { ?>
                                        <h4 class="heading"><?php print $widget_data['itg-block-12']['block_title']; ?></h4>
                                      <?php } ?>
                                      <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <?php if (isset($widget_data['itg-block-12']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-12"><?php print $widget_data['itg-block-12']['block_title']; ?></span>
    <?php } ?>
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
<?php } ?>
                </div>


                <div class="row itg-715-layout">
<?php if (isset($widget_data['itg-block-13']['widget_name']) || isset($widget_data['itg-block-15']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-8 mt-50">
                          <div class="itg-widget">
                              <div class="droppable <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-13']['widget_name']; ?>">
                                      <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-13']['block_title'])) { ?>
                                        <h4 class="heading"><?php print $widget_data['itg-block-13']['block_title']; ?></h4>
                                      <?php } ?>
                                      <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                        <div class="widget-settings">
                                            <div class="widget-title-wrapper">
                                                <?php if (isset($widget_data['itg-block-13']['block_title'])) { ?>
                                                  <span class="widget-title" data-id="itg-block-13"><?php print $widget_data['itg-block-13']['block_title']; ?></span>
    <?php } ?>
                                                <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-13']['block_title']; ?>" name="itg-block-13" class="block_title_id" placeholder="Enter Title" />
                                            </div>
                                            <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                        </div>
  <?php } ?>  
                                      <div class="data-holder" id="itg-block-13"><?php print $widget_data['itg-block-13']['widget']; ?></div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">

                          <div class="row">
                              <div class="col-md-12">                    
                                  <div class="itg-widget-parent">
                                      <div class="itg-widget">
                                          <div class="ad-widget">
                                              <div class="sidebar-ad">
                                                 <?php
                                                  if (!empty($itg_ad['200*200_right_bar_ad2'])) {
                                                    print $itg_ad['200*200_right_bar_ad2'];
                                                  }
                                                  ?>
                                              </div>
                                          </div>
                                      </div>
                                  </div>                    
                              </div>

                              <div class="col-md-12 mt-50">
                                  <div class="itg-widget itg-widget-child">
                                      <div class="droppable <?php print $gray_bg_layout; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-15']['widget_name']; ?>">
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-15']['block_title'])) { ?>
                                                <h4 class="heading"><?php print $widget_data['itg-block-15']['block_title']; ?></h4>
                                              <?php } ?>
                                              <!-- for admin  -->
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <?php if (isset($widget_data['itg-block-15']['block_title'])) { ?>
                                                          <span class="widget-title" data-id="itg-block-15"><?php print $widget_data['itg-block-15']['block_title']; ?></span>
    <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-15']['block_title']; ?>" name="itg-block-15" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                </div>
  <?php } ?>  

                                              <div class="data-holder" id="itg-block-15"><?php print $widget_data['itg-block-15']['widget']; ?></div>
                                          </div>             
                                      </div>
                                  </div>
                              </div>
                          </div>

                      </div>                      
<?php } ?>
                </div>




            </div>





            <!--------------------------------Code for Front tpl---------------------------------------->
            <?php if ($theme != 'itgadmin') { ?>
  <?php //print $feed_icons;      ?>
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
<?php if ($theme == 'itgadmin') { ?>
  <div class="itg-ajax-loader">
      <img src="<?php echo base_path() . drupal_get_path('theme', $theme); ?>/images/loader.svg" alt=""/>
  </div>
<?php } ?>
<script type="text/javascript">
  jQuery(document).ready(function () {
      jQuery('.slider-budget').slick({
          dots: true,
          prevArrow: false,
          nextArrow: false
      });
  });
</script>