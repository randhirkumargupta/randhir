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
  
  if (isset($_GET['items_per_page'])) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 10;
  }
  
  $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
  $itg_query->fields('layout_tpl', array('id','section_name', 'template_name', 'layout_type', 'status', 'created_date'));  
  $itg_query->join('taxonomy_term_data', 'ttd', 'ttd.tid = layout_tpl.section_name');
  $itg_query->fields('ttd', array('name'));
  $itg_query->groupBy('layout_tpl.section_name');
  $itg_query->extend('PagerDefault')->limit($items_per_page);
  $itg_query->condition('layout_tpl.layout_type', arg(1));
  if (!empty($_GET['section'])) {
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
      array('data' => $count+1),
      array('data' => $row->name),
      array('data' => $row->template_name),
      array('data' => $row->layout_type),
      array('data' => date('d/m/Y', $row->created_date)),
      array('data' => l(t('Edit'), 'itg-layout-manager/'.  arg(1), array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name)))),
    );
    $count++;
  }
  $filter_form = drupal_get_form('itg_layout_manager_filter_form');
  $output = render($filter_form);
  $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
  $output .= l(t('Add New Template'), 'itg-layout-manager/'.  arg(1)).'</div></div>';  
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
  $colorurl=$dataterm->field_state_map_color_json['und'][0]['value'];

  $urlarray = array('svgurl' => $svgurl, 'mapjson' => $mapgurl,'color_url'=>$colorurl);
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
  
  if (!empty($widget_data[$widget_name1]['widget_name']) 
            || !empty($widget_data[$widget_name2]['widget_name']) 
            || !empty($widget_data[$widget_name3]['widget_name'])) {      
   
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
      
       if ($nextdata != 0 && $sectinno+3 < 40) {
          
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
 * Implements hook_manager_preprocess_page().
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
  if($data=="" && $sectinno<80)
  {
     itg_layout_gethomecarddata_new($sectinno + 3); 
  }
  
   $nextdata = itg_layout_gethomecarddata_new_pre($sectinno + 3);
  $widget_data = $data;

  if (!empty($widget_data[$widget_name1]['widget_name']) 
          || !empty($widget_data[$widget_name2]['widget_name']) 
          || !empty($widget_data[$widget_name3]['widget_name'])) {
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
     if ($nextdata != 0 && $sectinno+3 < 40) {
         
       print '<div class="load-more-wrapper-front">
              <a href="javascript:void(0)" class="add-more-block-front">Load More <i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>
              </div>';       
    }
    print'</div>';
  }
  else {

  }

  exit();
}


