<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for saveUpdatedProfile
 * @pram array
 *
 * @return array
 */
function saveUpdatedProfile($data) {
    global $user;
    // variable declation
    $responce_object = array();
    $authtoken_id = $data['authtoken_id'];
    $user_id = $data['user_id'];
    $first_name = $data['first_name'];
    $last_name = $data['last_name'];
    $email_id = $data['email_id'];
    $phone_number = $data['phone_number'];
    $country = $data['country'];
    $state = $data['state'];
    $city = $data['city'];
    $zipcode = $data['zipcode'];
    $address = $data['address'];
    $profile_image = $data['profile_image'];
    $gender = $data['gender'];
    $date_of_birth = $data['date_of_birth'];
    $date_of_birth = strtotime($date_of_birth);
    $date_of_birth = date('Y-m-d', $date_of_birth);
    // taxonomy_get_term_by_name_and_vocabulary
    $country_tid = "";
    $state_tid = "";
    $city_tid = "";
    $country_tid_ar = taxonomy_get_term_by_name($country, 'country');
    $state_tid_ar = taxonomy_get_term_by_name($state, 'state');
    $city_tid_ar = taxonomy_get_term_by_name($city, 'city');

    $country_tid_ar = array_shift(array_values($country_tid_ar));
    $state_tid_ar = array_shift(array_values($state_tid_ar));
    $city_tid_ar = array_shift(array_values($city_tid_ar));

    $country_tid = $country_tid_ar->tid;
    $state_tid = $state_tid_ar->tid;
    $city_tid = $city_tid_ar->tid;
    // upadte script
    $inputs = $data;
    $user = $user_detail = user_load_by_name($user_id);
    $uid = $user->uid;

    // Update First Name.
    if (!empty($data['first_name'])) {
        $user_detail->field_first_name['und'][0]['value'] = check_plain($first_name);
    }

    // Update Last Name.
    if (!empty($data['last_name'])) {
        $user_detail->field_last_name['und'][0]['value'] = check_plain($last_name);
    }
    // Update dob field.
    if (!empty($data['date_of_birth'])) {
        $user_detail->field_story_issue_date['und'][0]['value'] = check_plain($date_of_birth);
    }

    // Update gender field.
    if (!empty($data['gender'])) {
        $user_detail->field_user_gender['und'][0]['value'] = check_plain($gender);
    }

    // Update profile pic
    // check mime-type
    $profile_img = base64_decode($profile_image);
    $f = finfo_open();
    $mime_type = finfo_buffer($f, $profile_img, FILEINFO_MIME_TYPE);
    $mime_type_ar = explode("/", $mime_type);
    $mime_type_ext = $mime_type_ar[1];

    $profile_img_tmp = '/tmp/profileimage_' . $uid . "." . $mime_type_ext;

    $image_name = 'profileimage_' . $uid . "." . $mime_type_ext;
    // crate profile img tmp file
    file_put_contents($profile_img_tmp, $profile_img);
    $imagedata = file_get_contents($profile_img_tmp);
    $file_data = file_save_data($imagedata, file_default_scheme() . '://' . $image_name);

    // Update profile pic
    if (!empty($file_data->fid)) {
        $user_detail->field_user_picture['und'][0]['fid'] = $file_data->fid;
    }
    // Update address field.
    if (!empty($data['address'])) {
        $user_detail->field_short_description['und'][0]['value'] = check_plain($address);
    }

    // Update zipcode field.
    if (!empty($data['zipcode'])) {
        $user_detail->field_user_pincode['und'][0]['value'] = check_plain($zipcode);
    }
    // Save user object.
    $flag_save = user_save($user_detail);
    // responce object
    if ($flag_save->uid) {
        $responce_object['status_code'] = "1";
        $responce_object['status_message'] = "customised_message";
    } else {
        $responce_object['status_code'] = "0";
        $responce_object['status_message'] = "";
    }
    return $responce_object;
}
