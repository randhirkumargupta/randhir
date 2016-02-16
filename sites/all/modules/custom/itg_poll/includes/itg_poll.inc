<?php

/*
 * Inc file contains the functions
 */

/**
 * Poll Post callback
 */
function itg_poll_result_details() {  
    global $user;
    $nId = filter_input(INPUT_POST, 'nid');
    $pole_answer = filter_input(INPUT_POST, 'pole_answer');
    
    //$nId =  ($_POST['nid']) ? $_POST['nid'] : '';
   // $pole_answer = ($_POST['pole_answer']) ? $_POST['pole_answer'] : '';
    if(empty($nId) && empty($pole_answer)) {
        return 'sorry';
        exit;
    } 
       /**
       * Insert poll information in the database.
       */
        $created = date('Y-m-d H:i:s');
        db_insert('itg_polls')->fields(array(
         'nId' => $nId,
         'ansId' => $pole_answer,
         'uId' => $user->uid, 
         'created' => $created)) ->execute();
        
        // setcookie(name, value, expire, path, domain); 
        $expire = time() + 60 * 60 * 24 * 30; // expires in one month
        $value = 'yes_'.$nId;
        setcookie('visitedPoll',$value,$expire,'/');
  
  echo 'Thanks, Your Poll is valuable for me';
}


function get_poll_result(){
    
    //$rbrochure = db_query("SELECT n.nid AS nid,l.field_brochure_fid AS fid FROM node AS n LEFT JOIN field_data_field_brochure AS l ON n.nid = l.entity_id AND (l.entity_type = 'node' AND l.deleted = '0') WHERE ((n.status = '1') AND n.type IN  ('event') ".$where.") ORDER BY n.created DESC")->fetchObject();
}

