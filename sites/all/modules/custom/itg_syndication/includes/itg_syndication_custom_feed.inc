<?php

/**
 * Function for validating the feed types
 * @param string $feed_type
 * @param string $body
 */
//define(DEFAULT_URL, "http://");

function isValidFeed($feed_type, $body) {
  $return = FALSE;
  switch ($feed_type) {
    case 'xml':
    case 'rss':
    case 'mrss':
      if (isValidXml($body)) {
        $return = TRUE;
      }
      break;
  }
  return $return;
}

/**
 * Function to generate feeds
 * @param array $data
 */
function generate_custom_pattern_feed($data) {
  $error = array();
  $nids = isset($data['syndication']) ? unserialize($data['syndication']) : array();
  $client = isset($data['client_title']) ? $data['client_title'] : "";
  $content_type = isset($data['web_property']) ? $data['web_property'] : "";

  // As known magazine is story content.
  if ($content_type == 'magazine') {
    $content_type = 'story';
  }
  $feed_type = isset($data['feed_type']) ? $data['feed_type'] : "";
  if (count($data) && (!empty($nids) && !empty($client) && !empty($content_type))) {
    /* get pattern of specific client for specific content_type */
    $pattern = get_client_feed_pattern($client, $content_type, $feed_type);
    /* Create Directory if does not exists */
    $feed_dir = "public://$feed_type/$client/$content_type";
    $feed_dir = str_replace(" ", "-", $feed_dir); // code by shravan
    file_prepare_directory($feed_dir, FILE_CREATE_DIRECTORY);
    $today = date('Y-M-d-h-m-s');
    /* Iterate for nodes */
    if (!empty($pattern['field_syndication_xml_formate_xml'])) {
      $feed = feed_starting_tags($feed_type);
      foreach ($nids as $nid) {
        $feed .= get_custom_feeds_files($nid, $pattern['field_syndication_xml_formate_xml'], $feed_type);
      }
      if ($feed_type == 'rss' || $feed_type == 'mrss') {
        $feed = get_full_feed_after_replace_items_tags_wtih_dollers($pattern['field_syndication_xml_formate_xml'], $feed);
      }
      $filename = sydication_pattren_file_name("$client - $today", $feed_type);
      $feed .= feed_ending_tags($feed_type);
      return sydication_feed_file_path($feed, $feed_dir, $filename);
    }
    else {
      $feed = feed_starting_tags($feed_type);
      $default_pattern = get_default_feed_pattern($feed_type, $content_type);
      foreach ($nids as $nid) {
        $feed .= get_custom_feeds_files($nid, $default_pattern, $feed_type);
      }
      if ($feed_type == 'rss' || $feed_type == 'mrss') {
        $feed = get_full_feed_after_replace_items_tags_wtih_dollers($default_pattern, $feed);
      }
      $filename = sydication_pattren_file_name("$client - $today", $feed_type);
      $feed .= feed_ending_tags($feed_type);
      return sydication_feed_file_path($feed, $feed_dir, $filename);
    }
  }
}

function get_full_feed_after_replace_items_tags_wtih_dollers($text, $feed) {
  preg_match_all('/<item>(.*?)<\/item>/s', $text, $tag_inside_item);
  // Item inside text got here
  $tags_inside_item_tag = $tag_inside_item[1][0];
  $only_item_text = '<item>' . $tags_inside_item_tag . '</item>';
  // Logic goes here
  // In this logic item tags are replaced by $$$.
  // After getting proper data of variables then $$$ will be replace by feed items.
  $position_of_items = str_replace($only_item_text, "$$$", $text);
  // Now i got item feed structure , then now replcae $$$ with item feed
  return str_replace("$$$", $feed, $position_of_items);
}

/**
 * Add tags at start of pattren
 * 
 * @param string $feed_type
 * @return string
 */
function feed_starting_tags($feed_type) {
  $tags = "";
  switch ($feed_type) {
    case 'xml':
      $tags = "<root>";
      break;
  }
  return $tags;
}

/**
 * Add tags end ending of pattren
 * 
 * @param string $feed_type
 * @return string
 */
function feed_ending_tags($feed_type) {
  $tags = "";
  switch ($feed_type) {
    case 'xml':
      $tags = "</root>";
      break;
  }
  return $tags;
}

function sydication_pattren_file_name($name, $extention) {
  if ($extention == 'xml' || $extention == 'rss' || $extention == 'mrss') {
    $extention = 'xml';
  }
  $filename = $name . '.' . $extention;
  $filename = str_replace(" ", "-", $filename); // code by shravan
  return $filename;
}

function sydication_feed_file_path($feed, $feed_dir, $filename) {
  $file = file_save_data($feed, "$feed_dir/" . $filename);
  //$file_server_path = getcwd() . '/' . str_replace('public:/', variable_get('file_public_path', 'sites/default/files'), $file->uri);
  $path = file_create_url($feed_dir);
  $file_path['file_path'] = $path . '/' . $filename;
  $file_path['file_name'] = $filename;
  $file_path['real_path'] = $feed_dir . "/" . $filename;
  //$uri = 'public://';
  return $file_path;
}

/**
 * This gives latest pattern w.r.t client & cotent type 
 * @param string $client
 * @param string $content_type
 * @param string $feed_type
 * @param string $pattern
 */
function get_client_feed_pattern($client, $content_type, $feed_type) {
  $pattern = "";
  if (isset($client) && isset($content_type) && isset($feed_type)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_syndication_xml_formate', 'fdb', 'fdb.entity_id=n.nid');
    $query->leftJoin('field_data_field_syndication_feed_content', 'sfc', 'sfc.entity_id=n.nid');
    $query->leftJoin('field_data_field_syndication_feed_clients', 'fsfc', 'fsfc.entity_id=n.nid');
    $query->leftJoin('field_data_field_syndication_feed_type', 'fsft', 'fsft.entity_id=n.nid');
    $query->fields('fdb', array('field_syndication_xml_formate_xml'));
    $query->condition('fsfc.field_syndication_feed_clients_value', $client);
    $query->condition('sfc.field_syndication_feed_content_value', $content_type);
    $query->condition('fsft.field_syndication_feed_type_value', $feed_type);
    $query->condition('n.status', '1');
    $query->orderBy('created', 'DESC');
    $pattern = $query->execute()->fetchAssoc();
  }
  return $pattern;
}

/**
 * Function for returing the feed file text
 * @param int $nid
 * @param string $pattren
 */
function get_custom_feeds_files($nid = NULL, $text = NULL, $feed_type = NULL) {
  $data_array = array();
  $feed_data = '';
  // extract fields name from text string
  $var_array = get_vars_from_feed_pattern($text, $feed_type);
  if (!empty($nid) && !empty($text)) {
    $node = node_load($nid);
    $isValidXml = isValidXml($text);
    if ($isValidXml) {
      // validate fields w.r.t content type
      $content_type = $node->type;
      foreach ($var_array[1] as $field_name) {
        if (!isValidField($field_name, $content_type)) {
          $message[] = $field_name . " is not a valid field in " . $content_type;
          drupal_set_message($field_name . " is not a valid field in for node " . $nid . $content_type, "error");
        }
      }
      // Remove other then item tags
      if ($feed_type == 'rss' || $feed_type == 'mrss') {
        preg_match_all('/<item>(.*?)<\/item>/s', $text, $tag_inside_item);

        // Item inside text got here
        $tags_inside_item_tag = $tag_inside_item[1][0];

        $only_item_text = '<item>' . $tags_inside_item_tag . '</item>';

        // Logic goes here
        // In this logic item tags are replaced by $$$.
        // After getting proper data of variables then $$$ will be replace by feed items.
        $position_of_items = str_replace($only_item_text, "$$$", $text);
        return get_generated_feed($message, $var_array, $node, $data_array, $only_item_text, $feed_type);
      }
      else if ($feed_type == 'xml') {
        // extract fields name from text string
        $var_array = get_vars_from_feed_pattern($text, $feed_type);
        // validate fields w.r.t content type
        $content_type = $node->type;
        foreach ($var_array[1] as $field_name) {
          if (!isValidField($field_name, $content_type)) {
            $message[] = $field_name . " is not a valid field in " . $content_type;
            drupal_set_message($field_name . " is not a valid field in for node " . $nid . $content_type, "error");
          }
        }
        //process if there is no error message
        if (empty($message)) {
          $iteration = count($var_array[0]);
          $new_text = '';
          for ($i = 0; $i < $iteration; $i++) {
            $return_value_for_sydiation = '';
            //Fix for sydication images repeated value.
            if ($var_array[1][$i] == 'field_gallery_image') {
              $field_gallery_image = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
              $return_value_for_sydiation[0] = implode(',', $field_gallery_image['field_gallery_image']);
            }
            elseif ($var_array[1][$i] == 'field_video_upload') {
              $field_gallery_image = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
              $return_value_for_sydiation[0] = implode(',', $field_gallery_image['field_video_upload']);
            }
            // Handel case for syndication images.
            else {
              if ($node->type == 'story' || $node->type == 'photogallery' || $node->type == 'videogallery') {
                $return_value_for_sydiation[0] = itg_syndication_get_syndication_image($node, $var_array[1][$i]);
              }
              else {
                $return_value_for_sydiation = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
              }
            }
            $data_array[] = $return_value_for_sydiation;
          }
          if (count($var_array[0])) {
            foreach ($var_array[0] as $key => $pattren) {
              $replacement = is_array($data_array[$key]) ? implode(", ", $data_array[$key]) : "";
              $new_text = str_replace($pattren, $replacement, $text);
              $text = $new_text;
            }
          }
          return $new_text;
        }
        else {
          drupal_set_message(t("not a valid field"));
        }
      }
    }
    else {
      drupal_set_message(t("Not a valid formet"));
    }
  }
  else {
    drupal_set_message(t("Either node ids not found or pattrens not found"));
  }
}

/**
 * Function returns value of syndication image.
 * @param array $node
 * @param string $field_name
 * @return string
 */
function itg_syndication_get_syndication_image($node, $field_name) {
  $return_value_for_sydiation = "";
  switch ($field_name) {
    case 'field_story_extra_large_image':
    case 'field_story_large_image':
    case 'field_story_medium_image':
    case 'field_story_small_image':
    case 'field_story_extra_small_image':
      // Get here image syndication value.
      $fid = $node->{$field_name}['und'][0]['fid'];
      $flag = itg_syndication_image_info_syndicate_flag($fid);
      if ($flag) {
        $file_url = file_create_url($node->{$field_name}['und'][0]['uri']);
        $return_value_for_sydiation = $file_url;
      }
      else {
        $return_value_for_sydiation = "";
      }
      break;

    default:
      $return_value_for_sydiation = get_required_data_field_get_items('node', $node, $field_name)[0];
      break;
  }
  return $return_value_for_sydiation;
}

/**
 * Function to get wether fid is valid for syndication or not.
 * @param int $fid
 * @return int
 */
function itg_syndication_image_info_syndicate_flag($fid) {
  $row_count = 0;
  if ($fid) {
    $row_count = db_select('image_info', 'ii')
            ->fields('ii', array("fid"))
            ->condition('ii.fid', $fid)
            ->condition('ii.image_syndicate', 1)
            ->execute()->rowCount();
  }
  return $row_count;
}

/**
 * 
 * Function analyse the var_array.
 * This funtion replace vriable with thiers value.
 * 
 * @param array $message
 * @param array $var_array
 *   var_array[0] has variables including i.e. {{{Variable}}}
 *   var_array[1] has only variables name i.e. Variable
 * @param object $node
 * @param array $data_array
 * @param string $text
 * @return string
 */
function get_generated_feed($message, $var_array, $node, $data_array, $text) {
  //process if there is no error message
  if (empty($message)) {
    $iteration = count($var_array[0]);
    for ($i = 0; $i < $iteration; $i++) {
      //$data_array[] = get_node_field_values($node, $var_array[1][$i]);
      $return_value_for_sydiation = '';
      //Fix for sydication images repeated value.
      if ($var_array[1][$i] == 'field_gallery_image') {
        $field_gallery_image = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
        //<media:thumbnail url="image url"/>
        //$return_value_for_sydiation[0] = implode(',', $field_gallery_image['field_gallery_image']);
        // handle case for creting multiple media tag. if there is multiple images
        $tags_start = "";
        $count_synd = count($field_gallery_image['field_gallery_image']) - 1;
        // Create multiple media tag if images count are more then 1
        // In case of only 1 , its working fine.
        // condition for counting images in file_gallery_image
        if (count($field_gallery_image['field_gallery_image']) > 1) {
          foreach ($field_gallery_image['field_gallery_image'] as $tag_key => $synd_images) {
            if ($tag_key == 0) {
              $tags_start .= $synd_images . '"/>';
            }
            elseif ($tag_key < $count_synd) {
              $tags_start .= '<media:thumbnail url="' . $synd_images . '"/>';
            }
            elseif ($tag_key == $count_synd) {
              $tags_start .= '<media:thumbnail url="' . $synd_images;
            }
          }
          $return_value_for_sydiation[0] = $tags_start;
        }
      }
      elseif ($var_array[1][$i] == 'field_video_upload') {
        $field_video_upload = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
        //<media:thumbnail url="image url"/>
        //$return_value_for_sydiation[0] = implode(',', $field_gallery_image['field_gallery_image']);
        // handle case for creting multiple media tag. if there is multiple images
        $tags_start = "";
        $count_synd = count($field_video_upload['field_video_upload']) - 1;
        // Create multiple media tag if images count are more then 1
        // In case of only 1 , its working fine.
        // condition for counting images in file_gallery_image
        if (count($field_video_upload['field_video_upload']) > 1) {
          foreach ($field_video_upload['field_video_upload'] as $tag_key => $video_swf_url) {
            if ($tag_key == 0) {
              $tags_start .= $video_swf_url . '"/>';
            }
            elseif ($tag_key < $count_synd) {
              $tags_start .= '<media:content url="' . $video_swf_url . '"/>';
            }
            elseif ($tag_key == $count_synd) {
              $tags_start .= '<media:content url="' . $video_swf_url;
            }
          }
          $return_value_for_sydiation[0] = $tags_start;
        }
      }
      else {
        if ($node->type == 'story' || $node->type == 'photogallery' || $node->type == 'videogallery') {
          $return_value_for_sydiation[0] = itg_syndication_get_syndication_image($node, $var_array[1][$i]);
        }
        else {
          $return_value_for_sydiation = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
        }
      }
      $data_array[] = $return_value_for_sydiation;
    }
    if (count($var_array[0])) {
      foreach ($var_array[0] as $key => $pattren) {
        $text = replace_variables_with_values($data_array, $key, $text, $pattren);
      }
      return $text;
    }
  }
}

/**
 * Function checks weahter its a field or predefine variables then returns the appropriate values
 *  
 * @param object $node
 * @param string $variable
 * @return array
 */
function get_node_field_values($node, $variable) {
  $predefine_variables = pre_define_variables();
  if (in_array($variable, $predefine_variables)) {
    $data_array[] = get_predefine_variables_value($node, $variable);
  }
  else {
    $data_array = get_required_data_field_get_items('node', $node, $variable);
  }
  return $data_array;
}

/**
 * Function which returns values for predefine variables
 * 
 * @global string $base_url
 * @param object $node
 * @param string $variable
 * @return string
 */
function get_predefine_variables_value($node, $variable) {
  global $base_url;
  $value = 'Not Found';
  switch ($variable) {
    case 'node_published_date':
      $value = date('r', $node->created);
      break;
    case 'node_author':
      $user_profile_data = user_load($node->uid);
      $value = $user_profile_data->mail . '(' . $user_profile_data->name . ')';
      break;
    case 'node_permalink':
      $node_alise_url = $base_url . '/' . drupal_get_path_alias("node/$node->nid");
      $value = $node_alise_url;
      break;
    case 'node_title':
      $value = $node->title;
      break;
  }
  return $value;
}

// Some predefine varliabes
function pre_define_variables() {
  return array(
    'node_published_date',
    'node_author',
    'node_permalink',
    'node_title'
  );
}

// Function is used to replace the values on appropriate array key
function replace_variables_with_values($data_array, $key, $text, $pattren) {
  $replacement = is_array($data_array[$key]) ? implode(", ", $data_array[$key]) : "";
  $new_text = str_replace($pattren, $replacement, $text);
  return $new_text;
}

/**
 * Funtion provides field list w.r.t. content type
 * @param string $content_type
 * @return array $field_info which has all the fields name on perticular file type
 */
function fieldsArray($content_type) {
  $field_info = array();
  $content_type_fields = field_info_instances('node', $content_type);
  foreach ($content_type_fields as $field) {
    $field_info[] = $field['field_name'];
  }

  foreach (pre_define_variables() as $variables) {
    $field_info[] = $variables;
  }
  return $field_info;
}

/**
 * Generate variables from pattern
 * @param string $text
 * @return array $matches
 */
function get_vars_from_feed_pattern($text, $feed_type) {
  $matches = array();

  if (isset($text)) {
    preg_match_all('/{{{(.*?)}}}/', $text, $matches);
  }
  return $matches;
}

/**
 * Check for field existance w.r.t content type
 * @param string $fieldName
 * @param boolen $flag
 */
function isValidField($field_name, $content_type) {
  $flag = FALSE;
  if (isset($field_name) && isset($content_type)) {
    if (in_array($field_name, fieldsArray($content_type))) {
      $flag = TRUE;
    }
  }
  return $flag;
}

/**
 * Function is uses fot validating the xml standrad
 * @param string $xml
 * @return boolen $errors
 */
function isValidXml($xml) {
  libxml_use_internal_errors(true);
  $doc = new DOMDocument('1.0', 'utf-8');
  $doc->loadXML($xml);
  $errors = libxml_get_errors();
  return empty($errors);
}

/**
 * Function gives values w.r.t field name & entity type
 * @param string $entity_type
 * @param obj $entity
 * @param string $field_name
 * @return array $required_value
 */
function get_required_data_field_get_items($entity_type, $entity, $field_name) {
  $field_item = field_get_items($entity_type, $entity, $field_name);
  if (is_array($field_item) && count($field_item)) {
    foreach ($field_item as $delta => $values) {
      $keys = array_keys($values);
      $key_delta = $keys[0];
      switch ($key_delta) {
        case 'tid':
          $tid_value = taxonomy_term_load($values['tid']);
          $required_value[] = $tid_value->name;
          break;
        case 'fid':
          $fid_value = $values['fid'];
          $file_load = file_load($fid_value);
          $file_url = file_create_url($file_load->uri);
          $required_value[] = (strlen($file_url) > 8) ? $file_url : 'http://';
          break;
        case 'uid':
          $uid_values = entity_load('user', $values['uid']);
          $required_value = $uid_values->name;
          break;
        case 'value':
          /* Its very importent to convert text into xml standard so using htmlspecialchars with ENT_XML1 */
          if ($field_name == 'field_gallery_image') {
            $temp_requred_value = array();
            foreach ($entity->field_gallery_image['und'] as $key => $fid) {
              /* Loop Only once */
              $value = $entity->field_gallery_image['und'][$key]['value'];
              $field_collection_item = entity_load('field_collection_item', array($value));
              // Only Synicated images ar required
              if ($field_collection_item[$value]->field_image_syndication['und'][0]['value'] == 'yes') {
                $field_collection_item_uri = $field_collection_item[$value]->field_images[LANGUAGE_NONE][0]['uri'];
                $temp_requred_value[] = file_create_url($field_collection_item_uri);
              }
            }
            $required_value['field_gallery_image'] = $temp_requred_value;
          }
          // Handel case to videogallery.
          elseif ($field_name == 'field_video_upload') {
            // prevent for dublicate.
            $temp_requred_value_1 = array();
            foreach ($entity->field_video_upload['und'] as $key => $vid) {
              /* Loop Only once */
              $value = $entity->field_video_upload['und'][$key]['value'];
              $field_collection_item = entity_load('field_collection_item', array($value));
              if (!empty($field_collection_item[$value]->field_videogallery_video_upload[LANGUAGE_NONE][0]['fid'])) {
                // Only Synicated images ar required
                $field_collection_item_fid = $field_collection_item[$value]->field_videogallery_video_upload[LANGUAGE_NONE][0]['fid'];
                $daily_motion_video_id = db_select('dailymotion_response_details', 'drd')
                        ->fields('drd', array('video_id'))
                        ->condition('drd.fid', $field_collection_item_fid)
                        ->execute()->fetchCol();
                //Create dailmition video url.
                $daily_motion_video_url = "http://www.dailymotion.com/swf/video/$daily_motion_video_id[0]";
                $temp_requred_value_1[] = $daily_motion_video_url;
              }
            }
            $required_value['field_video_upload'] = $temp_requred_value_1;
          }
          elseif ($field_name == 'body') {
            // Function to remove image have data-syndication='no' image.
            $body_field_value = remove_img_tags($field_item[0]['value']);
            if (function_exists('remove_extra_tag_in_body')) {
              $required_value[] = "<![CDATA[ " . remove_extra_tag_in_body(htmlspecialchars($body_field_value, ENT_XML1, 'UTF-8')) . " ]]>";
            }
            else {
              $required_value[] = "<![CDATA[ " . htmlspecialchars($body_field_value, ENT_XML1, 'UTF-8') . " ]]>";
            }
          }
          else {
            $required_value[] = "<![CDATA[ " . htmlspecialchars($field_item[0]['value'], ENT_XML1, 'UTF-8') . " ]]>";
          }
          break;
      }
    }
  }
  return $required_value;
}

/**
 * Hook_theme
 * @return array
 */
function itg_syndication_theme() {
  return array(
    'syndication_feed_variables' => array(
      'template' => '/templates/sydication_feed_variables',
    ),
    'syndication_feed_from_pattern_node_form' => array(
      'render element' => 'form',
      'template' => 'templates/syndication_feed_from_pattern_node_form',
    ),
  );
}

/**
 * Function used for getting default feed pattern 
 * @param string $feed_type
 * @param string $content_type
 * @return string in feed format
 */
function get_default_feed_pattern($feed_type, $content_type) {
  $feed_assoc_array = "";
  $default_pattern = "";
  $labelsArray = get_lebels_of_content_type_fields($content_type);
  switch ($feed_type) {
    case "xml":
      foreach ($labelsArray as $field_name => $label) {
        $label_trim = str_replace(' ', '', $label);
        $label_small = strtolower($label_trim);
        /* Special charcter is replaced for tags */
        $feed_assoc_array[preg_replace('/[^a-zA-Z0-9_.]/', '', $label_small)] = "{{{{$field_name}}}}";
      }
      $default_pattern = assocArrayToXML($content_type, $feed_assoc_array);
      break;
    case "rss":
    case "mrss":
      $default_pattern_file_path = drupal_get_path('module', 'itg_syndication') . "/default_feed_pattern/$content_type/" . $feed_type . "_default_pattern.xml";
      $default_pattern = file_get_contents($default_pattern_file_path);
      break;
  }
  return $default_pattern;
}

/**
 * Function to generate arry to xml
 * @param string $root_element_name
 * @param array $ar
 * @return xml $customXML
 */
function assocArrayToXML($root_element_name, $xml_array) {
  $xml = new SimpleXMLElement("<{$root_element_name}></{$root_element_name}>");
  $function = create_function('$function,$xml_child,$xml_array', ' 
            foreach($xml_array as $tags=>$element) { 
                if(is_array($element)) { 
                    $child=$xml_child->addChild($tags); 
                    $function($function,$child,$element); 
                } else { 
                    $xml_child->addChild($tags,$element); 
                } 
            }');
  $function($function, $xml, $xml_array);
  $real_xml = $xml->asXML();
  $customXML = substr($real_xml, strpos($real_xml, '?' . '>') + 2);
  return $customXML;
}

/**
 * Function got getting lebels of perticular content type into tag format
 * @param string $content_type
 * @return string $tags
 */
function get_lebels_of_content_type_fields($content_type) {
  $fieldsArray = array();
  $tags = array();
  if (isset($content_type)) {
    $fieldsArray = fieldsArray($content_type);
    foreach ($fieldsArray as $key => $field_name) {
      $tags[$field_name] = get_lebel_of_field('node', $content_type, $field_name);
    }
  }
  return $tags;
}

/**
 * Function for getting lebel for field
 * @param string $entity_type
 * @param string $bundle_name
 * @param string $field_name
 * @return string $label
 */
function get_lebel_of_field($entity_type = 'node', $bundle_name, $field_name) {
  if (isset($entity_type) && isset($bundle_name) && isset($field_name)) {
    $info = field_info_instance($entity_type, $field_name, $bundle_name);
    $label = $info['label'];
    return $label;
  }
  else {
    return;
  }
}

/**
 * Hook_FORM_ID_from_alter
 * @param array $form
 * @param array $form_state
 * @param string $form_id
 */
function itg_syndication_form_syndication_feed_from_pattern_node_form_alter(&$form, &$form_state, $form_id) {
  $data = array();
  $predefine_variables_markup = "";
  drupal_add_js('jQuery(document).ready(function(){
        jQuery("select#edit-field-syndication-feed-content-und").on(\'change\',function(){
           var selected =   jQuery(this).val();
           jQuery(".variables-tabs div").css("display","none");
           jQuery(".variables-tabs div#tab-"+selected).css("display","block");
        });
        //jQuery(".vertical-tabs").css("display","none");
        jQuery("#edit-body-und-0-value").css({"min-width":"900px","height":"400px"});
    });', 'inline');

  drupal_add_js(drupal_get_path('module', 'itg_syndication') . '/js/itg_syndication_custom_feed.js', 'file');
  /* JS library  added to beutify xml pattern */
  drupal_add_js(drupal_get_path('module', 'itg_syndication') . '/js/jquery.format.js', 'file');
  /* check for default value */
  $client = $form['field_syndication_feed_clients'][LANGUAGE_NONE]['#entity']->field_syndication_feed_clients[LANGUAGE_NONE][0]['value'];
  if (isset($client)) {
    $form['field_syndication_feed_clients'][LANGUAGE_NONE]['#default_value'] = $client;
  }
  /* Client list */
  $form['field_syndication_feed_clients'][LANGUAGE_NONE]['#options'] = itg_syndication_get_client("yes");
  $form['field_syndication_feed_clients']['#validated'] = TRUE;
  if (!empty($form['field_syndication_feed_content']['und']['#options']['photogallery'])) {
    $form['field_syndication_feed_content']['und']['#options']['photogallery'] = t('Photogallery');
  }
  /* Check if nid exists then set predefine variables */
  if (isset($form_state['build_info']['args'][0]->nid)) {
    $content_type = $form_state['build_info']['args'][0]->field_syndication_feed_content['und'][0]['value'];
    $predefine_variables_markup = theme('syndication_feed_variables', array("data" => fieldsArray($content_type), "content_type" => $content_type));
  }
  $form['pre_define_vars'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="pre_define_vars_replace_wrapper">',
    '#suffix' => '</div>',
    '#markup' => $predefine_variables_markup,
  );
  $form['actions']['cancle'] = array(
    '#markup' => l(t('Cancel'), 'syndication-feed-pattern-listing', array(
      'attributes' => array(
        'class' => 'button'
      )
    )),
    '#weight' => 21,
    '#value' => t('Cancel')
  );

  $form['field_syndication_feed_type'][LANGUAGE_NONE]['#ajax'] = array(
    'callback' => 'get_default_feed_pattern_callback',
    'wrapper' => 'syndication_form', //body-wrapper',
  );

  $form['field_syndication_feed_content'][LANGUAGE_NONE]['#ajax'] = array(
    'callback' => '_pre_define_vars_callback',
    'method' => 'replace', // the data would replace the field
    'effect' => 'fade',
    'event' => 'change', // On change of the selection this action would take place
  );
  // Add a new submit function for redirecting after submit
  $form['actions']['submit']['#submit'][] = 'node_save_redirect_submit';
  // Add extra validation
  $form['#validate'][] = 'itg_syndication_form_syndication_feed_from_pattern_node_form_validate';
  $form['#prefix'] = "<div id='syndication_form'>";
  $form['#suffix'] = "</div>";
  unset($form['actions']['preview']);
}

/**
 * This function checkes weather the same pattern exist or not
 * @param array $form
 * @param array $form_state
 */
function itg_syndication_form_syndication_feed_from_pattern_node_form_validate(&$form, &$form_state) {
  $arg = arg();
  $invalid_vars = array();
  $node = (object) $form_state['values'];
  $content_type = $node->field_syndication_feed_content['und'][0]['value'];
  $feed_type = $node->field_syndication_feed_type['und'][0]['value'];
  $client_title = $node->field_syndication_feed_clients['und'][0]['value'];
  $xml_pattern = $node->field_syndication_xml_formate['und'][0]['xml'];
  /* Check only if new node is bening craeted */
  if (isset($arg[0]) && isset($arg[1]) && $arg[0] == 'node' && $arg[1] == 'add') {
    $query = db_select('field_data_field_syndication_feed_clients', 'client');
    $query->leftJoin('field_data_field_syndication_feed_content', 'content_type', 'content_type.entity_id=client.entity_id');
    $query->leftJoin('field_data_field_syndication_feed_type', 'feed_type', 'feed_type.entity_id=client.entity_id');
    $query->condition('client.field_syndication_feed_clients_value', $client_title);
    $query->condition('content_type.field_syndication_feed_content_value', $content_type);
    $query->condition('feed_type.field_syndication_feed_type_value', $feed_type);
    $query->fields('client', array('entity_id'));
    $result = $query->execute()->fetchAll();

    if (count($result) >= 1) {
      form_set_error("itg_syndication_form_syndication_feed_from_pattern_node_form", "Pattern already exists for this client");
    }
    watchdog('debug', "Total " . count($result) . " results founds for combination");
  }

  // For retaing value of markup field.
  $form['pre_define_vars']['#markup'] = theme('syndication_feed_variables', array("data" => fieldsArray($content_type), "content_type" => $content_type));
  #check for all valid variables
  is_all_vars_valid($xml_pattern, $content_type);
}

/**
 * Function checks xml pattern .w.r.t content type for variables validation
 * @param type $xml_pattern
 * @param type $content_type
 */
function is_all_vars_valid($xml_pattern, $content_type) {
  drupal_add_js('jQuery(document).ready(function(){
            jQuery(".vertical-tabs").css("display","none");
        });', 'inline');
  // extract fields name from text string
  $var_array = get_vars_from_feed_pattern($xml_pattern);
  foreach ($var_array[1] as $field_name) {
    if (!isValidField($field_name, $content_type)) {
      $invalid_vars[] = $field_name;
      watchdog('syndication', "invalid variables found");
    }
  }
  if (!empty($invalid_vars)) {
    $invalid_vars_str = implode("<b>, </b>", $invalid_vars);
    form_set_error("itg_syndication_form_syndication_feed_from_pattern_node_form", "Invalid variables are $invalid_vars_str");
  }
  watchdog('syndication', "Variable validation pass");
}

/**
 * Function to used redirect the form after node save
 * @param array $form
 * @param array $form_state
 */
function node_save_redirect_submit($form, &$form_state) {
  $arg = arg();
  if (!isset($_GET['destination'])) {
    drupal_goto("syndication-feed-pattern-listing");
  }
}

/**
 * Callback function for displaying the variables 
 * @param array $form
 * @param array $form_state
 */
function _pre_define_vars_callback(&$form, &$form_state) {
  // current selected content type.
  $content_type = $form_state['values']['field_syndication_feed_content']['und'][0]['value'];
  // current feed type/
  $feed_type = $form_state['values']['field_syndication_feed_type']['und'][0]['value'];
  // change markup of variables as per content type foield is selected
  $form['pre_define_vars']['#markup'] = theme('syndication_feed_variables', array("data" => fieldsArray($content_type), "content_type" => $content_type));
  // Get feeds pattern as per feed type and content type.  
  $default_xml_pattern = get_default_feed_pattern($feed_type, $content_type);
  $form['pre_define_vars']['#markup'] = theme('syndication_feed_variables', array("data" => fieldsArray($content_type), "content_type" => $content_type));
  // Commands to replace both variables and value of pattern in field.
  $commands[] = ajax_command_invoke(NULL, "feed_pattern", array($default_xml_pattern));
  $commands[] = ajax_command_replace("#pre_define_vars_replace_wrapper", render($form['pre_define_vars']));
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
////  return $form;
//  return array(
//    '#type' => 'ajax',
//    '#commands' => array(
//      ajax_command_replace("#pre_define_vars_replace_wrapper", render($form['pre_define_vars'])),
//    )
//  );
}

/**
 * Function which is used to replaced dynamic body feed pattern
 * @param array $form
 * @param array $form_state
 * @return commands
 */
function get_default_feed_pattern_callback($form, &$form_state) {
  $feed_type = $form_state['values']['field_syndication_feed_type']['und'][0]['value'];
  $content_type = $form_state['values']['field_syndication_feed_content']['und'][0]['value'];
  if (!isset($content_type) && empty($content_type)) {
    $commands[] = ajax_command_replace('.poll-ans-error', '<span class="poll-ans-error error">Pleaes Select Content Type</span>');
    drupal_get_messages();
    return array('#type' => 'ajax', '#commands' => $commands);
  }
  else {
    $default_xml_pattern = get_default_feed_pattern($feed_type, $content_type);
    $content_type = $form_state['values']['field_syndication_feed_content']['und'][0]['value'];
    $form['pre_define_vars']['#markup'] = theme('syndication_feed_variables', array("data" => fieldsArray($content_type), "content_type" => $content_type));
    $commands[] = ajax_command_invoke(NULL, "feed_pattern", array($default_xml_pattern));
    return array(
      '#type' => 'ajax',
      '#commands' => $commands,
    );
  }
}
