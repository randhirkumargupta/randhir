<?php
$node_obj = menu_get_object();
print $node_obj->body[LANGUAGE_NONE][0]['value'];
