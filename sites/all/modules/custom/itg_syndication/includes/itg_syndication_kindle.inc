<?php

/**
 * @file
 * ITG Videogallery inc.
 */
module_load_include('php', 'itg_videogallery', 'includes/vendor/autoload');

use Aws\S3\S3Client;
use Aws\S3\Exception\S3Exception;
use Aws\Common\Credentials\Credentials;

define('KINDLE_WRAPPER', "public://kindle");

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form($form, &$form_state) {
    $options_first = magazine_options();
    $selected = isset($form_state['values']['magazine']) ? $form_state['values']['magazine'] : key($options_first);
    if(isset($_GET['magazine'])) {
        $selected = $_GET['magazine'];
    }

    $form['magazine'] = array(
        '#type' => 'select',
        '#title' => 'Magazine',
        '#options' => $options_first,
        '#default_value' => $selected,
        '#ajax' => array(
            'callback' => '_get_issues_callback',
            'wrapper' => 'dropdown-second-replace',
        ),
    );

    $issue_default = isset($form_state['values']['issues']) ? $form_state['values']['issues'] : '';
    if(isset($_GET['issue'])) {
        $issue_default = $_GET['issue'];
    }

    $form['issues'] = array(
        '#type' => 'select',
        '#title' => t('Issues'),
        '#prefix' => '<div id="dropdown-second-replace">',
        '#suffix' => '</div>',
        '#required' => TRUE,
        '#options' => _ajax_issue_options($selected),
        '#default_value' => $issue_default,
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit'),
    );

    $form['reset'] = array(
        '#type' => 'markup',
        '#markup' => l('cancle', 'itg-kindle-feed', array("attributes" => array("class" => array("button"))))
    );

    if(isset($_GET['issue']) && isset($_GET['magazine'])) {
        $form['generate_kindle_feed'] = array(
            '#type' => 'submit',
            '#value' => t('Generate Kindle Feed'),
            '#attributes' => array("style" => array("margin-left:10px"))
        );
    }
    return $form;
}

/**
 * Function is used to get option for magazine
 * 
 * @return array
 */
function magazine_options() {
    return itg_syndication_get_issue_list('magazine');
}

/**
 * {@inheritdocs}
 */
function _get_issues_callback($form, $form_state) {
    return $form['issues'];
}

/**
 * Function is used to get options for issues during ajaz call
 * @param string $key
 * @return array
 */
function _ajax_issue_options($key = '') {
    $options = _issues_options($key);
    if(isset($options[$key])) {
        return $options[$key];
    } else {
        return array();
    }
}

/**
 * Function which is used to get issues
 * 
 * @param string $magazine
 * @return array
 */
function _issues_options($magazine) {
    $issue_list = array();
    $issue_list[$magazine]['_none'] = '- None -';
    $itg_query = db_select('node', 'n');
    $itg_query->fields('n', array('title'));
    $itg_query->fields('sc', array('field_issue_magazine_target_id'));
    $itg_query->join('field_data_field_issue_magazine', 'sc', 'n.nid = sc.entity_id');
    $itg_query->condition('sc.field_issue_magazine_target_id', $magazine);
    $itg_query->condition('n.type', 'issue');
    //$itg_query->condition('n.status', 1);
    $itg_query->orderBy('n.created', 'DESC');
    $itg_query->range(0, 10);
    $itg_result = $itg_query->execute()->fetchAll();
    foreach($itg_result as $key => $data) {
        $issue_title = explode(" ", $data->title);
        $issue_list[$magazine][$data->title] = $issue_title[0];
    }
    return $issue_list;
}

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form_validate($form, &$form_state) {
    $issue = $form_state['values']['issues'];
    if($issue == '_none') {
        form_set_error('issue', t("Please select issue"));
    }
    if(isset($_GET['issue']) && empty($_GET['issue'])) {
        form_set_error('issue', t("Please select issue"));
    }

    if(isset($_GET['magazine']) && empty($_GET['magazine'])) {
        form_set_error('magazine', t("Please select magazine"));
    }
}

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form_submit($form, &$form_state) {
    if($form_state['values']['op'] == 'Submit') {
        $issue = $form_state['values']['issues'];
        $magazine = $form_state['values']['magazine'];
        drupal_goto('itg-kindle-feed', array('query' => array("issue" => $issue, "magazine" => $magazine)));
    } else {
        // create unique directory name
        $directory_name = uniqid() . "-" . time();
        $dir = KINDLE_WRAPPER . "/" . $directory_name;
        $dir_zip = KINDLE_WRAPPER . "/zip";
        file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
        file_prepare_directory($dir_zip, FILE_CREATE_DIRECTORY);
        $issue = $_GET['issue'];
        $magazine = $_GET['magazine'];
        if(!empty($issue) && !empty($magazine)) {
            $data_array = array();
            try {
                $query = db_select('node', 'n');
                $query->fields('n', array('nid'));
                $query->leftJoin('field_data_field_story_issue_date', 'mi', 'mi.entity_id=n.nid');
                $query->leftJoin('field_data_field_story_select_magazine', 'smi', 'smi.entity_id=n.nid');
                $query->condition("smi.field_story_select_magazine_target_id", $magazine);
                $query->condition("mi.field_story_issue_date_value", $issue);
                $query->condition("n.type", 'story');
                $result = $query->execute()->fetchAllAssoc('nid');
            } catch(Exception $ex) {
                drupal_set_message($ex->getMessage(), 'error');
            }
            $node_ids = array_keys($result);
            foreach($node_ids as $nid) {
                $data_array['sections'][] = kindle_get_sections_for_node($nid);
                $data_array['nids'][] = $nid;
            }
            $section_with_nids_array = _create_articles_section_files($data_array['sections'], $data_array['nids']);
            $sections_name_array = array_keys($section_with_nids_array);
            //Create cover file
            $cover_file = _create_cover_xml();
            //save civer file
            _kindle_save_unmanaged_file($cover_file, $directory_name);
            // Create cover page file.
            $cover_page_file = _create_cover_page_xml();
            // save cover page file.
            _kindle_save_unmanaged_file($cover_page_file, $directory_name);
            //Create manifiest file.
            $manifest_file = _create_manifest_file($sections_name_array, $section_with_nids_array);
            // save manifest file.
            _kindle_save_unmanaged_file($manifest_file, $directory_name);
            //create section file which are active.
            _create_section_file($section_with_nids_array, $directory_name);
            // Create zip in temp location.
            _create_tmp_zip("public://indiatoday/kindle/$directory_name");
        }
    }
}

/**
 *  main function for create zip
 * 
 * @param string $prefix
 */
function _create_tmp_zip($prefix) {
    $bucket = variable_get('aws_bucket');
    $aws_access_key = variable_get('aws_access_key');
    $aws_secret_key = variable_get('aws_secret_key');
    $aws_region = variable_get('aws_region');

    $s3 = S3Client::factory(array('key' => $aws_access_key, 'secret' => $aws_secret_key, 'signature' => 'v4', 'region' => $aws_region));
    try {
        $objects = $s3->getIterator('ListObjects', array(
            'Bucket' => $bucket,
            "Prefix" => $prefix
        ));
        //drupal_add_css("#widget-ajex-loader {display:block !important}" , "inline");
        // Prepare File
        $file = tempnam("download_" . time(), "zip");
        $zip = new ZipArchive();
        $zip->open($file, ZipArchive::OVERWRITE);
        foreach($objects as $object) {
            $xml_dot_gz_files = $s3->getObjectUrl($bucket, $object['Key']);
            $contents = file_get_contents($xml_dot_gz_files);
            $zip->addFromString(basename($xml_dot_gz_files), $contents);
        }
        $zip->close();
        header('Content-Type: application/zip');
        header('Content-Length: ' . filesize($file));
        header('Content-Disposition: attachment; filename="download.zip"');
        readfile($file);
        unlink($file);
        //drupal_add_css("#widget-ajex-loader {display:none}" , "inline");
        exit;
    } catch(S3Exception $e) {
        echo $e->getMessage() . "\n";
    }
}

/**
 * Function is responsible for save the unmanaged file.
 * 
 * @param array $data_array
 * @param string $directory_name
 */
function _kindle_save_unmanaged_file($data_array = array(), $directory_name) {
    if(isset($data_array['file_name']) && isset($data_array['xml'])) {
        $data_file_name = $data_array['file_name'];
        $data_file_destination = KINDLE_WRAPPER . "/$directory_name/$data_file_name";
        $data_file_xml = $data_array['xml'];
        file_unmanaged_save_data($data_file_xml, $data_file_destination, FILE_EXISTS_REPLACE);
        //drupal_set_message(t("File Location @loc", array("@loc" => file_create_url($data_file_destination))));
    }
}

/**
 * Main function which is used to create section xml file.
 * 
 * @param array $section_with_nids
 */
function _create_section_file($section_with_nids = array(), $directory_name) {
    if(!empty($section_with_nids)) {
        $fresh_sections_with_nids = _get_sections_with_corrected_nids($section_with_nids);
        // itg_watchdog("sections_with_nids", array('old_sectinos' => $section_with_nids, "fresh" => $fresh_sections_with_nids));
        foreach($fresh_sections_with_nids as $section_name => $node_array) {
            // Section file started
            $section_file_name = "Section_" . _get_correct_file_name($section_name) . ".xml";
            //itg_watchdog("section_node_count", array($section_file_name, $node_array));
            $xml = "<?xml version='1.0' encoding='utf-8'?>";
            $xml .= "<rss version='2.0'>";
            $xml .= "<channel>";
            $xml .= "<title>" . $section_name . "</title>";
            foreach($node_array as $nid) {
                $node_load_data = node_load($nid);
                // Skip future date and unpublised story.
                if(!is_expried_story($node_load_data) && !is_future_story($node_load_data)) {
                    $artical_file_name = "Article_" . _get_correct_file_name($section_name) . $nid . ".xml";
                    $xml .="<item><link>" . $artical_file_name . "</link></item>";
                    $node_file = _create_node_file($artical_file_name, $nid, $section_name);
                    _kindle_save_unmanaged_file($node_file, $directory_name);
                }
            }
            $xml .= "</channel></rss>";
            // Save logic for section files files.
            $destination = KINDLE_WRAPPER . "/$directory_name/$section_file_name";
            file_unmanaged_save_data(_formet_xml($xml), $destination, FILE_EXISTS_REPLACE);
            //drupal_set_message(t("File Location @loc", array("@loc" => file_create_url($destination))));
            // Section file ended
        }
    }
}

/**
 *  This function returns sections in which at least 1 story which are not future story or expried story
 * 
 * @param array $section_with_nids
 * 
 * @return type
 */
function _get_sections_with_corrected_nids($section_with_nids) {
    $fresh_section_array = array();
    foreach($section_with_nids as $section_name => $node_array) {
        $node_under_section = array();
        foreach($node_array as $nid) {
            $node_load_data = node_load($nid);
            // Validate for future story and expried story.
            if(!is_expried_story($node_load_data) && !is_future_story($node_load_data)) {
                $node_under_section[] = $nid;
            }
        }
        if(count($node_under_section)) {
            $fresh_section_array[$section_name] = $node_under_section;
        }
    }
    return $fresh_section_array;
}

/**
 * Story is expried or not.
 *  
 * @param array $node
 * @return boolean
 */
function is_expried_story($node) {
    $flag = FALSE;
    $expiry_time = strtotime($node->field_story_expiry_date['und'][0]['value']);
    $checked = $node->field_story_expires['und'][0]['value'];
    if(($expiry_time < time() && (!empty($checked) && strtolower($checked) == 'yes')) || $node->status == 0) {
        $flag = TRUE;
    }
    return $flag;
}

/**
 * Check story is future schedule or not.
 * 
 * @param array $node
 * @return boolean
 */
function is_future_story($node) {
    $flag = FALSE;
    $schedule_time = strtotime($node->field_story_schedule_date_time['und'][0]['value']);
    if($schedule_time > time()) {
        $flag = TRUE;
    }
    return $flag;
}

/**
 * Function which is used to create node file for kindle.
 * 
 * @param string $file_name
 *    File name must be provides Article_FILE_NAME_nid.xml
 * @param int $node_id
 * @param string $section
 * @return string
 */
function _create_node_file($file_name = NULL, $node_id = NULL, $section = NULL) {
    $data = array();
    $data['file_name'] = $file_name;
	
    if(!is_null($file_name) && !is_null($node_id) && !is_null($section)) {
        $current_time = date(sprintf('Y-m-d\TH:i:s%s', substr(microtime(), 1, 4)));
        $issue_date = explode("+", date("c", strtotime($_GET['issue'])));
        //$issue_date = $issue_date[0] . substr(microtime(), 1, 4);
        $issue_date = $issue_date[0].'.000';
        $node_data = node_load($node_id);     
        $bylines = _get_byline_from_nid_for_kindle($node_id);
        $node_body = $node_data->body['und'][0]['value'];
        $node_body = preg_replace('#<div class="body_caption">(.*?)</div>#', ' ', $node_body);
        $node_body = preg_replace("/<\/?div[^>]*\>/i", "$1", $node_body);       
		  preg_match_all('/<img.*src=\"(.*)\".*>/isU', $node_body, $matches);
		  $i = 0;
		  foreach ($matches[0] as $images) {
			$src = $matches[1][$i];
			$img_info = pathinfo($src);
			$img_name = $img_info['basename'];
			$img = '<img src="images/'.$img_name.'" credit=""></img>';
			$node_body = str_replace($images, $img, $node_body);
			$i++;
		  }
	    $node_body = trim(preg_replace('/\s+/', ' ', $node_body));
        $node_body = trim($node_body);
        // Node xml data.
        $xml = '<?xml version="1.0" encoding="utf-8"?><nitf version="-//IPTC//DTD NITF 3.3//EN" xmlns:extra="urn:extra-functions">
    <head>
        <title> ' . _get_correct_file_name($section) . ' - Title ' . $node_id . ' </title>
        <docdata management-status="usable">
            <doc-id id-string="' . $node_id . '" regsrc="AMZN" />
            <urgency ed-urg="2" /> 
            <date.issue norm="' . $issue_date . '" />
            <date.release norm="' . $issue_date . '" /> 
            <du-key generation="1" key="GN3;5275646997;Amazon.4" />
            <doc.copyright holder="India Today" />
            <key-list>
                <keyword key="' . $node_data->metatags['und']['keywords']['value'] . '" />
            </key-list>
        </docdata>
        <pubdata type="print" date.publication="' . $issue_date . '" item-length="" position.sequence="1" unit-of-measure="character" />
    </head> 
    <body>
        <body.head>
            <hedline>
                <hl1>' . $node_data->title . '</hl1>
                <hl2 class="subhead">' . html_entity_decode($node_data->field_story_kicker_text['und'][0]['value']) . ' </hl2>
            </hedline>
            <byline>'.implode(",", $bylines).'></byline>
            <dateline></dateline>
            <abstract>' . html_entity_decode($node_data->field_story_kicker_text['und'][0]['value']) . '</abstract>
        </body.head>
        <body.content>
            <block>  <![CDATA[ ' . html_entity_decode(_remove_embded_tags_from_story_body($node_body)) . ' ]]> </block>
        </body.content>
        <body.end />
    </body>
</nitf>';
        $data['xml'] = _formet_xml($xml);
    }
    return $data;
}

/**
 * Function provide formated xml.
 * 
 * @param array $xml
 * @return string
 */
function _formet_xml($xml) {
    $dom = new DOMDocument;
    $dom->preserveWhiteSpace = false;
    $dom->formatOutput = true;
    $dom->loadXML($xml);
    return $dom->saveXML();
}

/**
 * Function which gives sections corresponding to nid.
 * 
 * @param int $nid
 * @return array
 */
function kindle_get_sections_for_node($nid) {
    try {
        $query = db_select('field_data_field_primary_category', 'fdc');
        $query->leftJoin('itg_category_manager', 'cm', 'cm.tid=fdc.field_primary_category_value');
        $query->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid = fdc.field_primary_category_value');
        $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = fdc.field_primary_category_value');
        $query->fields("fdc", array("field_primary_category_value"));
        $query->fields("td", array("name"));
        $query->condition('fdc.entity_id', $nid);
        //$query->condition('th.parent', 0);
        $query->condition('cm.status', 1);
        $result = $query->execute()->fetchAllAssoc('name');
    } catch(Exception $ex) {
        drupal_set_message($ex->getMessage(), 'error');
    }
    if(!empty($result)) {
        $sections = array_keys($result);
        $section_name = array();
        foreach($sections as $section) {
            $section_name[] = $section;
        }
        return $section_name;
    } else {
        return array();
    }
}

/**
 * Function used to remove special chars and symbole to create
 * valid file name for xml
 * @param string $str
 * @return string
 */
function _get_correct_file_name($str = '') {
    $str = strip_tags($str);
    $str = preg_replace('/[\r\n\t ]+/', ' ', $str);
    $str = preg_replace('/[\"\*\/\:\<\>\?\'\|]+/', ' ', $str);
    $str = strtolower($str);
    $str = html_entity_decode($str, ENT_QUOTES, "utf-8");
    $str = htmlentities($str, ENT_QUOTES, "utf-8");
    $str = preg_replace("/(&)([a-z])([a-z]+;)/i", '$2', $str);
    $str = str_replace(' ', '', $str);
    $str = rawurlencode($str);
    $str = str_replace('%', '', $str);
    return strtolower($str);
}

/**
 * Function which is used to create cover file.
 * 
 * @return string
 */
function _create_cover_xml() {
    $data = array();
    $data['file_name'] = 'Cover.xml';
    $xml = "<?xml version='1.0' encoding='utf-8'?>
<rss version='2.0'>
    <channel>
        <title>COVER</title>
        <link>Cover_page.xml</link>
        <item>
            <link>Cover_page.xml</link>
        </item>
    </channel>
</rss>";
    $data['xml'] = _formet_xml($xml);
    return $data;
}

/**
 * Function is used to create cover page file.
 * 
 * @return string
 */
function _create_cover_page_xml() {
    $data = array();
    // Time with mili second.
    $current_time = date(sprintf('Y-m-d\TH:i:s%s', substr(microtime(), 1, 4)));
    $issue_date = explode("+", date("c", strtotime($_GET['issue'])));
    //$issue_date = $issue_date[0] . substr(microtime(), 1, 4);
    $issue_date = $issue_date[0].'.000';
    $data['file_name'] = 'Cover_page.xml';
    $xml = '<?xml version="1.0" encoding="utf-8"?>
  <nitf version="-//IPTC//DTD NITF 3.3//EN" xmlns:extra="urn:extra-functions">
      <head>
          <title>Cover</title>
          <docdata management-status="usable">
              <doc-id id-string="0" regsrc="AMZN" />
              <urgency ed-urg="2" /> 
              <date.issue norm="' . $issue_date . '" />
              <date.release norm="' . $issue_date . '" /> 
              <du-key generation="1" key="GN3;5275646997;Amazon.4" />
              <doc.copyright holder="India Today" />
              <key-list>
                  <keyword key="" />
              </key-list>
          </docdata>
          <pubdata type="print" date.publication="' . $issue_date . '" item-length="" position.sequence="1" unit-of-measure="character" />
      </head> 
      <body>
          <body.head>
              <hedline>
                  <hl1>
                      <strong>Cover</strong>
                  </hl1>
                  <hl2></hl2>
              </hedline>
              <abstract></abstract>
          </body.head>
          <body.content>
              <block>
                  <content>
                      <img src="images/it-cover.jpg" credit=""></img>
                  </content>
              </block>
          </body.content>
          <body.end />
      </body>
  </nitf>';
    $data['xml'] = _formet_xml($xml);
    return $data;
}

/**
 * Function which is used to create manifest file.
 * 
 * @param array $section_array
 * @return string
 */
function _create_manifest_file($section_array = array(), $section_with_nids_array = array()) {
    $data = array();
    $data['file_name'] = 'manifest.xml';
    // Get sections which have valid story , which have not future story and expried story.
    $fresh_sections = array_keys(_get_sections_with_corrected_nids($section_with_nids_array));
    $issue_date = explode("+", date("c", strtotime($_GET['issue'])));
    //$issue_date = $issue_date[0] . substr(microtime(), 1, 4);
    $issue_date = $issue_date[0].'.000';
    //itg_watchdog("sections_with_nids", array($fresh_sections, $section_array));
    if(!empty($section_array)) {
        $current_time = date(sprintf('Y-m-d\TH:i:s%s', substr(microtime(), 1, 4)));
        $xml = "<?xml version='1.0' encoding='utf-8'?><rss version='2.0'>";
        $xml .="<channel>";
        $xml .="<title>India Today</title>";
        $xml .="<link>manifest.xml</link>";
        $xml .= "<pubDate>" . $issue_date . "</pubDate>";
        $xml .= "<item>";
        $xml .="<link>Cover.xml</link>";
        $xml .= "</item>";
        foreach($section_array as $section) {
            if(in_array($section, $fresh_sections)) {
                $xml .= "<item>";
                $xml .="<link>Section_" . _get_correct_file_name($section) . ".xml</link>";
                $xml .= "</item>";
            }
        }
        $xml .= "</channel>";
        $xml .="</rss>";
    }
    $data['xml'] = _formet_xml($xml);
    return $data;
}

/**
 * Function which is used to create final array for sections and corrosponding nodes
 * 
 * Two array which is for sections and nodes are created.
 * Sections will have that nodes which are under same level of level of section.
 * Example
 * Nodes Array ( [0] => 172884 [1] => 172890 )
 * Sections Array ( [0] => Array ( [0] => section1 [1] => section2 )
 *                  [1] => Array ( [0] => section2 [1] => section3 )
 *                )
 * as section1 is in level of 0 then nodeid 172884 will be come , same as for section3
 * but section2 is common for both level i.e. 1,2 so this section will contain both nodes
 * 172884 , 172890
 * 
 * @param array $sections
 * @param array $nodes_array
 */
function _create_articles_section_files($sections = array(), $nodes_array = array()) {
    if(!empty($sections) && !empty($nodes_array)) {
        $all_sections = array();
        $final_array = array();
        // Combine all sections

        foreach($sections as $section) {
            foreach($section as $sec) {
                $all_sections[] = $sec;
            }
        }
        $all_unique_sections = array_unique($all_sections);

        // Create final array logic is define in function description
        foreach($all_unique_sections as $unq_section) {
            foreach($sections as $key => $section_array) {
                if(in_array($unq_section, $section_array)) {
                    $final_array[$unq_section][] = $nodes_array[$key];
                }
            }
        }
        return $final_array;
    }
    return array();
}
