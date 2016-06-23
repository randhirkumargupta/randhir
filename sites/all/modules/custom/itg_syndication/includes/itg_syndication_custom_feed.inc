<?php

/**
 * Function for validating the feed types
 * @param string $feed_type
 * @param string $body
 */
function isValidFeed($feed_type, $body) {
    $return = FALSE;
    switch ($feed_type) {
        case 'xml':
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
    $feed_type = isset($data['feed_type']) ? $data['feed_type'] : "";
    $xml        =   "<root>";
    if (count($data) && (!empty($nids) && !empty($client) && !empty($content_type))) {
        /* get pattern of specific client for specific content_type */
        $pattern = get_client_feed_pattern($client, $content_type, $feed_type);
        /* Create Directory if does not exists */
        $feed_dir = "public://$feed_type/$client/$content_type";
        file_prepare_directory($feed_dir, FILE_CREATE_DIRECTORY);
        $today = date('Y-M-d-h-m-s');
        /* Iterate for nodes */
        if (!empty($pattern['body_value'])) {
            foreach ($nids as $nid) {                
                $xml .= get_custom_feeds_files($nid, $pattern['body_value']);
                $filename = uniqid() . "-$content_type-date-$today.xml";
                watchdog("WATCHDOG_INFO", "XML $feed_dir/$filename (Y-M-d-h-m-s) is generated ");
            }
            $xml    .=  "</root>";
            $file   = file_save_data($xml, "$feed_dir/" . $filename);
            
            $file_path['file_path'] =  $feed_dir.'/' . $filename;
            $file_path['file_name'] =  $filename;
            
            return $file_path;
        } else {
            drupal_set_message(t('Pattern not found.'), 'error');
        }
    }
}

/**
 * This gives latest pattern w.r.t client & cotent type 
 * @param type $client
 * @param type $content_type
 * @param type $feed_type
 */
function get_client_feed_pattern($client, $content_type, $feed_type) {
    $pattern = "";
    if (isset($client) && isset($content_type) && isset($feed_type)) {
        $query = db_select('node', 'n');
        $query->leftJoin('field_data_body', 'fdb', 'fdb.entity_id=n.nid');
        $query->leftJoin('field_data_field_syndication_feed_content', 'sfc', 'sfc.entity_id=n.nid');
        $query->leftJoin('field_data_field_syndication_feed_clients', 'fsfc', 'fsfc.entity_id=n.nid');
        $query->leftJoin('field_data_field_syndication_feed_type', 'fsft', 'fsft.entity_id=n.nid');
        $query->fields('fdb', array('body_value'));
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
 * @param type $nid
 * @param type $pattren
 */
function get_custom_feeds_files($nid = NULL, $text = NULL) {
    $data_array = array();
    $feed_data = '';
    if (!empty($nid) && !empty($text)) {
        $node = node_load($nid);
        $isValidXml = isValidXml($text);
        if ($isValidXml) {
            // extract fields name from text string
            $var_array = get_vars_from_feed_pattern($text);
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
                    $data_array[] = get_required_data_field_get_items('node', $node, $var_array[1][$i]);
                }
                if (count($var_array[0])) {
                    foreach ($var_array[0] as $key => $pattren) {
                        $replacement = is_array($data_array[$key]) ? implode(", ", $data_array[$key]) : "";
                        $new_text = str_replace($pattren, $replacement, $text);
                        $text = $new_text;
                    }
                }
                return $new_text;
            } else {
                drupal_set_message("not a valid field");
            }
        } else {
            drupal_set_message("Not a valid formet");
        }
    } else {
        drupal_set_message("Either node ids not found or pattrens not found");
    }
}

/**
 * Funtion provides field list w.r.t. content type
 * @param string $content_type
 * @return array which has all the fields name on perticular file type
 */
function fieldsArray($content_type) {
    $field_info = array();
    $content_type_fields = field_info_instances('node', $content_type);
    foreach ($content_type_fields as $field) {
        $field_info[] = $field['field_name'];
    }
    return $field_info;
}

/**
 * Generate variables from pattern
 * @param string $text
 * @return array $matches
 */
function get_vars_from_feed_pattern($text) {
    $matches = array();
    if (isset($text)) {
        preg_match_all('/{{{(.*?)}}}/', $text, $matches);
    }
    return $matches;
}

/**
 * Check for field existance w.r.t content type
 * @param string $fieldName
 * @param blooen $flag
 */
function isValidField($field_name, $content_type) {
    $flag = false;
    if (isset($field_name) && isset($content_type)) {
        if (in_array($field_name, fieldsArray($content_type))) {
            $flag = true;
        }
    }
    return $flag;
}

/**
 * validate xml
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
 * @param type $entity_type
 * @param type $entity
 * @param type $field_name
 * @return type $required_value
 */
function get_required_data_field_get_items($entity_type, $entity, $field_name) {
    $required_value = '';
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
                    $required_value[] = file_create_url($file_load->uri);
                    break;
                case 'uid':
                    $uid_values = entity_load('user', $values['uid']);
                    $required_value = $uid_values->name;
                    break;
                case 'value':
                    $required_value[] = $field_item[0]['value'];
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
            'template' => 'templates/sydication_feed_variables',
        ),
    );
}

/**
 * 
 * @param type $feed_type
 * @param type $content_type
 * @return string
 */

function get_default_feed_pattern($feed_type,$content_type) {
    $feed_assoc_array   =   "";
    $labelsArray        =   get_lebels_of_content_type_fields($content_type);
    switch ($feed_type) {
        case "xml":
            foreach($labelsArray as $field_name=>$label) {
                $label_trim     =   str_replace(' ', '', $label);
                $label_small    =   strtolower($label_trim);
                /* Special charcter is replaced for tags*/
                $feed_assoc_array[preg_replace('/[^a-zA-Z0-9_.]/', '', $label_small)] =   "{{{{$field_name}}}}";
            }
            break;
    }
    return assocArrayToXML($content_type,$feed_assoc_array);
}

/**
 * Function to generate arry to xml
 * @param type $root_element_name
 * @param type $ar
 * @return type xml
 */
function assocArrayToXML($root_element_name,$ar) { 
    $xml = new SimpleXMLElement("<{$root_element_name}></{$root_element_name}>"); 
    $f = create_function('$f,$c,$a',' 
            foreach($a as $k=>$v) { 
                if(is_array($v)) { 
                    $ch=$c->addChild($k); 
                    $f($f,$ch,$v); 
                } else { 
                    $c->addChild($k,$v); 
                } 
            }'); 
    $f($f,$xml,$ar); 
    $real_xml   =       $xml->asXML(); 
    $customXML  =       substr($real_xml, strpos($real_xml, '?'.'>') + 2);
    return $customXML;
}

/**
 * 
 * @param type $content_type
 * @return type
 */
function get_lebels_of_content_type_fields($content_type) {
    $fieldsArray    =   array();
    $tags           =   array();
    if(isset($content_type)) {
        $fieldsArray  =  fieldsArray($content_type);
        foreach ($fieldsArray as $key => $field_name) {
             $tags[$field_name]    =   get_lebel_of_field('node',$content_type, $field_name);
        }
    }
    return $tags;
}

/**
 *
 * @param type $entity_type
 * @param type $bundle_name
 * @param type $field_name
 * @return type
 */
function get_lebel_of_field($entity_type='node',$bundle_name,$field_name) {
    if(isset($entity_type) && isset($bundle_name) && isset($field_name)) {
        $info   = field_info_instance($entity_type, $field_name, $bundle_name);
        $label  = $info['label'];
        return  $label;
    }else{
        return ;
    }
}


/**
 *  hook_form_FORM_ID_alter
 */
function itg_syndication_form_syndication_feed_from_pattern_node_form_alter(&$form, &$form_state, $form_id) {
    $data = array();
    drupal_add_js('jQuery(document).ready(function(){
        jQuery("select#edit-field-syndication-feed-content-und").on(\'change\',function(){
           var selected =   jQuery(this).val();
           jQuery(".variables-tabs div").css("display","none");
           jQuery(".variables-tabs div#tab-"+selected).css("display","block");
        });
    });', 'inline');
    drupal_add_js(drupal_get_path('module', 'itg_syndication') .'/js/itg_syndication_custom_feed.js', 'file');
    $content_types = array('story', 'cooking_tips', 'recipe', 'photogallery', 'food_news');
    if (isset($form_state['values'])) {
        $form_state['body']['#value'] = 'I HATE chickens';
      }
    /* Collecting all fields of $content_types in assocative array */
    foreach ($content_types as $CT) {
        $data[$CT] = fieldsArray($CT);
    }
    /* Client list */
    $form['field_syndication_feed_clients'][LANGUAGE_NONE]['#options'] = itg_syndication_get_client();
    $form['field_syndication_feed_clients']['#validated'] = TRUE;
    /* Extra field for displaying all the predefine variables */
    $form['variables'] = array(
        '#type' => 'markup',
        '#prefix' => '<strong>Pre-define variables</strong><div class="poll-main-wrap">',
        '#suffix' => '</div><span class="poll-ans-error"></span>',
        '#markup' => theme("syndication_feed_variables", array("data" => $data)),
    );
    
    $form['field_syndication_feed_type'][LANGUAGE_NONE]['#ajax']=array(
        'callback'  => 'get_default_feed_pattern_callback',
        'wrapper'   =>  'body-wrapper',
    );
}

/**
 * Function which is used to replaced dynamic body feed pattern
 * @param type $form
 * @param type $form_state
 * @return commands
 */
function get_default_feed_pattern_callback($form, &$form_state) {
    $feed_type      =   $form_state['values']['field_syndication_feed_type']['und'][0]['value'];
    $content_type   =   $form_state['values']['field_syndication_feed_content']['und'][0]['value'];
    
    if(!isset($content_type) && empty($content_type)) {
        $commands[] = ajax_command_replace('.poll-ans-error', '<span class="poll-ans-error error">Pleaes Select Content Type</span>');
        drupal_get_messages();
        return array('#type' => 'ajax', '#commands' => $commands);
    } else {
        $myCustomParameters =   get_default_feed_pattern($feed_type,$content_type);
        $commands[]         =   ajax_command_invoke(NULL, "feed_pattern", array($myCustomParameters) );
        return array(
                '#type' => 'ajax',
                '#commands' => $commands,
        );
    }

}