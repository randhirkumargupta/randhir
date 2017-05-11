<?php

/**
 * @file
 * Main module file for custom netcore mail
 */

/**
 * Defining constants
 */
define('APIKEY', 'b88b53a80447bacd974fea36f91c8695');
define('NETCORE_LIST_ID', 4);
define('NETCORE_URL', 'https://api.exacttouch.com/API/mailing/');
//define('NETCORE_USER_ID', 5);
//define('MESSAGE_ID', 10);



/**
 * Create a mailing list
 * @param Array $data
 *    Containing params for API.
 * @return Array
 */

function itg_netcore_create_list() {
  //[TYPE] => success
  
  /*$data['name'] = 'itgdev';
  $data['description'] = 'list for itgdev';
  $netcore_create = itg_netcore_mail_create_list($data);*/
  
  /*$data['email'] = 'shravankumar62757@gmail.com';
  $data['listId'] = NETCORE_LIST_ID;
  $netcore_create = itg_netcore_mail_add_user($data);*/
  
  /*$data['subject'] = 'Test mail for netcore3';
  $data['fromName'] = 'itg';
  $data['fromEmail'] = 'care@intoday.in';  
  $data['content'] = 'hello test data [UNSUBSCRIBEURL]';
  $netcore_campaign = itg_netcore_mail_create_campaign($data);
  
  $data['messageId'] = $netcore_campaign['OUTPUT']['MID'];
  $data['listId'] = NETCORE_LIST_ID;
  $netcore_create = itg_netcore_mail_scehdule_campaign($data);
  
  p($netcore_create);*/
  
}

/**
 * Create a mailing list
 * @param Array $data
 *    Containing params for API.
 * @return Array
 */
function itg_netcore_mail_create_list($data) { 
  $data = '<DATASET>
            <CONSTANT><ApiKey>' . APIKEY . '</ApiKey></CONSTANT>
            <INPUT>
              <Name>' . $data['name'] . '</Name>
              <Description>' . $data['description'] . '</Description>
              <Active>1</Active>
            </INPUT>
          </DATASET>';
  $url = NETCORE_URL."?type=list&activity=Add&";
  $curlResponse = itg_netcore_mail_send_curl_request($url, $data);
  return $curlResponse;
}

/**
 * Add an email to provided ListId
 * @param Array $data
 *    Containing params for API.
 * @return Array
 */
function itg_netcore_mail_add_user($data) {
  $data = "<DATASET>
            <CONSTANT><ApiKey>" . APIKEY . "</ApiKey></CONSTANT>
            <INPUT>
              <AddEmail>" . $data['email'] . "</AddEmail>
              <ListMember>" . $data['listId'] . "</ListMember>
              <DoubleOptin>0</DoubleOptin>
            </INPUT>
          </DATASET>";
  $url = NETCORE_URL."?type=contact&activity=Add&";
  $curlResponse = itg_netcore_mail_send_curl_request($url, $data);
  return $curlResponse;
}

/**
 * Create campaign with provide data. Please make sure to add "[UNSUBSCRIBEURL]"
 * in your mail content otherwise your campaign will not be created.
 * @param Array $data
 *    Containing params for API
 * @return Array
 */
function itg_netcore_mail_create_campaign($data) {
  $data = "<DATASET>
            <CONSTANT><ApiKey>" . APIKEY ."</ApiKey></CONSTANT>
            <INPUT>
              <Subject>" . $data['subject'] . "</Subject>
              <FromName>" . $data['fromName'] . "</FromName>
              <FromEmail>" . $data['fromEmail'] . "</FromEmail>
              <ReplyTo>" . $data['replyTo'] . "</ReplyTo>
              <SetLimit>" . $data['limit'] . "</SetLimit>
              <MessageHTML><![CDATA[" . $data['content'] . "]]></MessageHTML>
              <DYNAMIC></DYNAMIC>
              <TemplateID></TemplateID>
              <MessageMobile><![CDATA[]]></MessageMobile>
            </INPUT>
          </DATASET>";
  $url = NETCORE_URL."?type=message&activity=Add&";
  $curlResponse = itg_netcore_mail_send_curl_request($url, $data);
  return $curlResponse;
}

/**
 * Schedule or send a campaign to provided listId
 * @param Array $data
 *    Containing params for API.
 * @return Array
 */
function itg_netcore_mail_scehdule_campaign($data) {
  $data = "<DATASET>
            <CONSTANT><ApiKey>" . APIKEY . "</ApiKey></CONSTANT>
            <INPUT>
              <MID>" . $data['messageId'] . "</MID>
              <LID>" . $data['listId'] . "</LID>
            </INPUT>
          </DATASET>";
  $url = NETCORE_URL."?type=message&activity=Schedule&";
  $curlResponse = itg_netcore_mail_send_curl_request($url, $data);
  return $curlResponse;
}

/**
 * Send cURL request to provided URL
 * @param String $url
 *    Request URL.
 * @param String $data
 *    Request parameters in XML format.
 * @return Array
 */
function itg_netcore_mail_send_curl_request($url, $data) {
  //intiating cURL
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  //setting the param
  curl_setopt($ch, CURLOPT_POSTFIELDS, "data=" . $data);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 300);
  $op = curl_exec($ch);
  curl_close($ch);
  //convert the XML result into array
  return json_decode(json_encode(simplexml_load_string($op)), true);
}

 /**
 * Remove an email
 * @param Array $data
 *    Containing params for API.
 * @return Array
 */
function itg_netcore_mail_unsubscribe_user($data) {
  $data = "<DATASET>
            <CONSTANT><ApiKey>" . APIKEY . "</ApiKey></CONSTANT>
            <INPUT>
              <Emailaddress>" . $data['email'] . "</Emailaddress>
            </INPUT>
          </DATASET>";
  $url = NETCORE_URL."?type=contact&activity=Delete&";
  $curlResponse = itg_netcore_mail_send_curl_request($url, $data);
  return $curlResponse;
}