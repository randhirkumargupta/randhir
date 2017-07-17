<?php
function itg_rapid_api_resource() {
  
    $api = array(
       /**
        * custom resource for sprit1
        */
        
         // hamburger_menu custom resource declaration.....
	'hamburger_menu' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves hamburger_menu schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_hamburger_menu',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        
        // horizontal_menu custom resource declaration.....
	'horizontal_menu' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves horizontal_menu schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_horizontal_menu',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
         // config_update_status custom resource declaration.....
	'config_update_status' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves config_update_status schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_config_update_status',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        // master_config custom resource declaration.....
	'master_config' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves master_config schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_master_config',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
         // server_error_master custom resource declaration.....
	'server_error_master' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves server_error_master schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_server_error_master',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        // photolist custom resource declaration.....
	'photolist' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves photolist schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_photolist',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(            
                        array(
                            'name' => 'id',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 0), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
                        array(
                            'name' => 'cpageno',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 1), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 2), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
      	),
      	
    	),
      	),
	),
        
        // photodetail custom resource declaration.....
	'photodetail' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves photodetail schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_photodetail',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
                   'name' => 'id',
                    'type' => 'string',
                    'description' => 'Function to perform',
                     //'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
                    'optional' => TRUE,
                    'default' => '*',
                    ),         
                array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 1), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        // videolist custom resource declaration.....
	'videolist' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves videolist schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_videolist',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        // programlist custom resource declaration.....
	'programlist' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves programlist schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_programlist',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        // newslist custom resource declaration.....
	'newslist' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves newslist schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_newslist',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
        // datanotexist_api custom resource declaration.....
	'datanotexist_api' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves datanotexist_api schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_datanotexist_api',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
        	array(
          	'name' => 'token',
          	'type' => 'string',
          	'description' => 'Function to perform',
          	//'source' => array('param' => 'token'),
                    'source' => array('path' => 0), 
          	'optional' => TRUE,
          	'default' => '*',
        	),
      	),
      	
    	),
      	),
	),
        
  );

  return $api;
}
/**
 * resource callback function for sprit1
 */


/**
 * [itg_rapid_api_datanotexist_api] definition.
 * Returns the information about a itg_rapid_api_datanotexist_api.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */
//return services_error(t('Node type cannot be changed'), 406);
function itg_rapid_api_datanotexist_api($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/datanotexist_api.json';


       //$jsondata = file_get_contents($json_string);
       $jsondata = variable_get('datanotexist_api_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_newslist] definition.
 * Returns the information about a itg_rapid_api_newslist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_newslist($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/newslist.json';


       $jsondata = file_get_contents($json_string);
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_programlist] definition.
 * Returns the information about a itg_rapid_api_programlist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_programlist($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/programlist.json';


       $jsondata = file_get_contents($json_string);
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_videolist] definition.
 * Returns the information about a itg_rapid_api_videolist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_videolist($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/videolist.json';


       $jsondata = file_get_contents($json_string);
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_photodetail] definition.
 * Returns the information about a itg_rapid_api_photodetail.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_photodetail($id, $token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         //valid id 
        if(!is_numeric($id)){
          $id = 0;
        }
        
       // call function for return data..
       $jsondata = photoDetailPageRerourceValue($id);
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}


/**
 * [itg_rapid_api_photolist] definition.
 * Returns the information about a itg_rapid_api_photolist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_photolist($id, $cpageno, $token) {
    
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       //valid tid & pageno
        if(!is_numeric($id)){
          $id = 0;
        }
        if(!is_numeric($cpageno)){
          $cpageno = 0;
        }
       // call function from return data..
       $jsondata = photocategoryPageRerourceValue($id, $cpageno);
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}

/**
 * [itg_rapid_api_server_error_master] definition.
 * Returns the information about a itg_rapid_api_server_error_master.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_server_error_master($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/server_error_master.json';


       //$jsondata = file_get_contents($json_string);
       $jsondata = variable_get('server_error_master_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_master_config] definition.
 * Returns the information about a config_update_status.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_master_config($token) {
$get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/master_config.json';


       //$jsondata = file_get_contents($json_string);
       $jsondata = variable_get('master_config_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_config_update_status] definition.
 * Returns the information about a config_update_status.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_config_update_status($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
      
       $jsondata = variable_get('config_update_status_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_hamburger_menu] definition.
 * Returns the information about a hamburger_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_hamburger_menu($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/hamburger_menu.json';


       //$jsondata = file_get_contents($json_string);
       $jsondata = variable_get('hamburger_menu_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_horizontal_menu] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_horizontal_menu($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
         $json_string = 'http://localhost/decode/sprint1/horizontal_menu.json';


       //$jsondata = file_get_contents($json_string);
       $jsondata = variable_get('horizontal_menu_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * function for check valid resource & return type
 * @return $type
 */
function checkValidResource(){
  
   $error_flag = "";
  $flag_code = 0;
  //declare valid resource 
  $valid_resurce = array('hamburger_menu');
  // declare valid operation
  $valid_operation= array('retrieve');
  // declare valid return type
  $valid_return_type= array('json', 'xml');
  //check validity
  $resource = arg(1);  
  $resurce_arg = explode('.',arg(2));
  $resurce_opt = $resurce_arg[0];
  $resurce_ext = $resurce_arg[1]; 
  //validate resource
  if (!in_array($resource, $valid_resurce))
  {
    $error_flag .="\nInvalid resource";
    $flag_code = 1;
  }
  //validate operation
  if (!in_array($resurce_opt, $valid_operation))
  {
    $error_flag .="\nInvalid operation";
    $flag_code = 1;
  }
  //validate return type
  if (!in_array($resurce_ext, $valid_return_type))
  {
    $error_flag .="\nInvalid return type";
    $flag_code = 1;
  }
  
  // die if $flag_code is 1
  if($flag_code == 1){
      print $error_flag; die();
  }
  return;
}


