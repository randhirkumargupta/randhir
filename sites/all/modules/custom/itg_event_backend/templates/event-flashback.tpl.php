<?php
/**
 * @file
 * Sign and win page
 * 
 */

//Current event nid
$nid = itg_event_backend_get_event_node();
$flash_old_event = itg_event_backend_flashback($nid);
print $flash_old_event;
?>

<div style="text-align: center"><h2>Coming Soon...</h2></div>
