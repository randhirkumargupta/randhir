<?php

function itg_rapid_api_resource() {
    /**
     * custom resource for sprit1
     */
    $api = array(
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                            'source' => array('path' => 0),
                            'optional' => TRUE,
                            'default' => '*',
                        ),
                    ),
                ),
            ),
        ),
        // livetv_json custom resource declaration.....
        'livetv' => array(
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
        'homePage' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
        // login_request custom resource declaration.....
        'login_request' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_login_request',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'user email or mobile',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'password',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'password'),
                            'description' => 'user password',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'login_type',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'login_type'),
                            'description' => 'is_first_login (with value 0 or 1) ',
                            'type' => 'int',
                        ),
                        array(
                            'name' => 'token_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'token_id'),
                            'description' => 'Here token_id is social media token id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // signup custom resource declaration.....
        'signup' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves storydetail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_signup',
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
                            'name' => 'first_name',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'First Name',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'last_name',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'last_name'),
                            'description' => 'Last Name',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'User email or mobile number',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'password',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'password'),
                            'description' => 'Password',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'login_type',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'login_type'),
                            'description' => '0=for traditional, 1=socail media',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'token_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'token_id'),
                            'description' => 'Social Media token_id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // fblogin custom resource declaration.....
        'fblogin' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves fblogin schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_fblogin',
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
                            'name' => 'app_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'application master id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'uname',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'password'),
                            'description' => 'username (in socail login)',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'uid',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'login_type'),
                            'description' => 'uid (in socail login)',
                            'type' => 'int',
                        ),
                        array(
                            'name' => 'issued_at',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'token_id'),
                            'description' => 'in timestamp',
                            'type' => 'int',
                        ),
                        array(
                            'name' => 'expires_at',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'token_id'),
                            'description' => 'in timestamp',
                            'type' => 'int',
                        ),
                    ),
                ),
            ),
        ),
        // twtlogin custom resource declaration.....
        'twtlogin' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves twtlogin schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_twtlogin',
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
                            'name' => 'app_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'application master id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'uname',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'password'),
                            'description' => 'username (in socail login)',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'uid',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'login_type'),
                            'description' => 'uid (in socail login)',
                            'type' => 'int',
                        ),
                        array(
                            'name' => 'issued_at',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'token_id'),
                            'description' => 'in timestamp',
                            'type' => 'int',
                        ),
                        array(
                            'name' => 'expires_at',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'token_id'),
                            'description' => 'in timestamp',
                            'type' => 'int',
                        ),
                    ),
                ),
            ),
        ),
        // forgot_password custom resource declaration.....
        'forgot_password' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves forgot_password schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_forgot_password',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'user mobile or email',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // otp_verification custom resource declaration.....
        'otp_verification' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves otp_verification schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_otp_verification',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'user mobile or email',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'otp_code',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'otp_code',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // resend_otp custom resource declaration.....
        'resend_otp' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves resend_otp schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_resend_otp',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'user mobile or email',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // change_password custom resource declaration.....
        'change_password' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves change_password schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_change_password',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'user mobile or email',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'pass',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'password',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'pass2',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'confirm password',
                            'type' => 'string',
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                'retrieve' => array(
                    'help' => 'Retrieves cast_polls schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_poll_cast',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'user mobile or email',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'otp_code',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'user_id'),
                            'description' => 'otp_code',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // edit_profile custom resource declaration.....
        'edit_profile' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves edit_profile schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_edit_profile',
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
                            'name' => 'authtoken_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'authtoken_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'user_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'first_name',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'first_name',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'last_name',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'last_name',
                            'type' => 'string',
                        ),
//                        array(
//                            'name' => 'email_id',
//                            'optional' => FALSE,
//                            'source' => 'data',
//                            //'source' => array('data' => 'first_name'),
//                            'description' => 'email_id',
//                            'type' => 'string',
//                        ),
//                        array(
//                            'name' => 'phone_number',
//                            'optional' => FALSE,
//                            'source' => 'data',
//                            //'source' => array('data' => 'first_name'),
//                            'description' => 'phone_number',
//                            'type' => 'string',
//                        ),
                        array(
                            'name' => 'country',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'country',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'state',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'state',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'city',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'city',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'zipcode',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'zipcode',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'address',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'address',
                            'type' => 'string',
                        ),
//                        array(
//                            'name' => 'profile_image',
//                            'optional' => FALSE,
//                            'source' => 'data',
//                            //'source' => array('data' => 'first_name'),
//                            'description' => 'profile_image',
//                            'type' => 'string',
//                        ),
                        array(
                            'name' => 'gender',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'gender',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'date_of_birth',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'date_of_birth',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // edit_user_image custom resource declaration.....
        'edit_user_image' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves edit_user_image schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_edit_user_image',
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
                            'name' => 'authtoken_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'authtoken_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'user_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'profile_image',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'profile_image',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // get_login_user_detail custom resource declaration.....
        'get_login_user_detail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves get_login_user_detail schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_get_login_user_detail',
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
                            'name' => 'authtoken_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'authtoken_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'user_id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // get_login_user_detail custom resource declaration.....
        'log_out' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves log_out schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_log_out',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'user_id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // get_preference custom resource declaration.....
        'get_preference' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves get_preference schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_get_preference',
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
                            'name' => 'authtoken_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'authtoken_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'user_id',
                            'type' => 'string',
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'itg_rapid_api_update_preference',
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
                            'name' => 'authtoken_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'authtoken_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'user_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'node_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'node_id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'value',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'value',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // Sprint 4 Read Later
        'bookmark_get' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Bookmark Get Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'bookmark_get_responce',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Loged in user id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // Sprint 4 Read Later
        'bookmark_set' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Bookmark Set and return Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'bookmark_set_responce',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Loged in user id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'node_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Node id of the stories',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        // Sprint 4 Read Later
        'bookmark_delete' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Bookmark delete and return Responce based on userid.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
                    ),
                    'callback' => 'bookmark_delete_responce',
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
                            'name' => 'user_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Loged in user id',
                            'type' => 'string',
                        ),
                        array(
                            'name' => 'node_id',
                            'optional' => FALSE,
                            'source' => 'data',
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Node id of the stories',
                            'type' => 'string',
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
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Author id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        //sprint 4 anchor detail
        'anchor_detail' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves Anchor detail data based on Anchor id in the system.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
                            //'source' => array('data' => 'first_name'),
                            'description' => 'Anchor User id',
                            'type' => 'string',
                        ),
                    ),
                ),
            ),
        ),
        //sprint 4 Newswrap (Briefly.json)
        'newswrap' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves last stories which have heightights',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
        // sprint 3 : Anchor Programm list
        'anchor_programm_list' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieves programm list of a particular anchor.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_rapid_api',
                        'name' => 'itg_rapid_api.services',
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
 * 	The node processed information array.
 */
//return services_error(t('Node type cannot be changed'), 406);
function itg_rapid_api_datanotexist_api($token) {
    $get_token = variable_get('mobile_service_token');
    if ($get_token != $token) {
        return services_error(t('Please enter valid token'), 406);
    } else {

        $redis_key = "itgd_rapid_datanotexist_api_json";
        $result_get = getRedis($redis_key);

        if ($result_get['key_value'] != "") {
            $jsondata = $result_get['key_value'];
        } else {
            $jsondata = variable_get('datanotexist_api_json');
            $ttl = DEFAULT_REDIS_EXPIRE_TIME;
            $result_set = setRedis($redis_key, $jsondata, $ttl);
        }


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
 * 	The node processed information array.
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
        $ttl = RAPID_API_NEWSLIST_REDIS_EXPIRE_TIME;
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
 * [itg_rapid_api_programlist] definition.
 * Returns the information about a itg_rapid_api_programlist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_videolist] definition.
 * Returns the information about a itg_rapid_api_videolist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_photodetail] definition.
 * Returns the information about a itg_rapid_api_photodetail.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_photodetail($token) {
    //valid id
    $id = $_GET['id'];
    //$cpageno = $_GET['cpageno'];
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }
    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_photolist] definition.
 * Returns the information about a itg_rapid_api_photolist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_server_error_master] definition.
 * Returns the information about a itg_rapid_api_server_error_master.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_server_error_master($token) {
    $redis_key = "itgd_rapid_server_error_master_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('server_error_master_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_master_config] definition.
 * Returns the information about a config_update_status.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_master_config($token) {
    $redis_key = "itgd_rapid_master_config_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('master_config_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_config_update_status] definition.
 * Returns the information about a config_update_status.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_config_update_status($token) {
    $redis_key = "itgd_rapid_config_update_status_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('config_update_status_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * [itg_rapid_api_hamburger_menu] definition.
 * Returns the information about a hamburger_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_hamburger_menu($token) {
    $redis_key = "itgd_rapid_hamburger_menu_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('hamburger_menu_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * [itg_rapid_api_horizontal_menu] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_horizontal_menu($token) {
    $redis_key = "itgd_rapid_horizontal_menu_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('horizontal_menu_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * function for check valid resource & return type
 * @return $type
 */
function checkValidResource() {

    $error_flag = "";
    $flag_code = 0;
    //declare valid resource
    $valid_resurce = array('hamburger_menu');
    // declare valid operation
    $valid_operation = array('retrieve');
    // declare valid return type
    $valid_return_type = array('json', 'xml');
    //check validity
    $resource = arg(1);
    $resurce_arg = explode('.', arg(2));
    $resurce_opt = $resurce_arg[0];
    $resurce_ext = $resurce_arg[1];
    //validate resource
    if (!in_array($resource, $valid_resurce)) {
        $error_flag .= "\nInvalid resource";
        $flag_code = 1;
    }
    //validate operation
    if (!in_array($resurce_opt, $valid_operation)) {
        $error_flag .= "\nInvalid operation";
        $flag_code = 1;
    }
    //validate return type
    if (!in_array($resurce_ext, $valid_return_type)) {
        $error_flag .= "\nInvalid return type";
        $flag_code = 1;
    }

    // die if $flag_code is 1
    if ($flag_code == 1) {
        print $error_flag;
        die();
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
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_program_category_list] definition.
 * Returns the information about a itg_rapid_api_program_category_list.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_program_category_list($token) {


    $redis_key = "itg_rapid_api_program_category_list";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = programCategoryListlPageRerourceValue();
        $jsondata = json_encode($jsondata);
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_ad_config_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_ad_config_json($token) {

    $redis_key = "itg_rapid_api_ad_config_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('ad_config_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_livetv_channellist_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_livetv_channellist_json($token) {


    $redis_key = "itg_rapid_api_livetv_channellist_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_channellist_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;

    return $return_obj;
}

/**
 * [itg_rapid_api_livetv_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_livetv_json($token) {


    $redis_key = "itg_rapid_api_livetv_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('livetv_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_otherapps_ios_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_otherapps_ios_json($token) {


    $redis_key = "itg_rapid_api_otherapps_ios_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('otherapps_ios_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_otherapps_android_json] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_otherapps_android_json($token) {


    $redis_key = "itg_rapid_api_otherapps_android_json";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        $jsondata = variable_get('otherapps_android_json');
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

// magazine section start

/**
 * [itg_rapid_api_magazine_edition] definition.
 * Returns the information about a itg_rapid_api_magazine_edition.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_magazine_coverstories] definition.
 * Returns the information about a itg_rapid_api_magazine_coverstories.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

/**
 * [itg_rapid_api_magazine_editionlist] definition.
 * Returns the information about a itg_rapid_api_magazine_editionlist.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_magazine_editionlist($token) {
    $sdate = $_GET['sdate'];
    $tdate = $_GET['tdate'];
    $cpageno = $_GET['cpageno'];
    //echo $sdate; echo "<br>"; echo $tdate; exit();
    //valid tid & pageno
//    if (!is_numeric($sdate)) {
//        $sdate = 0;
//    }
//    if (!is_numeric($tdate)) {
//        $tdate = 0;
//    }
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);

    return $jsondata;
}

// magazine section end

/**
 * [itg_rapid_api_storydetail] definition.
 * Returns the information about a horizontal_menu.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * [itg_rapid_api_homePage] definition.
 * Returns the information about a itg_rapid_api_homePage.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
//return services_error(t('Node type cannot be changed'), 406);
function itg_rapid_api_homePage($token) {

    $redis_key = "itg_rapid_api_homePage";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..
        $jsondata = homePageJson();
        $jsondata = json_encode($jsondata);
        $ttl = RAPID_API_HOMEPAGE_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

function itg_rapid_api_testing($token) {
    $user = user_load(1989);
    echo "<pre>";
    print_r($user);
    echo "<pre>";
    exit();
    $get_token = variable_get('mobile_service_token');

    $str = '{
	"status_code": "0",
	"status_message": "Customised Message",
	"data": {}
}';


    $jsondata = $str;
    $obj = json_decode($jsondata, true);
    $return_obj = $obj;
    return $return_obj;
}

// login serveice function start from here

/**
 * [itg_rapid_api_login_request] definition.
 * Returns the information about a itg_rapid_api_login_request.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
//return services_error(t('Node type cannot be changed'), 406);
function itg_rapid_api_login_request_bk($token, $user_id, $password, $login_type, $token_id) {

    /* $filename = "http://localhost/decode/sprint3/login_request.json";
      $jsondata = file_get_contents($filename);
      $jsondata = json_decode($jsondata, true);
      return $jsondata; */
    //echo "<pre>"; print_r($_GET);echo "</pre>"; exit();
    $resp = array();
    $user_id = $_GET['user_id'];
    $password = $_GET['password'];
    // login sso user user
    $form_state = array();
    $form_state['values']['name'] = $user_id;
    $form_state['values']['pass'] = $password;
    $form_state['values']['op'] = t('Log in');
    $resp = drupal_form_submit('user_login_form', $form_state);
    $resp = form_get_errors();
    echo "<pre>";
    print_r($_GET);
    echo "</pre>";
    exit();
}

function itg_rapid_api_login_request($token, $user_id, $password, $login_type, $token_id) {
    $login_type = 0;
    $login_type = $_GET['login_type'];
    // for traditional login
    if ($login_type == 0) {
        $method = "GET";
        $data = $_GET;
        $account = array();
        $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/login_request";
        $result = callAPI($method, $url, $_GET);
        $result_obj = json_decode($result);
        $uid = 0;
        $uid = $result_obj->uid;
        $auth_token = $result_obj->token;
        $field_logged_in_count = $result_obj->user->field_logged_in_count->und[0]->value;
        $is_first_login = 1;
        if ($field_logged_in_count > 0) {
            $is_first_login = 0;
        }

        if ($uid) {
            $local_account = localSignup($_GET);
            //p($local_account);echo "andy";die();
            $uid = $local_account->user->uid;
            $name = $local_account->user->name;
            $is_first_login = $local_account->user->field_logged_in_count['und'][0]['value'];
            $auth_token = $local_account->token;
            if ($auth_token) {
                $account['status_code'] = "1";
                $account['status_message'] = "customised_message";
                $account['data']['user_id'] = "$name";
                $account['data']['is_first_login'] = "$is_first_login";
                $account['data']['auth_token'] = "$auth_token";
            } else {
                watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
                return services_error(t('Wrong username or password.'), 401);
            }
        } else {
            watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
            return services_error(t('Wrong username or password.'), 401);
        }

        return $account;
    }
    // for FW login
    elseif ($login_type == 1) {
        $method = "GET";

        $data = array();
        $password = rand(0, 9999);
        $_GET['password'] = $password;
        $data['token'] = $_GET['token_id'];
        $data['app_id'] = $_GET['app_id'];
        $data['uname'] = $_GET['user_id'];
        $data['uid'] = $_GET['user_id'];
        $data['issued_at'] = $_GET['issued_at'];
        $data['expires_at'] = $_GET['expires_at'];
        $data['password'] = $password;
        $account = array();
        $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/fblogin";
        $result = callAPI($method, $url, $data);
        $result_obj = json_decode($result);
        $uid = 0;
        $uid = $result_obj->user->uid;
        $auth_token = $result_obj->token;
        $field_logged_in_count = $result_obj->user->field_logged_in_count->und[0]->value;
        $is_first_login = 1;
        if ($field_logged_in_count > 0) {
            $is_first_login = 0;
        }

        if ($uid) {
            $local_account = fblogin($data);
            //p($local_account);echo "andy";die();
            $uid = $local_account->user->uid;
            $name = $local_account->user->name;
            $is_first_login = $local_account->user->field_logged_in_count['und'][0]['value'];
            $auth_token = $local_account->token;
            if ($auth_token) {
                $account['status_code'] = "1";
                $account['status_message'] = "customised_messageFB";
                $account['data']['user_id'] = "$name";
                $account['data']['is_first_login'] = "$is_first_login";
                $account['data']['auth_token'] = "$auth_token";
            } else {
                watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
                return services_error(t('Wrong username or password.'), 401);
            }
        } else {
            watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
            return services_error(t('Wrong username or passwordfb.'), 401);
        }

        return $account;
    }
    // for TWT login
    elseif ($login_type == 2) {
        $method = "GET";

        $data = array();
        $password = rand(0, 9999);
        $_GET['password'] = $password;
        $data['token'] = $_GET['token_id'];
        $data['app_id'] = $_GET['app_id'];
        $data['uname'] = $_GET['user_id'];
        $data['uid'] = $_GET['user_id'];
        $data['issued_at'] = $_GET['issued_at'];
        $data['expires_at'] = $_GET['expires_at'];
        $data['password'] = $password;
        $account = array();
        $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/fblogin";
        $result = callAPI($method, $url, $data);
        $result_obj = json_decode($result);
        $uid = 0;
        $uid = $result_obj->user->uid;
        $auth_token = $result_obj->token;
        $field_logged_in_count = $result_obj->user->field_logged_in_count->und[0]->value;
        $is_first_login = 1;
        if ($field_logged_in_count > 0) {
            $is_first_login = 0;
        }

        if ($uid) {
            $local_account = twtlogin($data);
            //p($local_account);echo "andy";die();
            $uid = $local_account->user->uid;
            $name = $local_account->user->name;
            $is_first_login = $local_account->user->field_logged_in_count['und'][0]['value'];
            $auth_token = $local_account->token;
            if ($auth_token) {
                $account['status_code'] = "1";
                $account['status_message'] = "customised_messagetwt";
                $account['data']['user_id'] = "$name";
                $account['data']['is_first_login'] = "$is_first_login";
                $account['data']['auth_token'] = "$auth_token";
            } else {
                watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
                return services_error(t('Wrong username or password.'), 401);
            }
        } else {
            watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
            return services_error(t('Wrong username or passwordtwt.'), 401);
        }

        return $account;
    }
}

//itg_rapid_api_signup
/**
 * [itg_rapid_api_signup] definition.
 * Returns the information about a itg_rapid_api_signup.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_signup($token, $first_name, $last_name, $user_id, $password, $login_type, $token_id) {
    $method = "GET";
    $data = $_GET;
    $account = array();
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/signup";
    $result = callAPI($method, $url, $data);
    $result_obj = json_decode($result);
    $uid = $result_obj->uid;
    $uname = $_GET['user_id'];

    if ($uid) {
        $account['status_code'] = "1";
        $account['status_message'] = "customised_message";
        $account['data']['user_id'] = "$uname";
        $account['data']['is_authenticated'] = "1";
        $account['data']['otp_status'] = "0";
    } else {
        watchdog('user', 'Duplicate signup attempt for %username.', array('%username' => $_GET['user_id']));
        return services_error(t('Duplicate signup attempt.'), 401);
    }

    return $account;
}

//itg_rapid_api_fblogin
/**
 * [itg_rapid_api_fblogin] definition.
 * Returns the information about a itg_rapid_api_fblogin.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_fblogin($token, $app_id, $uname, $uid, $issued_at, $expires_at) {
    //return fblogin($_GET);
    $method = "GET";

    $data = array();
    $data['token'] = $_GET['token'];
    $data['app_id'] = $_GET['app_id'];
    $data['uname'] = $_GET['uname'];
    $data['uid'] = $_GET['uid'];
    $data['issued_at'] = $_GET['issued_at'];
    $data['expires_at'] = $_GET['expires_at'];
    $account = array();
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/fblogin";
    $result = callAPI($method, $url, $data);
    $result_obj = json_decode($result);
    $uid = $result_obj->uid;
    $uname = $_GET['uname'];
    $is_authenticated = $account['status_code'] = "1";
    $account['status_message'] = "customised_message";
    $account['data']['user_id'] = "$uname";
    $account['data']['is_authenticated'] = "1";
    $account['data']['otp_status'] = "0";

    return $account;
}

//itg_rapid_api_twtlogin
/**
 * [itg_rapid_api_twtlogin] definition.
 * Returns the information about a itg_rapid_api_twtlogin.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_twtlogin($token, $app_id, $uname, $uid, $issued_at, $expires_at) {
    //return twtlogin($_GET);

    $method = "GET";

    $data = array();
    $data['token'] = $_GET['token'];
    $data['app_id'] = $_GET['app_id'];
    $data['uname'] = $_GET['uname'];
    $data['uid'] = $_GET['uid'];
    $data['issued_at'] = $_GET['issued_at'];
    $data['expires_at'] = $_GET['expires_at'];

    $account = array();
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/twtlogin";
    $result = callAPI($method, $url, $_GET);
    $result_obj = json_decode($result);
    $uid = $result_obj->uid;
    $is_authenticated = $account['status_code'] = "1";
    $uname = $_GET['uname'];
    $account['status_message'] = "customised_message";
    $account['data']['user_id'] = "$uname";
    $account['data']['is_authenticated'] = "1";
    $account['data']['otp_status'] = "0";

    return $account;
}

/**
 * [itg_rapid_api_forgot_password] definition.
 * Returns the information about a itg_rapid_api_forgot_password.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_forgot_password($token, $user_id) {

    $method = "GET";
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/forgot_password";
    $result = callAPI($method, $url, $_GET);
    $result_obj = json_decode($result);
    $data['status_code'] = "1";
    $data['status_message'] = "Please check your mobile for otp";

    return $data;
}

/**
 * [itg_rapid_api_otp_verification] definition.
 * Returns the information about a itg_rapid_api_otp_verification.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_otp_verification($token, $user_id, $otp_code) {

    $method = "GET";
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/otp_verification";
    $result = callAPI($method, $url, $_GET);
    $result_obj = json_decode($result);
    $uname = $_GET['user_id'];
    $data['status_code'] = "1";
    $data['status_message'] = "Please check your mobile for otp";
    $data['data']['user_id'] = "$uname";
    $data['data']['is_authenticated'] = "1";
    $data['data']['auth_token'] = "authToken";

    return $data;
}

/**
 * [itg_rapid_api_resend_otp] definition.
 * Returns the information about a itg_rapid_api_resend_otp.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_resend_otp($token, $user_id) {
    $method = "GET";
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/resend_otp";
    $result = callAPI($method, $url, $_GET);
    $result_obj = json_decode($result);

    $data['status_code'] = "1";
    $data['status_message'] = "Please check your mobile for otp";

    return $data;
}

/**
 * [itg_rapid_api_change_password] definition.
 * Returns the information about a itg_rapid_api_change_password.
 * @param $nid
 *   The nid of the housing_scheme node.
 * @return array
 * 	The node processed information array.
 */
function itg_rapid_api_change_password($token, $user_id) {
    $method = "GET";
    $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/change_password";
    $result = callAPI($method, $url, $_GET);
    $result_obj = json_decode($result);
    
    if($result_obj->uid){
        $local_obj = localChangePass($_GET, $result_obj->uid);
        $data['status_code'] = "1";
        $data['status_message'] = "customised_message";
    }
    else{
        $data['status_code'] = "0";
        $data['status_message'] = "custom msg";
    }

    

    return $data;
}

/**
 * [author_latest_story_list] definition.
 * Returns all the stories which is filled by particular author.
 * @param $nid
 *   The Author id
 *   Type [0/1 where 0 can be for Latest and 1 for Popular]
 * @return array
 * 	array of stories.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns all the open poll in the system
 * @param
 * @return array
 * 	array of open polls.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns all the open poll in the system
 * @param
 * @return array
 * 	array of open polls.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns all the open poll from the system
 * @param
 * @return array
 * 	array of open polls.
 */
function itg_rapid_api_poll_cast($token, $poll_id, $option_id, $user_id) {

    $poll_id = $_GET['poll_id'];
    $option_id = $_GET['option_id'];
    $user_id = $_GET['user_id'];

    $ip_address = $_SERVER['SERVER_ADDR'];
    if (strpos($_SERVER['HTTP_USER_AGENT'], "iPhone") > 0) {
        $device = 'iPhone';
    } elseif (strpos($_SERVER['HTTP_USER_AGENT'], "Android") > 0) {
        $device = 'Android';
    } elseif (strpos($_SERVER['HTTP_USER_AGENT'], "webOS") > 0) {
        $device = 'webOS';
    } elseif (strpos($_SERVER['HTTP_USER_AGENT'], "BlackBerry")) {
        $device = 'BlackBerry';
    } elseif (strpos($_SERVER['HTTP_USER_AGENT'], "iPod") > 0) {
        $device = 'iPod';
    } else {
        $device = '';
    }


    if (!is_numeric($poll_id)) {
        $poll_id = 0;
    }
    if (!is_numeric($option_id)) {
        $option_id = 0;
    }
    if (!is_numeric($user_id)) {
        $user_id = 0;
    }
    // call function from return data..
    $jsondata = poll_cast_list($poll_id, $option_id, $user_id, $ip_address, $device);
    $jsondata = json_encode($jsondata);

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns poll detail in an array based on poll id args
 * @param poll_id
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * function for itg_rapid_api_edit_profile
 * @param array
 * @return array
 *
 */
function itg_rapid_api_edit_profile($token) {
    
    
    $method = "GET";    
    $token = $_GET['authtoken_id'];    
    if (!drupal_valid_token($token, 'services')) {
        $responce_object['status_code'] = "0";
        $responce_object['status_message'] = "invalid token";
    } else {
        $url = "http://itgd-dev-sso.indiatodayonline.in/appapi/edit_profile";
        $result = callAPI($method, $url, $_GET);
        $result_obj = json_decode($result);
        //if ($result_obj->uid) {
            $responce_object = saveUpdatedProfile($_GET);
        //}
    }
    return $responce_object;
}

/**
 * function for itg_rapid_api_edit_user_image
 * @param array
 * @return array
 *
 */
function itg_rapid_api_edit_user_image($token) {
    echo "<pre>";
    print_r($_GET);
    echo "</pre>";
    exit();
}

/**
 * function for itg_rapid_api_get_login_user_detail
 * @param array
 * @return array
 *
 */
function itg_rapid_api_get_login_user_detail($token) {
    $data = array();
    $authtoken_id = $_GET['authtoken_id']; 
    $user_id = $_GET['user_id'];
    $token = $_GET['authtoken_id'];    
    if (!drupal_valid_token($token, 'services')) {
        $data['status_code'] = "0";
        $data['status_message'] = "invalid token";
    }
    else{
        $account = user_load_by_name($user_id);
        //$user_id = $account->uid;
        $first_name = $account->field_first_name['und'][0]['value'];
        $last_name = $account->field_last_name['und'][0]['value'];
        $email_id = $account->mail;
        $phone_number = $account->field_mobile_number['und'][0]['value'];
        $location = "";
        if ($account->field_personalization_city['und'][0]['value']) {
            $location .= $account->field_personalization_city['und'][0]['value'];
        }
        if ($account->field_personalization_state['und'][0]['value']) {
            $location .= ", " . $account->field_personalization_state['und'][0]['value'];
        }
        if ($account->field_user_counrty['und'][0]['value']) {
            $location .= ", " . $account->field_user_counrty['und'][0]['value'];
        }
        if ($account->field_short_description['und'][0]['value']) {
            $location .= ", " . $account->field_short_description['und'][0]['value'];
        }

        $profile_image = $account->field_user_picture['und'][0]['fid'];
        $gender = $account->field_user_gender['und'][0]['value'];
        $date_of_birth = $account->field_story_issue_date['und'][0]['value'];
        $login_type = "na";

        $data['status_code'] = "1";
        $data['status_message'] = "customised_message";

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
 * function for itg_rapid_api_log_out
 * @param array
 * @return array
 *
 */
function itg_rapid_api_log_out($token) {
    global $base_url;
    $data = array();
    $user_id = $_GET['user_id'];
    $pram = "uname=$user_id";
    $options = array(
        'method' => 'POST',
        'data' => $pram,
        'timeout' => 15,
        'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
    );
    $url = $base_url . "/user/logout";
    $result = drupal_http_request('$url', $options);
    $data['status_code'] = "1";
    $data['status_message'] = "customised_message";

    return $data;
}

/**
 * function for itg_rapid_api_get_preference
 * @param array
 * @return array
 *
 */
function itg_rapid_api_get_preference($token) {
    $user_id = $_GET['user_id'];
    $account = user_load_by_name($user_id);

    $user_id = $account->uid;
    $last_access = $account->access;
    $last_access_date = date('Y-m-d h:m:s', $last_access);
    $weight_count_loop = FALSE;
    $tid_array = array();
    $tid_value = array();
    $data = array();
    // As in table itg_widget_order tid is saved in nid colom.
    // So join field_story_category_tid join is applied on nid.
    // get personalization-preferences tid
    $query = db_select('itg_widget_order', 'iwo');
    $query->fields('iwo', array('weight', 'nid'))
            ->condition('iwo.widget', "personalization_widget")
            ->condition('iwo.extra', $user_id)
            // Orderby weight or taxonomyterm id.
            ->orderBy('iwo.weight', 'DESC')
            ->orderBy('iwo.nid', 'DESC')
            ->range(0, 30);
    $result = $query->execute()->fetchAllAssoc('nid');
    $new_array_of_terms = array_keys($result);
    // case handled if perferences is not saved.
    if (count($result) == 0) {
        $weight_count_loop = TRUE;
        $query = db_select('itg_widget_order', 'iwo');
        $query->leftJoin('field_data_field_set_as_featured_cate', 'fc', 'fc.entity_id=iwo.cat_id');
        $query->fields('iwo', array('cat_id'))
                ->condition('iwo.widget', "section_wise_widget")
                ->condition('fc.field_set_as_featured_cate_value', 'Yes')
                ->groupBy('iwo.cat_id')
                ->range(0, 30);
        $result = $query->execute()->fetchAllAssoc('cat_id');
    }
    if ($weight_count_loop) {
        $new_array_of_terms = array();
        // Get only tids.
        $tids_array = array_keys($result);
        foreach ($tids_array as $term_id) {
            $new_array_of_terms[$term_id] = count_node_under_tid($term_id);
        }
        krsort($new_array_of_terms);
    }
    $tid_array = ($weight_count_loop) ? array_keys($new_array_of_terms) : $new_array_of_terms;
    // return data of personalization-preferences value
    $data['status_code'] = "1";
    $data['status_message'] = "customised_message";
    $data['data']['updated_datetime'] = "$last_access_date";
    $data['data']['preference_type'] = "default/implicit/explicit";
    $loop_count = 0;
    //get personalization-preferences value
    foreach ($tid_array as $key => $value) {
        $prefeance = itg_rapid_api_get_personalization_saved_value($value, $user_id);
        $term = taxonomy_term_load($value);
        $term_name = $term->name;
        $data['data']['preference'][$loop_count]['id'] = "$value";
        $data['data']['preference'][$loop_count]['title'] = "$term_name";
        $data['data']['preference'][$loop_count]['is_preffered'] = "$prefeance";
        $loop_count++;
    }

    return $data;
}

/**
 *
 * @param int $tid
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
 * function for itg_rapid_api_update_preference
 * @param array
 * @return array
 *
 */
function itg_rapid_api_update_preference($token) {

    $user_id = $_POST['user_id'];
    $node_id = $_POST['node_id'];
    $new_value = $_POST['value'];
    $data = array();

    $updates = array();
    $node_value = array();
    $node_value['value'] = $new_value;
    $updates[$node_id] = $node_value;

    $status = rapid_save_itg_widget_personalization_data($updates, $user_id);
    if ($status) {
        $data['status_code'] = "1";
        $data['status_message'] = "updated value successfully";
    } else {
        $data['status_code'] = "0";
        $data['status_message'] = "Custom message";
    }
    return $data;
}

/**
 *
 * @param array $updates
 */
function rapid_save_itg_widget_personalization_data($updates, $user_id) {

    $widget_name = "personalization_widget";
    $responce = FALSE;
    $nids = array_keys($updates);
    // Delete all the tids from table if they are not in $updates variable
    // unsued tid should be delete
//  db_delete('itg_widget_order')
//      ->condition('widget', $widget_name)
//      ->condition('nid', $nids, "NOT IN")
//      ->condition('extra', $user_id)
//      ->execute();
    // Update the weight of tids if exists or insert if dont exists.
    foreach ($updates as $term_id => $weight) {
        $qry = db_merge('itg_widget_order')
                ->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user_id))
                ->fields(array(
                    'nid' => $term_id,
                    'widget' => $widget_name,
                    'weight' => $weight,
                    'extra' => $user_id,
                ))
                ->execute();
        if ($qry) {
            $responce = TRUE;
        } else {
            $responce = FALSE;
        }
    }

    return $responce;
}

/**
 *
 * @param int $tid
 * @return array
 */
function update_preference($user_id, $tid) {
    global $user;
    $widget_name = "personalization_widget";

    $nids = array_keys($updates);
    // Delete all the tids from table if they are not in $updates variable
    // unsued tid should be delete
    db_delete('itg_widget_order')
            ->condition('widget', $widget_name)
            ->condition('nid', $nids, "NOT IN")
            ->condition('extra', $user->uid)
            ->execute();
    // Update the weight of tids if exists or insert if dont exists.
    foreach ($updates as $term_id => $weight) {
        db_merge('itg_widget_order')
                ->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user->uid))
                ->fields(array(
                    'nid' => $term_id,
                    'widget' => $widget_name,
                    'weight' => $weight,
                    'extra' => $user->uid,
                ))
                ->execute();
    }
    drupal_set_message(t("My Preferences Has Been Save."));
}

/*
 * Ge All the Bookmark stories based on user id
 * @param $user_id
 * @return array of node stories
 */

function bookmark_get_responce($token, $user_id) {

    $user_id = $_GET['user_id'];
    $redis_key = "itg_rapid_get_bookmark" . $user_id . '';
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $jsondata = $result_get['key_value'];
    } else {
        // call function from return data..

        $jsondata = bookmark_responce_data($user_id);
        $jsondata = json_encode($jsondata);
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/*
 * Set bookmark stories for a specific user_id and return all
 *
 */

function bookmark_set_responce($token, $user_id, $node_id) {

    $user_id = $_GET['user_id'];
    $node_id = $_GET['node_id'];
    $jsondata = bookmark_set_data_responce($user_id, $node_id);
    //$jsondata = json_encode($jsondata);
    return $jsondata;
}

function bookmark_delete_responce($token, $user_id, $node_id) {

    $user_id = $_GET['user_id'];
    $node_id = $_GET['node_id'];
    $jsondata = bookmark_del_data_responce($user_id, $node_id);
    return $jsondata;
}

/**
 * Returns Author user detail in an array based on author id args
 * @param author_id
 * @return array
 * 	array of Author detail fields.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns Newswrap i.e recent stories which has Highlights
 * @return array
 * array of stories.
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns Anchor user detail in an array based on anchor id args
 * @param anchor_id
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
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}

/**
 * Returns all the programm which is filled by particular anchor.
 * @param $anchor_id
 *   The Anchor id
 *   Type [0/1 where 0 can be for Latest and 1 for Popular]
 * @return array
 * 	array of programms.
 */
function anchor_programm_list($token, $anchor_id, $type) {

    //valid id
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
    $suffix = $anchor_id.'_'.$cpageno;
    $redis_key = "itg_rapid_api_anchor_" . $redis_type . "_programmlist" . $suffix;

    $result_get = getRedis($redis_key);

//    if ($result_get['key_value'] != "") {
//        $jsondata = $result_get['key_value'];
//    } else {
        // call function from return data..
        $jsondata = anchor_programm_data_list($anchor_id, $type, $cpageno);
        $jsondata = json_encode($jsondata);
//        $ttl = '15';//DEFAULT_REDIS_EXPIRE_TIME;
//        $result_set = setRedis($redis_key, $jsondata, $ttl);
//    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
}
