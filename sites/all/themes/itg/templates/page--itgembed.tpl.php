<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<?php
$amp_class = '';
print_r($_REQUEST);die;
print_r(arg());die;
$is_amp = amp_is_amp_request();
if($is_amp){
  $amp_class = 'amp-video-embed';
}
?>
<div id="page">

  <main id="main" class="<?php print $amp_class; ?>">
    
    <section id="content" class="container" role="main">
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
      
    </section>

    
 </main>
    
    </div>

    
