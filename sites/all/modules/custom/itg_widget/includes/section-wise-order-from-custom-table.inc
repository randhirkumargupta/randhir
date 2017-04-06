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
    $rangearray = array('auto-road-trip' => 2,
      'auto-tips-and-tricks' => 3,
      'edu-exam' => 4,
      'budget-reactions' => 4,
      'home-shows' => 4,
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
      'buying-guid' => 6,
      'standpoint' => 5,
      'edu-notification' => 4,
      'tech-tips' => 4,
      'sport-column' => 3,
      'in-depth' => 6,
      'talking-point' => 4,
      'movies-lifestyle' => 7,
      'movies-celebrities' => 7,
      'oscar-news' => 5,
      'oscar-features' => 6);

    if (array_key_exists($widget_style, $rangearray)) {
      $range = $rangearray[$widget_style];
    }
    if ($widget_style == 'talking-point') {
      return itg_widget_section_wise_ordering_from_custom_table_by_content($info, 'story', $widget_style);
    }
    if ($widget_style == 'home-watch' || $widget_style == 'election-so-sorry') {
      return itg_widget_section_wise_ordering_from_custom_table_by_content($info, 'videogallery', $widget_style);
    }
    if ($widget_style == 'standpoint') {
      return itg_widget_section_wise_ordering_from_custom_table_by_content($info, 'photogallery', $widget_style);
    }




    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    //join  for field value
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('sh', array('field_story_short_headline_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
    //end
    $query->fields('iwo', array('nid', 'weight'))
        ->condition('iwo.cat_id', $cat_id)
        // fix for getting all content type
        ->condition('iwo.widget', $widget_name)
        ->condition('iwo.content_type', 'All')
        ->condition('n.status', '1')
        ->orderBy('iwo.weight', 'DESC')
        ->orderBy('n.nid', 'DESC')
        ->groupBy('iwo.nid')
        ->range(0, $range);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      //$entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_data_node;
    }

    return $entity_data;
  }
}

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_from_custom_table_by_content($info, $content = NULL, $widget_style = NULL) {
  if (is_array($info)) {
    $range = 3;
    $from_limit = 0;
    // set range of data here
    $rangearray = array('auto-road-trip' => 2,
      'auto-tips-and-tricks' => 3,
      'edu-exam' => 4,
      'budget-reactions' => 4,
      'home-shows' => 4,
      'election-other-story' => 4,
      'home-watch' => 3,
      'india-inc-on-budget' => 4,
      'budget-decoded' => 3,
      'edu-featurefilia' => 4,
      'edu-jobs-and-career' => 4,
      'election-so-sorry' => 1,
      'standpoint' => 5,
      'edu-tips-and-trick' => 10,
      'edu-sample-paper' => 5,
      'edu-from-the-magazine' => 4,
      'edu-gov-jobs' => 4,
      'buying-guid' => 6,
      'edu-notification' => 4,
      'tech-tips' => 4,
      'sport-column' => 3,
      'in-depth' => 6,
      'talking-point' => 4,
      'movies-lifestyle' => 7,
      'movies-celebrities' => 7,
      'oscar-news' => 5,
      'oscar-features' => 6);

    if (array_key_exists($widget_style, $rangearray)) {
      $range = $rangearray[$widget_style];
    }
    if ($widget_style == 'standpoint') {
      $from_limit = 0;
    }


    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sh', 'sh.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('sh', array('field_story_short_headline_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
    $query->fields('iwo', array('nid', 'weight'))
        ->condition('iwo.cat_id', $cat_id)
        // fix for getting all content type
        ->condition('iwo.widget', $widget_name)
        ->condition('n.type', $content)
        ->condition('n.status', '1')
        ->orderBy('iwo.weight', 'DESC')
        ->orderBy('n.nid', 'DESC')
        ->groupBy('iwo.nid')
        ->range($from_limit, $range);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {

      $entity_data[] = $entity_data_node;
    }
    return $entity_data;
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
