<?php
global $base_url;
?>
<div id="section-header-event-1206755" class="india-today-woman-summit">
    <div class="header-ads header_ltop_container">
        <div class="row">
            <div class="col-lg-3 col-md-3 col-sm-4 col-xs-12">
                <div class="main_logo"> <a href="/" title="Salaam cricket 2017"><img src="<?php echo file_create_url(file_default_scheme() . '://section_header_images/logo.png') ?>" alt="Salaam cricket 2017"></a> </div>
            </div>
            <div class="col-lg-9 col-md-9 col-sm-8 col-sm-12">
                <div class="topRight">
                    <div class="photosec">
                        <img src="<?php echo file_create_url(file_default_scheme() . '://section_header_images/meetthe-img.png'); ?>" alt="">

                    </div>

                    <div class="brandLogo">
                        <ul>
                            <li><a href="http://indiatoday.intoday.in" target="_blank"><img src="<?php echo file_create_url(file_default_scheme() . '://section_header_images/IT-logo.jpg') ?>" alt=""></a></li>
                            <li><a href="http://aajtak.intoday.in" target="_blank"><img src="<?php echo file_create_url(file_default_scheme() . '://section_header_images/AT-logo.png') ?>" alt=""></a></li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="itg-logo-container">
        <nav class="navigation">
            <div class="container">
                <?php
                if ($data['is_event']) {
                  ?>
                  <div class="row event-menu GoogleAnalyticsET-processed">
                      <div class="col-md-8 col-sm-8 GoogleAnalyticsET-processed" style="color:#f7ee23">
                          <ul class="menu">
                              <?php foreach ($data['data']['menu_manager']['menu'] as $menu): ?>
                                <?php print $menu ?>
                              <?php endforeach; ?>
                          </ul>	  
                      </div>
                      <div class="col-md-4 col-sm-4 GoogleAnalyticsET-processed">
                          <div class="event-detail GoogleAnalyticsET-processed">
                              <span class="event-str-date"><?php echo $data['data']['menu_manager']['event_start_date']; ?></span>
                              <span class="event-vanue-detail-place"><?php echo $data['data']['menu_manager']['event_location']; ?></span>                
                          </div>            
                      </div>        
                  </div>
                  <?php
                }else if ($data['data']['menu_manager']) {
                  $menu_manager = !empty($data['data']['menu_manager']) ? $data['data']['menu_manager'] : '';
                  print drupal_render(menu_tree_output($menu_manager));
                }
                ?>
            </div>         
        </nav>
    </div>
    <div class="event-add-header">
        <?php
        $block = block_load('itg_ads', ADS_HEADER);
        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
        print render($render_array);
        ?>
    </div>   
</div>

