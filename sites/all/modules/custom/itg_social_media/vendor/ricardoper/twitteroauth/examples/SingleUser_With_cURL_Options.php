<?php

/**
 * TwitterOAuth - https://github.com/ricardoper/TwitterOAuth
 * PHP library to communicate with Twitter OAuth API version 1.1
 *
 * @author Ricardo Pereira <github@ricardopereira.es>
 * @copyright 2014
 */

require __DIR__ . '/../../../../vendor/autoload.php';

use TwitterOAuth\Auth\SingleUserAuth;

/**
 * Serializer Namespace
 */
use TwitterOAuth\Serializer\ArraySerializer;


date_default_timezone_set('UTC');


/**
 * Array with the OAuth tokens provided by Twitter
 *   - consumer_key        Twitter API key
 *   - consumer_secret     Twitter API secret
 *   - oauth_token         Twitter Access token         * Optional For GET Calls
 *   - oauth_token_secret  Twitter Access token secret  * Optional For GET Calls
 */
$credentials = array(
    'consumer_key' => 'xvz1evFS4wEEPTGEFPHBog',
    'consumer_secret' => 'L8qq9PZyRg6ieKGEKhZolGC0vJWLw8iEJ88DRdyOg',
    'oauth_token' => 'e98c603b55646a6d22249d9b0096e9af29bafcc2',
    'oauth_token_secret' => '07cfdf42835998375e71b46d96b4488a5c659c2f',
);

/**
 * Instantiate SingleUser
 *
 * For different output formats you can set one of available serializers
 * (Array, Json, Object, Text or a custom one)
 */
$auth = new SingleUserAuth($credentials, new ArraySerializer());



/**
 * Get cURL Default Options
 */
$curlOptions = $auth->getCurl()->getOptions();

echo '[ Get cURL Default Options ]<pre>'; var_dump($curlOptions); echo '</pre><hr />';


/**
 * Customize cURL Options
 *
 *   - Change Certs to PHP defaults
 *   - Set timeout and connection timeout to 120 seconds
 */
unset($curlOptions[CURLOPT_CAINFO]);

$curlOptions[CURLOPT_TIMEOUT] = $curlOptions[CURLOPT_CONNECTTIMEOUT] = 120;

$auth->getCurl()->setOptions($curlOptions)->getOptions();

echo '[ Customized cURL Options ]<pre>'; var_dump($curlOptions); echo '</pre><hr />';



/**
 * Returns a collection of the most recent Tweets posted by the user
 * https://dev.twitter.com/docs/api/1.1/get/statuses/user_timeline
 */
$params = array(
    'screen_name' => 'ricard0per',
    'count' => 3,
    'exclude_replies' => true
);

/**
 * Send a GET call with set parameters
 */
$response = $auth->get('statuses/user_timeline', $params);

echo '<pre>'; print_r($auth->getHeaders()); echo '</pre>';

echo '<pre>'; print_r($response); echo '</pre><hr />';
