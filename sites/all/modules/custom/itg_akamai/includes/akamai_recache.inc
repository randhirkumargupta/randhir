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
  // Only continue if there any URLs found.
  if (empty($dburls)) {
    //watchdog('Akamai Recacher', 'No URLs needed to be crawled.', array(), WATCHDOG_INFO);
    //lock_release(__FUNCTION__);
    return 0;
  }
  
   $host_domain = itg_akamai_getting_domain_without_protocal();
  //watchdog('$host_domain', $host_domain);
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
    'headers' => array('Accept-Encoding' => 'gzip','Host'=>$host_domain),
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
  $messages = array();
  //watchdog('$request_for_httrl', '<pre>' . print_r($request, true) .'<pre>');
  foreach ($request as $url => $probe) {
    if($probe->code == 200){
     $messages[] = '<li>successful (' . $probe->code . '): ' . $url . '</li>';
    } else {
    $messages[] = '<li>UNsuccessful (' . $probe->code . '): ' . $url . '</li>';
   }
  }

  //watchdog('recache complete status', '<pre>' . print_r($codes, true) . '</pre>');

  // Report success and issue a warning for URLs that did not return code 200.
 
  if (!empty($messages)) {
    $messages = '<ul>' . implode('', $messages) . '</ul>';
     //watchdog('Akamai Recacher', $messages);
  }
  // End the lock.
  //lock_release(__FUNCTION__);
  return count($request);
  //}
}
