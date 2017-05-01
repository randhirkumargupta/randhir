<?php

/**
 * @file
 * itg_widget_view_pre_render.inc
 *
 * Implements hook_views_pre_render().
 * {@inheritdoc}
 */
function itg_widget_views_pre_render(&$view) {
  $color_box_query = array("width" => "900", "height" => "600", "iframe" => "true");
  $color_box_class = array("class" => array("colorbox-load"));
  if ($view->name == "static_pages" && $view->current_display == 'page') {
    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "so_sorry" && $view->current_display == 'so_sorry_videos') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('So Sorry Widget'), 'so-sorry-video-widget-order-reorder', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "so_sorry" && $view->current_display == 'so_sorry_page') {
    if (module_exists('itg_videogallery')) {
      $vid = itg_videogallery_get_videoid($view->result[0]->file_managed_field_data_field_upload_video_fid);
      $view->result[0]->file_managed_field_data_field_upload_video_fid = $vid;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'page_1') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Top Story Widget'), 'story-list-widget-listing', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'trending_videos') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Trending Videos Widget'), 'trending-video-widget-order-reorder', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'most_popular') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Most Popular Story Widget'), 'most-popular-widget-order-reorder', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'top_takes_video') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Top Takes Videos Widget'), 'top-takes-video-widget-order-reorder', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'watch_right_now') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Watch Right Now Widget'), 'watch-right-now-video-widget-order-reorder', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'most_popular_widget') {
//    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
//    $header_content .= l(t('Search Content'), 'most-popular-story', array('query' => array('destination' => arg(0))));
//    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "story_widget" && $view->current_display == 'top_takes_video_widget') {
//    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
//    $header_content .= l(t('Search Content'), 'top-takes-videos-list', array('query' => array('destination' => arg(0))));
//    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "home_page_feature_widget" && $view->current_display == 'page_2') {
//    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
//    $header_content .= l(t('Search Content'), 'home-page-feature-widget-listing', array('query' => array('destination' => arg(0))));
//    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "home_page_feature_widget" && $view->current_display == 'page_1') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Home Page Feature Widget'), 'home-page-feature-widget', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
// Add back to we may suggest on content search page.
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'we_may_suggest_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('We May Suggest Widget'), 'we-may-suggest-content-ordering-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
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
    //$header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
    //$header_content .= l(t('Search Content'), 'section-wise-draggable-content-order', array('query' => array('destination' => arg(0))));
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'photo_carousel_list') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Photo Carousel Widget'), 'photo-list-widget-listing', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'video_carousel') {
//$header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
//$header_content .= l(t('Search Content'), 'video-list-widget', array('query' => array('destination' => arg(0))));
//$view->attachment_before = $header_content;
  }
  elseif ($view->name == "photo_carousel_widget" && $view->current_display == 'video_carousel_list') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Video Carousel Widget'), 'video-list-widget-listing', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'big_story_format') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Big Story Widget'), 'big-story-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
//  elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'dont_miss_content') {
//    $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
//    $header_content .= l(t('Search Content'), 'dont-miss-widget-contents', array('query' => array('destination' => arg(0))));
//    $view->attachment_before = $header_content;
//  }
  elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'dont_miss_content') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Don\'t Miss Widget'), 'dont-miss-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_listing_page') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Anchors Listing Widget'), "anchor-list-order-reorder", array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "widget_anchors_listing" && $view->current_display == 'anchors_listing_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
//      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
//      $header_content .= l(t('Search Content'), 'anchor-list', array('query' => array('destination' => arg(0))));
//      $view->attachment_before = $header_content;
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
  elseif ($view->name == "category_wise_content_list" && ($view->current_display == 'section_wise_content_listing' || $view->current_display == 'grid_view')) {
    global $base_url;
  }
  elseif ($view->name == "podcasts_listing" && $view->current_display == 'page') {
    $header_content = '<h1 class="category-heading">' . t('Podcasts') . '</h1>';
    $view->attachment_before = $header_content;
  }
  elseif ($view->name == "blog_listing" && $view->current_display == 'page') {
    $header_content = '<h1 class="category-heading">' . t('Blog') . '</h1>';
    $view->attachment_before = $header_content;
  }
//  elseif ($view->name == "category_wise_content_list" && $view->current_display == 'section_wise_content_listing') {
//    $arg = arg();
//    $taxonomy_url = $base_url."/taxonomy/term/$arg[2]";
//    $term = taxonomy_term_load($arg[2]);
//    $header_content = '<h1 class="category-heading">' . $term->name . '</h1>';
//    $header_content .= '<div class="list-grid"><i class="fa fa-list" aria-hidden="true"></i> ' .l(t('List'),$taxonomy_url, array('query'=>array('view_type'=>'list'))).'<span class="pipline"> | </span><i class="fa fa-th" aria-hidden="true"></i> '.l(t('Grid'),$taxonomy_url ,array('query'=>array('view_type'=>'grid'))).'</div>';
//    $view->attachment_before = $header_content;
//  }
  elseif ($view->name == "poll_widget" && $view->current_display == 'poll_widget_format') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Poll Widget'), 'poll-format-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "issue_base_magazin_widget" && $view->current_display == 'issue_base_magazin_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Issue Magazine Widget'), 'issue-magazin-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "special_auto_review_widget" && $view->current_display == 'special_auto_review_widget_contents') {
    if(isset($_POST['views_bulk_operations']) && (empty($_GET['category_tid']))) {
      drupal_set_message(t("Please select Section first.") , 'error');
      drupal_goto('special-auto-review-widget-contents');
    }
    if($_GET['category_tid']=='All') {
       drupal_set_message(t("Please select Section first.") , 'error');
      drupal_goto('special-auto-review-widget-contents');
    }
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Special Review Widget'), 'special-auto-review-widget-lsit', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "special_how_i_made_it" && $view->current_display == 'special_how_made_it_widget_contents') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Special How I Made It Widget'), 'special-how-made-it-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "yearender_top_news_and_top_videos" && $view->current_display == 'yearend_left_widget_contents') {
  if(isset($_POST['views_bulk_operations']) && empty($_GET['tid']) ) {
      drupal_set_message(t("Please select Section and filter first.") , 'error');
      drupal_goto('yearend-left-widget-contents');
    }
    if($_GET['tid']=='All') {
       drupal_set_message(t("Please select Section and filter first.") , 'error');
      drupal_goto('yearend-left-widget-contents');
    }
    
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Year End Top News & Video'), 'yearend-left-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "most_read_widget" && $view->current_display == 'most_read_widget_contents') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Most Read Widget'), 'most-read-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "feature_content_by_section_widget" && $view->current_display == 'feature_content_section_widget_contents') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Feature Content By Section Widget'), 'feature-content-section-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "highlights_widget" && $view->current_display == 'highlights_widget_conent') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Highlights Content By Section Widget'), 'highlights-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "key_candidate" && $view->current_display == 'special_key_candidate_widget_contents') {
    if (!isset($_POST['views_bulk_operations'])) {
      $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Key Candidate Content Widget'), 'special-key-candidate-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "category_of_stroy_base_magazin_widget" && $view->current_display == 'issue_category_magazin_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      //$header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Widget - Category List'), 'issue-magazin-primary-cat-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "supplement_base_magazin_widget" && $view->current_display == 'supplement_base_magazin_widget') {
    if (!isset($_POST['views_bulk_operations'])) {
      //$header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
      $header_content .= l(t('Widget - Supplement List'), 'supplement-base-magazin-widget-list', array('query' => $color_box_query, 'attributes' => $color_box_class));
      $view->attachment_before = $header_content;
    }
  }
  elseif ($view->name == "user_selection" && $view->current_display == 'user_selection_for_section') {
    if(!isset($_GET['field_user_section_tid']) || $_GET['field_user_section_tid'] == 'All') {
      drupal_add_css("#views-form-user-selection-user-selection-for-section fieldset.container-inline , td.views-field-views-bulk-operations , th.views-field-views-bulk-operations {display:none}" , 'inline');
    }
//    if (isset($_POST['views_bulk_operations']) && !isset($_GET['field_user_section_tid'])) {
//      drupal_set_message(t("Please select section first."), 'error');
//      drupal_goto('user-selection');
//    }
//    if(isset($_POST['views_bulk_operations']) && isset($_GET['field_user_section_tid']) && !is_integer(isset($_GET['field_user_section_tid']))) {
//      drupal_set_message(t("Please select section first."), 'error');
//      drupal_goto('user-selection');
//    }
  }
}
