<?php
global $base_url;
global $message;
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">

  

  <main id="main">
    <?php print $messages; ?>
    <section id="content" class="container" role="main">
      <div id="widget-ajex-loader" style="display: none">
    <img class="widget-loader" align="center" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />
</div>
      <?php print render($page['content']); ?>
      
    </section>

    
 </main>
    
    </div>

    
