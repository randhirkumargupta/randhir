<?php
/**
 * Get associate content poll list
 * @return array $output //http://localhost/itg-cms/content/testttt
 */
function associate_content_poll() {
  // configure the table header columns
  $header = array(
    array('data' => t('S.No.')) ,
    array('data' => t('Title')) ,
    array('data' => t('ID')) ,
    array('data' => t('Status')) ,
    array('data' => t('Content type')) ,
    array('data' => t('Action')) ,
  );

  if ($_GET['items_per_page']) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 10;
  }
  $current_time = date("Y-m-d H:i:s");

  $itg_query = db_select('itg_poll_count_content' , 'p');
  $itg_query->fields('p' , array('content_id' , 'content_type'));
  $itg_query->join('node' , 'n' , 'n.nid = p.content_id');
  $itg_query->join('workbench_moderation_node_history' , 'w' , 'w.nid = n.nid');
  $itg_query->leftJoin('field_data_field_story_expiry_date' , 'expiry' , 'n.nid = expiry.entity_id');
  $itg_query->fields('n' , array('title' , 'status'));
  $itg_query->fields('expiry' , array('field_story_expiry_date_value'));
  $itg_query->fields('w' , array('state'));
  $itg_query->extend('PagerDefault')->limit($items_per_page);
  $itg_query->condition('p.poll_id' , arg(1));
  $itg_query->condition('w.is_current' , 1);

  $itg_result = $itg_query->execute()->fetchAll();

  $rows = array();

  $count = 0;

  foreach ($itg_result as $row) {
    if (empty($row->field_story_expiry_date_value) || ($row->field_story_expiry_date_value >= $current_time)) {
      $action_link = l(t('Edit') , 'node/' . $row->content_id . '/edit');
      $status = $row->state;
    }
    else {
      $action_link = '';
      $status = 'Expired';
    }

    $rows[] = array(
      array('data' => $count + 1) ,
      array('data' => $row->title) ,
      array('data' => $row->content_id) ,
      array('data' => $status) ,
      array('data' => $row->content_type) ,
      array('data' => $action_link) ,
    );
    $count++;
  }

  $output = '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
  $output .= theme('table' , array('header' => $header , 'rows' => $rows , 'attributes' => array('class' => array('views-table')) , 'empty' => 'No results found'));

  // add the pager
  $output .= theme('pager');

  return $output;
}