<?php

/**
 * Function for ajax request callback
 */

function itg_live_blog_custom() {
  global $base_url, $user;
  $arg = arg();

  drupal_add_js(drupal_get_path('theme', 'itg') . '/js/budget_predictor/jquery1.7.1.min.js', array('preprocess' => false, 'weight' => 4, 'scope' => 'footer'));
  drupal_add_js(drupal_get_path('theme', 'itg') . '/js/bootstrap.min.js', array('preprocess' => false, 'weight' => 5, 'scope' => 'footer'));
  drupal_add_css('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css', array('type' => 'external'));
  
 // $settings = array();
 // $settings['base_url'] = $base_url;
 // drupal_add_js(array('itg_breaking_new_form' => array('settings' => $settings)), array('type' => 'setting'));
 // drupal_add_js(drupal_get_path('module', 'itg_breaking_news') . '/js/itg_breaking_news_custom_form.js', array('preprocess' => false, 'scope' => 'footer'));
  
  return theme('itg_live_blog_custom_form', array('data' => $data));

}

function itg_manage_breking_news($form, &$form_state, $bid, $type) {
  $arg = arg();
   /*
   if (empty($arg[2])) {
     return '';
   } 
    * 
    */
  if (isset($arg) && ($arg[1] == 'edit' || $arg[2] == 'ajax')) {
    $query = db_select('itg_live_blog', 'm');
    if($arg[2] == 'ajax') {
      $query->condition('m.bid', $arg[3], '=');
    } else {
      $query->condition('m.bid', $arg[2], '=');
    }
    # get the desired fields from the database
    $query->fields('m', array('bid','blog_entity_id', 'blog_type', 'blog_title', 'blog_description', 'blog_breaking_band', 'blog_notification', 'blog_publish_time','blog_highlight_status'));
    # execute the query
    $results = $query->execute()->fetchObject();
  }
  elseif (isset($arg) && $arg[1] == 'add') {
    $blog_entity_id = $arg[2];
  }
 
  $form = array();
  // To make the fieldset collapsible
  $form['breaking'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content details'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => FALSE,  // Added
  );
   
   $form['breaking']['blog_title']['#prefix'] = '<div id="blog_title_replace_wrapper_test">';
   $form['breaking']['blog_title']['#suffix'] = '</div>';
   $form['breaking']['blog_description']['#prefix'] = '<div id="blog_description_replace_wrapper">';
   $form['breaking']['blog_description']['#suffix'] = '</div>';
   
   $form['breaking']['blog_title'] = array(
    '#type' => 'textfield',
    '#prefix' => '<div id="blog_title_replace_wrapper">',
    '#title' => t('Title'),
    '#default_value' => isset($results->blog_title) ? $results->blog_title : '',
    // '#required' => TRUE,
    '#suffix' => '</div>',
  );
   
  $form['breaking']['blog_description'] = array(
    '#type' => 'text_format',
    '#title' => 'Description',
    '#rows' => 5,
    '#resizable' => FALSE,
    '#default_value'=> isset($results->blog_description) ? $results->blog_description : '',
    '#format' => 'full_html',
  );
    
  $form['breaking']['blog_breaking_band'] = array(
    '#type' => 'radios',
    '#title' => t('Blog breaking band'),
    '#options' => array(1 => "Active", 2 => "Inactive"),
    '#default_value' => ($results->blog_breaking_band) ? $results->blog_breaking_band : 1,
    // '#required' => TRUE
  );
  
  $form['breaking']['blog_notification'] = array(
    '#type' => 'radios',
    '#title' => t('Blog Notification'),
    '#options' => array(1 => "Active", 2 => "Inactive"),
    '#default_value' => ($results->blog_notification) ? $results->blog_notification : 1,
    // '#required' => TRUE
  );
 
   $publish_time = date('H:i');
   $form['breaking']['blog_publish_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Publish Time'),
    '#default_value' => ($results->blog_notification) ? $results->blog_notification : $publish_time,
    '#date_format' => 'H:i',
    '#size' => 10,
  );
  
  
  $form['breaking']['blog_highlight_status'] = array(
    '#type' => 'radios',
    '#title' => t('Blog highlight status'),
    '#options' => array(1 => "Active", 2 => "Inactive"),
    '#default_value' => ($results->blog_highlight_status) ? $results->blog_highlight_status : 1,
    // '#required' => TRUE
  );
  
  $form['breaking']['blog_entity_id'] = array(
    '#type' => 'hidden',
    '#value' => ($results->blog_entity_id) ? $results->blog_entity_id : $blog_entity_id,
  );
  
   $form['breaking']['bid'] = array(
    '#type' => 'hidden',
    '#value' => ($results->bid) ? $results->bid : '',
  );
  
   /*
  if ($type == 'insert') {
     $form['breaking']['submit'] = array(
      '#type' => 'submit' ,
      '#value' => 'Submit' ,
      '#ajax' => array(
        'callback' => 'itg_breaking_form_ajax_submit' ,
        'effect' => 'fade' ,
        'progress' => array('type' => 'throbber' , 'message' => '') ,
        'validate_first' => TRUE ,
      ) ,
    );
  } else {
    $form['breaking']['submit'] = array(
      '#type' => 'submit' ,
      '#value' => 'Submit',
      '#access' => TRUE,
      '#attributes' => array('class' => array('itg-custom-blog')),
      '#attributes' => array("onclick" => "javascript:itg_blog_fetch_data($results->blog_entity_id);")
    );
    $form['#submit'][] = 'itg_live_blog_form_submit';
  }
 
  */
    $id = $form['field_name']['#value'];
    
     $form['breaking']['submit'] = array(
      '#type' => 'submit' ,
      '#value' => 'Submit' ,
      '#ajax' => array(
        'callback' => 'itg_breaking_form_ajax_submit' ,
        'wrapper' => $id,
        'method' => 'replace',
        'effect' => 'fade',
      ) ,
    );
  /*   
  $url = $base_url . '/manage-live-blog';
  $form['breaking']['actions']['cancel'] = array(
    '#markup' => l(t('Reset'), $url, array(
      'attributes' => array(
        'class' => 'button custom-url-search'
      )
    )),
    '#weight' => 9,
    '#value' => t('Reset')
  );
   * 
   */
  // unset($form['#submit']);
  // print "greeting =". $_SESSION['greeting'];
 
  /*
  if (isset($_SESSION['itg_blog_post'])) {
      $settings = array();
      $settings['base_url'] = $base_url;
      // $settings['uid'] = $user->uid;
      $settings['no_id'] = $arg[2];
      drupal_add_js(array('itg_breaking_new_form' => array('settings' => $settings)), array('type' => 'setting'));
      drupal_add_js(drupal_get_path('module', 'itg_breaking_news') . '/js/itg_breaking_news_custom_form.js', array('preprocess' => false, 'scope' => 'footer'));
  
     unset($_SESSION['itg_blog_post']);
     
  }
   * 
   */
  return $form;
}

function itg_live_blog_form_submit($form, &$form_state) {
  global $user;
  $insert_id = '';
  $_SESSION['itg_blog_post'] = 1;
  $_SESSION['blogcron'] = 1;
  $blog_uid = $user->uid;
  $blog_type = 'Breaking News';
  $blog_title = $form_state['values']['blog_title'];
  $blog_description = $form_state['values']['blog_description']['value'];
  $blog_breaking_band = $form_state['values']['blog_breaking_band'];
  $blog_notification = $form_state['values']['blog_notification'];
  $blog_publish_time = $form_state['input']['blog_publish_time']['time'];
  $blog_highlight_status = $form_state['values']['blog_highlight_status'];
  $blog_entity_id = $form_state['values']['blog_entity_id'];
  $bid = $form_state['input']['bid'];
  if (isset($bid) && $bid > 0) {
    $insert_id = db_update('itg_live_blog')
        ->fields(array(
          'blog_entity_id' => $blog_entity_id,
          'blog_type' => $blog_type,
          'blog_title' => $blog_title,
          'blog_description' => $blog_description,
          'blog_breaking_band' => $blog_breaking_band,
          'blog_notification' => $blog_notification,
          'blog_publish_time' => $blog_publish_time,
          'blog_highlight_status' => $blog_highlight_status,
          'blog_uid' => $blog_uid,
          'blog_updated_date' => REQUEST_TIME,
        ))
        ->condition('bid', $bid, '=')
        ->execute();
   // $form_state['rebuild'] = TRUE;
    drupal_set_message(t('The form has been updated'));
  }
}

/*
function itg_manage_breking_news_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}
 * 
 */
/**
 * This function is used to budget form submit.
 * {@inheritdoc}
 */
/*
function itg_manage_breking_news_submit_old($form, &$form_state) {
  global $user;
  $insert_id = '';
  $_SESSION['greeting'] = 1;
  $_SESSION['blogcron'] = 1;
  $blog_uid = $user->uid;
  $blog_type = 'Breaking News';
  $blog_title = $form_state['values']['blog_title'];
  $blog_description = $form_state['values']['blog_description']['value'];
  $blog_breaking_band = $form_state['values']['blog_breaking_band'];
  $blog_notification = $form_state['values']['blog_notification'];
  $blog_publish_time = $form_state['input']['blog_publish_time']['time'];
  $blog_highlight_status = $form_state['values']['blog_highlight_status'];
  $blog_entity_id = $form_state['values']['blog_entity_id'];
  $bid = $form_state['input']['bid'];

  if (isset($bid) && $bid > 0) {
    $insert_id = db_update('itg_live_blog')
        ->fields(array(
          'blog_entity_id' => $blog_entity_id,
          'blog_type' => $blog_type,
          'blog_title' => $blog_title,
          'blog_description' => $blog_description,
          'blog_breaking_band' => $blog_breaking_band,
          'blog_notification' => $blog_notification,
          'blog_publish_time' => $blog_publish_time,
          'blog_highlight_status' => $blog_highlight_status,
          'blog_uid' => $blog_uid,
          'blog_updated_date' => REQUEST_TIME,
        ))
        ->condition('bid', $bid, '=')
        ->execute();
    drupal_set_message(t('The form has been updated'));
    // drupal_goto('manage-live-blog' . '/edit/' . $blog_entity_id);
  }
  else {
    $insert_id = db_insert('itg_live_blog')
        ->fields(array(
          'blog_entity_id' => $blog_entity_id,
          'blog_type' => $blog_type,
          'blog_title' => $blog_title,
          'blog_description' => $blog_description,
          'blog_breaking_band' => $blog_breaking_band,
          'blog_notification' => $blog_notification,
          'blog_publish_time' => $blog_publish_time,
          'blog_highlight_status' => $blog_highlight_status,
          'blog_uid' => $blog_uid,
          'blog_created_date' => REQUEST_TIME,
        ))
        ->execute();
    drupal_set_message(t('The form has been submitted with ') . $insert_id);
    // drupal_goto('manage-live-blog' . '/add/' . $blog_entity_id);
  }
  // $form_state['storage']['alert_msg'] = 'Hello World';
  $form_state['rebuild'] = TRUE;
  
  // drupal_goto('manage-live-blog/add/1148227'); 
}
*/

 

function itg_live_blog_get_insert() {
  global $user, $base_url;
  $blog_uid = $user->uid;
  $blog_type = 'Breaking News';
  $blog_title = $_POST['blog_title'];
  $blog_description = 'test data'; // ($_POST['blog_description']) ? $_POST['blog_description'] : 'test data';
  $blog_breaking_band = $_POST['blog_breaking_band'];
  $blog_notification = $_POST['blog_notification'];
  $blog_publish_time = $_POST['blog_publish_time'];
  $blog_highlight_status = $_POST['blog_highlight_status'];
  $blog_entity_id = $_POST['blog_entity_id'];
  $bid = ($_POST['bid']) ? $_POST['bid'] : '';

  if (isset($bid) && $bid > 0) {
    $insert_id = db_update('itg_live_blog')
        ->fields(array(
          'blog_entity_id' => $blog_entity_id,
          'blog_type' => $blog_type,
          'blog_title' => $blog_title,
          'blog_description' => $blog_description,
          'blog_breaking_band' => $blog_breaking_band,
          'blog_notification' => $blog_notification,
          'blog_publish_time' => $blog_publish_time,
          'blog_highlight_status' => $blog_highlight_status,
          'blog_uid' => $blog_uid,
          'blog_updated_date' => REQUEST_TIME,
        ))
        ->condition('bid', $bid, '=')
        ->execute();
    return $insert_id = '';

  }  else {
    $insert_id = db_insert('itg_live_blog')
        ->fields(array(
          'blog_entity_id' => $blog_entity_id,
          'blog_type' => $blog_type,
          'blog_title' => $blog_title,
          'blog_description' => $blog_description,
          'blog_breaking_band' => $blog_breaking_band,
          'blog_notification' => $blog_notification,
          'blog_publish_time' => $blog_publish_time,
          'blog_highlight_status' => $blog_highlight_status,
          'blog_uid' => $blog_uid,
          'blog_created_date' => REQUEST_TIME,
        ))
        ->execute();
      $output = '';
      $query = db_select('itg_live_blog', 'p');
      $query->fields('p', array('bid','blog_title', 'blog_description', 'blog_breaking_band', 'blog_notification','blog_uid',	'blog_created_date'));
       $query->condition('p.bid', $insert_id); 
      # execute the query
       $row = $query->execute()->fetchObject();

         $user = !empty($row->blog_uid) ? user_load($row->blog_uid)->name : '';
         $edit_link = $base_url . '/manage-print-form/edit/' . $row->bid . '?width=1000&height=700&iframe=true';
        $output .= '  
                <tr>  
                     <td class="blog_title" id="t'.$row->bid.'" data-id1="'.$row->bid.'">'.$row->blog_title.'</td>  
                     <td class="blog_breaking_band" id="b'.$row->bid.'" data-id2="'.$row->bid.'">'.$row->blog_breaking_band.'</td>
                     <td class="blog_notification" id="n'.$row->bid.'" data-id2="'.$row->bid.'">'.$row->blog_notification.'</td>
                     <td class="user" id="u'.$row->bid.'" data-id2="'.$row->bid.'">'.$user.'</td>
                     <td>


                      <a class="colorbox-load add-more add-related-content-link" oncontextmenu="return false;" href="'.$edit_link.'">Edit</a>  
                      <button type="button" name="delete_btn" data-id3="'.$row->bid.'" class="btn btn-xs btn-danger btn_delete">Delete</button>
                     </td>  
                </tr>  
           ';  


      echo $output; 
  }
}

function live_bog_delete() {
  $blog_entity_id = (arg(1)) ? arg(1) : '';
  $bid = (arg(2)) ? arg(2) : '';
  if (!empty($bid)) {
    // db_delete('itg_live_blog')->condition('bid' , $bid)->execute();
  }
  
  if (!empty($blog_entity_id)) {
     return $blog_list = itg_live_blog_list($blog_entity_id);
  }
 
}


function live_bog_cron() {
  
  print itg_live_blog_list('1148227');
  
}