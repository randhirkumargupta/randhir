<?php
#MongoDB
$conf['mongodb_connections'] = array(
  'default' => array(                             // Connection name/alias
    'host' => 'mongodb://10.6.210.19',                      // Omit USER:PASS@ if Mongo isn't configured to use authentication.
    'db' => 'itgcmsmongo'                   // Database name. Make something up, mongodb will automatically create the database.
  ),
);

