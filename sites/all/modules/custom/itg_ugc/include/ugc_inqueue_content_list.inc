<?php
/**
 * Implements hook_form().
 * {@inheritdoc}
 */
function itg_ugc_inqueue_form($form, &$form_state) {
  global $base_url;
  $form = array();
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#maxlength' => 255,
    '#size' => 30,
    '#attributes' => array('placeholder' => t('Title'), 'autocomplete' => 'off'),
    '#default_value' => isset($_GET['title']) ? $_GET['title']:"",
  );
  
  $form['content_type'] = array(
      '#type' => 'select',
      '#title' => t('Content Type'),
      '#options' => array('' => 'none', 'story' => 'story', 'photogallery' => 'photogallery', 'videogallery' => 'videogallery', 'podcast' => 'podcast', 'blog' => 'blog'),
      '#default_value' => isset($_GET['content_type']) ? $_GET['content_type']:"",
  );
  
  $form['items_per_page'] = array(
    '#type' => 'select',
    '#title' => 'Items per page',
    '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60, 100 => 100, 500 => 500, 1000 => 1000),
    '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
  );
  $form['submit'] = array(
    '#value' => 'Apply',
    '#type' => 'submit',
    '#attributes' => array('class' => array('user-block-apply')),
    '#prefix' => '<div class = "user-log-filter-btn">',
    '#suffix' => '<a class="user-log-reset form-submit" href="' . base_path() . 'ugc-inqueue-content">'.t('Reset').'</a></div>',
  );
  
  return $form;
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_ugc_inqueue_form_submit($form, &$form_state) {
  $form_state['redirect'] = array(
    'ugc-inqueue-content',
    array(
      'query' => array(
        'title' => $form_state['values']['title'],
        'content_type' => $form_state['values']['content_type'],
        'items_per_page' => $form_state['values']['items_per_page'],
      ),
    ),
  );
}

/**
 * Implements itg_ugc_inqueue_content().
 */
function itg_ugc_inqueue_content() {
  global $base_url;
  $arg = arg();
  # configure the table header columns
  $header = array(
    array('data' => t('S. No')),
    array('data' => t('Title')),
    array('data' => t('Content Type')),
    array('data' => t('Name')),
    array('data' => t('Email')),
    array('data' => t('Status')),
    array('data' => t('Posted Date')),
    array('data' => t('Actions')),
  );
  if (function_exists('mongodb'))
  {
    $con = mongodb();
    if ($con)
    {
      $people = $con->ugc_details;
      $query = array();
      $limit = 0;
      
      if (!empty($_GET['items_per_page']))
      {
        $limit = $_GET['items_per_page'];
      }

      if (!empty($_GET['content_type']))
      {
        $query['content_type'] = trim($_GET['content_type']);
        $query['status'] = 1;
        $query['publish_status'] = array('$ne' => 1);
      }
      if (!empty($_GET['title']))
      {
        $query['title'] = trim($_GET['title']);
        $query['status'] = 1;
        $query['publish_status'] = array('$ne' => 1);
      }

      if (is_array($query) && empty($query))
      {
        $userData = $people->find(array("publish_status" => array('$ne' => 1), "status" => 1))->limit($limit)->sort(array('_id' => -1));
      }
      else
      {
        $userData = $people->find($query)->limit($limit)->sort(array('_id' => -1));
      }

      $rows = array();
      $sl_no = 1;
      
      foreach ($userData as $row) {
        $link = '<span class="view-link"><a class="colorbox-load" href="ugc-view-content/'.$row['_id'].'/'.$arg[0].'?width=500&height=300">'.t('view').'</a></span> | <span class="edit-link"><a href="'.$base_url.'/node/add/'.$row['content_type'].'/'.$row['_id'].'?destination=ugc-inqueue-content">'.t('Approve').'</a></span> | <a href="ugc-title/'.$row['_id'].'/reject" class="ugc-reject">'.t('Reject').'</a>';
        
        if ($row['status'] == 1)
        {
          $status = 'Active';
        }
        
        //get the value in table
        $rows[] = array(
          array('data' => $sl_no),
          array('data' => $row['title']),
          array('data' => $row['content_type']),
          array('data' => $row['name']),
          array('data' => $row['email']),
          array('data' => $status),
          array('data' => $row['publish_date']),
          array('data' => $link),
        );
        $sl_no = $sl_no + 1;
      } // end foreach
    }
  }
  //get the header in table
  $output = render(drupal_get_form('itg_ugc_inqueue_form'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}