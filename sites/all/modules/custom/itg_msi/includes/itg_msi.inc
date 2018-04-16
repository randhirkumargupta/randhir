<?php
/**
 * Functionality to check title is duplicate OR not
 * Call through ajax function
 */
function itg_msi_check_duplicate_title() {
    $type = arg(1);
    $nid = arg(2);
    $title = $_POST['title'];
    $itgQuery = db_select('node', 'itg');

    if (empty($nid)) {
        $itgQuery->fields('itg', array('title'))
                ->condition('title', $title, '=')
                ->condition('type', $type, '=');
    }
    else {
        $itgQuery->fields('itg', array('title'))
                ->condition('title', $title, '=')
                ->condition('type', $type, '=')
                ->condition('nid', $nid, '!=');
    }

    $itgResult = $itgQuery->execute()->fetchObject();
    if (isset($itgResult->title) && strcasecmp($title, $itgResult->title) == 0) {
        echo ($type == 'astro') ? 'false' : drupal_json_encode(array('Code' => 1));
    }
    else {
        echo ($type == 'astro') ? 'true' : drupal_json_encode(array('Code' => 0));
    }
}

/**
 * Autocomplete on title(date field) of issue listing
 * @param string $title
 */
function itg_msi_autocomplete_content($title) {

    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('field_data_field_issue_title', 'c');
        $query->fields('c', array('field_issue_title_value'));
        $query->condition('field_issue_title_value', '%' . $title . '%', 'LIKE');
        $query->condition('c.bundle', $content_type, '=');
        $query->range(0, 20);

        $result = $query->execute();
        while ($record = $result->fetchAssoc()) {
            $options[date('Y-m-d', strtotime($record['field_issue_title_value']))] = date('m/d/Y', strtotime($record['field_issue_title_value']));
        }
        drupal_json_output($options);
    }
}

/**
 * Setting form for Issue Web exclusive.
 * @return type
 */
function itg_msi_show_web_exclusive_form() {
  $form = array();
  $form['show_web_exclusive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Web Exclusive'),
    '#required' => FALSE,
    '#default_value' => variable_get('show_web_exclusive'), // for default checked and false is not checked
  );
  return system_settings_form($form);
}

function itg_msi_magazine_page(){
	return theme('magazine');	
}
