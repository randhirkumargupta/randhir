<?php

/*
 * Inc file contains the functions
 */

/**
 * ugc comment details callback
 */
function ugc_comment_listing() {

  $con = new Mongo();
  $db = $con->itgcms_mongodb;
  $reply_comment = $db->itgcms_comment;
  $reply_comment_data = $reply_comment->find();
  
    $output = '';
    $output = "<table class='views-table'><thead>
    <tr><th>" . t('S. No') . "</th><th>" . t('Name') . "</th><th>" . t('Email') . "</th><th>" . t('Comment') . "</th><th>" . t('Post date') . "</th><th>" . t('Status') . "</th><th>" . t('Action') . "</th></tr></thead><tbody>";

  $comment_counter = 1;
  foreach ($reply_comment_data as $final_comment_data) {
    $user_message_raw_value = strip_tags($final_comment_data['comment']);
    $user_message_lenth = strlen($final_comment_data['comment']);
      if ($user_message_lenth > 100) {
        $user_message_raw_value = substr($user_message_raw_value, 0, 99) . "...";
        $user_message_raw_value = itg_ugc_bad_words($user_message_raw_value);
      }
      else {
        $user_message_raw_value = itg_ugc_bad_words($user_message_raw_value);
        $user_message_raw_value = $user_message_raw_value;
      }

    $output.="<tr><td>" . $comment_counter . "</td><td>" . $final_comment_data['name'] . "</td><td>" . $final_comment_data['email'] . "</td><td>" . $user_message_raw_value . "</td><td>" . $final_comment_data['comment_date'] . "</td><td>" . $final_comment_data['status'] . "</td><td>" . l(t('View'), 'ugccommentview/' . $final_comment_data["_id"]) . " / ".l(t('Reject'), 'ugccommentapprove/' . $final_comment_data["_id"])."</td></tr>";

    $comment_counter = $comment_counter + 1;
  }
    $output .= "</tbody></table>";

    return $output;
}

/**
* Implements ugc_comment_view()
* @param string $id
*/
function ugc_comment_view($id) {  
  $con = new Mongo();
  $db = $con->itgcms_mongodb;
  $comment_view = $db->itgcms_comment;
  
  $pid = new MongoId($id); 
  $comment_view_data = $comment_view->find(array("_id" => $pid));
  
    
    $output = '';
    $output.= '<div class="comment-view">';
    
  foreach($comment_view_data as $final_view) {
    $user_message = itg_ugc_bad_words($final_view['comment']);
    $output.= 'Name : '.$final_view['name'].'<br/>';
    $output.= 'Email : '.$final_view['email'].'<br/>';
    $output.= 'Comment : '.$user_message.'<br/>';
    $output.= 'Post date : '.$final_view['comment_date'].'<br/>';
  }
  
  $output.='Action : '. l(  t('Cancel'),  'ugc-comment-listing',  array('attributes' => array('class'=> array('ugc-comment-listing'), 'id'=> array('ugc-comment-listing'))));
  
    $output.= '</div>';
  
    return $output;
}


/**
* Implements ugc_comment_approve()
* @param string $id
*/
function ugc_comment_approve($id) {  
  $con = new Mongo();
  $db = $con->itgcms_mongodb;
  $comment_view = $db->itgcms_comment;
  $rid = new MongoId($id); 
  $comment_view_data = $comment_view->update(array("_id" => $rid), array('$set' => array("status" => 1)));
  drupal_set_message('Comment Approved Sucessfully');
  drupal_goto('ugc-comment-listing');
}

/**
 * Implements ugc_comment_user_listing().
 */
function ugc_comment_user_listing() {
  # configure the table header columns
  $header = array(
    array('data' => t('')),
    array('data' => t('S. No')),
    array('data' => t('E-mail')),
    array('data' => t('Status')),
  );
  if (function_exists('mongodb'))
  {
    $con = mongodb();
    if ($con)
    {
      $people = $con->itgcms_comment_user;
      $query = array();
      $limit = 0;
      if (!empty($_GET['items_per_page']))
      {
        $limit = $_GET['items_per_page'];
      }

      if (!empty($_GET['email']))
      {
        $query['email'] = trim($_GET['email']);
      }

      if (is_array($query) && empty($query))
      {

        $userData = $people->find(array("email" => array('$ne' => null)))->limit($limit);
      }
      else
      {
        $userData = $people->find($query)->limit($limit);
      }

      $rows = array();
      $sl_no = 1;
      
      foreach ($userData as $row) {
        $block_check = '<input type="checkbox" class="block-user-id" name="block_user[]" value="' . $row['email'] . '">';
        if ($row['status'] == 1)
        {
          $status = 'Active';
        }
        else
        {
          $status = 'Blocked';
        }
        //get the value in table
        $rows[] = array(
          array('data' => $block_check),
          array('data' => $sl_no),
          array('data' => $row['email']),
          array('data' => $status),
        );
        $sl_no = $sl_no + 1;
      } // end foreach
    }
  }
  //get the header in table
  $output = render(drupal_get_form('itg_user_block_api_form'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}

/**
 * Implements ugc_comment_user_block().
 */
function ugc_comment_user_block() {
  $email = $_POST['email'];
  $event = $_POST['event'];
  if (function_exists('mongodb') && !empty($email))
  {
    $con = mongodb();
    $final_email = explode(',', $email);
    foreach ($final_email as $value) {
      $people = $con->itgcms_comment_user;
      if($event == 'comment-user-block') {
      $newdata = array('$set' => array('status' => 0));
      }
      if($event == 'comment-user-unblock') {
      $newdata = array('$set' => array('status' => 1));
      }
      $people->update(array("email" => trim($value)), $newdata);
    }
    if($event == 'comment-user-unblock') {
    $response = array('success' => 'unblock', 'ok' => 'true');
    }
    if($event == 'comment-user-block') {
    $response = array('success' => 'block', 'ok' => 'true');
    }
    print json_encode($response);
  }
}
