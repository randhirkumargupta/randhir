<?php
/**
 * Master config internal menu callback
 * @param array $form
 * @param array $form_state
 * @return array
 */
$fids = array();
  foreach ($node['upload']['#value'] as $img) {
    // Save media file.
    $scheme = variable_get('file_default_scheme', 'public') . '://';
    $source = $img['tmppath'];

    $directory = '';
    $destination = file_stream_wrapper_uri_normalize($scheme . $directory . $img['name']);
    $destination = file_unmanaged_move($source, $destination, FILE_EXISTS_RENAME);
    global $user;
    // Create the file object.
    $uri = file_stream_wrapper_uri_normalize($destination);
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $file = new StdClass;
    $file->uid = $user->uid;
    $file->filename = basename($uri);
    $file->uri = $uri;
    $file->filemime = file_get_mimetype($uri);
    $file->filesize = @filesize($uri);
    $file->timestamp = REQUEST_TIME;
    // $file->status = FILE_STATUS_PERMANENT;
    $file->is_new = TRUE;
    $file->status = FILE_STATUS_PERMANENT;
    $fids[] = file_save($file);
    file_usage_add($file, 'file', 'field_collection_item', '1');
  }