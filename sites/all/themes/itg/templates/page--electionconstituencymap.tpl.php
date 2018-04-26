<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
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
            <div class="itg-layout-container auto-layout-page election-page itg-front">
                <!-- Breaking news band -->    
                <?php if (!empty($page['breaking_news'])): ?>
                  <div class="row">
                      <div class="col-md-12">
                          <?php print render($page['breaking_news']); ?>
                      </div>      
                  </div>    
                <?php endif; ?>
                <div class="row itg-map">
                    <div class="col-md-12 mt-50">
                        <div class="itg-widget">
                            <div class="droppable itg-layout-605">
                                <div id="auto-new-block" class="widget-wrapper">
                                    <div class="data-holder" id="itg-block-1">
                                        <iframe frameborder="0" height="635" name="crbz_scag_frame" scrolling="no" src="https://smedia2.intoday.in/elections/2018/maps/karnataka.html" width="100%"></iframe>
                                        <?php
                                          $map_iframe_html = get_constituency_large_map_html($_GET['section']);
                                          print $map_iframe_html;
                                        ?>
                                    </div>
                                </div>                     
                            </div>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col-md-8 col-sm-12 col-sx-12 election-graph left-side">             
                        <div class="row itg-seats">
                            <div class="col-md-12 mt-50">
                                <div class="itg-widget">
                                    <div class="droppable itg-layout-605">
                                        <?php $seathtml = get_html_widget_data_by_layout($_GET['section'], 'page--special_election', 'itg-block-14', 'custom_html_widgets'); ?>
                                        <div id="auto-new-block" class="widget-wrapper">
                                            <?php if (!empty($seathtml)) { ?>
                                              <h4 class="heading">Seats</h4>  
                                            <?php } ?>
                                            <div class="data-holder" id="itg-block-1">
                                                <?php
                                                print $seathtml;
                                                ?>
                                            </div>
                                        </div>                     
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="row itg-key-condidates">
                            <div class="col-md-6 col-sm-12 itg-325 mt-50">
                                <div class="itg-widget">
                                    <div class="droppable itg-layout-605">
                                        <?php $condhtml = get_html_widget_data_by_layout($_GET['section'], 'page--special_election', 'itg-block-9', 'custom_html_widgets'); ?>
                                        <div id="auto-new-block" class="widget-wrapper">
                                            <?php if (!empty($condhtml)) { ?>
                                              <h4 class="heading">Key Candidate</h4>  
                                            <?php } ?>
                                            <div class="data-holder" id="itg-block-1">
                                                <?php
                                                print $condhtml;
                                                ?>
                                            </div>
                                        </div>                     
                                    </div>
                                </div>
                            </div>
                            <div class="col-md-6 col-sm-12 itg-325 mt-50">
                                <div class="itg-widget">
                                    <div class="droppable itg-layout-605">
                                        <div id="auto-new-block" class="widget-wrapper">
                                            <h4 class="heading">Know Your party</h4>  
                                            <div class="data-holder" id="itg-block-1">
                                                <?php
                                                  $block = block_load('itg_widget', 'election_know_your_party');
                                                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                                  print render($render_array);
                                                ?>
                                            </div>
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
                                                <?php echo views_embed_view('most_popular', 'elections_most_popular'); ?>
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
        </section>                  
    </main>
    <?php print render($page['footer']); ?>
</div>
<?php print render($page['bottom']); ?>
