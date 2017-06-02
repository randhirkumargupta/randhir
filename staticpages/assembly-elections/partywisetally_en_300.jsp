<?php
	$include = 'partywisetally_en_300.jsp?'.key($_GET).'='.$_GET[key($_GET)];
	//var_dump($include); exit;
	include($include);
?>