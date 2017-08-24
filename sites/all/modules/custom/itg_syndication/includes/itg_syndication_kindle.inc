<?php

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form($form, &$form_state) {

  $options_first = magazine_options();
  $selected = isset($form_state['values']['magazine']) ? $form_state['values']['magazine'] : key($options_first);
  if (isset($_GET['magazine'])) {
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
  if (isset($_GET['issue'])) {
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

  if (isset($_GET['issue']) && isset($_GET['magazine'])) {
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
  if (isset($options[$key])) {
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
  $itg_query->range(0, 10);
  $itg_result = $itg_query->execute()->fetchAll();
  foreach ($itg_result as $key => $data) {
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
  if ($issue == '_none') {
    form_set_error('issue', t("Please select issue"));
  }
  if (isset($_GET['issue']) && empty($_GET['issue'])) {
    form_set_error('issue', t("Please select issue"));
  }

  if (isset($_GET['magazine']) && empty($_GET['magazine'])) {
    form_set_error('magazine', t("Please select magazine"));
  }
}

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] == 'Submit') {
    $issue = $form_state['values']['issues'];
    $magazine = $form_state['values']['magazine'];
    drupal_goto('itg-kindle-feed', array('query' => array("issue" => $issue, "magazine" => $magazine)));
  } else {
    $issue = $_GET['issue'];
    $magazine = $_GET['magazine'];
    if (!empty($issue) && !empty($magazine)) {
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
      } catch (Exception $ex) {
        drupal_set_message($ex->getMessage() , 'error');
      }
      $node_ids = array_keys($result);
      foreach ($node_ids as $nid) {
        $data_array['sections'][] = kindle_get_sections_for_node($nid);
        $data_array['nids'][] = $nid;
      }
      $section_with_nids_array = _create_articles_section_files($data_array['sections'], $data_array['nids']);
      _create_section_file($section_with_nids_array);
    }
  }
}

/**
 * Main function which is used to create section xml file.
 * 
 * @param array $section_with_nids
 */
function _create_section_file($section_with_nids = array()) {
  if (!empty($section_with_nids)) {
    foreach ($section_with_nids as $section_name => $node_array) {
      // Section file started
      $xml = "<?xml version='1.0' encoding='utf-8'?>";
      $xml .= "<rss version='2.0'>";
      $xml .= "<channel>";
      $xml .= "<title>" . $section_name . "</title>";
      foreach ($node_array as $nid) {
        $artical_file_name = "Article_" . _get_correct_file_name($section_name) . $nid . ".xml";
        $xml .="<item><link>Article_" . $artical_file_name . ".xml</link></item>";
        _create_node_file($artical_file_name, $nid, $section_name);
      }
      $xml .= "</channel></rss>";
      // Section file ended
    }
  }
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

  if (!is_null($file_name) && !is_null($node_id) && !is_null($section)) {
    $current_time = date(sprintf('Y-m-d\TH:i:s%s', substr(microtime(), 1, 4)));
    $node_data = node_load($node_id);
    // Node xml data.
    $data['xml'] = '<?xml version="1.0" encoding="utf-8"?><nitf version="-//IPTC//DTD NITF 3.3//EN" xmlns:extra="urn:extra-functions">
    <head>
        <title> <![CDATA[ ' . _get_correct_file_name($section) . ' - Title ' . $node_id . ' ]]> </title>
        <docdata management-status="usable">
            <doc-id id-string="' . $node_id . '" regsrc="AMZN" />
            <urgency ed-urg="2" /> 
            <date.issue norm="' . $current_time . '" />
            <date.release norm="' . $current_time . '" /> 
            <du-key generation="1" key="GN3;5275646997;Amazon.4" />
            <doc.copyright holder="India Today" />
            <key-list>
                <keyword key="" />
            </key-list>
        </docdata>
        <pubdata type="print" date.publication="' . $current_time . '" item-length="" position.sequence="1" unit-of-measure="character" />
    </head> 
    <body>
        <body.head>
            <hedline>
                <hl1> <![CDATA[ ' . $node_data->title . ' ]]>  </hl1>
                <hl2 class="subhead"> <![CDATA[ ' . $node_data->field_story_magazine_kicker_text ['und'][0]['value'] . '  ]]> </hl2>
            </hedline>
            <byline> </byline>
            <dateline></dateline>
            <abstract>  <![CDATA[ ' . $node_data->field_story_magazine_kicker_text ['und'][0]['value'] . ' ]]> </abstract>
        </body.head>
        <body.content>
            <block>  <![CDATA[ ' . $node_data->body ['und'][0]['value'] . ' ]]> </block>
        </body.content>
        <body.end />
    </body>
</nitf>';
  }
  return $data;
}

/**
 * Function which gives sections corresponding to nid.
 * 
 * @param int $nid
 * @return array
 */
function kindle_get_sections_for_node($nid) {
  try {
    $query = db_select('field_data_field_story_category', 'fdc');
    $query->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid = fdc.field_story_category_tid');
    $query->leftJoin('taxonomy_term_data', 'td', 'td.tid = fdc.field_story_category_tid');
    $query->fields("fdc", array("field_story_category_tid"));
    $query->fields("td", array("name"));
    $query->condition('fdc.entity_id', $nid);
    $query->condition('th.parent', 0);
    $result = $query->execute()->fetchAllAssoc('name');
  } catch (Exception $ex) {
    drupal_set_message($ex->getMessage() , 'error');
  }
  if (!empty($result)) {
    $sections = array_keys($result);
    $section_name = array();
    foreach ($sections as $section) {
      $section_name[] = $section;
    }
    return $section_name;
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
  return $str;
}

/**
 * Function which is used to create cover file.
 * 
 * @return string
 */
function _create_cover_xml() {
  $data = array();
  $data['file_name'] = 'Cover.xml';
  $data['xml'] = "<?xml version='1.0' encoding='utf-8'?>
<rss version='2.0'>
    <channel>
        <title>COVER</title>
        <link>Cover_page.xml</link>
        <item>
            <link>Cover_page.xml</link>
        </item>
    </channel>
</rss>";
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
  $data['file_name'] = 'Cover_page.xml';
  $data['xml'] = '<?xml version="1.0" encoding="utf-8"?>
  <nitf version="-//IPTC//DTD NITF 3.3//EN" xmlns:extra="urn:extra-functions">
      <head>
          <title>Cover</title>
          <docdata management-status="usable">
              <doc-id id-string="0" regsrc="AMZN" />
              <urgency ed-urg="2" /> 
              <date.issue norm="' . $current_time . '" />
              <date.release norm="' . $current_time . '" /> 
              <du-key generation="1" key="GN3;5275646997;Amazon.4" />
              <doc.copyright holder="India Today" />
              <key-list>
                  <keyword key="" />
              </key-list>
          </docdata>
          <pubdata type="print" date.publication="' . $current_time .
    '" item-length="" position.sequence="1" unit-of-measure="character" />
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
  return $data;
}

/**
 * Function which is used to create manifest file.
 * 
 * @param array $section_array
 * @return string
 */
function _create_manifest_file($section_array = array()) {
  $data = array();
  $data['file_name'] = 'manifest.xml';
  if (!empty($section_array)) {
    $current_time = date(sprintf('Y-m-d\TH:i:s%s', substr(microtime(), 1, 4)));
    $xml = "<?xml version='1.0' encoding='utf-8'?><rss version='2.0'>";
    $xml .="<channel>";
    $xml .="<title>India Today</title>";
    $xml .="<link>manifest.xml</link>";
    $xml .= "<pubDate>" . $current_time . "</pubDate>";
    $xml .= "<item>";
    $xml .="<link>Cover.xml</link>";
    $xml .= "</item>";
    foreach ($section_array as $section) {
      $xml .= "<item>";
      $xml .="<link>Section_" . $section . ".xml</link>";
      $xml .= "</item>";
    }
    $xml .= "</channel>";
    $xml .="</rss>";
  }
  $data['xml'] = $xml;
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
  if (!empty($sections) && !empty($nodes_array)) {
    $all_sections = array();
    $final_array = array();
    // Combine all sections

    foreach ($sections as $section) {
      foreach ($section as $sec) {
        $all_sections[] = $sec;
      }
    }
    $all_unique_sections = array_unique($all_sections);

    // Create final array logic is define in function description
    foreach ($all_unique_sections as $unq_section) {
      foreach ($sections as $key => $section_array) {
        if (in_array($unq_section, $section_array)) {
          $final_array[$unq_section][] = $nodes_array[$key];
        }
      }
    }
    return $final_array;
  }
  return array();
}
