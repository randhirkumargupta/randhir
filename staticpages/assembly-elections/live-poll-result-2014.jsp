<?php
$include = 'live-poll-result-2014.jsp?'.key($_GET).'='.$_GET[key($_GET)];
//var_dump($include); exit;
include($include);
?>
