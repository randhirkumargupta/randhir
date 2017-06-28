<?php

/**
 * @file
 * Contain admin function for multiple sitemap.
 */
module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks_section.db');

/**
 * Form for section sitemap setting.
 *  {@inheritdocs}
 */
function itg_sitemap_chunks_section_form($form, &$form_state) {
  $sections = itg_sitemap_get_sections();

  $form['section'] = array(
    '#prefix' => '<div id="sections-container">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'table',
    '#attributes' => array('class' => array("views-table")),
    '#header' => array(t('Section Name'), t('Frequency'), t('Type'), t('Action')),
    '#rows' => array(),
  );
  for ($i = 0; $i < count($sections); $i++) {
    $db_data = itg_sitemap_chunks_section_db_data($sections[$i]->tid);
    // Prepare checboxes
    $section_checkbox = array(
      '#id' => 'section-' . $i . '-tid',
      '#type' => 'checkboxes',
      '#options' => array($sections[$i]->tid => $sections[$i]->name),
      '#default_value' => !empty($db_data->section_tid) ? array($db_data->section_tid) : array(),
    );

    // Prepare frequency
    $section_frequency = array(
      '#id' => 'section-' . $i . '-frequency',
      '#type' => 'select',
      '#options' => range(0, 31),
      '#default_value' => !empty($db_data->frequency) ? $db_data->frequency : '',
    );

    // Prepare frequency type
    $section_frequency_type = array(
      '#id' => 'section-' . $i . '-type',
      '#type' => 'select',
      '#options' => drupal_map_assoc(array("day", "month", "year")),
      '#default_value' => !empty($db_data->frequency_type) ? $db_data->frequency_type : '',
    );
    
    if(!empty($db_data->section_tid)) {
      $site_map_link = itg_sitemap_chunks_create_valid_url($sections[$i]->name) . '-sitemap.xml';
      $action_link = l("View" ,$site_map_link , array("attributes" => array("target" => "_blank")));
    } else {
      $action_link = t("N/A");
    }
    // Prepare frequency type
    $view_makrup = array(
      '#id' => 'section-' . $i . '-type',
      '#type' => 'markup',
      '#markup' => $action_link,
    );

    $form['section'][] = array(
      'section_tid' => &$section_checkbox,
      'section_freq' => &$section_frequency,
      'section_freq_type' => &$section_frequency_type,
      'view_action' => &$view_makrup,
    );

    $form['section']['#rows'][] = array(
      array('data' => &$section_checkbox),
      array('data' => &$section_frequency),
      array('data' => &$section_frequency_type),
      array('data' => &$view_makrup),
    );

    unset($section_checkbox);
    unset($section_frequency);
    unset($section_frequency_type);
    unset($view_makrup);
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Functions gives array of sections.
 * @return array
 */
function itg_sitemap_get_sections() {
  $query = db_select('taxonomy_term_hierarchy', 'tth');
  $query->join('itg_category_manager', 'icm', 'tth.tid=icm.tid');
  $query->join('taxonomy_term_data', 'ttd', 'ttd.tid=icm.tid');
  $query->fields('ttd', array('tid', 'name'));
  $query->condition('icm.status', 1);
  $query->condition('ttd.vid', CATEGORY_MANAGMENT);
  $query->condition('tth.parent', 0);
  $query->orderBy('ttd.name');
  return $query->execute()->fetchAll();
}

/**
 *  {@inheritdocs}
 */
function itg_sitemap_chunks_section_form_submit($form, &$form_state) {
  itg_sitemap_shunks_section_delete();
  $sections = $form_state['values']['section'];
  if (!empty($sections)) {
    foreach ($sections as $section) {
      $section_tid = array_keys($section['section_tid'])[0];
      if ($section['section_tid'][$section_tid] != 0) {
        $section_alise_name = $section['section_tid'][$section_tid];
        $alias = itg_videogallery_get_term_name($section_alise_name) . '-sitemap.xml';
        if (itg_event_backend_alias_check(itg_sitemap_chunks_create_valid_url($alias))) {
          $source = 'sitemap/' . $section['section_tid'][$section_tid];
          itg_event_backend_save_alias($source, itg_sitemap_chunks_create_valid_url($alias));
        }
        $handel_value = array();
        $handel_value['tid'] = array_keys($section['section_tid'])[0];
        $handel_value['frequency'] = $section['section_freq'];
        $handel_value['frequency_type'] = $section['section_freq_type'];
        itg_sitemap_chunks_section_save_setting($handel_value);
        unset($handel_value);
      }
    }
  }
}

/**
 * Function gives right string for sitemap link.
 * @param string $pathdata
 * @return string
 */
function itg_sitemap_chunks_create_valid_url($pathdata) {

  if (preg_match("![^a-z0-9]!i", $pathdata)) {
    $pathdata = preg_replace('/[^a-zA-Z0-9\/\\.\']/', '-', $pathdata);
    while (preg_match('/--/', $pathdata)) {
      $pathdata = preg_replace('/--/', '-', $pathdata);
    }
    $pathdata = rtrim($pathdata, "-");
    $pathdata = strtolower($pathdata);
    $pathdata = str_replace(array(':', '*', '"', "'", '#'), "-", $pathdata);
  }
  return $pathdata;
}
