<?php

/**
 * @file
 * itg_widget_view_pre_render.inc
 *
 * Implements hook_views_pre_render().
 * {@inheritdoc}
 */
function itg_widget_views_pre_render(&$view) {
  if ($view->name == "story_widget" && $view->current_display == 'page_2') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'story-list-widget', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'page_1') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back To Top Stories'), 'story-list-widget-listing');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'trending_videos') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back To Trending Videos Widget'), 'trending-video-widget-order-reorder');
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
      $header_content .= l(t('Back To Most Popular Story Widget'), 'most-popular-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'top_takes_video') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back To Top Takes Videos Widget'), 'top-takes-video-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'watch_right_now') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back To Watch Right Now Widget'), 'watch-right-now-video-widget-order-reorder');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'watch_right_now_widget') {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Search Content'), 'watch-right-now-videos-list' , array('query' => array('destination' => arg(0))));
      $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'most_popular_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'most-popular-story', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'top_takes_video_widget') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'top-takes-videos-list' , array('query' => array('destination' => arg(0))));
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
      $header_content .= l(t('Back to home page feature'), 'home-page-feature-widget');
      $view->attachment_before = $header_content;
    }
  }
  // Add back to we may suggest on content search page.
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'we_may_suggest_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back to we may suggest'), 'we-may-suggest-content-ordering-list');
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
      $header_content .= l(t('Back to Section Ordering Widget'), 'section-wise-content-ordering-list', array('query' => array('destination' => arg(0))));
      $view->attachment_before = $header_content;
    }
    if (isset($_GET['category_tid']) && $_GET['category_tid'] == 'All') {
      unset($view->result);
    }
  }
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'page') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'section-wise-draggable-content-order' , array('query' => array('destination' => arg(0))));
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
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'video_carousel') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'video-list-widget', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'big_story_format') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'big-story-format-conent' , array('query' =>  array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'big_story_format') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back to big story widget'), 'big-story-widget-list');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'dont_miss_content') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $header_content .= l(t('Search Content'), 'dont-miss-widget-contents' , array('query' =>  array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'dont_miss_content') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back to dont miss widget'), 'dont-miss-widget-list');
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_listing_page') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Back To Anchor List Widget'), 'anchor-list-order-reorder' );
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_listing_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Search Content'), 'anchor-list' , array('query' => array('destination' => arg(0))));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "category_wise_content_list" && $view->current_display == 'page') {
      $arg = arg();
      $term = taxonomy_term_load($arg[1]);
      $header_content = '<h1 class="category-heading">'.$term->name.'</h1>';
      $view->attachment_before = $header_content;
  }
}
