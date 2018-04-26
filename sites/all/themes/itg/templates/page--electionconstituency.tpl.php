<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
//drupal_add_library('flexslider', 'flexslider');
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $widget_data['itg-block-4']['block_title']);
$fb_share_title = htmlentities($search_title, ENT_QUOTES);
$short_url = $actual_link;
$share_desc = '';
$src = '';
?>
<?php
global $theme;
global $base_url;
$live_url = "";
$preview = NULL;


if ($theme == 'itgadmin' || $preview == 'preview') {
  global $conf;
  $conf['preprocess_js'] = 0;
}
//$tax_data = taxonomy_term_load($_GET['section']);

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
            <?php //print render($page['content']);    ?>
            <?php
            $itg_class = 'itg-admin';
            if ($theme != 'itgadmin') {
              $itg_class = 'itg-front';
            }
            ?>
            <div class="itg-layout-container auto-layout-page election-page <?php echo $itg_class; ?> ">
                <!-- Breaking news band -->    
<?php if (!empty($page['breaking_news'])): ?>
                  <div class="row">
                      <div class="col-md-12">
  <?php print render($page['breaking_news']); ?>
                      </div>      
                  </div>    
                <?php endif; ?>
                <div class="row">
                    <div class="col-md-8 col-sm-12 col-sx-12 election-graph left-side">             
                          <div class="">
                              <div class="itg-widget">
                                  <div class="droppable itg-layout-605">
                                      <div id="auto-new-block" class="widget-wrapper">
                                          <div class="data-holder" id="itg-block-1">
                                              Parse json here
                                          </div>
                                      </div>                     
                                  </div>
                              </div>
                          </div>
                            
                       
                        <div class="row itg-most-popular">
                            <div class="col-md-12 mt-50">
                                <div class="itg-widget">
                                    <div class="droppable">
                                        <div class="widget-wrapper">
                                            <h4 class="heading">Most Popular</h4>                                            
                                            <div class="data-holder" id="itg-block-7">
                                                <?php
                                                  $block = block_load('itg_widget', 'election_most_popular');
                                                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                                  print render($render_array);
                                                ?>
                                            </div>
                                        </div>             
                                    </div>
                                </div>
                            </div>
                        </div>                           
                    </div>    
                    <div class="col-md-4 col-sm-12 col-sx-12 right-side itg-map">
                        <div class="row">
                            <div class="<?php echo $adsclass; ?> col-md-12 col-sm-6">
                                <div class="itg-widget <?php echo $margin_class; ?>">
                                    <div class="ad-widget droppable">
                                        <div class="sidebar-ad">
                                            <?php
                                            $block = block_load('itg_ads', ADS_RHS1);
                                            $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                            print render($render_array);
                                            ?></div>
                                    </div>
                                </div>
                            </div> 
                            <div class="col-md-12 col-sm-6 mt-50">
                                <div class="itg-widget">
                                <div class="droppable">                                        
                                    <h4 class="heading">Map</h4>                                                 
                                    <div class="data-holder" id="itg-block-12">
                                    <?php
                                        $block = block_load('itg_widget', 'election_mini_map');
                                        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                        print render($render_array);
                                    ?>
                                    </div>
                                  </div>    
                                </div>
                            </div>
                              <div class="itg-484 col-md-12 col-sm-6 mt-50">
                                <div class="itg-widget">
                                  <div class="droppable">                                        
                                    <h4 class="heading">Videos</h4>                                                 
                                    <div class="data-holder" id="itg-block-12">
                                        <?php echo views_embed_view('tech', 'block_8'); ?>
                                    </div>
                                  </div>             
                                </div>               
                              </div> 
                           
                            <div class="itg-320 col-md-12 col-sm-6 mt-50">
                              <div class="itg-widget">
                                  <div class="droppable <?php print $gray_bg_layout; ?>">
                                      <div class="widget-wrapper">
                                          <h4 class="heading">Who said What</h4>
                                          <div class="data-holder" id="itg-block-10" data-widget-style="election-so-sorry">
                                              <?php
                                              $block = block_load('itg_widget', 'election_who_said_what');
                                              $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                              print render($render_array);
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div> 
                            </div> 
                            <div class="itg-320 col-md-12 col-sm-6 mt-50">
                              <div class="itg-widget">
                                  <div class="droppable">
                                      <div class="widget-wrapper">
                                          <h4 class="heading">Know your election</h4>                                                 
                                          <div class="data-holder" id="itg-block-11">
                                              <?php
                                              print get_html_widget_data_by_layout($_GET['section'], 'page--special_election', 'itg-block-11', 'custom_html_widgets');
                                              ?>
                                          </div>
                                      </div>             
                                  </div>               
                              </div> 
                            </div>
                            
                            <div class="col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Non Draggable ( <strong>Ads</strong> )</div>
                                <div class="itg-widget">
                                    <div class="ad-widget droppable">
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
                    </div>    
                </div>
                <!--End of Common add more section--> 
            </div>
            <!--------------------------------Code for Front tpl---------------------------------------->
            <?php if ($theme != 'itgadmin') { ?>
                  <?php //print $feed_icons;         ?>
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
<?php
$good_big = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/highlights_icons/good-big.png');
$bad_big = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/highlights_icons/Bad-big.png');
$wgmf_big = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/highlights_icons/wgmf-big.png');
?>
<!--animation emoji for hightlight-->
<div id="smily">
    <div class="face1 face"><img src="<?php echo $good_big; ?>" alt="" title="" /></div>    
    <div class="face2 face"><img src="<?php echo $good_big; ?>" alt="" title="" /></div>    
    <div class="face3 face"><img src="<?php echo $good_big; ?>" alt="" title="" /></div>    
    <div class="face4 face"><img src="<?php echo $good_big; ?>" alt="" title="" /></div>       
</div>
<div id="smilysad">
    <div class="face1 face"><img src="<?php echo $bad_big; ?>" alt="" title="" /></div>
    <div class="face2 face"><img src="<?php echo $bad_big; ?>" alt="" title="" /></div>
    <div class="face3 face"><img src="<?php echo $bad_big; ?>" alt="" title="" /></div>
    <div class="face4 face"><img src="<?php echo $bad_big; ?>" alt="" title="" /></div>  
</div>
<div id="wgmf">
    <div class="face1 face"><img src="<?php echo $wgmf_big; ?>" alt="" title="" /></div>
    <div class="face2 face"><img src="<?php echo $wgmf_big; ?>" alt="" title="" /></div>
    <div class="face3 face"><img src="<?php echo $wgmf_big; ?>" alt="" title="" /></div>
    <div class="face4 face"><img src="<?php echo $wgmf_big; ?>" alt="" title="" /></div>
</div>
<!--animation emoji for hightlight end-->
<style>
    .small_state_graph{height: 320px;}
    .election-page .itg-map #map-state{top: 24px;}
</style>
