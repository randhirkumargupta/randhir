<?php
include_once('./includes/cache.inc');

ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('max_input_vars', 50000);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);

$conf = array(
'cache_backends' => array('sites/all/modules/memcache/memcache.inc'),
'cache_default_class' => 'MemCacheDrupal',
'cache_class_cache_form' => 'DrupalDatabaseCache',
  'memcache_servers' => array(
   'itgd-drupal-memc-dev.yissgx.cfg.aps1.cache.amazonaws.com:11211' => 'default',   
  ),
  'memcache_bins' => array(
    'cache' => 'default',
    'cache_filter' => 'default',
    'cache_menu' => 'default',
    'cache_page' => 'default',
   // 'session' => 'session',
    'users' => 'default',
    'cache_pathdst' => 'default',
    'cache_pathsrc' => 'default',
  ),
);
$conf['memcache_key_prefix'] = 'itgmem_dev';

$conf['path_inc'] = 'sites/all/modules/contrib/pathcache/path.inc';

#MongoDB 
$conf['mongodb_connections'] = array(
  'default' => array(    
    'host' => 'mongodb://itg_write:1tg_wr1te111@mongodb1,mongodb2,mongodb3/itgcmsmongo_dev',
    'db' => 'itgcmsmongo_dev',
    'connection_options' => array('replicaSet' => 'uatreplica'),
  ),
);


