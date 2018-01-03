<?php

/**
 * @file
 * The PHP page that serves all page requests on a Drupal installation.
 *
 * The routines here dispatch control to the appropriate handler, which then
 * prints the appropriate page.
 *
 * All Drupal code is released under the GNU General Public License.
 * See COPYRIGHT.txt and LICENSE.txt.
 */

/**
 * Root directory of Drupal installation.
 */
if ($_SERVER['HTTP_HOST'] == 'staging-it.indiatodayonline.in') {
  $old_url = $_SERVER['SCRIPT_URL'];
  $url_re = 'http://uat-it.indiatodayonline.in/'.$old_url;
  header('Location: ' . $url_re);
  //drupal_goto('http://uat-it.indiatodayonline.in/'.$old_url);
}

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
menu_execute_active_handler();
