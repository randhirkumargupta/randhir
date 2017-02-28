<?php

/**
 * @file
 * Implements the file browser.
 */

/**
 * q = itg_image_repository.
 */
function itg_image_repository($scheme = NULL) {

    module_invoke('admin_menu', 'suppress'); //suppress admin_menu
    $jsop = isset($_GET['jsop']) ? $_GET['jsop'] : NULL;
    drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
    print itg_image_repository_page($GLOBALS['user'], $scheme, $jsop);
    exit();
}

/**
 * q = user/x/itg_image_repository.
 */
function itg_image_repository_user_page($account) {
    return theme('itg_image_repository_user_page', array('account' => $account));
}

/**
 * Returns the itg_image_repository page for the specified user and the file scheme.
 */
function itg_image_repository_page($user, $scheme = NULL, $jsop = NULL) {
    return theme('itg_image_repository_page', array('content' => itg_image_repository_content($user, $scheme, $jsop)));
}

/**
 * Returns the content of the file browser.
 */
function itg_image_repository_content($user, $scheme = NULL, $jsop = NULL) {

    //execute ajax calls.
    if ($jsop) {
        return itg_image_repository_js($user, $scheme, $jsop);
    }

    //initiate configuration profile
    if (!$itg_image_repository = itg_image_repository_initiate_profile($user, $scheme)) {
        return '';
    }
   //p($itg_image_repository);
    //p($itg_image_repository)
    //itg_image_repository_process_profile($itg_image_repository); //get active directory content
    //Before creating the content let's add main files required for itg_image_repository to function properly.
    $path = drupal_get_path('module', 'itg_image_repository');
    drupal_add_js($path . '/js/jquery.form.js');
    drupal_add_js($path . '/js/itg_image_repository.js');
    drupal_add_js($path . '/js/itg_image_repository_extras.js');
    drupal_add_js($path . '/js/dropzone.js');

    drupal_add_css($path . '/css/itg_image_repository-content.css');
    drupal_add_css($path . '/css/dropzone.css');
    drupal_add_js($path . '/js/imce.js');
    drupal_add_js($path . '/js/imce_extras.js');

    //process forms.
    $itg_image_repository_ref = array('itg_image_repository' => &$itg_image_repository);

    $forms = array();
    if (!$itg_image_repository['error']) {
        //process file upload.
        if (itg_image_repository_perm_exists($itg_image_repository, 'upload')) {
            $forms[] = drupal_get_form('itg_image_repository_upload_form', $itg_image_repository_ref);
        }
        //process file operations.
        $forms[] = drupal_get_form('itg_image_repository_filesearch_form', $itg_image_repository_ref);
    }
    $forms = drupal_render($forms);

    //run custom content functions. possible to insert extra forms. content is invisible when js is enabled.
    foreach (variable_get('imce_custom_content', array()) as $func => $state) {
        if ($state && function_exists($func) && $output = $func($itg_image_repository)) {
            $forms .= $output;
        }
    }

    $content = theme('itg_image_repository_content', array(
        'tree' => itg_image_repository_create_tree($itg_image_repository),
        'forms' => $forms,
        'itg_image_repository_ref' => $itg_image_repository_ref,
    ));

    //make necessary changes for js conversion
    $itg_image_repository['dir'] = str_replace('%2F', '/', rawurlencode($itg_image_repository['dir']));
    unset($itg_image_repository['files'], $itg_image_repository['name'], $itg_image_repository['directories'], $itg_image_repository['subdirectories'], $itg_image_repository['filesize'], $itg_image_repository['quota'], $itg_image_repository['tuquota'], $itg_image_repository['thumbnails'], $itg_image_repository['uid'], $itg_image_repository['usertab']);

    drupal_add_js($itg_image_repository_ref, 'setting');

    return $content;
}

/**
 * Ajax operations. q=itg_image_repository&jsop={op}
 */
function itg_image_repository_js($user, $scheme, $jsop = '') {
    $response = array();
    //data
    if ($itg_image_repository = itg_image_repository_initiate_profile($user, $scheme)) {
       // itg_image_repository_process_profile($itg_image_repository);
       // if (!$itg_image_repository['error']) {
            module_load_include('inc', 'itg_image_repository', 'inc/itg_image_repository.js');
            if (function_exists($func = 'itg_image_repository_js_' . $jsop)) {
                $response['data'] = $func($itg_image_repository);
            }
            // Allow alteration of response.
            foreach (variable_get('imce_custom_response', array()) as $func => $state) {
                if ($state && function_exists($func)) {
                    $func($jsop, $response, $itg_image_repository, $user);
                }
            }
      //  }
    }
    //messages
    $response['messages'] = drupal_get_messages();

    //disable devel log.
    $GLOBALS['devel_shutdown'] = FALSE;
    //for upload we must return plain text header.
    drupal_add_http_header('Content-Type', (!empty($_POST['html_response']) ? 'text/html' : 'application/json') . '; charset=utf-8');
    print drupal_json_encode($response);
    exit();
}

/**
 * Upload form.
 */
function itg_image_repository_upload_form($form, &$form_state, $ref) {


    $itg_image_repository = & $ref['itg_image_repository'];

    $form['upload'] = array(
        '#type' => 'submit',
        '#value' => t('Upload'),
        '#submit' => $itg_image_repository['perm']['upload'] ? array('itg_image_repository_upload_submit') : NULL,
    );
    $form['html_response'] = array('#type' => 'hidden', '#default_value' => '1');
    $form['#attributes']['enctype'] = 'multipart/form-data';
    $form['#attributes']['class'] = 'dropzone';
    $form['#action'] = $itg_image_repository['url'] . '?jsop=upload&dir=gallery';
    return $form;
}

/**
 * File operations form.
 */
function itg_image_repository_filesearch_form($form, &$form_state, $ref) {
    $itg_image_repository = & $ref['itg_image_repository'];
    return $form;
}

/**
 * Submit upload form.
 */
function itg_image_repository_upload_submit($form, &$form_state) {

    $form_state['redirect'] = FALSE;
    $itg_image_repository = & $form_state['build_info']['args'][0]['itg_image_repository'];
    // Need to provide extension validatior, otherwise file_save_upload uses the default.
    $validators['file_validate_extensions'] = array($itg_image_repository['extensions'] === '*' ? NULL : $itg_image_repository['extensions']);
    $validators['itg_image_repository_validate_all'] = array(&$itg_image_repository);
    $diruri = itg_image_repository_dir_uri($itg_image_repository);


    $replace = variable_get('imce_settings_replace', FILE_EXISTS_RENAME);
   // $file = file_save_upload('imce', $validators, $diruri, $replace);

    if ($file = file_save_upload('imce', $validators, $diruri, $replace)) {

        //core bug #54223.
        if ($replace == FILE_EXISTS_RENAME) {
            $name = basename($file->uri);
            if ($name != $file->filename) {
                $file->filename = $name;
                drupal_set_message(t('The file has been renamed to %filename.', array('%filename' => $file->filename)));
            }
        }

        $file->uid = $itg_image_repository['uid']; //global user may not be the owner.
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        itg_image_repository_file_register($file);
        drupal_set_message(t('%filename has been uploaded.', array('%filename' => $file->filename)));

        //update file list
        $img = itg_image_repository_image_info($file->uri);
        $file->width = $img ? $img['width'] : 0;
        $file->height = $img ? $img['height'] : 0;

        itg_image_repository_add_file($file, $itg_image_repository);

        //create thumbnails
        if (isset($form_state['values']['thumbnails']) && $img) {
            itg_image_repository_create_thumbnails($file->filename, $itg_image_repository, $form_state['values']['thumbnails']);
        }
    }
    else {
        drupal_set_message(t('Upload failed.'), 'error');
    }
}

/**
 * Submit thumbnail form.
 */
function itg_image_repository_thumb_submit($form, &$form_state) {
    $form_state['redirect'] = FALSE;
    $itg_image_repository = & $form_state['build_info']['args'][0]['itg_image_repository'];
    //create thumbnails
    itg_image_repository_process_files($form_state['values']['filenames'], $itg_image_repository, 'itg_image_repository_create_thumbnails', array($form_state['values']['thumbnails']));
}

/**
 * Submit delete form.
 */
function itg_image_repository_delete_submit($form, &$form_state) {
    $form_state['redirect'] = FALSE;
    $itg_image_repository = & $form_state['build_info']['args'][0]['itg_image_repository'];

    $deleted = itg_image_repository_process_files($form_state['values']['filenames'], $itg_image_repository, 'itg_image_repository_delete_file');

    if (!empty($deleted)) {
        drupal_set_message(t('File deletion successful: %files.', array('%files' => utf8_encode(implode(', ', $deleted)))));
    }
}

/**
 * Do batch operations on files.
 * Used by delete, resize, create thumbnail submissions.
 */
function itg_image_repository_process_files($filenames, &$itg_image_repository, $function, $args = array()) {

    $args = array_merge(array('', &$itg_image_repository), $args);
    $processed = array();

    foreach ($filenames as $filename) {
        $args[0] = $filename;
        if (call_user_func_array($function, $args)) {
            $processed[] = $filename;
        }
    }

    return $processed;
}

/**
 * Add a new file to the file list.
 */
function itg_image_repository_add_file($file, &$itg_image_repository) {

    $itg_image_repository['dirsize'] += $file->filesize;
    if (isset($itg_image_repository['files'][$file->filename])) {
        $itg_image_repository['dirsize'] -= $itg_image_repository['files'][$file->filename]['size'];
    }
    $file_url = file_create_url($file->uri);
    $itg_image_repository['files'][$file->filename] = array(
    'name' => $file->filename,
    'size' => $file->filesize,
    'file_uri' => $file_url ,
    'width' => $file->width,
    'height' => $file->height,
    'date' => $file->timestamp
    );
  
    if (isset($_GET['jsop'])) {
        $add = $itg_image_repository['files'][$file->filename];
        $add['name'] = rawurlencode($file->filename);
        $add['file_uri'] = $file_url;
        $add['fsize'] = format_size($file->filesize);
        $add['fdate'] = format_date($file->timestamp, 'short');
        $add['id'] = $file->fid;
        $itg_image_repository['added'][] = $add;
    }
}

/**
 * Validate uploaded file.
 */
function itg_image_repository_validate_all($file, $itg_image_repository) {

    //validate image resolution only if filesize validation passes.
    //because user might have uploaded a very big image
    //and scaling it may exploit system memory.
    $errors = itg_image_repository_validate_filesize($file, $itg_image_repository['filesize']);
    //image resolution validation
    if (empty($errors) && preg_match('/\.(png|gif|jpe?g)$/i', $file->filename)) {
        $errors = array_merge($errors, file_validate_image_resolution($file, $itg_image_repository['dimensions']));
    }
    //directory quota validation
    if ($itg_image_repository['quota']) {
        $errors = array_merge($errors, itg_image_repository_validate_quota($file, $itg_image_repository['quota'], $itg_image_repository['dirsize']));
    }
    //user quota validation. check it if no errors were thrown.
    if (empty($errors) && $itg_image_repository['tuquota']) {
        $errors = itg_image_repository_validate_tuquota($file, $itg_image_repository['tuquota'], file_space_used($itg_image_repository['uid']));
    }
    return $errors;
}

/**
 * Validate filesize for maximum allowed file size.
 */
function itg_image_repository_validate_filesize($file, $maxsize = 0) {
    $errors = array();
    if ($maxsize && $file->filesize > $maxsize) {
        $errors[] = t('The file is %filesize exceeding the maximum file size of %maxsize.', array('%filesize' => format_size($file->filesize), '%maxsize' => format_size($maxsize)));
    }
    return $errors;
}

/**
 * Validate filesize for directory quota.
 */
function itg_image_repository_validate_quota($file, $quota = 0, $currentsize = 0) {
    $errors = array();
    if ($quota && ($currentsize + $file->filesize) > $quota) {
        $errors[] = t('%filename is %filesize which would exceed your directory quota. You are currently using %size of %total_quota.', array('%size' => format_size($currentsize), '%total_quota' => format_size($quota), '%filesize' => format_size($file->filesize), '%filename' => utf8_encode($file->filename)));
    }
    return $errors;
}

/**
 * Validate filesize for total user quota.
 */
function itg_image_repository_validate_tuquota($file, $quota = 0, $currentsize = 0) {
    $errors = array();
    if ($quota && ($currentsize + $file->filesize) > $quota) {
        $errors[] = t('%filename is %filesize which would exceed your total user quota. You are currently using %size of %total_quota.', array('%size' => format_size($currentsize), '%total_quota' => format_size($quota), '%filesize' => format_size($file->filesize), '%filename' => utf8_encode($file->filename)));
    }
    return $errors;
}

/**
 * Validate both directory and total user quota. Returns true/false not errors.
 */
function itg_image_repository_validate_quotas($file, &$itg_image_repository, $add = 0) {
    $errors = itg_image_repository_validate_quota($file, $itg_image_repository['quota'], $itg_image_repository['dirsize'] + $add);
    if (empty($errors) && $itg_image_repository['tuquota']) {
        $errors = itg_image_repository_validate_tuquota($file, $itg_image_repository['tuquota'], file_space_used($itg_image_repository['uid']) + $add);
    }
    if (!empty($errors)) {
        drupal_set_message($errors[0], 'error');
        return FALSE;
    }
    return TRUE;
}

/**
 * Checks if the file is an image and returns info.
 * There are two switchable versions that use image_get_info() and getimagesize()
 */
if (variable_get('imce_image_get_info', 0)) {

    function itg_image_repository_image_info($file) {
        $mimes = array('image/jpeg' => IMAGETYPE_JPEG, 'image/gif' => IMAGETYPE_GIF, 'image/png' => IMAGETYPE_PNG);
        if (is_file($file) && ($dot = strrpos($file, '.')) && in_array(strtolower(substr($file, $dot + 1)), array('jpg', 'jpeg', 'gif', 'png')) && ($info = @image_get_info($file)) && isset($mimes[$info['mime_type']])) {
            return array('width' => $info['width'], 'height' => $info['height'], 'type' => $mimes[$info['mime_type']], 'mime' => $info['mime_type']);
        }
        return FALSE;
    }

}
else {

    function itg_image_repository_image_info($file) {
        if (is_file($file) && ($dot = strrpos($file, '.')) && in_array(strtolower(substr($file, $dot + 1)), array('jpg', 'jpeg', 'gif', 'png')) && ($info = @getimagesize($file)) && in_array($info[2], array(IMAGETYPE_JPEG, IMAGETYPE_GIF, IMAGETYPE_PNG))) {
            return array('width' => $info[0], 'height' => $info[1], 'type' => $info[2], 'mime' => $info['mime']);
        }
        return FALSE;
    }

}

/**
 * Return thumbnails as options to be used in upload form.
 */
function itg_image_repository_thumbnail_options($thumbs = array()) {
    $options = array();
    foreach ($thumbs as $thumb) {
        $options[$thumb['name']] = $thumb['name'] . ' (' . $thumb['dimensions'] . ')';
    }
    return $options;
}

/**
 * Initiate and return configuration profile for the $user.
 */
function itg_image_repository_initiate_profile($user, $scheme = NULL) {

    //check user profile and translate tokens in directory paths and evaluate php paths.
    if ($itg_image_repository = itg_image_repository_user_profile($user, $scheme)) {
        // Allow alteration of raw profile
        foreach (variable_get('imce_custom_init', array()) as $func => $state) {
            if ($state && function_exists($func)) {
                $func($itg_image_repository, $user);
            }
        }
        itg_image_repository_process_directories($itg_image_repository, $user);
        if (!empty($itg_image_repository['directories'])) {
            $itg_image_repository['uid'] = (int) $user->uid;
            $itg_image_repository['url'] = url($_GET['q']);
            $itg_image_repository['clean'] = variable_get('clean_url', 0) == 1;
            $itg_image_repository['absurls'] = variable_get('imce_settings_absurls', 0) == 1;
            $itg_image_repository['furl'] = file_create_url($itg_image_repository['scheme'] . '://');
            $itg_image_repository['filesize'] *= 1048576; //convert from Mb to byte
            $itg_image_repository['quota'] *= 1048576;
            $itg_image_repository['tuquota'] *= 1048576;
            $itg_image_repository['filenum'] = (int) $itg_image_repository['filenum'];
            //check and set the active directory
            if ($info = itg_image_repository_working_directory($itg_image_repository)) {
                $itg_image_repository['direct'] = isset($itg_image_repository['directories'][$info['name']]);
                $itg_image_repository['directories'][$info['name']] = $info;
                $itg_image_repository['dir'] = $info['name'];
                $itg_image_repository['perm'] = $info; //copy permissions of the active directory.
                unset($itg_image_repository['perm']['name']);
            }
            else {
                drupal_set_message(t('Unable to get a working directory for the file browser!'), 'error');
                $itg_image_repository['dir'] = FALSE;
                $itg_image_repository['error'] = TRUE;
            }
            return $itg_image_repository;
        }
        drupal_set_message(t('There is no valid directory specified for the file browser!'), 'error');
    }
    else {
        drupal_set_message(t('You do not have access to any configuration profile to use the file browser!'), 'error');
    }

    return FALSE;
}

/**
 * Get files and folders of the actve directory. Do custom processing.
 */
function itg_image_repository_process_profile(&$itg_image_repository) {
    //get directory content. do a custom scan if it is set
    $scan = ($scan = variable_get('imce_custom_scan', '')) && function_exists($scan) ? $scan : 'itg_image_repository_scan_directory';
    $itg_image_repository += $scan($itg_image_repository['dir'], $itg_image_repository);

    //run custom process functions
    foreach (variable_get('imce_custom_process', array()) as $func => $state) {
        if ($state && function_exists($func)) {
            $func($itg_image_repository);
        }
    }

    //set subdirectories
    if (!$itg_image_repository['error'] && !itg_image_repository_subdirectories_accessible($itg_image_repository)) {
        $itg_image_repository['subdirectories'] = array();
    }
}

/**
 * Translate tokens and evaluate php in directory names.
 * Convert directories into an associative array (dirname => info)
 */
function itg_image_repository_process_directories(&$itg_image_repository, $user) {
    $directories = $itg_image_repository['directories'];
    $paths = array();
    $translate = array('%uid' => $user->uid);

    foreach ($directories as $directory) {
        if (substr($directory['name'], 0, 4) == 'php:') {
            $directory['name'] = @eval(substr($directory['name'], 4));
            //php may return an array of directories
            if (is_array($directory['name'])) {
                foreach ($directory['name'] as $name) {
                    $paths[$name] = array('name' => $name) + $directory;
                }
                continue;
            }
        }
        else {
            $directory['name'] = strtr($directory['name'], $translate);
        }
        if ($directory['name']) {
            $paths[$directory['name']] = $directory;
        }
    }

    $itg_image_repository['directories'] = $paths;
}

/**
 * Return an avaliable directory for the profile.
 */
function itg_image_repository_working_directory(&$itg_image_repository) {
    //Do not use session if there is only one directory assigned.
    $sess = TRUE;
    if (count($itg_image_repository['directories']) < 2) {
        $perms = reset($itg_image_repository['directories']);
        if (!isset($perms['subnav']) || !$perms['subnav']) {
            $sess = FALSE;
        }
    }
    //check GET.
    if (isset($_GET['dir'])) {
        if ($info = itg_image_repository_directory_info($_GET['dir'], $itg_image_repository)) {
            if (itg_image_repository_check_directory($_GET['dir'], $itg_image_repository)) {
                if ($sess) {
                    $_SESSION['itg_image_repository_directory'] = rawurlencode($info['name']);
                }
            }
            else {
                $info = FALSE;
            }
        }
        else {
            itg_image_repository_inaccessible_directory($_GET['dir'], $itg_image_repository);
        }
        return $info;
    }

    //check session
    if ($sess && isset($_SESSION['itg_image_repository_directory'])) {
        $dirname = rawurldecode($_SESSION['itg_image_repository_directory']);
        if ($info = itg_image_repository_directory_info($dirname, $itg_image_repository)) {
            if (itg_image_repository_check_directory($dirname, $itg_image_repository)) {
                return $info;
            }
        }
    }

    //or the whole list.
    foreach ($itg_image_repository['directories'] as $dirname => $info) {
        $dirname = (string) $dirname;
        if (itg_image_repository_check_directory($dirname, $itg_image_repository)) {
            if ($sess) {
                $_SESSION['itg_image_repository_directory'] = rawurlencode($dirname);
            }
            return $info;
        }
    }

    return FALSE;
}

/**
 * Create a writable directory(any level) under file system directory.
 */
function itg_image_repository_check_directory($dirname, $itg_image_repository) {
    $diruri = itg_image_repository_dir_uri($itg_image_repository, $dirname);

    if (!itg_image_repository_reg_dir($dirname) || !file_prepare_directory($diruri, FILE_CREATE_DIRECTORY)) {
        return itg_image_repository_inaccessible_directory($dirname, $itg_image_repository);
    }

    return TRUE;
}

/**
 * Generate and log a directory access error.
 */
function itg_image_repository_inaccessible_directory($dirname, $itg_image_repository) {
    if (is_string($dirname)) {
        $dirname = utf8_encode($dirname);
        $diruri = itg_image_repository_dir_uri($itg_image_repository, $dirname);
        drupal_set_message(t('Directory %dirname is not accessible.', array('%dirname' => $dirname)), 'error');
        watchdog('itg_image_repository', 'Access to %directory was denied.', array('%directory' => $diruri), WATCHDOG_ERROR);
    }
    return FALSE;
}

/**
 * Return the permissions for a directory that is accessed directly or indirectly.
 * A child of a predefined directory in the directory list takes its parent's properties.
 * If it has multiple parents, it gets the properties of the latter in the list.
 */
function itg_image_repository_directory_info($dirname, $itg_image_repository) {

    if (isset($itg_image_repository['directories'][$dirname])) {
        return $itg_image_repository['directories'][$dirname];
    }

    $info = FALSE;
    if (itg_image_repository_reg_dir($dirname)) {
        $diruri = itg_image_repository_dir_uri($itg_image_repository, $dirname);
        if (file_prepare_directory($diruri)) {
            foreach ($itg_image_repository['directories'] as $name => $prop) {
                if ($prop['subnav'] && ($name === '.' || strpos($dirname . '/', $name . '/') === 0)) {
                    $info = $prop;
                    $info['name'] = $dirname;
                }
            }
        }
    }

    return $info;
}

/**
 * Detect if the subdirectories are accessible through any directory(not just the current one) in the list.
 */
function itg_image_repository_subdirectories_accessible(&$itg_image_repository) {

    if (!empty($itg_image_repository['subdirectories'])) {
        if (!empty($itg_image_repository['perm']['subnav'])) {
            return TRUE;
        }
        //checking only the first one is sufficient.
        $dirname = ($itg_image_repository['dir'] == '.' ? '' : $itg_image_repository['dir'] . '/') . $itg_image_repository['subdirectories'][0];

        //check if any setting is applicable for this subdirectory through any directory in the list.
        foreach ($itg_image_repository['directories'] as $name => $info) {
            $name = (string) $name;
            if ($info['subnav'] && $dirname != $name && ($name == '.' || strpos($dirname . '/', $name . '/') === 0)) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

/**
 * Check if a permission is given to at least one directory in the list.
 */
function itg_image_repository_perm_exists(&$itg_image_repository, $perm) {
    static $perms = array();

    if (isset($perms[$perm])) {
        return $perms[$perm];
    }

    if (isset($itg_image_repository['perm'][$perm]) && $itg_image_repository['perm'][$perm]) {
        return $perms[$perm] = TRUE;
    }

    foreach ($itg_image_repository['directories'] as $name => $info) {
        if (isset($info[$perm]) && $info[$perm]) {
            return $perms[$perm] = TRUE;
        }
    }

    return $perms[$perm] = FALSE;
}

/**
 * Scan directory and return file list, subdirectories, and total size.
 */
function itg_image_repository_scan_directory($dirname, $itg_image_repository) {

    $directory = array('dirsize' => 0, 'files' => array(), 'subdirectories' => array(), 'error' => FALSE);
    $diruri = itg_image_repository_dir_uri($itg_image_repository, $dirname);

    if (!is_string($dirname) || $dirname == '' || !$handle = opendir($diruri)) {
        itg_image_repository_inaccessible_directory($dirname, $itg_image_repository);
        $directory['error'] = TRUE;
        return $directory;
    }

    while (($file = readdir($handle)) !== FALSE) {

        // Do not include dot files and folders
        if (substr($file, 0, 1) === '.') {
            continue;
        }

        $path = $diruri . $file;

        if (is_dir($path)) {
            $directory['subdirectories'][] = $file;
            continue;
        }

        $width = $height = 0;
        if ($img = itg_image_repository_image_info($path)) {
            $width = $img['width'];
            $height = $img['height'];
        }
        $size = filesize($path);
        $date = filemtime($path);
        $directory['files'][$file] = array(
            'name' => $file,
            'size' => $size,
            'width' => $width,
            'height' => $height,
            'date' => $date
        );
        $directory['dirsize'] += $size;
    }

    closedir($handle);
    sort($directory['subdirectories']);
    return $directory;
}

/**
 * Create directory tree.
 */
function itg_image_repository_create_tree(&$itg_image_repository) {
    $paths = array();
    //rearrange paths as arg0=>arg1=>...
    foreach ($itg_image_repository['directories'] as $path => $arr) {
        $tmp = & $paths;
        if ($path != '.') {
            $args = explode('/', $path);
            foreach ($args as $arg) {
                if (!isset($tmp[$arg])) {
                    $tmp[$arg] = array();
                }
                $tmp = & $tmp[$arg];
            }
            $tmp[':access:'] = TRUE;
        }
        if ("$path" == $itg_image_repository['dir']) {
            $tmp[':active:'] = TRUE;
            foreach ($itg_image_repository['subdirectories'] as $arg) {
                $tmp[$arg][':access:'] = TRUE;
            }
        }
    }
    //set root branch
    $root = theme('itg_image_repository_root_text', array('itg_image_repository_ref' => array('itg_image_repository' => &$itg_image_repository)));
    $q = $itg_image_repository['clean'] ? '?' : '&';
    if (isset($itg_image_repository['directories']['.'])) {
        $root = '<a href="' . $itg_image_repository['url'] . $q . 'dir=." title="." class="folder' . ($itg_image_repository['dir'] == '.' ? ' active' : '') . '">' . $root . '</a>';
    }
    else {
        $root = '<a title="." class="folder disabled">' . $root . '</a>';
    }

    return $root . itg_image_repository_tree_html($itg_image_repository, $paths, $q);
}

/**
 * Return tree html.
 * This is not themable because it is complex and needs to be in a proper format for js processing.
 */
function itg_image_repository_tree_html(&$itg_image_repository, $paths, $q = '?', $prefix = '', $eprefix = '') {
    unset($paths[':access:'], $paths[':active:']);
    $html = '';
    foreach ($paths as $arg => $children) {
        $path = $prefix . $arg;
        $earg = rawurlencode($arg);
        $epath = $eprefix . $earg;
        if (isset($children[':access:']) || itg_image_repository_directory_info($path, $itg_image_repository)) {
            $a = '<a href="' . $itg_image_repository['url'] . $q . 'dir=' . $epath . '" title="' . $epath . '" class="folder' . (isset($children[':active:']) ? ' active' : '') . '">' . $earg . '</a>';
        }
        else {
            $a = '<a title="' . $epath . '" class="folder disabled">' . $earg . '</a>';
        }
        $ul = itg_image_repository_tree_html($itg_image_repository, $children, $q, $path . '/', $epath . '/');
        $class = $ul ? ' class="expanded"' : (isset($children[':active:']) ? ' class="leaf"' : '');
        $html .= '<li' . $class . '>' . $a . $ul . '</li>';
    }
    if ($html) {
        $html = '<ul>' . $html . '</ul>';
    }
    return $html;
}

/**
 * Return the uri of the active directory
 */
function itg_image_repository_dir_uri($itg_image_repository, $dir = NULL) {
    if (!isset($dir)) {
        $dir = $itg_image_repository['dir'];
    }
    return $itg_image_repository['scheme'] . '://' . ($dir == '.' ? '' : $dir . '/');
}

/**
 * Returns the text for the root directory in a directory tree.
 */
function theme_itg_image_repository_root_text($variables) {
    //$itg_image_repository = &$variables['itg_image_repository_ref']['itg_image_repository'];
    return '&lt;' . t('root') . '&gt;';
}

/**
 * Returns the html for user's file browser tab.
 */

/**
 * Registers the file as an itg_image_repository file.
 */
function itg_image_repository_file_register($file) {
    if (!db_query("SELECT 1 FROM {file_usage} WHERE module = 'itg_image_repository' AND fid = :fid", array(':fid' => $file->fid))->fetchField()) {
        file_usage_add($file, 'itg_image_repository', 'file', $file->fid);
    }
}
