<?php
/**
 * Akamai Re-cache expired URLs.
 *
 * Uses a lock to prevent concurrent execution.
 *
 * @return int
 *   Returns the number of URLs that were crawled, zero if none.
 */
function akamai_recacher_crawler($dburls) {
  //if (lock_acquire(__FUNCTION__)) {
//$dburls = array();
//$dburls[] = 'node/';

    // Only continue if there any URLs found.
    if (empty($dburls)) {
      watchdog('Akamai Recacher', 'No URLs needed to be crawled.', array(), WATCHDOG_INFO);
      //lock_release(__FUNCTION__);
      return 0;
    }

    //p($dburls);
    // Default HTTP request options for anonymous users.
    $recacher_role_options['anonymous'] = array(
      'timeout' => 90,
      // We are using BLOCKING requests so as not to strain the target website
      // with parallel requests for uncached URLs. And also to be able to
      // determine whether the request was successful or not!
      'blocking' => TRUE,
      // Accept-Encoding is crucial - this is how most browsers, but also
      // GoogleBot, request content.
      // If we leave it out, most browsers would still find the cache cold!
      'headers' => array('Accept-Encoding' => 'gzip'),
    );

     foreach ($dburls as $dburl) {
      foreach ($recacher_role_options as $role => $options) {
        // Queue up the request.
        httprl_request($dburl, $options);
      }
    }

    // Execute request.
    $request = httprl_send_request();

    $codes = array();
    foreach ($request as $url => $probe) {
      $codes[$url] = $probe->code;
    }

    watchdog('recache complete status', '<pre>' .print_r($codes, true). '</pre>' );
    
      $someerror = FALSE;
      // Report success and issue a warning for URLs that did not return code 200.
      $messages = array();
      foreach ($dburls as $dburl) {
        if ($codes[$dburl] <> 200) {
          $success = t('UNsuccessful');
          $someerror = TRUE;
        }
        else {
          $success = t('successful');
        }
        if ($codes[$dburl] == 200)
          continue; // If not required, don't show successfully re-cached URLs.
        $messages[] = '<li>' . $success . ' (' . $codes[$dburl] . '): ' . $dburl . '</li>';
      }
      if (!empty($messages)) {
        $messages = '<ul>' . implode('', $messages) . '</ul>';
        $boodschap = t('Attempted re-caching the following URLs:') . '</br>' . $messages;
        if ($someerror === FALSE) {
          watchdog('Akamai Recacher1', $boodschap, NULL, WATCHDOG_INFO);
        }
        else {
          // If there is at least one unsuccessful re-caching, elevate the
          // watchdog reporting level.
          watchdog('Akamai Recacher2', $boodschap, NULL, WATCHDOG_WARNING);
        }
      }
    // End the lock.
    //lock_release(__FUNCTION__);
    return count($dburls);
  //}
}
