<?php

/**
 * Implements itg_story_byline().
 * @param string $title
 */
function itg_story_byline($title) {
  $options = '';
  $title = strtolower(trim($title));
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_reporter_email_id', 're', 'n.nid = re.entity_id');
  $query->leftJoin('field_data_field_reporter_profile_type', 'frq', 'n.nid = frq.entity_id');
  $query->fields('n');
  $query->fields('frq', array('field_reporter_profile_type_value'));
  $query->fields('re', array('field_reporter_email_id_value'));
  $query->condition('n.title', '%' . $title . '%', 'LIKE');
  $query->condition('n.type', 'reporter', '=');
  $query->range(0, 20);
  //field_reporter_profile_type_value
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    if (!empty($record['field_reporter_profile_type_value']))
    {
      $reporter_type = '(' . $record['field_reporter_profile_type_value'] . ')';
    }
    if (!empty($record['field_reporter_email_id_value']))
    {
      $reporter_email = '(' . $record['field_reporter_email_id_value'] . ')';
    }
    $name_format = $record['title'] . $reporter_type . $reporter_email . '{' . $record['nid'] . '}';
    $options[$name_format] = $name_format;
  }
  drupal_json_output($options);
}

/**
 * Implements itg_story_byline_save().
 */
function itg_story_byline_save() {
//  preg_match_all('!\d+!', $_POST['nd_id'], $matches);
//  $byline_nid = $matches[0][0];
  $trigger_event = $_POST['byline_event'];
  //preg_match_all('/\(([A-Za-z0-9 ]+?)\)/', $_POST['nd_id'], $matches);
  preg_match_all('/{(.*?)}/', $_POST['nd_id'], $matches);
  if($trigger_event == 'unpublish') {
  //$byline_nid = trim($matches[1][1]);
    $byline_nid = trim($matches[1][0]);
  } else {
    $byline_nid = $_POST['nd_id'];
  }
  $nid = $_POST['nd_id'];
  $unique_id = $_POST['unique_id'];
  $byline_arr = itg_get_byline_detail($byline_nid);
  $byline_name = $byline_arr[0]['title'];
  $byline_type = $byline_arr[0]['field_reporter_profile_type_value'];
  $previous_byline = itg_get_previous_byline_detail($unique_id, $byline_nid);


  if ($trigger_event == 'unpublish')
  {

    if (!empty($byline_nid) && empty($previous_byline))
    {
      $qry = db_insert('itg_multi_byline_info')
          ->fields(array(
            'byline_id' => $byline_nid,
            'uniqueid' => $unique_id,
            'created' => REQUEST_TIME
          ))
          ->execute();
      $remove = '<a href="javascript:void(0)" data-val="' . $byline_nid . '" data-tag="' . $qry . '" class="remove-byline">' . t('Remove') . '</a>';
      if (!empty($byline_type))
      {
        $byline_type = '<span>' . $byline_type . '</span>';
      }
      $byline_res = '<li id="' . $qry . '"><i class="fa fa-arrows" aria-hidden="true"></i><input type="checkbox" name="bylinepublish" data-tag="' . $qry . '" value="' . $byline_nid . '" class="byline_publish"><span>' . t('Publish') . '</span><span>' . $byline_name . '</span>' . $byline_type . '<span>' . $remove . '</span></li>';
      $response = array('msg' => 'success', 'lnk' => $byline_res);
      print json_encode($response);
    }
    else
    {
      $response = array('msg' => 'error', 'description' => 'alreadyexist');
      print json_encode($response);
    }
  }

  if ($trigger_event == 'publish' && !empty($previous_byline))
  {

    $status = $_POST['status'];
    //print 'ankush';
    if (!empty($nid) && !empty($unique_id))
    {

      db_update('itg_multi_byline_info')
          ->fields(array(
            'publish_status' => $status,
          ))
          ->condition('id', $_POST['bl_id'], '=')
          ->condition('uniqueid', $unique_id, '=')
          ->execute();
      $response = array('msg' => 'success', 'response' => 'true');
      print json_encode($response);
    }
    else
    {
      $response = array('msg' => 'error', 'description' => 'alreadyupdate');
      print json_encode($response);
    }
  }

  if ($trigger_event == 'remove' && !empty($nid))
  {
    db_delete('itg_multi_byline_info')
        ->condition('id', $nid)
        ->execute();
    $response = array('msg' => 'delete', 'byline' => $nid);
    print json_encode($response);
  }
}

/**
 * Implements itg_byline_info().
 * @param int $reporter_id
 */
function itg_byline_info($reporter_id) {
  $val = '';
  if (!empty($reporter_id))
  {
    $query = db_select('itg_multi_byline_info', 'c');
    $query->fields('c');
    $query->condition('c.uniqueid', $reporter_id);
    $query->orderBy("byline_weight", "ASC");
    $result = $query->execute();
    while ($record = $result->fetchAssoc()) {
      $byline_arr = itg_get_byline_detail($record['byline_id']);
      $byline_name = $byline_arr[0]['title'];
      $byline_type = $byline_arr[0]['field_reporter_profile_type_value'];
      if (!empty($byline_type))
      {
        $byline_type = '<span>' . $byline_type . '</span>';
      }
      $remove = '<a href="javascript:void(0)" data-val="' . $record['byline_id'] . '" data-tag="' . $record['id'] . '" class="remove-byline">' . t('Remove') . '</a>';
      if ($record['publish_status'] == 1)
      {
        $val .= '<li id="' . $record['id'] . '"><i class="fa fa-arrows" aria-hidden="true"></i><input type="checkbox" name="bylinepublish" data-tag="' . $record['id'] . '" value="' . $record['byline_id'] . '" class="byline_publish" checked><span>' . t('Publish') . '</span><span>' . $byline_name . '</span>' . $byline_type . '<span>' . $remove . '</span></li>';
      }
      else
      {
        $val .= '<li id="' . $record['id'] . '"><i class="fa fa-arrows" aria-hidden="true"></i><input type="checkbox" name="bylinepublish" data-tag="' . $record['id'] . '" value="' . $record['byline_id'] . '" class="byline_publish"><span>' . t('Publish') . '</span><span>' . $byline_name . '</span>' . $byline_type . '<span>' . $remove . '</span></li>';
      }
    }
    return $val;
  }
}

/**
 * Implements itg_miscellaneous_byline().
 * @param int $nid
 */
function itg_get_byline_detail($nid) {

  if (!empty($nid))
  {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_reporter_profile_type', 'pk', 'n.nid=pk.entity_id');
    $query->fields('n', array('title'));
    $query->fields('pk', array('field_reporter_profile_type_value'));
    $query->condition('n.nid', $nid);
    $query->condition('n.type', 'reporter', '=');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    return $result;
  }
}

/**
 * Implements itg_miscellaneous_byline().
 * @param string $unique_id
 * @param int $nid
 */
function itg_get_previous_byline_detail($unique_id, $nid) {

  if (!empty($nid))
  {
    $query = db_select('itg_multi_byline_info', 'bn');
    $query->fields('bn', array('id'));
    $query->condition('bn.byline_id', $nid);
    $query->condition('bn.uniqueid', $unique_id);
    $result = $query->execute()->fetchField();

    return $result;
  }
}

/**
 * Implements itg_get_byline_row().
 * @param string $uniqueid
 */
function itg_get_byline_row($uniqueid) {
  if (!empty($uniqueid))
  {
    $query = db_select('itg_multi_byline_info', 'c');
    $query->fields('c', array('byline_id'));
    $query->condition('c.uniqueid', $uniqueid);
    $result = $query->execute()->fetchField();
    return $result;
  }
}

/**
 * Implements hook_node_insert
 * {@inheritdoc}
 */
function itg_story_node_insert($node) {
  if ($node->type == 'story' && !empty($node->type))
  {
    $nid = $node->nid;
    $unique_id = '';
    $publish_id = '';
    if (!empty($node->field_reporter_unique_id[LANGUAGE_NONE]))
    {
      $unique_id = $node->field_reporter_unique_id[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($node->field_reporter_publish_id[LANGUAGE_NONE][0]['value']))
    {
      $publish_id = $node->field_reporter_publish_id[LANGUAGE_NONE][0]['value'];
    }

    itg_byline_order_update($publish_id, $nid, $unique_id);

    unset($_SESSION['unique']);
  }
}

/**
 * Implements hook_node_update
 * {@inheritdoc}
 */
function itg_story_node_update($node) {
  if ($node->type == 'story')
  {
    if(itg_workflow_stop_node_update_batch_for_widgets()) {
      return;
    }
    $nid = $node->nid;
    if (!empty($node->field_reporter_unique_id[LANGUAGE_NONE]))
    {
      $unique_id = $node->field_reporter_unique_id[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($node->field_reporter_publish_id[LANGUAGE_NONE][0]['value']))
    {
      $publish_id = $node->field_reporter_publish_id[LANGUAGE_NONE][0]['value'];
    }

    itg_byline_order_update($publish_id, $nid, $unique_id);
  }
}

/**
 * Implements itg_byline_order_update
 * @param string $byline
 * @param int $nid
 */
function itg_byline_order_update($byline, $nid, $uniqueid) {
  $byline_arr = explode(',', $byline);
  $i = 0;
  if (!empty($byline_arr))
  {
    foreach ($byline_arr as $value) {
      db_update('itg_multi_byline_info')
          ->fields(array(
            'byline_weight' => $i,
            'nid' => $nid,
          ))
          ->condition('byline_id', $value, '=')
          ->condition('uniqueid', $uniqueid, '=')
          ->execute();
      $i++;
    }
  }
}
