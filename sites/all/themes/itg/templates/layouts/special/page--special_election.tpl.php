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
drupal_add_js(drupal_get_path('module', 'itg_widget') . '/js/itg_election_refresh_block.js', array('type' => 'file', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('theme', 'itg')  . '/js/budget_predictor/jquery.cookie.js', array('weight' => 7, 'scope' => 'footer'));
$itg_election_home_webcast_livetv = get_itg_variable('itg_election_home_webcast_livetv');
?>
<?php
global $theme;
global $base_url;
$live_url = "";
$preview = NULL;

if (arg(2) == 'preview') {
  $preview = 'preview';
}
if ($theme == 'itgadmin' || $preview == 'preview') {
  global $conf;
  $conf['preprocess_js'] = 0;
}
$tax_data = menu_get_object('taxonomy_term', 2);
if (isset($_GET['ele_is_live']) && $_GET['ele_is_live'] == 'is_live') {
  $tax_data->field_is_election_live[LANGUAGE_NONE][0]['value'] = 1;
}
if (empty($tax_data->field_is_election_live[LANGUAGE_NONE][0]['value'])) {
  $highlights = itg_widget_highlights_block_data();
  $device = itg_live_tv_company('web');
  if (!empty($device[0])) {
    $live_tv_get_details = node_load($device[0]);
    $live_url = $live_tv_get_details->field_ads_ad_code[LANGUAGE_NONE][0]['value'];
    if (filter_var($live_url, FILTER_VALIDATE_URL)) {
      $live_url = '<iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="<?php print $live_url; ?>"></iframe>';
    }
  }
}
else {
  
}
//~ p($tax_data->field_is_election_live);
if ($theme == 'itgadmin' && !isset($preview)) {
  $gray_bg_layout = 'gray-bg-layout';
}
?>
<script src="<?php echo $base_url; ?>/sites/all/themes/itg/js/election_map.js"></script>
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
                <?php
                $graphdata = array();
                if (!empty($tax_data->field_is_election_live[LANGUAGE_NONE][0]['value'])) {
                  $itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
                  if (!empty($itg_election_home_content_id)) {
                    $story_title = get_first_story_title_by_tid($itg_election_home_content_id);
                    $content_link = $base_url . "/" . drupal_get_path_alias('node/' . $story_title[0]['nid']);
                    $story_title_display = $story_title[0]['title'];
                    $actual_link = $content_link;
                    $search_title = preg_replace("/'/", "\\'", $story_title_display);
                    $fb_share_title = htmlentities($story_title_display, ENT_QUOTES);  
                    $short_url = $actual_link;
                    $story_title_display = l($story_title_display, $content_link);
                    $display_title = "";
                    if (empty($story_title)) {
                      $display_title = 'style="display:none"';
                    }
                    if (!empty($story_title[0]['uri'])) {
                      $src = file_create_url($story_title[0]['uri']);
                    }
                    $list_story = get_miscellaneous_content($section, NULL, 'home-story-lists');
										$list_story_li = '';
										foreach ($list_story as $_key => $_value) {
											if(!empty($_value->field_story_external_url_value)){
												$list_story_li .= '<li><a href="'.$_value->field_story_external_url_value.'">'.$_value->title.'</a></li>';
											}else{
												 $list_story_li .= '<li>'.$_value->title.'</li>';
											}
										}
                    echo '<div class="row"><div class="col-md-12 election-top-block"><h1 ' . $display_title . ' id="display_tit"><span class="highlights-title">' . $story_title_display . '</span></h1><div class="liststory-election"><ul>' .$list_story_li.'</ul></div> </div></div>';
                  }                  
                  $graphdata = itg_widget_get_graph_data();
                }
                if (!empty($tax_data->field_is_election_live[LANGUAGE_NONE][0]['value']) && count($graphdata) > 2) {
                  ?>
                  <div class="row election-graph election-graph-<?php echo count($graphdata); ?>">
                      <?php
                      $block = module_invoke('itg_widget', 'block_view', 'graph_election');
                      print render($block['content']);
                      ?>
                  </div>
                        <?php } ?>
                <div class="row">
                    <div class="col-md-8 col-sm-12 col-sx-12 election-graph left-side">
                            <?php if (!empty($tax_data->field_is_election_live[LANGUAGE_NONE][0]['value']) && count($graphdata) <= 2) {
                              ?>
                          <div class="row itg-415-layout">
                              <?php
                              $block = module_invoke('itg_widget', 'block_view', 'graph_election');
                              print render($block['content']);
                              ?>
                          </div>
<?php } ?>
<?php if (!empty($tax_data->field_is_election_live[LANGUAGE_NONE][0]['value'])) { ?>
                          <div class="row itg-325-layout" id="livetv-section">
                              <div class="col-md-6 col-sm-6 mt-50">
                                 <div class="itg-widget">
                                    <h2 class="widget-title" data-id="itg-block-3"><?php print 'Live TV'; ?></h2>
                                    <div class="data-holder" id="itg-block-3">
                                      <div class="placeholder-livetv">
                                      <div class="livetv-fixed">
                                        <span class="closelive" id="closetv">X</span>
                                        <?php if(!empty($itg_election_home_webcast_livetv) && $itg_election_home_webcast_livetv == 'webcast'){?>
											<div class="data-holder" id="home-webcast-election">
											  <?php
												print get_itg_variable('itg_election_home_webcast_html');
											  ?>
											</div>
										<?php } ?>
										<?php else { ?>
                                      <?php
                                      $block = block_load('itg_widget', 'live_tv');
                                      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                      print render($render_array);
                                      ?>
                                      <?php } ?>
                                      </div>
                                      </div>
                                     <div class="homelive-share">
                                      <span class="sharethis">SHARE </span>
                                          <?php
                                          $liveTvshare = FRONT_URL . '/livetv';
                                          $liveTvfb_share_title = get_itg_variable('itg_livetvshare_title');
                                          $liveTvshare_desc = get_itg_variable('itg_livetvshare_desc');
                                          $liveTvsrc = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/logo.png');
                                            print '<div class="social-share">
                                                   <ul>
                                                       <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                                                       <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $liveTvshare . "'" . ', ' . "'" . $liveTvfb_share_title . "'" . ', ' . "'" . $liveTvshare_desc . "'" . ', ' . "'" . $liveTvsrc . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                                                       <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($liveTvfb_share_title) . "'" . ', ' . "'" . urlencode($liveTvshare) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                                                       <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $liveTvshare . "'" . ')" class="google def-cur-pointer"><i class="fa fa-google-plus"></i></a></li>
                                                   </ul>
                                               </div>';
                                          ?>
                                     </div>    
                                    </div>
                                </div> 
                              </div>
                              <div class="col-md-6 col-sm-6 mt-50">
                                  <div class="itg-widget">
                                      <h2 class="widget-title" data-id="itg-block-4"><?php print 'Top stories'; ?></h2>
                                      <div class="data-holder" id="itg-block-4">
                                        <?php
                                        $block = block_load('itg_widget', 'election_top_stories');
                                        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                        print render($render_array);
                                        ?>  
                                      </div>
                                  </div>
                              </div>
                          </div>
                            <script>
                          document.addEventListener("DOMContentLoaded", function(event) {
							  jQuery(window).scroll(function(){
							  var cookies_id = jQuery.cookie("COOKIES_IT_liveTv");
							  if(cookies_id === undefined || cookies_id != 'smalltv'){
							  if (jQuery(window).width() > 1024) {
								jQuery('#livetv-section').each(function(){
								  var zt = jQuery('#livetv-section').offset().top + 350;
								  var tr = jQuery(window).scrollTop();
								  var scrval = tr > zt ? true : false;
								if(scrval){
								  jQuery('.livetv-fixed').addClass('active');      
								}
								else{
								  jQuery('.livetv-fixed').removeClass('active');
								}
							  });
							}
							}
							});
                            jQuery('#closetv').click(function(){
                                var date = new Date();
                                var minutes = 30;
                                date.setTime(date.getTime() + (minutes * 60 * 1000));
                                jQuery.cookie("COOKIES_IT_liveTv", 'smalltv', { expires: date });
                                jQuery('.livetv-fixed').removeClass('active');
                            })
                            function isScrolledIntoView(elem){
                                var elem = jQuery(elem);
                                var window = jQuery(window);
                                var docViewTop = window.scrollTop();
                                var docViewBottom = docViewTop + window.height();
                                var elemTop = elem.offset().top;
                                var elemBottom = elemTop + elem.height();
                                return ((elemBottom <= docViewBottom) && (elemTop >= docViewTop));
                            }
                          });   
                            </script>
<?php }
else { ?>

                          <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Automated Top Story'); ?></strong> )</div>
                          <div class="">
                              <div class="itg-widget">
                                  <div class="droppable itg-layout-605 <?php print $gray_bg_layout; ?>">
                                      <div id="auto-new-block" class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name'] . $widget_data['itg-block-1']['widget_display_name']; ?>">
                                          <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-1']['block_title'])) { ?>
                                            <h2 class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></h2>
  <?php } ?>
  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                            <div class="widget-settings">
                                                <div class="widget-title-wrapper">
                                                    <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-1']['block_title']; ?>" name="itg-block-1" class="block_title_id" placeholder="Enter Title" />
                                                </div>
                                                <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-1"><i class="fa fa-times"></i></a></span>
                                            </div>  
                                              <?php } ?>    
                                          <div class="data-holder" id="itg-block-1">
                                              <?php
                                              if (isset($widget_data['itg-block-1']['widget'])) {
                                                print $widget_data['itg-block-1']['widget'];
                                              }
                                              else {
                                                print '<div class="widget-placeholder"><span>' . t('Auto featured') . '</span></div>';
                                              }
                                              ?>
                                          </div>
                                      </div>                     
                                  </div>
                              </div>
                          </div>
                            <?php } ?>
                          <div class="row">
                            <div class="itg-325 mt-50  col-md-12 col-sm-12">
                                <div class="widget-help-text">Special widgets ( <strong>Seats</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-14']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-14']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-14']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-14"><?php print $widget_data['itg-block-14']['block_title']; ?></h2>
  <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-14']['block_title']; ?>" name="itg-block-14" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-14"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?> 
                                            <div class="data-holder" id="itg-block-14">
                                                <?php
                                                if (isset($widget_data['itg-block-14']['widget']) && !empty($widget_data['itg-block-14']['widget'])) {
                                                  print $widget_data['itg-block-14']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Seats') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div>
                            </div>
                          </div>    
                        <!-- Block area for Seats block-->                            
                        <div class="row">
                            <?php
                            $adsclass = "";
                            $key_candidate_extra_block = "";
                            $margin_class = 'election-topaddd';
                            if (count($graphdata) > 2) {
                              $adsclass = 'ads-after-two mt-50';
                              $margin_class = 'election-topadd';
                              $key_candidate_extra_block = 'key_candidate_extra_block';
                            }
                            ?>                       
                            <div class="itg-325 mt-50 <?php echo $key_candidate_extra_block; ?> col-md-6 col-sm-12">
                                <div class="widget-help-text">Special widgets ( <strong>Key candidate</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php //print $widget_data['itg-block-9']['widget_name'];    ?>">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-9']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-9']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-9']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-9"><?php print $widget_data['itg-block-9']['block_title']; ?></h2>
  <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-9']['block_title']; ?>" name="itg-block-9" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-9"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?> 
                                            <div class="data-holder" id="itg-block-9">
                                                <?php
                                                if (isset($widget_data['itg-block-9']['widget'])) {
                                                  print $widget_data['itg-block-9']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Key candidate') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div>
                            </div>
                            <div class="itg-325 mt-50  col-md-6 col-sm-12">
                                <div class="widget-help-text">Special widgets ( <strong>Know your party</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php //print $widget_data['itg-block-13']['widget_name'];    ?>">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-13']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-13']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-13']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-13"><?php print $widget_data['itg-block-13']['block_title']; ?></h2>
  <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-13']['block_title']; ?>" name="itg-block-13" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-13"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?> 
                                            <div class="data-holder" id="itg-block-13">
                                                <?php
                                                if (isset($widget_data['itg-block-13']['widget']) && !empty($widget_data['itg-block-13']['widget'])) {
                                                  print $widget_data['itg-block-13']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Know oyur party') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div>
                            </div>
                        </div>
                        
                         
                        
                        <div class="row itg-photo">
                            <div class="col-md-12 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Photo</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-8']['widget_name'] . $widget_data['itg-block-8']['widget_display_name']; ?>">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-8']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-8']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-8']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-8"><?php print $widget_data['itg-block-8']['block_title']; ?></h2>
  <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-8']['block_title']; ?>" name="itg-block-8" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-8"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?>  
                                            <div class="data-holder" id="itg-block-8">
                                                <?php
                                                if (isset($widget_data['itg-block-8']['widget'])) {
                                                  print $widget_data['itg-block-8']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Photo') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="row itg-most-popular">
                            <div class="col-md-12 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Most Popular</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-7']['widget_name']; ?>">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-7']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-7']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-7']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-7"><?php print $widget_data['itg-block-7']['block_title']; ?></h2>
  <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-7']['block_title']; ?>" name="itg-block-7" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-7"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?>  
                                            <div class="data-holder" id="itg-block-7">
                                                <?php
                                                if (isset($widget_data['itg-block-7']['widget'])) {
                                                  print $widget_data['itg-block-7']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Most popular') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="itg-325 mt-50  col-md-12 col-sm-12">
                                <div class="widget-help-text">Special widgets ( <strong>Key Issue</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper">
                                            <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-15']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-15']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-15']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-15"><?php print $widget_data['itg-block-15']['block_title']; ?></h2>
  <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-15']['block_title']; ?>" name="itg-block-15" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-15"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?> 
                                            <div class="data-holder" id="itg-block-15">
                                                <?php
                                                if (isset($widget_data['itg-block-15']['widget']) && !empty($widget_data['itg-block-15']['widget'])) {
                                                  print $widget_data['itg-block-15']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Key Issue') . '</span></div>';
                                                }
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
                                <div class="widget-help-text">Non Draggable ( <strong>Ads</strong> )</div>
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
                            <div class="col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Non Draggable ( <strong>MAP</strong> )</div>
                                <div class="itg-widget">
                                    <h2 class="heading">Results Map</h2> 
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                    <?php
                                        $block = block_load('itg_widget', 'election_mini_map');
                                        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                        print render($render_array);
                                    ?>
                                    </div>                                                                       
                                </div>
                            </div>                           
                            <?php endif; ?>
                            <div class="itg-484 col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Videos</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-12']['widget_name']; ?>">
<?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-12']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-12']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-12']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-12"><?php print $widget_data['itg-block-12']['block_title']; ?></h2>
                                              <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-12']['block_title']; ?>" name="itg-block-12" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-12"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?>  
                                            <div class="data-holder" id="itg-block-12">
                                                <?php
                                                if (isset($widget_data['itg-block-12']['widget'])) {
                                                  print $widget_data['itg-block-12']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Videos') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div> 
                            </div>
                            <div class="itg-320 col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Who said What</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-10']['widget_name']; ?>">
<?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-10']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-10']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-10']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-10"><?php print $widget_data['itg-block-10']['block_title']; ?></h2>
                                              <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-10']['block_title']; ?>" name="itg-block-10" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-10"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?>  
                                            <div class="data-holder" id="itg-block-10" data-widget-style="election-so-sorry">
                                                <?php
                                                if (isset($widget_data['itg-block-10']['widget'])) {
                                                  print $widget_data['itg-block-10']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Who said What') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div> 
                            </div> 
                            <div class="itg-320 col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Know your election</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-11']['widget_name']; ?>">
<?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-11']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-11']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-11']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-11"><?php print $widget_data['itg-block-11']['block_title']; ?></h2>
                                              <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-11']['block_title']; ?>" name="itg-block-11" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-11"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?>  
                                            <div class="data-holder" id="itg-block-11">
                                                <?php
                                                if (isset($widget_data['itg-block-11']['widget'])) {
                                                  print $widget_data['itg-block-11']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Know your election') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div> 
                            </div>
                            <div class="itg-484 col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Past results</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-16']['widget_name']; ?>">
<?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-16']['block_title'])) { ?>
                                              <h2 class="heading"><?php print $widget_data['itg-block-16']['block_title']; ?></h2>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-16']['block_title'])) { ?>
                                                        <h2 class="widget-title" data-id="itg-block-16"><?php print $widget_data['itg-block-16']['block_title']; ?></h2>
                                              <?php } ?>
                                                      <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-16']['block_title']; ?>" name="itg-block-16" class="block_title_id" placeholder="Enter Title" />
                                                  </div>
                                                  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                  <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-16"><i class="fa fa-times"></i></a></span>
                                              </div>
                                                <?php } ?>  
                                            <div class="data-holder" id="itg-block-16">
                                                <?php
                                                if (isset($widget_data['itg-block-16']['widget'])) {
                                                  print $widget_data['itg-block-16']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Know your election') . '</span></div>';
                                                }
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
