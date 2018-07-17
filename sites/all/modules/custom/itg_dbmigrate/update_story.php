<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

update_migrated_story();

/**
 * Implement function for Update story fields.
 */
function update_migrated_story() {
  $query = db_select('migrate_map_itgstorylist', 'm_map_i');
  $query->fields('m_map_i', array('destid1', 'sourceid1'));
  $query->isNotNull('destid1');
  $query->orderBy('sourceid1', 'ASC');
  $result = $query->execute();
  foreach ($result as $resul) {
    $check_updated = check_updated_node_story($resul->destid1, $resul->sourceid1);
    if (empty($check_updated)) {
      $val['node_destid'] = $resul->destid1;
      $val['xml_sourceid'] = $resul->sourceid1;
      $node = node_load($resul->destid1);
      /*       * ***************XML LOAD************ */
      $xml_path = 'sites/default/files/migrate/xml_file/story_update/';
      $xml_file = $resul->sourceid1 . '.xml';
      $xml_source = $xml_path . $xml_file;
      $xml = simplexml_load_file($xml_source, 'SimpleXMLElement');
      if (!empty(migrate_story_image_missed_folder($val['xml_sourceid']))) { //CHECK IMAGE EXIST IN MIGRATE_MESSAGE_ITGSTORYLIST TABLE.
        if (!isset($node->field_story_extra_large_image['und']) && empty($node->field_story_extra_large_image['und'][0])) {
          $extralargeimage_url = (string) $xml->extralargeimage;
          $fid = '';
          if (!empty($extralargeimage_url)) {
            $fid = img_save_return_fid($extralargeimage_url, $node->nid, (int) $xml->id, 'extralargeimage');
            if (!empty($fid)) {
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->extra_large_alt;
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] = (string) $xml->extra_large_title;
            }
          }
        }
        if (!isset($node->field_story_large_image['und']) && empty($node->field_story_large_image['und'][0])) {
          $largeimage_url = (string) $xml->largeimage;
          $fid = '';
          if (!empty($largeimage_url)) {
            $fid = img_save_return_fid($largeimage_url, $node->nid, (int) $xml->id, 'largeimage');
            if (!empty($fid)) {
              $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
              $node->field_story_large_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->large_alt;
              $node->field_story_large_image[LANGUAGE_NONE][0]['title'] = (string) $xml->large_title;
            }
          }
        }
        if (!isset($node->field_story_medium_image['und']) && empty($node->field_story_medium_image['und'][0])) {
          $medium_url = (string) $xml->mediumimage;
          $fid = '';
          if (!empty($medium_url)) {
            $fid = img_save_return_fid($extralargeimage_url, $node->nid, (int) $xml->id, 'mediumimage');
            if (!empty($fid)) {
              $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] = $fid;
              $node->field_story_medium_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->mediumimage_alt;
              $node->field_story_medium_image[LANGUAGE_NONE][0]['title'] = (string) $xml->mediumimage_title;
            }
          }
        }
        if (!isset($node->field_story_small_image['und']) && empty($node->field_story_small_image['und'][0])) {
          $small_url = (string) $xml->smallimage;
          $fid = '';
          if (!empty($small_url)) {
            $fid = img_save_return_fid($small_url, $node->nid, (int) $xml->id, 'smallimage');
            if (!empty($fid)) {
              $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] = $fid;
              $node->field_story_small_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->smallimage_alt;
              $node->field_story_small_image[LANGUAGE_NONE][0]['title'] = (string) $xml->smallimage_title;
            }
          }
        }
        if (!isset($node->field_story_extra_small_image['und']) && empty($node->field_story_extra_small_image['und'][0])) {
          $esmall_url = (string) $xml->extrasmallimage;
          $fid = '';
          if (!empty($esmall_url)) {
            $fid = img_save_return_fid($esmall_url, $node->nid, (int) $xml->id, 'extrasmallimage');
            if (!empty($fid)) {
              $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] = $fid;
              $node->field_story_extra_small_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->extra_small_alt;
              $node->field_story_extra_small_image[LANGUAGE_NONE][0]['title'] = (string) $xml->extra_small_title;
            }
          }
        }
        if (!isset($node->field_story_expert_image['und']) && empty($node->field_story_expert_image['und'][0])) {
          $expert_url = (string) $xml->expertimage;
          $fid = '';
          if (!empty($expert_url)) {
            $fid = img_save_return_fid($expert_url, $node->nid, (int) $xml->id, 'expertimage');
            if (!empty($fid)) {
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'] = (string) $xml->expert_alt;
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] = (string) $xml->expert_title;
            }
          }
        }
        if (!isset($node->field_story_quote_image['und']) && empty($node->field_story_quote_image['und'][0])) {
          $quote_url = (string) $xml->fulltext_conclaveformat->quote_image;
          $fid = '';
          if (!empty($quote_url)) {
            $fid = img_save_return_fid($quote_url, $node->nid, (int) $xml->id, 'quote_image');
            if (!empty($fid)) {
              $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
            }
          }
        }
        if (!isset($node->field_story_tech_pros_cons_image['und']) && empty($node->field_story_tech_pros_cons_image['und'][0])) {
          $pros_cons_url = (string) $xml->pros_cons->tech_pros_cons_main->pron_cons_img;
          $fid = '';
          if (!empty($pros_cons_url)) {
            $fid = img_save_return_fid($pros_cons_url, $node->nid, (int) $xml->id, 'pron_cons_img');
            if (!empty($fid)) {
              $node->field_story_tech_pros_cons_image[LANGUAGE_NONE][0]['fid'] = $fid;
            }
          }
        }
        if (!isset($node->field_story_tech_image_gallery['und']) && empty($node->field_story_tech_image_gallery['und'][0])) {
          $fid_array = array();
          foreach ($xml->tech_image_gallery->image as $tech_img) {
            if (!empty($tech_img)) {
              $fid_array[]['fid'] = img_save_return_fid($tech_img, $node->nid, (int) $xml->id, 'tech_image_gallery');
            }
          }
          if (!empty($fid_array) && isset($fid_array)) {
            $node->field_story_tech_image_gallery[LANGUAGE_NONE] = $fid_array;
          }
        }
        if (!isset($node->field_facebook_animated_image['und']) && empty($node->field_facebook_animated_image['und'][0])) {
          $facebook_animated_url = (string) $xml->facebook_instant_article_integration->animated_image;
          $fid = '';
          if (!empty($facebook_animated_url)) {
            $fid = img_save_return_fid($facebook_animated_url, $node->nid, (int) $xml->id, 'animated_image');
            if (!empty($fid)) {
              $node->field_facebook_animated_image[LANGUAGE_NONE][0]['fid'] = $fid;
            }
          }
        }
        if (!isset($node->field_story_big_image['und']) && empty($node->field_story_big_image['und'][0])) {
          $big_url = (string) $xml->bigimage;
          $fid = '';
          if (!empty($big_url)) {
            $fid = img_save_return_fid($big_url, $node->nid, (int) $xml->id, 'big_image');
            if (!empty($fid)) {
              $node->field_story_big_image[LANGUAGE_NONE][0]['fid'] = $fid;
            }
          }
        }
      } //xml check


      if (!empty($node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'])) {
        $node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'] = '';
      }

      if (!empty($xml->external_url)) { // update for external url we have to create field in story form.
        $node->field_story_external_url[LANGUAGE_NONE][0]['value'] = (string) $xml->external_url;
      }

      // if (!empty($xml->longheadline) && strlen((string) $xml->longheadline) > 255) { //Long Headine update
      if (!empty($xml->longheadline)) { //Long Headine update
        $newtitle = (string) $xml->longheadline;
        db_update('node') // Update title in node table
            ->fields(array(
              'title' => $newtitle,
            ))
            ->condition('nid', $node->nid, '=')
            ->execute();

        db_update('node_revision') // Update title in node revision
            ->fields(array(
              'title' => $newtitle,
            ))
            ->condition('nid', $node->nid, '=')
            ->execute();
      }

      /* Listicle Title */
      //if (!empty($xml->fulltext_conclaveformat->listicle_title) && strlen((string) $xml->fulltext_conclaveformat->listicle_title) > 255) {
      if (!empty($xml->fulltext_conclaveformat->listicle_title)) {
        $node->field_story_template_guru[LANGUAGE_NONE][0]['value'] = (string) $xml->fulltext_conclaveformat->listicle_title;
      }

      /* Quote Title */
      // if (!empty($xml->fulltext_conclaveformat->quote_title) && strlen((string) $xml->fulltext_conclaveformat->quote_title) > 255) {
      if (!empty($xml->fulltext_conclaveformat->quote_title)) {
        $node->field_story_quote_title[LANGUAGE_NONE][0]['value'] = (string) $xml->fulltext_conclaveformat->quote_title;
      }

      /* Factoid Title */
      // if (!empty($xml->fulltext_conclaveformat->factoids_title) && strlen((string) $xml->fulltext_conclaveformat->factoids_title) > 255) {
      if (!empty($xml->fulltext_conclaveformat->factoids_title)) {
        $node->field_story_factoids_title[LANGUAGE_NONE][0]['value'] = (string) $xml->fulltext_conclaveformat->factoids_title;
      }

      /* Quote field */
      if (isset($xml->fulltext_conclaveformat->quotes->quote) && !empty($xml->fulltext_conclaveformat->quotes->quote)) {
        foreach ($xml->fulltext_conclaveformat->quotes->quote as $final_quote) {
          $data_quotes[]['value'] = (string) $final_quote;
        }
      }
      if (!empty($data_quotes) && isset($data_quotes)) {
        unset($node->field_story_template_quotes[LANGUAGE_NONE]);
        $node->field_story_template_quotes[LANGUAGE_NONE] = $data_quotes;
      }

      /* Factoids Field Update */
      if (isset($xml->fulltext_conclaveformat->factoids_content->factoids) && !empty($xml->fulltext_conclaveformat->factoids_content->factoids)) {
        foreach ($xml->fulltext_conclaveformat->factoids_content->factoids as $final_factoid) {
          $data_factoid[]['value'] = (string) $final_factoid;
        }
      }
      if (!empty($data_factoid) && isset($data_factoid)) {
        unset($node->field_story_template_factoids[LANGUAGE_NONE]);
        $node->field_story_template_factoids[LANGUAGE_NONE] = $data_factoid;
      }

      /* Brief case content update */
      if (isset($xml->briefcase_content->briefcase) && !empty($xml->briefcase_content->briefcase)) {
        foreach ($xml->briefcase_content->briefcase as $final_briefcase) {
          $data_brifcase[]['value'] = (string) $final_briefcase;
        }
      }
      if (!empty($data_brifcase) && isset($data_brifcase)) {
        unset($node->field_story_highlights[LANGUAGE_NONE]);
        $node->field_story_highlights[LANGUAGE_NONE] = $data_brifcase;
      }

      /* multiple city update */
      if (isset($xml->cities->city) && !empty($xml->cities->city)) {
        foreach ($xml->cities->city as $final_city) {
          $data_city[]['tid'] = (string) $final_city;
        }
      }

      if (!empty($data_city) && isset($data_city)) {
        unset($node->field_stroy_city[LANGUAGE_NONE]);
        $node->field_stroy_city[LANGUAGE_NONE] = $data_city;
      }

      /*       * ***************field_facebook_gallery_associate********************** */
      //facebook instant article filed
      if (isset($xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate) && !empty($xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate->gallery_id)) {
        $pos_count = 0;
        foreach ($xml->facebook_instant_article_integration->gallery_associate_content->gallery_associate as $facebook_article) {
          if (!empty($facebook_article->gallery_id_position) || !empty($facebook_article->gallery_id)) {
            $position = (int) $facebook_article->gallery_id_position;
            $gallery_id = (int) $facebook_article->gallery_id;
            $values = array(
              'field_name' => 'field_facebook_gallery_associate',
              'field_gallery_position' => array(LANGUAGE_NONE => array(array('value' => $position))),
              'field_associate_gallery_id' => array(LANGUAGE_NONE => array(array('target_id' => $gallery_id))),
            );
            $field_collection_item_facebook = entity_create('field_collection_item', $values);
            $field_collection_item_facebook->setHostEntity('node', $node);
            $field_collection_item_facebook->save(TRUE);
            $node->field_facebook_gallery_associate[LANGUAGE_NONE][$pos_count]['value'] = $field_collection_item_facebook->item_id;
            $pos_count++;
          }
        }
      }


      /* URl Alias Update Work */
      if (!empty($xml->metatags->sefurl)) {
        //Delete old sef url
        $nid = $node->nid;
        update_alias_delete($nid);

        if (!empty($xml->publisheddate)) {
          $published_date = (int) $xml->publisheddate;
        }
        else {
          $published_date = (int) $xml->createddate;
        }
        if (!empty($published_date)) {
          $published_dates = date('Y-m-d', $published_date);
        }
        $node_sef = (string) $xml->metatags->sefurl;
        $node_new_sefurl = itg_migrate_new_custompath($node, $published_dates, $node_sef);
        update_path_alias($nid, $node_new_sefurl);
      }
      field_attach_update('node', $node);
      node_update_insert_status($node->nid, (int) $xml->id);
      // p($node->nid);
    }
  } //end foreach
}

function update_alias_delete($nid) {
  $query = db_select('url_alias', 'ua');
  $query->fields('ua', array('pid'));
  $query->condition('source', "node/$nid", '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    path_delete($rel->pid);
  }
}

function update_path_alias($nid, $new_alias) {
  $path = array('source' => "node/$nid", 'alias' => $new_alias);
  path_save($path);
}

function migrate_story_image_missed_folder($source_id) {
  $query = db_select('migrate_message_itgstorylist', 'mmi');
  $query->fields('mmi', array('sourceid1'));
  //$query->condition('message', '%' . db_like('The specified file <em class="placeholder">/opt/sites/media/indiatoday/') . '%', 'LIKE'); //127973
  $query->condition('message', '%' . db_like('The specified file') . '%', 'LIKE'); //133457
  $query->condition('sourceid1', $source_id, '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    $story_xml_id[$rel->sourceid1] = $rel->sourceid1;
  }
  return $story_xml_id;
}

/**
 * Image save and return fid
 */
function img_save_return_fid($image_url, $nid, $xml_id, $field_name) {
  if (!empty($image_url)) {
    try {
      $file = file_save_data(file_get_contents($image_url), file_default_scheme() . '://' . basename($image_url), FILE_EXISTS_RENAME);
      $file->status = 1;
      $image = (array) $file;
      return $image['fid'];
    }
    catch (Exception $e) {
      db_insert('story_missed_image_update')
          ->fields(array(
            'xml_id' => $xml_id,
            'nid' => $nid,
            'image_fail_message' => $e->getMessage(),
            'image_field_name' => $field_name,
          ))
          ->execute();
    }
  }
}

/**
 * node status save in db
 */
function node_update_insert_status($nid, $xml_id) {
  db_insert('story_fields_update_update_script')
      ->fields(array(
        'xml_id' => $xml_id,
        'nid' => $nid,
        'status' => 1,
      ))
      ->execute();
}

/**
 * Check updated node
 */
function check_updated_node_story($nid, $xml_id) {
  $query = db_select('story_fields_update_update_script', 'sfuus');
  $query->fields('sfuus');
  $query->condition('nid', $nid, '=');
  $query->condition('xml_id', $xml_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

//Get custompath of migrate.
//
//function itg_migrate_new_custompath($node, $published_date, $node_sef) {
//  //$published_date = 'date';//2014-02-31
//
//  $getsection = !empty($node->field_primary_category[LANGUAGE_NONE][0]['value']) ? $node->field_primary_category[LANGUAGE_NONE][0]['value'] : '';
//  //p($node->field_primary_category);
//  // if (!empty($getsection)) {
//  if ($node->type == 'story' && is_issue_baised_magazine($node)) {
//    if (!empty($node->field_story_select_supplement['und'][0]['target_id'])) {
//      $pathdata = 'magazine/supplement';
//    }
//    else {
//      $pathdata = 'magazine';
//      $pathdata .= '/' . get_path_from_category($getsection);
//    }
//
//    //Get node type.
//    $pathdata .= '/' . $node->type;
//    // Get issue date.
//    $issue_date = $node->field_story_issue_date['und'][0]['value'];
//    $issue_date_sef_format = date('Ymd', strtotime($issue_date));
//    // preapreurl with issue date.
//    $pathdata .= '/' . $issue_date_sef_format;
//    // Add node title.
//    $pathdata .= '-' . trim($node_sef);
//    // Add node id.
//    $pathdata .= '-' . $node->nid;
//    // Add workbanch date.
//    $pathdata .= '-' . $published_date;
//    // Prepare SEO friendly node url
//    $newpath = itg_common_custompath_insert_val($pathdata);
//    return $newpath;
//    // Create url alise for magazine type story.      
//  }
//  else {
//    $set_hierarchy = get_path_from_category($getsection);
//    $node_CT = $node->type;
//    if ($node_CT == 'story') {
//      $node_CT = 'story';
//    }
//    elseif ($node_CT == 'photogallery') {
//      $node_CT = 'photo';
//    }
//    elseif ($node_CT == 'videogallery') {
//      $node_CT = 'videos';
//    }
//    if (!empty($getsection)) {
//      $pathdata = $set_hierarchy . '/' . $node_CT . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
//    }
//    else {
//      $pathdata = $node_CT . '/' . trim($node_sef) . '-' . $node->nid . '-' . $published_date;
//    }
//    $newpath = itg_common_custompath_insert_val($pathdata);
//    return $newpath;
//  }
//  //}
//}

?>

