<?php

/**
 * @file
 * Theme implementation for Magazine Calendar.
 * 
 */
$count = 1;
foreach ($data as $year) {
  if ($count % 24 == 1) {
    $output .= "<li>";
  }
  $output .= '<span>' . l($year, 'calendar/0/' . $year . '/magazine.html') . '</span>';
  if ($count % 24 == 0) {
    $output .= "</li>";
  }
  $count++;
}
?>
<?php print '<ul>' . $output . '</ul>'; ?>