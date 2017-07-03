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
        $jsondata = newscategoryPageRerourceValue($id, $cpageno);
        $jsondata = json_encode($jsondata);
        $ttl = RAPID_API_NEWSLIST_REDIS_EXPIRE_TIME;
        $result_set = setRedis($redis_key, $jsondata, $ttl);
    }

    $jsondata = json_decode($jsondata, true);
    return $jsondata;
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
    //valid tid & pageno
    if (!is_numeric($sdate)) {
        $sdate = 0;
    }
    if (!is_numeric($tdate)) {
        $tdate = 0;
    }
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

function itg_rapid_api_testing($token) {
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
    //echo "<pre>hi"; print_r($_GET);echo "</pre>"; exit();
    global $user;
    $user_id = $username = $_GET['user_id'];
    $password = $password = $_GET['password'];

    if ($user->uid) {
        // user is already logged in
        return services_error(t('Already logged in as @user.', array('@user' => $user->name)), 406);
    }

    // Check if account is active.
    if (user_is_blocked($username)) {
        return services_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
    }

    // Emulate drupal native flood control: check for flood condition.
    $flood_state = array();
    if (variable_get('services_flood_control_enabled', TRUE)) {
        $flood_state = _user_resource_flood_control_precheck($username);
    }

    // Only authenticate if a flood condition was not detected.
    if (empty($flood_state['flood_control_triggered'])) {
        //echo "andy"; exit();
        $uid = user_authenticate($username, $password);
    } else {
        $uid = FALSE;
    }

    // Emulate drupal native flood control: register flood event, and throw error
    // if a flood condition was previously detected
    if (variable_get('services_flood_control_enabled', TRUE)) {
        $flood_state['uid'] = $uid;
        _user_resource_flood_control_postcheck($flood_state);
    }

    if ($uid) {
        $user = user_load($uid);
        if ($user->uid) {
            user_login_finalize();

            $return = new stdClass();
            $return->sessid = session_id();
            $return->session_name = session_name();
            $return->token = drupal_get_token('services');

            $account = clone $user;

            services_remove_user_data($account);

            $return->user = $account;

            return $return;
        }
    }
    watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
    return services_error(t('Wrong username or password.'), 401);
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


$first_name = $_GET['first_name'];
$last_name = $_GET['last_name'];
$user_id = $_GET['user_id'];
$password = $_GET['password'];
$login_type = $_GET['login_type'];
$token_id = $_GET['token_id'];
$form_state = array();


    // check user_id is mail or mobile
$url_info = "aHR0cDovL2l0Z2RyYXBpZC5pbmRpYXRvZGF5b25saW5lLmluL2luZGlhL3N0b3J5L2Rpd2FsaS1zbW9rZS1wb2xsdXRpb24tcGFydGljdWxhdGUtbWF0dGVyLTM0OTQ2Ny0yMDE2LTEwLTMx";
    $mail_flag = 1;
    if (preg_match('/^\d{10}$/', $user_id)) {
        $mail_flag = 0;
        $mobile = $user_id;
        $mail = $first_name . "@nowhereandy.com";
    } else {
        $mobile = "";
        $mail = $user_id;
    }
    $form_state['values']['mobile'] = $mobile;
    $form_state['values']['url_info'] = $url_info;
    if($mail_flag){
        $form_state['values']['mail'] = $mail;
    }
    else{
        $form_state['values']['mail'] = "";
    }
    // prepare array for user
    $edit = array(
        'name' => $user_id,
        'pass' => $password,
        'mail' => $mail,
        'init' => $mail,
        'status' => 1,
        'access' => REQUEST_TIME,
        'field_first_name' => array(
            LANGUAGE_NONE => array(
                0 => array(
                    'value' => $first_name
                )
            )
        ),
        'field_last_name' => array(
            LANGUAGE_NONE => array(
                0 => array(
                    'value' => $last_name
                )
            )
        ),
        'roles' => array(
            2 => 'authenticated',
            FRONT_USER => 'Front User',
        ),
    );

    if (is_numeric($mobile)) {
        $edit['field_mobile_number'] = array(LANGUAGE_NONE => array(
                0 => array(
                    'value' => $mobile
                )
            )
        );
    }


    try {

        $account = user_save(NULL, $edit);

        if (function_exists('itg_personalization_reddem_referfriend')) {
            itg_personalization_reddem_referfriend($_SESSION['referral_key']);
            unset($_SESSION['referral_key']);
        }
        // Set operation.
        
        $op = 'register_no_approval_required';
        // Send an email.
        if (empty($form_state['values']['mobile'])) {
            // _user_mail_notify($op, $account);
            if (function_exists('itg_sso_get_mail_content')) {
                if (!empty($form_state['values']['url_info'])) {
                    $url_info = $form_state['values']['url_info'];
                }
                $mail_content = itg_sso_get_mail_content($account, $mail, $url_info);
            }
            itg_user_mapping_activate($account->uid);
        } else {
            $rand_otp = rand(0, 9999);
            if (function_exists('itg_sso_first_time_otp_insert')) {
                itg_sso_first_time_otp_insert($mobile, $mail, $rand_otp, 'register');
                itg_sso_sms_send($rand_otp, $mobile);
            }
            if (!empty($form_state['values']['mail'])) {
                itg_sso_otp_mail_content($rand_otp, $mail);
            }
        }

        
     
    } catch (Exception $e) {
        watchdog('error on user save', $e->getMessage());
        drupal_set_message('Error:' . $e->getMessage(), 'error');
        $account = $e;
    }
    return $account;
}
