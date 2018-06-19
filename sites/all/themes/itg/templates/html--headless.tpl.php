<?php
$node_obj = node_load(arg(1));
pr(arg());
pr($node_obj);
print str_replace("&#13;", "", $node_obj->body[LANGUAGE_NONE][0]['value']);
