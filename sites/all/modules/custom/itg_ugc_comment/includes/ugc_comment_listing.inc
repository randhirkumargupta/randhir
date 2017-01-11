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