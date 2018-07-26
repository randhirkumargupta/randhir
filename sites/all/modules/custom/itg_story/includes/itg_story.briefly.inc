<?php

/**
 * @file
 * Inc file contains the functions
 */

module_load_include('inc', 'itg_app_api', 'itg_app_api.services');

/**
 * List of briefly
 * @return type
 */
$data = news_wrap_list();

pr($data);