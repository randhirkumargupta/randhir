<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
// configuration for social sharing
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $widget_data['itg-block-2']['block_title']);
$fb_share_title= htmlentities($search_title, ENT_QUOTES);    
$short_url = shorten_url($actual_link, 'goo.gl');
$share_desc = '';
$src = '';
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
              
              <?php if ($secondary_menu): ?>
                            
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
                <div class="row">
                    <div class="col-md-12 budget-top-block">
                <?php
                $display_title = "";
                if($widget_data['itg-block-2']['block_title'] == "")
                {
                    $display_title = 'style="display:none"';
                }
                if($_GET['type'] != 'budget-predictor') { 
                  echo '<h1 '.$display_title.' id="display_tit"><span class="highlights-title">' . mb_strimwidth($widget_data['itg-block-2']['block_title'], 0, 90, "..") . '</span></h1>';
                  
                ?>
                <div class="social-share">
                    <ul>
                        <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                        <li><a title="share on facebook" class= "facebook def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_share_title; ?>', '<?php print $share_desc; ?>', '<?php print $src; ?>')"><i class="fa fa-facebook"></i></a></li>
                        <li><a title="share on twitter" class= "twitter def-cur-pointer" onclick="twitter_popup('<?php print urlencode($widget_data['itg-block-2']['block_title']);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                        <li><a title="share on google+" class= "google def-cur-pointer" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a></li>
                    </ul>
                </div>
                <?php } ?>          
                        </div>
                </div>
                <!--budget predictor with first block-->  
                <?php if($_GET['type'] == 'budget-predictor') { ?>
                   <div class="row">  
                     <div class="col-md-8 itg-h747-section">
                      <?php
                       $block = module_invoke('itg_budget_predictor', 'block_view', 'budget_pradictor');
                       print render($block['content']);
                       ?>
                     </div>
                     <div class="col-md-4">   
                         <div class="row">
                          <div class="col-md-12">
                                                
                                  <div class="itg-widget-parent">
                                      <div class="itg-widget">
                                          <div class="ad-widget budget-ad">
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
                          <div class="col-md-12">
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
                      </div>    
                     </div>    
                   </div>    
                <?php } else { ?>
                
                <div class="row itg-325-layout">
                    <?php if ($live_url != "" || !empty($highlights['node_data']->field_story_highlights['und']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-4 col-sm-12 mt-50">
                          <div class="itg-widget">
                              <div class=" <?php print $gray_bg_layout; ?>">
                                  <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">
                                     
                                        <h4 class="heading">LIVE TV</h4>
                             
                                      <!-- for admin  -->
                                     

                                      <div class="data-holder" id="itg-block-1"><div class="video-wrapper"><?php print $live_url; ?></div></div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 col-sm-6 mt-50">
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
                
                                    

                    <div class="data-holder" id="itg-block-2">
                      <?php
                        if (isset($widget_data['itg-block-2']['widget'])) {
                          print $widget_data['itg-block-2']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('Highlights').'</span></div>';
                        } 
                      ?>
                    </div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 col-sm-6 mt-50">                    
                          <div class="itg-widget-parent">
                              <div class="itg-widget">
                                  <div class="ad-widget budget-ad">
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

                    <?php } ?>
                </div>
                <?php } ?>
                 <!--End budget predictor with first block--> 
                
                 <!--budget predictor with second block-->  
                <?php if($_GET['type'] != 'budget-predictor') { ?>
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

                                      <div class="data-holder" id="itg-block-4">
                                        <?php
                                          if (isset($widget_data['itg-block-4']['widget'])) {
                                            print $widget_data['itg-block-4']['widget']; 
                                          } else{
                                            print '<div class="widget-placeholder"><span>'.t('Top news').'</span></div>';
                                          } 
                                        ?>
                                      </div>
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

                                      <div class="data-holder" id="itg-block-6">
                                        <?php 
                                        //$block = module_invoke('itg_widget', 'block_view', 'budget_tweets');
                                    //print render($block['content']);
                                      ?>
                                      <?php
                                                if (isset($widget_data['itg-block-6']['widget'])) {
                                                  print $widget_data['itg-block-6']['widget']; 
                                                } else{
                                                  print '<div class="widget-placeholder"><span>'.t('Live Chat').'</span></div>';
                                                } 
                                              ?>
                                      </div>
                                  </div>             
                              </div>
                          </div>
                      </div>

                    <?php } ?>
                </div>
                <?php } ?>
                 <!--End budget predictor with first block--> 


                <div class="row itg-370-layout">
                <?php if (isset($widget_data['itg-block-7']['widget_name']) || isset($widget_data['itg-block-8']['widget_name']) || isset($widget_data['itg-block-9']['widget_name']) || $theme == 'itgadmin') { ?>
                      <div class="col-md-4 col-sm-6 col-xs-12 mt-50">
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

                                      <div class="data-holder" id="itg-block-7" data-widget-style="india-inc-on-budget">
                                        <?php
                                          if (isset($widget_data['itg-block-7']['widget'])) {
                                            print $widget_data['itg-block-7']['widget']; 
                                          } else{
                                            print '<div class="widget-placeholder"><span>'.t('India inc on budget').'</span></div>';
                                          } 
                                        ?>
                                      </div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 col-sm-6 col-xs-12 mt-50">
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

                                      <div class="data-holder" id="itg-block-8" data-widget-style="budget-decoded">
                                        <?php
                                          if (isset($widget_data['itg-block-8']['widget'])) {
                                            print $widget_data['itg-block-8']['widget']; 
                                          } else{
                                            print '<div class="widget-placeholder"><span>'.t('Budget decoded').'</span></div>';
                                          } 
                                        ?>
                                      </div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 col-sm-12 col-xs-12 mt-50">
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

                                      <div class="data-holder" id="itg-block-9" data-widget-style="budget-reactions">
                                        <?php
                                          if (isset($widget_data['itg-block-9']['widget'])) {
                                            print $widget_data['itg-block-9']['widget']; 
                                          } else{
                                            print '<div class="widget-placeholder"><span>'.t('Reactions').'</span></div>';
                                          } 
                                        ?>
                                      </div>
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
                            <?php if($_GET['type'] != 'budget-predictor') { ?>  
                              <div class="col-md-12 col-sm-6 col-xs-12 m-bottom40">
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

                                              <div class="data-holder" id="itg-block-10">
                                                <?php
                                                  if (isset($widget_data['itg-block-10']['widget'])) {
                                                    print $widget_data['itg-block-10']['widget']; 
                                                  } else{
                                                    print '<div class="widget-placeholder"><span>'.t('Cheaper / Dearer').'</span></div>';
                                                  } 
                                                ?>
                                              </div>
                                          </div>             
                                      </div>
                                  </div>
                              </div>
                            <?php } ?>  
                              <div class="col-md-12 col-sm-6 col-xs-12">
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

                                              <div class="data-holder" id="itg-block-11">
                                                <?php
                                                  if (isset($widget_data['itg-block-11']['widget'])) {
                                                    print $widget_data['itg-block-11']['widget']; 
                                                  } else{
                                                    print '<div class="widget-placeholder"><span>'.t('Infographics').'</span></div>';
                                                  } 
                                                ?>
                                              </div>
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
                                      <div class="data-holder" id="itg-block-12">
                                        <?php
                                          if (isset($widget_data['itg-block-12']['widget'])) {
                                            print $widget_data['itg-block-12']['widget']; 
                                          } else{
                                            print '<div class="widget-placeholder"><span>'.t('Videos').'</span></div>';
                                          } 
                                        ?>
                                      </div>
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
                                      <div class="data-holder" id="itg-block-13">
                                        <?php
                                          if (isset($widget_data['itg-block-13']['widget'])) {
                                            print $widget_data['itg-block-13']['widget']; 
                                          } else{
                                            print '<div class="widget-placeholder"><span>'.t('Latest').'</span></div>';
                                          } 
                                        ?>
                                      </div>
                                  </div>             
                              </div>
                          </div>
                      </div>
                      <div class="col-md-4 mt-50">

                          <div class="row">
                              <div class="col-md-12 col-sm-6 col-xs-12">                    
                                  <div class="itg-widget-parent">
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

                              <div class="col-md-12 col-sm-6 col-xs-12 mt-50 ipad-space">
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

                                              <div class="data-holder" id="itg-block-15">
                                                <?php
                                                  if (isset($widget_data['itg-block-15']['widget'])) {
                                                    print $widget_data['itg-block-15']['widget']; 
                                                  } else{
                                                    print '<div class="widget-placeholder"><span>'.t('Previous budget').'</span></div>';
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