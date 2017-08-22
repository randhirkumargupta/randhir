<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $widget_data['itg-block-4']['block_title']);
$fb_share_title = htmlentities($search_title, ENT_QUOTES);
$short_url = shorten_url($actual_link, 'goo.gl');
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
$highlights = itg_widget_highlights_block_data();

$device = itg_live_tv_company('web');
if (!empty($device[0])) {
  $live_tv_get_details = node_load($device[0]);
  $live_url = $live_tv_get_details->field_ads_ad_code[LANGUAGE_NONE][0]['value'];
  if (filter_var($live_url, FILTER_VALIDATE_URL)) {
    $live_url = '<iframe frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="<?php print $live_url; ?>"></iframe>';
  }
}


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
            <div class="itg-layout-container election-page <?php echo $itg_class; ?> ">
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
                if ($widget_data['itg-block-4']['block_title'] == "") {
                  $display_title = 'style="display:none"';
                }
                echo '<div class="row"><div class="col-md-12 election-top-block"><h1 ' . $display_title . ' id="display_tit"><span class="highlights-title">' . mb_strimwidth($widget_data['itg-block-4']['block_title'], 0, 90, "..") . '</span></h1> <div class="social-share">
                    <ul>
                        <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                        <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $src . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                        <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($search_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                        <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google def-cur-pointer"></a></li>
                    </ul>
                </div></div></div>';

                $graphdata = itg_widget_get_graph_data();

                if (count($graphdata) > 2) {
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

                        <?php if (count($graphdata) <= 2) {
                          ?>
                          <div class="row itg-415-layout">
                              <?php
                              $block = module_invoke('itg_widget', 'block_view', 'graph_election');
                              print render($block['content']);
                              ?>


                          </div>
                        <?php } ?>
                        <?php if ($theme == 'itgadmin' || (!empty($live_url) || $highlights['node_data']->field_story_highlights['und'][0]['value'] != "" )) { ?>
                          <div class="row itg-325-layout">
                              <div class="col-md-6 col-sm-6 mt-50">
                                  <div class="itg-widget">
                                      <div class=" <?php print $gray_bg_layout; ?>">
                                          <div class="widget-wrapper <?php print $widget_data['itg-block-3']['widget_name']; ?>">
                                              <?php if (($theme != 'itgadmin' || isset($preview)) && isset($widget_data['itg-block-3']['block_title'])) { ?>
                                                <h4 class="heading"><?php print $widget_data['itg-block-3']['block_title']; ?></h4>
                                              <?php } ?>
                                              <!-- for admin  -->
                                              <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
                                                <div class="widget-settings">
                                                    <div class="widget-title-wrapper">
                                                        <?php if (isset($widget_data['itg-block-3']['block_title'])) { ?>
                                                          <span class="widget-title" data-id="itg-block-3"><?php print $widget_data['itg-block-3']['block_title']; ?></span>
                                                        <?php } ?>
                                                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-block-3']['block_title']; ?>" name="itg-block-3" class="block_title_id" placeholder="Enter Title" />
                                                    </div>
                                                    <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                                                </div>
                                              <?php } ?>  

                                              <div class="data-holder" id="itg-block-3">
                                                  <?php print $live_url; ?>
                                              </div>
                                          </div>             
                                      </div>
                                  </div>
                              </div>
                              <div class="col-md-6 col-sm-6 mt-50">
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
                                                  }
                                                  else {
                                                    print '<div class="widget-placeholder"><span>' . t('Highlights') . '</span></div>';
                                                  }
                                                  ?>
                                              </div>

                                          </div>             
                                      </div>
                                  </div>
                              </div>
                          </div>
                        <?php } ?>
                        <div class="row itg-map">
                            <div class="col-md-6 col-sm-6 mt-50">
                                <div class="itg-widget">
                                    <?php
                                    if ($theme != 'seven') {
                                      if ($theme == FRONT_THEME_NAME) {
                                        $section = arg(2);
                                      }
                                      else {
                                        $section = $_GET['section'];
                                      }
                                    }
                                    $vocabulary = taxonomy_vocabulary_machine_name_load('state_managment');
                                    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
                                    if (!empty($terms)) {
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
                                                </div>
                                                <?php
                                              }
                                              ?>  
                                              

                                              <div class="data-holder pos-rel" id="itg-block-5">
                                                <select id="map-state" name="map_state">

                                                  <?php
                                                  $countf = 0;
                                                  $svgurl = "";
                                                  $mapgurl = "";
                                                  $colorurl = "";

                                                  foreach ($terms as $values) {
                                                    if ($values->field_section[LANGUAGE_NONE][0]['tid'] == $section) {
                                                      if ($countf == 0) {
                                                        $svgurl = $values->field_state_svg_json[LANGUAGE_NONE][0]['value'];
                                                        $mapgurl = $values->field_state_map_json[LANGUAGE_NONE][0]['value'];
                                                        $colorurl = $values->field_state_map_color_json[LANGUAGE_NONE][0]['value'];
                                                      }
                                                      echo '<option value="' . itg_layout_clean_url($values->tid) . '">' . $values->name . '</option>';
                                                      $countf++;
                                                    }
                                                  }
                                                  $urlarray = array('svgurl' => $svgurl, 'mapjson' => $mapgurl, 'color_url' => $colorurl);
                                                  ?>
                                              </select>
                                                  <div id="main_container" class="map-result-detail">
                                                      <div id= "consTable"></div></div>
                                                  <div id = "conssvg"></div>
                                                  <script>getconssvg(<?php echo json_encode($urlarray); ?>, "0");</script>
                                              </div>
                                          </div>             
                                      </div>
                                    <?php }
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
                            <div class="col-md-6 col-sm-6 mt-50">
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

                                            <div class="data-holder" data-widget-style="election-other-story" id="itg-block-6">
                                                <?php
                                                if (isset($widget_data['itg-block-6']['widget'])) {
                                                  print $widget_data['itg-block-6']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Other Stories') . '</span></div>';
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
                        <div class="row itg-photo">
                            <div class="col-md-12 mt-50">
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



                    </div>    
                    <div class="col-md-4 col-sm-12 col-sx-12 right-side">        
                        <?php
                        $adsclass = "";
                        $key_candidate_extra_block = "";
                        if (count($graphdata) > 2) {
                          $adsclass = 'ads-after-two';
                          $key_candidate_extra_block = 'key_candidate_extra_block';
                        }
                        ?>
                        <div class="row">


                            <div class="<?php echo $adsclass; ?> col-md-12 col-sm-6 mt-50">
                                <div class="itg-widget election-topadd">
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

                            <div class="itg-325 mt-50 <?php echo $key_candidate_extra_block; ?> col-md-12 col-sm-6">
                                <div class="itg-widget">
                                    <div class="droppable <?php print $gray_bg_layout; ?>">
                                        <div class="widget-wrapper <?php //print $widget_data['itg-block-9']['widget_name'];  ?>">
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
                            <div class="itg-320 col-md-12 col-sm-6 mt-50">
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
                                              </div>
<?php } ?>  

                                            <div class="data-holder" id="itg-block-10" data-widget-style="election-so-sorry">
                                                <?php
                                                if (isset($widget_data['itg-block-10']['widget'])) {
                                                  print $widget_data['itg-block-10']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('So sorry') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div> 
                            </div> 
                            <div class="itg-460 col-md-12 col-sm-6 mt-50">
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
                                              </div>
<?php } ?>  

                                            <div class="data-holder" id="itg-block-11">
                                                <?php
                                                // $block = module_invoke('itg_widget', 'block_view', 'budget_tweets');
                                                //  print render($block['content']);
                                                ?>
                                                <?php
                                                if (isset($widget_data['itg-block-11']['widget'])) {
                                                  print $widget_data['itg-block-11']['widget'];
                                                }
                                                else {
                                                  print '<div class="widget-placeholder"><span>' . t('Live Chat') . '</span></div>';
                                                }
                                                ?>
                                            </div>
                                        </div>             
                                    </div>               
                                </div> 
                            </div>
                            <div class="col-md-12 col-sm-6 mt-50">
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
                            <div class="itg-484 col-md-12 col-sm-6 mt-50">
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
                        </div>
                    </div>    
                </div>
                <!--End of Common add more section--> 
            </div>

            <!--------------------------------Code for Front tpl---------------------------------------->
            <?php if ($theme != 'itgadmin') { ?>
  <?php //print $feed_icons;        ?>
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