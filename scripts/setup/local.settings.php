<?php
include_once('./includes/cache.inc');

ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('max_input_vars', 50000);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);

# -- Configure Cache
#$conf['cache_backends'][] = 'sites/all/modules/contrib/mongodb/mongodb_cache/mongodb_cache.inc';
#$conf['cache_class_cache'] = 'DrupalMongoDBCache';
#$conf['cache_class_cache_bootstrap'] = 'DrupalMongoDBCache';
#$conf['cache_default_class'] = 'DrupalMongoDBCache';

# -- Don't touch SQL if in Cache
#$conf['page_cache_without_database'] = TRUE;
#$conf['page_cache_invoke_hooks'] = TRUE;

# Session Caching
// $conf['session_inc'] = 'sites/all/modules/contrib/mongodb/mongodb_session/mongodb_session.inc';
// $conf['cache_session'] = 'DrupalMongoDBCache';

# Field Storage
//$conf['field_storage_default'] = 'mongodb_field_storage';

# Message Queue
#$conf['queue_default_class'] = 'MongoDBQueue';

# Memcache specific settings
/*$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache_storage/memcache_storage.inc';
$conf['cache_default_class'] = 'MemcacheStorage';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
$conf['cache_class_cache_update'] = 'DrupalDatabaseCache';

#$conf['memcache_storage_debug'] = TRUE;
$conf['memcache_extension'] = 'Memcache';

$conf['memcache_storage_key_prefix'] = 'itgmem';
//$conf['session_inc'] = 'sites/all/modules/contrib/memcache_storage/includes/session.inc';

// setting for UAT
$conf['memcache_servers'] = array(
  'itgd-drupal-memc-dev.yissgx.cfg.aps1.cache.amazonaws.com:11211' => 'default',
);*/

// setting for production
 /*$conf['memcache_servers'] = array(
  'itgd-drupal-mem-prod.yissgx.cfg.aps1.cache.amazonaws.com:11211' => 'default',
);*/
$conf = array(
'cache_backends' => array('sites/all/modules/memcache/memcache.inc'),
'cache_default_class' => 'MemCacheDrupal',
'cache_class_cache_form' => 'DrupalDatabaseCache',
//  'session_inc' => './sites/all/modules/memcache/memcache-session.inc',
  'memcache_servers' => array(
   'itgd-drupal-memc-dev.yissgx.cfg.aps1.cache.amazonaws.com:11211' => 'default',   
  ),
  'memcache_bins' => array(
    'cache' => 'default',
    'cache_filter' => 'default',
    'cache_menu' => 'default',
    'cache_page' => 'default',
    'users' => 'default',
    'cache_pathdst' => 'default',
    'cache_pathsrc' => 'default',
    'cache_class_cache_form' => 'default',
  ),
);

$conf['memcache_key_prefix'] = 'itgmem';
$conf['path_inc'] = 'sites/all/modules/contrib/pathcache/path.inc';

// Don't bootstrap the database when serving pages from the cache.
$conf['page_cache_without_database'] = TRUE;
$conf['page_cache_invoke_hooks'] = FALSE;

#MongoDB 
$conf['mongodb_connections'] = array(
  'default' => array(
    //'host' => 'mongodb://prod_write:Pr0d_wr1te654@mongodb1,mongodb2,mongodb3/itgcmsmongo',
    'host' => 'mongodb://itoday_write:1t0day_wr1te111@mongodb1,mongodb2,mongodb3/itgcmsmongo',// uat
    'db' => 'itgcmsmongo',
    'connection_options' => array('replicaSet' => 'uatreplica'),
  ),
);


