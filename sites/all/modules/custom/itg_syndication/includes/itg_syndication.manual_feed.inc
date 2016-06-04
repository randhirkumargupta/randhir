<?php

/*
 * Inc file contains the functions
 */

/**
 * Implements hook_form_alter()
 * @param array $form
 * @param array $form_state
 * @param string $form_id
 */
function itg_syndication_form_alter(&$form, &$form_state, $form_id) {
  
  if ($form_id == 'views_form_syndication_feed_generator_page') {
    $form['#attached']['js'] = array(
      drupal_get_path('module', 'itg_syndication') . '/js/itg_syndication.js',
    );
    $form['actions']['submit']['#submit'][] = 'itg_syndication_selector_custom_submit';
  }
  
  // Add client dropdown to view
  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'syndication_feed_generator') {    
    
    $form['changed']['min'] = array(
      '#type' => 'date_popup',
      '#title' => t('From'),
      '#date_format' => 'd/m/Y',
      '#date_year_range' => '-1:+1',
      '#attributes' => array(
        'readonly' => 'readonly'
      ),
    );
     
    $form['changed']['max'] = array(
      '#type' => 'date_popup',
      '#title' => t('To'),
      '#date_format' => 'd/m/Y',
      '#date_year_range' => '-1:+1',
      '#attributes' => array(
        'readonly' => 'readonly'
      ),
    );
    
    $form['client_title'] = array(
      '#type' => 'select',
      '#title' => t('Select Client'),
      '#options' => itg_syndication_get_client(),
      '#default_value' => '_none',
      '#weight' => 1,             
    );
       
    $form['issue'] = array(
      '#type' => 'select',
      '#title' => t('Select Issue'),      
      '#options' => itg_syndication_get_issue_list(),
      '#default_value' => '_none',
      '#weight' => 3,
      '#states' => array(
        'visible' => array(
          ':input[name="type"]' => array('value' => 'magazine'),
        ),
      ),
    );
    
    $form['type']['#weight'] = 2;
    $form['submit']['#weight'] = 4;
    
    drupal_add_js('jQuery(document).ready(function() {
              jQuery("#edit-field-story-issue-date-value-wrapper").hide();
              jQuery("#edit-issue").change(function() {                
                jQuery("#edit-field-story-issue-date-value-value-date").val(jQuery("#edit-issue").val());
              });
            });', array('type' => 'inline', 'scope' => 'footer'));
    
 } else if ($form_id == 'views_form_syndication_feed_generator_page') {
   if (isset($_GET['client_title'])) {
    $op = itg_syndication_get_mode($_GET['client_title']);
   } else {
     $op = array('_none' => '- None -');
   }
  
   $form['client_delivery_mode'] = array(
      '#type' => 'select',
      '#title' => t('Select Delivery Mode'),
      '#options' => $op,
      '#default_value' => '_none',
      '#weight' => 98,
      '#prefix' => '<div id="client_delivery_mode_replace">',
      '#suffix' => '</div>',
    );
   
   $feed_type_options = array(t('xml') => t('XML'), 
                    t('rss') => t('RSS'), 
                    t('mrss') => t('MRSS'), 
                    t('ussd') => t('USSD'), 
                    t('sms') => t('SMS'), 
                    t('stf') => t('SIMPLE TEXT FEED'), 
                    t('html') => t('HTML')
              );

   $form['feed_type'] = array(
    '#type' => 'radios',
    '#title' => t('Select Feed Type'),
    '#default_value' => 'xml',
    '#options' => $feed_type_options,    
    '#weight' => 99,
  );
   $form['actions']['download_feed'] = array('#type' => 'submit', '#value' => t('Download Feed'));
   $form['actions']['submit']['#value'] = 'Generate feed and Send it to client';
   // Add cancel button to create/edit
    $form['actions']['cancel'] = array(
      '#markup' => l(t('Cancel'), 'syndication-rule-listing', array('attributes' => array('class' => 'button'))),
      '#weight' => 20,
    );
 }

  // View autocomplete title field.
  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'syndication_client') {
    $form['title']['#autocomplete_path'] = 'content-title-list/syndication_client/autocomplete';
  }  
}


/**
 * Submit callback for row selector form
 * @param array $form
 * @param array $form_state
 */
function itg_syndication_selector_custom_submit($form, &$form_state) {
  
  $client_name = check_plain($form_state['values']['itg_row_selector_client']);
  $web_property = check_plain($form_state['values']['itg_row_selector_web_property']);
  $issue = check_plain($form_state['values']['itg_row_selector_issue']);
  $delivery_mode = check_plain($form_state['values']['client_delivery_mode']);
  $feed_type = check_plain($form_state['values']['feed_type']);
  
  $syndication_node = $form_state['values']['itg_row_selector'];
  
  $data = array(
    'web_property' => $web_property,
    'client_title' => $client_name,
    'delivery_mode' => $delivery_mode,
    'feed_type' => $feed_type,
    'syndication' => serialize($syndication_node),
    'created' => format_date(time(), 'custom', 'Y-m-d'),
  );
  
  $file_path = feed_generator_of_contents($data);
  
  // insert records into database table itg_row_selector.
  
  $syndication_data = array(
    'web_property' => $web_property,
    'client_title' => $client_name,
    'delivery_mode' => $delivery_mode,
    'feed_type' => $feed_type,
    'syndication' => serialize($syndication_node),
    'feed_file_path' => $file_path,
    'created' => format_date(time(), 'custom', 'Y-m-d'),
  );
  
  $query = db_insert('itg_cron_time_scheduler')->fields($syndication_data)->execute();
  
  
  //drupal_write_record('itg_row_selector', $pre_save);
  //watchdog('Syndication', 'Node has been inserted for syndication.');
  drupal_set_message('Content has been saved for syndication.', 'status');
}

/**
 * Feed generator of selected contents
 * @param array $data 
 */

function feed_generator_of_contents($data) {
       
    switch ($data['feed_type']) {
      case 'xml':
        $file_path = itg_syndication_generate_xml($data);
        break;
      case 'rss':
        $file_path = itg_syndication_generate_rss($data);
        break;
      case 'mrss':

        break;
      case 'ussd':

        break;
      case 'sms':

        break;
      case 'stf':
        watchdog('syndication_stf', 'I am in queue!');
        break;
      case 'html':
        $file_path = itg_syndication_mail_syndication($data);
        break;
    }
      

  return $file_path;
}

/**
 * Function for generating xml files.
 * @param array $data
 * @param array $syndication_node
 */
function itg_syndication_generate_xml($data) {
  $syndication_node = unserialize($data->syndication);
  $file_path = drupal_realpath('public://');
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->formatOutput = true;
  $root = $dom->createElement('syndication');
  $dom->appendChild($root);

  foreach ($syndication_node as $key => $val) {
    $node = node_load($val);
    $result = $dom->createElement('content');
    $root->appendChild($result);
    $result->setAttribute('id', $key + 1);
    $result->appendChild($dom->createElement('title', $node->title));
    $result->appendChild($dom->createElement('body', strip_tags($node->body[LANGUAGE_NONE][0]['value'])));
    $result->appendChild($dom->createElement('headline', strip_tags($node->body[LANGUAGE_NONE][0]['value'])));
  }

  $dom->save($file_path . '/' . $data->title . '.xml') or die('XML Create Error');
  drupal_set_message('xml file has been created.', 'status');
  
  $delivery_mode = $data['delivery_mode'];

  if (!filter_var($delivery_mode, FILTER_VALIDATE_EMAIL) === false) {
    $delivery_mode_type = 'Email';
  } else {
      $delivery_mode_type = 'FTP';
  }
  
  // Decide sharing mode
  switch ($delivery_mode_type) {
    // 1. Fetch web URL (our server)
    case '1':
      break;
    // 2. Via FTP location
      
    case 'FTP':
      itg_syndication_ftp_syndication($data, $file_path . '/' . $data->title . '.xml');
      break;
    // 3. Via Email
    case 'Email':
      itg_syndication_mail_syndication($data, $file_path . '/' . $data->title . '.xml');
      break;
  }
  
  return  $file_path . '/' . $data->title . '.xml';
}

/**
 * Callback function to send syndication by mail attachment.
 * @param type $data
 * @param type $syndication_node
 */
function itg_syndication_mail_syndication($data, $file_path) {
  $attachment = array(
    'filepath' => $file_path,
  );
  $params = array(
    'key' => 'itg_syndication',
    'to' => $data['delivery_mode'],
    'from' => 'noreply@indiatoday.com',
    'subject' => 'Test email',
    'body' => 'Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industrys standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.',
    'attachment' => $attachment,
    'headers' => array(
      'MIME-Version: 1.0' . "\r\n",
      'Content-type: text/html; charset=iso-8859-1' . "\r\n",
      'To: '.$data['delivery_mode'] . "\r\n",
      'From: India Today <noreply@indiatoday.com>' . "\r\n",
    ),
  );
  $language = language_default();

  drupal_mail('itg_syndication', $params['key'], $params['to'], $language, $params, $params['from']);
}

/**
 * Implements hook_mail().
 * @param string $key
 * @param string $message
 * @param array $params
 */
function itg_syndication_mail($key, &$message, $params) {
  if ($key == 'itg_syndication') {
    $message['subject'] = $params['subject'];
    $message['body'][] = $params['body'];

    // Add attachment when available.
    if (isset($params['attachment'])) {
      $message['params']['attachments'][] = $params['attachment'];
    }
  }
}

function itg_syndication_ftp_syndication($data, $file_path) {  
  $ftp_details = get_ftp_details_by_client($data['client_title'], $data['delivery_mode']);
  
  $file = $file_path;
  $remote_file = 'readme.txt';
  
  $ftp_server = $ftp_details->field_syndication_ftp_url_value;
  $ftp_user_name = $ftp_details->field_syndication_ftp_username_value;
  $ftp_user_pass = $ftp_details->field_syndication_ftp_password_value;
  
  // set up basic connection
  $conn_id = ftp_connect($ftp_server);

  // login with username and password
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass);

  // upload a file
  if (ftp_put($conn_id, $remote_file, $file, FTP_ASCII)) {
   echo "successfully uploaded $file\n";
  } else {
   echo "There was a problem while uploading $file\n";
  }

  // close the connection
  ftp_close($conn_id);
}

function get_ftp_details_by_client($client_name, $ftp_name) {
  
  $client = explode('-', $client_name);
  $client_description = $client[1];
  $client_title = $client[0];
  $itg_query = db_select('node', 'n');
  $itg_query->condition('n.title', $client_description)
      ->fields('n', array('nid'))
      ->fields('ftp', array('field_syndication_ftp_details_value'))
      ->fields('ftp_name', array('field_syndication_ftp_name_value'))
      ->fields('ftp_url', array('field_syndication_ftp_url_value'))
      ->fields('ftp_username', array('field_syndication_ftp_username_value'))      
      ->fields('ftp_pass', array('field_syndication_ftp_password_value'));
  $itg_query->join('field_data_field_syndication_client_title', 'sc', 'n.nid = sc.entity_id');
  $itg_query->join('taxonomy_term_data', 'term', 'term.tid = sc.field_syndication_client_title_tid');
  $itg_query->join('field_data_field_syndication_ftp_details', 'ftp', 'ftp.entity_id = n.nid');
  $itg_query->join('field_data_field_syndication_ftp_url', 'ftp_url', 'ftp_url.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->join('field_data_field_syndication_ftp_username', 'ftp_username', 'ftp_username.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->join('field_data_field_syndication_ftp_password', 'ftp_pass', 'ftp_pass.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->join('field_data_field_syndication_ftp_name', 'ftp_name', 'ftp_name.entity_id = ftp.field_syndication_ftp_details_value');
  $itg_query->condition('term.name', $client_title);
  $itg_query->condition('ftp_name.field_syndication_ftp_name_value', $ftp_name);
  $itg_result = $itg_query->execute()->fetchAll();
 
  
  return $data;
}