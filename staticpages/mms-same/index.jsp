<?php
if(isset($_GET[key($_GET)])){
	$include = 'index.jsp?'.key($_GET).'='.$_GET[key($_GET)];
	include($include);
}else{
	include('index.html');
}

?>
