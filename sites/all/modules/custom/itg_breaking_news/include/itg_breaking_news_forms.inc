<?php

/**
 * Function for ajax request callback
 */
function itg_live_blog_custom() {
  return theme('itg_live_blog_custom_form', array('data' => $data));
}

/**
 * custom form for content deatils.
 * @param type $form
 * @param type $form_state
 * @param type $bid
 * @param type $type
 * @return string
 */
function itg_manage_breking_news($form, &$form_state, $bid, $type) {
  $arg = arg();
  $blog_entity_id = $arg[2];
  $form = array();
  // To make the fieldset collapsible
  $form['breaking'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
   
  $form['breaking']["wrapper"] = array(
      "#markup" => "<div class='inline-error-messages'></div>",
  );
   
  $form['breaking']['blog_highlight_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mark as most recent'),
    '#default_value' => '0',
    '#prefix' => '<div id="blog_highlight_replace_wrapper">',
    '#suffix' => '</div>',
  );
   
  $form['breaking']['blog_title'] = array(
    '#type' => 'textfield',
    '#prefix' => '<div id="blog_title_replace_wrapper">',
    '#title' => t('Title'),
    '#default_value' => '',
    '#suffix' => '</div>',
  );
   
  $form['breaking']['blog_description'] = array(
    '#type' => 'text_format',
    '#title' => 'Description',
    '#rows' => 5,
    '#resizable' => FALSE,
    '#default_value'=> '',
    '#format' => 'icon_format',
    '#prefix' => '<div id="blog_description_replace_wrapper">',
    '#suffix' => '</div>',
  );
    
  $form['breaking']['blog_breaking_band'] = array(
    '#type' => 'hidden',
    '#value' => 1,
  );
     
  $form['breaking']['blog_entity_id'] = array(
    '#type' => 'hidden',
    '#value' => ($blog_entity_id) ? $blog_entity_id : '',
    '#prefix' => '<div id="blog_entity_replace_wrapper">',
    '#suffix' => '</div>',
  );
  
  $form['breaking']['bid'] = array(
    '#type' => 'hidden',
    '#value' => '',
    '#attributes' => array('class' => 'custom_blog_bid'),
    '#prefix' => '<div id="blog_bid_replace_wrapper">',
    '#suffix' => '</div>',
  );
  
  $form['breaking']['action'] = array(
    '#type' => 'hidden',
    '#value' => '',
    '#attributes' => array('class' => 'custom_blog_action'),
  );
   
  $form['breaking']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#ajax' => array(
      'callback' => 'itg_breaking_form_ajax_submit' ,
      'effect' => 'fade' ,
      'progress' => array('type' => 'throbber' , 'message' => '') ,
      'validate_first' => TRUE ,
    ) ,
  );
  return $form;
}

/**
 * {@inheritdoc}.
 */
function itg_manage_breking_news_submit($form, &$form_state) {
  
}

/**
 * Delete live blog by cms.
 */
function live_bog_delete() {
  $bid = ($_POST['id']) ? $_POST['id'] : '';
  global $user;
  $blog_uid = $user->uid;
  $status = 0;
  $updated_date = date('Y-m-d H:i:s');
  if (!empty($bid)) {
     db_update('itg_live_blog')
              ->fields(array(
                'status' => $status,
                'update_uid' => $blog_uid,
                'blog_updated_date' => $updated_date,
              ))
              ->condition('bid', $bid, '=')
              ->execute();
  }
}

/**
 * refresh content for live blog.
 */
function itg_live_blog_refresh() {
 $entityId = ($_POST['entityId']) ? $_POST['entityId'] : '';
 if (!empty($entityId)) {
    print $blog_list = itg_live_blog_list($blog_entity_id); 
 } 
}

/**
 * Notification alter for file new live blog.
 */
function itg_live_blog_check_updates() {
  $entityId = ($_POST['entityId']) ? $_POST['entityId'] : '';
  $bid = ($_POST['bId']) ? $_POST['bId'] : '';
  if(!empty($entityId) && !empty($bid)) {
    $total_records = db_query("SELECT bid FROM itg_live_blog WHERE status = 1 AND blog_entity_id = $entityId AND bid > $bid")->rowCount();
    print '(' . $total_records . ')'; 
  } 
}