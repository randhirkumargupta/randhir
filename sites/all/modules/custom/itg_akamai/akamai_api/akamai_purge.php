<?php

ini_set('display_errors', 1);
error_reporting(E_ALL);

if (!defined('DS')) {
    define('DS', DIRECTORY_SEPARATOR);
}
if (!defined('ROOTPATH_API')) {
    define('ROOTPATH_API', dirname(__DIR__));
}

/*  AKAMAI */
define('AKAMAI_BASE_URI', 'https://akab-m5dvvyeoipksje5b-khfwrc7yvl364fml.purge.akamaiapis.net/');
define('AKAMAI_API_ENDPOINT', '/ccu/v3/delete/url/production');
define('AKAMAI_CLIENT_TOKEN', 'akab-ry7625oyq5l3sw5l-v6ywajzmatezae6b');
define('AKAMAI_CLIENT_SECRET', '+M3t+LXDncrTblwmHrJpoaeqv9N6Gz2JTsngv6oVB7s=');
define('AKAMAI_ACCESS_TOKEN', 'akab-q4ksytw26xwt5d56-zwhjtxiwaxfqeasj');


require_once('akamai-open-edgegrid-client.phar');

use Akamai\Open\EdgeGrid\Client;
use Akamai\Open\EdgeGrid\Authentication;

if (!empty($_REQUEST['url'])) {
    $url = $_REQUEST['url'];
} else {
    $url = '';
    echo 'URL is empty';
    die;
}

$urls = explode(',',$url);
if(is_array($urls)) {
    $url = '';
    foreach($urls as $singleUrl) {
       $url .= '"'.$singleUrl.'",';
    }
    $url = substr($url,0,-1);
}else {
    $url = '"'.$url.'"';
}




$client = new Akamai\Open\EdgeGrid\Client(['base_uri' => AKAMAI_BASE_URI]);

$client->setAuth(AKAMAI_CLIENT_TOKEN, AKAMAI_CLIENT_SECRET, AKAMAI_ACCESS_TOKEN);

// use $client just as you would \Guzzle\Http\Client  
try {
    //$data = '{ "hostname" : "www.example.com", "objects" : [ "/prodimages/dvd-large.jpg","/lcomputercable.gif","/lscanner.gif" ] }';
    //$data = '{ "objects" : [ "' . $url . '"] }';
    $data = '{ "objects" : [ ' . $url . '] }';
    $response = $client->post(AKAMAI_API_ENDPOINT, [
        'body' => $data,
        'headers' => ['Content-Type' => 'application/json']
    ]);
    echo $response->getBody();
    #echo '<pre>';
    #print_r(json_decode($response->getBody()));
} catch (\Exception $e) {
    echo 'Akamai error : <pre>';
    print_r($e->getMessage());
}
