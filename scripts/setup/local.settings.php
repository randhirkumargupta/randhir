<?php
#MongoDB
$conf['mongodb_connections'] = array(
  'default' => array(                             // Connection name/alias
    'host' => 'mongodb://itoday_write:1t0day_wr1te111@10.6.210.218/itgcmsmongo',
    //'host' => 'itoday_write:1t0day_wr1te111@10.6.210.218/itgcmsmongo,itoday_read:1t0day_read110@10.6.210.214/itgcmsmongo,itoday_read:1t0day_read110@10.6.210.117/itgcmsmongo',
    //'host' => 'mongodb://10.6.210.19',                      // Omit USER:PASS@ if Mongo isn't configured to use authentication.
    //'host' => 'mongodb://10.6.101.66',//prod
    'db' => 'itgcmsmongo',                   // Database name. Make something up, mongodb will automatically create the database.
    //'connection_options' => array('replicaSet' => 'uatreplica'),
  ),
);

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
$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache_storage/memcache_storage.inc';
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
);

// setting for production
/*$conf['memcache_servers'] = array(
  'itgd-drupal-mem-prod.yissgx.cfg.aps1.cache.amazonaws.com:11211' => 'default',
);*/

