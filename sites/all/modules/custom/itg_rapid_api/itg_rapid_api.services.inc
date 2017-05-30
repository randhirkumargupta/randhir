<?php
function itg_rapid_api_resource() {
  
    $api = array(
       /**
        * custom resource for sprit1
        */
        
        // testing custom resource declaration.....
	'testing' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves testing schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_testing',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
//        'args' => array(
//        	array(
//          'name' => 'count', 
//          'type' => 'int', 
//          'description' => t('Number of comments to load.'), 
//          'source' => array('param' => 'count'),           
//          //'source' => array('path' => 0),
//          //'source' =>'data',
//          'optional' => TRUE,
//          'default value' => 0,
//        ),
//      	),
      	
    	),
      	),
	),
        
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
        
        // sprint 2 api start
        
        // photostorydetail custom resource declaration.....
	'photostorydetail' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves photostorydetail schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_photostorydetail',
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
        
        // program_category_list custom resource declaration.....
	'program_category_list' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves program_category_list schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_program_category_list',
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
        
        // ad_config_json custom resource declaration.....
	'ad_config_json' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves ad_config_json schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_ad_config_json',
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
        
        // livetv_channellist_json custom resource declaration.....
	'livetv_channellist_json' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves livetv_channellist_json schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_livetv_channellist_json',
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
        
        // livetv_json custom resource declaration.....
	'livetv_json' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves livetv_json schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_livetv_json',
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
        
        // otherapps_ios_json custom resource declaration.....
	'otherapps_ios_json' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves otherapps_ios_json schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_otherapps_ios_json',
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
        
         // otherapps_android_json custom resource declaration.....
	'otherapps_android_json' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves otherapps_android_json schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_otherapps_android_json',
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
        
        // magazine section start
        
         // magazine_edition custom resource declaration.....
	'magazine_edition' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves magazine_edition schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_magazine_edition',
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
        
        // magazine_coverstories custom resource declaration.....
	'magazine_coverstories' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves magazine_coverstories schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_magazine_coverstories',
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
        
        // magazine_editionlist custom resource declaration.....
	'magazine_editionlist' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves magazine_editionlist schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'itg_rapid_api',
        	'name' => 'itg_rapid_api.services',
      	),
      	'callback' => 'itg_rapid_api_magazine_editionlist',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
        'args' => array(
            
                        array(
                            'name' => 'sdate',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 0), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
                        array(
                            'name' => 'tdate',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 1), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
                        array(
                            'name' => 'cpageno',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 2), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            //'source' => array('param' => 'token'),
                                'source' => array('path' => 3), 
                            'optional' => TRUE,
                            'default' => '*',
                            ),
      	),
      	
    	),
      	),
	),
        
        // magazine section end
        
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
       
        $redis_key = "itgd_rapid_datanotexist_api_json";
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            $jsondata = variable_get('datanotexist_api_json');
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
               
       
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

function itg_rapid_api_newslist($id, $cpageno, $token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       //valid tid & pageno
        $suffix = $id."_".$cpageno;
        if(!is_numeric($id)){
          $id = 0;
        }
        if(!is_numeric($cpageno)){
          $cpageno = 0;
        }
        
        $redis_key = "itgd_rapid_api_newslist_".$suffix;
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            // call function from return data..
            $jsondata = newscategoryPageRerourceValue($id, $cpageno);
            $jsondata = json_encode($jsondata);
            //print_r($jsondata);exit();
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
        
       $jsondata = json_decode($jsondata, true);
       
       

     return $jsondata;
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

function itg_rapid_api_programlist($id, $cpageno, $token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       //valid tid & pageno
        $suffix = $id."_".$cpageno;
        if(!is_numeric($id)){
          $id = 0;
        }
        if(!is_numeric($cpageno)){
          $cpageno = 0;
        }
        
        $redis_key = "itgd_rapid_api_programlist_".$suffix;
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            // call function from return data..
            $jsondata = programcategoryPageRerourceValue($id, $cpageno);
            $jsondata = json_encode($jsondata);
            //print_r($jsondata);exit();
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
       
       //print_r($jsondata);exit();
       
        $jsondata = json_decode($jsondata, true);
     return $jsondata;
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

function itg_rapid_api_videolist($id, $cpageno, $token) {    
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       //valid tid & pageno
        $suffix = $id."_".$cpageno;
        if(!is_numeric($id)){
          $id = 0;
        }
        if(!is_numeric($cpageno)){
          $cpageno = 0;
        }
        
        $redis_key = "itgd_rapid_api_videolist_".$suffix;
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            // call function from return data..
            $jsondata = videocategoryPageRerourceValue($id, $cpageno);
            $jsondata = json_encode($jsondata);
            //print_r($jsondata);exit();
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
       
       //print_r($jsondata);exit();
       $jsondata = json_decode($jsondata, true);

     return $jsondata;
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
        $suffix = $id;
        if(!is_numeric($id)){
          $id = 0;
        }
        
        $redis_key = "itgd_rapid_api_photodetail_".$suffix;
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            // call function from return data..
            $jsondata = photoDetailPageRerourceValue($id);
            $jsondata = json_encode($jsondata);
            //print_r($jsondata);exit();
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
        
       //print_r($jsondata);exit();
       $jsondata = json_decode($jsondata, true);

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
        $suffix = $id."_".$cpageno;
        if(!is_numeric($id)){
          $id = 0;
        }
        if(!is_numeric($cpageno)){
          $cpageno = 0;
        }
        
        $redis_key = "itgd_rapid_api_photolist_".$suffix;
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            // call function from return data..
            $jsondata = photocategoryPageRerourceValue($id, $cpageno);
            $jsondata = json_encode($jsondata);
            //print_r($jsondata);exit();
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
       
       //print_r($jsondata);exit();
       $jsondata = json_decode($jsondata, true);

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
        
        $redis_key = "itgd_rapid_server_error_master_json";
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            $jsondata = variable_get('server_error_master_json');
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
       
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
       
        $redis_key = "itgd_rapid_master_config_json";
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            $jsondata = variable_get('master_config_json');
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
        
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
        
        $redis_key = "itgd_rapid_config_update_status_json";
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            $jsondata = variable_get('config_update_status_json');
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
      
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
        
        $redis_key = "itgd_rapid_hamburger_menu_json";
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            $jsondata = variable_get('hamburger_menu_json');
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
       
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
       
        $redis_key = "itgd_rapid_horizontal_menu_json";
        $result_get = getRedis($redis_key);

        if($result_get['key_value'] !=""){
            $jsondata = $result_get['key_value'];
            //echo "redis get - ". $output; exit();
        }else{
            $jsondata = variable_get('horizontal_menu_json');
            $ttl = 300;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }
        
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


// sprint2 function start

/**
 * [itg_rapid_api_photostorydetail] definition.
 * Returns the information about a itg_rapid_api_photostorydetail.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_photostorydetail($id, $token) {
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
       $jsondata = photoStoryDetailPageRerourceValue($id);
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}


/**
 * [itg_rapid_api_program_category_list] definition.
 * Returns the information about a itg_rapid_api_program_category_list.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_program_category_list($token) {
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
       $jsondata = programCategoryListlPageRerourceValue();
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}


/**
 * [itg_rapid_api_ad_config_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_ad_config_json($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
       $jsondata = variable_get('ad_config_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}


/**
 * [itg_rapid_api_livetv_channellist_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_livetv_channellist_json($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
       $jsondata = variable_get('livetv_channellist_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_livetv_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_livetv_json($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
       $jsondata = variable_get('livetv_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_otherapps_ios_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_otherapps_ios_json($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
       $jsondata = variable_get('otherapps_ios_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

/**
 * [itg_rapid_api_otherapps_android_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_otherapps_android_json($token) {
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
       $jsondata = variable_get('otherapps_android_json');
       //echo $jsondata;exit;
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
   }
}

// magazine section start

/**
 * [itg_rapid_api_magazine_edition] definition.
 * Returns the information about a itg_rapid_api_magazine_edition.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_magazine_edition($id, $cpageno, $token) {
    
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
       $jsondata = magazineEditionPageRerourceValue($id, $cpageno);
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}


/**
 * [itg_rapid_api_magazine_coverstories] definition.
 * Returns the information about a itg_rapid_api_magazine_edition.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_magazine_coverstories($token) {
    
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       
       // call function from return data..
       $jsondata = magazineCoverstoriesPageRerourceValue();
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}

/**
 * [itg_rapid_api_magazine_editionlist] definition.
 * Returns the information about a itg_rapid_api_magazine_editionlist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 *	The node processed information array.
 */

function itg_rapid_api_magazine_editionlist($sdate, $tdate, $cpageno, $token) {
    
    $get_token = variable_get('mobile_service_token');
    if($get_token != $token){
        return services_error(t('Please enter valid token'), 406);
    }
    else{
       //valid tid & pageno
        if(!is_numeric($sdate)){
          $sdate = 0;
        }
        if(!is_numeric($tdate)){
          $tdate = 0;
        }
        if(!is_numeric($cpageno)){
          $cpageno = 0;
        }
       // call function from return data..
       $jsondata = magazineEditionListPageRerourceValue($sdate, $tdate, $cpageno);
       //print_r($jsondata);exit();
       

     return $jsondata;
   }
}

// magazine section end

function itg_rapid_api_testing($count) {
    //echo "hi andy-".$count;    exit();
    $json_string = 'http://localhost/decode/sprint1/master_config.json';


       $jsondata = file_get_contents($json_string);
       
       $obj = json_decode($jsondata, true);
       $return_obj = $obj;

     return $return_obj;
}