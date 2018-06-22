<?php
$node_obj = menu_get_object();
print str_replace("&#13;", "", $node_obj->body[LANGUAGE_NONE][0]['value']);
