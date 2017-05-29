<?php

error_reporting(E_ALL);
ini_set('display_errors', 1);

function itg_device_notification_menu() {
  $items['notification'] = array(
    'title' => 'Device Notification',
    'page callback' => 'notification_page',
    'access arguments' => array('access content'),
    'type' => MENU_SUGGESTED_ITEM,
  );
  return $items;
}

function get_notification_config(){
    $config = array();
    $config['start_index'] = 0;
    $config['end_index'] = 20;
    $config['idsection'] = 1;
    $config['section'] = 'Notifications';
    $config['footersharemsg'] = 'Shared via India Today News App  http://bit.ly/1DBXcjS';
    return $config;
}
//notification?website=aajtak&contentid=11&title=Test Aaj Tak&kicker=Test Kicker&contenttype=test&app_id=12&device=232
function notification_page(){
    $params = drupal_get_query_parameters();
    //print_r($params);
    generate_notification_all($params);
    //message_data();
    //return $output = 'Test';
}


function generate_notification_all($params){
    
    $idsection = 1;
    $section = 'Notifications';
    $file_name = '';
    $output = '';
    $app_file_name = '';
    $app_output = '';
     
    $footersharemsg = isset($params['title']) ? $params['title'] : '';
    $website = isset($params['website']) ? $params['website'] : '';
    //Application ID 1-India Today 4-India Today Ipad
    $app_id = isset($params['app_id']) ? $params['app_id'] : '';
    //1 - iOS; 2 - BB; 3 - Android; 4 - Nokia ASHA; 5 - Windows Phone; 7 - OS X; 8 - Windows 8; 9 - Amazon; 10 - Safari; 11 - Chrome
    $device = isset($params['device']) ? $params['device'] : '';
    
    //XML Files Generation Based on App Id
     if($app_id == '4'){
        
        $app_file_name = 'notification_ipad.xml';
        $app_output .= ipad_notification_xml();
     }   
   // XML Files Generation Based on Device Id

    if($params['device'] == '1'){
        $file_name = 'notification_ios.xml';
        $output .= default_xml_feed();
    }elseif ($params['device'] == '2') {
        $file_name = 'notification_bb.xml';
        $output = bb_notification_xml();
    }elseif ($params['device'] == '3') {
        $file_name = 'notification_android.xml';
        $output = default_xml_feed();
    }elseif ($params['device'] == '4') {
        $file_name = 'notification_nokiaasha.xml';
        $output = nokiaasha_notification_xml();
    }elseif ($params['device'] == '5') {
        $file_name = 'notification_windowsphone.xml';
        $output .= default_xml_feed();
    }elseif ($params['device'] == '7') {
        $file_name = 'notification_osx.xml';
        $output .= osx_notification_xml();
    }elseif ($params['device'] == '8') {
        $file_name = 'notification_windows8.xml';
        $output .= windows8_notification_xml();
    }elseif ($params['device'] == '9') {
        $file_name = 'notification_amazon.xml';
        $output .= amazon_notification_xml();
    }elseif ($params['device'] == '10') {
        $file_name = 'notification_safari.xml';
        $output .= safari_notification_xml();
    }elseif ($params['device'] == '11') {
        $file_name = 'notification_chrome.xml';
        $output .= chrome_notification_xml();
    }
    
    $term_feed_path = getcwd() . "/sites/default/files/xml_it/notification";
    
    $default_output = default_xml_feed();
    $default_file_name = 'notification_all.xml';
    
    writeFeedFile($term_feed_path, $default_file_name, $default_output);
    
    if($output){
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
    }
    else{
        $return_flag .="Nid is missing";
    }
    if(isset($app_output) && $app_output != ''){
        writeFeedFile($term_feed_path, $app_file_name, $app_output);
    }

  //return $return_flag;
    header('Content-Type: application/xml; charset=utf-8');
    echo $default_output;  die();
    
}

/* Common Function to get weburl 
 * args nid
 * return string weburl
 */

function get_web_url($nid){
     global $base_url;
     $alias = drupal_get_path_alias('node/'.$nid.'');
     $weburl = $base_url ."/". $alias;
     return $weburl;
}

/*
 * Function for getting the xml output for notification_all, android, ios
 */

function default_xml_feed(){
    
    $totalarticle = count(message_data());
    $config = get_notification_config();
    
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index><footersharemsg>".$config['footersharemsg']."</footersharemsg>";
    $output .= notifications_article();
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the Ipad notification Xml Output
 */

function ipad_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the chrome notification Xml Output
 */

function chrome_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the safari notification Xml Output
 */

function safari_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the amazon notification Xml Output
 */

function amazon_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the Window 8 notification Xml Output
 */

function windows8_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the osx notification Xml Output
 */

function osx_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the Nokia Asha notification Xml Output
 */

function nokiaasha_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

/*
 * Function for getting the BB Xml Output
 */

function bb_notification_xml(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
     
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>".$config['idsection']."</idsection><section>".$config['section']."</section><totalarticle>".$totalarticle."</totalarticle><start_index>".$config['start_index']."</start_index><end_index>".$config['end_index']."</end_index>";
    
    if($totalarticle > 0){
            foreach ($all_data as $data){
              $msg_node = node_load($data->content_id);
              $thumb_image = file_create_url($msg_node->field_story_small_image['und'][0]['uri']);
              $kicker_image = '';
              $weburl = '';
              $url = $data->message_url;
              $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
              $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
              //print_r($msg_node);

               $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
            }
    }else {
        $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><create_date></create_date><create_datetime></create_datetime></article>";
    }
    
    $output .= getMobileFeedXmlFooter();
    
    return $output;
}

function notifications_article(){
    
    $all_data = message_data();
    $totalarticle = count($all_data);
    if($totalarticle > 0){
        foreach ($all_data as $data){
          $msg_node = node_load($data->content_id);
          $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
          $kicker_image = '';
          $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
          if($msg_node->type == 'story'){
             $url = 'story'.$msg_node->nid.'.xml'; 
          }elseif ($msg_node->type == 'videogallery') {
             $url = 'video'.$msg_node->nid.'.xml'; 
          }elseif ($msg_node->type == 'photogallery') {
             $url = 'photo'.$msg_node->nid.'.xml'; 
          }
          $created_date = format_date($msg_node->created, 'custom', 'M d, Y');
          $created_date_time = format_date($msg_node->created, 'custom', 'Y-m-d H:i:s P');
          
          if($msg_node->nid > 0){
                    $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $kicker_image . "</kickerimage><url>" . $url . "</url><weburl>" . $weburl . "</weburl><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>"; 
           }else {
                    $output .= "<article><title><![CDATA[]]></title><thumbimage></thumbimage><kickerimage></kickerimage><url></url><weburl></weburl><create_date></create_date><create_datetime></create_datetime></article>";
            }
            //Attach the node type details
            
           if($msg_node->type == 'story'){
                $related_node = relatedContentNodeType($msg_node->nid, "story");
                if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
                $output .= getRelatedNodeXmlTag($related_node['nid']);
              }
                
            }elseif ($msg_node->type == 'videogallery') {
                $related_node = relatedContentNodeType($msg_node->nid, "videogallery");
                if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
                $output .= getRelatedNodeXmlTag($related_node['nid']);
              }
                
            }elseif ($msg_node->type == 'photogallery') {
               
              $related_node = relatedContentNodeType($msg_node->nid, "photogallery");
              if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
                $output .= getRelatedNodeXmlTag($related_node['nid']);
              }
            }
            
            
          }
    }
    return $output;
}

function message_data(){
    $config = get_notification_config();
    $res = db_select('message_backup','m')
           ->fields('m')
           ->range($config['start_index'],$config['end_index'])
           ->execute()->fetchAll();
    return $res;
   
}


function bbgetCommentXmlTag($node) {
  // variable declation
  $mode = "COMMENT_MODE_FLAT";
  $comments_per_page = 10;
  $commentsflag = 0;
  $comment_tag = "";
  $output = "";
  $comments_list = comment_get_thread($node, $mode, $comments_per_page);

  // writng comments tag
  foreach ($comments_list as $key => $value) {
    $cid = $value;
    $commentsflag = 1;
    $commens_obj = comment_load($cid);
    $commenttext = $commens_obj->comment_body['und'][0]['value'];
    $name = $commens_obj->name;
    $create_date = date("F d, Y", $commens_obj->created);
    $create_datetime = date(DATE_ATOM, $commens_obj->created);
    $email = $commens_obj->mail;
    $comment_tag .= "<comment><commenttext>" . $commenttext . "</commenttext><name>" . $name . "</name><createddate>" . $create_date . "</createddate><createddatetime>" . $create_datetime . "</createddatetime><email>" . $email . "</email></comment>";
  }

  if ($commentsflag) {
    $output .= "<comments>";
    $output .= $comment_tag;
    $output .= "</comments>";
  }else{
      $output .= emptygetCommentXmlTag();
  }
  return $output;
}
