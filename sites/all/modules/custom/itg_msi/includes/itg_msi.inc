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
	drupal_set_title('');
	return theme('magazine');	
}

/**
 * Menu Callback for Fixing Issue Magazine Page.
 */ 
function fix_magazine_order_by_issue($issue_date) {
  $issue_title = date("Y-m-d", strtotime($issue_date));
  $weight = 1106005;
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_issue_date', 'ft', 'ft.entity_id = n.nid');
  $query->fields('n', array('nid'));
  $query->condition('ft.field_story_issue_date_value', '%' . db_like($issue_title) . '%', 'LIKE');
  $query->condition('n.type', 'story', '=');
  $query->condition('ft.bundle', 'story', '=');
  $results = $query->execute()->fetchAll();
  foreach ($results as $nid_obj) {
    $nid = $nid_obj->nid;
    $category_arr = get_story_categories_by_nid($nid);
    foreach ($category_arr as $cat_id) {
      $row_count = 0;
      $w_query = db_select('itg_widget_order', 'w');
      $w_query->fields('w', array('weight'));
      $w_query->condition('w.nid', $nid, '=');
      $w_query->condition('w.cat_id', $cat_id, '=');
      $w_query->condition('w.widget', 'section_wise_widget', '=');
      $w_query->condition('w.content_type', 'all', '=');
      $row_count = $w_query->execute()->rowCount();
      if ($row_count < 1) {
        db_insert('itg_widget_order') // Table name no longer needs {}
            ->fields(array(
              'nid' => $nid,
              'cat_id' => $cat_id,
              'content_type' => 'all',
              'widget' => 'section_wise_widget',
              'weight' => $weight,
            ))
            ->execute();
        
      }
    }    
  }
  $node_count = count($results);
  print "Done Successfully for ".$node_count." Nodes.";
}
