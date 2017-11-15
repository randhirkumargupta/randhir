<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * {@inheritdoc}
 */
function itg_menu_manager_form($form, &$form_state) {
    $menu_arg = arg();
    // Change title during edit operation.
    if (isset($_GET['edit_id'])) {
        drupal_set_title("Edit menu");
    }

    $default_values = array();
    $edit_id = isset($_GET['edit_id']) ? intval(trim($_GET['edit_id'])) : FALSE;
    $term_id = isset($_GET['term_id']) ? intval(trim($_GET['term_id'])) : FALSE;
    //$doc_id = variable_get('document_variable_name');
    $frist_section = FALSE;
    // condition to check operation
    if ($edit_id && $term_id) {
        $query = db_select('itg_menu_manager', 'imm')
          ->fields('imm')
          ->condition('imm.id', $edit_id);
        $default_values = $query->execute()->fetchAssoc();
    }
    if (!empty($options)) {
        reset($options);
        // Get only frist tid
        $frist_section = key($options);
    }

    $section = isset($form_state['values']['sections']) ? $form_state['values']['sections'] : $frist_section;

    $menu_level = isset($form_state['values']['menu_level']) ? $form_state['values']['menu_level'] : "second";

    ########################################
    #                                      #
    # Handel case when user come form menu #
    #                                      #
    ########################################

    if ($menu_arg[0] == 'itg-menu-manager' && $menu_arg[1] == 'second') {
        $default_values['menu_level'] = "second";
    }

    if ($menu_arg[0] == 'itg-menu-manager' && $menu_arg[1] == 'vertical') {
        $default_values['menu_level'] = "vertical";
    }

    if ($menu_arg[0] == 'itg-menu-manager' && $menu_arg[1] == 'third') {
        $default_values['menu_level'] = "third";
        $menu_level = 'third';
    }

    if ($menu_level == 'third') {
        $options = itg_menu_manager_get_taxonomy_term_options('category_management');
    } else {
        $options = array(0 => "Home Page");
    }
    $form['url_type'] = array(
      '#type' => 'radios',
      '#title' => t('Menu Type'),
      '#options' => array(
        'internal' => 'Internal',
        'external' => 'External',
      ),
      '#default_value' => isset($default_values['url_type']) ? $default_values['url_type'] : 'internal',
      '#ajax' => array(
        'callback' => 'add_or_remove_autocomplete',
        'wrapper' => 'entire_form',
      ),
      '#description' => t('internal menu type will search "title" from category pool and external will not search.'),
      '#required' => TRUE,
    );

    $form['menu_level'] = array(
      '#type' => 'select',
      '#title' => t('Menu Level'),
      '#options' => array(
        '' => '--Select--',
        'second' => 'Second',
        'third' => 'Third',
        'vertical' => 'Vertical menu',
      ),
      '#default_value' => isset($default_values['menu_level']) ? $default_values['menu_level'] : "",
      '#required' => TRUE,
      '#ajax' => array(
        'callback' => 'decide_section',
        'wrapper' => 'entire_form',
      ),
    );

    $form['sections'] = array(
      '#type' => 'select',
      '#title' => t('Section'),
      '#ajax' => array(
        'callback' => 'get_section_update',
        'wrapper' => 'entire_form',
      ),
      '#options' => ($edit_id && (isset($default_values['menu_level']) && $default_values['menu_level'] == 'third')) ? itg_menu_manager_get_taxonomy_term_options('category_management') : $options,
      '#prefix' => '<div id="decided-section">',
      '#suffix' => '</div>',
      '#default_value' => isset($default_values['section_id']) ? $default_values['section_id'] : "",
      '#validated' => TRUE
    );

    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title / Category'),
      '#prefix' => '<div id="referral_provider">',
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => 'get_url_of_current_term',
        'wrapper' => 'entire_form',
      ),
      '#attributes' => array(
        'onkeydown' => array("return isValidKey(event)"),
      ),
      '#default_value' => isset($default_values['title']) ? $default_values['title'] : "",
      '#required' => TRUE,
    );
    if ($menu_level == 'third' || (isset($default_values['section_id']) && $default_values['section_id'])) {
        if (isset($default_values['section_id']) && $default_values['section_id']) {
            $section = $default_values['section_id'];
        }
        $form['title']['#autocomplete_path'] = 'itg-menu-manager/get-child/autocomplete/' . $section;
    } else {
        $form['title']['#autocomplete_path'] = 'itg-menu-manager/get-child-under-category-management/autocomplete';
    }

    $form['url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#prefix' => '<div id="url-of-current-term">',
      '#suffix' => '</div>',
      '#required' => TRUE,
      '#default_value' => isset($default_values['url']) ? $default_values['url'] : "",
      '#maxlength' => 255,
    );

    $form['url_window'] = array(
      '#type' => 'radios',
      '#title' => t('Target'),
      '#options' => array(
        'same_window' => 'Same Window',
        'new_window' => 'New Window',
      ),
      '#description' => t('Same window will open "MENU" in current tab and New window will open "MENU" in new tab'),
      '#default_value' => isset($default_values['target']) ? $default_values['target'] : "same_window",
      '#required' => TRUE,
    );

    $form['sponsored_category'] = array(
      '#title' => t('Sponsored Category'),
      '#type' => 'checkboxes',
      '#description' => t('If menu is sponsored the the background color will apply.'),
      '#default_value' => (isset($default_values['extra']) && ($default_values['extra'] == "Yes")) ? array("Yes") : array(),
      '#options' => array('Yes' => t('Yes')),
    );
    $default_color_value = isset($default_values['bk_color']) ? $default_values['bk_color'] : "#000000";

    $form['bk_color'] = array(
      '#type' => 'textfield',
      '#title' => t('Background Color'),
      '#default_value' => $default_color_value,
      '#attributes' => array('class' => array('jscolor {hash:true}')),
      '#suffix' => '<div class="form-item form-type-textfield"><input type="color" id="color-picker" value="' . $default_color_value . '"></div>',
    );


    if (arg(1) == 'vertical') {
        $default_values['display_icon'] = 1;
    }

    $form['display_icon'] = array(
      '#title' => t('Display'),
      '#type' => 'radios',
      '#description' => t('Show title will display "title" field value insteed of icon.'),
      '#default_value' => isset($default_values['display_icon']) ? $default_values['display_icon'] : 0,
      '#options' => array(0 => t('Show title'), 1 => t('Show icon')),
      '#prefix' => (arg(1) == 'vertical') ? '<div class="hide">' : '',
      '#suffix' => (arg(1) == 'vertical') ? '</div>' : '',
    );

    $form['category_icon'] = array(
      '#title' => t('Upload the icon'),
      '#type' => 'managed_file',
      '#name' => 'category_icon',
      '#title' => t('Upload External Menu Icon'),
      '#description' => t('Category icon applicable for <br/>only external link. For internal icon <br/>will come from category manager. <br/> Preferred image size 46x37.'),
      '#file_validate_extensions' => array(
        'png gif jpg jpeg'
      ),
      '#default_value' => (isset($default_values['menu_name']) && (int) $default_values['menu_name']) ? $default_values['menu_name'] : NULL,
      '#upload_location' => 'public://category_icon/',
    );
    // Submit Button
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save Menu'),
    );

    $destination = "menu-manager/second";
    if (isset($_GET['destination'])) {
        $destination = $_GET['destination'];
    } else if (isset($_GET['prev_page'])) {
        $destination = $_GET['prev_page'];
    }
    $form['cancle'] = array(
      '#type' => 'markup',
      '#markup' => l('Cancel', $destination, array("attributes" => array("class" => array("button")))),
    );

    $form['#attributes'] = array(
      'class' => array('itg_menu_manager_form'),
    );

    $form['#prefix'] = '<div id="entire_form">';
    $form['#suffix'] = '</div>';

    if (!$edit_id) {
        drupal_add_js(drupal_get_path('module', 'itg_menu_manager') . '/js/itg_menu_manager.js', array('scope' => 'footer'));
    }

    if ((isset($form_state['values']['url_type']) && $form_state['values']['url_type'] == 'external') || (isset($default_values['url_type']) && $default_values['url_type'] == 'external')) {
        unset($form['title']['#ajax']);
    }


##############################################################################
########### Condtion removed fornow for file title in case of second #########
##############################################################################

    $form['#after_build'][] = 'itg_menu_manager_after_build';
    return $form;
}

/**
 * {@inheritdoc}
 */
function itg_menu_manager_form_validate($form, &$form_state) {
    if (isset($form_state['clicked_button']) && $form_state['clicked_button']['#type'] == 'submit') {
        $errors = array();
        $values = $form_state['values'];
        // Section id.
        $section_id = $values['sections'];
        $menu_level = $values['menu_level'];
        $url_type = $values['url_type'];
        // Validate here for dublicasy.
        $url = $values['url'];

        // Validation for dublicate menu and sub menu.
        if ($url_type == 'internal') {
            // get values beween squre breaket.
            preg_match_all("/\[([^\]]*)\]/", $values['title'], $matches);
            // get tid
            $term_tid_array = explode("tid:", $matches[1][0]);
            // In case of external url we didnt got tid so mannualy give a tid.
            $term_id = ($term_tid_array[1]) ? trim($term_tid_array[1]) : time();

            $count = _get_itg_menu_data($menu_level, $section_id, $url_type, $term_id);

            if ($count) {
                $display_message = "";
                if ($menu_level == 'third') {
                    $section_link = l("Click here", "menu-manager/third", array("attributes" => array("target" => array("_blank")), "query" => array("section_child" => $section_id, "tid" => "", "section_id" => $section_id)));
                    $taxonomy_term_data = taxonomy_term_load($section_id);
                    $display_message = "Under <b> $taxonomy_term_data->name </b> Section. $section_link";
                } else if ($menu_level == 'second') {
                    $section_link = l("Click Here", "menu-manager/second", array("attributes" => array("target" => array("_blank"))));
                    $display_message = $section_link;
                } else if ($menu_level == 'vertical') {
                    drupal_add_css("#decided-section {display:none !important}", "inline");
                    $section_link = l("Click Here", "menu-manager/vertical", array("attributes" => array("target" => array("_blank"))));
                    $display_message = $section_link;
                }
                $errors[] = t("Menu <b>" . $values['title'] . "</b> Already Exists. $display_message");
            }
            // Handle edit case if same.
            if (isset($_GET['edit_id'])) {
                try {
                    $get_term_id_from_db = db_select('itg_menu_manager', 'imm');
                    $get_term_id_from_db->fields('imm', array('title'));
                    $get_term_id_from_db->condition('imm.id', $_GET['edit_id'], '=');
                    $title_data = $get_term_id_from_db->execute()->fetchField();

                    if ($values['title'] == $title_data) {
                        $errors = array();
                    }
                } catch (Exception $ex) {
                    watchdog('menu_manager', $ex->getMessage());
                }
            }
        }

        if ($url_type == 'external' && !empty($url)) {
            if ((strpos($url, 'http') === 0) && filter_var($url, FILTER_VALIDATE_URL)) {
                //watchdog("menu_manager", "Url validated in case of external");
            } else {
                $errors[] = t("Please enter valid external url  eg: http://www.example.com");
            }
        }

        if ($url_type == 'internal' && !empty($url)) {
            if (!drupal_valid_path($url)) {
                // Not a system URL.
                if (!drupal_lookup_path('source', $url)) {
                    $errors[] = t("Please enter valid internal url");
                }
            } else {
                $url_parse = parse_url($url);
                if (!empty($url_parse['scheme'])) {
                    $errors[] = t("It seems you entered external url.");
                }
            }
        }

        if ($values['display_icon'] == 1 && $values['url_type'] == 'external' && $values['menu_level'] == 'vertical' && !$values['category_icon']) {
            //$errors[] = t("For external vertical menu category icon is required.");
            //drupal_add_css(".form-item-sections {display:none !important}" , "inline");
        }

        if ($values['menu_level'] == '') {
            $errors[] = t("Please select menu level");
        }

        if ($menu_level == 'vertical') {
            drupal_add_css("input[name=bk_color] , .form-item-display-icon {display:none !important}", "inline");
        }
        if (!empty($errors)) {
            drupal_set_message(implode("][", $errors), "error");
            foreach ($errors as $error) {
                form_set_error($error);
            }
        }
    }
}

/**
 * {@inheritdoc}
 */
function itg_menu_manager_form_submit($form, &$form_state) {
    //START Logic to clear cache
    $block_cache = array(
      'itg_layout_manager:header_block',
      'itg_menu_manager:vertical_menu',
      'itg_menu_manager:second_level_menu',
      'itg_menu_manager:third_level_menu'
    );
    itg_common_cache_clear($block_cache);
    //END Logic to clear cache
    $edit_id = (null !== filter_input(INPUT_GET, 'edit_id')) ? filter_input(INPUT_GET, 'edit_id') : 0;
    $values = $form_state['values'];
    $display_icon = $values['display_icon'];
    $url_type = filter_xss($values['url_type']);
    $menu_level = filter_xss($values['menu_level']);
    $sections = filter_xss($values['sections']);
    $title = filter_xss($values['title']);
    $url = filter_xss($values['url']);
    $target = filter_xss($values['url_window']);
    $category_icon = $values['category_icon'];
    $bk_color = $values['bk_color'];
    $sponsored_category = $values['sponsored_category']['Yes'];
    $is_sponsored = ($sponsored_category) ? $sponsored_category : "No";
    $file_id = 'notFound';
    if ($category_icon != 0) {
        // Upload and save file.
        $file = file_load($category_icon);

        $file->status = FILE_STATUS_PERMANENT;
        $file_saved = file_save($file);
        // Record that the module is using the file.
        // If we dont do , then file will remove if a cron run.
        file_usage_add($file_saved, 'itg_menu_manager', 'category_icon_image', $file_saved->fid);
        $file_id = $file_saved->fid;
    }
    if ($edit_id) {
        // Handle update
        try {
            // get values beween squre breaket.
            preg_match_all("/\[([^\]]*)\]/", $title, $matches);
            // get tid
            $term_tid_array = explode("tid:", $matches[1][0]);
            // In case of external url we didnt got tid so mannualy give a tid.
            $term_id = ($term_tid_array[1]) ? trim($term_tid_array[1]) : time();
            db_update('itg_menu_manager')
              ->fields(array(
                'title' => $title,
                'url' => $url,
                'target' => $target,
                'menu_level' => $menu_level,
                'url_type' => $url_type,
                'section_id' => $sections,
                'tid' => $term_id,
                'created' => time(),
                'extra' => $is_sponsored,
                'menu_name' => $file_id,
                'display_icon' => $display_icon,
                'bk_color' => $bk_color,
                )
              )->condition('id', $edit_id, "=")->execute();

            if ($menu_level == 'second') {
                drupal_goto('menu-manager/second');
            } else if ($menu_level == 'vertical') {
                drupal_goto('menu-manager/vertical');
            } else {
                $query = array("section_id" => $sections, "section_child" => $sections);
                drupal_goto('menu-manager/third', array("query" => $query));
            }
            drupal_set_message("@level menu has been updated", array("@level" => $menu_level));
        } catch (Exception $ex) {
            drupal_set_message($ex->getMessage());
        }
    } else {
        // handle insert
        $max_query = db_select('itg_menu_manager');
        $max_query->addExpression('MAX(weight)');
        $max_query->condition('menu_level', $menu_level);
        // condition during menu level
        if ($menu_level == 'third') {
            $max_query->condition('section_id', $sections);
        }
        $max_result = $max_query->execute()->fetchField();

        $order = ++$max_result;

        // get values beween squre breaket.
        preg_match_all("/\[([^\]]*)\]/", $title, $matches);
        // get tid
        $term_tid_array = explode("tid:", $matches[1][0]);
        // In case of external url we didnt got tid so mannualy give a tid.
        $term_id = ($term_tid_array[1]) ? trim($term_tid_array[1]) : time();

        try {

            db_insert('itg_menu_manager')
              ->fields(array(
                'title' => $title,
                'url' => $url,
                'target' => $target,
                'menu_level' => $menu_level,
                'weight' => $order,
                'url_type' => $url_type,
                'section_id' => $sections,
                'tid' => trim($term_id),
                'created' => time(),
                'extra' => $is_sponsored,
                'menu_name' => $file_id,
                'display_icon' => $display_icon,
                'bk_color' => $bk_color,
              ))
              ->execute();
            if ($menu_level == 'second') {
                drupal_goto('menu-manager/second');
            } else if ($menu_level == 'vertical') {
                drupal_goto('menu-manager/vertical');
            } else {
                $query = array("section_id" => $sections, "section_child" => $sections);
                drupal_goto('menu-manager/third', array("query" => $query));
            }
            drupal_set_message("$menu_level menu has been created");
        } catch (Exception $ex) {
            drupal_set_message($ex->getMessage());
        }
    }
}
