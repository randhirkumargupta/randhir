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
   foreach ($cursor as $document) {
      $output .=  $document["time"] . "\n";
      $output .=  $document["day"] . "\n";
      $output .=  $document["program"] . "\n";
      //echo $document["upload date"] . "\n";
      $output .=  "<br/>";
   }
   return $output;
}
?>