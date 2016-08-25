<?php

/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
$menus = itg_widget_anchor_landing_menu(arg(1));
foreach ($menus as $key => $value):
  $output .= '<span value="' . $key . '"><a href="javascript:void(0)" class="NULL">' . $value . '</a></span>';
endforeach;

print '<div class="anchor-detail-menu"><div class="tab-buttons">' . $output . '</div></div>';
?>