<?php

$args = drush_get_arguments(); // Get the arguments.

itg_comments_migrate_step1();

/**
 * Code started for comments migration
 */
function itg_comments_migrate_step1() {
  // $xml_path = 'sites/default/files/comments_data/rundown/comments_master_test1.xml';
  //$xml_path = 'sites/default/files/comments_data/final/comment_1.xml';
  $xml_path = '/opt/httpd/vhosts/indiatoday/sites/default/files/comment_migration/comment_1.xml';


  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');

  echo "Start migrating comments...\n";
  $success_count = 0;
  $failed_count = 0;
  $row = '';
  $output = '';
  foreach ($xml->row as $xm) {
    $check_already_exist = itg_comments_migrate_step2_get_mapping1($xm->id);
    // Getting the mapped Node Id on the basis of content ID 
    
    if(empty($check_already_exist)){
    //echo $check_already_exist; 
    //echo $xm->article_id;echo " ";
    //echo $xm->content_type;
    
    
    $content_nid = NULL;
    switch ($xm->content_type) {
      case 'story':
        //$content_nid = get_itg_destination_id('migrate_map_itgstorylist', (string) $xm->article_id);
        break;
      case 'video':
        //$content_nid = get_itg_destination_id('migrate_map_itgvideogallery', (string) $xm->article_id);
        break;
      case 'photo':
        $content_nid = get_itg_destination_id('migrate_map_itgphotogallery', (string) $xm->article_id);
        break;
    }

    // This is the hardcoded content ID for testing purposes 
    //$content_nid = 349522;

    if (isset($content_nid) && !empty($content_nid)) {
      // We need two collections first for storing the mapping data and second one is storing mapped data means 
      // final migrated data


      if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->itgcms_comment;
        $comment_user = $con->itgcms_comment_user;
        if (isset($xm->created_date) && !empty($xm->created_date)) {
          $comment_date = date('d-m-Y', (int) $xm->created_date);
          $comment_date_time = date('d-m-Y H:i:s', (int) $xm->created_date);
        }
        else {
          $comment_date = 0;
          $comment_date_time = 0;
        }

        $qry = array(
          "id" => (string) $xm->id,
          "article_id" => (string) $xm->article_id,
          "page_id" => (string) $content_nid,
          "email" => (string) $xm->email,
          "name" => (string) $xm->fname . ' ' . $xm->lname,
          "comment" => decode_entities($xm->comment),
          "parent_comment_id" => (string) "0",
          "comment_date" => $comment_date,
          "comment_date_time" => $comment_date_time,
          "property" => (string) $xm->website,
          "content_type" => (string) $xm->content_type,
          "activity" => "comment",
          "status" => (int) $xm->state,
          "uid" => (int) 0,
          "timestamp" => time(),
          'date_of_birth' => $xm->date_of_birth,
          'sex' => (string) $xm->sex,
          'city' => (string) $xm->city,
          'country' => (string) $xm->country,
          'display_emailid' => (string) $xm->display_emailid,
          'galleryid' => (string) $xm->galleryid,
          'source' => (string) $xm->source,
          'sourceurl' => (string) $xm->sourceurl,
          'parent_id' => (string) $xm->parent_id,
          'ip' => (string) $xm->ipaddress,
          'comment_level' => (int) $xm->comment_level,
          'root_comment_id' => (string) $xm->root_comment_id,
          'sn_image' => (string) $xm->sn_image,
          'sn_source' => (string) $xm->sn_source,
          'abuse_word' => (string) $xm->abuse_word,
          'abuse_status' => (string) $xm->abuse_status,
          'abuse_status_count' => (string) $xm->abuse_status_count,
          'se_comment_id' => (string) $xm->se_comment_id,
          'se_parent_id' => (string) $xm->se_parent_id,
          'source_type' => 'migrated',
        );

        $result = $people->insert($qry);


        // Code started for adding the migration mapping 

        if (function_exists('mongodb')) {
          $con = mongodb();
          $people = $con->itgcms_comment_mapping;
          $id = (string) ($qry['_id']);
          if (!empty($id)) {
            $mig_mapp_result = $people->insert(array("old_id" => (string) $xm->id, "new_id" => (string) $id));
          }
        }


        $check_user_existance = ugc_comment_user_status((string) $xm->email);
        if (empty($check_user_existance['email'])) {
          $user_email_query = array("email" => (string) $xm->email, "status" => 1);
          $comment_user_result = $comment_user->insert($user_email_query);
        }
//        if ($success_count == 5000) {
//          break;
//        }
        $success_count++;
        echo (string) $xm->id . ' ';
      }
    }
    else {
      $failed_count++;
      // Start code for creating XML
      if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->itgcms_comment_fail;
        $qry = array(
          "id" => (string) $xm->id,
          "content_type" => (string) $xm->content_type,
        );

        $result = $people->insert($qry);
      }
    }
    
    }
    
  }


  echo "\n Total Processed:" . $success_count;
  echo "\n Total Failed:" . $failed_count;
  echo "\nMigration finished...\n";
}


function itg_comments_migrate_step2_get_mapping1($parent_id) {
  $id = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->itgcms_comment_mapping;
    $cond = array('old_id' => (string) $parent_id);
    $cursor = $people->find($cond);
    foreach ($cursor as $document) {
      $id = $document['new_id'];
      if (isset($id) && !empty($id)) {
        return $id;
      }
    }
  }
}

