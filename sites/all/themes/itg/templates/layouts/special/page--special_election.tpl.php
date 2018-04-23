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

if (arg(2) == 'preview') {
  $preview = 'preview';
}
if ($theme == 'itgadmin' || $preview == 'preview') {
  global $conf;
  $conf['preprocess_js'] = 0;
}
$tax_data = menu_get_object('taxonomy_term', 2);
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
                  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
                  $search_title = preg_replace("/'/", "\\'", $widget_data['itg-block-4']['block_title']);
                  $fb_share_title = htmlentities($search_title, ENT_QUOTES);
                  $itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
                  $story_title = get_first_story_title_by_tid($itg_election_home_content_id);
                  $story_title_display = mb_strimwidth($widget_data['itg-block-4']['block_title'], 0, 90, "..");
                  if (!empty($story_title)) {
                    $content_link = $base_url . "/" . drupal_get_path_alias('node/' . $story_title[0]['nid']);
                    $story_title_display = l(mb_strimwidth($story_title[0]['title'], 0, 90, ".."), $content_link);
                    $actual_link = $content_link;
                    $search_title = preg_replace("/'/", "\\'", $story_title_display);
                    $fb_share_title = htmlentities($story_title_display, ENT_QUOTES);
                  }
                  else {
                    $short_url = shorten_url($actual_link, 'goo.gl');
                  }
                  $display_title = "";
                  if ($widget_data['itg-block-4']['block_title'] == "" && empty($story_title)) {
                    $display_title = 'style="display:none"';
                  }

                  echo '<div class="row"><div class="col-md-12 election-top-block"><h1 ' . $display_title . ' id="display_tit"><span class="highlights-title">' . $story_title_display . '</span></h1> <div class="social-share">
                              <ul>
                                  <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                                  <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $src . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                                  <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($search_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                                  <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google def-cur-pointer"></a></li>
                              </ul>
                          </div></div></div>';
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
                          <div class="row itg-325-layout">
                              <div class="col-md-6 col-sm-6 mt-50">
                                 <div class="itg-widget">
                                    <span class="widget-title" data-id="itg-block-3"><?php print 'LiveTV'; ?></span>
                                    <div class="data-holder" id="itg-block-3">
                                      <?php
                                      $block = block_load('itg_widget', 'live_tv');
                                      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                                      print render($render_array);
                                      ?>
                                    </div>
                                </div> 
                              </div>
                              <div class="col-md-6 col-sm-6 mt-50">
                                  <div class="itg-widget">
                                      <span class="widget-title" data-id="itg-block-4"><?php print 'Top stories'; ?></span>
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
<?php }
else { ?>

                          <div class="widget-help-text"><?php print t('Special widgets'); ?> ( <strong><?php print t('Automated Top Story'); ?></strong> )</div>
                          <div class="">
                              <div class="itg-widget">
                                  <div class="droppable itg-layout-605 <?php print $gray_bg_layout; ?>">
                                      <div id="auto-new-block" class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name'] . $widget_data['itg-block-1']['widget_display_name']; ?>">
                                          <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-block-1']['block_title'])) { ?>
                                            <span class="widget-title"><?php print $widget_data['itg-block-1']['block_title']; ?></span>
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
                                              <h4 class="heading"><?php print $widget_data['itg-block-14']['block_title']; ?></h4>
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
                        
                        <div class="row">
                            <div class="itg-325 mt-50  col-md-12 col-sm-12">
                                <div class="widget-help-text">Special widgets ( <strong>Key Issue</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper">
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
                        
                        <div class="row itg-photo">
                            <div class="col-md-12 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Photo</strong> )</div>
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php print $widget_data['itg-block-8']['widget_name'] . $widget_data['itg-block-8']['widget_display_name']; ?>">
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
                            <div class="col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Non Draggable ( <strong>MAP</strong> )</div>
                                <div class="itg-widget">
                                    <?php
                                    if ($theme != 'seven') {
                                      if ($theme == FRONT_THEME_NAME) {
                                        $section = arg(2);
                                      }
                                      else {
                                        $section = $_GET['section'];
                                        if (isset($_GET['category']) && !empty($_GET['category'])) {
                                          $section = $_GET['category'];
                                        }
                                      }
                                    }
                                    $vocabulary = taxonomy_vocabulary_machine_name_load('state_managment');
                                    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
                                    if (!empty($terms)) {
                                      ?>
                                      <div class="droppable <?php print $gray_bg_layout; ?>">
                                          <div class="widget-wrapper map-box <?php print $widget_data['itg-block-5']['widget_name']; ?>">
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-5']['block_title'])) { ?>
                                                <h4 class="heading"><?php print $widget_data['itg-block-5']['block_title']; ?></h4>
                                                      <?php } ?>
                                              <!-- for admin  -->
                                                      <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
    <?php if (isset($widget_data['itg-block-5']['block_title'])) { ?>
                                                          <span class="widget-title" data-id="itg-block-5"><?php print $widget_data['itg-block-5']['block_title']; ?></span>
                                                <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                </div>
                                                    <?php
                                                  }
                                                  ?>                                          
                                              <div class="data-holder pos-rel" id="itg-block-5">                              

                                                  <?php
                                                  $countf = 0;
                                                  $svgurl = "";
                                                  $mapgurl = "";
                                                  $colorurl = "";
                                                  $state = 0;
                                                  $state_opt = '';
                                                  foreach ($terms as $values) {
                                                    if ($values->field_section[LANGUAGE_NONE][0]['tid'] == $section) {
                                                      if ($countf == 0) {
                                                        $svgurl1 = $values->field_state_svg_json[LANGUAGE_NONE][0]['value'];
                                                        $state = $values->tid;
                                                      }
                                                      $svgurl = $values->field_state_svg_json[LANGUAGE_NONE][0]['value'];
                                                      $mapgurl = $values->field_state_map_json[LANGUAGE_NONE][0]['value'];
                                                      $colorurl = $values->field_state_map_color_json[LANGUAGE_NONE][0]['value'];
                                                      echo '<input type="hidden" name="svg_url_' . $values->tid . '" value= "' . $svgurl . '" id="svg_url_' . $values->tid . '">';
                                                      echo '<input type="hidden" name="election_cat_' . $values->tid . '" value= "' . arg(2) . '" id="election_cat_' . $values->tid . '">';

                                                      $state_opt .= '<option value="' . $values->tid . '">' . $values->name . '</option>';
                                                      $countf++;
                                                    }
                                                  }
                                                  //~ $urlarray = array('svgurl' => $svgurl, 'mapjson' => $mapgurl, 'color_url' => $colorurl);
                                                  ?>
                                                  <select id="map-state" name="map_state" onChange="change_mini_state_graph(this)">
  <?php echo $state_opt; ?>
                                                  </select>
                                                  <div id="main_container" class="map-result-detail">
                                                      <div id= "consTable"></div></div>
                                                  <div id = "conssvg"></div>
                                                  <div class="small_state_graph_wrapper">
                                                      <a href="/state-elections/<?php echo arg(2) . "/" . $state; ?>"> 
                                                          <div class="small_state_graph">
                                                              <iframe src="<?php echo $svgurl1; ?>" frameborder="0" style="overflow:hidden;height:100%;width:100%;pointer-events: none;" height="100%" width="100%" > </iframe>
                                                          </div>
                                                      </a>
                                                  </div>
                                              </div>
                                          </div>             
                                      </div>
                                            <?php
                                            }
                                            else {
                                              ?>
                                      <div class="droppable <?php print $gray_bg_layout; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-5']['widget_name']; ?>">
  <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-5']['block_title'])) { ?>
                                                <h4 class="heading"><?php print $widget_data['itg-block-5']['block_title']; ?></h4>
                                                      <?php } ?>
                                              <!-- for admin  -->
                                                      <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
    <?php if (isset($widget_data['itg-block-5']['block_title'])) { ?>
                                                          <span class="widget-title" data-id="itg-block-5"><?php print $widget_data['itg-block-5']['block_title']; ?></span>
                                                <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-5']['block_title']; ?>" name="itg-block-5" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                    <span><a  href="javascript:void(0)" class="delete-block-widget" delete-block-id="itg-block-5"><i class="fa fa-times"></i></a></span>
                                                </div>
                                                  <?php } ?>  
                                              <div class="data-holder" data-widget-style="election-other-story" id="itg-block-5">
                                                  <?php
                                                  if (isset($widget_data['itg-block-5']['widget'])) {
                                                    print $widget_data['itg-block-5']['widget'];
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>' . t('Map') . '</span></div>';
                                                  }
                                                  ?>
                                              </div>
                                          </div>             
                                      </div>
<?php } ?>
                                </div>
                            </div>
                            <div class="itg-484 col-md-12 col-sm-6 mt-50">
                                <div class="widget-help-text">Special widgets ( <strong>Videos</strong> )</div>
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
                                              <h4 class="heading"><?php print $widget_data['itg-block-16']['block_title']; ?></h4>
                                                    <?php } ?>
                                            <!-- for admin  -->
                                                    <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                              <div class="widget-settings">
                                                  <div class="widget-title-wrapper">
  <?php if (isset($widget_data['itg-block-16']['block_title'])) { ?>
                                                        <span class="widget-title" data-id="itg-block-16"><?php print $widget_data['itg-block-16']['block_title']; ?></span>
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
