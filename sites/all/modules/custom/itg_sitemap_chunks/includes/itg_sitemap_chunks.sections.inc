<?php

/**
 * @file
 * Contain admin function for multiple sitemap.
 */
module_load_include('inc', 'itg_sitemap_chunks', 'includes/itg_sitemap_chunks_section.db');

function itg_sitemap_chunks_section_form($form, &$form_state) {
  $sections = itg_sitemap_get_sections();

  $form['section'] = array(
    '#prefix' => '<div id="sections-container">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'table',
    '#header' => array(t('Section Name'), t('Frequency'), t('Type')),
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

    $form['section'][] = array(
      'section_tid' => &$section_checkbox,
      'section_freq' => &$section_frequency,
      'section_freq_type' => &$section_frequency_type,
    );

    $form['section']['#rows'][] = array(
      array('data' => &$section_checkbox),
      array('data' => &$section_frequency),
      array('data' => &$section_frequency_type),
    );

    unset($section_checkbox);
    unset($section_frequency);
    unset($section_frequency_type);
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

function itg_sitemap_chunks_section_form_submit($form, &$form_state) {
  itg_sitemap_shunks_section_delete();
  $sections = $form_state['values']['section'];
  if (!empty($sections)) {
    foreach ($sections as $section) {
      $section_tid = array_keys($section['section_tid'])[0];
      if ($section['section_tid'][$section_tid] != 0) {
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
