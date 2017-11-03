<?php
/**
 * Implement itg_nifty_feed
 */
function itg_nifty_feed() {
  $direc = getcwd() . '/sites/all/modules/custom/itg_api/feeds/nifty/';
  $new_file_name = $direc . 'SensexNiftyFeed.txt';
  $response_xml_data = get_content_from_xml_loc('http://businesstoday.accordhostings.com/SensexNiftyFeed.aspx');

  if ($response_xml_data) {
    $nifty_xml = simplexml_load_string($response_xml_data);
    $final_output = '';
    foreach ($nifty_xml as $nifty_value) {
      $final_output .= $nifty_name = $nifty_value->name . ',';
      $final_output .= 'Current Value : ' . $current_value = $nifty_value->current_value . ',';
      $final_output .= 'Value Change : ' . $value_change = $nifty_value->value_change . ',';
      $final_output .= 'Percentage Change : ' . $percentage_change = $nifty_value->percentage_change . '@';
    }
    unlink($new_file_name);
    if (!file_exists($new_file_name)) {
      $file = fopen($new_file_name, "w+");
      fwrite($file, $final_output);
      fclose($file);
      chmod($file, 777);
    }
  }
  watchdog('Nifty_FEED', 'Nifty feed saved successfully');
}

