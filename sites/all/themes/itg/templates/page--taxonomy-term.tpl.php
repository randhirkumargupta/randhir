<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */

?>
<?php if($_SERVER['HTTP_HOST'] == PARENT_SSO) { ?>
<script>
window.addEventListener("message", function(ev) {
    if (ev.data.message === "requestResult") {
        // ev.source is the opener
        ev.source.postMessage({ message: "deliverResult", result: true }, "*");
    }   
});

</script>
<?php } ?> 
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
                
                <?php print render($page['header']); ?>
                <?php 
                  $arg = arg(); 
                  $term = taxonomy_term_load($arg[2]);
                ?>                
            </section>
        </header>
    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>
    <?php 
      $cls = 'col-md-12';
      if ($sidebar_first || $sidebar_second):
        $cls = 'col-md-8';
    endif; ?>
  <?php print render($page['top']); ?>
  <?php print render($page['my_cart']); ?>
  
  <main id="main" class="container pos-rel">
    <?php
      if(!empty($node->type) && ($node->type != "videogallery" || $node->type != "photogallery")) {
        $page['vertical_menu'] = array();
      }
      print render($page['vertical_menu']);
    ?>
    <!-- Breaking news band -->    
    <?php if (!empty($page['breaking_news'])): ?>
    <div class="row">
        <div class="col-md-12">
          <?php print render($page['breaking_news']); ?>
        </div>      
    </div>    
    <?php endif; ?>
    <div class="row">
    <section id="content" class="<?php echo $cls;?>" role="main">
      <?php print render($page['highlighted']); ?>
      <?php if(arg(0)!= 'user'): print $breadcrumb; ?>
      <?php endif; ?>
     
      <a id="main-content"></a>
      <!-- Sponsored Category changes. Show category icon or Impact text. --> 
	<?php
	  if((_is_sponsored_category($arg[2])) && (!empty($term->field_show_fields))){
		  $show_field_val = $term->field_show_fields[LANGUAGE_NONE][0]['value'];
		  if($show_field_val == 'category_icon'):
		    print "<div class='sponsor-header'><span class='sponsor-powerby'>Powered by</span><span class='sponsor-logo'>".theme('image_style', array('path' => $term->field_sponser_logo[LANGUAGE_NONE][0]['uri'], 'style_name' => 'widget_very_small'))."</span></div>";
		  else:
		    print "<div class='sponsor-header'><span class='sponsor-impact-text'>".$term->field_impact_text[LANGUAGE_NONE][0]['value']."</span></div>";
		  endif;
	    }
	  ?>
      <!-- Page title for specific page -->      
      <?php
          $flag = '';
          switch ($arg[0]) {
              case 'product':
              case 'cart':
              case 'order':
              case 'order-summary':
                  $flag = TRUE;
                  break;
          }
      ?>
      <?php print render($title_prefix); ?>
      <?php if ($title && $flag): ?>
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
        
      <?php
        global $base_url;
        $taxonomy_url = $base_url."/taxonomy/term/$arg[2]";
        //show heading and list/grid view if category is not sponsored.
        if(!_is_sponsored_category($arg[2])){          
          $header_content = '<h1 class="category-heading">' . $term->name . '</h1>';
          $query = drupal_get_query_parameters();
          if ($query['view_type'] == 'list')  {
          $header_content .= '<div class="list-grid">' .l('<i class="fa fa-list" aria-hidden="true"></i>'.t(' List'),$taxonomy_url, array('attributes' => array('class' => 'active'),'html'=>true,'query'=>array('view_type'=>'list'))).'<span class="pipline"> | </span>'.l('<i class="fa fa-th" aria-hidden="true"></i>'.t(' Grid'),$taxonomy_url ,array('html'=>true,'query'=>array('view_type'=>'grid'))).'</div>';
          } elseif ($query['view_type'] == 'grid')   {
          $header_content .= '<div class="list-grid">' .l('<i class="fa fa-list" aria-hidden="true"></i>'.t(' List'),$taxonomy_url, array('html'=>true,'query'=>array('view_type'=>'list'))).'<span class="pipline"> | </span>'.l('<i class="fa fa-th" aria-hidden="true"></i>'.t(' Grid'),$taxonomy_url ,array('attributes' => array('class' => 'active'),'html'=>true,'query'=>array('view_type'=>'grid'))).'</div>';    
          } else {
          $header_content .= '<div class="list-grid">' .l('<i class="fa fa-list" aria-hidden="true"></i>'.t(' List'),$taxonomy_url, array('attributes' => array('class' => 'active'),'html'=>true,'query'=>array('view_type'=>'list'))).'<span class="pipline"> | </span>'.l('<i class="fa fa-th" aria-hidden="true"></i>'.t(' Grid'),$taxonomy_url ,array('html'=>true,'query'=>array('view_type'=>'grid'))).'</div>';
          }
          print $header_content;
        }        
        
      if(!isset($_GET['view_type']) || (isset($_GET['view_type']) && $_GET['view_type'] == 'list')) {
        // show list view.
          print views_embed_view('category_wise_content_list', 'section_wise_content_listing' , arg(2));
      }
      else {
          // show grid view.
          print views_embed_view('category_wise_content_list', 'grid_view' , arg(2));
      }
    ?>
      
      <?php print render($page['content_bottom']); ?>
      <?php print render($page['personalization']); ?>
      <?php print $feed_icons; ?>
    </section>
    <?php if (false): ?>
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
          )); ?>
        </nav>
      <?php endif; ?>

      <?php print render($page['navigation']); ?>

    </div>
    <?php endif; ?>
      
    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars col-md-4">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>
    </div>
  </main>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
<?php global $base_url; ?>
