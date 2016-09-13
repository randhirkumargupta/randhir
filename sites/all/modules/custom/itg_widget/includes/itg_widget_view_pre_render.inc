<?php

/**
 * @file
 * itg_widget_view_pre_render.inc
 *
 * Implements hook_views_pre_render().
 * {@inheritdoc}
 */
function itg_widget_views_pre_render(&$view) {

  if ($view->name == "so_sorry" && $view->current_display == 'so_sorry_videos_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'so-sorry-video-widget-list', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "so_sorry" && $view->current_display == 'so_sorry_videos') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('So Sorry Widget'), 'so-sorry-video-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "so_sorry" && $view->current_display == 'so_sorry_page') {
    if (module_exists('itg_videogallery')) {
      $vid = itg_videogallery_get_videoid($view->result[0]->file_managed_field_data_field_upload_video_fid);
      $view->result[0]->file_managed_field_data_field_upload_video_fid = $vid;
    }
  }
  if ($view->name == "story_widget" && $view->current_display == 'page_2') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'story-list-widget', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'page_1') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Top Story Widget'), 'story-list-widget-listing');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'trending_videos') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Trending Videos Widget'), 'trending-video-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'trending_videos_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'trending-video-widget-list', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'most_popular') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Most Popular Story Widget'), 'most-popular-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'top_takes_video') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Top Takes Videos Widget'), 'top-takes-video-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'watch_right_now') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Watch Right Now Widget'), 'watch-right-now-video-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'watch_right_now_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'watch-right-now-videos-list', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'most_popular_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'most-popular-story', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'top_takes_video_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'top-takes-videos-list', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "home_page_feature_widget" && $view->current_display == 'page_2') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'home-page-feature-widget-listing', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "home_page_feature_widget" && $view->current_display == 'page_1') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Home Page Feature Widget'), 'home-page-feature-widget');
      $view->attachment_before = $header_content;
    }
  }
// Add back to we may suggest on content search page.
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'we_may_suggest_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('We May Suggest Widget'), 'we-may-suggest-content-ordering-list');
      $view->attachment_before = $header_content;
    }
  }
// Added search content on widget page.
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'we_may_suggest_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'we-may-suggest-draggable-content-order', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'page') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Section Ordering Widget'), 'section-wise-content-ordering-list', array('query' => array('destination' => arg(0))));
      $view->attachment_before = $header_content;
    }
    if (isset($_GET['category_tid']) && $_GET['category_tid'] == 'All') {
      unset($view->result);
    }
  }
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'page') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'section-wise-draggable-content-order', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
    if (!isset($_GET['category_tid'])) {
//$view = array();
    }
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'photo_carousel') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'photo-list-widget', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'photo_carousel_list') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Photo Carousel Widget'), 'photo-list-widget-listing');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'video_carousel') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'video-list-widget', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'video_carousel_list') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Video Carousel Widget'), 'video-list-widget-listing');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'big_story_format') {
    $header_content = l(t('Search Content'), 'big-story-format-conent', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'big_story_format') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Big Story Widget'), 'big-story-widget-list');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'dont_miss_content') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'dont-miss-widget-contents', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'dont_miss_content') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Don\'t Miss Widget'), 'dont-miss-widget-list');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_listing_page') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Anchors Listing Widget'), 'anchor-list-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_listing_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Search Content'), 'anchor-list', array('query' => array('destination' => arg(0))));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_display_page') {
//dpm($view->result);
//$view->result = ordered_anchors($view->result);
//dpm(taxonomy_get_term_by_name('ANI'));
  }
  elseif ($view->name == "category_wise_content_list" && $view->current_display == 'page') {
    $arg = arg();
    $term = taxonomy_term_load($arg[1]);
    $header_content = '<h1 class="category-heading">' . $term->name . '</h1>';
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "category_wise_content_list" && $view->current_display == 'section_wise_content_listing') {
    $arg = arg();
    $term = taxonomy_term_load($arg[2]);
    $header_content = '<h1 class="category-heading">' . $term->name . '</h1>';
    $view->attachment_before = $header_content;
  }

   elseif ($view->name == "poll_widget" && $view->current_display == 'poll_widget_list') {
    $header_content = l(t('Search Content'), 'poll-format-conent', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "poll_widget" && $view->current_display == 'poll_widget_format') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Poll Widget'), 'poll-format-widget-list');
      $view->attachment_before = $header_content;
    }
  }
  
   elseif ($view->name == "issue_base_magazin_widget" && $view->current_display == 'issue_magazin_widget_list') {
    $header_content = l(t('Search Content'), 'issue-base-magazin-widget');
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "issue_base_magazin_widget" && $view->current_display == 'issue_base_magazin_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Issue Magazin Widget'), 'issue-magazin-widget-list');
      $view->attachment_before = $header_content;
    }
  }
}

/**
 * Function used for showing correct order of anchors.
 * 
 * @return array
 */
function get_anchor_display_page_order() {
  $query = db_select('draggableviews_structure', 'ds')
          ->fields('ds', array('entity_id', 'weight'))
          ->condition('ds.args', '{"ntype":null}')
          ->condition('ds.view_name', 'widget_anchors_listing')
          ->orderBy('ds.weight');
  return $query->execute()->fetchAll();
}

/**
 * Make custom order of anchors.
 * 
 * @param array $views_data
 * @return array
 */
function ordered_anchors($views_data) {
  $real_order_of_anchors = get_anchor_display_page_order();
  $new_order_of_anchors = array();
  foreach ($real_order_of_anchors as $anchor) {
    foreach ($views_data as $view_anchors) {
      if ($view_anchors->nid == $anchor->entity_id) {
        $new_order_of_anchors[] = $view_anchors;
      }
    }
  }
  return $new_order_of_anchors;
}
