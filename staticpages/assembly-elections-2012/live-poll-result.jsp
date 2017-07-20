<?php
if(!empty($_GET)){
	$include = 'live-poll-result.jsp?'.key($_GET).'='.$_GET[key($_GET)];
}else{
	$include = 'live-poll-result.jsp?state=uttarpradesh';
}
include($include);
?>
