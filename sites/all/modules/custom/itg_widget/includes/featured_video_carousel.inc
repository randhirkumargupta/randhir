<?php

/**
 * @file
 * home page feature ordering and reordering
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @param string $slider_type
 * @return array
 */
function itg_widget_featured_video_carousel_data($info, $slider_type) {
    $data = '';
    if (is_array($info)) {
       // watchdog('Widget', 'inside Home page feature query');
        $result = itg_widget_get_widget_data_data($info);
        return itg_widget_featured_video_carousel_data_fetch($result, $slider_type);
    }
    return $data;
}

/**
 * @param array $result
 * @param string $slider_type
 * @return array
 */
function itg_widget_featured_video_carousel_data_fetch($result, $slider_type) {
    $data_render = array();
    global $base_url;
    $style = '';
    if ($slider_type == 'flexslider') {
        //$style = 'photo_carousel_flexslider';
    }
    if ($slider_type == 'rolling') {
        //  $style = 'photo_carousel_rollingslider';
    }
    $sid = '';
    if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
        $sid = arg(2);
        $section_cat_id = get_first_category_of_media_widget(arg(2), 'page--section_video', 'video_list_of_category');
    }
    foreach ($result as $key => $data) {
        $node = node_load($data['nid']);
        // $data_render[$data['entity_id']]['file_url'] = theme('image_style', array('style_name' => $style, 'path' => $node->field_story_extra_large_image[$node->language][0]['uri']));
        $file_uri = $data['uri'];
        $data_render[$data['nid']]['file_url'] = file_create_url($file_uri);
        $data_render[$data['nid']]['count'] = count($node->field_videogallery_video_upload[$node->language]);
        $data_render[$data['nid']]['caption'] = $node->field_story_extra_large_image[$node->language][0]['title'];
        $data_render[$data['nid']]['node_url'] = $base_url . '/' . drupal_get_path_alias('node/' . $data['nid']);
        $data_render[$data['nid']]['title'] = $node->title;
        $data_render[$data['nid']]['nid'] = $node->nid;
        $data_render[$data['nid']]['primary_category'] = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
        $data_render[$data['nid']]['sid'] = $sid;
        $data_render[$data['nid']]['cat'] = $section_cat_id;
        $data_render[$data['nid']]['image_alt'] = $node->field_story_extra_large_image[$node->language][0]['alt'];
        $data_render[$data['nid']]['image_title'] = $node->field_story_extra_large_image[$node->language][0]['title'];
    }
    return $data_render;
}
