<?php
/**
 * @file
 * Sign and win page
 * 
 */
$nid = itg_event_backend_get_event_node();
?>

<div class="sign-and-win-title">SIGN & WIN</div>
<div class="sign-win-thankyou-text"><h2>Thank you for visiting the page.</h2></div>
<div class="sign-and-win-contest">SIGN AND WIN CONTEST IS CLOSED NOW.</div>
<div id="vuukle_div"></div>
<?php 
echo itg_event_backend_vukkul_content($nid);
?>
