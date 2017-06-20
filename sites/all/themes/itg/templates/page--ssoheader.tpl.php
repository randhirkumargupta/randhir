<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
        $returnto = $_GET['ReturnTo'];
        $explode_returnto_val = explode('/', $returnto);
        $get_first_arr = end($explode_returnto_val);
        $pre_decode_val = urldecode(urldecode(urldecode($get_first_arr)));
        $explode_decode_val = explode('&ReturnTo', $pre_decode_val);
        $end_part_string = end($explode_decode_val);
        $exp_end_part_string = explode('/', $end_part_string);
        $final_redirect = end($exp_end_part_string);
        $shr = base64_decode($final_redirect);
}
?>
<div class="sso-header">
    <div class="container">
        <a class="back-to-itg" href="<?php print $shr; ?>"><i class="fa fa-angle-left" aria-hidden="true"></i> Back to the india today</a>
        <div class="itg-logo">
            <img src="<?php print base_path() ?>sites/all/themes/itg/images/span_itg_group.jpg" alt="" />     
        </div>
    </div>
</div>

<div id="page">

  

  <main id="main">
    
    <section id="content" class="container" role="main">
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
      
    </section>

    
 </main>
    
</div>

<div class="sso-footer">
  <div class="container">
    <?php print theme('links', array('links' => menu_navigation_links('menu-itg-publications-menu-foote'), 'attributes' => array('class'=> array('links', 'site-menu')) ));?>
  </div>
  <p><?php print t('Copyright &copy;');?> <?php echo date("Y") ?> <?php print t('Living Media India Limited. For reprint rights: Syndications Today'); ?></p>
</div>

    
