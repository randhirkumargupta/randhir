<?php

/**
 * Function for ajax request callback
 */

function itg_live_blog_custom() {
  global $base_url, $user;
  $arg = arg();
  drupal_add_js(drupal_get_path('theme', 'itg') . '/js/bootstrap.min.js', array('preprocess' => false, 'weight' => 5, 'scope' => 'footer'));
  drupal_add_css('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css', array('type' => 'external'));
 
  return theme('itg_live_blog_custom_form', array('data' => $data));

}

function itg_manage_breking_news($form, &$form_state, $bid, $type) {
  $arg = arg();
   
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
    '#title' => t(''),
    '#collapsible' => TRUE, // Added
    '#collapsed' => FALSE,  // Added
  );
   
 
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
    '#required' => TRUE
  );
  
  $form['breaking']['blog_entity_id'] = array(
    '#type' => 'hidden',
    '#value' => ($results->blog_entity_id) ? $results->blog_entity_id : $blog_entity_id,
  );
  
   $form['breaking']['bid'] = array(
    '#type' => 'hidden',
    '#value' => ($results->bid) ? $results->bid : '',
  );
   
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
      // '#attributes' => array("onclick" => "javascript:itg_blog_fetch_data($results->blog_entity_id);")
    );
    $form['#submit'][] = 'itg_live_blog_form_submit';
    $blog_list = itg_live_blog_list($blog_entity_id);
     drupal_add_js('
       jQuery(document).ready(function($) {
         alert("form submit");
         $("#live_data").parent().empty();  
         $("#live_data").parent().html("replace sting");             
         parent.jQuery.colorbox.close();
        });',"inline");
  }
 
  
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
  
  return $form;
}

function itg_manage_breking_news_submit($form, &$form_state) {
  
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



function print_form() {
  // p(arg());
  
   $nid = (arg(2)) ? arg(2) : '';
   $type = (arg(1)) ? arg(1) : '';
   if($type == 'add') {
     return drupal_render(drupal_get_form('itg_manage_breking_news'));
   } elseif($type == 'edit') {
     return drupal_render(drupal_get_form('itg_manage_breking_news', $nid));
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


function live_bog_cron()
{
            
        db_query("INSERT INTO `itg_live_blog` (`bid`, `blog_entity_id`, `blog_type`, `blog_title`, `blog_description`, `blog_breaking_band`, `blog_notification`, `blog_publish_time`, `blog_highlight_status`, `blog_uid`, `blog_created_date`, `blog_updated_date`) VALUES
(16, 1148227, 'Breaking News', 'dsd', '<p>daasd</p>\r\n', 1, 1, '', 1, 1522, '1524040055', NULL),
(17, 1148227, 'Breaking News', 'test data', '<p>test data</p>\r\n', 1, 2, '', 1, 1522, '1524040256', NULL),
(18, 1148227, 'Breaking News', 'test data 1', '<p>test data 1</p>\r\n', 1, 1, '', 1, 1522, '1524045105', NULL),
(19, 1148227, 'Breaking News', 'test data 2', '<p>test data 2</p>\n', 1, 1, '', 1, 1522, '1524045279', NULL),
(40, 1148227, 'Breaking News', 'xcxcxc', '<p>czxczx</p>\n', 1, 1, '', 1, 1522, '2018-04-19 13:27:21', NULL);");
}
