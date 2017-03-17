<?php
function itg_bestcollege_csv_import() {

  $form = drupal_get_form('itg_bestcollege_csv_form');

  $output = "<p>This tool will attempt to import CSV data";
  $output .= drupal_render($form);

  return $output;
}

/**
 * csvImporter form
 * @return string
 */
function itg_bestcollege_csv_form() {

  $form['#attributes'] = array(
    'enctype' => 'multipart/form-data'
  );

  $form['csvfile'] = array(
    '#title' => t('CSV File'),
    '#type' => 'file',
    '#description' => ($max_size = parse_size(ini_get('upload_max_filesize'))) ? t('Due to server restrictions, the <strong>maximum upload file size is !max_size</strong>. Files that exceed this size will be disregarded.', array('!max_size' => format_size($max_size))) : '',
      );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Commence Import'),
      );
  $form['#validate'] = array(
    'itg_bestcollege_validate_file_upload',
    'itg_bestcollege_form_validate',
      );
  return $form;
}
/**
 * Validate csvImporter CSV File.
 * @param array $form
 * @param array $form_state
 */
function itg_bestcollege_validate_file_upload(&$form, &$form_state) {
  $validators = array(
    'file_validate_extensions' => array('csv'),
  );

  if ($file = file_save_upload('csvfile', $validators, "public://", FILE_EXISTS_REPLACE)) {
    $form_state['values']['csvupload'] = $file->destination;
  }
  else {
    form_set_error('csvImporter', t('Unable to copy upload file to !dest', array('!dest' => $destination)));
  }
}

/**
 * Validate csvImporter Form.
 * @param array $form
 * @param array $form_state
 */
function itg_bestcollege_form_validate(&$form, &$form_state) {
  if (isset($form_state['values']['csvupload'])) {
    if ($handle = fopen($form_state['values']['csvupload'], 'r')) {
      $line_count = 1;
      $first = TRUE;
      if ($line = fgetcsv($handle, 4096)) {
        // pr($line);
        // exit;
        // print count($line);
        //-------------------------------------------------------------------------------------------|
        //  This is where you can validate aspects of the file itself, like the number of columns
        //-------------------------------------------------------------------------------------------|
        if (count($line) != 15) {
          form_set_error('csvfile', t('This file has the incorrect number of columns. Expecting 14'));
        }
        //-------------------------------------------------------------------------------------------|
        //  End validating aspects of the CSV file
        //-------------------------------------------------------------------------------------------|
      }
      fclose($handle);
    }
    else {
      form_set_error('csvfile', t('Unable to read uploaded file !filepath', array('!filepath' => $form_state['values']['csvupload'])));
    }
  }
}

/**
 * Submit csvImporter Form.
 * @param array $form
 * @param array $form_state
 */
function itg_bestcollege_csv_form_submit(&$form, &$form_state) {
  $batch = array(
    'title' => t('Importing CSV for best college...'),
    'operations' => array(),
    'init_message' => t('Commencing'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('An error occurred during processing'),
    'finished' => 'itg_bestcollege_import_finished',
      );
  if (isset($form_state['values']['csvupload'])) {
    if ($handle = fopen($form_state['values']['csvupload'], 'r')) {
      $batch['operations'][] = array('_itg_bestcollege_remember_filename', array($form_state['values']['csvupload']));
      $line_count = 1;
      $first = TRUE;
      $line = fgetcsv($handle, 4096);
      while ($line = fgetcsv($handle, 4096)) {
        /**
         * we use base64_encode to ensure we don't overload the batch
         * processor by stuffing complex objects into it
         */
        $batch['operations'][] = array('_itg_bestcollege_import_line', array(array_map('base64_encode', $line)));
      }
      fclose($handle);
    } // we caught this in csvImporter_form_validate()
  } // we caught this in csvImporter_form_validate()
  batch_set($batch);
}

/**
 *
 * @param type $success
 * @param type $results
 * @param type $operations
 * @return type
 */
function itg_bestcollege_import_finished($success, $results, $operations) {
  if (!empty($results['failed_rows'])) {
    $dir = file_directory_path() . '/csvImporter/';
    if (file_check_directory($dir, FILE_CREATE_DIRECTORY)) {
      $csv_filename = 'failed_rows-' . basename($results['uploaded_filename']); // we validated extension on upload
      $csv_filepath = $dir . '/' . $csv_filename;
      $targs = array(
        '!csv_url' => l(check_plain($csv_filename), $csv_filepath),
        '%csv_filename' => $csv_filename,
        '%csv_filepath' => $csv_filepath,
          );
      if ($handle = fopen($csv_filepath, 'w+')) {
        foreach ($results['failed_rows'] as $failed_row) {
          fputcsv($handle, $failed_row);
        }
        fclose($handle);
        drupal_set_message(t('Some rows failed to import. You may download a CSV of these rows: !csv_url', $targs), 'error');
      }
      else {
        drupal_set_message(t('Some rows failed to import, but unable to write error CSV to %csv_filepath', $targs), 'error');
      }
    }
    else {
      drupal_set_message(t('Some rows failed to import, but unable to create directory for error CSV at %csv_directory', $targs), 'error');
    }
  }
  return t('The CSV import has completed.');
}

/**
 *
 * @param type $filename
 * @param array $context
 */
function _itg_bestcollege_remember_filename($filename, &$context) {
  $context['results']['uploaded_filename'] = $filename;
}

/**
 *
 * @param type $line
 * @param type $session_nid
 * @param type $context
 */
function _itg_bestcollege_import_line($line, $session_nid, &$context) {

  $context['results']['rows_imported'] ++;
  $line = $cleaned_line = array_map('base64_decode', $line);

  //pr($line);
  //$collegename    = $line[0];
  $collegeid = $line[1];
  $collegename = $line[2];
  $city = $line[3];
  $description = $line[4];
  $image = $line[5];
  $websiteurl = $line[6];
  $storyids = $line[7];
  $photoids = $line[8];
  $videoids = $line[9];
  $published = $line[10];
  $created_date = $line[11];
  $year = $line[12];
  $rank = $line[13];
  $stream = $line[14];


  $node = new stdClass();
  $node->title = $collegename;
  $node->type = "bestcolleges";

  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
  //node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().

  $node->field_bestcollege_city[LANGUAGE_NONE][0]['value'] = $city;
  $node->body[LANGUAGE_NONE][0]['value'] = $description;
  //$node->field_story_extra_large_image = $image;
  $node->field_bestcollege_website_url[LANGUAGE_NONE][0]['value'] = $websiteurl;
  $node->field_bestcollege_related_story[LANGUAGE_NONE][0]['value'] = $storyids;
  $node->field_bestcollege_related_photo[LANGUAGE_NONE][0]['value'] = $photoids;
  $node->field_bestcollege_related_video[LANGUAGE_NONE][0]['value'] = $videoids;
  $node->field_bestcollege_rank[LANGUAGE_NONE][0]['value'] = $rank;
  $node->field_bestcollege_year[LANGUAGE_NONE][0]['value'] = $year;
  $node->field_college_id[LANGUAGE_NONE][0]['value'] = $collegeid;

  // print "year = ".$year;
  if ($year) {
    if ($year == '2016') {
      $tid = '787';
      if ($stream == 'Education') {
        $stream = 'education1';
      }

      if ($stream == 'Fine Arts') {
        $stream = 'Fine-Arts';
      }
      if ($stream == 'Hotel Management') {
        $stream = 'Hotel-Management';
      }
      if ($stream == 'Mass Comm') {
        $stream = 'Mass-Comm';
      }

      $final_tid = itg_bestcollege_get_term_tid($tid, $stream);
    }
  }

  // Term reference (taxonomy) field
  if (!empty($final_tid)) {
    $node->field_story_category[LANGUAGE_NONE][]['tid'] = $final_tid;
  }


  // watchdog("test arun@", '<pre>'. print_r($node, TRUE) .'</pre>');
  // watchdog("test arun line@", '<pre>'. print_r($line, TRUE) .'</pre>');

  $url = $image; //'https://ssl.gstatic.com/gb/images/k1_a31af7ac.png';
  //I have used picture folder to store images using image field settings
  $file_info = system_retrieve_file($url, 'public://migrate/', TRUE);
  if ($file_info->fid) {
    $node->field_story_extra_large_image[LANGUAGE_NONE]['0']['fid'] = $file_info->fid; //assign fid
  }

  $node->uid = 3;
  $node->status = 1; //(1 or 0): published or not
  if (!empty($final_tid)) {

    if ($node = node_submit($node)) {
      node_save($node);
      drupal_set_message('submitted successfully');

      $num_updated = db_update('bestcolleges_master')
          ->fields(array('node_id' => $node->nid))
          ->condition('collegeid', $collegeid)
          ->execute();
      // bestcolleges_ranking
      db_update('bestcolleges_ranking')
          ->fields(array('CollegeNewNid' => $node->nid))
          ->condition('collegeid', $collegeid)
          ->condition('year', $year)
          ->execute();
      // bestcolleges_themebasedranking
      $num_updated = db_update('bestcolleges_themebasedranking')
          ->fields(array('CollegeNewNid' => $node->nid))
          ->condition('collegeid', $collegeid)
          ->condition('year', $year)
          ->execute();

      // bestcolleges_emergingranking
      $num_updated = db_update('bestcolleges_emergingranking')
          ->fields(array('CollegeNewNid' => $node->nid))
          ->condition('collegeid', $collegeid)
          ->condition('year', $year)
          ->execute();
    }

    drupal_set_message("Pass line {$line[0]} college id = {$collegeid}");
  }
  else {
    drupal_set_message("Fail line {$line[0]} college id = {$collegeid}");

    drupal_set_message("Fail line {$line[0]} stream for {$stream}");
  }
}

?>
