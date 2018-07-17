<?php
$include = 'askquestion.jsp?'.key($_GET).'='.$_GET[key($_GET)];
if(file_exists($include)){
include($include);
}else{
	header("Location: /specials/youthsummit/chennai/index.jsp");
}
?>
