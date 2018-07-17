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
        '#header' => array(t('Section Name'), t('Day'), '<div class="hide">' . t('Type') . '</div>', t('Action')),
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
            '#default_value' => !empty($db_data->frequency) ? $db_data->frequency : 2,
        );

        // Prepare frequency type
        $section_frequency_type = array(
            '#id' => 'section-' . $i . '-type',
            '#type' => 'select',
            '#options' => drupal_map_assoc(array("day", "month", "year")),
            //'#default_value' => !empty($db_data->frequency_type) ? $db_data->frequency_type : '',
            '#default_value' => 'day',
            '#prefix' => '<div class="hide">',
            '#suffix' => '</div>',
        );

        if (!empty($db_data->section_tid)) {
            $site_map_link = FRONT_URL . '/sitemap/' . $db_data->section_tid;
            $action_link = l("View", $site_map_link, array("attributes" => array("target" => "_blank")));
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
    _itg_delete_all_section_sitemap_alias();
    $sections = $form_state['values']['section'];
    if (!empty($sections)) {
        foreach ($sections as $section) {
            $flag = array_values($section['section_tid']);
            if ($flag[0]) {
                $handel_value = array();
                $handel_value['tid'] = array_keys($section['section_tid'])[0];
                $handel_value['frequency'] = $section['section_freq'];
                $handel_value['frequency_type'] = $section['section_freq_type'];
                $operations[] = array(
                    'itg_sitemap_chunks_section_batch_processing', // The function to run on each row
                    array($handel_value), // The row in the csv
                );
            }
        }
        $batch = array(
            'title' => t('Saving setting for xml sitemap...'),
            'operations' => $operations, // Runs all of the queued processes from the while loop above.
            'finished' => 'itg_sitemap_chunks_section_save_finish', // Function to run when the import is successful
            'error_message' => t('The installation has encountered an error.'),
            'progress_message' => t('Saved setting @current of @total sections.'),
            'file' => drupal_get_path('module', 'itg_sitemap_chunks') . '/includes/itg_sitemap_chunks.sections.inc',
        );
        batch_set($batch);
    }
}

function itg_sitemap_chunks_section_batch_processing($handel_value) {
    $tid = $handel_value['tid'];
    $frequency = $handel_value['frequency'];
    $frequency_type = $handel_value['frequency_type'];
    $alias = itg_videogallery_get_term_name($tid) . '-sitemap.xml';
    if (itg_event_backend_alias_check(itg_sitemap_chunks_create_valid_url($alias))) {
        $source = 'sitemap/' . $tid;
        itg_event_backend_save_alias($source, itg_sitemap_chunks_create_valid_url($alias));
    }
    try {
        db_insert('itg_sitemap_chunks_sections')
                ->fields(array(
                    'section_tid' => $tid,
                    'frequency' => $frequency,
                    'frequency_type' => $frequency_type,
                ))->execute();
    } catch (Exception $ex) {
        drupal_set_message($ex->getMessage());
    }
}

function itg_sitemap_chunks_section_save_finish() {
    drupal_set_message(t('Settings has been done.'));
}

function _itg_delete_all_section_sitemap_alias() {
    try {
        db_delete('url_alias')->condition('source', '%' . db_like('sitemap/') . '%', 'LIKE')->execute();
    } catch (Exception $ex) {
        drupal_set_message($ex->getMessage(), 'error');
    }
}
