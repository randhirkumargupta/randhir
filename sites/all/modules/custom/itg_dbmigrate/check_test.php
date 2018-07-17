<?php

folder_move();

function read_folder_xml() {
  $path_xml = 'sites/default/files/migrate/xml_file/migrate_xml/xml_for_migrate/';
  $files = scandir($path_xml);
  if($files[0] == '.'){
  unset($files[0]);
  }
 if($files[1] == '..'){
 unset($files[1]);
 }
 $result =  array_values($files);
 return $result[0];
}


function folder_move() {
  $file_path = 'sites/default/files';
    $xml_folder = $file_path . '/' . 'migrate/xml_file/migrate_xml/xml_for_migrate/'.read_folder_xml();
    recurse_copy($xml_folder,'sites/default/files/migrate_xml/xml_for_migrate/xml_complete/'.read_folder_xml());
//    if (!empty($file_name)) {
//    if () {
//      //if (exec("cp -r".$xml_folder."/migrate_xml/xml_for_migrate/xml_complete/".$this->city_consvalue)) {
//        unlink($xml_folder);
//      }
//    }
  
}


  function recurse_copy($src,$dst) { 
        $dir = opendir($src); 
        @mkdir($dst); 
        while(false !== ( $file = readdir($dir)) ) { 
            if (( $file != '.' ) && ( $file != '..' )) { 
                if ( is_dir($src . '/' . $file) ) { 
                    recurse_copy($src . '/' . $file,$dst . '/' . $file); 
                } 
                else { 
                    copy($src . '/' . $file,$dst . '/' . $file); 
                } 
            } 
        } 
        closedir($dir); 
    } 

    
    
    
  
  
  /**
 * Implement function for crate directory and copy all xmls after complete migration.
 * @param type $src
 * @param type $dst
 * @return boolean
 */
function copy_source_dest_xml_folder($src, $dst) {
  $dir = opendir($src);
  @mkdir($dst, 0777);
  while (false !== ( $file = readdir($dir))) {
    if (( $file != '.' ) && ( $file != '..' )) {
      if (is_dir($src . '/' . $file)) {
        recurse_copy($src . '/' . $file, $dst . '/' . $file);
      }
      else {
        copy($src . '/' . $file, $dst . '/' . $file);
      }
    }
  }
  closedir($dir);
  return true;
}

/**
 * Delete Directory after complete Migration.
 * @param type $dir
 * @return type
 */
 function delete_xml_folder_after_move($dir)
    { 
        $files = array_diff(scandir($dir), array('.', '..')); 

        foreach ($files as $file) { 
            (is_dir("$dir/$file")) ? delTree("$dir/$file") : unlink("$dir/$file"); 
        }

        return rmdir($dir); 
    } 

  
  
?>
