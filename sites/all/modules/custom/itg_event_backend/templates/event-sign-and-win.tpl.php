<?php
/**
 * @file
 * Sign and win page
 * 
 */
$nid = itg_event_backend_get_event_node();
?>

<h2><?php echo t('SIGN & WIN'); ?></h2>
<h1><?php echo t('Thank you for visiting the page.'); ?></h1>
<div class="sign-and-win-contest"><i class="fa fa-frown-o" aria-hidden="true"></i> <?php echo t('SIGN AND WIN CONTEST IS CLOSED NOW.')?> <i class="fa fa-frown-o" aria-hidden="true"></i></div>
<div id="vuukle_div"></div>
<?php 
echo itg_event_backend_vukkul_content($nid);
?>
