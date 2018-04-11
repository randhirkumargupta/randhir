<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */


global $theme, $user, $base_url;
$preview = NULL;

if (arg(2) == 'preview') {
  $preview = 'preview'; 
}
if ($theme == 'itgadmin' || $preview == 'preview') {
  global $conf;
  $conf['preprocess_js'] = 0;
}
if ($theme == 'itgadmin' && !isset($preview)) {
  $gray_bg_layout = 'gray-bg-layout';
}

$itg_class = 'itg-admin';
if ($theme != 'itgadmin') {
  $itg_class = 'itg-front';
}
?>

<!--------------------------------Code for Front tpl---------------------------------------->
<?php if ($theme != 'itgadmin') {?>
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
    <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);

        $cls = 'col-md-12';
        if ($sidebar_first || $sidebar_second):
          $cls = 'col-md-9';
        endif;
    ?>
    <main id="main" class="container section-news pos-rel">
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
 

<div class="itg-layout-container <?php echo $itg_class; ?> auto-layout-page ">
    <!-- Breaking news band -->    
    <?php if (!empty($page['breaking_news'])): ?>
    <div class="row">
        <div class="col-md-12">
          <?php print render($page['breaking_news']); ?>
        </div>      
    </div>    
    <?php endif; ?>
    <?php if(isset($widget_data['big_story'])) : ?>
    <div class="row">
        <div class="col-md-12">
            <?php print $widget_data['big_story']; ?>
        </div>    
    </div>
    <?php endif; ?>   
    
  <!--Common section strat here-->
  <?php if (isset($widget_data['itg-news-section-1']['widget_name']) || isset($widget_data['itg-news-section-2']['widget_name']) || $theme == 'itgadmin') { ?>
    <div class="row itg-common-section">
	<!-- Left 8 Block Section -->
    <div class="col-md-8 col-sm-8">
    <div class="row">
		<div class="col-md-12 col-sm-12">		
			<h2 class="news-head"><span>Top Headlines</span></h2>
			<?php
				$info['widget'] = 'home_page_feature_widget';
				$info['order'] = 'ASC';
				$info['max_limit'] = HOME_PAGE_FEATURE_MAX_RANGE;
				$info['min_limit'] = HOME_PAGE_FEATURE_MIN_RANGE;
				$data = itg_widget_get_widget_data_data($info);
				foreach($data as $data_key => $data_val){ ?>
					<?php if (!empty($data_val['title'])) : ?>
						<h3 class="news-page-feature">
						  <?php
						  if (function_exists('itg_common_get_smiley_title')) {
							echo l(itg_common_get_smiley_title($data_val['nid'], 0, 80), "node/" . $data_val['nid'], array('html' => TRUE , 'attributes' => array("title" => $data_val['title'])));
						  }
						  else {
							echo l(mb_strimwidth($data_val['title'], 0, 90, ".."), "node/" . $data_val['nid']  , array('attributes' => array("title" => $data_val['title'])));
						  }
						  ?>
						</h3>   
					<?php endif; ?>
				<?php } ?>
		</div>
    </div>
    <div class="row">
		<div class="col-md-12 col-sm-12 mt-30">
		  <h1 class="news-heading"> News </h1>
		</div>
    </div>
    <div class="row">
		<!-- First News section Card -->
      <div class="col-md-6 col-sm-6 col-xs-12">
          <div class="widget-help-text"><?php print t('News section card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-news-section-1']['widget_name'].$widget_data['itg-news-section-1']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-news-section-1']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-news-section-1']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-news-section-1"><?php print $widget_data['itg-news-section-1']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-section-1']['block_title']; ?>" name="itg-news-section-1" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-news-section-1">
                      <?php
                        if (isset($widget_data['itg-news-section-1']['widget'])) {
                          print $widget_data['itg-news-section-1']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('News section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
		<!-- Second News section Card-->
        <div class="col-md-6 col-sm-6 col-xs-12">
          <div class="widget-help-text"><?php print t('News section card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-news-section-2']['widget_name'].$widget_data['itg-news-section-2']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-news-section-2']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-news-section-2']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-news-section-2"><?php print $widget_data['itg-news-section-2']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-section-2']['block_title']; ?>" name="itg-news-section-2" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-news-section-2">
                      <?php
                        if (isset($widget_data['itg-news-section-2']['widget'])) {
                          print $widget_data['itg-news-section-2']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('News section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>
        </div>
        </div>
        
        <div class="row">
        <!-- Third News section Card--> 
        <div class="col-md-6 col-sm-6 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('News section card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-news-section-3']['widget_name'].$widget_data['itg-news-section-3']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-news-section-3']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-news-section-3']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-news-section-3"><?php print $widget_data['itg-news-section-3']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-section-3']['block_title']; ?>" name="itg-news-section-3" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-news-section-3">
                      <?php
                        if (isset($widget_data['itg-news-section-3']['widget'])) {
                          print $widget_data['itg-news-section-3']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('News section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
        <!-- Fourth News section Card-->        
        <div class="col-md-6 col-sm-6 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('News section card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-news-section-4']['widget_name'].$widget_data['itg-news-section-4']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-news-section-4']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-news-section-4']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-news-section-4"><?php print $widget_data['itg-news-section-4']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-section-4']['block_title']; ?>" name="itg-news-section-4" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-news-section-4">
                      <?php
                        if (isset($widget_data['itg-news-section-4']['widget'])) {
                          print $widget_data['itg-news-section-4']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('News section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
        </div>
        <div class="row">
        <!-- Fifth News section Card-->        
        <div class="col-md-6 col-sm-6 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('News section card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-news-section-5']['widget_name'].$widget_data['itg-news-section-5']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-news-section-5']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-news-section-5']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-news-section-5"><?php print $widget_data['itg-news-section-5']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-section-5']['block_title']; ?>" name="itg-news-section-5" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-news-section-5">
                      <?php
                        if (isset($widget_data['itg-news-section-5']['widget'])) {
                          print $widget_data['itg-news-section-5']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('News section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
        <!-- Sixth News section Card-->        
        <div class="col-md-6 col-sm-6 col-xs-12 mt-50">
          <div class="widget-help-text"><?php print t('News section card'); ?></div>
            <div class="itg-widget">
              <div class="droppable <?php print $gray_bg_layout; ?>">
               <div class="widget-wrapper <?php print $widget_data['itg-news-section-6']['widget_name'].$widget_data['itg-news-section-6']['widget_display_name']; ?>">
                 <?php if (($theme != 'itgadmin' || isset($preview)) && !empty($widget_data['itg-news-section-6']['block_title'])) { ?>
                     <span class="widget-title"><?php print $widget_data['itg-news-section-6']['block_title']; ?></span>
                  <?php } ?>
                     <!-- for admin  -->
                  <?php if ($theme == 'itgadmin'  && !isset($preview)) { ?>
                    <div class="widget-settings">
                      <div class="widget-title-wrapper">
                        <span class="widget-title" data-id="itg-news-section-6"><?php print $widget_data['itg-news-section-6']['block_title']; ?></span>
                        <input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-section-6']['block_title']; ?>" name="itg-news-section-6" class="block_title_id" placeholder="Enter Title" />
                      </div>
                      <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
                    </div>
                   <?php } ?>  
                  
                    <div class="data-holder" id="itg-news-section-6">
                      <?php
                        if (isset($widget_data['itg-news-section-6']['widget'])) {
                          print $widget_data['itg-news-section-6']['widget']; 
                        } else{
                          print '<div class="widget-placeholder"><span>'.t('News section card').'</span></div>';
                        } 
                      ?>
                    </div>
                  </div>             
                </div>               
            </div>  
        </div>
        </div>
        <!-- News Section card Ends -->
        <!-- Photogallery Section -->
        <div class="news-photo-section">
        <h3><span>Latest Photo Galleries</span></h3>
        <ul class="photo-list">
		<?php
		    $photo_sectionid = variable_get('tid_photogallery', 1208521);
			$gallery_items = itg_common_get_content_by_section($photo_sectionid, 'photogallery');
			foreach($gallery_items as $item_key => $item_val){
				if ((!empty($item_val['uri']) && isset($item_val['uri']))) {
					$image = theme('image_style',array('path' => $item_val['uri'], 'style_name' => 'video_landing_page_170_x_127'));
				}
				else{
					$image = '<img src = "'.$base_url.'/'. drupal_get_path('theme', 'itg').'/images/itg_image170x127.jpg">';
				}
				?>
				<li class="col-md-3">
					<div class="tile">
						<figure>
						<?php print l($image, 'node/'.$item_val['nid'], array('html' => TRUE)); ?>
						<figcaption><i class="fa fa-camera" aria-hidden="true"></i><?php print itg_common_count_images_in_photogallery($item_val['nid']); ?> images</figcaption>
						</figure>
						<span class="posted-on"><?php print format_date($item_val['created'], 'itg_day_date'); ?></span>
						<p title="<?php print $item_val['title'];?>">
						<?php print l($item_val['title'], 'node/'.$item_val['nid']); ?>
						</p>
					</div>
				</li>
			<?php }			
		?>
		</ul>
		</div>
		<!-- Videogallery section -->
		<div class="news-photo-section">
		<h3><span>Latest Video Galleries</span></h3>
        <ul class="photo-list">
		<?php
		    $video_sectionid = variable_get('tid_videos', 1206552);
			$gallery_items = itg_common_get_content_by_section($video_sectionid, 'videogallery');
			foreach($gallery_items as $item_key => $item_val){
				if ((!empty($item_val['uri']) && isset($item_val['uri']))) {
					$image = theme('image_style',array('path' => $item_val['uri'], 'style_name' => 'video_landing_page_170_x_127'));
				}
				else{
					$image = '<img src = "'.$base_url.'/'. drupal_get_path('theme', 'itg').'/images/itg_image170x127.jpg">';
				}				
				?>
				<li class="col-md-3">
					<div class="tile">
						<figure>
						<?php print l($image, 'node/'.$item_val['nid'], array('html' => TRUE)); ?>
						<figcaption><i class="fa fa-play-circle"></i> <?php print $item_val['field_video_duration_value']; ?></figcaption>
						</figure>
						<span class="posted-on"><?php print format_date($item_val['created'], 'itg_day_date'); ?></span>
						<p title="<?php print $item_val['title'];?>">
						<?php print l($item_val['title'], 'node/'.$item_val['nid']); ?>
						</p>
					</div>
				</li>
			<?php }			
		?>
		</ul>
		</div>
		<!-- Static content -->
        <div class="clear"></div><div class="news_content"><p>India Today News breaks the most important stories in and from India and abroad in six sections - India News, Business News, Cinema News, Sports News, World News and Lifestyle News. India News keeps tab of every development in all parts of India. Business News has the latest business updates from India and abroad. Cinema News tracks the latest from Bollywood, Hollywood and the South film industries and TV channels. Sports News has all the sports from India and abroad with a special focus on cricket. Lifestyle News presents developments that impact one's lifestyle. World News makes sense of news across the world and its impact on India</p></div>
    </div>
    <!-- Left 8 Block section -->
    <!-- Right 4 Block section -->
    <div class="col-md-4 col-sm-4 col-xs-12">
		<!-- Right Side Ad -->
		<div class="itg-widget">
			<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
				<div class="widget-help-text"><?php print t('Non Draggable'); ?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
			<?php } ?>
			<div class="itg-widget-inner">
				<div class="ad-widget">
					<div class="sidebar-ad droppable">
						<?php
							$block = block_load('itg_ads', ADS_RHS1);
							$render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
							print render($render_array);
						?>
					</div>
				</div>              
			</div>              
		</div>		
		<!-- Right Side may we suggest -->
		<div class="itg-widget">
			<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
			  <div class="widget-help-text"><?php print t('Template widgets');?> ( <strong><?php print t('May We Suggest'); ?></strong> )</div>
			<?php } ?>
			<div class="itg-widget-inner">
			  <div class="droppable <?php print $gray_bg_layout; ?>">
				<div class="widget-wrapper <?php print $widget_data['itg-news-rhs-mws']['widget_name']; ?>">
				  <!-- for admin  -->
				  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
					<div class="widget-settings">
					  <div class="widget-title-wrapper">
						<span class="widget-title" data-id="itg-news-rhs-mws"><?php print $widget_data['itg-news-rhs-mws']['block_title']; ?></span>
						<input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-rhs-mws']['block_title']; ?>" name="itg-news-rhs-mws" class="block_title_id" placeholder="Enter Title" />
					  </div>
					  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
					</div>
				  <?php } ?>  

				  <div class="data-holder" id="itg-news-rhs-mws">
					<?php
					if (isset($widget_data['itg-news-rhs-mws']['widget'])) {
					  print $widget_data['itg-news-rhs-mws']['widget'];
					} else {
					  print '<div class="widget-placeholder"><span>'.t('May we suggest').'</span></div>';
					}
					?>
				  </div>
				</div>             
			  </div>               
			</div>               
		 </div>
		<!-- Right Side Tabola ad -->
		<!-- Right side second ad -->
		<div class="itg-widget">
			<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
				<div class="widget-help-text"><?php print t('Non Draggable'); ?> ( <strong><?php print t('Tabola ad widget'); ?></strong> )</div>
			<?php } ?>
		    <?php
				$block = module_invoke('itg_front_end_common', 'block_view', 'may_be_recommend_block');
				print render($block['content']);
		    ?>           
		</div>		
		<!-- Right Side watch right now -->
		<div class="itg-widget">
			<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
			  <div class="widget-help-text"><?php print t('Template widgets'); ?> ( <strong><?php print t('Watch Right Now'); ?></strong> )</div>
			<?php } ?>
			<div class="itg-widget-inner">
			  <div class="droppable <?php print $gray_bg_layout; ?>">
				<div class="widget-wrapper <?php print $widget_data['itg-news-rhs-wrn']['widget_name']; ?>">
				  <!-- for admin  -->
				  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
					<div class="widget-settings">
					  <div class="widget-title-wrapper">
						<span class="widget-title" data-id="itg-news-rhs-wrn"><?php print $widget_data['itg-news-rhs-wrn']['block_title']; ?></span>
						<input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-rhs-wrn']['block_title']; ?>" name="itg-news-rhs-wrn" class="block_title_id" placeholder="Enter Title" />
					  </div>
					  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
					</div>
				  <?php } ?>  

				  <div class="data-holder" id="itg-news-rhs-wrn">
					<?php
					if (isset($widget_data['itg-news-rhs-wrn']['widget'])) {
					  print $widget_data['itg-news-rhs-wrn']['widget'];
					} else {
					  print '<div class="widget-placeholder"><span>'.t('Watch right now').'</span></div>';
					}
					?>
				  </div>
				</div>             
			  </div>               
			</div>               
		 </div>
		<!-- Right side second ad -->
		<div class="itg-widget">
			<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
			  <div class="widget-help-text"><?php print t('Non Draggable');?> ( <strong><?php print t('Ad widget'); ?></strong> )</div>
			<?php } ?>
			<div class="itg-widget-inner">
			  <div class="ad-widget">
				<div class="sidebar-ad droppable">
				  <?php
				  $block = block_load('itg_ads', ADS_RHS2);
				  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
				  print render($render_array);
				  ?>
				</div>
			  </div>              
			</div>              
		</div>
		<!-- Right side Top takes -->
		<div class="itg-widget">
			<?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
			  <div class="widget-help-text"><?php print t('Template widgets'); ?> ( <strong><?php print t('Top Takes'); ?></strong> )</div>
			<?php } ?>
			<div class="itg-widget-inner">
			  <div class="droppable <?php print $gray_bg_layout; ?>">
				<div class="widget-wrapper <?php print $widget_data['itg-news-rhs-top-takes']['widget_name']; ?>">
				  <!-- for admin  -->
				  <?php if ($theme == 'itgadmin' && !isset($preview)) { ?>
					<div class="widget-settings">
					  <div class="widget-title-wrapper">
						<span class="widget-title" data-id="itg-news-rhs-top-takes"><?php print $widget_data['itg-news-rhs-top-takes']['block_title']; ?></span>
						<input type="text" maxlength="255" size="30" value="<?php print $widget_data['itg-news-rhs-top-takes']['block_title']; ?>" name="itg-news-rhs-top-takes" class="block_title_id" placeholder="Enter Title" />
					  </div>
					  <span class="widget-trigger"><i class="fa fa-pencil" aria-hidden="true"></i></span>
					</div>
				  <?php } ?>  

				  <div class="data-holder" id="itg-news-rhs-top-takes">
					<?php
					if (isset($widget_data['itg-news-rhs-top-takes']['widget'])) {
					  print $widget_data['itg-news-rhs-top-takes']['widget'];
					} else {
					  print '<div class="widget-placeholder"><span>'.t('Top takes').'</span></div>';
					}
					?>
				  </div>
				</div>             
			  </div>               
			</div>               
		 </div>
		
	</div>
    <!-- Right 4 Block section -->
    
    </div>
  <?php } ?>
  
  <!--End of Common section-->
</div>

<!--------------------------------Code for Front tpl---------------------------------------->
        <?php if ($theme != 'itgadmin') {?>
        
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

      <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
        </aside>
      <?php endif; ?>
    </main>


    <?php print render($page['footer']); ?>


  </div>

  <?php print render($page['bottom']); ?>

<?php } ?>
<?php if ($theme == 'itgadmin') {?>
<div class="itg-ajax-loader">
  <img src="<?php  echo base_path().drupal_get_path('theme', $theme);?>/images/loader.svg" alt=""/>
</div>
<?php } 
if($theme != 'itgadmin')
{
    drupal_add_js("jQuery(document).ready(function() {
       jQuery('.add-more-block').on('click', function() {
                jQuery(this).hide();
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').slideDown( 1000);
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.removes-more-block').show();
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.add-more-block').show();
                 if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').next('.itg-common-section').is(':visible')) {
                  jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').find('.add-more-block').hide();
                }
            });
            jQuery('.add-more-block').each(function() {

                if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').is(':visible')) {
                    jQuery(this).hide();
                }
                if(jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').html() ==null)
                {
                    jQuery(this).remove();
                }
            });
             jQuery('.removes-more-block').on('click', function() {
                jQuery(this).hide();
                 jQuery(this).parent('.itg-common-section').hide();
                jQuery(this).parent('.itg-common-section').prev('.itg-common-section').find('.add-more-block').show();
            });
      
    });", array('type' => 'inline', 'scope' => 'footer'));
}

?>
