<?php

/*
 * Inc file contains the functions
 */

/**
 * Implements hook_form_alter()
 * {@inheritdoc}
 */
function itg_syndication_form_alter(&$form, &$form_state, $form_id) {
  if (!empty($form_state['input']['magazine-name'])) {
    $magazine_id = $form_state['input']['magazine-name'];
  }
  if (isset($form_state['view']->name) && $form_state['view']->name == 'syndication_rule_listing') {
    $form['field_syndication_rule_title_value']['#options'] = itg_syndication_get_client("yes");
    unset($form['field_syndication_rule_title_value']['#options']['_none']);
    $options = $form['field_syndication_rule_title_value']['#options'];
    unset($form['field_syndication_rule_title_value']['#options']);
    $form['field_syndication_rule_title_value']['#options']['All'] = '- Any -';
    foreach($options as $keys=>$values) {
      $form['field_syndication_rule_title_value']['#options'][$keys] = $values;
    }
  }

  if ($form_id == 'views_form_syndication_feed_generator_page') {
    $form['actions']['submit']['#submit'][] = 'itg_syndication_selector_custom_submit';
    $form['#validate'][] = 'syndication_selector_custom_form_validate';
  }

  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'syndication_feed_pattern_listing') {
    if(!empty($form['field_syndication_feed_content_value']['#options']['photogallery'])) {
      $form['field_syndication_feed_content_value']['#options']['photogallery'] = t('Photogallery');
    }
  }
  
  // Add client dropdown to view
  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'syndication_feed_generator') {
    global $user, $base_url;
    $mag_option = '';
    // add js for issue dropdown ajax
    $settings = array();
    $settings['base_url'] = $base_url;
    $settings['uid'] = $user->uid;
    drupal_add_js(array('itg_syndication' => array('settings' => $settings)), array('type' => 'setting'));
    drupal_add_js(drupal_get_path('module', 'itg_syndication') . '/js/itg_syndication.js', array('weight' => 1));

    // hide save button
    if (!(isset($_GET['type']) && $_GET['type'] != 'article')) {
      drupal_add_js('jQuery(document).ready(function() {
              jQuery("#edit-actions").hide();              
            });', array('type' => 'inline', 'scope' => 'footer'));
    }

    $form['type']['#options']['article'] = '- Select -';

    $form['client_title'] = array(
      '#type' => 'select',
      '#title' => t('Select Client'),
      '#options' => itg_syndication_get_client('yes'),
      '#default_value' => '_none',
      '#validated' => true,
      '#weight' => 10,
    );

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

    $form['magazine-name'] = array(
      '#type' => 'select',
      '#title' => t('Select magazine'),
      '#options' => itg_syndication_get_issue_list('magazine'),
      '#default_value' => '_none',
      '#weight' => 3,
      '#states' => array(
        'visible' => array(
          ':input[name="type"]' => array('value' => 'magazine'),
        ),
      ),
    );

    if (isset($magazine_id)) {
      $mag_option = itg_magazine_custom_callback($magazine_id);
    }

    $form['issue'] = array(
      '#type' => 'select',
      '#title' => t('Select Issue'),
      '#options' => $mag_option,
      '#weight' => 4,
      '#states' => array(
        'visible' => array(
          ':input[name="type"]' => array('value' => 'magazine'),
        ),
      ),
    );

    $form['type']['#weight'] = 2;
    $form['submit']['#weight'] = 4;


    views_syndication_insert_field($form, 'client_title', 0);
    views_syndication_insert_field($form, 'filter-type', 3);

    drupal_add_js('jQuery(document).ready(function() {
              jQuery("#edit-field-story-issue-date-value-wrapper").hide();
              jQuery("#edit-issue").change(function() {                
                jQuery("#edit-field-story-issue-date-value-value-date").val(jQuery("#edit-issue").val());
              });
            });', array('type' => 'inline', 'scope' => 'footer'));
  }
  else if ($form_id == 'views_form_syndication_feed_generator_page' && (isset($_GET['type']) && $_GET['type'] != 'article')) {
    if (isset($_GET['client_title'])) {
      $op = itg_syndication_get_mode($_GET['client_title']);
    }
    else {
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

    $form['actions']['download_feed'] = array('#type' => 'submit',
      '#value' => t('Download Feed'),
      '#name' => t('download_feed'),
      '#submit' => array('itg_syndication_selector_custom_submit'),);

    $form['actions']['submit']['#value'] = 'Generate feed and Send it to client';

    // for feed download 
    $form['feed_download_value'] = array(
      '#type' => 'textfield',
      '#title' => t('Select Feed Type'),
      '#weight' => 99,
    );

    $form['#after_build'][] = 'itg_syndication_feed_download_after_build';
  }
  elseif ($form_id == 'views_exposed_form' && $form_state['view']->name == 'syndication_feed_pattern_listing') {
    $form['field_syndication_feed_clients_value'] = array(
      '#type' => 'select',
      '#options' => itg_syndication_get_client("yes"),
      '#default_value' => '_none',
      '#validated' => true,
      '#weight' => 1,
    );
  }
  // View autocomplete title field.
  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'syndication_client') {
    $form['title']['#autocomplete_path'] = 'content-title-list/syndication_client/autocomplete';
  }
  // Code to ristrict future date on client creation.
  if($form_id == 'views_form_syndication_feed_generator_page') {
   $form['client_delivery_mode']['#title'] = t("Select delivery end point");
   $form['client_delivery_mode']['#prefix'] = '<div id="itg-cutom-pager">'.theme('pager').'</div>';
    drupal_add_js('
      jQuery(function() {
        jQuery( "#edit-changed-max-datepicker-popup-0 , #edit-changed-min-datepicker-popup-0" ).datepicker({  
          dateFormat: \'dd/mm/yy\',
          changeMonth:true,
          changeYear:true,
          maxDate: new Date() ,
        });
      });
    ',"inline");
    //code pager display
    drupal_add_js('jQuery(document).ready(function() {              
                   jQuery(".item-list").hide();
                   jQuery("div").parents("#itg-cutom-pager").find(".item-list").show();                   
                });', array('type' => 'inline', 'scope' => 'footer'));
  }
}

/**
 * After build callback function.
 * @param array $form
 * @param array $form_state
 * @return array $form
 */
function itg_syndication_feed_download_after_build($form, &$form_state) {

  drupal_add_js('jQuery(document).ready(function() {
              jQuery(".form-item-feed-download-value").hide();
              
              jQuery("#edit-download-feed").click(function() {
                jQuery ("#edit-changed-min-datepicker-popup-0").val("");
                jQuery ("#edit-changed-max-datepicker-popup-0").val("");
                jQuery("#edit-feed-download-value").val("yes");                
              });
              
              jQuery("#edit-submit").click(function() {
                jQuery ("#edit-changed-min-datepicker-popup-0").val("");
                jQuery ("#edit-changed-max-datepicker-popup-0").val("");
                jQuery("#edit-feed-download-value").val("");                
              });
              
            });', array('type' => 'inline', 'scope' => 'footer'));

  return $form;
}

/**
 * Submit callback for row selector form
 * @param array $form
 * @param array $form_state
 */
function itg_syndication_selector_custom_submit($form, &$form_state) {
  global $base_url;
  $client_name = check_plain($form_state['values']['itg_row_selector_client']);
  $web_property = check_plain($form_state['values']['itg_row_selector_web_property']);
  $issue = check_plain($form_state['values']['itg_row_selector_issue']);
  $delivery_mode = check_plain($form_state['values']['client_delivery_mode']);
  $feed_type = check_plain($form_state['values']['feed_type']);

  $syndication_node = array_filter($form_state['values']['itg_row_selector']);

  $data = array(
    'web_property' => $web_property,
    'client_title' => $client_name,
    'delivery_mode' => $delivery_mode,
    'feed_type' => $feed_type,
    'syndication' => serialize($syndication_node),
  );

  $file_path = feed_generator_of_contents($data);

  $file_url = $file_path['file_path'];
  $real_path = $file_path['real_path'];
  // insert records into database table itg_syndication_manual_feed_details.

  $syndication_data = array(
    'web_property' => $web_property,
    'client_title' => $client_name,
    'delivery_mode' => $delivery_mode,
    'feed_type' => $feed_type,
    'syndication' => serialize($syndication_node),
    'feed_file_path' => $file_url,
    'created' => format_date(time(), 'custom', 'Y-m-d'),
  );

  if (isset($file_url)) {
    $query = db_insert('itg_syndication_manual_feed_details')->fields($syndication_data)->execute();
  }

  // for feed download
  if ($form_state['values']['feed_download_value'] == 'yes') {
    // $link_val = 'Click to Download. <a href="'.$realpath.'" download>Import Feed</a>';
    // drupal_set_message($link_val, 'status');
    // send file to browser as a download dialog
    // no content can be output prior to these header() calls
    header('Content-type: application/octet-stream');
    header('Content-Disposition: attachment; filename="' . basename($real_path) . '"');
    header('Content-Length: ' . filesize($real_path));
    header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
    //header("Expires: Sat, 26 Jul 1997 05:00:00 GMT");

    echo file_get_contents($real_path);
    exit; // terminate script
  }
  else {
    drupal_set_message('Successfully feed Generated  and Sent to client.', 'status');
  }
}

/**
 * Implementation of hook_views_query_alter
 * {@inheritdoc}
 */
function itg_syndication_views_query_alter(&$view, &$query) {

  if (isset($view->name) && $view->name === 'syndication_feed_generator') {
    foreach ($query->where[1]['conditions'] as $key => $val) {
      if (isset($val['field']) && $val['field'] == 'node.type' && $val['value'][0] == 'magazine') {
        $query->where[1]['conditions'][$key]['value'][0] = 'story';
      }
      else if (isset($val['field']) && $val['field'] == 'node.type' && $val['value'][0] == 'All') {
        $query->where[1]['conditions'][$key]['value'][0] = '_none';
      }
    }

    if (!empty($_GET['changed']['max']['date'])) {
      $max_conditions_array = array();
      $min_date = str_replace('/', '-', $_GET['changed']['min']['date']);
      $max_date = str_replace('/', '-', $_GET['changed']['max']['date']);

      $min = strtotime(str_replace('/', '-', $min_date));
      $max = strtotime(date('d-m-Y', strtotime($max_date . "+1 days")));

      $max_date_condition = "BETWEEN " . $min . " AND " . $max;

      if (isset($view->query->where[1]['conditions'])) {
        foreach ($query->where[1]['conditions'] as $idx => $condition) {
          if (!is_object($condition['field']) && $condition['operator'] == 'formula') {
            if (empty($condition['value'])) {
              $max_conditions_array = explode('BETWEEN', $view->query->where[1]['conditions'][$idx]['field']);
              $view->query->where[1]['conditions'][$idx]['field'] = $max_conditions_array[0] . $max_date_condition;
            }
          }
        }
      }
    }
  }

  if (isset($view->name) && $view->name === 'syndication_feed_pattern_listing' && $view->current_display == 'page') {
    foreach ($query->where[1]['conditions'] as $key => $condition) {
      $field_syndication_feed_clients_value = filter_input(INPUT_GET, 'field_syndication_feed_clients_value');
      if ($field_syndication_feed_clients_value == '_none' && $condition['field'] == 'field_data_field_syndication_feed_clients.field_syndication_feed_clients_value') {
        unset($query->where[1]['conditions'][$key]);
      }
    }
  }
}

/**
 * syndication selector custom form validate
 * {@inheritdoc}
 */
function syndication_selector_custom_form_validate($form, &$form_state) {

  if ($form_state['values']['client_delivery_mode'] == '_none' && $form_state['values']['feed_download_value'] != 'yes') {
    form_set_error('client_delivery_mode', t('Please select Delivery Mode.'));
  }

  if (empty($form_state['values']['itg_row_selector_client'])) {
    form_set_error('client_title', t('Please select Client.'));
  }
  
  if($form_state['values']['feed_type'] == 'ussd' 
      || $form_state['values']['feed_type'] == 'sms'
      || $form_state['values']['feed_type'] == 'stf'
      || $form_state['values']['feed_type'] == 'html'
      ) {
    form_set_error('feed_type', t('Feed type format does not exists to generate.'));
  }
}

/**
 * syndication filter custom form validate
 * {@inheritdoc}
 */
function syndication_filter_custom_form_validate($form, &$form_state) {
  if ($form_state['values']['client_delivery_mode'] == '_none' && $form_state['values']['feed_download_value'] != 'yes') {
    form_set_error('client_delivery_mode', t('Please select Delivery Mode.'));
  }
}

/**
 * Implements views header link 
 * {@inheritdoc}
 */
function itg_syndication_views_pre_render(&$view) {
  if ($view->name == "syndication_feed_generator") {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $view->attachment_before = $header_content;
  }
  else if ($view->name == "syndication_feed_pattern_listing") {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Create Syndication Pattern'), 'node/add/syndication-feed-from-pattern', array('query' => array('destination' => 'syndication-feed-pattern-listing')));
    $view->attachment_before = $header_content;
  }
}

/**
 * Insert the given field into a particular position in the form.
 * 
 * @param $form
 *   The form which is going to have the field inserted. Passed by reference.
 * @param string $file_key
 *   The key in the form where the field is to be found. e.g. if $form['foo']
 *   contains the field, then use 'foo' as this parameter.
 * @param int $insert_index
 *   Index of where in the form the field should be placed.
 */
function views_syndication_insert_field(&$form, $field_key, $insert_index) {
  // this value determines the position of the new element.
  $element_to_insert = array();
  $element_to_insert[$field_key] = array(
    'value' => $field_key,
  );
  $form_info_top = array_slice($form['#info'], 0, $insert_index);
  $form_info_bottom = array_slice($form['#info'], $insert_index);
  $new_form_info = $form_info_top + $element_to_insert + $form_info_bottom;
  $form['#info'] = $new_form_info;
}
