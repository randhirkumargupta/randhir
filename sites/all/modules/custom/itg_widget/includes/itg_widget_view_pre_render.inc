<?php

/**
 * @file
 * itg_widget_view_pre_render.inc
 *
 * Provide functionality to pre render on view.
 *
 */
function itg_widget_views_pre_render(&$view) {
    if ($view->name == "story_widget" && $view->current_display == 'page_2') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Search Content'), 'story-list-widget', array('query' => array('destination' => arg(0))));
        $view->attachment_before = $header_content;
    }
    elseif ($view->name == "story_widget" && $view->current_display == 'page_1') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Back To Top Stories'), 'story-list-widget-listing');
        $view->attachment_before = $header_content;
    }
    elseif ($view->name == "home_page_feature_widget" && $view->current_display == 'page_2') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Search Content'), 'home-page-feature-widget-listing', array('query' => array('destination' => arg(0))));
        $view->attachment_before = $header_content;
    }
    elseif ($view->name == "home_page_feature_widget" && $view->current_display == 'page_1') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Back to home page feature'), 'home-page-feature-widget');
        $view->attachment_before = $header_content;
    }
    // Add back to we may suggest on content search page.
    elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'we_may_suggest_widget') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Back to we may suggest'), 'we-may-suggest-content-ordering-list');
        $view->attachment_before = $header_content;
    }
    // Added search content on widget page.
    elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'we_may_suggest_widget') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Search Content'), 'we-may-suggest-draggable-content-order', array('query' => array('destination' => arg(0))));
        $view->attachment_before = $header_content;
    }
    elseif ($view->name == "section_wise_draggable_content_order" && $view->current_display == 'page') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Back to Section Ordering Widget'), 'section-wise-content-ordering-list', array('query' => array('destination' => arg(0))));
        $view->attachment_before = $header_content;
    }
    elseif ($view->name == "section_wise_content_ordering_list" && $view->current_display == 'page') {
        $header_content = '<span class="count">Count (' . $view->total_rows . ') </span>';
        $header_content .= l(t('Search Content'), 'section-wise-draggable-content-order');
        $view->attachment_before = $header_content;
    }
}
