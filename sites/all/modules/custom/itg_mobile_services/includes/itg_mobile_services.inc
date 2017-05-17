<?php

/**
 * Inc file contains the functions
 */

/**
 * Feed generator of selected contents
 * @param object $node
 * @return bool
 */
function itg_mobile_services_feed_generator_of_contents($node) {
  // get service id  
  $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
  // get astro exist
  $astro = itg_mobile_services_check_astro_service($association_nid);

  $frequency_date_array = explode(' ', $node->field_service_frequency_date[LANGUAGE_NONE][0]['value']);
  $today_date = date('Y-m-d');

  // load service node  
  $service_details = node_load($association_nid);
  // service title
  $service_title = str_replace(' ', '-', $service_details->title);
  // xml format
  $delivery_mode = $service_details->field_service_delivery_mode[LANGUAGE_NONE][0]['value'];
  // delivery mode
  $xml_format = $service_details->field_mobile_xml_format[LANGUAGE_NONE][0]['xml'];

  $get_clients_id = get_clients_id($association_nid);
  // client ids
  $client_id_array = $get_clients_id['target_id'];
  // service association id
  $service_association_id = $get_clients_id['service_association_id'];
  $service_association_info = node_load($service_association_id);
  // service association data
  if (is_object($service_association_info) && count($service_association_info) > 0) {
    $content_count = isset($service_association_info->field_service_content_count[LANGUAGE_NONE]) ? $service_association_info->field_service_content_count[LANGUAGE_NONE][0]['value'] : '';
    $field_header = isset($service_association_info->field_header[LANGUAGE_NONE]) ? $service_association_info->field_header[LANGUAGE_NONE][0]['value'] : '';
    $field_footer = isset($service_association_info->field_footer[LANGUAGE_NONE]) ? $service_association_info->field_footer[LANGUAGE_NONE][0]['value'] : '';
  }

  // Load itg_mobile_services.inc from the node module.
  module_load_include('inc', 'itg_mobile_services', 'includes/itg_mobile_services.feed_generate');
  $error = FALSE;
  $validate_content = validate_content_count($node->nid);

  if (isset($validate_content)) {
    $data = unserialize($validate_content);
    if (is_array($data['clients']) && count($data['clients']) > 0) {
      foreach ($data['clients'] as $key => $val) {
        if ($content_count <= $val && empty($error)) {
          drupal_set_message(t('Feed cannot be generated. You have already exceeded feed count limit. Please increase content count limit from service association page.'), 'error');
          $error = TRUE;
        }
      }
    }
  }

  if (!empty($error)) {
    return FALSE;
  }
  else {

    if ($astro) {
      switch ($delivery_mode) {
        case 1: // xml
          $file_path = itg_mobile_services_generate_xml($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
        case 2: // rss
          $file_path = itg_mobile_services_generate_rss($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
        case 3: // mrss
          $file_path = itg_mobile_services_generate_astro_mrss($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
        case 4: //ussd
          $file_path = itg_mobile_services_generate_ussd($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
        case 5: //sms
          $file_path = itg_mobile_services_generate_astro_sms($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
        case 6: // Simple Text Feed
          $file_path = itg_mobile_services_generate_feed($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
      }
    }
    else {
      switch ($delivery_mode) {
        case 1: // xml
          $file_path = itg_mobile_services_generate_xml($node, $service_title, $field_header, $field_footer, $xml_format, NULL);
          break;
        case 2: // rss
          $file_path = itg_mobile_services_generate_rss($node, $service_title, $field_header, $field_footer, $xml_format, NULL);
          break;
        case 3: // mrss
          $file_path = itg_mobile_services_generate_mrss($node, $service_title, $field_header, $field_footer, $xml_format, NULL);
          break;
        case 4: //ussd
          $file_path = itg_mobile_services_generate_ussd($node, $service_title, $field_header, $field_footer, $xml_format, NULL);
          break;
        case 5: //sms
          $file_path = itg_mobile_services_generate_sms($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
        case 6: // Simple Text Feed
          $file_path = itg_mobile_services_generate_feed($node, $service_title, $field_header, $field_footer, $xml_format, $astro);
          break;
      }
    }


    foreach ($client_id_array as $client_id) {
      $client_info = node_load($client_id);
      if (is_object($client_info) && count($client_info) > 0) {
        $content_sharing_mode = isset($client_info->field_content_sharing_mode[LANGUAGE_NONE]) ? $client_info->field_content_sharing_mode[LANGUAGE_NONE][0]['value'] : '';
        // Decide sharing mode
        switch ($content_sharing_mode) {
          // 1. Fetch web URL (our server)
          case '1':
            $service_fetch_link = isset($client_info->field_service_fetch_link[LANGUAGE_NONE]) ? $client_info->field_service_fetch_link[LANGUAGE_NONE][0]['value'] : '';
            if ($frequency_date_array[0] <= $today_date) {
              itg_mobile_web_url_mobile($service_fetch_link, $file_path, 1);
            }
            else {
              itg_mobile_web_url_mobile($service_fetch_link, $file_path, 0);
            }

            break;
          case 2: // 2. Via FTP location
            if ($frequency_date_array[0] <= $today_date) {
              $ftp_ip_address = isset($client_info->field_ftp_ip_address[LANGUAGE_NONE]) ? $client_info->field_ftp_ip_address[LANGUAGE_NONE][0]['value'] : '';
              $ftp_username = isset($client_info->field_ftp_username[LANGUAGE_NONE]) ? $client_info->field_ftp_username[LANGUAGE_NONE][0]['value'] : '';
              $ftp_password = isset($client_info->field_ftp_password[LANGUAGE_NONE]) ? $client_info->field_ftp_password[LANGUAGE_NONE][0]['value'] : '';
              $data = array('ftp_ip_address' => $ftp_ip_address, 'ftp_username' => $ftp_username, 'ftp_password' => $ftp_password);
              itg_mobile_services_ftp_feeds($data, $file_path);
            }

            break;
          case 3: // 3. Via Email
            if ($frequency_date_array[0] <= $today_date) {
              $service_email_address = isset($client_info->field_service_email_address[LANGUAGE_NONE]) ? $client_info->field_service_email_address[LANGUAGE_NONE][0]['value'] : '';
              itg_mobile_services_mail($service_email_address, $file_path);
            }

            break;
        }

        $client_array[$client_id] = 1;
      }
    }

    if ($frequency_date_array[0] <= $today_date) {
      itg_mobile_cron_after_feed_generate($node, $client_array, $content_count, $file_path, 1);
    }
    else {
      itg_mobile_cron_after_feed_generate($node, $client_array, $content_count, $file_path, 0);
    }
  }
}

/**
 * Callback function to send mobile feeds by mail with attachment.
 * @param string $service_email_address
 * @param string $file_path
 */
function itg_mobile_services_mail($service_email_address, $file_path) {
  $attachment = array(
    'filepath' => $file_path,
  );
  $params = array(
    'key' => 'itg_syndication',
    'to' => $service_email_address,
    'from' => 'noreply@indiatoday.com',
    'subject' => 'Test email',
    'body' => 'Lorem Ipsum is simply dummy text of the printing and typesetting industry.',
    'attachment' => $attachment,
    'headers' => array(
      'MIME-Version: 1.0' . "\r\n",
      'Content-type: text/html; charset=iso-8859-1' . "\r\n",
      'To: ' . $service_email_address . "\r\n",
      'From: India Today <noreply@indiatoday.com>' . "\r\n",
    ),
  );
  $language = language_default();
  drupal_mail('itg_syndication', $params['key'], $params['to'], $language, $params, $params['from']);
}

/**
 * function get_clients_id().
 * @param int $association_nid
 * @return array $result
 */
function get_clients_id($association_nid) {
  $query = db_select('node', 'node')->fields('cs', array('field_client_selection_target_id'));
  $query->fields('sat', array('entity_id'));
  $query->leftJoin('field_data_field_client_selection', 'cs', "node.nid = cs.entity_id");
  $query->leftJoin('field_data_field_service_association_title', 'sat', "node.nid = sat.entity_id");
  $query->condition('sat.field_service_association_title_target_id', $association_nid, '=');
  $query->condition('node.type', array('client_service_association'), 'IN');
  $query->range(0, 20);
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $target_id[] = $record['field_client_selection_target_id'];
    $service_association_id = $record['entity_id'];
  }
  return $result = array('target_id' => $target_id, 'service_association_id' => $service_association_id);
}

/**
 * function get_content_sharing_mode().
 * @param int $entity_id
 * @return int
 */
function get_content_sharing_mode($entity_id) {
  if (isset($entity_id)) {
    $query = db_select('field_data_field_content_sharing_mode', 'csm')->fields('csm', array('field_content_sharing_mode_value'));
    $query->condition('csm.entity_id', $entity_id, '=');
    $query->range(0, 1);
    $result = $query->execute();
    $record = $result->fetchAssoc();
  }
  return isset($record['field_content_sharing_mode_value']) ? $record['field_content_sharing_mode_value'] : '';
}

/**
 * function to feed for mobile services by ftp.
 * @param array $data
 * @param array $file
 */
function itg_mobile_services_ftp_feeds($data, $file) {
  $file_array = explode('/', $file);
  $last = count($file_array) - 1;
  $remote_file = $file_array[$last]; // 'readmefeeds.txt';

  $ftp_server = $data['ftp_ip_address'];
  $ftp_user_name = $data['ftp_username'];
  $ftp_user_pass = $data['ftp_password'];

  // set up basic connection
  $conn_id = ftp_connect($ftp_server) or die("Couldn't connect to $ftp_server");
  // login with username and password
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass) or die("You do not have access to this ftp server!");
  if ((!$conn_id) || (!$login_result)) {
    echo "FTP connection has failed";
    exit;
  }
  // turn passive mode on
  ftp_pasv($conn_id, TRUE);
  $upload = ftp_put($conn_id, $remote_file, $file, FTP_BINARY);
  if (!$upload) {
    echo "There was a problem while uploading $file\n";
  }
  else {
    echo "successfully uploaded $file\n";
  }
  // close the connection
  ftp_close($conn_id);
}

/**
 * function validate_content_count().
 * @param int $nid
 * @return string
 */
function validate_content_count($nid) {
  $record = array();
  if (isset($nid)) {
    $query = db_select('itg_cron_time_scheduler', 's');
    $query->fields('s', array('cron_details'));
    $query->condition('s.cron_type', 'vas_service_content', '=');
    $query->condition('s.content_id', $nid, '=');
    $query->range(0, 1);
    $result = $query->execute();
    $record = $result->fetchAssoc();
  }
  return isset($record['cron_details']) ? $record['cron_details'] : '';
}

/**
 * function for cron time update
 * @param object $node
 * @param array $client_array
 * @param int $content_count
 * @param string $file_path
 * @param int $status
 */
function itg_mobile_cron_after_feed_generate($node, $client_array, $content_count, $file_path, $status) {
  // get service id  
  $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
  $frequency_from_date = $node->field_service_frequency_date[LANGUAGE_NONE][0]['value'];
  $frequency = $node->field_service_frequency[LANGUAGE_NONE][0]['value'];

  $scheduler_time = strtotime($frequency_from_date);

  $nid = $node->nid;
  $validate_content = validate_content_count($nid);

  if (isset($validate_content)) {
    $data = unserialize($validate_content);
    if (is_array($data['clients']) && count($data['clients']) > 0) {
      foreach ($data['clients'] as $key => $val) {
        if ($content_count >= $val) {
          $client[$key] = $val + 1;
        }
      }
    }
    else {
      $client = $client_array;
    }

    $details_array = array('service_id' => $association_nid,
      'frequency' => $frequency,
      'feed_type' => $node->type,
      'file_name' => '', // TODO: Check file_name usage.
      'service_content_count' => $content_count,
      'clients' => $client,
      'file_path' => $file_path
    );

    $details = serialize($details_array);
    if ($nid) {
      db_delete('itg_cron_time_scheduler')
          ->condition('cron_type', 'vas_service_content', '=')
          ->condition('content_id', $nid, '=')
          ->execute();

      $query = db_insert('itg_cron_time_scheduler');
      $query->fields(array(
        'content_id' => $node->nid,
        'fid' => $node->nid,
        'cron_type' => $node->type,
        'last_cron_time' => $scheduler_time,
        'scheduler_time' => $scheduler_time,
        'cron_details' => $details,
        'status' => $status
      ));
      $query->execute();
    }
  }
  else {
    $details_array = array('service_id' => $association_nid,
      'frequency' => $frequency,
      'feed_type' => $node->type,
      'file_name' => '', // TODO: check $file_name
      'service_content_count' => $content_count,
      'clients' => $client_array,
      'file_path' => $file_path
    );

    $details = serialize($details_array);
    $query = db_insert('itg_cron_time_scheduler');
    $query->fields(array(
      'content_id' => $node->nid,
      'fid' => $node->nid,
      'cron_type' => $node->type,
      'last_cron_time' => $scheduler_time,
      'scheduler_time' => $scheduler_time,
      'cron_details' => $details,
      'status' => $status
    ));
    $query->execute();
  }
}

/**
 * function to feed for syndication by ftp.
 * @param string $service_fetch_link
 * @param string $file_path
 * @param int $status
 */
function itg_mobile_web_url_mobile($service_fetch_link, $file_path, $status) {
  $timestamp = date("Y-m-d H:i:s");
  $query = db_insert('itg_syndication_feed_url');
  $query->fields(array(
    'xml_name' => $file_path,
    'client_feed_url' => $service_fetch_link,
    'created_date' => $timestamp,
    'status' => $status
  ));
  $query->execute();
}


/**
 * function for show list of feed by url
 * @return string
 */
function itg_mobile_get_feed_byurl() {
  global $base_url;
  $build = array();
  $request_url = explode('/', $_SERVER['REQUEST_URI']);
  unset($request_url[0]);
  
  $url = $base_url . '/' . $request_url[1] . '/' . $request_url[2] . '/' . $request_url[3];
  $path = file_create_url('public://');
  $query = db_select('itg_syndication_feed_url', 'feed')->extend('PagerDefault');
  # get the desired fields from the database
  $query->condition('feed.client_feed_url', $url)
      ->condition('feed.status', 1, '=');

  $search_box = drupal_render(drupal_get_form('search_form'));
  # set the database table
  if (isset($_POST['max']['date'])) {
    $mx_date = str_replace('/', '-', $_POST['max']['date']);
    $min_date = str_replace('/', '-', $_POST['min']['date']);

    $max_date = date('Y-m-d', strtotime($mx_date)) . ' 00:00:00';
    $min_date = date('Y-m-d', strtotime($min_date)) . ' 00:00:00';

    $query->condition('feed.created_date', $min_date, '>=');
    $query->condition('feed.created_date', $max_date, '<=');
  }

  $query->fields('feed', array('id', 'xml_name', 'created_date'))
      ->orderBy('created_date', 'DESC')
      ->limit(10);
  # execute the query
  $results = $query->execute();
  $header = array(
    '1' => t('S. No.'),
    '2' => array('data' => t('Service Name'), 'sort' => 'desc'),
    '3' => t('Frequency'),
    '4' => t('Frequency Date'),
    '5' => t('Created Date'),
    '6' => t('Link'),
  );
  # build the table fields
  $rows = array();
  $i = 1;
  foreach ($results as $row) {

    $real_path = substr($path, 0, -1) . $row->xml_name;
    $files_url = explode('mobile/', $real_path);
    $file_url = explode('/', $files_url[1]);
    $file_url_array = explode('_', $file_url[2]);
    $file_date_array = explode('.', $file_url_array[3]);
    $frequency_type_arr = explode('/', $file_url_array[0]);
    $frequency_type = ($frequency_type_arr[count($frequency_type_arr) - 1]);
    $fq_date = explode('-to', $file_url_array[2]);
    $frequency_date = isset($fq_date[0]) ? date('d/m/Y', strtotime($fq_date[0])) : date('d/m/Y', strtotime($file_url_array[2]));
    $date_time = isset($file_url_array[0]) ? date('d/m/Y H:i:s', $file_date_array[0]) : '';
    $created_date = isset($row->created_date) ? date('d/m/Y H:i:s', strtotime($row->created_date)) : '';

    $rows[] = array($i,
      $file_url_array[1],
      $frequency_type,
      $frequency_date,
      $created_date,
      '<a href="' . $real_path . '" download> Click to Download </a>' . '</td>',
    );
    $i++;
  }
  // Format and print out the table.
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table'))));

  $build['content'] = array(
    'itg_mobile_services_search' => drupal_get_form('itg_mobile_services_search_form'),
    'itg_mobile_services_content' => array(
      '#markup' => $output,
    ),
  );
  # add the pager
  $build['pager'] = array(
    '#theme' => 'pager',
    '#weight' => 5,
  );

  return $build;
}

/**
 * 
 * @param type $form
 * @param type $form_state
 * @return string
 */
function itg_mobile_services_search_form($form, &$form_state) {
  $form['created']['min'] = array(
    '#type' => 'date_popup',
    '#title' => t('From'),
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '-1:0',
    '#attributes' => array(
      'readonly' => 'readonly'
    ),
  );

  $form['created']['max'] = array(
    '#type' => 'date_popup',
    '#title' => t('To'),
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '-1:0',
    '#attributes' => array(
      'readonly' => 'readonly'
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $request_url = explode('/', $_SERVER['REQUEST_URI']);
  unset($request_url[0]);
  unset($request_url[1]);
  $url = $base_url . '/' . $request_url[2] . '/' . $request_url[3] . '/' . $request_url[4];

  $form['actions']['cancel'] = array(
    '#markup' => l(t('Reset'), $url, array(
      'attributes' => array(
        'class' => 'button custom-url-search'
      )
    )),
    '#weight' => 9,
    '#value' => t('Reset')
  );


  return $form;
}

/**
 * 
 * @param type $form
 * @param array $form_state
 */
function itg_mobile_services_search_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * function itg_mobile_services_cron().
 * @return bool
 */
function itg_mobile_services_cron() {
  $query = db_select('itg_cron_time_scheduler', 's');
  $query->fields('s', array('content_id', 'cron_details', 'scheduler_time'));
  $query->condition('s.cron_type', 'vas_service_content', '=');
  $query->condition('s.status', 0, '=');
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $content_id = $record['content_id'];
    $cron_details = $record['cron_details'];
    $scheduler_time = $record['scheduler_time'];
    // service association id
    $node = node_load($content_id);
    $association_nid = $node->field_service_association_title[LANGUAGE_NONE][0]['target_id'];
    $get_clients_id = get_clients_id($association_nid);
    // client ids
    $client_id_array = $get_clients_id['target_id'];
    $today_date = strtotime("now");

    if ($scheduler_time <= $today_date) {
      $data = unserialize($cron_details);
      $file_path = $data['file_path'];

      db_update('itg_cron_time_scheduler')
          ->fields(array(
            'status' => 1
          ))
          ->condition('content_id', $content_id)
          ->execute();
      foreach ($client_id_array as $client_id) {
        $client_info = node_load($client_id);
        if (is_object($client_info) && count($client_info) > 0) {
          $content_sharing_mode = isset($client_info->field_content_sharing_mode[LANGUAGE_NONE]) ? $client_info->field_content_sharing_mode[LANGUAGE_NONE][0]['value'] : '';
          // Decide sharing mode
          switch ($content_sharing_mode) {
            // 1. Fetch web URL (our server)
            case '1':
              $service_fetch_link = isset($client_info->field_service_fetch_link[LANGUAGE_NONE]) ? $client_info->field_service_fetch_link[LANGUAGE_NONE][0]['value'] : '';

              db_update('itg_syndication_feed_url')
                  ->fields(array(
                    'status' => 1
                  ))
                  ->condition('client_feed_url', $service_fetch_link)
                  ->execute();
              break;
            case 2: // 2. Via FTP location
              $ftp_ip_address = isset($client_info->field_ftp_ip_address[LANGUAGE_NONE]) ? $client_info->field_ftp_ip_address[LANGUAGE_NONE][0]['value'] : '';
              $ftp_username = isset($client_info->field_ftp_username[LANGUAGE_NONE]) ? $client_info->field_ftp_username[LANGUAGE_NONE][0]['value'] : '';
              $ftp_password = isset($client_info->field_ftp_password[LANGUAGE_NONE]) ? $client_info->field_ftp_password[LANGUAGE_NONE][0]['value'] : '';
              $data = array('ftp_ip_address' => $ftp_ip_address, 'ftp_username' => $ftp_username, 'ftp_password' => $ftp_password);
              itg_mobile_services_ftp_feeds($data, $file_path);
              break;
            case 3: // 3. Via Email
              $service_email_address = isset($client_info->field_service_email_address[LANGUAGE_NONE]) ? $client_info->field_service_email_address[LANGUAGE_NONE][0]['value'] : '';
              itg_mobile_services_mail($service_email_address, $file_path);
              break;
          }
        }
      }
    }
  }
  return TRUE;
}
