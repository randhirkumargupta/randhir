<?php

/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
$menus = itg_widget_anchor_landing_menu(arg(1));
foreach ($menus as $key => $value):
  $output .= '<li value="' . $key . '"><a href="javascript:void(0)" class="NULL">' . $value . '</a></li>';
endforeach;

print '<ul class="video_landing_menu">' . $output . '</ul>';
?>