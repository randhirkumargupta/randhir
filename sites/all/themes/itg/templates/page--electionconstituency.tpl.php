<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
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
                                <?php
                                $block = block_load('itg_widget', 'election_constituency_page');
                                $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                print render($render_array);
                                ?>
                            </div>
                        </div>                     
                    </div>
                </div>
            </div>
            <div class="">
                <div class="itg-widget">
                    <div class="droppable itg-layout-605">
                        <div id="auto-new-block" class="widget-wrapper">
                            <h4 class="heading">Past Results</h4>
                            <div class="data-holder" id="itg-block-1">
                                <?php
                                $block = block_load('itg_widget', 'election_past_results');
                                $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                print render($render_array);
                                ?>
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

