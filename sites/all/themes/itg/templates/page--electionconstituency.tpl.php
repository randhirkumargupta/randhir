<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
drupal_add_js(drupal_get_path('module', 'itg_widget') . '/js/itg_election_refresh_block.js', array('type' => 'file', 'scope' => 'footer'));
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
    <div class="row electiontop-header mb-20">
     <?php 
        //$header_text_value = isset($data['field_constituency_header_text_value']) ? "<span>". $data['field_constituency_header_text_value'] ."</span> "  : '';  
        $header_text_value = $data['field_constituency_header_text_value'];
        $livetext = '';
        $header_text = '';
        if (!empty($data['field_constituency_header_text_value'])) {
          $header_text_value = explode(',', $data['field_constituency_header_text_value']);
          $header_text = $header_text_value[0];
          if (!empty($header_text_value[1])) {
            $livetext = $header_text_value[1];
          }
        }
      ?>  
        
        <div class="col-md-8 col-sm-8 col-sx-8 custom-page-title"> <h1><?php print $livetext .' '. drupal_get_title() .' '. $header_text; ?></h1> </div>
        <div class="col-md-4 col-sm-4 col-sx-4 election-back-button"><span class="back-button"><a href="<?php print FRONT_URL . '/' . drupal_get_path_alias('taxonomy/term/' . $_GET['section']);?>"><i class="fa fa-long-arrow-left" aria-hidden="true"></i> <?php echo get_itg_variable('itg_election_home_bottom_label', 'Back');?></a></span> </div>
    </div>
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
                            <h2 class="heading">Past Results</h2>
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
                                <h2 class="heading"><?php print get_html_widget_name_by_layout($_GET['section'], 'page--special_election', 'itg-block-7', 'Latest Karnataka News'); ?></h2>                                            
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
                <?php if(get_itg_variable('itg_election_mini_graph')) : ?>  
                <div class="col-md-12 col-sm-6 mt-50 itg-election-map">
                    <div class="itg-widget">
                        <div class="droppable">                                        
                            <h2 class="heading">Results Map</h2>                                                 
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
                <?php endif; ?>
                <div class="itg-484 col-md-12 col-sm-6 mt-50">
                    <div class="itg-widget">
                        <div class="droppable">                                        
                            <h2 class="heading"><?php print get_html_widget_name_by_layout($_GET['section'], 'page--special_election', 'itg-block-12', 'Videos'); ?></h2>                                                 
                            <div class="data-holder" id="itg-block-12">
                                <?php echo views_embed_view('tech', 'election_videos'); ?>
                            </div>
                        </div>             
                    </div>               
                </div> 

                <div class="itg-320 col-md-12 col-sm-6 mt-50">
                    <div class="itg-widget">
                        <div class="droppable <?php print $gray_bg_layout; ?>">
                            <div class="widget-wrapper">
                                <h2 class="heading"><?php print get_html_widget_name_by_layout($_GET['section'], 'page--special_election', 'itg-block-10', 'Who said what'); ?></h2>
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
                                <h2 class="heading"><?php print get_html_widget_name_by_layout($_GET['section'], 'page--special_election', 'itg-block-11'); ?></h2>                                                 
                                <div class="data-holder" id="itg-block-11">
                                    <?php
                                    print get_html_widget_data_by_layout($_GET['section'], 'page--special_election', 'itg-block-11', 'custom_html_widgets');
                                    ?>
                                </div>
                            </div>             
                        </div>               
                    </div> 
                </div>
                <?php $static_pages_nids = get_itg_variable('election_staticpages_nid');
                   if (!empty($static_pages_nids)){
                     $static_pages_data = get_html_widget_data_by_nids($static_pages_nids);
                     foreach ($static_pages_data as $_key => $_value) { ?>
                       <div class="itg-320 col-md-12 col-sm-6 mt-50">
                          <div class="itg-widget">
                              <div class="droppable">
                                  <div class="widget-wrapper">
                                      <h2 class="heading"><?php print $_value->title; ?></h2>                                                 
                                      <div class="data-holder">
                                          <?php
                                          print $_value->body_value;
                                          ?>
                                      </div>
                                  </div>             
                              </div>               
                          </div> 
                      </div>
                     <?php }
                   }
                ?>

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

