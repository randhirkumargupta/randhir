<?php
/**
 * Inc file contains the tid config array
 */

 define('FEED_NOTIFICATION_PATH', '/sites/default/files/xml_it/notifications');

function tidConfig(){
    $tid_config = array();
    // decalation of photo section array

    /**
     * india - 1206578
     * entertainment - 1206749
     * sports - 1206550
     * world - 1206577
     * lifestyle - 1206567
     * movies - 1206533
     * cricket - 1206676
     * elections - 1206719
     *
     */

    //$photo_sec_tid = array(1206578, 1206749, 1206550, 1206577, 1206567, 1206533, 1206676, 1206719);
     $photo_sec_tid = explode(',',variable_get('photo_sec_tid'));
    //for my local
    //$photo_sec_tid = array(844517, 844529, 844583, 286531, 844520);
    // decalation of video section array

    /**
     * india - 1206578
     * world - 1206577
     * so sorry - 1207580
     * entertainment - 1206749
     * movies - 1206533
     * lifestyle - 1206567
     * sports - 1206550
     */

    //$video_sec_tid = array(1206578, 1206577, 1207580, 1206749, 1206533, 1206567, 1206550);
    $video_sec_tid = explode(',',variable_get('video_sec_tid'));
    //for my local
    //$video_sec_tid = array(844517, 844693, 844529, 286531, 844520);


    // decalation of program section array

    /**
     * Sports Today - 1206960
     * GADGETS & GIZMOS - 1207605
     * To The Point - 1207722
     * Nothing But The Truth - 1207726
     * Up South - 1207728
     * First Up - 1207755
     * News Today - 1207797
     * Newsroom - 1207827
     * Auto Today - 1207972
     */

    $program_sec_tid = explode(',',variable_get('photo_sec_tid'));
    //$program_sec_tid = array(1206960, 1207605, 1207722, 1207726, 1207728, 1207755, 1207797, 1207827, 1207972);
     //for my local
    //$program_sec_tid = array(844517, 844693, 844529, 286531, 844520);

    // decalation of left main array

    /**
     * India - 1206578
     * Sports - 1206550
     * World - 1206577
     * FYI - 1206795
     * Movies - 1206533
     * Lifestyle - 1206567
     * From the Magazine - 1207414 -- separate url for this, because here list of last 20-magazine type node
     * Auto - 1206689
     * Technology - 1206688
     */

    //$left_main_tid = array(1206578, 1206550, 1206577, 1206795, 1206533, 1206567, 1206689, 1206688);
    $left_main_tid =  explode(',',variable_get('left_main_tid'));
     ////for my local
    //$left_main_tid = array(844693, 844529, 286531, 844520);


    $tid_config['photo_sec_tid'] = $photo_sec_tid;
    $tid_config['video_sec_tid'] = $video_sec_tid;
    $tid_config['program_sec_tid'] = $program_sec_tid;
    $tid_config['magazine'] = 844529;
    $tid_config['left_main_tid'] = $left_main_tid;
    return $tid_config;
}

/**
 * Function for get to redis
 */
function getRedis($key){
    
    $key_value = 0; 
    $result = array();
    $connection_str = ""; 
        
    $redis = redis_connection();
    if($redis->exists($key)){ 
          $key_value = $redis->get($key);                  
    }else{
          $key_value = 0;
    }
    
    $result['key_value'] = $key_value;
    
    return $result;
}

/**
 * Function for set into redis
 */
function setRedis($key, $value, $ttl = 300){
    
    $key_value = 0; 
    $result = array();
    $connection_str = ""; 
    $set_flag = 0;
  
    $redis = redis_connection();
    $set_flag = $redis->set($key, $value);
    $redis->expire($key, $ttl);         
    
    $result['set_flag'] = $set_flag;
    return $result;
}


/*
 * unique function to return all the redis keys
 * args - no
 * reurn - array
 */
function list_redis_key(){

      $redis = redis_connection();
      $all_redis_key = $redis->keys("*");
      return $all_redis_key;
 }

 /*
  * unique function to connect redis server
  */
 function redis_connection(){
   
   $redis = new Redis();    
        $time = 300;
        $redis_server_read = variable_get('redis_server_host');//'127.0.0.1';
        $redis_server_read_port = variable_get('redis_server_port');//6379;
        $redis_server_read_timeout = variable_get('redis_server_timeout');//30;
        $connection_str = $redis->connect($redis_server_read, $redis_server_read_port, $redis_server_read_timeout);
        
        if(!$connection_str){
            throw new Exception("Can’t connect redis");
            return;
        }else{
            return $redis;
        }
   
 }
 
 /*
  * delete redis key value
  */
 
 function redis_key_delete($key){
   
   $redis = redis_connection();
   $result = $redis->del($key);   
   
   return $result;
 }

