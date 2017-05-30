<?php

$args = drush_get_arguments(); // Get the arguments.

itg_comments_migrate_step1();

/**
 * Code started for comments migration
 */
function itg_comments_migrate_step1() {
  $xml_path = 'sites/default/files/comments_data/rundown/comments_master_test1.xml';
  $xml = simplexml_load_file($xml_path, 'SimpleXMLElement');

  echo "Start migrating comments...\n";
      $success_count = 0;
    $failed_count = 0;
    $row = '';
    $output = '';
  foreach ($xml->row as $xm) {
    // Getting the mapped Node Id on the basis of content ID 
    $content_nid = NULL;
    switch ($xm->content_type) {
      case 'story':
        $content_nid = get_itg_destination_id('migrate_map_itgstory', (string) $xm->article_id);
        break;
      case 'video':
        $content_nid = get_itg_destination_id('migrate_map_itgvideogallery', (string) $xm->article_id);
        break;
      case 'photo':
        $content_nid = get_itg_destination_id('migrate_map_itgphoto', (string) $xm->article_id);
        break;
    }

    // This is the hardcoded content ID for testing purposes 
    $content_nid = 349522;

    if (isset($content_nid) && !empty($content_nid)) {
      // We need two collections first for storing the mapping data and second one is storing mapped data means 
      // final migrated data
      // Adding data in comment_migrated_mapping
//      if (function_exists('mongodb')) {
//        $con = mongodb();
//        $people = $con->comment_migrated_mapping;
//        $qry = array(
//          "id" => (string) $xm->id,
//          "content_nid" => (string) $content_nid,
//        );
//        $result = $people->insert($qry);
//      }
//      else {  // Handling the failed mapping data
//      }
      // Adding Main comment against node

      if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->itgcms_comment;
        $comment_user = $con->itgcms_comment_user;
        $qry = array(
          "id" => (string) $xm->id,
          "page_id" => (string) $content_nid,
          "email" => (string) $xm->email,
          "name" => (string) $xm->fname . ' ' . $xm->lname,
          "comment" =>  decode_entities($xm->comment),
          "parent_comment_id" => (string) $xm->parent_id,
          "comment_date" => date('d-m-Y', strtotime((string) $xm->created_date)),
          "comment_date_time" => date('d-m-Y H:i:s', strtotime((string) $xm->created_date)),
          "property" => (string) $xm->website,
          "content_type" => (string) $em->content_type,
          "activity" => "comment",
          "status" => (int) $xm->state,
          "uid" => 0,
          "timestamp" => time(),
          'date_of_birth' => (string) $xm->date_of_birth,
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
          'migrated_data' => 1,
        );

        $result = $people->insert($qry);

        $check_user_existance = ugc_comment_user_status((string) $xm->email);
        if (empty($check_user_existance['email'])) {
          $user_email_query = array("email" => (string) $xm->email, "status" => 1);
          $comment_user_result = $comment_user->insert($user_email_query);
        }
        $success_count++;
        echo (string) $xm->id . ' ';
      }
    }
    else {
      $failed_count++;
      // Start code for creating XML

      $row.="<row>
      <id>".$xm->id."</id>
      <article_id>".$xm->article_id."</article_id>
      <fname>".$xm->fname."</fname>
      <lname>".$xm->lname."</lname>
      <email>".$xm->email."</email>
      <date_of_birth>".$xm->date_of_birth."</date_of_birth>
      <sex>".$xm->sex."</sex>
      <city>".$xm->city."</city>
      <country>".$xm->country."</country>
      <comment>".$xm->comment."</comment>
      <state>".$xm->state."</state>
      <created_date>".$xm->created_date."</created_date>
      <featured>".$xm->featured."</featured>
      <display_emailid>".$xm->display_emailid."</display_emailid>
      <creating_wealth>".$xm->creating_wealth."</creating_wealth>
      <photo_category>".$xm->photo_category."</photo_category>
      <galleryid>".$xm->galleryid."</galleryid>
      <content_type>".$xm->content_type."</content_type>
      <source>".$xm->source."</source>
      <ipaddress>".$xm->ipaddress."</ipaddress>
      <longitude>".$xm->longitude."</longitude>
      <latitude>".$xm->latitude."</latitude>
      <slideid>".$xm->slideid."</slideid>
      <sourceurl>".$xm->sourceurl."</sourceurl>
      <website>".$xm->website."</website>
      <parent_id>".$xm->parent_id."</parent_id>
      <comment_level>".$xm->comment_level."</comment_level>
      <root_comment_id>".$xm->root_comment_id."</root_comment_id>
      <sn_image>".$xm->sn_image."</sn_image>
      <sn_source>".$xm->sn_source."</sn_source>
      <abuse_word>".$xm->abuse_word."</abuse_word>
      <abuse_status>".$xm->abuse_status."</abuse_status>
      <abuse_status_count>".$xm->abuse_status_count."</abuse_status_count>
      <se_comment_id>".$xm->se_comment_id."</se_comment_id>
      <se_parent_id>".$xm->se_parent_id."</se_parent_id>
   </row>";
    }

    $output = "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\" ?>";
    $output .= '<data>';
    $output .= $row;
    $output .= '</data>';

    $dom = new DOMDocument;
    $dom->preserveWhiteSpace = FALSE;
    $dom->loadXML($output);

//Save XML as a file
    $dom->save('sites/default/files/comments_mig_fail_'.date('Y-M-d').'.xml');
  }
      
  echo "\n Total Processed:" . $success_count;
  echo "\n Total Failed:" . $failed_count;

  echo "\nMigration finished...\n";
}
