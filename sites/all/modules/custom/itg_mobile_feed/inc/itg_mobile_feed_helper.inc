<?php

/**
 * Inc file contains global configurations
 */
define('FEED_NOTIFICATION_PATH', '/sites/default/files/xml_it/notifications');
define('DEFAULT_REDIS_EXPIRE_TIME', 86400);
define('RAPID_API_HOMEPAGE_REDIS_EXPIRE_TIME', 86400);
define('RAPID_API_NEWSLIST_REDIS_EXPIRE_TIME', 86400);


define('ITGD_DEV_FILES_PATH', 'http://itgddev.indiatodayonline.in/sites/default/files');
define('ITGD_MUM_DEV_FILES_PATH', 'http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public');

function tidConfig() {
    $tid_config = array();

    $photo_sec_tid = explode(',', variable_get('photo_sec_tid'));
    $video_sec_tid = explode(',', variable_get('video_sec_tid'));
    $program_sec_tid = explode(',', variable_get('program_sec_tid'));
    $left_main_tid = explode(',', variable_get('left_main_tid'));
    $magazine_tid = variable_get('itg_feed_magazine_tid');

    $tid_config['photo_sec_tid'] = $photo_sec_tid;
    $tid_config['video_sec_tid'] = $video_sec_tid;
    $tid_config['program_sec_tid'] = $program_sec_tid;
    $tid_config['magazine'] = $magazine_tid;
    $tid_config['left_main_tid'] = $left_main_tid;

    return $tid_config;
}

/**
 * Function for get to redis
 */
function getRedis($key) {

    $key_value = 0;
    $result = array();

    $redis = redis_connection();
    if ($redis->exists($key)) {
        $key_value = $redis->get($key);
    } else {
        $key_value = 0;
    }

    $result['key_value'] = $key_value;

    return $result;
}

/**
 * Common function to set the value on redis key
 */
function setRedis($key, $value, $ttl = 300) {

    $key_value = 0;
    $result = array();
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

function list_redis_key() {

    $redis = redis_connection();
    $all_redis_key = $redis->keys("*");
    return $all_redis_key;
}

/*
 * unique function to connect redis server
 */

function redis_connection() {

    $redis = new Redis();
    $time = 300;
    $redis_server_read = variable_get('redis_server_host');
    $redis_server_read_port = variable_get('redis_server_port');
    $redis_server_read_timeout = variable_get('redis_server_timeout');
    $connection_str = $redis->connect($redis_server_read, $redis_server_read_port, $redis_server_read_timeout);

    if (!$connection_str) {
        throw new Exception("Can’t connect redis");
        return;
    } else {
        return $redis;
    }
}

/*
 * delete redis key value
 */

function redis_key_delete($key) {

    $redis = redis_connection();
    $result = $redis->del($key);

    return $result;
}
