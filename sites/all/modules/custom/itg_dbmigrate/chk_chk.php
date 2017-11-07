<?php
chk_chk_chk();


set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

function chk_chk_chk() {
 $query = db_select('migrate_map_itgcategory', 'tab');
  $query->fields('tab', array('sourceid1'));
  $query->isNull('destid1');
  $result = $query->execute()->fetchAll();
p($result);
}

?>
