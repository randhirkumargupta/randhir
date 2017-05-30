<?php

/**
 * @file
 * The ITG Be Lucky Today
 *
 * Contains functionality for Be Lucky Today
 *
 */

/**
 * {@inheritdoc}
 */
function be_lucky_today_form($form, &$form_state) {
    global $base_url;

    if (!isset($form_state['stage']))
        $form_state['stage'] = 'be_lucky_home';
    $form = array();
    $form = be_lucky_today_get_header($form, $form_state);
    $form['#prefix'] = '<div class="itg_be_lucky_today">';
    $form['#suffix'] = '</div>';
    $form['#attached']['js'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/js/itg_be_lucky_today.js',
    );
    $form['#attached']['css'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/css/itg_be_lucky_today.css',
    );
    switch ($form_state['stage']) {
        case 'be_lucky_home':
            return be_lucky_today_home($form, $form_state);
            break;
        case 'registration1':
            return be_lucky_today_registration1($form, $form_state);
            break;
        case 'registration2':
            return be_lucky_today_registration2($form, $form_state);
            break;
        case 'registration3':
            return be_lucky_today_registration3($form, $form_state);
            break;
        case 'subscribe':
            return be_lucky_today_subscribe($form, $form_state);
            break;
        default:
            return be_lucky_today_home($form, $form_state);
            break;
    }
    return $form;
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_home($form, $form_state) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();
    $form['be_lucky_markup_image'] = array(
      '#markup' => '<img src="' . $base_url . '/' . drupal_get_path('module', 'itg_be_lucky_today') . '/images/iphone-one.png" alt="">',
      '#prefix' => '<div class="ball">',
      '#suffix' => '</div>',
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
    );
    $form['termsandcondition'] = array(
      '#type' => 'link',
      '#title' => t('Terms and Condition'),
      '#href' => 'be-lucky-today/terms/nojs',
      '#attributes' => array('class' => array('ctools-use-modal'))
    );
    return $form;
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_registration1($form, $form_state) {

    $form['name_label'] = array(
      '#markup' => 'Q1. By what name should we call you?',
      '#prefix' => '<strong>',
      '#suffix' => '</strong>',
    );
    $form['yourname'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
      '#attributes' => array('class' => array('form-control'), 'autocomplete' => 'off')
    );
    $form['gender_label'] = array(
      '#markup' => 'Q2. Let us know you better....',
      '#prefix' => '<strong>',
      '#suffix' => '</strong>',
    );
    $form['gender'] = array(
      '#type' => 'radios',
      '#title' => t('Gender'),
      '#options' => array('male' => t('Male'), 'female' => t('Female')),
      '#default_value' => 'male',
      '#description' => t('When a poll is closed, visitors can no longer vote for it.')
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#attributes' => array('class' => array('next'))
    );
    return $form;
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_registration2($form, $form_state) {
    $age = array(
      '18-24' => t('<em>18</em>-<em>24</em>'),
      '25-34' => t('<em>25</em>-<em>34</em>'),
      '35-44' => t('<em>35</em>-<em>44</em>'),
      '45-54' => t('<em>45</em>-<em>54</em>'),
      '55-64' => t('<em>55</em>-<em>64</em>'),
      '65-74' => t('<em>65</em>-<em>74</em>')
    );
    $form['age_label'] = array(
      '#markup' => 'Q3. How old are you? (Shhh... We’ll keep it a secret)',
      '#prefix' => '<strong>',
      '#suffix' => '</strong>',
    );
    $form['age'] = array(
      '#type' => 'radios',
      '#title' => t('Age'),
      '#options' => $age,
      '#default_value' => '18-24'
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#attributes' => array('class' => array('next2'))
    );
    return $form;
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_registration3($form, $form_state) {
    $states = array();
    $states = get_states_from_country();
    $default_state = '';
    foreach ($states as $key => $value) {
        $default_state = $key;
        break;
    }

    $form['email_markup'] = array(
      '#markup' => 'Q4. On which e-mail ID should we notify you about the prize?',
      '#prefix' => '<strong>',
      '#suffix' => '</strong>',
    );

    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Email'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
      '#attributes' => array('autocomplete' => 'off'),
//      '#ajax' => array(
//        'callback' => 'email_validation_ajax_callback',
//        'wrapper' => 'email_validation_error',
//      ),
//      '#prefix' => '<div id="email_validation_error">',
//      '#suffix' => '</div>',
    );
    $form['address_markup'] = array(
      '#markup' => 'Q5. Where should we deliver your gift?',
      '#prefix' => '<strong>',
      '#suffix' => '</strong>',
    );
    $form['address'] = array(
      '#type' => 'textfield',
      '#title' => t('Address'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
      '#attributes' => array('autocomplete' => 'off'),
    );
    $form['state'] = array(
      '#type' => 'select',
      '#title' => t('State'),
      '#options' => $states,
      '#default_value' => $default_state,
      '#ajax' => array(
        'callback' => 'get_city_from_state_ajax_callback',
        'wrapper' => 'city_wrapper',
      ),
    );
    $city_arr = array('' => 'Select');
    if (isset($form_state['values']['state'])) {
        $city_arr = get_city_from_state($form_state['values']['state']);
    }
    else {
        $city_arr = get_city_from_state($default_state);
    }
    $form['city'] = array(
      '#type' => 'select',
      '#title' => t('City'),
      '#options' => $city_arr,
      '#default_value' => 0,
      '#prefix' => '<div id="city_wrapper">',
      '#suffix' => '</div>',
    );
    $form['zip_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Zip code'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
      '#attributes' => array('autocomplete' => 'off'),
    );
    $form['mobile_label'] = array(
      '#markup' => 'Q6. At what number should we contact you?',
      '#prefix' => '<strong>',
      '#suffix' => '</strong>',
    );
    $form['mobile'] = array(
      '#type' => 'textfield',
      '#title' => t('Mobile'),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => TRUE,
      '#attributes' => array('autocomplete' => 'off'),
//      '#ajax' => array(
//        'callback' => 'mobile_validation_ajax_callback',
//        'wrapper' => 'mobile_validation_error',
//      ),
//      '#prefix' => '<div id="mobile_validation_error">',
//      '#suffix' => '</div>',
    );

    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#attributes' => array('class' => array('next3'))
    );
    return $form;
}

function email_validation_ajax_callback($form, &$form_state) {
    $email = $form_state['values']['email'];
    $result = get_survey_detail_by_field('email', $email);
    if (count($result) > 0) {
        form_set_error('email', t('Email has already used. Please enter another email.'));
        $form['email']['#prefix'] .= theme('status_messages');
    }
    return $form['email'];
}

function mobile_validation_ajax_callback($form, &$form_state) {
    $mobile = $form_state['values']['mobile'];
    $result = get_survey_detail_by_field('mobile', $mobile);
    if (count($result) > 0) {
        form_set_error('mobile', t('Mobile number has already used. Please enter another mobile number'));
        $form['mobile']['#prefix'] .= theme('status_messages');
    }
    return $form['mobile'];
}

/**
 * 
 * @global String $base_url
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_subscribe($form, $form_state) {
    $form['magazine'] = array(
      '#markup' => '<div>' . file_get_contents("http://subscriptions.intoday.in/subscriptions/digitalsubscriptions/index-fetchdata.jsp") . '</div>',
      '#prefix' => '<div id="magazine_wrapper">',
      '#suffix' => '</div>',
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#attributes' => array('class' => array('magazine'))
    );
    return $form;
}

/**
 * 
 * @param array $form
 * @param array $form_state
 */
function be_lucky_today_form_validate($form, &$form_state) {
    switch ($form_state['stage']) {
        case 'registration3':
            $email = $form_state['values']['email'];
            $mobile = $form_state['values']['mobile'];
            $result = get_survey_detail_by_field('email', $email);
            if (count($result) > 0) {
                form_set_error('email', t('Email has already used. Please enter another email.'));
            }
            $result = get_survey_detail_by_field('mobile', $mobile);
            if (count($result) > 0) {
                form_set_error('mobile', t('Mobile number has already used. Please enter another mobile number.'));
            }
    }
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 */
function be_lucky_today_form_submit($form, &$form_state) {
    switch ($form_state['stage']) {
        case 'subscribe':
            $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
            if ($form_state['triggering_element']['#value'] != 'Back') {
                be_lucky_today_aftersubscription_submit($form, $form_state);
                $form_state['complete'] = TRUE;
            }
            break;

        default:
            $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
            $form_state['new_stage'] = be_lucky_today_move_to_next_stage($form, $form_state);
            break;
    }

    if ($form_state['stage'] != 'subscribe') {
        if (isset($form_state['multistep_values']['form_build_id'])) {
            $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
        }
        $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
        $form_state['stage'] = $form_state['new_stage'];
        $form_state['rebuild'] = TRUE;
    }
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 */
function be_lucky_today_aftersubscription_submit($form, &$form_state) {
    global $base_url;
    $state = '';
    if (isset($form_state['multistep_values']['registration3']['state'])) {
        $state = get_term_name_by_tid($form_state['multistep_values']['registration3']['state']);
    }
    $city = '';
    if (isset($form_state['multistep_values']['registration3']['city'])) {
        $city = get_term_name_by_tid($form_state['multistep_values']['registration3']['city']);
    }

    $magazine1 = $form_state['input']['magazine'];
    $magazineName = explode(":", $magazine1);
    $magazine = $magazineName[0];
    $magazine2 = $magazineName[1];
    $data = array(
      'survey_id' => 29072016,
      'name' => $form_state['multistep_values']['registration1']['yourname'],
      'gender' => $form_state['multistep_values']['registration1']['gender'],
      'age' => $form_state['multistep_values']['registration2']['age'],
      'email' => $form_state['multistep_values']['registration3']['email'],
      'address' => $form_state['multistep_values']['registration3']['address'],
      'state' => $state,
      'city' => $city,
      'studled' => $form_state['multistep_values']['registration3']['zip_code'],
      'mobile' => $form_state['multistep_values']['registration3']['mobile'],
      'income' => 'unconfirm',
      'ipaddress' => '10.20.30',
      'comment' => $magazine,
    );
    $fields = array_keys($data);
    $query = db_insert('survey')->fields($data);
    $key = $query->execute();

    $data['magazine'] = $form_state['input']['magazine'];
    $data['magazine2'] = $magazine2;
    $data['user_id'] = '';
    $data['product_id'] = 161;
    $data['key'] = $key;
    $data['source'] = '';
    if (isset($_GET['source'])) {
        $data['source'] = $_GET['source'];
    }
    $_SESSION['be_lucky_today'] = json_encode($data);
    $form_state['redirect'] = array(
      'be-lucky-today/aftersubscribe'
    );
}

/**
 * This function is used to get term name.
 * @param int $tid
 * @return array
 */
function get_term_name_by_tid($tid) {
    return db_select('taxonomy_term_data', 't')
            ->fields('t', array('name'))
            ->condition('tid', $tid)
            ->execute()
            ->fetchField();
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_get_header($form, &$form_state) {

    $form_state['stage'] = isset($form_state['stage']) ? $form_state['stage'] : 1;

    $form_stages = array(
      'be_lucky_home' => 1,
      'registration1' => 2,
      'registration2' => 3,
      'registration3' => 4,
      'subscribe' => 5
    );

    if (isset($form_stages[$form_state['stage']])) {
        $current_step = $form_stages[$form_state['stage']];
    }
    else {
        $current_step = 1;
    }

    $stages = array(
      1 => array('data' => 'This is what you can WIN'),
      2 => array('data' => "Let's Start With Your Name"),
      3 => array('data' => 'Age Is Just A Number Luck Has Nothing To Do With Age.'),
      4 => array('data' => 'Help us deliver your Prize on time'),
      5 => array('data' => 'Yor are just a step away from submitting your entry for Lucky Draw. Select your preferred digital magazine @just INR 49 and be ready...'),
    );

    $stages[$current_step]['class'] = array('active');

    $stages_list = theme('item_list', array('items' => $stages));
//    $form['header'] = array(
//      '#markup' => '<h1>Be Lucky Today</h1>'
//    );
    $form['header2'] = array(
      '#type' => 'fieldset',
      '#title' => '',
      '#value' => $stages_list,
    );
    return $form;
}

/**
 * 
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function be_lucky_today_move_to_next_stage($form, &$form_state) {
    switch ($form_state['stage']) {
        case 'be_lucky_home':
            return 'registration1';
            break;
        case 'registration1':
            return 'registration2';
            break;
        case 'registration2':
            return 'registration3';
            break;
        case 'registration3':
            return 'subscribe';
            break;
    }
}

/**
 * {@inheritdoc}
 */
function be_lucky_form($form, &$form_state) {
    //$email = $_GET['email'];

    $html = <<<meter
<div class="luck_meter">
      <div class="strip color10"></div>
      <div class="strip color9"></div>
      <div class="strip color8"></div>
      <div class="strip color7"></div>
      <div class="strip color6"></div>
      <div class="strip color5"></div>
      <div class="strip color4"></div>
      <div class="strip color3"></div>
      <div class="strip color2"></div>
      <div class="strip color1"></div>
      <span class="black_strip"></span>
      <div class="clearfix"></div>
    </div>
meter;

    $form['#attached']['js'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/js/itg_be_lucky_today.js',
    );
    $form['#attached']['css'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/css/itg_be_lucky_today.css',
    );
    $form['#prefix'] = '<div class="itg_be_lucky_today_2">';
    $form['#suffix'] = '</div>';
    $form['indiatoday_logo'] = array(
      '#markup' => '<a href="/" title="India Today Group" class="logo"><img src="' . $base_url . '/' . drupal_get_path("module", "itg_be_lucky_today") . '/images/logo.png" alt="India Today Group"></a>',
      '#prefix' => '<div class="body-center">'
    );
    $form['header'] = array(
      '#markup' => '<h1>Be Lucky Today</h1>',
      '#suffix' => '</div>'
    );
    $form['message'] = array(
      '#markup' => '<p>Your happiness will be inclimlete without your friends.Let them be a part of it!!</p>',
      '#prefix' => '<div class="form-main-container"><div class="form-wrappe-left">',
    );

    $form['number_1'] = array(
      '#markup' => '<div class="col1_l"> <span class="numb_l">1</span> </div>',
      '#prefix' => '<div class="left_part_box"><div class="row"><div class="col_left">',
    );
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Name')),
      '#prefix' => '<div class="left-form-container">',
    );
    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Email Id'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Email Id')),
    );
    $form['mobile'] = array(
      '#type' => 'textfield',
      '#title' => t('Mobile No'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Mobile No')),
      '#suffix' => '</div></div></div>',
    );
    $form['number_2'] = array(
      '#markup' => '<div class="col1_l"> <span class="numb_l">2</span> </div>',
      '#prefix' => '<div class="row"><div class="col_left">',
    );
    $form['name_2'] = array(
      '#type' => 'textfield',
      '#title' => '', // t('Name'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Name')),
      '#prefix' => '<div class="left-form-container">',
    );
    $form['email_2'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Email Id'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Email Id')),
    );
    $form['mobile_2'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Mobile No'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Mobile No')),
      '#suffix' => '</div></div></div>',
    );
    $form['number_3'] = array(
      '#markup' => '<div class="col1_l"> <span class="numb_l">3</span> </div>',
      '#prefix' => '<div class="row"><div class="col_left">',
    );
    $form['name_3'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Name'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Name')),
      '#prefix' => '<div class="left-form-container">',
    );
    $form['email_3'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Email Id'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Email Id')),
    );
    $form['mobile_3'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Mobile No'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Mobile No')),
      '#suffix' => '</div></div></div>',
    );

    $form['number_4'] = array(
      '#markup' => '<div class="col1_l"> <span class="numb_l">4</span> </div>',
      '#prefix' => '<div class="row"><div class="col_left">',
    );
    $form['name_4'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Name'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Name')),
      '#prefix' => '<div class="left-form-container">',
    );
    $form['email_4'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Email Id'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Email Id')),
    );
    $form['mobile_4'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Mobile No'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Mobile No')),
      '#suffix' => '</div></div></div>',
    );
    $form['number_5'] = array(
      '#markup' => '<div class="col1_l"> <span class="numb_l">5</span> </div>',
      '#prefix' => '<div class="row"><div class="col_left">',
    );
    $form['name_5'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Name'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Name')),
      '#prefix' => '<div class="left-form-container">',
    );
    $form['email_5'] = array(
      '#type' => 'textfield',
      '#title' => '', //t('Email Id'),
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Email Id')),
    );
    $form['mobile_5'] = array(
      '#type' => 'textfield',
      '#title' => '',
      '#size' => 25,
      '#maxlength' => 128,
      '#attributes' => array('placeholder' => t('Mobile No')),
      '#suffix' => '</div></div></div></div>',
    );
    $form['luck_meter'] = array(
      '#markup' => $html,
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#attributes' => array('class' => array('be_lucky_today_submit')),
      '#value' => t('Submit your Entry'),
      '#suffix' => '</div></div>',
    );
    return $form;
}

/**
 * 
 * @param array $form
 * @param array $form_state
 */
function be_lucky_form_submit($form, &$form_state) {
    $email = $_GET['email'];
    $fb_username = '';
    $surve_parent = get_survey_detail_by_field('email', $email);
    if (count($surve_parent) > 0) {
        $fb_username = $surve_parent[0]->id;
    }

    if (!empty($form_state['values']['name'])) {
        $data[] = array(
          'name' => $form_state['values']['name'],
          'email' => $form_state['values']['email'],
          'mobile' => $form_state['values']['mobile'],
          'fb_username' => $fb_username,
          'survey_id' => 29072016
        );
    }
    if (!empty($form_state['values']['name_2'])) {
        $data[] = array(
          'name' => $form_state['values']['name_2'],
          'email' => $form_state['values']['email_2'],
          'mobile' => $form_state['values']['mobile_2'],
          'fb_username' => $fb_username,
          'survey_id' => 29072016
        );
    }
    if (!empty($form_state['values']['name_3'])) {
        $data[] = array(
          'name' => $form_state['values']['name_3'],
          'email' => $form_state['values']['email_3'],
          'mobile' => $form_state['values']['mobile_3'],
          'fb_username' => $fb_username,
          'survey_id' => 29072016
        );
    }
    if (!empty($form_state['values']['name_4'])) {
        $data[] = array(
          'name' => $form_state['values']['name_4'],
          'email' => $form_state['values']['email_4'],
          'mobile' => $form_state['values']['mobile_4'],
          'fb_username' => $fb_username,
          'survey_id' => 29072016
        );
    }
    if (!empty($form_state['values']['name_5'])) {
        $data[] = array(
          'name' => $form_state['values']['name_5'],
          'email' => $form_state['values']['email_5'],
          'mobile' => $form_state['values']['mobile_5'],
          'fb_username' => $fb_username,
          'survey_id' => 29072016
        );
    }
    if (count($data) > 0) {
        $fields = array_keys($data[0]);
        $query = db_insert('survey')->fields($fields);
        foreach ($data as $record) {
            $query->values($record);
        }
        $query->execute();
    }
    $form_state['redirect'] = array(
      '/be-lucky-today/email-confirmation-reference-list'
    );
}

/**
 * 
 * @param String $field
 * @param String $value
 * @return Array
 */
function get_survey_detail_by_field($field = 'email', $value = '') {
    $survey = db_select('survey', 's');
    $survey->fields('s');
    $survey->condition(trim($field), db_like(trim($value)), 'LIKE');
    return $survey->execute()->fetchAll();
}

/**
 * 
 * @param array $form
 * @param array $form_state
 * @return array
 */
function get_city_from_state_ajax_callback($form, &$form_state) {
    return $form['city'];
}

/**
 * 
 * @param String $state
 * @return array
 */
function get_city_from_state($state = NULL) {
    $city = array();
    if ($state == NULL) {
        return;
    }
    $result = db_select('taxonomy_term_data', 'tt');
    $result->fields('tt', array('tid', 'name'));
    $result->leftJoin('taxonomy_vocabulary', 'tv', 'tt.vid = tv.vid');
    $result->leftJoin('field_data_field_city_states', 'fcs', "fcs.entity_id = tt.tid AND fcs.entity_type = 'taxonomy_term'");
    $result->condition('fcs.field_city_states_tid', $state, '=');
    $result->condition('tv.machine_name', 'city', 'LIKE');
    $data = $result->execute()->fetchAll();
    foreach ($data as $value) {
        $city[$value->tid] = $value->name;
    }
    return $city;
}

/**
 * 
 * @param String $country
 * @return array
 */
function get_states_from_country($country = COUNTRY_INDIA_TID) {
    $result = db_select('taxonomy_term_data', 'tt');
    $result->fields('tt', array('tid', 'name'));
    $result->leftJoin('taxonomy_vocabulary', 'tv', 'tt.vid = tv.vid');
    $result->leftJoin('field_data_field_state_county', 'fsc', "fsc.entity_id = tt.tid AND fsc.entity_type = 'taxonomy_term'");
    $result->condition('fsc.field_state_county_tid', 3383, '=');
    $result->condition('tv.machine_name', 'state', 'LIKE');
    $data = $result->execute()->fetchAll();
    $state = array();
    foreach ($data as $value) {
        $state[$value->tid] = $value->name;
    }
    return $state;
}

/**
 * {@inheritdoc}
 */
function thank_you_payment_failed_form($form, &$form_state) {
    unset($_SESSION['be_lucky_today']);
    global $base_url;
    $module_path = $base_url . '/' . drupal_get_path('module', 'itg_be_lucky_today');
    $html = <<<share
<ul class="social" style="width:156px;">
<li><a href="javascript:void(0);" onclick="return fbs_click()" title="facebook"><img src="$module_path/images/fb.png" alt="facebook"></a></li>
<li><a href="https://twitter.com/intent/tweet?original_referer=http://indiatoday.intoday.in/be-lucky-today&amp;source=tweetbutton&amp;text=Grab the chance before it??s gone! Enter the India Today Survey %26 stand a chance to win an iPhone6: bit.ly/Social_sharing %23YourLuckToday" target="_blank" title="twitter"><img src="$module_path/images/twitter.png" alt="twitter"></a></li>
<li><a href="https://plus.google.com/share?url=http://indiatoday.intoday.in/be-lucky-today/index.jsp" target="_blank" title="gplus"><img src="$module_path/images/gplus.png" alt="gplus"></a></li>
</ul>
share;
    $form['#attached']['js'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/js/itg_be_lucky_today.js',
    );
    $form['#attached']['css'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/css/itg_be_lucky_today.css',
    );
    $form['indiatoday_logo'] = array(
      '#markup' => '<a href="/" title="India Today Group" class="logo"><img src="' . $base_url . '/' . drupal_get_path("module", "itg_be_lucky_today") . '/images/logo.png" alt="India Today Group"></a>',
      '#prefix' => '<div class="body-center">'
    );
    $form['header'] = array(
      '#markup' => '<h1>Be Lucky Today</h1>',
      '#suffix' => '</div>'
    );
    $form['message'] = array(
      '#markup' => '<h2>Thank You<br />for your Participation.</h2>',
      '#prefix' => '<div class="thank_you_text">',
    );
    $form['tsnmessage'] = array(
      '#markup' => '<p>Payment process cancelled.</p>',
      '#suffix' => '</div>',
    );
    $form['socialshare'] = array(
      '#markup' => $html,
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Increase your Chances'),
    );
    return $form;
}

/**
 * {@inheritdoc}
 */
function thank_you_payment_success_form($form, &$form_state) {
    unset($_SESSION['be_lucky_today']);
    global $base_url;
    $module_path = $base_url . '/' . drupal_get_path('module', 'itg_be_lucky_today');
    $html = <<<share
<ul class="social" style="width:156px;">
<li><a href="javascript:void(0);" onclick="return fbs_click()" title="facebook"><img src="$module_path/images/fb.png" alt="facebook"></a></li>
<li><a href="https://twitter.com/intent/tweet?original_referer=http://indiatoday.intoday.in/be-lucky-today&amp;source=tweetbutton&amp;text=Grab the chance before it??s gone! Enter the India Today Survey %26 stand a chance to win an iPhone6: bit.ly/Social_sharing %23YourLuckToday" target="_blank" title="twitter"><img src="$module_path/images/twitter.png" alt="twitter"></a></li>
<li><a href="https://plus.google.com/share?url=http://indiatoday.intoday.in/be-lucky-today/index.jsp" target="_blank" title="gplus"><img src="$module_path/images/gplus.png" alt="gplus"></a></li>
</ul>
share;
    $form['#attached']['js'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/js/itg_be_lucky_today.js',
    );
    $form['#attached']['css'] = array(
      drupal_get_path('module', 'itg_be_lucky_today') . '/css/itg_be_lucky_today.css',
    );
    $form['indiatoday_logo'] = array(
      '#markup' => '<a href="/" title="India Today Group" class="logo"><img src="' . $base_url . '/' . drupal_get_path("module", "itg_be_lucky_today") . '/images/logo.png" alt="India Today Group"></a>',
      '#prefix' => '<div class="body-center">'
    );
    $form['header'] = array(
      '#markup' => '<h1>Be Lucky Today</h1>',
      '#suffix' => '</div>'
    );
    $form['message'] = array(
      '#markup' => '<h2>Thank You<br />for your Participation.</h2>',
      '#prefix' => '<div class="thank_you_text">',
    );
    $form['tsnmessage'] = array(
      '#markup' => '<p>Payment process success.</p>',
      '#suffix' => '</div>',
    );
    $form['socialshare'] = array(
      '#markup' => $html,
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Increase your Chances'),
    );
    return $form;
}

/**
 * 
 * @param type $form
 * @param type $form_state
 */
function thank_you_payment_success_form_submit($form, &$form_state) {
    $email = $_GET['email'];
    $form_state['redirect'] = array(
      'be-lucky-today/be-lucky-form',
      array(
        'query' => array(
          'email' => $email,
        )
      ),
    );
}

/**
 * 
 * @param type $form
 * @param type $form_state
 */
function thank_you_payment_failed_form_submit($form, &$form_state) {
    $email = $_GET['email'];
    $form_state['redirect'] = array(
      'be-lucky-today/be-lucky-form',
      array(
        'query' => array(
          'email' => $email,
        )
      ),
    );
}
