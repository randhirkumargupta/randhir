<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
$arg = arg();
$back_to_link_config = variable_get('sitename-domain');
if(!empty($back_to_link_config)) {
  $explode_back_link = explode(',', $back_to_link_config);
  foreach ($explode_back_link as $key => $value) {
    $ex_hash = explode('|', $value);
    $key = trim($ex_hash[0]);
    $sitehash[$key] = trim($ex_hash[1]);
  }
}

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
  $parse = parse_url($shr);
  $parse_host = $parse['host'];
  // back to site configuration code in case of login
  $site_name = array_search($parse_host, $sitehash);
  if (!empty($site_name)) {
    $site_name = $site_name;
  }
  else {
    $site_name = t('India Today');
  }
}
else {
  $parse = parse_url(base64_decode($arg[1]));
  $parse_host = $parse['host'];
  // back to site configuration code in case of signup/forgot-password
  $site_name = array_search($parse_host, $sitehash);
  if (!empty($site_name)) {
    $site_name = $site_name;
    $shr = base64_decode($arg[1]);
  }
  else {
    $site_name = t('India Today');
  }
}

// case for change password page
if($arg[0] == 'sso' && $arg[1] == 'change-password') {
  $parse = parse_url(base64_decode($arg[2]));
  $parse_host = $parse['host'];
  // back to site configuration code in case of signup/forgot-password
  $site_name = array_search($parse_host, $sitehash);
  if (!empty($site_name)) {
    $site_name = $site_name;
    $shr = base64_decode($arg[2]);
  }
  else {
    $site_name = t('India Today');
  }
}

// case for change password page
if($arg[0] == 'sso-user') {
  $parse = parse_url(base64_decode($arg[3]));
  $parse_host = $parse['host'];
  // back to site configuration code in case of signup/forgot-password
  $site_name = array_search($parse_host, $sitehash);
  if (!empty($site_name)) {
    $site_name = $site_name;
    $shr = base64_decode($arg[3]);
  }
  else {
    $site_name = t('India Today');
  }
}

?>
<div class="sso-header">
    <div class="container">
        <a class="back-to-itg" href="<?php print $shr; ?>" title="<?php print 'Back to the '.$site_name; ?>"><i class="fa fa-angle-left" aria-hidden="true"></i><?php print 'Back to the '.$site_name; ?></a>
        <div class="itg-logo">
            <img src="<?php print base_path() ?>sites/all/themes/itg/images/span_itg_group.jpg" alt="India Today Group" />     
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
    <?php print theme('links', array('links' => menu_navigation_links('menu-sso-footer-menu'), 'attributes' => array('class'=> array('links', 'site-menu')) ));?>
  </div>
  <p><?php print t('Copyright &copy;');?> <?php echo date("Y") ?> <?php print t('Living Media India Limited. For reprint rights: Syndications Today'); ?></p>
</div>

    
