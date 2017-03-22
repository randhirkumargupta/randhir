<?php

/**
 * @file
 *   This file contains report dashboard logic and implementation.
 */

/**
 * Implments callback function for "itg-report-dashboard".
 *
 * @return
 *   Themed html output.
 */
function itg_report_user_dashboard() {
  $data = array();
  $user_menu_tree = menu_tree_all_data('menu-itg-reports');
  foreach ($user_menu_tree as $key_tree => $val_tree) {
    if (empty($val_tree['below'])) {
      $menu_link[$val_tree['link']['link_path']] = t($val_tree['link']['link_title']);
    }
    else {
      foreach ($val_tree['below'] as $key => $val) {
        $menu_link[$val['link']['link_path']] = t($val['link']['link_title']);
      }
    }
  }
  $data['user_link'] = $menu_link;

  return theme('itg_reports_dashboard', array('data' => $data));
}

/**
 * Implements callback function for email auto complete widget.
 *
 * @param string $string'
 *   String for auto complete search.
 */
function itg_reports_email_autocomplete($string) {
  $itg_query = db_select('users', 'u')
      ->fields('u', array('mail'))
      ->condition('mail', '%' . db_like($string) . '%', 'LIKE');
  $itg_result = $itg_query->execute()->fetchAll();
  $result = array();
  $errors = array_filter($itg_result);
  if (!empty($errors)) {
    foreach ($itg_result as $value) {
      $result[$value->mail] = $value->mail;
    }
  }

  return drupal_json_output($result);
}

function itg_registered_user_report($user_id) {
  if(isset($_GET['dispaly_report']) && $_GET['dispaly_report'] == 'true') {
    itg_registered_user_display_report($user_id);
  }
  else {
    drupal_add_js(drupal_get_path('module', 'itg_reports') . '/js/itg_reports.js', array('type' => 'file'));
    return drupal_get_form('itg_registred_user_report_form');
  }
}

function itg_registred_user_report_form($form , $form_state) {
  // Add date/time field with Pop-up calendar to the form.
  $form['markup'] = array(
    '#markup' => t("Please select date from and to for display report"),
  );
  $form['date_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Date from'),
  );
  $form['date_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Date to'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function itg_registred_user_report_form_submit($form , $form_state) {
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  $path = "itg-registered-user-report/". arg(1);
  $options = array(
    'query' => array(
      'report_type' => $_GET['report_type'],
      'width' => $_GET['width'],
      'height' => $_GET['height'],
      'iframe' => $_GET['iframe'],
      'dispaly_report' => 'true',
      'date_from' => strtotime($date_from. "00:00:00"),
      'date_to' => strtotime($date_to. "00:00:00"),
    ),
  );
  drupal_goto($path, $options);
}

function itg_registered_user_display_report($user_id) {
  $report_display = FALSE;
  if(isset($_GET['date_from']) && isset($_GET['date_to']) && !empty($_GET['date_from']) && !empty($_GET['date_to'])) {
    $report_display = TRUE;
  }
  if($report_display) {
    $data = array();
    $nodes_under_section = array();
    $node_under_section_visited = array();
    $visited_nodes_array = array();
    //Get user specific taxonomies.
    $query = db_select('itg_widget_order','iwo');
    $query->fields('iwo',array('nid'));
    $query->condition('iwo.widget' , 'personalization_widget');
    $query->condition('iwo.extra' , $user_id);
    $result = $query->execute()->fetchAllAssoc('nid');
    $personalized_taxonomy = array_keys($result);

    // Get nodes which use is visited.
    if (function_exists('mongodb')) {
      $con = mongodb();
      $people = $con->pagedetails;
      $date_from = $_GET['date_from'];
      $date_to = strtotime('+1 day', $_GET['date_to']);
      $condition = array(
        'viewtime' => array('$gte' => (int) $date_from, '$lte' => (int) $date_to),
        'uid' => $user_id,
        );
      $views_nodes = $people->find($condition);
      foreach ($views_nodes as $chunk_data) {
        $data[] = $chunk_data['nid'];
      }
      
      $visited_nodes_array = array_unique($data);
      $total_visted_node_by_user = count($visited_nodes_array);

      if(empty($personalized_taxonomy)) {
        $nodes_under_section = array();
      }
      else {
        // Get all nodes which are under user personalization sections.
        foreach($personalized_taxonomy as $section_tid) {
          $query = db_select('node','n');
          $query->leftJoin('field_data_field_story_category', 'sc' ,'sc.entity_id=n.nid');
          $query->fields('n' , array('nid'));
          $query->fields('sc',array('field_story_category_tid'));
          $query->condition('sc.field_story_category_tid' , $section_tid);
          $query->condition('n.status',1);
          $nodes_under_section = $query->execute()->fetchAllAssoc('nid');
        }
      }

      $nodes_under_section_visited = array_unique(array_keys($nodes_under_section));
      // Get only nodes which are other then personalize section.
      $nodes_visited_by_user_other_than_personalize_section = array_diff($visited_nodes_array, $nodes_under_section_visited);
      $node_visied_by_user_under_his_personalize_section = array_diff($visited_nodes_array, $nodes_visited_by_user_other_than_personalize_section);


      //Calculate percertage for personalize graph.
      //$total_node_visted =  count($visited_nodes_array);
      $total_section_node_visited = count($node_visied_by_user_under_his_personalize_section);
      $total_other_node_visited = count($nodes_visited_by_user_other_than_personalize_section);
      //$section_node_percentage = ($total_section_node_visited/$total_node_visted)*100;
      //$other_node_percentage = 100-$section_node_percentage;
      // END.

      if(!empty($visited_nodes_array)) {
        // Query to get section of nodes which usesr visited
        $category_query = db_select('field_data_field_story_category' ,'fc');
        $category_query->fields('fc' , array('entity_id','field_story_category_tid'));

        $or = db_or();
        foreach ($visited_nodes_array as $nid) {
          $or->condition('fc.entity_id' , $nid , '=');
        }
        $category_query->condition($or);
        $category_wise_result = $category_query->execute()->fetchAll(PDO::FETCH_ASSOC);
        //END
      }

      if(!empty($category_wise_result)) {
        // Calculation for user visted nodes under section.
        foreach($category_wise_result as $node_details) {
          $node_under_section_visited[$node_details['field_story_category_tid']] += count($node_under_section_visited[$node_details['field_story_category_tid']]); 
        }
      }


      // Chart to display nodes viewed by users.
      if($_GET['report_type'] == 'personalized') {
        if(!$total_section_node_visited && !$total_other_node_visited) {
          print t("No data found");
          exit;
        }
        print '<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
        <script type="text/javascript">
          google.charts.load(\'current\', {\'packages\':[\'corechart\']});
          google.charts.setOnLoadCallback(drawChart);

          function drawChart() {

            var data = google.visualization.arrayToDataTable([
              [\''.t("Type of nodes").'\', \''.t("Visited per Day").'\'],
              [\''.t("Personalized Viewd Node").'\', '.$total_section_node_visited.'],
              [\''.t("Other Section Viewd Nodes").'\', '.$total_other_node_visited.']
            ]);

            var options = {
              title: \''.t("User Node Visit Activity").'\'
            };

            var chart = new google.visualization.PieChart(document.getElementById(\'piechart\'));

            chart.draw(data, options);
          }
        </script>
        <div id="piechart" style="width: 900px; height: 600px;"></div>';
      }

      else if($_GET['report_type'] == 'section_wise_report') {
        if(empty($node_under_section_visited)) {
          print t("No data found");
          exit;
        }
        print '<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
        <script type="text/javascript">
          google.charts.load(\'current\', {\'packages\':[\'corechart\']});
          google.charts.setOnLoadCallback(drawChart);

          function drawChart() {

          var data = google.visualization.arrayToDataTable([';
          print '[\''.t("Sections").'\', \''.t("Visited nodes").'\'],';
          //pr($node_under_section_visited);
          foreach($node_under_section_visited as $section => $count) {
            $total = $count+1;
            print '[\''.t(get_term_name_from_tid($section)->name).'\', '.$total.'],';
          }
          print ']);';
          print 'var options = {
              title: \''.t("Section Wise User Node Visit Activity").'\'
            };

            var chart = new google.visualization.PieChart(document.getElementById(\'piechart\'));

            chart.draw(data, options);
          }
        </script>
        <div id="piechart" style="width: 900px; height: 600px;"></div>';
      }
      else {
        print t("Please choose report type.");
      }
    }
  }
}
function get_term_name_from_tid($tid) {
  $data = array();
  $query = db_select('taxonomy_term_data' ,'ttd')
      ->fields('ttd' ,array('name'))
      ->condition('ttd.tid' ,$tid);
  return $query->execute()->fetchObject();
}