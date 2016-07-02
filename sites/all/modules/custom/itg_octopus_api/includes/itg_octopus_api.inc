<?php
  
/**
 * Implement itg_pti_content
 */
function itg_octopus_api_rundown() {
 $file_path = drupal_realpath('public://');
 ///var/www/itgcms/sites/default/files
  global $base_url, $user;
  $direc = getDirContents($file_path.'/octopus/rundown/');
  foreach ($direc as $xm_file) {
    $xml_file_path = $xm_file;
    $xml_filename = basename($xml_file_path);
    $rundown_xml = simplexml_load_file($xml_file_path, 'SimpleXMLElement', LIBXML_NOCDATA);
    $rundownId = (string)$rundown_xml->rundown->rundownType;
    $rundownTitle = (string)$rundown_xml->rundown->rundownType;
    $rundownStart = (string)$rundown_xml->rundown->rundownType;
    $exported = $rundown_xml->exported;
    $exportedBy = $rundown_xml->exportedBy;
    //p($rundown_xml);
  }
    
}
