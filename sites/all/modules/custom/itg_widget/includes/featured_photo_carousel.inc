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
//function itg_widget_featured_photo_carousel_data($info, $slider_type) {
//    $data = '';
//    if (is_array($info)) {
//        //watchdog('Widget', 'inside Home page feature query');
//        $view_name = isset($info['view_name']) ? $info['view_name'] : "";
//        $page = isset($info['page']) ? $info['page'] : "";
//        // condition to validate
//        if (!empty($view_name) && !empty($page)) {
//            $result = draggable_views_nodes_for_widgets($view_name, $page, "NOT", PHOTO_CAROUSEL_MIN_RANGE, PHOTO_CAROUSEL_MAX_RANGE);
//            if (empty($result)) {
//                $nodequeue_name = isset($info['nodequeue']) ? $info['nodequeue'] : "";
//                $result = itg_widget_nodes_from_nodequeue($nodequeue_name, TRUE, PHOTO_CAROUSEL_MIN_RANGE, PHOTO_CAROUSEL_MAX_RANGE);
//            }
//            return itg_widget_featured_photo_carousel_data_fetch($result, $slider_type);
//        }
//    }
//    return $data;
//}

/**
 * @param array $result
 * @param string $slider_type
 * @return array
 */
function itg_widget_featured_photo_carousel_data_fetch($result, $slider_type) {
    $data_render = array();
    global $base_url;
    $style = '';
    if ($slider_type == 'flexslider') {
        //$style = 'image_750x363';
    }
    if ($slider_type == 'rolling') {
       // $style = 'photo_carousel_rollingslider';
    }
    if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
        $sid = arg(2);
        $section_cat_id = get_first_category_of_media_widget(arg(2), 'page--section_photo', 'photo_list_of_category');
    }
    foreach ($result as $key => $data) {
        $data['entity_id'] = $data['nid'];
        $node = node_load($data['entity_id']);
        $file_uri = file_create_url($node->field_story_extra_large_image[$node->language][0]['uri']);
        //  $data_render[$data['entity_id']]['file_url'] = theme('image_style', array('style_name' => $style, 'path' => $node->field_story_extra_large_image[$node->language][0]['uri']));
        $data_render[$data['entity_id']]['file_url'] = $file_uri;
        $data_render[$data['entity_id']]['count'] = count($node->field_gallery_image[$node->language]);
        $data_render[$data['entity_id']]['caption'] = $node->field_story_extra_large_image[$node->language][0]['title'];
        $data_render[$data['entity_id']]['node_url'] = $base_url . '/' . drupal_get_path_alias('node/' . $data['entity_id']);
        $data_render[$data['entity_id']]['title'] = $node->title;
        $data_render[$data['entity_id']]['nid'] = $node->nid;
        $data_render[$data['entity_id']]['image_alt'] = $node->field_story_extra_large_image[$node->language][0]['alt'];
        $data_render[$data['entity_id']]['image_title'] = $node->field_story_extra_large_image[$node->language][0]['title'];
        //$data_render[$data['entity_id']]['primary_category'] = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
        $data_render[$data['entity_id']]['sid'] = isset($sid) ? $sid : 0;
        $data_render[$data['entity_id']]['cat'] = isset($section_cat_id) ? $section_cat_id :0;
    }
    return $data_render;
}
