<?php
/**
 * Get Mail content
 * @global String $base_url
 * @param object $node
 * @param string $event
 * @param string $to
 * @param string $user_name
 * @param string $current_user_name
 * @return 
 */
function workflow_get_mail_content($node, $event, $to, $user_name, $current_user_name, $vbo_state, $vbo_update) {
  global $base_url;
  $author_mail = array();
  $content_type = $node->type;
  $review = $node->workbench_moderation_state_new;
  if (FALSE && $review == 'needs_review' || $review == 'rejected' || $review == 'needs_modification') {// We don't need this feature right now
    $node_url = l($node->title, $base_url . '/node/' . $node->nid . '/edit');
    $actual_node_url = $base_url . '/node/' . $node->nid . '/edit';
  }
  else {
    $node_url = l($node->title, FRONT_URL . '/node/' . $node->nid);
    $alias_un = drupal_get_path_alias('node/' . $node->nid);
    if($alias_un == 'node/'.$node->nid && !empty($node->path['alias'])){
	  $alias_un = $node->path['alias'];
    }
    $actual_node_url = FRONT_URL . '/' . $alias_un;
  }

  if ($event == 'create' && $review == 'published') {
    $author_mail[] = db_query("SELECT mail from {users} WHERE uid = :uid AND status = 1", array(":uid" => $node->uid))->fetchField();
    $to_mail = $author_mail[0];

    if (function_exists('itg_mail_templates_get_mailcontent')) {
      $mail_data = itg_mail_templates_get_mailcontent($content_type, 'create');
      $mail_data_cat = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];

      if ($mail_data_cat == 'blog') {
        $subject = $mail_data->field_mail_subject_blog[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_blog[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }
      elseif ($mail_data_cat == 'story') {
        if (variable_get('mail_template_emails') != '') {
          //$to_mail = $to_mail . ' , ' . variable_get('mail_template_emails');
          $to_mail = variable_get('mail_template_emails');
        }
        if ($node->status == 1) {
          $byline_emails = get_node_byline_emails($node);
          $to_mail = $to_mail . ' , ' . $byline_emails;
        }
        $subject = $mail_data->field_mail_subject_story[LANGUAGE_NONE][0]['value'];
        $alias = drupal_get_path_alias('node/' . $node->nid . '');
        if($alias == 'node/'.$node->nid && !empty($node->path['alias'])){
		  $alias = $node->path['alias'];
		}
        $weburl = FRONT_URL . "/" . $alias;
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_story[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_by_line = str_replace('[itg_mail_token:itg_node_byline]', $node->field_itg_common_by_line_name[LANGUAGE_NONE][0]['value'], $mail_node_type);
        $mail_node_city = str_replace('[itg_mail_token:itg_node_city]', story_city_list($node->field_stroy_city[LANGUAGE_NONE]), $mail_node_by_line);
        $mail_node_creator = str_replace('[itg_mail_token:itg_node_creator]', $current_user_name, $mail_node_city);
        $mail_node_weburl = str_replace('[itg_mail_token:itg_node_url]', $weburl, $mail_node_creator);
        $mail_node_short_desc = str_replace('[itg_mail_token:itg_node_short_desc]', $node->field_story_kicker_text[LANGUAGE_NONE]['0']['value'], $mail_node_weburl);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_short_desc);
      }
      elseif ($mail_data_cat == 'photogallery') {
        if(variable_get('mail_template_emails') != ''){
            //$to_mail = $to_mail.' , '.variable_get('mail_template_emails');
            $to_mail = variable_get('mail_template_emails');
        }
        
        $subject = $mail_data->field_mail_subject_photo_gallery[LANGUAGE_NONE][0]['value'];
        $alias = drupal_get_path_alias('node/' . $node->nid . '');
        if($alias == 'node/'.$node->nid && !empty($node->path['alias'])){
		  $alias = $node->path['alias'];
		}
        $weburl = FRONT_URL . "/" . $alias;
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_photo_gallery[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_by_line = str_replace('[itg_mail_token:itg_node_byline]', $node->field_itg_common_by_line_name[LANGUAGE_NONE][0]['value'], $mail_node_type);
        $mail_node_city = str_replace('[itg_mail_token:itg_node_city]', story_city_list($node->field_stroy_city[LANGUAGE_NONE]), $mail_node_by_line);
        $mail_node_creator = str_replace('[itg_mail_token:itg_node_creator]', $current_user_name, $mail_node_city);
        $mail_node_weburl = str_replace('[itg_mail_token:itg_node_url]', $weburl, $mail_node_creator);
        $mail_node_short_desc = str_replace('[itg_mail_token:itg_node_short_desc]', $node->field_story_kicker_text[LANGUAGE_NONE]['0']['value'], $mail_node_weburl);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_short_desc);
      }
      elseif ($mail_data_cat == 'podcast') {
        $subject = $mail_data->field_mail_subject_podcast[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_podcast[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }
      elseif ($mail_data_cat == 'videogallery') {
        if(variable_get('publish_alert_emails_videos') != ''){
            //$to_mail = $to_mail.' , '.variable_get('mail_template_emails');
            $to_mail = variable_get('publish_alert_emails_videos');
        }
        if ($node->status == 1) {
          $byline_emails = get_node_byline_emails($node);
          $to_mail = $to_mail . ' , ' . $byline_emails;
        }
        $subject = $mail_data->field_mail_subject_video[LANGUAGE_NONE][0]['value'];
        $alias = drupal_get_path_alias('node/' . $node->nid . '');
        if($alias == 'node/'.$node->nid && !empty($node->path['alias'])){
		  $alias = $node->path['alias'];
		}
        $weburl = FRONT_URL . "/" . $alias;
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_video[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_by_line = str_replace('[itg_mail_token:itg_node_byline]', $node->field_itg_common_by_line_name[LANGUAGE_NONE][0]['value'], $mail_node_type);
        $mail_node_city = str_replace('[itg_mail_token:itg_node_city]', story_city_list($node->field_stroy_city[LANGUAGE_NONE]), $mail_node_by_line);
        $mail_node_creator = str_replace('[itg_mail_token:itg_node_creator]', $current_user_name, $mail_node_city);
        $mail_node_weburl = str_replace('[itg_mail_token:itg_node_url]', $weburl, $mail_node_creator);
        $mail_node_short_desc = str_replace('[itg_mail_token:itg_node_short_desc]', $node->field_story_kicker_text[LANGUAGE_NONE]['0']['value'], $mail_node_weburl);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_short_desc);
      }
      $mail_content = $mail_node_author;
    }
  }
  elseif (FALSE && $event == 'create' && $review == 'needs_review') { // We don't need this feature right now
    $to_mail = implode(',', $to);
    if (function_exists('itg_mail_templates_get_mailcontent')) {
      $mail_data = itg_mail_templates_get_mailcontent($content_type, $review);
      $mail_data_cat = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];

      if ($mail_data_cat == 'blog') {
        $subject = $mail_data->field_mail_subject_blog[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_blog[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }
      elseif ($mail_data_cat == 'story') {
        $subject = $mail_data->field_mail_subject_story[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_story[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }
      elseif ($mail_data_cat == 'photogallery') {
        $subject = $mail_data->field_mail_subject_photo_gallery[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_photo_gallery[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }
      elseif ($mail_data_cat == 'podcast') {
        $subject = $mail_data->field_mail_subject_podcast[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_podcast[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }
      elseif ($mail_data_cat == 'videogallery') {
        $subject = $mail_data->field_mail_subject_video[LANGUAGE_NONE][0]['value'];
        $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_video[LANGUAGE_NONE][0]['value']);
        $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
        $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
        $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
      }

      $mail_content = $mail_node_author;
    }
  }
  elseif ($event == 'update') {
    if (FALSE && $review == 'needs_review') {// We don't need this feature right now
      $to_mail = implode(',', $to);
      if (function_exists('itg_mail_templates_get_mailcontent')) {
        $mail_data = itg_mail_templates_get_mailcontent($content_type, $review);
        $mail_data_cat = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];

        if ($mail_data_cat == 'blog') {
          $subject = $mail_data->field_mail_subject_blog[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_blog[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'story') {
          $subject = $mail_data->field_mail_subject_story[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_story[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'photogallery') {
          $subject = $mail_data->field_mail_subject_photo_gallery[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_photo_gallery[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'podcast') {
          $subject = $mail_data->field_mail_subject_podcast[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_podcast[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'videogallery') {
          $subject = $mail_data->field_mail_subject_video[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_video[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }

        $mail_content = $mail_node_author;
      }
    }
    else if (FALSE && $review == 'rejected') { // We don't need this feature right now
      $author_mail[] = db_query("SELECT mail from {users} WHERE uid = :uid AND status = 1", array(":uid" => $node->uid))->fetchField();
      $to_mail = $author_mail[0];

      if (function_exists('itg_mail_templates_get_mailcontent')) {
        $mail_data = itg_mail_templates_get_mailcontent($content_type, $review);
        $mail_data_cat = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];

        if ($mail_data_cat == 'blog') {
          $subject = $mail_data->field_mail_subject_blog[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_blog[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'story') {
          $subject = $mail_data->field_mail_subject_story[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_story[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'photogallery') {
          $subject = $mail_data->field_mail_subject_photo_gallery[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_photo_gallery[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'podcast') {
          $subject = $mail_data->field_mail_subject_podcast[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_podcast[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'videogallery') {
          $subject = $mail_data->field_mail_subject_video[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_video[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        $mail_content = $mail_node_author;
      }
    }
    else if (FALSE && $review == 'needs_modification') { // We don't need this feature right now
      $author_mail[] = db_query("SELECT mail from {users} WHERE uid = :uid AND status = 1", array(":uid" => $node->uid))->fetchField();
      $to_mail = $author_mail[0];

      if (function_exists('itg_mail_templates_get_mailcontent')) {
        $mail_data = itg_mail_templates_get_mailcontent($content_type, $review);
        $mail_data_cat = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];
        if ($mail_data_cat == 'blog') {
          $subject = $mail_data->field_mail_subject_blog[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_blog[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'story') {
          $subject = $mail_data->field_mail_subject_story[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_story[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'photogallery') {
          $subject = $mail_data->field_mail_subject_photo_gallery[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_photo_gallery[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'podcast') {
          $subject = $mail_data->field_mail_subject_podcast[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_podcast[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'videogallery') {
          $subject = $mail_data->field_mail_subject_video[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_video[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        $mail_content = $mail_node_author;
      }
    }
    else if ($review == 'published') {
      $author_mail[] = db_query("SELECT mail from {users} WHERE uid = :uid AND status = 1", array(":uid" => $node->uid))->fetchField();
      $to_mail = $author_mail[0];

      if (function_exists('itg_mail_templates_get_mailcontent')) {
        $mail_data = itg_mail_templates_get_mailcontent($content_type, 'update');
        $mail_data_cat = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];
        if ($mail_data_cat == 'blog') {
          $subject = $mail_data->field_mail_subject_blog[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_blog[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'story') {
          
          if ($node->status == 1 && $node->original->status == 0) {
            if (variable_get('mail_template_emails') != '') {
              //$to_mail = $to_mail.' , '.variable_get('mail_template_emails');
              $to_mail = variable_get('mail_template_emails');
            }
            $byline_emails = get_node_byline_emails($node);
            $to_mail = $to_mail . ' , ' . $byline_emails;
          }

          $subject = $mail_data->field_mail_subject_story[LANGUAGE_NONE][0]['value'];
          $alias = drupal_get_path_alias('node/' . $node->nid . '');
          if($alias == 'node/'.$node->nid && !empty($node->path['alias'])){
		    $alias = $node->path['alias'];
		  }
          $weburl = FRONT_URL . "/" . $alias;
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_story[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_by_line = str_replace('[itg_mail_token:itg_node_byline]', $node->field_itg_common_by_line_name[LANGUAGE_NONE][0]['value'], $mail_node_type);
          $mail_node_city = str_replace('[itg_mail_token:itg_node_city]', story_city_list($node->field_stroy_city[LANGUAGE_NONE]), $mail_node_by_line);
          $mail_node_creator = str_replace('[itg_mail_token:itg_node_creator]', $current_user_name, $mail_node_city);
          $mail_node_weburl = str_replace('[itg_mail_token:itg_node_url]', $weburl, $mail_node_creator);
          $mail_node_short_desc = str_replace('[itg_mail_token:itg_node_short_desc]', $node->field_story_kicker_text[LANGUAGE_NONE]['0']['value'], $mail_node_weburl);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_short_desc);
        }
        elseif ($mail_data_cat == 'photogallery') {
		      if ($node->status == 1 && $node->original->status == 0) {
            if (variable_get('mail_template_emails') != '') {
              //$to_mail = $to_mail.' , '.variable_get('mail_template_emails');
              $to_mail = variable_get('mail_template_emails');
            }
          }

          $subject = $mail_data->field_mail_subject_photo_gallery[LANGUAGE_NONE][0]['value'];
          $alias = drupal_get_path_alias('node/' . $node->nid . '');
          if($alias == 'node/'.$node->nid && !empty($node->path['alias'])){
		    $alias = $node->path['alias'];
		  }
          $weburl = FRONT_URL . "/" . $alias;
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_photo_gallery[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_by_line = str_replace('[itg_mail_token:itg_node_byline]', $node->field_itg_common_by_line_name[LANGUAGE_NONE][0]['value'], $mail_node_type);
          $mail_node_city = str_replace('[itg_mail_token:itg_node_city]', story_city_list($node->field_stroy_city[LANGUAGE_NONE]), $mail_node_by_line);
          $mail_node_creator = str_replace('[itg_mail_token:itg_node_creator]', $current_user_name, $mail_node_city);
          $mail_node_weburl = str_replace('[itg_mail_token:itg_node_url]', $weburl, $mail_node_creator);
          $mail_node_short_desc = str_replace('[itg_mail_token:itg_node_short_desc]', $node->field_story_kicker_text[LANGUAGE_NONE]['0']['value'], $mail_node_weburl);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_short_desc);
        }
        elseif ($mail_data_cat == 'podcast') {
          $subject = $mail_data->field_mail_subject_podcast[LANGUAGE_NONE][0]['value'];
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_podcast[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_type);
        }
        elseif ($mail_data_cat == 'videogallery') {

          if ($node->status == 1 && $node->original->status == 0) {
            if (variable_get('publish_alert_emails_videos') != '') {
              //$to_mail = $to_mail.' , '.variable_get('mail_template_emails');
              $to_mail = variable_get('publish_alert_emails_videos');
            }
            $byline_emails = get_node_byline_emails($node);
            $to_mail = $to_mail . ' , ' . $byline_emails;
          }
          $subject = $mail_data->field_mail_subject_video[LANGUAGE_NONE][0]['value'];
          $alias = drupal_get_path_alias('node/' . $node->nid . '');
          if($alias == 'node/'.$node->nid && !empty($node->path['alias'])){
		    $alias = $node->path['alias'];
		  }
          $weburl = FRONT_URL . "/" . $alias;
          $mail_node_title = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_data->field_mail_body_video[LANGUAGE_NONE][0]['value']);
          $mail_node_url = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $mail_node_title);
          $mail_node_type = str_replace('[itg_mail_token:itg_node_type]', $node->type, $mail_node_url);
          $mail_node_by_line = str_replace('[itg_mail_token:itg_node_byline]', $node->field_itg_common_by_line_name[LANGUAGE_NONE][0]['value'], $mail_node_type);
          $mail_node_city = str_replace('[itg_mail_token:itg_node_city]', story_city_list($node->field_stroy_city[LANGUAGE_NONE]), $mail_node_by_line);
          $mail_node_creator = str_replace('[itg_mail_token:itg_node_creator]', $current_user_name, $mail_node_city);
          $mail_node_weburl = str_replace('[itg_mail_token:itg_node_url]', $weburl, $mail_node_creator);
          $mail_node_short_desc = str_replace('[itg_mail_token:itg_node_short_desc]', $node->field_story_kicker_text[LANGUAGE_NONE]['0']['value'], $mail_node_weburl);
          $mail_node_author = str_replace('[itg_mail_token:itg_author]', $current_user_name, $mail_node_short_desc);
        }
        $mail_content = $mail_node_author;
      }
    }
    else if (!empty ($vbo_state) && $vbo_state == 'pub-unpub' && ($review != 'needs_review' && $review != 'rejected' && $review != 'needs_modification')){
      if ($vbo_update == 'published') {
        $subject_line_upd = 'unpublished';
        $body_htwo = strtoupper($content_type) . ' UNPUBLISHED';
      } 
      elseif($vbo_update == 'draft') {
        $subject_line_upd = 'published';
        $body_htwo = strtoupper($content_type) . ' PUBLISHED';
      }
      
     if ($node->type == 'videogallery' && variable_get('unpublish_alert_emails_videos') != '') {
			  $to_mail = variable_get('unpublish_alert_emails_videos');
		 } else if(variable_get('unpublish_alert_emails') != '') {
       $to_mail = variable_get('unpublish_alert_emails');
     }
      $subject = 'A new ' . $content_type . ' has been ' . $subject_line_upd . ', please find details below.';
      $mail_content = '<div style="max-width: 502px; margin: 0 auto; font-family: sans-serif; color: #000;">
                        <table style="border-collapse: collapse; border: 1px solid #ececec;"> 
                            <tr>
                                <td style="background-color:#ececec;">
                                    <img src="template_logo.png" alt="Indiatoday" title="Indiatoday" />
                                </td>
                            </tr>
                            <tr>
                                <td style="padding: 10px 20px;">
                                    <h2 style="font-size: 18px; margin: 20px 0 30px;">' . $body_htwo . ' :</h2>
                                    <strong style="font-size: 16px;">Dear Team,</strong>
                                    <p style="font-size: 16px; color: #595959; margin: 20px 0;">' . ucwords($content_type) . ' <strong style="color: #000;">: ' . $node_url . ' </strong></p>
                                    <p style="font-size: 16px; color: #595959; margin: 20px 0;"> Url: ' . $actual_node_url . '</p>
                                    <p style="font-size: 16px; color: #595959; margin: 20px 0;">has been ' . $subject_line_upd . '.</p>
                                    <p style="font-size: 16px; color: #595959; margin: 20px 0;"><strong style="color: #000;">Thanks,</strong><br>India Today Team</p>
                                </td>
                            </tr>
                            <tr>
                                <td style="background-color: #000; font-size: 11px; color: #7c7c7c; padding: 10px; text-align: center; font-weight: bold;">COPYRIGHT &copy; 2017 LIVING MEDIA INDIA LIMITED. ALL RIGHT RESERVED.</td>
                            </tr>
                        </table>
                    </div>';
    }
  }
  
  $mail_content = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $mail_content);
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
              <html xmlns:v="urn:schemas-microsoft-com:vml">
                <head><title></title></head>
                <body style="margin:0; padding:0;">';
  $content .= $mail_content;
  $content .= '</body>';
  $content .= '</html>';
  
  $params = array(
    'body' => $content,
    'subject' => $subject,
  );
  $to_mail = preg_replace('/\s+/', '', $to_mail);
  if(empty($to_mail)){
    return FALSE;
  }
  $mail = drupal_mail('itg_workflow', 'send_mail_to_task', $to_mail, language_default(), $params, 'desk-itgd@intoday.com', TRUE);
  if ($mail['result']) {
    return TRUE;
  }
  else {
    $error_msg = 'Failed to send the email!';
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}
