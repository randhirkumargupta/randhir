<?php
/*
 * Inc file contains the functions
 */

/**
 * ugc comment details callback
 */
function tv_schedule_listing() {

  $con = new Mongo();
// Select Database
    $db = $con->csvhandling;
// Select Collection
    $people = $db->itgcms_ty;
  //select collection  
   $cursor = $people->find();

  $output = '';

   // iterate cursor to display title of documents
  $key = 0;
   foreach ($cursor as $document) {
      $output[$key]['time'] =  $document["time"];
      $output[$key]['day'] =  $document["day"];
      $output[$key]['program'] =  $document["program"];
      $key++;
   }
    return theme('itg_tv_schedule', array('output' => $output));


}
?>