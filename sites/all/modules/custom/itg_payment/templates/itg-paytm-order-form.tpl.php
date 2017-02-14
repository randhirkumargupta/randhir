<?php

header("Pragma: no-cache");
header("Cache-Control: no-cache");
header("Expires: 0");
print drupal_render_children($form);
?>