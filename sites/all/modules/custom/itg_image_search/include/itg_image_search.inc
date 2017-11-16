<?php
/**
 * This function use for search image by tags and make listing
 */
function itg_image_search_findimages() {
    $serilizedata = $_POST['formdata'];
    parse_str($serilizedata, $output);
    $tags = $output['terms'];
    $gettagfid = itg_image_search_getimagefid_by_tag($tags);
    print theme('image_listing', array('data' => $gettagfid, 'term' => $tags
    ));
}

/**
 * This function use for save image
 */
function itg_image_search_saveimage() {

    $image_url = $_POST['imageurl'];
  
    $image_name = end(explode('/', $image_url));
    
    $imagedata = file_get_contents($image_url);
    if (!file_exists(file_default_scheme() . '://crop_image')) {
        mkdir(file_default_scheme() . '://crop_image', 0777, TRUE);
    }
    $file = file_save_data($imagedata, file_default_scheme() . '://crop_image/' .$image_name);
    file_usage_add($file, 'itg_image_repository', 'file', $file->fid);
    (array) $file;
    print json_encode($file);
    exit();
}

/**
 * itg_image_search_get_dimension
 */
function itg_image_search_get_dimension() {

    $image_url = $_POST['imageurl'];
    if (strpos($image_url, 'styles/thumbnail')) {
        $image_url = str_replace('styles/thumbnail/public/', '', $image_url);
    }
    $image_name = $_POST['field_name'];
    if ($image_name == "") {
        $image_name = time();
    }
    list($width, $height) = getimagesize($image_url);
    $returndata=array('Width'=>$width,'height'=>$height);
    print '<span class="image-dim">'.$width.'X'.$height.'</span>';    
  
    exit();
}