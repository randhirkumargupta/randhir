<?php

/*
 * Inc file contains the functions
 */

/**
 * Implements page callback.
 * @return
 */
function itg_layout_admin() {
    $data = '';
    if (isset($_GET['section']) && isset($_GET['template_name'])) {
        $data = get_layout_details($_GET['section'], $_GET['template_name'], 'admin');
    }
    if (arg(2) == 'preview') {
        $data['preview'] = 'yes';
    }
    drupal_add_js('jQuery(document).ready(function(){ jQuery("#views-exposed-form-video-list-of-category-block-1 , #views-exposed-form-photo-list-of-category-block").hide(); });', array('scope' => 'footer', 'type' => 'inline'));
    drupal_add_css(drupal_get_path('theme', FRONT_THEME_NAME) . '/css/layout-manager.css');

    return theme('itg_layout_admin_page', array('widget_data' => $data));
}

/**
 * Get itg layout list
 * @return array $output
 */
function itg_layout_list() {
    // configure the table header columns
    $header = array(
        array('data' => t('ID')),
        array('data' => t('Section name')),
        array('data' => t('Template name')),
        array('data' => t('Template type')),
        array('data' => t('Created Date')),
        array('data' => t('Action')),
    );
    $arg = arg();
    if ($arg[1] == 'special') {
        drupal_set_title(t('Special Template'));
    }
    if ($arg[1] == 'section') {
        drupal_set_title(t('Section Template'));
    }
    if (isset($_GET['items_per_page'])) {
        $items_per_page = $_GET['items_per_page'];
    }
    else {
        $items_per_page = 20;
    }

    $itg_query = db_select('itg_layout_tpl', 'layout_tpl')->extend('PagerDefault')->limit($items_per_page);
    $itg_query->fields('layout_tpl', array('id', 'section_name', 'template_name', 'layout_type', 'status', 'created_date'));
    $itg_query->join('taxonomy_term_data', 'ttd', 'ttd.tid = layout_tpl.section_name');
    $itg_query->fields('ttd', array('name'));    
    $itg_query->groupBy('layout_tpl.section_name');
    $itg_query->condition('layout_tpl.layout_type', arg(1));
    if (!empty($_GET['section']) && $_GET['section'] != '_none') {
        $itg_query->condition('layout_tpl.section_name', $_GET['section']);
    }
//  else {
//    $itg_query->condition('layout_tpl.section_name', 'home_page', '!=');
//  } 

    $itg_result = $itg_query->execute()->fetchAll();

    $rows = array();

    $count = 0;

    foreach ($itg_result as $row) {
        $rows[] = array(
            array('data' => $count + 1),
            array('data' => $row->name),
            array('data' => $row->template_name),
            array('data' => $row->layout_type),
            array('data' => date('d/m/Y', $row->created_date)),
            //array('data' => l(t('Edit'), 'itg-layout-manager/' . arg(1), array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name))).'/'.l(t('Delete'), 'itg-delete-layout/' . $row->section_name, array('query' => array('destination' => 'itg-layout-list/'.  arg(1))))),
            array('data' => l(t('Edit'), 'itg-layout-manager/' . arg(1), array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name)))),
           
        );
        $count++;
    }
    $filter_form = drupal_get_form('itg_layout_manager_filter_form');
    $output = render($filter_form);
    $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
    $output .= l(t('Add New Template'), 'itg-layout-manager/' . arg(1)) . '</div></div>';
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

    // add the pager
    $output .= theme('pager');

    return $output;
}

/**
 * This function use for term details
 */
function itg_layout_getterm_detials() {
    $tid = $_POST['state_id'];
    $dataterm = taxonomy_term_load($tid);

    $svgurl = $dataterm->field_state_svg_json['und'][0]['value'];
    $mapgurl = $dataterm->field_state_map_json['und'][0]['value'];
    $colorurl = $dataterm->field_state_map_color_json['und'][0]['value'];

    $urlarray = array('svgurl' => $svgurl, 'mapjson' => $mapgurl, 'color_url' => $colorurl);
    print json_encode($urlarray);
    die;
}

/**
 * callback for gethomecarddata
 * {@inheritdoc}
 */
function itg_layout_gethomecarddata() {
    global $theme;

    $arg = arg();

    $sectinno = end(explode('-', $_POST['section_ids']));

    $is_fron_page = drupal_is_front_page();

    if ($sectinno == 16) {
        $sectinno = 20;
    }

    if ($sectinno == 20) {
        $widget_name1 = 'itg-block-' . ($sectinno);
        $widget_name2 = 'itg-block-' . ($sectinno + 1);
        $widget_name3 = 'itg-block-' . ($sectinno + 2);
    }
    else {
        $widget_name1 = 'itg-block-' . ($sectinno + 1);
        $widget_name2 = 'itg-block-' . ($sectinno + 2);
        $widget_name3 = 'itg-block-' . ($sectinno + 3);
    }

    $block_name = array($widget_name1, $widget_name2, $widget_name3);
    $section = 'home_page';
    $template_name = 'page--front';
    $data = get_layout_details_by_block_name($section, $template_name, 'front', $block_name);
    $nextdata = itg_layout_gethomecarddata_new_pre($sectinno + 3);

    $widget_data = $data;

    if (!empty($widget_data[$widget_name1]['widget_name']) || !empty($widget_data[$widget_name2]['widget_name']) || !empty($widget_data[$widget_name3]['widget_name'])) {

        print '<div class="row itg-common-section"  id="content-section-widget">
            <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name1 . '">
            <div class="itg-widget">
            <div class="droppable ' . $gray_bg_layout . '">
            <div class="widget-wrapper ' . $widget_data[$widget_name1]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name1]['block_title'])) {
            print '<span class="widget-title">' . $widget_data[$widget_name1]['block_title'] . '</span>';
        }

        print' <div class="data-holder" id="' . $widget_name1 . '">' . $widget_data[$widget_name1]['widget'] . '</div></div></div></div></div>
            <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name2 . '">
            <div class="itg-widget">
            <div class="droppable ' . $gray_bg_layout . '">
            <div class="widget-wrapper ' . $widget_data[$widget_name2]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name2]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name2]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name2 . '">' . $widget_data[$widget_name2]['widget'] . '</div></div></div></div></div>';

        print '<div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name3 . '">
            <div class="itg-widget">
            <div class="droppable ' . $gray_bg_layout . '">
            <div class="widget-wrapper ' . $widget_data[$widget_name3]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name3]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name3]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name3 . '">' . $widget_data[$widget_name3]['widget'] . '</div></div></div></div></div>';

        if ($nextdata != 0 && $sectinno + 3 < 40) {

            print '<div class="load-more-wrapper-front">
        <a href="javascript:void(0)" class="add-more-block-front">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
        </div>';
        }

        print '</div>';
    }
    else {
        itg_layout_gethomecarddata_new($sectinno + 4);
    }

    exit();
}



/**
 * callback for gethomecarddata
 * {@inheritdoc}
 */
function itg_layout_getsecttioncarddata() {
    global $theme;

    $arg = arg();

    $sectinno = end(explode('-', $_POST['section_ids']));

    $is_fron_page = drupal_is_front_page();

    if ($sectinno == 16) {
        $sectinno = 20;
    }

    if ($sectinno == 20) {
        $widget_name1 = 'itg-block-' . ($sectinno);
        $widget_name2 = 'itg-block-' . ($sectinno + 1);
        $widget_name3 = 'itg-block-' . ($sectinno + 2);
    }
    else {
        $widget_name1 = 'itg-block-' . ($sectinno + 1);
        $widget_name2 = 'itg-block-' . ($sectinno + 2);
        $widget_name3 = 'itg-block-' . ($sectinno + 3);
    }

    $block_name = array($widget_name1, $widget_name2, $widget_name3);
    $section = $_POST['getsectionid'];
    $template_name = 'page--section_default';
    $data = get_layout_details_by_block_name($section, $template_name, 'front', $block_name);
    $nextdata = itg_layout_getsectioncarddata_new_pre($sectinno + 3 ,$section);

    $widget_data = $data;

    if (!empty($widget_data[$widget_name1]['widget_name']) || !empty($widget_data[$widget_name2]['widget_name']) || !empty($widget_data[$widget_name3]['widget_name'])) {

        print '<div class="row itg-common-section"  id="content-section-widget">
            <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name1 . '">
            <div class="itg-widget">
            <div class="droppable ' . $gray_bg_layout . '">
            <div class="widget-wrapper ' . $widget_data[$widget_name1]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name1]['block_title'])) {
            print '<span class="widget-title">' . $widget_data[$widget_name1]['block_title'] . '</span>';
        }

        print' <div class="data-holder" id="' . $widget_name1 . '">' . $widget_data[$widget_name1]['widget'] . '</div></div></div></div></div>
            <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name2 . '">
            <div class="itg-widget">
            <div class="droppable ' . $gray_bg_layout . '">
            <div class="widget-wrapper ' . $widget_data[$widget_name2]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name2]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name2]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name2 . '">' . $widget_data[$widget_name2]['widget'] . '</div></div></div></div></div>';

        print '<div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name3 . '">
            <div class="itg-widget">
            <div class="droppable ' . $gray_bg_layout . '">
            <div class="widget-wrapper ' . $widget_data[$widget_name3]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name3]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name3]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name3 . '">' . $widget_data[$widget_name3]['widget'] . '</div></div></div></div></div>';

        if ($nextdata != 0 && $sectinno + 3 < 40) {

            print '<div class="load-more-wrapper-front">
        <a href="javascript:void(0)" section_id ="'.$section.'" class="add-more-block-front-section">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
        </div>';
        }

        print '</div>';
    }
    else {
        itg_layout_getsectioncarddata_new($sectinno + 4,$section);
    }

    exit();
}

/**
 * Implements itg_layout_gethomecarddata_new().
 * {@inheritdoc}
 */
function itg_layout_gethomecarddata_new($sectinno) {
    global $theme;
    $arg = arg();

    $widget_name1 = 'itg-block-' . ($sectinno);
    $widget_name2 = 'itg-block-' . ($sectinno + 1);
    $widget_name3 = 'itg-block-' . ($sectinno + 2);

    $block_name = array($widget_name1, $widget_name2, $widget_name3);
    $section = 'home_page';
    $template_name = 'page--front';

    $data = get_layout_details_by_block_name($section, $template_name, 'front', $block_name);
    if ($data == "" && $sectinno < 80) {
        itg_layout_gethomecarddata_new($sectinno + 3);
    }

    $nextdata = itg_layout_gethomecarddata_new_pre($sectinno + 3);
    $widget_data = $data;

    if (!empty($widget_data[$widget_name1]['widget_name']) || !empty($widget_data[$widget_name2]['widget_name']) || !empty($widget_data[$widget_name3]['widget_name'])) {
        print '<div class="row itg-common-section"  id="content-section-widget">

    <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name1 . '">
    <div class="itg-widget">
    <div class="droppable ' . $gray_bg_layout . '">
    <div class="widget-wrapper ' . $widget_data[$widget_name1]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name1]['block_title'])) {
            print '<span class="widget-title">' . $widget_data[$widget_name1]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name1 . '">' . $widget_data[$widget_name1]['widget'] . '</div></div></div></div></div>

          <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name2 . '">
          <div class="itg-widget">
          <div class="droppable ' . $gray_bg_layout . '">
          <div class="widget-wrapper ' . $widget_data[$widget_name2]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name2]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name2]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name2 . '">' . $widget_data[$widget_name2]['widget'] . '</div></div></div></div></div>';

        print '<div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name3 . '">
           <div class="itg-widget">
           <div class="droppable ' . $gray_bg_layout . '">
           <div class="widget-wrapper ' . $widget_data[$widget_name3]['widget_name'] . '">';
        if (!empty($widget_data[$widget_name3]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name3]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name3 . '">' . $widget_data[$widget_name3]['widget'] . '</div></div></div></div></div>';
        if ($nextdata != 0 && $sectinno + 3 < 40) {
            print '<div class="load-more-wrapper-front">
              <a href="javascript:void(0)" class="add-more-block-front">' . t("Load More") . ' <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
              </div>';
        }
        print'</div>';
    }
    else {
        
    }

    exit();
}


/**
 * Implements hook_manager_preprocess_page().
 * {@inheritdoc}
 */
function itg_layout_getsectioncarddata_new($sectinno,$section) {
    global $theme;
    $arg = arg();

    $widget_name1 = 'itg-block-' . ($sectinno);
    $widget_name2 = 'itg-block-' . ($sectinno + 1);
    $widget_name3 = 'itg-block-' . ($sectinno + 2);

    $block_name = array($widget_name1, $widget_name2, $widget_name3);
    
    $template_name = 'page--section_default';

    $data = get_layout_details_by_block_name($section, $template_name, 'front', $block_name);
    if ($data == "" && $sectinno < 80) {
      itg_layout_getsectioncarddata_new($sectinno + 3,$section);
    }

    $nextdata = itg_layout_getsectioncarddata_new_pre($sectinno + 3,$section);
    $widget_data = $data;

    if (!empty($widget_data[$widget_name1]['widget_name']) || !empty($widget_data[$widget_name2]['widget_name']) || !empty($widget_data[$widget_name3]['widget_name'])) {
        print '<div class="row itg-common-section"  id="content-section-widget">

    <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name1 . '">
    <div class="itg-widget">
    <div class="droppable ' . $gray_bg_layout . '">
    <div class="widget-wrapper ' . $widget_data[$widget_name1]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name1]['block_title'])) {
            print '<span class="widget-title">' . $widget_data[$widget_name1]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name1 . '">' . $widget_data[$widget_name1]['widget'] . '</div></div></div></div></div>

          <div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name2 . '">
          <div class="itg-widget">
          <div class="droppable ' . $gray_bg_layout . '">
          <div class="widget-wrapper ' . $widget_data[$widget_name2]['widget_name'] . '">';

        if (!empty($widget_data[$widget_name2]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name2]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name2 . '">' . $widget_data[$widget_name2]['widget'] . '</div></div></div></div></div>';

        print '<div class="col-md-4 col-sm-4 col-xs-12 mt-50 sectioncart" id="section-cart-' . $widget_name3 . '">
           <div class="itg-widget">
           <div class="droppable ' . $gray_bg_layout . '">
           <div class="widget-wrapper ' . $widget_data[$widget_name3]['widget_name'] . '">';
        if (!empty($widget_data[$widget_name3]['block_title'])) {
            print' <span class="widget-title">' . $widget_data[$widget_name3]['block_title'] . '</span>';
        }

        print '<div class="data-holder" id="' . $widget_name3 . '">' . $widget_data[$widget_name3]['widget'] . '</div></div></div></div></div>';
        if ($nextdata != 0 && $sectinno + 3 < 40) {
            print '<div class="load-more-wrapper-front">
              <a href="javascript:void(0)" section_id ="'.$section.'" class="add-more-block-front-section">' . t("Load More") . ' <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
              </div>';
        }
        print'</div>';
    }
    else {
        
    }

    exit();
}

/**
 * Callback of pre-layout-drag-widgets
 * {@inheritdoc}
 */
function pre_layout_drag_widgets() {

    //code for If already a section is dragged while configuration and 
    //if same section is being dragged again on default,photo and video page then system should show an ALERT

    $check_drag_tid = get_use_category_on_tpl($_GET['section_name'], $_GET['category']);
    if (!empty($check_drag_tid)) {
        echo 'yes';
        exit;
    }

    // code end
}

/**
 * Get map category id with tpl
 * @param int $layout_id
 * @param string $block_name 
 * @return array $data_array
 */
function get_use_category_on_tpl($section_id, $cate_id) {

    $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
    $itg_query->fields('layout_manager', array('filter_url'));
    $itg_query->join('itg_layout_manager', 'layout_manager', 'layout_tpl.id = layout_manager.layout_id');
    $itg_query->condition('layout_tpl.section_name', $section_id);
    $itg_query->condition('layout_manager.filter_url', $cate_id);
    $itg_query->orderBy('layout_tpl.id', 'DESC');
    $itg_query->range(0, 1);
    $id = $itg_query->execute()->fetchField();


//  $query = db_select('itg_layout_manager', 'layout');
//  $query->fields('layout', array('id'));  
//  $query->condition('layout_id', $layout_id)
//        ->condition('block_name', $block_name);  
//  $id = $query->execute()->fetchField();
//  
    return $id;
}
