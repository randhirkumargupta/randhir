<?php

/**
 * @file
 *   This file contains report dashboard logic and implementation.
 */

/**
 * Implements callback function for "itg-report-dashboard".
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

  return theme('itg_reports_dashboard' , array('data' => $data));
}

/**
 * Implements callback function for email auto complete widget.
 *
 * @param string $string
 *   String for auto complete search.
 */
function itg_reports_email_autocomplete($string) {
  $itg_query = db_select('users' , 'u')
      ->fields('u' , array('mail'))
      ->condition('mail' , '%' . db_like($string) . '%' , 'LIKE');
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

/**
 * Function which returns registred users form.
 * @param int $user_id
 */
function itg_registered_user_report($user_id) {
  drupal_add_js(drupal_get_path('module' , 'itg_reports') . '/js/itg_reports.js' , array('type' => 'file'));
  return drupal_get_form('itg_registred_user_report_form');
}

/**
 * Second form which is resonsible to display report.
 * Implements Hook_form.
 * {@inheritdocs}
 */
function itg_registred_user_report_form($form , $form_state) {
  $report_data = "";

  // current date
  $sunday = date('d-m-Y');
  //Prev 6 days i.e. total 7 days including today.
  $monday = date('d-m-Y' , strtotime('-6days' , strtotime($sunday)));


  if (isset($_GET['dispaly_report']) && $_GET['dispaly_report'] == 'true') {
    $report_data .= itg_registered_user_display_report(arg(1));
  }
  // Add date/time field with Pop-up calendar to the form.
  $form['markup'] = array(
    '#markup' => t("<h2>Please select date from and to for display report</h2>") ,
  );
  $form['date_from'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date from') ,
    '#default_value' => (!empty($_GET['date_from'])) ? date('d-m-Y' , $_GET['date_from']) : $monday ,
  );
  $form['date_to'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date to') ,
    '#default_value' => (!empty($_GET['date_to'])) ? date('d-m-Y' , $_GET['date_to']) : $sunday ,
  );

  $form['submit'] = array(
    '#type' => 'submit' ,
    '#value' => t('Submit') ,
  );

  $form['reset'] = array(
    '#type' => 'markup' ,
    '#markup' => l('Reset' , 'itg-registered-user-section-wise-breakup/' . arg(1) , array('attributes' => array('class' => array('btn-reset')))) ,
  );

  $form['report_markup'] = array(
    '#type' => 'markup' ,
    '#markup' => $report_data ,
  );
  return $form;
}

/**
 * Implements Hook_form_validate.
 * {@inheritdocs}
 */
function itg_registred_user_report_form_validate($form , &$form_state) {
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  if (empty($date_from) || empty($date_to)) {
    form_set_error("date_from" , "Date to field can'tbe empty");
    //form_set_error("");
  }
  if (strtotime($date_to) < strtotime($date_from)) {
    form_set_error("date_from" , "Date to can't be less then date from.");
  }
}

/**
 * Implements Hook_form_submit.
 * {@inheritdocs}
 */
function itg_registred_user_report_form_submit($form , $form_state) {
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  $path = "itg-registered-user-report/" . arg(1);
  $options = array(
    'query' => array(
      'report_type' => $_GET['report_type'] ,
      'width' => $_GET['width'] ,
      'height' => $_GET['height'] ,
      'iframe' => $_GET['iframe'] ,
      'dispaly_report' => 'true' ,
      'date_from' => strtotime($date_from . "00:00:00") ,
      'date_to' => strtotime($date_to . "00:00:00") ,
    ) ,
  );
  drupal_goto($path , $options);
}

/**
 * Function which is used to display readers reports.
 * @param int $user_id
 * @return string
 */
function itg_registered_user_display_report($user_id) {
  $report_display = FALSE;
  if (isset($_GET['date_from']) && isset($_GET['date_to']) && !empty($_GET['date_from']) && !empty($_GET['date_to'])) {
    $report_display = TRUE;
  }
  if ($report_display) {
    $data = array();
    $views_nodes = array();
    $personalized_section = array();
    //Get user specific taxonomies.
    $query = db_select('itg_widget_order' , 'iwo');
    $query->fields('iwo' , array('nid'));
    $query->condition('iwo.widget' , 'personalization_widget');
    $query->condition('iwo.extra' , $user_id);
    $result = $query->execute()->fetchAllAssoc('nid');
    $personalized_taxonomy = array_keys($result);
    // Get data of personalized sections viewed Node.

    foreach ($personalized_taxonomy as $personalized_term) {
      // Get nodes which use is visited.
      if (function_exists('mongodb')) {
        $con = mongodb();
        $people = $con->pagedetails;
        // Handle case from current date.
        $date_from = strtotime('-1 day' , $_GET['date_from']);
        $date_to = strtotime('+1 day' , $_GET['date_to']);
        $condition = array(
          'viewtime' => array('$gte' => (int) $date_from , '$lte' => (int) $date_to) ,
          'uid' => $user_id ,
          'section' => (string) $personalized_term ,
        );
        $views_nodes['under_personalized_section'][$personalized_term] = $people->find($condition)->count();
      }
    }

    foreach ($personalized_taxonomy as $personalized_term) {
      $personalized_section[] = (string) $personalized_term;
    }

    //Get nodes which is not under personalized sections.
    if (function_exists('mongodb')) {
      $con = mongodb();
      $people = $con->pagedetails;
      // Handle case from current date.
      $date_from = strtotime('-1 day' , $_GET['date_from']);
      $date_to = strtotime('+1 day' , $_GET['date_to']);
      $condition = array(
        'viewtime' => array('$gte' => (int) $date_from , '$lte' => (int) $date_to) ,
        'uid' => $user_id ,
        'section' => array(
          '$nin' => $personalized_section ,
        ) ,
      );
      $result_data = $people->find($condition);

      foreach ($result_data as $mongo_result) {
        $counter['other_personalized_section'][$mongo_result['section']][] = $mongo_result['nid'];
        $views_nodes['other_personalized_section'][$mongo_result['section']] = sizeof($counter['other_personalized_section'][$mongo_result['section']]);
      }
    }

    // Chart to display nodes viewed by users.
    //if ($_GET['report_type'] == 'personalized') {
    $chart = '<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>';
    $chart .= '<div>
                    <ul class="report-chart-tabs">
                      <li class="active"><a data-toggle="report1" href="javascript:void(0);">Personalized Sections</a></li>
                      <li><a data-toggle="report2" href="javascript:void(0);">Sections</a></li>
                    </ul>
                </div>';
    $chart .= '<div class="tab-content">';
    $chart .= '<div id="report1">';
    if(!empty($views_nodes['under_personalized_section'])) {
      $chart .= theme('itg_reports_personalized_data_chart' , array(
        "total_section_node_visited" => $views_nodes['under_personalized_section'] ,
          )
      );
    } else {
      $chart .= '<p>' . t("Data not found.") . '<p>';
    }
    $chart .= "</div>";

    $chart .= '<div id="report2">';
    if(!empty($views_nodes['other_personalized_section'])) {
      $chart .= theme('itg_reports_sections_data_chart' , array(
        'node_under_section_visited' => $views_nodes['other_personalized_section'] ,
      ));
    }
    else {
      $chart .= '<p>' . t("Data not found.") . '<p>';
    }
    $chart .= "</div>";
    $chart .= "</div>";
    return $chart;
  }
  else {
    $chart .= "<div class='form-item'>" . t("Please select date range.") . "</div>";
    return $chart;
  }
}

/**
 * Main function which is comes first and auto submit.
 * @param int $user_id
 * @return string
 */
function itg_registered_user_report_section_wise_breakup($user_id) {
  if(!empty($user_id)) {
    drupal_add_js('
      jQuery(document).ready(function(){myFunction(); jQuery(".widget-ajex-loader").show();});
      function myFunction() {
          
          document.getElementById("itg-registred-user-report-form").submit();
      }
    ' ,'inline');
  }
  drupal_add_js(drupal_get_path('module' , 'itg_reports') . '/js/itg_reports.js' , array('type' => 'file'));
  $registred_users_form = drupal_get_form('itg_registred_user_report_form');
  return $registred_users_form;
}
