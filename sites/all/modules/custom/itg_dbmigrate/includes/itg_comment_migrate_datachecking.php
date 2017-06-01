<?php

$args = drush_get_arguments(); // Get the arguments.

itg_comments_migrate_step111();

/**
 * Code started for comments migration
 */
function itg_comments_migrate_step111() {
   $xml_path = 'sites/default/files/comments_data/final/comment_1.xml';
  //$xml_path = 'sites/default/files/comments_data/final/comment_2.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');
      
    echo "Start migrating comments...\n";
    $success_count = 0;
    $failed_count = 0;
    $row = '';
    $output = '';
    
    
  foreach ($xml->row as $xm) {
    
    print "#######################################\n";
    // Getting the mapped Node Id on the basis of content ID 
    
    if($xm->id == 9270464){
    $success_count++;
    pr($xm);
    }
     
     
     if($success_count==2)
       
     
       
    // print $xm->created_date.'\n';
    // print date('d-m-Y h:i:s', (int)$xm->created_date);
    // die;
    
    if($success_count==3)
      break;
    $content_nid = NULL;
    switch ($xm->content_type) {
      case 'story':

        break;
      case 'video':

        break;
      case 'photo':

        
        break;
    }

 
  
       print "#######################################\n";



  }
      
  echo "\n Total Processed:" . $success_count;
  echo "\n Total Failed:" . $failed_count;

  echo "\nMigration finished...\n";
}
