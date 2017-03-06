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
    $node_body = $node->body[LANGUAGE_NONE][0]['value'];
    $node->link = url("node/$node->nid", ['absolute' => TRUE]);
    
    // data extracted here  
    $audio_position = $node->field_facebook_audio_position[LANGUAGE_NONE][0]['value'];
    $audio_position = $node->field_facebook_instant_audio_url[LANGUAGE_NONE][0]['value'];
    $img_position = $node->field_animated_image_position[LANGUAGE_NONE][0]['value'];
    $img_path .file_create_url($node->field_facebook_animated_image[LANGUAGE_NONE][0]['uri']);
    $map_position = $node->field_facebook_map_position[LANGUAGE_NONE][0]['value'];
    $map_code = $node->field_map_embed_code[LANGUAGE_NONE][0]['value'];
    $gall_position = $node->field_facebook_gallery_associate[LANGUAGE_NONE][0]['target_id'];
    // need to write code for gallery position
    
    $items .= itg_fia_xml_format_rss_item($img_path, $guid, $node_body, $node->title, $node->link, $pubdate, $auth_name, $desc, $op_pub, $modified, $op_modified);
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
  $output .= "    <title>" . check_plain($title) . "</title>\n";
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
function itg_fia_xml_format_rss_item($img_path, $guid, $node_body, $title, $link, $pubdate, $name, $desc, $op_pub, $modified, $op_modified) {
  $output = "    <item>\n";
  
  $output .= '      <title>' . check_plain($title) . "</title>\n";
  $output .= '      <link>' . check_url($link) . "</link>\n";
  $output .= '      <guid>' . $guid . "</guid>\n";
  $output .= '      <pubDate>' . $pubdate . "</pubDate>\n";
  $output .= '      <author>' . check_plain($name) . "</author>\n";
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
  $output .= "    <article>\n";
  $output .= "    <header>\n";
  $output .= "      <h1>" . check_plain($title) . "</h1>\n";
  $output .= "      <time class='op-published' datetime='" . $pubdate . "'>" . $op_pub . "</time>\n";
  $output .= "      <time class='op-modified' datetime='" . $modified . "'>" . $op_modified . "</time>\n";
//  $output .= "      <figure>" . check_plain($name) . "</figure>\n";
  $output .= "      <figure>\n"; // . check_plain($name) . "</address>\n";
  $output .= "      <img src='" . $img_path . "' />\n";
  $output .= "      </figure>\n\n";
  
  $output .= "    </header>\n\n";
  $output .= "    <div property='content:encoded'>". $node_body . "</div>\n";
  $output .= "    </article>\n\n";
  $output .= "    </body>\n\n";
  $output .= "    </head>\n\n";
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