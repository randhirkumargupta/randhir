<?php

/**
 * @file
 * Itg_auto_save contains member function and member used for autosave
 * functionality.
 *
 * @author ITG
 */

/**
 * Class have logic to autosave node data.
 */
class itg_auto_save {

  /**
   * Insert form ids to database.
   *
   * @param array $pre_save
   *   Preapared array for saving into database.
   */
  public function itg_save_form_id($pre_save) {
    // Check value if form id is already in database.
    $this->is_duplicate = $this->itg_save_is_duplicate($pre_save);
    // If form id is duplicate then update form id else insert into database.
    if ($this->is_duplicate) {
      $this->itg_save_form_id_update($pre_save);
      drupal_set_message('Form id has been updated.', 'status');
    } else {
      $this->itg_save_form_id_insert($pre_save);
      drupal_set_message('Form id has been inserted.', 'status');
    }
  }

  /**
   * Check duplicate form id.
   *
   * @param array $pre_save
   *   Form id information which is going to be save.
   *
   * @return bool
   *   If form id already in database then return true else return false.
   */
  private function itg_save_is_duplicate($pre_save) {
    $this->dup_query = db_select('itg_autosave_forms', 'itg');
    $this->dup_query->condition('form_name', $pre_save['form_name']);
    $this->dup_query->fields('itg', array('form_name'));
    $this->dup_result = $this->dup_query->execute()->fetchField();
    // Compare new value from existing value.
    if ($pre_save['form_name'] == $this->dup_result) {
      return TRUE;
    } else {
      return FALSE;
    }
  }

  /**
   * Insert form data.
   *
   * @param array $pre_save
   *   Form id information.
   */
  private function itg_save_form_id_insert($pre_save) {
    $this->itg_query = db_insert('itg_autosave_forms')
            ->fields($pre_save)
            ->execute();
  }

  /**
   * Update form data.
   *
   * @param array $pre_save
   *   Form id information.
   */
  private function itg_save_form_id_update($pre_save) {
    $this->itg_query = db_update('itg_autosave_forms')
            ->fields($pre_save)
            ->condition('form_name', $pre_save['form_name'])
            ->execute();
  }

  /**
   * Pass form ids to js file.
   *
   * @param int $nid
   *   Node id of the node.
   * @param string $c_type
   *   Name of the content type.
   */
  public function itg_save_set_form_ids($nid, $c_type) {
    global $base_url;
    $this->data = '';
    $this->fid_query = db_select('itg_autosave_forms', 'itg');
    $this->fid_query->fields('itg', array('form_name', 'autosave_time'));
    $this->fid_result = $this->fid_query->execute()->fetchAll();
    // Prepare array list form settings.
    foreach ($this->fid_result as $row) {
      $this->data[$row->form_name] = array(
          $row->form_name,
          $row->autosave_time,
      );
    }
    // Pass data to js file.
    drupal_add_js(array(
        'itg_autosave' => array(
            'auto_settings' => $this->data,
            'base_url' => $base_url,
            'nid' => $nid,
            'c_type' => $c_type,
        ),
            ), array(
        'type' => 'setting',
    ));
  }

  /**
   * Extract field type available on any content type.
   *
   * @param array $inputs
   *   Submitted form data.
   *
   * @return array
   *   Return array containing field name with field type.
   */
  public function itg_save_extract_fieldtype($inputs) {
    $this->field_type_result = array();
    foreach ($inputs as $key => $value) {
      // Get field information.
      $this->field_type_query = field_info_field($key);
      $this->field_type_result[] = array(
          'fieldName' => $this->field_type_query['field_name'],
          'fieldType' => $this->field_type_query['type'],
      );
    }
    return $this->field_type_result;
  }

  /**
   * Prepare presave array for file field.
   *
   * @param string $field_name
   *   Machine name of the current field.
   * @param array $inputs
   *   File field submitted value.
   * @param stdObject
   *   Node object.
   */
  public function itg_save_field_file($field_name, $inputs, &$node) {
    $this->file = $inputs[$node->language][0];
    if ($this->file['fid'] > 0) {
      $node->{$field_name}[$node->language][0]['fid'] = $this->file['fid'];
    }
    if ($this->file['description'] != '') {
      $node->{$field_name}[$node->language][0]['description'] = $this->file['description'];
    }
    if ($this->file['display'] != '') {
      $node->{$field_name}[$node->language][0]['display'] = $this->file['display'];
    }
  }

  /**
   * Prepare presave arrave for text field.
   *
   * @param array $value
   *   Field Value
   *
   * @return string
   *   Extracted value.
   */
  public function itg_save_field_text($value) {
    $this->text_arr = '';
    $this->text_arr = $value['und'][0]['value'];

    return $this->text_arr;
  }

  /**
   * Prepare presave array for field collection type field.
   *
   * @param array $value
   *   All values of current field collection field.
   * @param stdObject $node
   *   Standard node object.
   * @param string $field_name
   *   Field name of the current field collection field.
   * @param array $fc_ids
   *   Serialized array contaning field collections ids.
   */
  public function itg_save_field_field_collection($value, &$node, $field_name, $fc_ids) {

    $this->field_collection = array();
    $this->field_collection_data = array();
    // Unserialize fields collections ids for deletion of field collection.
    $fc_ids = unserialize($fc_ids);
    if (isset($node->nid)) {
      // Unset field collection field .
      unset($node->{$field_name}[LANGUAGE_NONE]);
      // Delete field collection items.      
      entity_delete_multiple('field_collection_item', $fc_ids[$field_name]);
    }

    // Create new field collection for node field.
    foreach ($value['und'] as $key => $fc_value) {

      // Get field type for field collection values.
      $this->field_collection_data = $this->itg_save_extract_fieldtype($fc_value);

      // Filter empty array from list.
      $this->field_collection_data = array_filter($this->field_collection_data, 'itg_autosave_remove_empty');

      // Validate empty field collection
      $this->validation = $this->itg_save_validate_field_collection($this->field_collection_data, $fc_value);
      // Create entity of type field collection
      if ($this->validation) {

        watchdog('Field Collection Validation', $this->validation . ' Auto Save' . $key);

        $this->fc_item = entity_create('field_collection_item', array('field_name' => $field_name));
        $this->fc_item->setHostEntity('node', $node);
        $this->itg_save_field_collection($this->field_collection_data, $fc_value, $this->fc_item);
        $this->fc_item->save(TRUE);
        $node->{$field_name}[$node->language][$key]['value'] = $this->fc_item->item_id;
      }
    }
  }

  /**
   * Update field collection values.
   *
   * @param stdObject $node
   *   Standard node object.
   * @param array $collection
   *   Name of the collection object.
   * @param array $fields
   *   Fields of a single collections.
   * @param int $index
   *   Delta value of field collections.
   */
  function itg_save_update_field_collection($node, $collection, $fields = Array(), $index = 0) {
    if ($node && $collection && !empty($fields)) {
      // Get the field collection ID
      $eid = $node->{$collection}[LANGUAGE_NONE][$index]['value'];
      // Load the field collection with the ID from above.
      $entity = entity_load_single('field_collection_item', array($eid));
      // Wrap the loaded field collection which makes setting/getting much easier.
      $node_wrapper = entity_metadata_wrapper('field_collection_item', $entity);
      // Loop through our fields and set the values.
      foreach ($fields as $field => $data) {
        $node_wrapper->{$field}->set($data);
      }
      // Once we have added all the values we wish to change then we need to 
      // save. This will modify the node and does not require node_save() so
      // at this point be sure it is all correct as this will save directly
      // to a published node.
      $node_wrapper->save(true);
    }
  }

  /**
   * Prepare presave array for datestamp field.
   *   
   * @param array $value
   *   Field value.
   *
   * @return array
   *   return extracted value.
   */
  public function itg_save_field_datestamp($value) {
    $this->datestamp_arr = array();
    if (!empty($value['und'][0]['value']['date'])) {
      $this->datestamp_arr['value'] = strtotime($value['und'][0]['value']['date']);
      $this->datestamp_arr['value2'] = strtotime($value['und'][0]['value2']['date']);
    }

    return $this->datestamp_arr;
  }

  /**
   * Prepare presave array for datetime field.
   *
   * @param array $value
   *   Field value
   *
   * @return string
   *   Extracted value.
   */
  public function itg_save_field_datetime($value, $c_type = NULL) {
    if (empty($value['und'][0]['value']['date'])) {
      unset($value);
    }
    $this->datetime_result = '';
    if (!empty($value['und'][0]['value']['date'])) {
      if (!empty($value['und'][0]['value']['time'])) {
        $date_time = $value['und'][0]['value']['date'] . ' ' . $value['und'][0]['value']['time'];
        if ($c_type == 'event_backend') {
          $timestamp = strtotime(str_replace('/', '-', $date_time));
        } else {
          $timestamp = strtotime($date_time);
        }
      } else {
        $timestamp = strtotime(str_replace('/', '-', $value['und'][0]['value']['date']));
      }
      $this->datetime_result = array(
          'value' => date("Y-m-d H:i:s", $timestamp),
          'timezone' => date_default_timezone(),
          'timezone_db' => date_default_timezone(),
      );
    }

    return $this->datetime_result;
  }

  /**
   * Prepare presave array for long text field.
   * 
   * @param array $value
   *   Field Value.
   *
   * @return string
   *   Extracted value.
   */
  public function itg_save_field_text_long($value) {
    if ($value['und'][0]['value'] != '' && isset($value['und'][0]['format'])) {
      $this->text_long['value'] = $value['und'][0]['value'];
      $this->text_long['format'] = $value['und'][0]['format'];
    } else {
      $this->text_long['value'] = $value['und'][0]['value'];
    }

    return $this->text_long;
  }

  /**
   * Prepare presave array for image field.
   *
   * @param array $value
   *   Array of field value.
   *
   * @return string
   *   Extracted value.
   */
  public function itg_save_field_text_with_summary($value) {
    $this->text_with_summary = array();
    $this->text_with_summary['value'] = $value['und'][0]['value'];
    $this->text_with_summary['format'] = $value['und'][0]['format'];

    return $this->text_with_summary;
  }

  /**
   * Prepare presave array for list text field.
   *
   * @param array $value
   *   Field value.
   *
   * @return string
   *   Extracted value.
   */
  public function itg_save_field_list_text($value) {
    $this->list_text = '';
    $this->list_text = $value['und'];

    return $this->list_text;
  }

  /**
   * Save unique id associated with node id.
   *
   * @global stdObject $user
   *   Global user variable for user information.
   * @param array $pre_save
   *   Array of unique key and all field collections ids.
   * @param int $nid
   *   Mode id of the node.
   * @param string $c_type
   *   name of the content type.
   */
  public function itg_save_form_data($pre_save, $nid, $c_type) {
    global $user;
    $this->data = 0;
    // Check if unique id is already in database
    $this->dup_query = db_select('itg_autosave_node_data', 'itg');
    $this->dup_query->condition('itg_identity', $pre_save['unique_id']);
    $this->dup_query->fields('itg', array('itg_identity'));
    $this->dup_result = $this->dup_query->execute()->fetchField();
    // If unique id is not exist then insert. 
    if ($this->dup_result !== $pre_save['unique_id']) {
      $this->pre_save_form = array(
          'nid' => $nid,
          'username' => $user->name,
          'node_type' => $c_type,
          'created' => REQUEST_TIME,
          'itg_identity' => $pre_save['unique_id'],
          'field_collection' => isset($pre_save['field_collection']) ? $pre_save['field_collection'] : '',
          'lock_status' => 0,
      );
      $this->data = drupal_write_record('itg_autosave_node_data', $this->pre_save_form);
    } else {
      $this->pre_save_form['field_collection'] = isset($pre_save['field_collection']) ? count($pre_save['field_collection']) > 0 ? serialize($pre_save['field_collection']) : array('empty')  : array('empty');
      $this->data = db_update('itg_autosave_node_data');
      $this->data->fields($this->pre_save_form);
      $this->data->condition('itg_identity', $pre_save['unique_id']);
      $this->data->execute();
      $this->data = 0;
    }
    // Print status of the insert or update. 1 means insert and 0 means update.
    print $this->data;
  }

  /**
   * Validate field collection values before entity create.
   *
   * @param array $data
   *   Array of collection fields with name and field type.   
   * @param array $field_value
   *   Values of collections fields
   *
   * @return bool
   *   Return true if filed is not empty else return false.
   */
  public function itg_save_validate_field_collection($data, $field_values) {
    foreach ($data as $value) {
      switch ($value['fieldType']) {
        case 'taxonomy_term_reference':
          if (is_int($field_values[$value['fieldName']]['und'])) {
            return TRUE;
          }
          break;

        case 'text_long':
          if ($field_values[$value['fieldName']]['und'][0]['value'] != '') {
            return TRUE;
          }
          break;
        case 'text_with_summary':
          if ($field_values[$value['fieldName']]['und'][0]['value'] != '') {
            return TRUE;
          }
          break;

        case 'list_text':
          if (is_array($field_values[$value['fieldName']]['und'])) {
            return TRUE;
          }
          break;

        case 'text':
          if ($field_values[$value['fieldName']]['und'][0]['value'] != '') {
            return TRUE;
          }
          break;
        case 'file':
          if ($field_values[$value['fieldName']]['und'][0]['fid'] > 0) {
            return TRUE;
          }
          break;
        case 'images':
          if ($field_values[$value['fieldName']]['und'][0]['fid'] > 0) {
            return TRUE;
          }
          break;
        case 'image':
          if ($field_values[$value['fieldName']]['und'][0]['fid'] > 0) {
            return TRUE;
          }
          break;
        case 'list_integer':
          if ($field_values[$value['fieldName']]['und'] > 0) {
            return TRUE;
          }
          break;

        case 'list_float':
          if ($field_values[$value['fieldName']]['und'] > 0) {
            return TRUE;
          }
          break;
      }
    }

    return FALSE;
  }

  /**
   * Prepare presave array for all fields.
   *
   * @param array $data
   *   Array containing field name and field type.
   * @param array $inputs
   *   Submitted form data in aarray format.
   * @param stdObject $node
   *   Node object which will be saved.   
   *
   * @return array
   */
  public function itg_autosave_prepare_presave($data, $inputs, &$node) {
    $this->temp = array();
    foreach ($data as $field) {
      switch ($field['fieldType']) {
        case 'datestamp':
          $node->{$field['fieldName']}['und'][0] = $this->itg_save_field_datestamp($inputs[$field['fieldName']]);
          break;

        case 'datetime':
          $node->{$field['fieldName']}['und'][0] = $this->itg_save_field_datetime($inputs[$field['fieldName']], $node->type);
          break;

        case 'text':
          if (is_array($inputs[$field['fieldName']]['und']) && count($inputs[$field['fieldName']]['und']) > 0) {
            foreach ($inputs[$field['fieldName']]['und'] as $key => $value) {
              if ($value['value'] != '') {
                $node->{$field['fieldName']}['und'][$key]['value'] = $value['value'];
              }
            }
          } else {
            $node->{$field['fieldName']}['und'][0]['value'] = $this->itg_save_field_text($inputs[$field['fieldName']]);
          }
          break;

        case 'taxonomy_term_reference':
          $this->value = $inputs[$field['fieldName']]['und'];
          /* $this->var_type = gettype($this->value);
            if ($this->var_type == 'string') {
            $this->value = (int) $this->value;
            } */

          // For Mega Review Type autosave
          if (!empty($this->value) && $field['fieldName'] == 'field_mega_review_type') {
            $node->{$field['fieldName']}[$node->language][0]['tid'] = $this->value;
          }

          // For City autosave
          if (!empty($this->value) && $field['fieldName'] == 'field_stroy_city') {
            $getcity = $this->itg_autosave_get_citytids($this->value);
            if (isset($getcity) && !empty($getcity)) {
              foreach ($getcity as $city_key => $city_val) {
                $node->{$field['fieldName']}[$node->language][$city_key]['tid'] = $city_val->tid;
              }
            }
          }

          // For Bloggers autosave
          if (!empty($this->value) && $field['fieldName'] == 'field_blog_bloggers') {
            $getblogger = $this->itg_autosave_get_bloggertids($this->value);
            if (isset($getblogger) && !empty($getblogger)) {
              foreach ($getblogger as $blogger_key => $blogger_val) {
                $node->{$field['fieldName']}[$node->language][$blogger_key]['tid'] = $blogger_val->tid;
              }
            }
          }

          // For Tags Autosave
          if (!empty($this->value) && is_array($this->value) && $field['fieldName'] == 'field_story_itg_tags') {
            $get_tids = $this->itg_autosave_get_tids($this->value['value_field']);
            if (!empty($get_tids) && is_array($get_tids)) {
              foreach ($get_tids as $tid_key => $tid_val) {
                if (isset($tid_val->tid) && !empty($tid_val->tid)) {
                  $node->{$field['fieldName']}[$node->language][$tid_key]['tid'] = $tid_val->tid;
                }
              }
            }
          }

          // For section and primary category
          if (!empty($this->value) && is_array($this->value) && $field['fieldName'] == 'field_story_category') {
            foreach ($this->value as $sc_key => $sc_val) {
              $node->{$field['fieldName']}[$node->language][$sc_key]['tid'] = $sc_val;
            }
          }
          break;

        case 'field_collection':
          // Save field name of field collection to array.
          $this->temp[] = $field['fieldName'];
          break;

        case 'text_long':
          $this->value = $this->itg_save_field_text_long($inputs[$field['fieldName']]);
          if (count($this->value) > 0) {
            $node->{$field['fieldName']}[$node->language][0] = $this->value;
          }
          break;

        case 'text_with_summary':
          $node->{$field['fieldName']}[$node->language][0] = $this->itg_save_field_text_with_summary($inputs[$field['fieldName']]);
          break;

        case 'list_text':
          $this->flag = 0;
          if (count($inputs[$field['fieldName']]['und']) >= 2) {
            foreach ($inputs[$field['fieldName']]['und'] as $list_value) {
              $node->{$field['fieldName']}['und'][$this->flag]['value'] = $list_value;
              ++$this->flag;
            }
          } else {
            $node->{$field['fieldName']}['und'][0]['value'] = $this->itg_save_field_list_text($inputs[$field['fieldName']]);
          }
          break;

        case 'list_float':
          if ($inputs[$field['fieldName']]['und'] != '_none') {
            $node->{$field['fieldName']}['und'][0]['value'] = $inputs[$field['fieldName']]['und'];
          }

          break;

        case 'number_integer':
          $tickets = $inputs[$field['fieldName']]['und'][0]['value'];
          if (isset($tickets) && !empty($tickets)) {
            $node->{$field['fieldName']}['und'][0]['value'] = $tickets;
          }
          break;

        case 'entityreference':
          if ($field['fieldName'] == 'field_video_anchor') {
            $this->value = $inputs[$field['fieldName']]['und'];
            if (!empty($this->value) && is_array($this->value)) {
              foreach ($this->value as $anchor_key => $anchor_val) {
                preg_match_all('!\d+!', $anchor_val['target_id'], $matches);
                $targetids = reset($matches);
                if (isset($targetids[0]) && !empty($targetids[0])) {
                  $node->{$field['fieldName']}['und'][$anchor_key]['target_id'] = $targetids[0];
                }
              }
            }
          } elseif ($inputs['form_id'] == 'story_node_form' ||
                  $inputs['form_id'] == 'videogallery_node_form' ||
                  $inputs['form_id'] == 'survey_node_form' ||
                  $inputs['form_id'] == 'quiz_node_form' && $field['fieldName'] == 'field_story_reporter') {
            $this->value = $inputs[$field['fieldName']]['und'];
            if (isset($this->value[0]['target_id']) && !empty($this->value[0]['target_id'])) {
              preg_match_all('!\d+!', $this->value[0]['target_id'], $matches);
              $targetid = reset($matches);
              if (isset($targetid[0]) && !empty($targetid[0])) {  
                $node->{$field['fieldName']}['und'][0]['target_id'] = $targetid[0];
              }
            } 
          } else {
            $this->value = $inputs[$field['fieldName']]['und'];
            preg_match_all('!\d+!', $this->value, $matches);
            $targetid = reset($matches);
            if (isset($targetid[0]) && !empty($targetid[0])) {
              $i = 0;
              foreach ($targetid as $target_val) {
                $node->{$field['fieldName']}['und'][$i]['target_id'] = $target_val;
                $i++;
              }
            } 
          }
          break;

        case 'image':
          $this->itg_save_field_image($field['fieldName'], $inputs[$field['fieldName']], $node);

          break;

        case 'file':
          $this->itg_save_field_file($field['fieldName'], $inputs[$field['fieldName']], $node);
          break;

        case 'list_integer':
          if ($field['fieldName'] == 'field_survey_expity_date') {
            $node->{$field['fieldName']}['und'][0]['value'] = $inputs[$field['fieldName']]['und'][1];
          } else {
            $this->value = $inputs[$field['fieldName']]['und'];
            if (isset($this->value) && !empty($this->value)) {
              preg_match_all('!\d+!', $this->value, $matches);
              $get_techrating = reset($matches);
              $node->{$field['fieldName']}['und'][0]['value'] = $get_techrating[0];
            }
          }

          break;

        case 'youtube':
          $this->value = $inputs[$field['fieldName']]['und'];
          if (isset($this->value) && !empty($this->value)) {
            $node->{$field['fieldName']}['und'][0]['input'] = $this->value[0]['input'];
          }
          break;
      }
    }

    return $this->temp;
  }

  /**
   * Prepare node object for image field.
   *
   * @param string $field_name
   *   Machine name of the field.
   * @param array $inputs
   *   Form submitted data for current field.
   * @param type $node
   *   Node object.
   */
  public function itg_save_field_image($field_name, $inputs, &$node) {
    // Assign fid to field.
    if ($inputs[$node->language][0]['fid'] > 0) {
      $node->{$field_name}[$node->language][0]['fid'] = $inputs[$node->language][0]['fid'];
    }
    // Assign alternative text.
    if ($inputs[$node->language][0]['alt'] != '') {
      $node->{$field_name}[$node->language][0]['alt'] = $inputs[$node->language][0]['alt'];
    }
    // Assign title text.
    if ($inputs[$node->language][0]['title'] != '') {
      $node->{$field_name}[$node->language][0]['title'] = $inputs[$node->language][0]['title'];
    }
    // Assign display mode.
    if ($inputs[$node->language][0]['display'] != '') {
      $node->{$field_name}[$node->language][0]['display'] = $inputs[$node->language][0]['display'];
    }
  }

  /**
   * Create field collection items.
   *
   * @param array $data
   *   Array of fields with name and type.
   * @param array $inputs
   *   Array of submitted form values.   
   * @param type $fc_item
   *   Field collection entity object.
   */
  public function itg_save_field_collection($data, $inputs, &$fc_item) {

    foreach ($data as $field) {
      switch ($field['fieldType']) {
        case 'datestamp':

          break;

        case 'datetime':

          break;

        case 'text':
          if ($field['fieldName'] == 'field_survey_answer_option_2') {
            $opt2 = $inputs[$field['fieldName']]['und'];
            foreach ($opt2 as $opt2_key => $opt2_val) {
              $fc_item->{$field['fieldName']}[LANGUAGE_NONE][$opt2_key]['value'] = $opt2_val['value'];
            }
          } else {
            $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $inputs[$field['fieldName']]['und'][0]['value'];
          }
          break;

        case 'taxonomy_term_reference':
          $this->value = $inputs[$field['fieldName']]['und'];
          $this->value = (int) $this->value;
          if ($this->value > 0) {
            $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['tid'] = $this->value;
          }

          break;

        case 'text_long':
          $this->value = $this->itg_save_field_text_long($inputs[$field['fieldName']]);
          $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0] = $this->value;
          break;

        case 'number_integer':
          if (!empty($inputs[$field['fieldName']]['und']) && is_array($inputs[$field['fieldName']]['und'])) {
            $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $inputs[$field['fieldName']]['und'][0]['value'];
          }
          break;

        case 'text_with_summary':
          $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $inputs[$field['fieldName']][LANGUAGE_NONE][0]['value'];
          break;

        case 'list_text':
          $this->value = $inputs[$field['fieldName']]['und'];
          if (is_array($this->value)) {
            foreach ($this->value as $f_value) {
              $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $f_value;
            }
          } else {
            $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $this->value;
          }
          break;

        case 'jquery_colorpicker':
          $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['jquery_colorpicker'] = $inputs[$field['fieldName']]['und'][0]['jquery_colorpicker'];
          break;

        case 'file':
          $this->value = $inputs[$field['fieldName']]['und'][0];
          $this->itg_save_file_field_collection($fc_item, $this->value, $field['fieldName']);
          break;

        case 'image':
          $this->value = $inputs[$field['fieldName']]['und'][0];
          $this->itg_save_file_field_collection($fc_item, $this->value, $field['fieldName']);
          break;

        case 'list_integer':
          $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $inputs[$field['fieldName']]['und'];
          break;

        case 'list_float':
          $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['value'] = $inputs[$field['fieldName']]['und'];
          break;

        case 'entityreference':
          $this->value = $inputs[$field['fieldName']]['und'][0]['target_id'];
          $this->value = explode(')', end(explode("(", $this->value)));
          if (count($this->value) > 0) {
            $this->value = (int) $this->value[0];
          } else {
            $this->value = 0;
          }
          if ($this->value > 0) {
            $fc_item->{$field['fieldName']}[LANGUAGE_NONE][0]['target_id'] = $this->value;
          }
      }
    }
  }

  /**
   * Prepare file field for field collection.
   * 
   * @param stdObject $fc_item
   *   Field collection item object.
   * @param array $field_value
   *   Value of file field.
   * @param string $field_name
   *   Machine name of the current field.
   */
  public function itg_save_file_field_collection(&$fc_item, $field_value, $field_name) {
    if ($field_value['fid'] > 0) {
      $fc_item->{$field_name}[LANGUAGE_NONE][0]['fid'] = $field_value['fid'];
    }
    if ($field_value['description'] != '') {
      $fc_item->{$field_name}[LANGUAGE_NONE][0]['description'] = $field_value['description'];
    }
    if ($field_value['display'] != '') {
      $fc_item->{$field_name}[LANGUAGE_NONE][0]['display'] = $field_value['display'];
    }
  }

  /**
   * Remove field collection values based on other input.
   *
   * @param string $c_type
   *   Name of the content type.
   * @param type $inputs
   *   Submitted form values.
   */
  public function itg_save_remove_fcollection($c_type, &$inputs) {
    switch ($c_type) {
      case 'astro':
        if ($inputs['field_astro_type']['und'] == 224) {
          unset($inputs['field_astro_numerology_values']);
          unset($inputs['field_astro_zodiac']);
        } elseif ($inputs['field_astro_type']['und'] == 225) {
          unset($inputs['field_astro_zodiac']);
        } elseif ($inputs['field_astro_type']['und'] == 227) {
          unset($inputs['field_astro_numerology_values']);
        } else {
          unset($inputs['field_astro_numerology_values']);
          unset($inputs['field_astro_zodiac']);
        }
        break;
    }
  }

  /**
   * Get saved form ids from database.
   *
   * @return array
   *   Array of form ids for autosave.
   */
  public function itg_save_get_form_ids() {
    $this->data = array();
    $this->itg_query = db_select('itg_autosave_forms', 'itg');
    $this->itg_query->fields('itg', array('form_name'));
    $this->itg_result = $this->itg_query->execute()->fetchAll();

    // Make array of form ids from result object
    foreach ($this->itg_result as $ids) {
      $this->data[] = $ids->form_name;
    }

    return $this->data;
  }

  /**
   * Get Node Lock status for autosave.
   *
   * @param type $nid
   *   node id.
   *
   * @return int
   *   Node id of the node.
   */
  public function itg_autosave_get_lock_status_node_id($nid) {
    $itg_query = db_select('itg_autosave_node_data', 'itg');
    $itg_query->fields('itg', array('nid', 'lock_status'))
            ->condition('nid', $nid);
    $itg_result = $itg_query->execute()->fetchObject();
    return $itg_result;
  }

  /**
   * Get tid's from database.
   *
   * @return array
   *   Array of term ids for tags autosave.
   */
  public function itg_autosave_get_tids($arr_name) {
    $get_name = explode("\"\"", $arr_name);
    $trimmed_array = array_map('trim',$get_name);
    $term_names = array_filter($trimmed_array);
    if (!empty($term_names) && is_array($term_names)) {
      // List All the similer term_name
      $term_name_cr = db_select('taxonomy_term_data', 'ttd');
      $term_name_cr->fields('ttd', array('name'));
      $term_name_cr->condition('vid', 1, '=');
      $term_name_cr->condition('name', $term_names, 'IN');
      $result_cr = $term_name_cr->execute()->fetchAll();
      foreach ($result_cr as $tn) {
        $names_cr[] = $tn->name;
      }
      if (!empty($names_cr)) {
        // Get the diff from inserted and existing
        $new_tname = array_diff($term_names, $names_cr);
      } else {
        $new_tname = $term_names;
      }
      if (!empty($new_tname) && is_array($new_tname)) {
        // Creating new term_name from diff
        foreach ($new_tname as $new_tname_data) {
          $term = new stdClass();
          $term->name = $new_tname_data;
          $term->vid = 1;
          try {
            taxonomy_term_save($term);
          } catch (Exception $e) {
            pr($e->getMessage());
          }
        }
      }
      // Get the tids from all the term_name
      $term_name = db_select('taxonomy_term_data', 'ttd');
      $term_name->fields('ttd', array('tid'));
      $term_name->condition('name', $term_names, 'IN');
      $term_name->condition('vid', 1, '=');
      $result = $term_name->execute()->fetchAll();
      return $result;
    }
  }

  /**
   * Get tid's for city from database.
   *
   * @return array
   *   Array of term ids for city autosave.
   */
  public function itg_autosave_get_citytids($city_name) {
    $cityname = explode(", ", $city_name);
    $term_name = db_select('taxonomy_term_data', 'ttd');
    $term_name->fields('ttd', array('tid'));
    $term_name->condition('name', $cityname, 'IN');
    $term_name->condition('vid', 9, '=');
    $result = $term_name->execute()->fetchAll();
    return $result;
  }

  /**
   * Get tid's for blogger from database.
   *
   * @return array
   *   Array of term ids for blogger name for autosave.
   */
  public function itg_autosave_get_bloggertids($blogger_name) {
    $bloggername = explode(", ", $blogger_name);
    $term_name = db_select('taxonomy_term_data', 'ttd');
    $term_name->fields('ttd', array('tid'));
    $term_name->condition('name', $bloggername, 'IN');
    $term_name->condition('vid', 19, '=');
    $result = $term_name->execute()->fetchAll();
    return $result;
  }

}
