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
      if(!empty($node->type) && ($node->type == "videogallery" || $node->type == "podcast" || $node->type == "photogallery")) {
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
      <!-- Page title for specific page -->
      <?php $arg = arg();?>
      <?php
          $flag = TRUE;
          $node_array = array('story', 'photogallery', 'videogallery', 'podacast', 'breaking_news', 'blog', 'survey', 'quiz', 'poll', 'mega_review_critic');
          $node_arg = array('site-search', 'blog-listing', 'anchors-list', 'sosorry', 'programmes', 'online-archive-story', 'personalization', 'itg_active_polls');
          if(isset($node->type) && in_array($node->type , $node_array)) {
            $flag = FALSE;
          }else if(isset($arg[0]) && in_array($arg[0], $node_arg)) {
            $flag = FALSE;
          }
    ?>
      <?php print render($title_prefix); ?>
      <?php if ($title && $flag): ?>
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
      <?php print render($page['content']); ?>
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
