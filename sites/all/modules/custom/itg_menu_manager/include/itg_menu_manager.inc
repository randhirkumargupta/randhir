<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function itg_menu_manager_custom_variables() {
    $form = array();
    $form['menu_manager_custom_url'] = array(
        '#type' => 'textarea',
        '#title' => t('Enter Urls in which menu custom link will display'),
        '#default_value' => variable_get('menu_manager_custom_url'),
        '#rows' => 10,
        '#cols' => 60,
        '#resizable' => TRUE,
    );
    return system_settings_form($form);
}
