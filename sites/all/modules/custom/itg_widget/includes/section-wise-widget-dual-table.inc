<?php

/**
 * Function which gives main details for a node.
 * @param int $nid
 * @return array
 */
function _get_section_wise_widget_node_data($nid) {
  $query = db_select("node", "n");
  $query->leftJoin("users", "u", "u.uid=n.uid");
  $query->fields("n", array("title", "created", "uid", "nid", "type"));
  $query->fields("u", array("name"));
  $query->condition("n.nid", $nid);
  return $query->execute()->fetchAssoc();
}

/**
 * Form which is used to save widget data.
 * 
 * {@inheritdocs}
 */
function section_wise_widget_form($form, &$form_state) {
  $type = !empty($_GET['type']) ? $_GET['type'] : "All";
  $cat_id = !empty($_GET['category_tid']) ? $_GET['category_tid'] : 0;
  $item_per_page = !empty($_GET['items_per_page']) ? $_GET['items_per_page'] : 10;
  $table = 'itg_widget_order_section';
  if (strtolower($type) == 'all') {
    $table = 'itg_widget_order';
  }
  $db_query = db_select($table, 'iwo')->extend('PagerDefault')->limit($item_per_page);
  $db_query->fields('iwo', array('nid', 'weight', 'content_type', 'cat_id'));
  $db_query->condition('iwo.widget', 'section_wise_widget');
  $db_query->condition('iwo.content_type', $type);
  $db_query->condition('iwo.cat_id', $cat_id);
  $db_query->orderBy('iwo.weight', 'DESC');
  $result = $db_query->execute()->fetchAll(PDO::FETCH_ASSOC);
  if (count($result)) {

    $form['widget_data'] = array(
      '#tree' => TRUE
    );

    foreach ($result as $key => $value) {
      if (!empty($value['nid']) && $value['nid'] > 0) {
        $form['widget_data'][$key]['weight'] = array(
          '#type' => 'textfield',
          '#value' => $value['weight'],
          '#title' => 'weight',
        );

        $form['widget_data'][$key]['nid'] = array(
          '#type' => 'hidden',
          '#value' => $value['nid'],
          '#title' => 'node id'
        );

        $form['widget_data'][$key]['content_type'] = array(
          '#type' => 'hidden',
          '#value' => $value['content_type'],
          '#title' => 'weight',
        );

        $form['widget_data'][$key]['cat_id'] = array(
          '#type' => 'hidden',
          '#value' => $value['cat_id'],
          '#title' => 'weight',
        );
      }
    }
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'save',
    );

    $form['pagger'] = array(
      '#type' => 'markup',
      "#markup" => theme('pager'),
    );

    $form['content_type_hint'] = array(
      '#type' => 'hidden',
      '#value' => isset($_GET['type']) ? $_GET['type'] : FALSE,
    );
  }
  else {
    $form['row_count'] = array(
      '#type' => 'markup',
      "#markup" => t("No result found."),
    );
  }
  drupal_add_css(".no-result-found , #views-form-section-wise-content-ordering-list-page p {
        display: none;
    }", "inline");
  return $form;
}

/**
 * Function which gives categories associated to nodes.
 * @param int $nid
 * @return string
 */
function _get_sections_name_related_to_nid($nid) {
  $db_query = db_select('field_data_field_story_category', 'sc');
  $db_query->leftJoin('taxonomy_term_data', 'ttd', 'ttd.tid = sc.field_story_category_tid');
  $db_query->fields('sc', array("field_story_category_tid"));
  $db_query->fields('ttd', array("name"));
  $db_query->condition("sc.entity_id", $nid);
  $sections = $db_query->execute()->fetchAll(PDO::FETCH_ASSOC);
  if (!empty($sections)) {
    foreach ($sections as $section) {
      $html[] = $section['name'];
    }
    return implode(", ", $html);
  }
  return "";
}

/**
 * Function which save section widget order data.
 * {@inheritdocs}
 */
function section_wise_widget_form_submit($form, &$form_state) {
  $content_type_hint = $form_state['input']['content_type_hint'];
  $db_table = 'itg_widget_order_section';
  if (strtolower($content_type_hint) == 'all') {
    $db_table = 'itg_widget_order';
  }
  $widget_data = $form_state['input']['widget_data'];
  $widget = 'section_wise_widget';
  // Now insert new entry in itg_widget_order table of combination
  foreach ($widget_data as $data) {
    try {
      if (!empty($data['weight']) && !empty($data['nid']) && !empty($data['cat_id'] && !empty($data['content_type']))) {
        db_merge($db_table)
            ->key(array(
              'nid' => $data['nid'],
              'widget' => $widget,
              'cat_id' => $data['cat_id'],
              'content_type' => $data['content_type'],
            ))
            ->fields(array(
              'weight' => $data['weight'],
              'nid' => $data['nid'],
              'widget' => $widget,
              'cat_id' => $data['cat_id'],
              'content_type' => $data['content_type'],
            ))
            ->execute();
      }
    }
    catch (Exception $ex) {
      drupal_set_message($ex->getMessage());
    }
  }
}
