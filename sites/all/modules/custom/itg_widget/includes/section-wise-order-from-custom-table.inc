<?php

/**
 * @file
 * home page feature ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_from_custom_table($info, $widget_style = NULL) {
    if (is_array($info)) {
        $range = 3;
        // set range of data here
        $rangearray = array('auto-road-trip' => 4,
          'auto-tips-and-tricks' => 3,
          'edu-exam' => 4,
          'budget-reactions' => 4,
          'home-shows' => 5,
          'election-other-story' => 4,
          'home-watch' => 3,
          'india-inc-on-budget' => 4,
          'budget-decoded' => 3,
          'edu-featurefilia' => 4,
          'edu-jobs-and-career' => 4,
          'election-so-sorry' => 1,
          'edu-tips-and-trick' => 10,
          'edu-sample-paper' => 5,
          'edu-from-the-magazine' => 4,
          'edu-gov-jobs' => 4,
          'buying-guid' => 7,
          'standpoint' => 5,
          'edu-notification' => 4,
          'tech-tips' => 4,
          'sport-column' => 3,
          'in-depth' => 6,
          'talking-point' => 4,
          'movies-lifestyle' => 7,
          'movies-celebrities' => 7,
          'oscar-news' => 5,
          'oscar-features' => 6,
          'news-section' => 8);

        if (array_key_exists($widget_style, $rangearray)) {
            $range = $rangearray[$widget_style];
        }

        $cat_id = $info['section'];
        $view_name = $info['view_name'];
        $widget_name = _get_widget_name($view_name, 'page');
        $images = array();
        if ($widget_style == 'talking-point') {
            $valid_content_type = 'story';
            $query = db_select('itg_widget_order_section', 'iwo');
        } else if ($widget_style == 'home-watch' || $widget_style == 'election-so-sorry') {
            $valid_content_type = 'videogallery';
            $query = db_select('itg_widget_order_section', 'iwo');
        } else if ($widget_style == 'standpoint') {
            $valid_content_type = 'photogallery';
            $query = db_select('itg_widget_order_section', 'iwo');
        } else {
            //$valid_content_type = _get_content_type_for_widget($widget_name);
            $query = db_select('itg_widget_order', 'iwo');
        }
        if ($widget_style == 'oscar-news' || $widget_style == 'home-watch' || $widget_style == 'sport-column' || $widget_style == 'budget-decoded' || $widget_style == 'auto-road-trip' || $widget_style == 'in-depth' || $widget_style == 'movies-celebrities' || $widget_style == 'movies-lifestyle' || $widget_style == 'oscar-features' || $widget_style == 'tech-tips' || $widget_style == 'india-inc-on-budget' || $widget_style == 'budget-reactions' || $widget_style == 'election-other-story' || $widget_style == 'home-shows' || $widget_style == 'budget-decoded') {
            $image = 'field_story_extra_small_image';
        }
        if ($widget_style == 'undefined' || $widget_style == '' || $widget_style == 'edu-from-the-magazine' || $widget_style == 'edu-exam' || $widget_style == 'edu-gov-jobs' || $widget_style == 'election-so-sorry' || $widget_style == 'oscar-news' || $widget_style == 'buying-guid' || $widget_style == 'in-depth' || $widget_style == 'movies-celebrities' || $widget_style == 'movies-lifestyle') {
            $image = 'field_story_medium_image';
        }

        if ($widget_style == 'standpoint') {
            $image = 'field_story_extra_large_image';
        }
        
        $query->leftJoin('itg_widget_helper', 'wh', 'wh.nid=iwo.nid');
        //$query->leftJoin('node', 'n', 'n.nid=iwo.nid'); //by shravan 28 oct 2017
        $query->fields('iwo', array('nid', 'weight' , 'extra'));
        $query->fields('wh', array('node_data'));
        $query->condition('iwo.cat_id', $cat_id);
        $query->condition('iwo.widget', $widget_name);
        if ($widget_style == 'talking-point' || $widget_style == 'home-watch' || $widget_style == 'election-so-sorry' || $widget_style == 'standpoint') {
            $query->condition('iwo.content_type', $valid_content_type);
        } else {
            $query->condition('iwo.content_type', 'All');
        }
        $query->condition('wh.node_status', 1)
        //$query->condition('n.status', 1)
        //$query->condition('n.type', $valid_content_type)->condition('n.status', 1)
          ->orderBy('iwo.weight', 'DESC')
          ->orderBy('iwo.nid', 'DESC')
          ->groupBy('iwo.nid')
          ->range(0, $range);
        $result = $query->execute();

        return _get_widget_display_data_as_per_db_result($result);
    }
}

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_for_rhs_from_custom_table($info) {
    if (is_array($info)) {
        $cat_id = $info['section'];
        $view_name = $info['view_name'];
        $widget_name = _get_widget_name($view_name, 'page');
        $valid_content_type = _get_content_type_for_widget($widget_name);

        $query = db_select('itg_widget_order', 'iwo');
        $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
        //join  for field value

        $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
        $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
        $query->fields('mi_file', array('uri'));
        $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
        //end
        $query->fields('iwo', array('nid'))
          ->condition('iwo.cat_id', $cat_id)
          // fix for getting all content type
          ->condition('iwo.widget', $widget_name)
          ->condition('n.type', $valid_content_type)
          ->condition('n.status', '1')
          ->orderBy('iwo.weight', 'DESC')
          ->range(0, 5);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $entity_data = array();
        foreach ($result as $entity_data_node) {
            //$entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
            $entity_data[] = $entity_data_node;
        }
        return $entity_data;
    }
}
