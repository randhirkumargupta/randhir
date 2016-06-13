<?php
/*
 * Inc file contains the functions
 */

/**
 * ugc comment details callback
 */
function tv_schedule_listing() {
  $arg = arg();
  //p($arg);
  $con = new Mongo();
// Select Database
    $db = $con->csvhandling;
// Select Collection
    $people = $db->itgcms_tys;
  //select collection  
   $cond = array('day' => $arg[1]);

    $cursor = $people->find($cond);

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

function tv_schedule_searching($search_value) {
  
  $con = new Mongo();
// Select Database
    $db = $con->csvhandling;
// Select Collection
    $people = $db->itgcms_tys;
  //select collection  
   $cond = array('program' => $search_value);

    $cursor = $people->find($cond);

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