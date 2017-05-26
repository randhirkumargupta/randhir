<?php
#MongoDB
$conf['mongodb_connections'] = array(
  'default' => array(                             // Connection name/alias
    'host' => 'mongodb://10.6.210.19',                      // Omit USER:PASS@ if Mongo isn't configured to use authentication.
    'db' => 'itgcmsmongo'                   // Database name. Make something up, mongodb will automatically create the database.
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


