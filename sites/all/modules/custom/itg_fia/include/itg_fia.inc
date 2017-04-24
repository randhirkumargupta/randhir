<?php

/**
 * Implementing itg_fia_data().
 */
function itg_fia_data() {
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_social_media_integ', 'fsmi', 'n.nid = fsmi.entity_id');
  $query->fields('n', ['nid', 'created']);
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->condition('fsmi.field_story_social_media_integ_value', 'facebook_instant_article', '=');
  $query->orderBy('n.created', 'DESC');
  $query->range(0, 10);
  $query = $query->execute()->fetchCol();
  itg_fia_xml_node_feed($query);
}

/**
 * Generates and prints a custom XML feed.
 */
function itg_fia_xml_node_feed($query) {
  global $base_url;
  $xml_base = $base_url . '/' . current_path();
  $nodes = node_load_multiple($query);
  $getautor = 
  $items = '';
  foreach ($nodes as $node) {
    if ($node->workbench_moderation['current']->state == 'published') {
      $op_pub = date('F j, h:i a', $node->workbench_moderation['current']->timestamp);
      $pubdate = date('Y-m-d\Th:i:s\Z', $node->workbench_moderation['current']->timestamp);
    } else {
      $op_pub = date('F j, h:i a', $node->created);
      $pubdate = date('Y-m-d\Th:i:s\Z', $node->created);
    }
    $guid = $node->nid . " at " . $base_url;
    $op_modified = date('F j, h:i a', $node->changed);
    $modified = date('Y-m-d\Th:i:s\Z', $node->changed);
    $auth_name = get_author_name($node->field_story_reporter[LANGUAGE_NONE][0]['target_id']);
    $desc = $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'];

    $embed_code_pos = $node->field_social_embed_code_position[LANGUAGE_NONE][0]['value'];
    $embed_code_data = $node->field_social_embed_code[LANGUAGE_NONE][0]['value'];
    $audio_pos = $node->field_facebook_audio_position[LANGUAGE_NONE][0]['value'];
    $audio_url = $node->field_facebook_instant_audio_url[LANGUAGE_NONE][0]['value'];
    $img_position =  $node->field_animated_image_position[LANGUAGE_NONE][0]['value'];
    $img_path = file_create_url($node->field_facebook_animated_image[LANGUAGE_NONE][0]['uri']);
    $fb_instant_image = file_create_url($node->field_story_big_image[LANGUAGE_NONE][0]['uri']);
    $map_pos = $node->field_facebook_map_position[LANGUAGE_NONE][0]['value'];
    if (isset($node->field_map_embed_code[LANGUAGE_NONE][0]['value']) && !empty($node->field_map_embed_code[LANGUAGE_NONE][0]['value'])) {
      $map_data = $node->field_map_embed_code[LANGUAGE_NONE][0]['value'];
      // getting map data from map <iframe>
      if (strpos($map_data, '<iframe') !== false) {
        $map_data_iframe = $map_data;
        $get_map_iframe = explode(" ", $map_data_iframe);
        $get_map_data = explode("!", $get_map_iframe[1]);
        $get_map_lat = explode("2d", $get_map_data[5]);
        $get_map_lng = explode("3d", $get_map_data[6]);
        $lat = number_format($get_map_lat[1], 6);
        $lng = number_format($get_map_lng[1], 6);
        $get_iframe_place = $get_map_data[18];
        $get_iframe_places = explode('2s', $get_map_data[18]);
        $get_place_name = str_replace("+", " ", $get_iframe_places[1]);
      } 
      else {
        // getting map data from map url
        $get_map = explode("place", $map_data);
        $get_map_coordinate = explode("@", $get_map[1]);
        $get_place = str_replace("/", "", $get_map_coordinate[0]);
        $get_place_name = str_replace("+", " ", $get_place);
        $coordinate_map = explode(",", $get_map_coordinate[1]);
        $lat = $coordinate_map[0];
        $lng = $coordinate_map[1];
      }
    }
    
    // getting gallery data
    $target_nids = NULL;
    $gall_position = NULL;
    if(is_array($node->field_facebook_gallery_associate[LANGUAGE_NONE]) && !empty($node->field_facebook_gallery_associate[LANGUAGE_NONE])) {
      $associate_gallery = $node->field_facebook_gallery_associate[LANGUAGE_NONE];
      foreach($associate_gallery as $fc_k => $fc_v){
        $fc_ids = $associate_gallery[$fc_k]['value'];
        $load_fc = field_collection_item_load($fc_ids);
        $gall_position[] = $load_fc->field_gallery_position[LANGUAGE_NONE][0]['value'];
        $fc_target_id = $load_fc->field_associate_gallery_id[LANGUAGE_NONE];
        foreach($fc_target_id as $fct_k => $fct_v){
          $target_nids[] = $fct_v['target_id'];
        }
      }
    }
    
    // facebook instant article body placement
    $node_body = $node->body[LANGUAGE_NONE][0]['value'];
    $numLine = explode("<p>",$node_body);
    unset($numLine[0]);
    foreach ($numLine as $body_key =>  $body_val) {
      $bk[$body_key] = $body_key;
      $body_vals[$body_key] = $numLine[$body_key];
    }
    
    // facebook instant article audio placement
    if (!empty($audio_url)) {
      if (in_array($audio_pos, $bk)) {
        $body_vals[$audio_pos] = $body_vals[$audio_pos] . 
                '<figure>
                   <audio muted title="audio title">
                     <source src="' . $audio_url . '">
                  </audio>
                 </figure>';
      } else {
        $last_postion = end($bk);
        $body_vals[$last_postion] = $body_vals[$last_postion] . 
               '<figure>
                  <audio muted title="audio title">
                    <source src="' . $audio_url . '">
                  </audio>
                </figure>';
      }
    }
    
    // facebook instant article animated image placement
    if (!empty($img_path)) {
      if (in_array($img_position, $bk)) {
        $body_vals[$img_position] = $body_vals[$img_position] . 
               '<figure>
                  <img src="'.$img_path.'" />
                </figure>';
      } else {
        $last_postion = end($bk);
        $body_vals[$last_postion] = $body_vals[$last_postion] . 
               '<figure>
                  <img src="'.$img_path.'" />
                </figure>';
      }
    }
    
    // facebook instant article map placement
    if (!empty($get_place_name)) {
      if (in_array($map_pos, $bk)) {
        $body_vals[$map_pos] = $body_vals[$map_pos] . 
                '<figure class="op-map">
                  <script type="application/json" class="op-geotag">
                    {
                      "type": "Feature",
                      "geometry":
                        {
                          "type": "Point",
                          "coordinates": ['.$lat.', '.$lng.']
                        },
                      "properties":
                        {
                          "title": "'.$get_place_name.'",
                          "radius": 10000,
                          "pivot": true,   
                          "style": "satellite",
                        }
                     }
                  </script>
                </figure>';
      } else {
        $last_postion = end($bk);
        $body_vals[$last_postion] = $body_vals[$last_postion] . 
                '<figure class="op-map">
                  <script type="application/json" class="op-geotag">
                    {
                      "type": "Feature",
                      "geometry":
                        {
                          "type": "Point",
                          "coordinates": ['.$lat.', '.$lng.']
                        },
                      "properties":
                        {
                          "title": "'.$get_place_name.'",
                          "radius": 10000,
                          "pivot": true,   
                          "style": "satellite",
                        }
                     }
                  </script>
                </figure>';

      }
    }

    // Creating Slideshow for facebook instant article data
    if(!empty($target_nids)) {
      $gall_nodes = node_load_multiple($target_nids);
      foreach ($gall_position as $pos) {
        $gall_nodes = node_load_multiple($target_nids);
        foreach ($gall_nodes as $gl_k => $gl_v) {
          $imgs_path = file_create_url($gl_v->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
          if (in_array($pos, $bk)) {
            $body_vals[$pos] = $body_vals[$pos] . 
              '<figure class="op-slideshow">
                <figure>
                  <img src="'.$imgs_path.'" />
                </figure>
              </figure>';
          } else {
            $last_postion = end($bk);
            $body_vals[$last_postion] = $body_vals[$last_postion] . 
              '<figure class="op-slideshow">
                <figure>
                  <img src="'.$imgs_path.'" />
                </figure>
              </figure>';
          }
          
        }
      }
    }
    
    // Creating Social Embed Code for facebook instant article data
    if(!empty($embed_code_data)) {
      if (in_array($embed_code_pos, $bk)) {
        $body_vals[$embed_code_pos] = $body_vals[$embed_code_pos] . 
                '<figure class="op-interactive">' . $embed_code_data . '</figure>';
      } else {
        $last_postion = end($bk);
        $body_vals[$last_postion] = $body_vals[$last_postion] . 
               '<figure class="op-interactive">' . $embed_code_data . '</figure>';
      }
    }

    
    $node_body_content = implode(" ", $body_vals);
    $node->link = url("node/$node->nid", ['absolute' => TRUE]);
    $kicker = $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
    $items .= itg_fia_xml_format_rss_item($kicker, $target_nids, $fb_instant_image, $guid, $node_body_content, $node->title, $node->link, $pubdate, $auth_name, $desc, $op_pub, $modified, $op_modified);
  }
  
  global $base_url;
  $channel_defaults = array(
    'title' => variable_get('site_name', 'Drupal'),
    'link' => $base_url . '/' . current_path(),
  );
  
  $output = "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\" ?>\n";
  $output .= "<rss version='2.0' xml:base='" . $xml_base . "' xmlns:dc='http://purl.org/dc/elements/1.1/' xmlns:atom='http://www.w3.org/2005/Atom'>\n";
  $output .= itg_fia_xml_format_rss_channel($channel_defaults['title'], $channel_defaults['link'], $items);
  drupal_add_http_header('Content-Type:application/rss+xml; charset=utf-8');
  print $output;
}

/**
 * Creates the xml channel.
 */
function itg_fia_xml_format_rss_channel($title, $link, $items) {

  $output = "  <channel>\n";
  $output .= "    <title>" . $title . "</title>\n";
  $output .= "    <link>" . check_url($link) . "</link>\n";
  $output .= "    <description>" . t("Facebook Instant Articles feed") . "</description>\n";
  $output .= "    <language>en</language>\n";
  $output .= "    <atom:link href='" . check_url($link) . "' rel='self' type='application/rss+xml' />\n";
  $output .= $items;
  $output .= "  </channel>\n";
  $output .= "</rss>\n";

  return $output;
}

/**
 * Creates the xml item.
 */
function itg_fia_xml_format_rss_item($kicker, $target_nids, $fb_instant_image, $guid, $node_body_content, $title, $link, $pubdate, $name, $desc, $op_pub, $modified, $op_modified) {
  $output = "    <item>\n";
  
  $output .= '      <title>' . $title . "</title>\n";
  $output .= '      <link>' . check_url($link) . "</link>\n";
  $output .= '      <guid>' . $guid . "</guid>\n";
  $output .= '      <pubDate>' . $pubdate . "</pubDate>\n";
  $output .= '      <author>' . $name . "</author>\n";
  $output .= '      <description>' . $desc . "</description>\n";
  $output .= "    <content:encoded>\n";
  $output .= "    <![CDATA[\n";
  $output .= "    <!doctype html>\n";
  $output .= "    <html lang='en' prefix='op: http://media.facebook.com/op#'>\n";
  $output .= "    <head>\n";
  $output .= "    <meta charset='utf-8'>\n";
  $output .= "    <link rel='canonical' href='" . $link . "'>\n";
  $output .= "    <meta property='op:markup_version' content='v1.0'>\n";
  $output .= "    <body>\n";
  $output .= "    </head>\n\n";
  $output .= "    <article>\n";
  $output .= "    <header>\n";
  
  // <!-- The header image shown inside your article --> 
  $output .= "    <figure data-mode=aspect-fit>\n";
  $output .= "    <video loop>\n";
  $output .= "    <source src='" . $fb_instant_image . "' type='video/mov' />\n";
  $output .= "    </video>\n\n";
  $output .= "    </figure>\n\n";
  $output .= "      <h1>" . $title . "</h1>\n";
  $output .= "      <h2>" . $kicker . "</h2>\n";
  // <!-- A kicker for your article -->
  $output .= "      <h3 class='op-kicker'>" . $kicker . "</h3>\n";
  // <!-- The author of your article -->
  $output .= "      <address>" . $name . "</address>\n";
  $output .= "      <time class='op-published' dateTime='" . $pubdate . "'>" . $op_pub . "</time>\n";
  $output .= "      <time class='op-modified' dateTime='" . $modified . "'>" . $op_modified . "</time>\n";
  
  $output .= "    </header>\n\n";
  $output .= "    <div property='content:encoded'>". $node_body_content . "</div>\n";
  
  $output .= "    <footer>\n";
  // <!-- Credits for your article -->
  $output .= "    <aside>The footer section can be used for acknowledgements, author bios, related articles, or any other supplemental information.</aside>\n";
  // <!-- Copyright details for your article -->
  $output .= "    <small>© Facebook</small>\n";
  $output .= "    </footer>\n\n";

  $output .= "    </article>\n\n";
  $output .= "    </body>\n\n";
  
  $output .= "    </html>\n\n";
  $output .= "    ]]>\n\n";
  $output .= "    </content:encoded>\n\n";
  $output .= "    </item>\n\n";
  return $output;
}

/*
 * Return Author Name
 */
function get_author_name($auid) {
  $author_name = db_query("SELECT title from {node} WHERE nid = :nid ", array(":nid" => $auid))->fetchField();
  return $author_name;
}