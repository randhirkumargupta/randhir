<?php
$include = 'live-poll-result.jsp?'.key($_GET).'='.$_GET[key($_GET)];
//~ var_dump($include);die;
include($include);
?>
