<?php

/**
 * @file
 * INC file for APP API Schemes Services.
 * Contains the resource declarations for the service APIs
 * and other commons functions/hooks. if necessary
 */
// include inc file

module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_photo');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_video');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_news');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_magazine');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_story');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_homePage');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_fblogin');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_twtlogin');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_author_story');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_polls');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_edit_profile');
module_load_include('inc', 'itg_app_api', 'inc/itg_app_api_bookmark');

/**
 * Function for APP API resource declaration.
 */
function itg_app_api_resource() {

    $api = array(
        /**
         * custom resource for sprint1
         */
        // config_update_status custom resource declaration.....
        'config_update_status' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves config_update_status schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
        // server_error_master custom resource declaration.....
        'server_error_master' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves server_error_master schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_photolist',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_photodetail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                            'source' => array('path' => 0),
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // adconfig_android custom resource declaration.....
        'adconfig_android' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves adconfig_android schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_adconfig_android',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // adconfig_ipad custom resource declaration.....
        'adconfig_ipad' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves adconfig_ipad schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_adconfig_ipad',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // adconfig_iphone custom resource declaration.....
        'adconfig_iphone' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves adconfig_iphone schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_adconfig_iphone',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // adconfig_tab custom resource declaration.....
        'adconfig_tab' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves adconfig_tab schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_adconfig_tab',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        /**
         * custom resource for sprint2
         */
        // photostorydetail custom resource declaration.....
        'photostorydetail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves photostorydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_photostorydetail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // livetv_channellist_json custom resource declaration.....
        'livetv_channellist' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves livetv_channellist_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // otherapps_ios_json custom resource declaration.....
        'otherapps_ios' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves otherapps_ios_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // otherapps_android_json custom resource declaration.....
        'otherapps_android' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves otherapps_android_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_magazine_edition',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
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
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_magazine_editionlist',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // magazine section end
        // storydetail custom resource declaration.....
        'storydetail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_storydetail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // homePage custom resource declaration.....
        'home' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_homePage',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // livetv_indiatoday_json custom resource declaration.....
        'livetv_indiatoday' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves livetv_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_livetv_indiatoday',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // livetv_aajtak_json custom resource declaration.....
        'livetv_aajtak' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves livetv_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_livetv_aajtak',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // livetv_delhiaajtak_json custom resource declaration.....
        'livetv_delhiaajtak' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves livetv_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_livetv_delhiaajtak',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // livetv_tej_json custom resource declaration.....
        'livetv_tej' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves livetv_json schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_livetv_tej',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        /**
         * custom resource for sprint3
         */
        // signup custom resource declaration.....
        'signup' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_signup',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'first_name',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'First Name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'last_name',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Last Name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User email or mobile number',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'confirm_password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Confirm Password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'login_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => '0=for traditional, 1=socail media',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'email_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Email Id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'phone_number',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Phone Number',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'location',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Location',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'profile_image',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Profile image',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'gender',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Gender',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'date_of_birth',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Date of birth',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Device id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Device type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // login_request custom resource declaration.....
        'login_request' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_login_request',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user email or mobile',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_id ',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // log_out custom resource declaration.....
        'log_out' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves log_out schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_log_out',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'auth_token',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'auth_token',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // change_password custom resource declaration.....
        'change_password' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves change_password schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_change_password',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user mobile or email',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'auth_token',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'auth token',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'old_password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'old password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'new_password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'new password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'confirm_password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'confirm password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // forgot_password custom resource declaration.....
        'forgot_password' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves forgot_password schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_forgot_password',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user mobile or email',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // otp_verification custom resource declaration.....
        'otp_verification' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves otp_verification schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_otp_verification',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user mobile or email',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'otp_code',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'otp_code',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device_type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // resend_otp custom resource declaration.....
        'resend_otp' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves resend_otp schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_resend_otp',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            //'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'source' => array('data'),
                            'description' => 'user mobile or email',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // get_login_user_detail custom resource declaration.....
        'get_login_user_detail' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves get_login_user_detail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_get_login_user_detail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'authtoken_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'authtoken_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user_id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // edit_profile custom resource declaration.....
        'edit_profile' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves edit_profile schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_edit_profile',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'authtoken_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'authtoken_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'first_name',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'first_name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'last_name',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'last_name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'zipcode',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'zipcode',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'address',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'address',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'profile_image',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'profile_image',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'gender',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'gender',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'date_of_birth',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'date_of_birth',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // get_preference custom resource declaration.....
        'get_preference' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves get_preference schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_get_preference',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'authtoken_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'authtoken_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user_id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // update_preference custom resource declaration.....
        'update_preference' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves update_preference schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_update_preference',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'authtoken_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'authtoken_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'preference',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'node_id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // reset_password custom resource declaration.....
        'reset_password' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves change_password schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_reset_password',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user mobile or email',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'new_password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'new password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'confirm_password',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'confirm password',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // authtoken_verification custom resource declaration.....
        'authtoken_verification' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves authtoken_verification schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_authtoken_verification',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user mobile or email',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'auth_token',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'auth token',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'device_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'device type',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // author_list custom resource declaration.....
        'author_list' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow author list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_author_list',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // anchor_list custom resource declaration.....
        'anchor_list' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow anchor list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_anchor_list',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // get_the_user_follow_status custom resource declaration.....
        'get_the_user_follow_status' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow anchor and author etc list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_get_the_user_follow_status',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // sprint 3 : Author latest story list @ dhmendra
        'author_story_list' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves latest story list of a particular author.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'author_latest_story',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // sprint 3 open poll
        'polls_open' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves All the open poll in the system.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'polls_open',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        //Sprint 3 close poll
        'polls_close' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves All the close/expire poll in the system.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'polls_close',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        //Sprint 3 close poll
        'poll_detail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves poll data based on poll id in the system.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'poll_detail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                        array(
                            'name' => 'poll_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Poll id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        //sprint 3 cast poll id
        'cast_polls' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Cast poll on the basis of poll id & option id',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_poll_cast',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'poll_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'First Name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'option_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Last Name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User email or mobile number',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        //sprint 4 Author detail
        'author_detail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves Author detail data based on Author id.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'author_detail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                        array(
                            'name' => 'author_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            'description' => 'Author id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // sprint 3 : Anchor Programm list
        'anchor_programm_list' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves programm list of a particular anchor.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'anchor_programm_list',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                        array(
                            'name' => 'anchor_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            'description' => 'Anchor id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'type',
                            'optional' => FALSE,
                            'source' => 'data',
                            'description' => 'Type 0 or 1 , 0 for latest and 1 for popular',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        /**
         * custom resource for sprint4
         */
        //sprint 4 Newswrap (Briefly.json)
        'newswrap' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves last stories which have heightights',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'news_wrap',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // Sprint 4 Read Later
        'bookmark_get' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Bookmark Get Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'bookmark_get_responce',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Loged in user id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'authtoken_id',
                            'optional' => TRUE,
                            'source' => 'data',
                            'description' => 'Loged user token id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // Sprint 4 Read Later
        'bookmark_set' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Bookmark Set and return Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'bookmark_set_responce',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'node_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Node Id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // Sprint 4 Read Later
        'bookmark_delete' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Bookmark delete and return Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'bookmark_delete_responce',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'node_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Node Id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // follow/unfollow API
        // follow_anchor custom resource declaration.....
        'follow_anchor' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow Anchor and return Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'follow_anchor_responce',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'author_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Node Id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'type follow or unfollow',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // follow_author custom resource declaration.....
        'follow_author' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow Author and return Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'follow_author_responce',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'author_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Node Id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'type follow or unfollow',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // anchor_follow_list custom resource declaration.....
        'anchor_follow_list' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow Anchor list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_anchor_follow_list',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // author_follow_list custom resource declaration.....
        'author_follow_list' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow author list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_author_follow_list',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // follow_topic custom resource declaration.....
        'follow_topic' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'follow_topic list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_follow_topic',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // user_follow_topic_list custom resource declaration.....
        'user_follow_topic_list' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Follow anchor list based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_user_follow_topic_list',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User id',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        /**
         * custom resource for other than sprint
         */
        // testing custom resource declaration.....
        'testing' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves testing schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_testing',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // edit_user_image custom resource declaration.....
        'edit_user_image' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves edit_user_image schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_edit_user_image',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'authtoken_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'authtoken_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'user_id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'profile_image',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'profile_image',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // anchor detail
        'anchor_detail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves Anchor detail data based on Anchor id in the system.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'anchor_detail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                        array(
                            'name' => 'anchor_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            'description' => 'Anchor User id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        /* Change request */
        // videodetail custom resource declaration.....
        'videodetail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves videodetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_videodetail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // programdetail custom resource declaration.....
        'programdetail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves programdetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_programdetail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // topstories custom resource declaration.....
        'topstories' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves topstories schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_topstories',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        //Social share in report API   
        'social_share_save_it' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Social Share Rest API save data',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'social_share_save_it_detail',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'website_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'First Name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'content_id',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'Last Name',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'content_type',
                            'optional' => TRUE,
                            'source' => array('data'),
                            'description' => 'User email or mobile number',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
        // aboutus custom resource declaration.....
        'aboutus' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves aboutus schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_aboutus',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'token',
                            'type' => 'string',
                            'description' => 'Function to perform',
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
 * sprint1 callback function
 */

/**
 * Call back function for master_config API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_master_config($token) {
    $redis_key = "itgd_rapid_master_config_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('master_config_json');
        if(variable_get('master_config_ttl')){
            $ttl = variable_get('master_config_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for config_update_status API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_config_update_status($token) {
    $redis_key = "itgd_rapid_config_update_status_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('config_update_status_json');
        if(variable_get('config_update_status_ttl')){
            $ttl = variable_get('config_update_status_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for hamburger_menu API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_hamburger_menu($token) {
    $redis_key = "itgd_rapid_hamburger_menu_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('hamburger_menu_json');
        if(variable_get('hamburger_menu_ttl')){
            $ttl = variable_get('hamburger_menu_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for horizontal_menu API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_horizontal_menu($token) {
    $redis_key = "itgd_rapid_horizontal_menu_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('horizontal_menu_json');
        if(variable_get('horizontal_menu_ttl')){
            $ttl = variable_get('horizontal_menu_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for server_error_master API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_server_error_master($token) {
    $redis_key = "itgd_rapid_server_error_master_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('server_error_master_json');
        if(variable_get('server_error_master_ttl')){
            $ttl = variable_get('server_error_master_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for photolist API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_photolist($token) {
    $id = $_GET['id'];
    $cpageno = $_GET['cpageno'];
    //valid tid & pageno
    $suffix = $id . "_" . $cpageno;
    if (!is_numeric($id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }

    $redis_key = "itgd_rapid_api_photolist_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = photocategoryPageRerourceValue($id, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('photolist_ttl')){
            $ttl = variable_get('photolist_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for photodetail API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_photodetail($token) {
    //valid id
    $id = $_GET['id'];
    $suffix = $id;
    if (!is_numeric($id)) {
        $id = 0;
    }

    $redis_key = "itgd_rapid_api_photodetail_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = photoDetailPageRerourceValue($id);
        $jsondata = json_encode($jsondata);
        if(variable_get('photodetail_ttl')){
            $ttl = variable_get('photodetail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }
    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for programlist API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_programlist($token) {
    //valid tid & pageno
    $id = $_GET['id'];
    $cpageno = $_GET['cpageno'];
    $suffix = $id . "_" . $cpageno;
    if (!is_numeric($id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }

    $redis_key = "itgd_rapid_api_programlist_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = programcategoryPageRerourceValue($id, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('programlist_ttl')){
            $ttl = variable_get('programlist_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for newslist API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_newslist($token) {
    //valid tid & pageno
    $realtime = 0;
    $id = $_GET['id'];
    $cpageno = $_GET['cpageno'];
    $suffix = $id . "_" . $cpageno;
    if (!is_numeric($id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }

    $redis_key = "itgd_rapid_api_newslist_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $realtime = 1;
        $jsondata_realtime = $jsondata = newscategoryPageRerourceValue($id, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('newslist_ttl')){
            $ttl = variable_get('newslist_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }
    if ($realtime) {
        return $jsondata_realtime;
    } else {
        $jsondata = json_decode($jsondata);
        return $jsondata;
    }
}

/**
 * Call back function for videolist API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_videolist($token) {
    //valid tid & pageno
    $id = $_GET['id'];
    $cpageno = $_GET['cpageno'];
    $suffix = $id . "_" . $cpageno;
    if (!is_numeric($id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }

    $redis_key = "itgd_rapid_api_videolist_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = videocategoryPageRerourceValue($id, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('videolist_ttl')){
            $ttl = variable_get('videolist_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for adconfig_android API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_adconfig_android($token) {
    $redis_key = "itgd_rapid_adconfig_android";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('adconfig_android');
        if(variable_get('adconfig_android_ttl')){
            $ttl = variable_get('adconfig_android_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for adconfig_ipad API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_adconfig_ipad($token) {
    $redis_key = "itgd_rapid_adconfig_ipad";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('adconfig_ipad');
        if(variable_get('adconfig_ipad_ttl')){
            $ttl = variable_get('adconfig_ipad_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for adconfig_iphone API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_adconfig_iphone($token) {
    $redis_key = "itgd_rapid_adconfig_iphone";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('adconfig_iphone');
        if(variable_get('adconfig_iphone_ttl')){
            $ttl = variable_get('adconfig_iphone_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for adconfig_tab API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_adconfig_tab($token) {
    $redis_key = "itgd_rapid_aadconfig_tab";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('adconfig_tab');
        if(variable_get('adconfig_tab_ttl')){
            $ttl = variable_get('adconfig_tab_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * sprint2 callback function
 */

/**
 * Call back function for photostorydetail API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_photostorydetail($token) {
    //valid id
    $id = $_GET['id'];
    if (!is_numeric($id)) {
        $id = 0;
    }

    // call function for return data..
    $suffix = $id;
    $redis_key = "itg_rapid_api_photostorydetail_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = photoStoryDetailPageRerourceValue($id);
        $jsondata = json_encode($jsondata);
        if(variable_get('photostorydetail_ttl')){
            $ttl = variable_get('photostorydetail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for program_category_list API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_program_category_list($token) {

    $redis_key = "itg_rapid_api_program_category_list";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = programCategoryListlPageRerourceValue();
        $jsondata = json_encode($jsondata);
        if(variable_get('program_category_list_ttl')){
            $ttl = variable_get('program_category_list_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for ad_config_json API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_ad_config_json($token) {

    $redis_key = "itg_rapid_api_ad_config_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('ad_config_json');
        if(variable_get('ad_config_json_ttl')){
            $ttl = variable_get('ad_config_json_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for livetv_channellist API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_livetv_channellist_json($token) {


    $redis_key = "itg_rapid_api_livetv_channellist_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_channellist_json');
        if(variable_get('livetv_channellist_ttl')){
            $ttl = variable_get('livetv_channellist_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * Call back function for otherapps_ios API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_otherapps_ios_json($token) {


    $redis_key = "itg_rapid_api_otherapps_ios_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('otherapps_ios_json');
        if(variable_get('otherapps_ios_ttl')){
            $ttl = variable_get('otherapps_ios_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for otherapps_android API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_otherapps_android_json($token) {


    $redis_key = "itg_rapid_api_otherapps_android_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('otherapps_android_json');
        if(variable_get('otherapps_android_ttl')){
            $ttl = variable_get('otherapps_android_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for magazine_edition API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_magazine_edition($token) {
    $id = $_GET['issueid'];
    $cpageno = $_GET['cpageno'];
    //valid tid & pageno
    if (!is_numeric($id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }


    $suffix = $id . "_" . $cpageno;
    $redis_key = "itg_rapid_api_magazine_edition_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = magazineEditionPageRerourceValue($id, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('magazine_edition_ttl')){
            $ttl = variable_get('magazine_edition_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for magazine_coverstories API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_magazine_coverstories($token) {

    // call function from return data..

    $redis_key = "itg_rapid_api_magazine_coverstories";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = magazineCoverstoriesPageRerourceValue();
        $jsondata = json_encode($jsondata);
        if(variable_get('magazine_coverstories_ttl')){
            $ttl = variable_get('magazine_coverstories_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for magazine_editionlist API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_magazine_editionlist($token) {
    $sdate = $_GET['sdate'];
    $tdate = $_GET['tdate'];
    $cpageno = $_GET['cpageno'];

    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }
    // call function from return data..


    $suffix = $sdate . "_" . $tdate . "_" . $cpageno;
    $redis_key = "itg_rapid_api_magazine_editionlist_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = magazineEditionListPageRerourceValue($sdate, $tdate, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('magazine_editionlist_ttl')){
            $ttl = variable_get('magazine_editionlist_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);

    return $jsondata;
}

/**
 * Call back function for storydetail API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_storydetail($token) {
    //valid id
    $id = $_GET['id'];
    if (!is_numeric($id)) {
        $id = 0;
    }

    // call function for return data..


    $suffix = $id;
    $redis_key = "itg_rapid_api_storydetail" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = StoryDetailPageRerourceValue($id);
        $jsondata = json_encode($jsondata);
        if(variable_get('storydetail_ttl')){
            $ttl = variable_get('storydetail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, FALSE);
    return $jsondata;
}

/**
 * Call back function for homePage API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_homePage($token) {

    $redis_key = "itg_rapid_api_homePage";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = homePageJson();
        $jsondata = json_encode($jsondata);
        if(variable_get('home_ttl')){
            $ttl = variable_get('home_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for livetv_aajtak API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_livetv_aajtak($token) {


    $redis_key = "itg_rapid_api_livetv_aajtak";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_aajtak');
        if(variable_get('livetv_aajtak_ttl')){
            $ttl = variable_get('livetv_aajtak_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for livetv_indiatoday API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_livetv_indiatoday($token) {


    $redis_key = "itg_rapid_api_livetv_indiatoday";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_indiatoday');
        if(variable_get('livetv_indiatoday_ttl')){
            $ttl = variable_get('livetv_indiatoday_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for livetv_delhiaajtak API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_livetv_delhiaajtak($token) {


    $redis_key = "itg_rapid_api_livetv_delhiaajtak";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_delhiaajtak');
        if(variable_get('livetv_delhiaajtak_ttl')){
            $ttl = variable_get('livetv_delhiaajtak_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * Call back function for livetv_tej API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_livetv_tej($token) {


    $redis_key = "itg_rapid_api_livetv_tej";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_tej');
        if(variable_get('livetv_tej_ttl')){
            $ttl = variable_get('livetv_tej_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, TRUE);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * sprint3 callback function
 */

/**
 * Call back function for signup API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_signup($token) {
    $HTTP_RAW_POST_DATA;
    // check duplicate user
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    $login_type = 0;
    $login_type = $params['login_type'];
    if ($login_type < 0 || $login_type > 2) {
        watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
        $account = array();
        $account['status_code'] = "0";
        $account['status_message'] = "Invalid Login Type.";
        return $account;
    }

    // signup validation function calling
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = signupValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);

    $method = "POST";
    $data = array();
    $account_err = array();
    $data['user_id'] = $params['user_id'];
    $account = array();

    if ($login_type == 0) {

        $rand = rand();
        $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
        $result = callAPI("GET", $url, $data);
        $result_obj = json_decode($result);

        $error_code_flag = 0;
        //if ($validation_error_str = "User already exists") {
        if (strpos($validation_error_str, 'User already exists') !== FALSE) {
            $error_code_flag = 2;
        }
        if ($validation_error_str) {
            $account_err['status_code'] = "$error_code_flag";
            $account_err['status_message'] = "$validation_error_str";
            return $account_err;
        } elseif ($result_obj->uid) {
            $account_err['status_code'] = "2";
            $account_err['status_message'] = "User already exists with " . $params['user_id'] . "";
            return $account_err;
        } else {

            $method = "POST";
            $data = $params;
            $account = array();
            $url = PARENT_SSO . "/appapisso/signup";
            $result = callAPI($method, $url, $data);
            $result_obj = json_decode($result);
            $uid = $result_obj->uid;
            $uname = $params['user_id'];

            if ($uid) {
                $result = localSignup($params);
                $cookie_val = getSmlCookie();
                $session_id = $cookie_val['session_id'];
                $session_name = $cookie_val['session_name'];
                $result_obj = json_decode($result);
                $account['status_code'] = "1";
                $account['status_message'] = "";
                $account['data']['user_id'] = "$uname";
                $account['data']['auth_token'] = "$result->token";
                $account['data']['session_id'] = "$session_id";
                $account['data']['session_name'] = "$session_name";
                //$account['data']['otp_status'] = "1";
            } else {
                watchdog('user', 'Duplicate signup attempt for %username.', array('%username' => $params['user_id']));
                $account['status_code'] = "2";
                $account['status_message'] = "User already exists with  " . $uname . "";
            }

            return $account;
        }
    } elseif ($login_type == 1) {

        $method = "POST";



        $data = array();
        $password = rand(0, 9999);
        $data = $params;
        $uname_fi = $params['user_id'];
        $data['password'] = $password;
        $data['uname'] = $uname_fi;
        $data['uid'] = $uname_fi;
        $data['token'] = $uname_fi;
        $data['app_id'] = $uname_fi;
        $data['issued_at'] = $uname_fi;
        $data['expires_at'] = $uname_fi;

        // signup validation function calling
        $validation_error = array();
        $validation_error_str = "";
        $validation_error = fblogin_rapid($params);
        $validation_error_str = implode(", ", $validation_error['custom_error']);
        if ($validation_error_str) {
            $account_err['status_code'] = "0";
            $account_err['status_message'] = "$validation_error_str";
            return $account_err;
        }

        $rand = rand();
        $account = array();
        $url = PARENT_SSO . "/appapisso/fblogin/" . $rand;

        $result = callAPI("GET", $url, $data);

        $result_obj = json_decode($result);
        $uid = 0;
        $uid = $result_obj->user->uid;
        $auth_token = $result_obj->token;
        $field_logged_in_count = $result_obj->user->field_logged_in_count->und[0]->value;


        if ($uid) {
            $local_account = fblogin($data);
            $cookie_val = getSmlCookie();
            $session_id = $cookie_val['session_id'];
            $session_name = $cookie_val['session_name'];
            $uid = $local_account->user->uid;
            $name = $local_account->user->name;
            $field_logged_in_count = $local_account->user->field_logged_in_count['und'][0]['value'];
            $auth_token = $local_account->token;
            $is_first_login = 1;
            if ($field_logged_in_count > 0) {
                $is_first_login = 0;
            }
            if ($auth_token) {
                $user = updateUsedrProfileAtSignup_rapid($data, 1);
                $account['status_code'] = "1";
                $account['status_message'] = "";
                $account['data']['user_id'] = "$name";
                $account['data']['auth_token'] = "$auth_token";
                $account['data']['session_id'] = "$session_id";
                $account['data']['session_name'] = "$session_name";
            } else {
                watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
                $account = array();
                $account['status_code'] = "0";
                $account['status_message'] = "Wrong username or password.";
                return $account;
            }
        } else {
            watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
            $account = array();
            $account['status_code'] = "0";
            $account['status_message'] = "Wrong username or password1.";
            return $account;
        }

        return $account;
    } elseif ($login_type == 2) {
        $method = "POST";
        $data = array();
        $password = rand(0, 9999);
        $data = $params;
        $uname_fi = $params['user_id'];
        $data['password'] = $password;
        $data['uname'] = $uname_fi;
        $data['uid'] = $uname_fi;
        $data['token'] = $uname_fi;
        $data['app_id'] = $uname_fi;
        $data['issued_at'] = $uname_fi;
        $data['expires_at'] = $uname_fi;

        // signup validation function calling
        $validation_error = array();
        $validation_error_str = "";
        $validation_error = twtogin_rapid($params);
        $validation_error_str = implode(", ", $validation_error['custom_error']);
        if ($validation_error_str) {
            $account_err['status_code'] = "0";
            $account_err['status_message'] = "$validation_error_str";
            return $account_err;
        }

        $rand = rand();
        $account = array();
        $url = PARENT_SSO . "/appapisso/fblogin/" . $rand;

        $result = callAPI("GET", $url, $data);

        $result_obj = json_decode($result);
        $uid = 0;
        $uid = $result_obj->user->uid;
        $auth_token = $result_obj->token;
        $field_logged_in_count = $result_obj->user->field_logged_in_count->und[0]->value;


        if ($uid) {
            $local_account = fblogin($data);
            $cookie_val = getSmlCookie();
            $session_id = $cookie_val['session_id'];
            $session_name = $cookie_val['session_name'];

            $uid = $local_account->user->uid;
            $name = $local_account->user->name;
            $field_logged_in_count = $local_account->user->field_logged_in_count['und'][0]['value'];
            $auth_token = $local_account->token;
            $is_first_login = 1;
            if ($field_logged_in_count > 0) {
                $is_first_login = 0;
            }
            if ($auth_token) {
                $user = updateUsedrProfileAtSignup_rapid($data, 1);
                $account['status_code'] = "1";
                $account['status_message'] = "";
                $account['data']['user_id'] = "$name";
                $account['data']['auth_token'] = "$auth_token";
                $account['data']['session_id'] = "$session_id";
                $account['data']['session_name'] = "$session_name";
            } else {
                watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
                $account = array();
                $account['status_code'] = "0";
                $account['status_message'] = "Wrong username or password.";
                return $account;
            }
        } else {
            watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
            $account = array();
            $account['status_code'] = "0";
            $account['status_message'] = "Wrong username or password.";
            return $account;
        }

        return $account;
    }
}

/**
 * Call back function for login_request API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_login_request($token) {

    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $method = "POST";
    $data = $params;
    // login raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = loginValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    if ($validation_error_str) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }

    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $data);
    $result_obj = json_decode($result);
    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Wrong username or password.";
        return $account_err;
    }

    //check user is block
    $user_data = user_load_by_name($data['user_id']);
    if ($user_data->status == 0) {
        $account_err['status_code'] = "3";
        $account_err['status_message'] = "Accont Locked";
        return $account_err;
    }
    $account = array();
    $url = PARENT_SSO . "/appapisso/login_request";
    $result = callAPI($method, $url, $params);
    $result_obj = json_decode($result);
    $uid = 0;
    $uid = $result_obj->uid;
    $auth_token = $result_obj->token;
    $field_logged_in_count = $result_obj->user->field_logged_in_count->und[0]->value;

    if ($uid) {
        $local_account = localLogin($params);
        $cookie_val = getSmlCookie();
        $session_id = $cookie_val['session_id'];
        $session_name = $cookie_val['session_name'];
        $uid = $local_account->user->uid;
        $name = $local_account->user->name;
        $field_logged_in_count = $local_account->user->field_logged_in_count['und'][0]['value'];
        $auth_token = $local_account->token;
        $is_first_login = 1;
        if ($field_logged_in_count > 0) {
            $is_first_login = 0;
        }
        if ($auth_token) {

            $SimpleSAMLSessionID = $_COOKIE['SimpleSAMLSessionID'];
            $field_first_name = $local_account->user->field_first_name['und'][0]['value'];
            $field_last_name = $local_account->user->field_last_name['und'][0]['value'];
            $field_short_description = $local_account->user->field_short_description['und'][0]['value'];
            $profile_image = completeFilePath($local_account->user->field_user_picture['und'][0]['fid']);
            $gender = $local_account->user->field_user_gender['und'][0]['value'];
            $date_of_birth = $local_account->user->field_story_issue_date['und'][0]['value'];
            $phone_number = "";
            $mail = "";
            if (is_numeric($name)) {
                $phone_number = $name;
            } else {
                $mail = $name;
            }
            $account['status_code'] = "1";
            $account['status_message'] = "";
            $account['data']['user_id'] = "$name";
            $account['data']['auth_token'] = "$auth_token";
            $account['data']['is_authenticated'] = "0";

            $account['data']['first_name'] = "$field_first_name";
            $account['data']['last_name'] = "$field_last_name";
            $account['data']['email_id'] = "$mail";
            $account['data']['phone_number'] = "$phone_number";
            $account['data']['location'] = "$field_short_description";
            $account['data']['profile_image'] = "$profile_image";
            $account['data']['gender'] = "$gender";
            $account['data']['date_of_birth'] = "$date_of_birth";
            $account['data']['session_id'] = "$session_id";
            $account['data']['session_name'] = "$session_name";


            // query for insert data into itg_app_device - $action $token
            $action = 2;
            $device_id = $params['device_id'];
            $device_type = $params['device_type'];
            db_insert('itg_app_device')->fields(array(
                'uid' => $uid,
                'device_id' => check_plain($device_id),
                'device_type' => check_plain($device_type),
                'action' => check_plain($action),
                'token' => check_plain($auth_token),
            ))->execute();
        } else {
            watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
            //return services_error(t('Wrong username or password.'), 401);
            $account = array();
            $account['status_code'] = "0";
            $account['status_message'] = "Wrong username or password.";
            return $account;
        }
    } else {
        watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
        //return services_error(t('Wrong username or password.'), 401);
        $account = array();
        $s_code = 0;
        if($user_data->uid > 0){
            $s_code = 2;
        }
        $account['status_code'] = "$s_code";
        $account['status_message'] = "Wrong username or password.";
        return $account;
    }

    return $account;
}

/**
 * Call back function for edit_user_image API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_edit_user_image($token) {
    $HTTP_RAW_POST_DATA;
    $data = array();
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        //return $account_err;
    }
    $authtoken_id = $token = $params['authtoken_id'];


    $token_val_flag = 0;
    $token_val_flag = tokenValidator($params['user_id'], $authtoken_id);
    if (!drupal_valid_token($token, 'services')) {
        //if (!$token_val_flag) {
        $data['status_code'] = "0";
        $data['status_message'] = "invalid token";
    } else {

        global $user;
        $user_id = $params['user_id'];
        $profile_image = $params['profile_image'];
        $user_detail = user_load_by_name($user_id);
        $uid = $user_detail->uid;

        // call sso server api
        $method = "POST";
        $url = PARENT_SSO . "/appapisso/edit_user_image";
        $result = callAPI($method, $url, $params);

        // check mime-type
        $profile_img = base64_decode($profile_image);
        $f = finfo_open();
        $mime_type = finfo_buffer($f, $profile_img, FILEINFO_MIME_TYPE);
        $mime_type_ar = explode("/", $mime_type);
        $mime_type_ext = $mime_type_ar[1];



        $profile_img_tmp = '/tmp/profileimage_' . $uid . "." . $mime_type_ext;

        $image_name = 'profileimage_' . $uid . "." . $mime_type_ext;
        // crate profile img tmp file
        file_put_contents($profile_img_tmp, $profile_img);
        $imagedata = file_get_contents($profile_img_tmp);
        $file_data = file_save_data($imagedata, file_default_scheme() . '://' . $image_name);


        // Update profile pic
        if (!empty($file_data->fid)) {
            $user_detail->field_user_picture['und'][0]['fid'] = $file_data->fid;
        }

        // Save user object.
        $resp = user_save($user_detail);
        if ($resp->uid) {
            $data['status_code'] = "1";
            $data['status_message'] = "";
        } else {
            $data['status_code'] = "0";
            $data['status_message'] = "Technical Error.";
        }
    }
    return $data;
}

/**
 * Call back function for log_out API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_log_out($token) {
    $HTTP_RAW_POST_DATA;
    global $base_url;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    // check valid user_id
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $token = $params['auth_token'];
    $result_obj = json_decode($result);
    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }
    $token_val_flag = 0;
    $token_val_flag = tokenValidator($params['user_id'], $token);
    if (!drupal_valid_token($token, 'services')) {
        $res['status_code'] = "0";
        $res['status_message'] = "invalid token";
        return $res;
    }

    $method = "POST";
    $url = PARENT_SSO . "/appapisso/log_out";
    $result = callAPI($method, $url, $params);
    $user_id = $params['user_id'];
    $user = user_load_by_name($user_id);
    watchdog('user', 'Session closed for %name.', array('%name' => $user->name));
    $original_session_state = drupal_save_session();
    drupal_save_session(TRUE);
    // Destroy the current session.
    module_invoke_all('user_logout', $user);
    session_destroy();
    // Load the anonymous user.
    $user = drupal_anonymous_user();
    drupal_save_session($original_session_state);
    // call custom function to clean token in custom table
    cleanToken_Rapid($params);

    $data['status_code'] = "1";
    $data['status_message'] = "";

    return $data;
}

/**
 * Call back function for change_password API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_change_password($token) {
    $HTTP_RAW_POST_DATA;
    $method = "POST";
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $params['old_pass'] = trim($params['old_password']);
    $params['new_pass'] = trim($params['new_password']);

    // raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = validateChangePass($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    if ($validation_error_str) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }
    $token = $params['auth_token'];
    $token_val_flag = 0;
    $token_val_flag = tokenValidator($params['user_id'], $token);
    if (!drupal_valid_token($token, 'services')) {
        //if (!$token_val_flag) {
        $res['status_code'] = "0";
        $res['status_message'] = "invalid token";
        return $res;
    }

    $url = PARENT_SSO . "/appapisso/change_password";
    $result = callAPI($method, $url, $params);
    $result_obj = json_decode($result);

    if ($result_obj->uid) {
        $local_obj = localChangePass($params, $result_obj->uid);
        itg_reset_pass_info_insert_rapid($params, 2);
        cleanToken_Rapid($params);
        $user_name = $params['user_id'];
        $user = user_load_by_name($user_name);

        watchdog('user', 'Session closed for %name.', array('%name' => $user->name));

        $original_session_state = drupal_save_session();
        drupal_save_session(TRUE);

        // Destroy the current session.
        module_invoke_all('user_logout', $user);
        session_destroy();

        // Load the anonymous user.
        $user = drupal_anonymous_user();

        drupal_save_session($original_session_state);
        deviceTokenReset_Rapid($params);
        $data['status_code'] = "1";
        $data['status_message'] = "Password has changed";
    } else {
        $data['status_code'] = "2";
        $data['status_message'] = "Password has not changed";
    }

    return $data;
}

/**
 * Call back function for forgot_password API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_forgot_password($token) {
    $HTTP_RAW_POST_DATA;
    $method = "POST";
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    // login raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = forgotPasswordValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    $error_code_flag = 0;
    //if ($error_code_flag = "This phone number/ email is not registered") {
    if (strpos($validation_error_str, 'This phone number/ email is not registered') !== FALSE) {
        $error_code_flag = 2;
    }
    if ($validation_error_str) {
        $account_err['status_code'] = "$error_code_flag";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }

    // check valid user_id
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "2";
        $account_err['status_message'] = "This phone number/ email is not registered";
        return $account_err;
    }

    $url = PARENT_SSO . "/appapisso/forgot_password";
    //itg_otp_device_info_insert_rapid($params);
    $result = callAPI($method, $url, $params);
    $result_obj = json_decode($result);

    // get_otp & insert into itg_otp_device_info
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/get_otp/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj_otp = json_decode($result);

    if ($result_obj_otp[0]->otp) {
        itg_otp_device_info_insert_rapid($params, $result_obj_otp[0]->otp, 1, $result_obj_otp[0]->created);
    }
    cleanToken_Rapid($params);
    $data['status_code'] = "1";
    $data['status_message'] = "";

    return $data;
}

/**
 * Call back function for otp_verification API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_otp_verification($token) {
    $HTTP_RAW_POST_DATA;
    $method = "POST";
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    // login raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = forgotPasswordValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    $error_code_flag = 0;
    //if ($error_code_flag = "This phone number/ email is not registered") {
    if (strpos($validation_error_str, 'This phone number/ email is not registered') !== FALSE) {
        $error_code_flag = 2;
    }
    if ($validation_error_str) {
        $account_err['status_code'] = "$error_code_flag";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }
    //$params = $_POST;
    $url = PARENT_SSO . "/appapisso/otp_verification";
    $result = callAPI($method, $url, $params);
    $result_obj = json_decode($result);

    if ($result_obj[0]->otp) {
        //login scritp start
        $user_name = $params['user_id'];
        $user = user_load_by_name($user_name);

        if ($user->uid) {
            //user_login_finalize($user);

            $return = new stdClass();
            $return->sessid = session_id();
            $return->session_name = session_name();
            $return->token = drupal_get_token('services');

            $account = clone$user;

            services_remove_user_data($account);

            $return->user = $account;

            //return $return;
        }
        //login scritp end
        $uname = $params['user_id'];
        $data['status_code'] = "1";
        $data['status_message'] = "";
        $data['data']['user_id'] = "$uname";
        $data['data']['is_authenticated'] = "1";
        //$data['data']['auth_token'] = "$return->token";
    } else {
        $data['status_code'] = "0";
        $data['status_message'] = "Please enter the correct OTP";
    }


    return $data;
}

/**
 * Call back function for resend_otp API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_resend_otp($token, $user_id) {
    $HTTP_RAW_POST_DATA;
    $method = "POST";
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    // raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = resentotpValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    if ($validation_error_str) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }

    $url = PARENT_SSO . "/appapisso/resend_otp";
    $result = callAPI($method, $url, $params);
    $result_obj = json_decode($result);

    $data['status_code'] = "1";
    $data['status_message'] = "";

    return $data;
}

/**
 * Call back function for get_login_user_detail API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_get_login_user_detail($token) {
    $HTTP_RAW_POST_DATA;
    $data = array();
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }
    $authtoken_id = $params['authtoken_id'];
    $user_id = $params['user_id'];
    $token = $params['authtoken_id'];
    $token_val_flag = 0;
    $token_val_flag = tokenValidator($params['user_id'], $authtoken_id);
    if (!drupal_valid_token($token, 'services')) {
        $data['status_code'] = "0";
        $data['status_message'] = "invalid token";
    } else {
        $account = user_load_by_name($user_id);
        $first_name = $account->field_first_name['und'][0]['value'];
        $last_name = $account->field_last_name['und'][0]['value'];
        $email_id = $account->mail;
        $phone_number = $account->field_mobile_number['und'][0]['value'];
        $location = "";
        $location = $account->field_short_description['und'][0]['value'];
        $profile_image = completeFilePath($account->field_user_picture['und'][0]['fid']);
        $gender = $account->field_user_gender['und'][0]['value'];
        $date_of_birth = $account->field_story_issue_date['und'][0]['value'];
        $login_type = "0";
        if (strpos($email_id, '@facebook.com') !== FALSE) {
            $login_type = 1;
        } elseif (strpos($email_id, '@twitter.com') !== FALSE) {
            $login_type = 2;
        }

        $data['status_code'] = "1";
        $data['status_message'] = "";

        $data['data']['user_profile_detail']['token_id'] = "$authtoken_id";
        $data['data']['user_profile_detail']['login_type'] = "$login_type";
        $data['data']['user_profile_detail']['user_id'] = "$user_id";
        $data['data']['user_profile_detail']['first_name'] = "$first_name";
        $data['data']['user_profile_detail']['last_name'] = "$last_name";
        $data['data']['user_profile_detail']['email_id'] = "$email_id";
        $data['data']['user_profile_detail']['phone_number'] = "$phone_number";
        $data['data']['user_profile_detail']['location'] = "$location";
        $data['data']['user_profile_detail']['profile_image'] = "$profile_image";
        $data['data']['user_profile_detail']['gender'] = "$gender";
        $data['data']['user_profile_detail']['date_of_birth'] = "$date_of_birth";
    }

    return $data;
}

/**
 * Call back function for edit_profile API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_edit_profile($token) {

    $HTTP_RAW_POST_DATA;
    $method = "POST";
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $pram['user_id'] = array($params['user_id']);
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $pram);
    $result_obj = json_decode($result);

    // raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = resentotpValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    if ($validation_error_str) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }
    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }
    $token = $params['authtoken_id'];
    $token_val_flag = 0;
    $token_val_flag = tokenValidator($params['user_id'], $token);
    if (!drupal_valid_token($token, 'services')) {
        //if (!$token_val_flag) {
        $responce_object['status_code'] = "0";
        $responce_object['status_message'] = "invalid token";
    } else {
        $url = PARENT_SSO . "/appapisso/edit_profile";
        $result = callAPI($method, $url, $params);
        $result_obj = json_decode($result);

        //if ($result_obj->uid) {
        $responce_object_rs = saveUpdatedProfile($params);
        $user_val = user_load_by_name($params['user_id']);
        $profile_image = completeFilePath($user_val->field_user_picture['und'][0]['fid']);
        $responce_object['status_code'] = "1";
        $responce_object['status_message'] = "";
        $responce_object['data']['profile_image'] = "$profile_image";
        //}
    }
    return $responce_object;
}

/**
 * Call back function for get_preference API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_get_preference($token) {
    $HTTP_RAW_POST_DATA;
    global $base_url;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $user_id = $params['user_id'];
    $authtoken_id = $params['authtoken_id'];
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }
    if (!drupal_valid_token($authtoken_id, 'services')) {
        $data['status_code'] = "0";
        $data['status_message'] = "invalid token";
        return $data;
    } else {
        $account = user_load_by_name($user_id);
        $preference_tid = get_personalization_saved_value_service($account->uid);
        $data['status_code'] = "1";
        $data['status_message'] = "";
        $data['data']['updated_datetime'] = "$last_access_date";
        $data['data']['preference_type'] = "explicit";
        $loop_count = 0;
        //get personalization-preferences value
        foreach ($preference_tid as $key => $value) {
            $pdata = $value;
            $tid = $pdata['nid'];
            $prefeance = $pdata['weight'];
            $term = taxonomy_term_load($tid);
            $term_name = $term->name;
            $data['data']['preference'][$loop_count]['id'] = "$tid";
            $data['data']['preference'][$loop_count]['title'] = "$term_name";
            $data['data']['preference'][$loop_count]['is_preffered'] = "$prefeance";
            $loop_count++;
        }
    }
    return $data;
}

/**
 * Call back function for update_preference API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_update_preference($token) {
    global $base_url;
    global $user;
    $HTTP_RAW_POST_DATA;
    $data = array();
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $user_id = $params['user_id'];
    $authtoken_id = $params['authtoken_id'];
    $preference = $params['preference'];
    $updates = array();
    foreach ($preference as $key => $val) {
        $tid = (int) $val['id'];
        $value = (int) $val['is_preffered'];
        if ($value) {
            $is_preffered = 100;
        } else {
            $is_preffered = 0;
        }
        $updates[$tid]['value'] = $is_preffered;
    }

    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }
    if (!drupal_valid_token($authtoken_id, 'services')) {
        $data['status_code'] = "0";
        $data['status_message'] = "invalid token";
        return $data;
    } else {

        $result = callAPI($method, $url, $params);

        $user = user_load_by_name($user_id);
        $widget_name = "personalization_widget";

        $nids = array_keys($updates);
        // Delete all the tids from table if they are not in $updates variable
        // unsued tid should be delete
        db_delete('itg_widget_order')->condition('widget', $widget_name)->condition('nid', $nids, "NOT IN")->condition('extra', $user->uid)->execute();
        // Update the weight of tids if exists or insert if dont exists.
        foreach ($updates as $term_id => $weight) {
            $weight_val = $weight['value'];
            db_merge('itg_widget_order')->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user->uid))->fields(array(
                'nid' => $term_id,
                'widget' => $widget_name,
                'weight' => $weight_val,
                'extra' => $user->uid,
            ))->execute();
        }
    }
    $data['status_code'] = "1";
    $data['status_message'] = "";
    return $data;
}

/**
 * Call back function for reset_password API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_reset_password($token) {
    $HTTP_RAW_POST_DATA;
    $method = "POST";
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    // raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = validateResetPass($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    if ($validation_error_str) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    }
    $rand = rand();
    $url = PARENT_SSO . "/appapisso/check_user/" . $rand;

    $result = callAPI("GET", $url, $params);
    $result_obj = json_decode($result);

    if (!$result_obj->uid) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "Invalid User_ID";
        return $account_err;
    }

    $url = PARENT_SSO . "/appapisso/reset_password";
    $result = callAPI($method, $url, $params);
    $result_obj = json_decode($result);

    if ($result_obj->uid) {
        $local_obj = localResetPass($params, $result_obj->uid);
        itg_reset_pass_info_insert_rapid($params, 1);
        cleanToken_Rapid($params);
        $user_name = $params['user_id'];
        $user = user_load_by_name($user_name);

        watchdog('user', 'Session closed for %name.', array('%name' => $user->name));

        $original_session_state = drupal_save_session();
        drupal_save_session(TRUE);

        // Destroy the current session.
        module_invoke_all('user_logout', $user);
        session_destroy();

        // Load the anonymous user.
        $user = drupal_anonymous_user();

        drupal_save_session($original_session_state);
        deviceTokenReset_Rapid($params);
        $data['status_code'] = "1";
        $data['status_message'] = "password has been changed";
    } else {
        $data['status_code'] = "2";
        $data['status_message'] = "password has not been changed";
    }



    return $data;
}

/**
 * Call back function for authtoken_verification API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_authtoken_verification($token) {

    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    $token = $params['auth_token'];
    $data = array();
    $method = "POST";
    $res = array();
    // login raw input validation
    $validation_error = array();
    $validation_error_str = "";
    $validation_error = authtokenValidation_rapid($params);
    $validation_error_str = implode(", ", $validation_error['custom_error']);
    if ($validation_error_str) {
        $account_err['status_code'] = "0";
        $account_err['status_message'] = "$validation_error_str";
        return $account_err;
    } else {
        $rand = rand();
        $url = PARENT_SSO . "/appapisso/check_user/" . $rand;
        $result = callAPI("GET", $url, $params);
        $result_obj = json_decode($result);

        if (!$result_obj->uid) {
            $account_err['status_code'] = "0";
            $account_err['status_message'] = "Invalid User_ID";
            return $account_err;
        }
        $token_val_flag = 0;
        $token_val_flag = tokenValidator($params['user_id'], $token);
        if (!drupal_valid_token($token, 'services')) {
            $res['status_code'] = "0";
            $res['status_message'] = "invalid token";
        } else {
            $res['status_code'] = "1";
            $res['status_message'] = "";
        }
    }
    return $res;
}

/**
 * Call back function for author_list API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_author_list($token) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $cpageno = $params['cpageno'];
    $message_array = array();
    $args = '0';
    if ($user_id != '0' && isset($authtoken_id)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }
    // check args
    if ($args != '0') {
        $jsondata = list_itg_rapid_api_author_list($user_id, $cpageno);
    } else {
        $jsondata = $message_array;
    }
    return $jsondata;
}

/**
 * Call back function for anchor_list API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_anchor_list($token) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $cpageno = $params['cpageno'];
    $showall = $params['showall'];

    $message_array = array();

    $args = '0';
    if ($params['user_id']) {
        if ($user_id != '0' && isset($authtoken_id)) {
            $args = '1';
        } else {
            $message_array['status_code'] = '0';
            $message_array['status_message'] = "Argument are missing";
            $message_array['data'] = array();
        }

        if ($user_id == '') {
            $args = '0';
            $message_array['status_code'] = "0";
            $message_array['status_message'] = "User does not exist";
            $message_array['data'] = array();
        }

        if (!drupal_valid_token($authtoken_id, 'services')) {
            $args = '0';
            $message_array['status_code'] = "0";
            $message_array['status_message'] = "invalid token";
            $message_array['data'] = array();
        }
    } else {
        $args = 1;
        $showall = 0;
    }


    // check args
    if ($user_id > 0) {
        //$jsondata = list_itg_rapid_api_anchor_list($user_id, $cpageno, $showall);
        $jsondata = list_itg_rapid_api_anchor_list_default();
    } else {
        $jsondata = list_itg_rapid_api_anchor_list_default();
    }

    return $jsondata;
}

/**
 * Call back function for get_the_user_follow_status API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_get_the_user_follow_status($token) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }

    // check args
    if ($args != '0') {
        $jsondata = list_itg_rapid_api_get_the_user_follow_status($user_id);
    } else {
        $jsondata = $message_array;
    }
    return $jsondata;
}

/**
 * Call back function for author_latest_story API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function author_latest_story($token) {
    //valid id
    $author_id = $_GET['author_id'];
    $story_type = $_GET['type'];
    $cpageno = $_GET['cpageno'];


    if (!is_numeric($author_id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }
    // call function for return data..
    if ($_GET['type'] == '0') {
        $type = 'latest';
    } elseif ($_GET['type'] == '1') {
        $type = 'popular';
    }

    $suffix = $author_id . '_' . $cpageno;
    $redis_key = "itg_rapid_api_author_" . $type . "_storylist" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = author_story_list($author_id, $story_type, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('author_story_list_ttl')){
            $ttl = variable_get('author_story_list_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for polls_open API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function polls_open($token) {
    $cpageno = $_GET['cpageno'];
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }

    $redis_key = "itg_rapid_api_open_polls_" . $cpageno;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = polls_open_list($cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('polls_open_ttl')){
            $ttl = variable_get('polls_open_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for polls_close API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function polls_close($token) {
    $cpageno = $_GET['cpageno'];
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }
    $redis_key = "itg_rapid_api_close_polls_" . $cpageno;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = polls_close_list($cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('polls_close_ttl')){
            $ttl = variable_get('polls_close_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for poll_cast API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_poll_cast($poll_id, $option_id, $user_id, $args) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    $poll_id = $params['poll_id'];
    $option_id = isset($params['option_id']) ? $params['option_id'] : "";
    $device_id = $params['device_id'];
    $device = isset($params['device_type']) ? $params['device_type'] : "";
    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = isset($user_load->uid) ? $user_load->uid : "";

    $message_array = array();
    $args = '0';
    //Check args is exist
    if ($poll_id != '' && $device_id != '') {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    $node_load = node_load($poll_id);

    if (!$node_load) {
        $args = '0';
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "This is not a valid poll id";
        $message_array['data'] = array();
    } else {
        if ($node_load->type != 'poll') {
            $args = '0';
            $message_array['status_code'] = '0';
            $message_array['status_message'] = "This is not a valid poll id";
            $message_array['data'] = array();
        } else {
            if ($option_id != '') {
                $polls = array();
                foreach ($node_load->field_poll_answer['und'] as $data) {
                    $polls[] = $data['value'];
                }
                if (!in_array($option_id, $polls)) {
                    $args = '0';
                    $message_array['status_code'] = '0';
                    $message_array['status_message'] = "Option id does not match with poll id";
                    $message_array['data'] = array();
                }
            }
        }
    }

    // check args
    if ($args != '0') {
        // if status is 0 then poll is already closed ,
        $poll_status = check_poll_status($poll_id);
        if ($poll_status != '0') {
            $jsondata = poll_cast_list($poll_id, $option_id, $device_id, $ip_address, $device);
        } else {
            $message_array['status_code'] = '0';
            $message_array['status_message'] = "Poll is already closed";
            $message_array['data'] = array();
            $jsondata = $message_array;
        }
    } else {
        $jsondata = $message_array;
    }
    return $jsondata;
}

/**
 * Call back function for author_detail API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function author_detail($token, $author_id) {

    $author_id = $_GET['author_id'];
    $redis_key = "itg_rapid_api_author_" . $author_id . "_detail";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = author_detail_data($author_id);
        $jsondata = json_encode($jsondata);
        if(variable_get('author_detail_ttl')){
            $ttl = variable_get('author_detail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * sprint4 callback function
 */

/**
 * Call back function for news_wrap API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function news_wrap($token) {

    $redis_key = "itg_rapid_newswrap";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = news_wrap_list();
        $jsondata = json_encode($jsondata);
        if(variable_get('newswrap_ttl')){
            $ttl = variable_get('newswrap_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for bookmark_get_responce API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function bookmark_get_responce($token, $user_id, $authtoken_id) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];

    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array('news' => array());
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array('news' => array());
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array('news' => array());
    }


    if ($args != '0') {
        $jsondata = bookmark_responce_data($user_id);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for bookmark_set_responce API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function bookmark_set_responce($token, $user_id, $node_id) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $node_ids = $params['data']['content'];

    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id) && is_array($node_ids)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array('news' => array());
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array('news' => array());
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array('news' => array());
    }

    // check args
    if ($args != '0') {
        $jsondata = bookmark_set_data_responce($user_id, $node_ids);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for bookmark_delete_responce API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function bookmark_delete_responce($token, $user_id, $node_id) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $authtoken_id = $params['authtoken_id'];

    $user_id = $user_load->uid;
    $node_ids = $params['data']['bookmark_content'];
    $message_array = array();
    $args = '0';
    if ($user_id != '0' && isset($authtoken_id) && is_array($node_ids)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array('bookmark_content' => array());
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array('bookmark_content' => array());
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array('bookmark_content' => array());
    }

    if ($args != '0') {
        $jsondata = bookmark_del_data_responce($user_id, $node_ids);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for follow_anchor API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function follow_anchor_responce($token, $user_id, $node_id) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $author_id = $anchor_id = $params['anchor_id'];
    $isfollow = $params['isfollow'];
    if ($isfollow == 1) {
        $type = "follow_story";
    } else {
        $type = "Unfollow";
    }

    $message_array = array();


    $args = '0';
    if ($user_id != '0' && isset($authtoken_id) && $anchor_id != '' && $type != '') {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }
    if (!valid_anchor_author($anchor_id, 'anchor')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "Anchor Id is not valid.";
        $message_array['data'] = array();
    }
    if ($type == 'follow_story' || $type == 'Unfollow') {
        
    } else {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "Type is not valid it shoud be either follow_story or Unfollow";
        $message_array['data'] = array();
    }

    // check args
    if ($args != '0') {
        $jsondata = follow_anchor_data_responce($user_id, $author_id, $type);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for follow_author API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function follow_author_responce($token, $user_id, $node_id) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $author_id = $params['author_id'];
    $isfollow = $params['isfollow'];
    if ($isfollow == 1) {
        $type = "follow_story";
    } else {
        $type = "Unfollow";
    }


    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id) && $author_id != '' && $type != '') {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }
    if (!valid_anchor_author($author_id, 'author')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "Author Id is not valid.";
        $message_array['data'] = array();
    }
    if ($type == 'follow_story' || $type == 'Unfollow') {
        
    } else {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "Type is not valid it shoud be either follow_story or Unfollow";
        $message_array['data'] = array();
    }

    // check args
    if ($args != '0') {
        $jsondata = follow_author_data_responce($user_id, $author_id, $type);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for anchor_follow_list API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_anchor_follow_list($token) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];


    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }


    // check args
    if ($args != '0') {
        $jsondata = list_anchor_data_responce($user_id);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for author_follow_list API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_author_follow_list($token) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $author_id = $params['author_id'];
    $type = $params['type'];

    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }


    // check args
    if ($args != '0') {
        $jsondata = list_author_data_responce($user_id);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for get_the_user_follow_status API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function list_itg_rapid_api_get_the_user_follow_status($uid) {
    $data = '';
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        $cond = array('uid' => $uid);
        $cursor = $people->find($cond);
        $loopc = 0;
        foreach ($cursor as $document) {

            $data[$loopc]['nid'] = $document['nid'];
            $data[$loopc]['status'] = $document['status'];
            $data[$loopc]['ntype'] = $document['ntype'];
            $loopc++;
        }
        //return $data;
    }
    $anchor_list = array();
    $author_list = array();
    $topics_list = array();
    $anchor_data = array();
    $anchor_c = 0;
    $anchor_c1 = 0;
    $anchor_c2 = 0;
    foreach ($data as $key => $value) {
        if ($value['nid']) {
            // 837259
            $node_data = node_load($value['nid']);

            if ($value['ntype'] == "anchor" && $value['status'] == 1) {
                $a_id = $node_data->nid;

                $anchor_list[$anchor_c]['a_id'] = "$a_id";

                $anchor_c++;
            } elseif ($value['ntype'] == "author" && $value['status'] == 1) {
                $a_id = $node_data->nid;

                $author_list[$anchor_c1]['a_id'] = "$a_id";

                $anchor_c1++;
            } elseif ($value['ntype'] == "tag" && $value['status'] == 1) {
                $a_id = $value['nid'];

                $topics_list[$anchor_c2]['t_id'] = "$a_id";

                $anchor_c2++;
            }
        }
    }


    $anchor_data['anchor'] = $anchor_list;
    $anchor_data['author'] = $author_list;
    $anchor_data['topic'] = $topics_list;

    if ($anchor_c > 0 || $anchor_c1 > 0 || $anchor_c2 > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * Call back function for follow_topic API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_follow_topic($token) {

    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];
    $author_id = $anchor_id = $params['topic_id'];
    $isfollow = $params['isfollow'];
    if ($isfollow == 1) {
        $type = "follow_story";
    } else {
        $type = "Unfollow";
    }

    $message_array = array();


    $args = '0';
    if ($user_id != '0' && isset($authtoken_id) && $anchor_id != '' && $type != '') {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }

    if ($type == 'follow_story' || $type == 'Unfollow') {
        
    } else {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "Type is not valid it shoud be either follow_story or Unfollow";
        $message_array['data'] = array();
    }

    // check args
    if ($args != '0') {
        $jsondata = follow_topic_data_responce($user_id, $author_id, $type);
    } else {
        $jsondata = $message_array;
    }

    return $jsondata;
}

/**
 * Call back function for follow_topic_list API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_user_follow_topic_list($token) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    // user name of the logend in user
    $user_name = $params['user_id'];
    $user_load = user_load_by_name($user_name);
    $user_id = $user_load->uid;
    $authtoken_id = $params['authtoken_id'];


    $message_array = array();

    $args = '0';
    if ($user_id != '0' && isset($authtoken_id)) {
        $args = '1';
    } else {
        $message_array['status_code'] = '0';
        $message_array['status_message'] = "Argument are missing";
        $message_array['data'] = array();
    }

    if ($user_id == '') {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "User does not exist";
        $message_array['data'] = array();
    }

    if (!drupal_valid_token($authtoken_id, 'services')) {
        $args = '0';
        $message_array['status_code'] = "0";
        $message_array['status_message'] = "invalid token";
        $message_array['data'] = array();
    }
    // check args
    if ($args != '0') {
        $jsondata = list_user_follow_topic_list($user_id);
    } else {
        $jsondata = $message_array;
    }
    return $jsondata;
}

/**
 * other callback function
 */

/**
 * Call back function for testing API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_testing($token) {
    ############ code write static html start #####################
    $html_temp_top = '<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
         <meta name="viewport" content="width=device-width, minimum-scale=1, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
            <title>aaa     </title>
            <link rel="shortcut icon" href="https://www.indiatoday.in/sites/all/themes/itg/favicon.ico" type="image/vnd.microsoft.icon" />
       <link href="https://fonts.googleapis.com/css?family=Roboto" rel="stylesheet">
   <style>
*{padding:0;margin:0;}   
._it_container{width:100%;box-sizing: border-box;font-family: "Roboto", sans-serif; padding:10px;}
._it_container ._head{width:100%;margin-bottom: 10px;}
._it_container ._head h3{font-size: 18px;line-height: 22px;}
._it_container ._body{width:100%;border:1px solid #ccc;box-sizing: border-box;}
._it_container ._body ul{list-style-type: none;padding: 0;margin:0;}
._it_container ._body ul li{border-bottom: 1px solid #ccc;padding:5px;font-size: 15px;line-height: 18px;}
._it_container ._body ul li ._contmain{}
._it_container ._body ul li ._contmain ._leftImg{width: auto; float: left;margin-right: 10px;}
._it_container ._body ul li ._contmain ._leftImg img{width:88px;height:50px;}
._it_container ._body ul li ._contmain ._leftImg a{outline: none;}
._it_container ._body ul li ._contmain ._rightText{display: table;}
._it_container ._body ul li ._contmain ._rightText a{outline: none;text-decoration: none;color:#323232;}
._clr{clear: both;}
</style>             
    </head>
    <body>
       
<div class="_it_container">
<div class="_head">
	<h3>Latest from India Today</h3>
</div>
<div class="_body">
	<ul id="_fetchData">';
    $html_temp_content = "";
    $html_temp_footer = "</ul></div></div></body></html>";
    $output = "";
    global $base_url;
    $data = array();
    $rand = rand();
    $prod_url =  "https://appfeeds.intoday.in";   
    $url = $prod_url . "/appapi/topstories/" . $rand;
    $contents = file_get_contents($url);
    $contents_ar = json_decode($contents);
    $data = $contents_ar->data;
    $l_cont = 1;
    foreach ($data as $key => $value) {
        $n_share_link = $value->n_share_link;
        $n_small_image = $value->n_small_image;
        $n_title = $value->n_title;
        $html_temp_content .= '<li><div class="_contmain"><div class="_leftImg"><a href="' . $n_share_link . '" title="' . $n_title . '" target="_blank"><img src="' . $n_small_image . '" alt=""></a></div><div class="_rightText"><a href="' . $n_share_link . '" title="' . $n_title . '" target="_blank">' . $n_title . '</a></div><div class="_clr"></div></div></li>';
        if ($l_cont >= 5) {
            break;
        }
        $l_cont++;
    }
    $return_flag = "";
    $output = $html_temp_top . $html_temp_content . $html_temp_footer;
    $term_feed_path = "public://topstories_chunk";
    file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
    $file_name1 = "it_thelallantop.html";
    $file_name2 = "it_ichowk.html";
    $file_name3 = "it_dailyo.html";
    $return_flag .= "<br>" . writeFeedFile($term_feed_path, $file_name1, $output);
    $return_flag .= "<br>" . writeFeedFile($term_feed_path, $file_name2, $output);
    $return_flag .= "<br>" . writeFeedFile($term_feed_path, $file_name3, $output);
    print $return_flag;
    ############ code write static html end #####################
    die();
}

/**
 * Helper function
 */
/*
 * Common function for checking poll is open or close
 * @param $poll_id
 * return 0|1 , if return 0 then poll is closed , if return 1 then poll is open , 
 */
function check_poll_status($poll_id) {

    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');
    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ed', array('field_poll_end_date_value'));
    $query->condition('n.type', 'poll');
    $query->condition('st.field_poll_start_date_value', $current_time, '<');
    $query->condition('n.status', '1');
    $query->condition('n.nid', $poll_id);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $poll_status = '0';
    foreach ($result as $k => $res) {
        if ($res['field_poll_end_date_value'] != '' && $res['field_poll_end_date_value'] > $current_time) {
            $poll_status = '1';
        } elseif ($res['field_poll_end_date_value'] == '') {
            $poll_status = '1';
        }
    }

    return $poll_status;
}

/**
 * Returns poll detail in an array based on poll id args
 *
 * @param poll_id
 *
 * @return array
 * 	array of open polls.
 */
function poll_detail($token, $poll_id) {
    $poll_id = $_GET['poll_id'];
    $redis_key = "itg_rapid_poll_details_" . $poll_id;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = poll_detail_data($poll_id);
        $jsondata = json_encode($jsondata);
        if(variable_get('poll_detail_ttl')){
            $ttl = variable_get('poll_detail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Helper function to get_personalization_saved_value.
 *
 * @param int $tid, $uid
 *
 * @return array
 */
function itg_rapid_api_get_personalization_saved_value($tid, $uid) {
    $query = db_select('itg_widget_order', 'iwo');
    $query->addField('iwo', 'weight');
    $query->condition('iwo.nid', $tid);
    $query->condition('iwo.extra', $uid);
    return $query->execute()->fetch();
}

/**
 * Helper function to save_itg_widget_personalization_data.
 *
 * @param int $updates, $user_id
 *
 * @return array
 */
function rapid_save_itg_widget_personalization_data($updates, $user_id) {

    $widget_name = "personalization_widget";
    $responce = FALSE;
    $nids = array_keys($updates);

    // Update the weight of tids if exists or insert if dont exists.
    foreach ($updates as $term_id => $weight) {
        $qry = db_merge('itg_widget_order')->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user_id))->fields(array(
                    'nid' => $term_id,
                    'widget' => $widget_name,
                    'weight' => $weight,
                    'extra' => $user_id,
                ))->execute();
        if ($qry) {
            $responce = TRUE;
        } else {
            $responce = FALSE;
        }
    }

    return $responce;
}

/**
 * Helper function to update_preference.
 *
 * @param int $user_id, $tid
 *
 * @return array
 */
function update_preference($user_id, $tid) {
    global $user;
    $widget_name = "personalization_widget";

    $nids = array_keys($updates);
    // Delete all the tids from table if they are not in $updates variable
    // unsued tid should be delete
    db_delete('itg_widget_order')->condition('widget', $widget_name)->condition('nid', $nids, "NOT IN")->condition('extra', $user->uid)->execute();
    // Update the weight of tids if exists or insert if dont exists.
    foreach ($updates as $term_id => $weight) {
        db_merge('itg_widget_order')->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user->uid))->fields(array(
            'nid' => $term_id,
            'widget' => $widget_name,
            'weight' => $weight,
            'extra' => $user->uid,
        ))->execute();
    }
    drupal_set_message(t("My Preferences Has Been Save."));
}

/**
 * Returns Anchor user detail in an array based on anchor id args
 *
 * @param anchor_id
 *
 * @return array
 * 	array of Anchor detail fields.
 */
function anchor_detail($token, $anchor_id) {

    $anchor_id = $_GET['anchor_id'];
    $redis_key = "itg_rapid_api_anchor_" . $anchor_id . "_detail";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = anchor_detail_data($anchor_id);
        $jsondata = json_encode($jsondata);
        if(variable_get('anchor_detail_ttl')){
            $ttl = variable_get('anchor_detail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Returns all the programm which is filled by particular anchor.
 *
 * @param string $token
 * @param int $anchor_id
 * @param string $type
 *
 * @return array
 */
function anchor_programm_list($token, $anchor_id, $type) {
    $anchor_id = $_GET['anchor_id'];
    $story_type = $_GET['type'];
    $cpageno = $_GET['cpageno'];

    if (!is_numeric($anchor_id)) {
        $id = 0;
    }
    if (!is_numeric($cpageno)) {
        $cpageno = 0;
    }

    // call function for return data..
    if ($_GET['type'] == '0') {
        $redis_type = 'latest';
        $type = '0';
    } elseif ($_GET['type'] == '1') {
        $redis_type = 'popular';
        $type = '1';
    } else {
        $type = '';
    }
    $suffix = $anchor_id . '_' . $cpageno;
    $redis_key = "itg_rapid_api_anchor_" . $redis_type . "_programmlist" . $suffix;

    $result_get = getRedis($redis_key);
    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = anchor_programm_data_list($anchor_id, $type, $cpageno);
        $jsondata = json_encode($jsondata);
        if(variable_get('anchor_programm_list_ttl')){
            $ttl = variable_get('anchor_programm_list_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Helper function to get previous insert record.
 *
 * @param int $uid
 *
 * @return array
 */
function list_anchor_data_responce($uid) {
    $data = '';
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        $cond = array('uid' => $uid);
        $cursor = $people->find($cond);
        $loopc = 0;
        $anchor_list = array();
        $anchor_data = array();
        foreach ($cursor as $document) {


            if ($document['ntype'] == "anchor" && $document['status'] == 1) {
                $node_data = node_load($document['nid']);
                $a_id = $node_data->nid;
                $a_title = $node_data->title;
                $a_profile_image_fid = $node_data->field_story_extra_large_image['und'][0]['fid'];
                $a_profile_image = completeFilePath($a_profile_image_fid);
                $a_follower_count = get_follower_count($a_id);

                $anchor_list[$loopc]['a_id'] = "$a_id";
                $anchor_list[$loopc]['a_title'] = "$a_title";
                $anchor_list[$loopc]['a_profile_image'] = "$a_profile_image";
                $anchor_list[$loopc]['a_follower_count'] = "$a_follower_count";
                $loopc++;
            }
        }
    }

    $anchor_data['anchor'] = $anchor_list;
    if ($loopc > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * Helper function to get previous insert record.
 *
 * @param int $uid
 *
 * @return array
 */
function list_author_data_responce($uid) {
    $data = '';
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        $cond = array('uid' => $uid);
        $cursor = $people->find($cond);
        $loopc = 0;
        $anchor_list = array();
        $anchor_data = array();
        foreach ($cursor as $document) {
            if ($document['ntype'] == "author" && $document['status'] == 1) {
                $node_data = node_load($document['nid']);
                $a_id = $node_data->nid;
                $a_title = $node_data->title;
                $a_profile_image_fid = $node_data->field_story_extra_large_image['und'][0]['fid'];
                $a_profile_image = completeFilePath($a_profile_image_fid);
                $a_follower_count = get_follower_count($a_id);

                $anchor_list[$loopc]['a_id'] = "$a_id";
                $anchor_list[$loopc]['a_title'] = "$a_title";
                $anchor_list[$loopc]['a_profile_image'] = "$a_profile_image";
                $anchor_list[$loopc]['a_follower_count'] = "$a_follower_count";
                $loopc++;
            }
        }
    }
    $anchor_data['author'] = $anchor_list;

    if ($loopc > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * Helper function to get follower_count.
 *
 * @param int $a_id
 *
 * @return int $count
 */
function get_follower_count($a_id) {
    $count = 0;
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        $cond = array('nid' => $a_id);
        $cursor = $people->find($cond);
        $loopc = 0;
        foreach ($cursor as $document) {
            if ($document['status'] == 1) {
                $count++;
            }
        }
    }
    return $count;
}

/**
 * Helper function to get previous insert record.
 *
 * @param int $uid
 *
 * @return array
 */
function list_itg_rapid_api_author_list($uid, $cpageno) {
    $data = '';
    $anchor_list = array();
    $anchor_data = array();
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        $cond = array('uid' => $uid);
        $cursor = $people->find($cond);
        $loopc = 0;
        foreach ($cursor as $document) {

            if ($document['status'] == 1 && $document['ntype'] == 'author') {
                $node_data = node_load($document['nid']);
                $a_id = $node_data->nid;
                $a_title = $node_data->title;
                $a_profile_image_fid = $node_data->field_story_extra_large_image['und'][0]['fid'];
                $a_profile_image = completeFilePath($a_profile_image_fid);
                $a_follower_count = get_follower_count($a_id);

                $anchor_list[$loopc]['a_id'] = "$a_id";
                $anchor_list[$loopc]['a_title'] = "$a_title";
                $anchor_list[$loopc]['a_profile_image'] = "$a_profile_image";
                $anchor_list[$loopc]['a_follower_count'] = "$a_follower_count";
                $loopc++;
            }
        }
    }


    $anchor_data['id'] = "$uid";
    $anchor_data['title'] = "Authors";
    $anchor_data['author_count'] = "$loopc";
    $anchor_data['author_display_count'] = "25";
    $anchor_data['author_pagination_cap'] = "25";

    $anchor_data['author'] = $anchor_list;

    if ($loopc > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * function check user status
 *
 * @param int $uid
 * @param string $ntype
 * @param int $nid
 *
 * @return int
 */
function itg_rapid_api_get_user_status($uid, $ntype, $nid) {
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        if (!empty($uid)) {
            $cond = array('uid' => $uid, 'ntype' => $ntype, 'nid' => $nid);
            $cursor = $people->findOne($cond);
            return $cursor['status'];
        }
    }
}

/**
 * Helper function to get previous insert record.
 *
 * @param int $uid, $cpageno, $showall
 *
 * @return array
 */
function list_itg_rapid_api_anchor_list($uid, $cpageno, $showall) {
    $data = '';
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        if ($showall == 1) {
            $cond = array('uid' => $uid, 'ntype' => 'anchor', 'status' => '1');
            $cursor = $people->find($cond);
        } else {
            $cond = array('ntype' => 'anchor');
            $cursor = $people->find($cond);
        }

        $loopc = 0;
        $anchor_c = 0;
        $anchor_list = array();
        $anchor_data = array();
        $anchor_list_dump = array();

        foreach ($cursor as $document) {
            $node_data = node_load($document['nid']);

            $a_id = $node_data->nid;
            $a_title = $node_data->title;
            $a_profile_image_fid = $node_data->field_story_extra_large_image['und'][0]['fid'];
            $a_is_following = '0';
            if (!empty($uid)) {
                $user_status = itg_rapid_api_get_user_status($uid, 'anchor', $document['nid']);
                $a_is_following = !empty($user_status) ? $user_status : '0';
            }
            $a_profile_image = completeFilePath($a_profile_image_fid);
            $a_follower_count = get_follower_count($a_id);
            $a_twitter_handler = $node_data->field_reporter_twitter_handle['und'][0]['value'];
            $a_location = "";
            $a_desc = $node_data->body['und'][0]['value'];

            $dup_flag = 0;
            $dup_flag = searchIn2DArray($a_id, $anchor_list_dump);
            if ($dup_flag == 2) {

                $anchor_list[$anchor_c]['a_id'] = "$a_id";
                $anchor_list[$anchor_c]['a_title'] = "$a_title";
                $anchor_list[$anchor_c]['a_profile_image'] = "$a_profile_image";
                $anchor_list[$anchor_c]['a_is_following'] = "$a_is_following";
                $anchor_list[$anchor_c]['a_follower_count'] = "$a_follower_count";
                $anchor_list[$anchor_c]['a_twitter_handler'] = "$a_twitter_handler";
                $anchor_list[$anchor_c]['a_location'] = "";
                $anchor_list[$anchor_c]['a_desc'] = "$a_desc";

                $anchor_list_dump[]['a_id'] = $a_id;
                $anchor_c++;
            }

            // }
        }
    }

    $anchor_data['id'] = "$uid";
    $anchor_data['display_label'] = "Anchors";
    $anchor_data['anchor_count'] = "$anchor_c";
    $anchor_data['anchor_display_count'] = "50";
    $anchor_data['anchor_pagination_cap'] = "50";

    //$anchor_list = removeduplicatefrommiltiD($anchor_list);
    $anchor_data['anchor'] = $anchor_list;
    //$anchor_data = array_unique($anchor_data);


    if ($anchor_c > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * Helper function to follow_topic_data_responce.
 *
 * @param int $user_id, $author_id
 * @param string $type
 *
 * @return array
 */
function follow_topic_data_responce($user_id, $author_id, $type) {
    // variable decalartion

    $data = array();
    $output_array = array();
    $data_array = array();
    $updated_datetime = "";
    $ntype = 'tag';
    $dtag = 'tag';
    $activity = "follow_tags";
    if ($type == 'follow_story') {
        $dstatus = '1';
    } elseif ($type == 'Unfollow') {
        $dstatus = '0';
    }

    $activity_date = date('d-m-Y');
    $activity_date_time = date('d-m-Y h:i:s');


    if (function_exists('mongodb')) {
        $con = mongodb();
        if ($con) {
            $people = $con->front_user_activity;
            $get_previous_info = itg_get_front_activity_info($author_id, $ntype, $user_id, $activity, '');
            if (empty($get_previous_info['nid'])) {
                if ($dtag == 'tag') {
                    $term = taxonomy_term_load($author_id);
                    $actual_title = $term->name;
                    $primary_cat_id = '';
                    $primary_cat_name = '';
                    $extra_image = NULL;
                    $path = '';
                } else {
                    $actual_data = node_load($author_id);
                    $actual_title = $actual_data->title;
                    $primary_cat_id = $actual_data->field_primary_category[LANGUAGE_NONE][0]['value'];
                    $primary_cat_name = taxonomy_term_load($actual_data->field_primary_category[LANGUAGE_NONE][0]['value']);
                    $extra_image = $actual_data->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $path = $actual_data->path['source'];
                }

                $qry = array("nid" => $author_id, "uid" => $user_id, "title" => $actual_title, "path" => $path, "image" => $extra_image, "primary_category_id" => $primary_cat_id, "primary_category_name" => $primary_cat_name->name, "ntype" => $ntype, "activity" => $activity, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "status" => $dstatus, "timestamp" => time());
                $result = $people->insert($qry);
                $response = array('success' => $dstatus, 'activity' => $user_activity, 'type' => $ntype);
            } else {
                $newdata = array('$set' => array("status" => $dstatus, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "timestamp" => time()));
                $people->update(array("nid" => $author_id, "activity" => $activity, "uid" => $user_id), $newdata);
                $response = array("success" => $dstatus, 'activity' => $activity, 'type' => $ntype);
            }
        }
    }

    if (!empty($response)) {
        $data['id'] = $author_id;
        //$response['success'];
        $data['is_saved'] = 1;
        $data['limit_crossed'] = '0';
    }

    if (!empty($response)) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $data;
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * Helper function to get previous insert record.
 *
 * @param int $uid
 *
 * @return array
 */
function list_user_follow_topic_list($uid) {
    $data = '';
    if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->front_user_activity;
        $cond = array('uid' => $uid, 'ntype' => 'tag', 'status' => '1');
        $cursor = $people->find($cond);
        $loopc = 0;

        foreach ($cursor as $document) {

            //  if($document['ntype'] == "tag" && $document['status'] == 1){
            $topic_follow_count = get_follower_count($document['nid']);
            $data[$loopc]['id'] = $document['nid'];
            $data[$loopc]['title'] = $document['title'];
            $data[$loopc]['topic_follow_count'] = "$topic_follow_count";
            $loopc++;
            //  }
        }
    }
    $anchor_data['topic'] = $data;

    if ($loopc > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}

/**
 * Helper function to removeduplicatefrommiltiD.
 *
 * @param array
 *
 * @return array
 */
function removeduplicatefrommiltiD($array) {
    // create copy to delete dups from
    $copy = $array;
    // used emails
    $usedEmails = array();

    for ($i = 0; $i < count($array); $i++) {
        if (in_array($array[$i][2], $usedEmails)) {
            unset($copy[$i]);
        } else {
            $usedEmails[] = $array[$i][2];
        }
    }

    return $copy;
}

/**
 * Helper function to searchIn2DArray.
 *
 * @param int $id
 * @param array
 *
 * @return int
 */
function searchIn2DArray($id, $array) {
    foreach ($array as $key => $val) {
        if ($val['a_id'] === $id) {
            return 1;
        }
    }
    return 2;
}

/**
 * Helper function to tokenValidator.
 *
 * @param string $uname, $token
 *
 * @return int
 */
function tokenValidator($uname, $token) {
    $user_load = user_load_by_name($uname);
    $uid = $user_load->uid;
    $query = db_select('itg_app_device', 'app');
    $query->fields('app', array('uid'));
    $query->condition('app.uid', $uid);
    $query->condition('app.token', $token);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    if ($result[0]['uid'] == $uid) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Helper function to get_personalization_saved_value.
 *
 * @param string $uname, $token
 */
function resetToken($uname, $token) {
    $time_now = time();
    if ($uname) {
        $user_load = user_load_by_name($uname);
        $uid = $user_load->uid;
        db_update('itg_app_device')->expression('token', 'token + :token', array(':token' => $time_now))->condition('uid', $uid)->condition('token', $token)->execute();
    }
    return $cook_val;
}

/**
 * Helper function to get cookie value
 *
 * @return array
 */
function getSmlCookie() {
    $cook_val = array();
    foreach ($_COOKIE as $key => $value) {
        $cook_val['session_id'] = $key;
        $cook_val['session_name'] = $value;
    }
    return $cook_val;
}

/* Change request */

/**
 * Call back function for programdetail API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_programdetail($token) {
    //valid id
    $id = $_GET['id'];
    $suffix = $id;
    if (!is_numeric($id)) {
        $id = 0;
    }

    $redis_key = "itg_rapid_api_programdetail_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = generateProgramDetail($id);
        $jsondata = json_encode($jsondata);
        if(variable_get('programdetail_ttl')){
            $ttl = variable_get('programdetail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }
    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for videodetail API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_videodetail($token) {
    //valid id
    $id = $_GET['id'];
    $suffix = $id;
    if (!is_numeric($id)) {
        $id = 0;
    }

    $redis_key = "itg_rapid_api_videodetail_" . $suffix;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = generateVideoDetail($id);
        $jsondata = json_encode($jsondata);
        if(variable_get('videodetail_ttl')){
            $ttl = variable_get('videodetail_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }
    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for topstories API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_topstories($token) {
    //valid id
    $id = $_GET['id'];
    $suffix = $id;
    if (!is_numeric($id)) {
        $id = 0;
    }

    $redis_key = "itg_rapid_api_topstories";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = topstoriesList();
        $jsondata = json_encode($jsondata);
        if(variable_get('topstories_ttl')){
            $ttl = variable_get('topstories_ttl');
        }else{
            $ttl = variable_get('default_ttl');
        }
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }
    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}

/**
 * Call back function for Social Share API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */
function social_share_save_it_detail($website_id, $content_id, $content_type, $args) {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);

    $website_id = $params['website_id'];
    $content_id = $params['content_id'];
    $content_type = $params['content_type'];
    $content_title = $params['content_title'];
    $content_url = $params['content_url'];
    $category = $params['category'];
    $share_status = $params['share_status'];
    $share_comment = $params['share_comment'];
    $message = '';

    if ($website_id == '' || $content_id == '') {
        echo "Please pass the website_id & content_id properly";
        exit;
    }

    $query = db_select('jos_social_media_sharing', 'sm');
    $query->fields('sm', array('id'));
    $query->condition('sm.content_type', $content_type);
    $query->condition('sm.content_id', $content_id);
    $result_id = $query->execute()->fetchField();

    $current_time = date('Y-m-d H:i:s');
    if ($result_id == '') {
        //Insert the value
        $content_title = addslashes($content_title);
        $category = addslashes($category);
        $share_comment = addslashes($share_comment);
        $query = db_insert('jos_social_media_sharing')
                        ->fields(array(
                            'content_id' => isset($content_id) ? $content_id : '',
                            'website_id' => isset($website_id) ? $website_id : '',
                            'content_type' => isset($content_type) ? $content_type : '',
                            'content_title' => isset($content_title) ? $content_title : '',
                            'content_url' => isset($content_url) ? $content_url : '',
                            'category' => isset($category) ? $category : '',
                            'is_promoted' => isset($share_status) ? $share_status : '',
                            'promotion_remark' => isset($share_comment) ? $share_comment : '',
                            'promotion_datetime' => $current_time,
                            'created_datetime' => $current_time,
                        ))->execute();

        $message = 'Data has been Inserted successfully';
    } else {
        //Update the value
        $content_title = addslashes($content_title);
        $category = addslashes($category);
        $share_comment = addslashes($share_comment);
        $query = db_update('jos_social_media_sharing')
                        ->fields(array(
                            'content_id' => $content_id,
                            'content_type' => $content_type,
                            'content_title' => $content_title,
                            'content_url' => $content_url,
                            'category' => $category,
                            'is_promoted' => $share_status,
                            'promotion_remark' => $share_comment,
                            'promotion_datetime' => date('Y-m-d H:i:s'),
                        ))->condition('id', $result_id)->execute();
        if ($query) {
            $message = 'Data has been updated successfully';
        }
    }
    echo $message;
    drupal_exit();
}
/**
 * Call back function for aboutus API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_aboutus($token){
    $jsondata = '{  
    "status_code": "1",
    "status_message": "",
    "data": {  
        "id": "1",
        "title": "About Us",
        "website": "India Today",
        "thumb_image": "",
        "short_desc": "",
        "description": "<p>India Today was launched in 1975. And in just a few years, it became the leading news magazine in the country. Now, with editions in five languages, it is the most widely-read publication in India-a position it has held for over a decade-with a readership of over 11 million (Source: IRS)</p><p>At present, India Today is published in Hindi, Tamil, Telugu and Malayalam. These editions deliver the same credibility, incisiveness and authority to our readers, that has become the hallmark of India Today. To keep pace with the diversifying interests of its affluent readers, the India Today Group has added 5 magazines to its value proposition - Simply, Aspire, Woman, Spice & Home.</p><p>In its online avatar, www.indiatoday.in brings you a daily connect with India\'s leading news magazine through special articles, blogs, columns, breaking news coverage and more. Also available on mobile handsets at m.indiatoday.in. The India Today Magazine is also available digitally across devices like the Kindle, iPad, Smartphones, Mac, Personal Computers,Windows phone and other tablets.</p>",
        "web_url": "http://indiatoday.intoday.in"
    }
}';
    $jsondata = json_decode($jsondata, TRUE);
    return $jsondata;
}
/**
 * Helper function to list_itg_rapid_api_anchor_list_default. 
 *
 * @return array
 */
function list_itg_rapid_api_anchor_list_default() {
    $data = array();
    $loopc = 0;
    $anchor_c = 0;
    $anchor_list = array();
    $anchor_data = array();
    $anchor_list_dump = array();
    $query = db_select('itg_widget_order', 'iwo');
    $query->Join('field_data_field_celebrity_pro_occupation', 'fco', 'iwo.nid=fco.entity_id');
    $query->fields('iwo', array('nid'));
    $query->condition('iwo.widget', 'anchors_listing_widget');
    $query->condition('fco.field_celebrity_pro_occupation_tid', 285903);
    $query->orderBy('iwo.weight', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);  
    foreach ($result as $reskey => $resvalue) {
        $node_data = node_load($resvalue['nid']);
        $a_id = $node_data->nid;
        $a_title = $node_data->title;
        $a_profile_image_fid = $node_data->field_story_extra_large_image['und'][0]['fid'];
        $a_is_following = '0';
        if (!empty($uid)) {
            $user_status = itg_rapid_api_get_user_status($uid, 'anchor', $document['nid']);
            $a_is_following = !empty($user_status) ? $user_status : '0';
        }
        $a_profile_image = completeFilePath($a_profile_image_fid);
        $a_follower_count = get_follower_count($a_id);
        $a_twitter_handler = $node_data->field_reporter_twitter_handle['und'][0]['value'];
        $a_location = "";
        $a_desc = $node_data->body['und'][0]['value'];
        $anchor_list[$anchor_c]['a_id'] = "$a_id";
        $anchor_list[$anchor_c]['a_title'] = "$a_title";
        $anchor_list[$anchor_c]['a_profile_image'] = "$a_profile_image";
        $anchor_list[$anchor_c]['a_is_following'] = "$a_is_following";
        $anchor_list[$anchor_c]['a_follower_count'] = "$a_follower_count";
        $anchor_list[$anchor_c]['a_twitter_handler'] = "$a_twitter_handler";
        $anchor_list[$anchor_c]['a_location'] = "";
        $anchor_list[$anchor_c]['a_desc'] = "$a_desc";
        $anchor_c++;
    }


    $anchor_data['id'] = "";
    $anchor_data['display_label'] = "Anchors";
    $anchor_data['anchor_count'] = "$anchor_c";
    $anchor_data['anchor_display_count'] = "50";
    $anchor_data['anchor_pagination_cap'] = "50";

    //$anchor_list = removeduplicatefrommiltiD($anchor_list);
    $anchor_data['anchor'] = $anchor_list;
    //$anchor_data = array_unique($anchor_data);


    if ($anchor_c > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
        $output_array['data'] = $anchor_data;
    } else {
        $data = array();
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
        $output_array['data'] = $data;
    }
    return $output_array;
}
