<?php

/**
 * @file
 * itg_social_media.views.inc file for adding custom table to views.
 */
function itg_social_media_views_data() {
    $data['itg_social_media_logs']['table']['group'] = t('Social Media Logs');

    $data['itg_social_media_logs']['table']['base'] = array(
        'field' => 'nid',
        'title' => t('Social media Logs'),
        'help' => t('Social media logs are stroed in this table.'),
        'weight' => -11,
    );
    $data['itg_social_media_logs']['table']['join'] = array(
        'node' => array(
            'left_field' => 'nid',
            'field' => 'nid',
        ),
    );
    $data['itg_social_media_logs']['node_publish_on'] = array(
        'title' => t('node publish on'),
        'help' => t('node publish on.'),
        'field' => array(
            'handler' => 'itg_social_media_views_handler',
            'click sortable' => TRUE,
        ),
        
    );

    $data['itg_social_media_logs']['count_fb_promote'] = array(
        'title' => t('Count Facebook Promote'),
        'help' => t('Count Facebook Promote.'),
        'field' => array(
            'handler' => 'itg_social_media_count_fb_views_handler',
            'click sortable' => TRUE,
        ),
    );
    $data['itg_social_media_logs']['count_twitter_promote'] = array(
        'title' => t('Count Twitter Promote'),
        'help' => t('Count Twitter Promote.'),
        'field' => array(
            'handler' => 'itg_social_media_count_twiteer_views_handler',
            'click sortable' => TRUE,
        ),
    );
    $data['itg_social_media_logs']['count_fb_like'] = array(
        'title' => t('Count facebook like'),
        'help' => t('Count facebook like.'),
        'field' => array(
            'handler' => 'itg_social_media_count_fb_like_views_handler',
            'click sortable' => TRUE,
        ),
    );
    $data['itg_social_media_logs']['count_fb_share'] = array(
        'title' => t('Count facebook Share'),
        'help' => t('Count facebook Share.'),
        'field' => array(
            'handler' => 'itg_social_media_count_fb_share_views_handler',
            'click sortable' => TRUE,
        ),
    );
    $data['itg_social_media_logs']['count_fb_comment'] = array(
        'title' => t('Count facebook commnet'),
        'help' => t('Count facebook commnet.'),
        'field' => array(
            'handler' => 'itg_social_media_count_fb_comment_views_handler',
            'click sortable' => TRUE,
        ),
    );
    $data['itg_social_media_logs']['count_twitter_retweet'] = array(
        'title' => t('Count Twitter retweet'),
        'help' => t('Count Twitter retweet.'),
        'field' => array(
            'handler' => 'itg_social_media_count_twiteer_retweet_views_handler',
            'click sortable' => TRUE,
        ),
    );
    $data['itg_social_media_logs']['count_twitter_like'] = array(
        'title' => t('Count Twitter like'),
        'help' => t('Count Twitter like.'),
        'field' => array(
            'handler' => 'itg_social_media_count_twiteer_like_views_handler',
            'click sortable' => TRUE,
        ),
    );

    $data['itg_social_media_logs']['nid'] = array(
        'title' => t('Node id of the story'),
        'help' => t('Each nid reference to a full story.'),
        'relationship' => array(
            'base' => 'node',
            'base field' => 'nid',
            'handler' => 'views_handler_relationship',
            'label' => t('Social Media Logs'),
            'title' => t('relate a node to social media post'),
            'help' => t('Social Media custom table'),
        ),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
        ),
    );

    // Example plain text field.
    $data['itg_social_media_logs']['node_title'] = array(
        'title' => t('Node title'),
        'help' => t('Title of the story posted to social media'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
        ),
    );
//    $data['itg_social_media_logs']['nid'] = array(
//        'title' => t('nid'),
//        'help' => t('nid of the content posted to social media'),
//        'field' => array(
//            'handler' => 'views_handler_field',
//            'click sortable' => TRUE,
//        ),
//        'sort' => array(
//            'handler' => 'views_handler_sort',
//        ),
//        'filter' => array(
//            'handler' => 'views_handler_filter_string',
//        ),
//        'argument' => array(
//            'handler' => 'views_handler_argument_string',
//        ),
//    );
    $data['itg_social_media_logs']['username'] = array(
        'title' => t('Username'),
        'help' => t('Name of the user who has posted the content to social media'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
        ),
    );

    $data['itg_social_media_logs']['social_media'] = array(
        'title' => t('Social media'),
        'help' => t('Name of the social media where content has been posted'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
        ),
    );

    $data['itg_social_media_logs']['created'] = array(
        'title' => t('Created time'),
        'help' => t('When the content has been posted to social media.'),
        'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['itg_social_media_logs']['scheduled_time'] = array(
        'title' => t('Scheduled Time'),
        'help' => t('When the content will publish on social media.'),
        'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );
    $data['itg_social_media_logs']['status'] = array(
        'title' => t('Status'),
        'help' => t('Status of the post.'),
        'field' => array(
            'handler' => 'views_handler_field_boolean',
            'click sortable' => TRUE,
            'output formats' => array(
                'published-unpublished' => array(t('Published'), t('unpublished')),
            )
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_boolean_operator',
            'label' => t('Status'),
            'type' => 'published-unpublished',
            'use equal' => TRUE,
        ),
    );

    return $data;
}

/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {

        $data_node = itg_last_node_published_on($values->nid, 1);

        if (!empty($data_node)) {
            return date('d/m/Y H:i', $data_node[0]->stamp);
        }
        else {

            return date('d/m/Y H:i', $values->node_created);
        }
    }

}

/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_fb_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
        $count = itg_social_media_count_log('facebook', $values->nid);
        $last_date = itg_social_media_get_data_by_nid('facebook', $values->nid);
       if(!empty($last_date)) {
         return $count.'</br> ('.date('d/m/Y H:i', $last_date[0]->scheduled_time).')';  
       } else {
           return $count;
       }
        
    }

}

/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_twiteer_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
        $count = itg_social_media_count_log('twitter', $values->nid);
        $last_date = itg_social_media_get_data_by_nid('twitter', $values->nid);
       if(!empty($last_date)) {
         return $count.'</br> ('.date('d/m/Y H:i', $last_date[0]->scheduled_time).')';  
       } else {
           return $count;
       }
    }

}


/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_fb_like_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
        $return_count = 0;
        $result = itg_social_media_get_data_by_nid('facebook', $values->nid);
        if(!empty($result)) {
            foreach ($result as $res_data) { 
                $return_count = $return_count+$res_data->fb_likes;
            }
        }
        return $return_count;
    }

}


/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_fb_share_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
         $return_count = 0;
        $result = itg_social_media_get_data_by_nid('facebook', $values->nid);
        if(!empty($result)) {
            foreach ($result as $res_data) { 
                $return_count = $return_count+$res_data->fb_shares;
            }
        }
        return $return_count;
    }

}


/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_fb_comment_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
         $return_count = 0;
        $result = itg_social_media_get_data_by_nid('facebook', $values->nid);
        if(!empty($result)) {
            foreach ($result as $res_data) { 
                $return_count = $return_count+$res_data->fb_comment;
            }
        }
        return $return_count;
    }

}


/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_twiteer_retweet_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
         $return_count = 0;
        $result = itg_social_media_get_data_by_nid('Twitter', $values->nid);
        if(!empty($result)) {
            foreach ($result as $res_data) { 
                $return_count = $return_count+$res_data->twitter_retweet;
            }
        }
        return $return_count;
    }

}


/**
 * Views field handler for current path.
 *
 * @ingroup views_field_handlers
 */
class itg_social_media_count_twiteer_like_views_handler extends views_handler_field {

    function query() {
        // Do nothing -- to override the parent query.
    }

    /**
     * {@inheritdoc}
     */
    function option_definition() {
        $options = parent::option_definition();
        return $options;
    }

    /**
     * {@inheritdoc}
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    function render($values) {
        $return_count = 0;
        $result = itg_social_media_get_data_by_nid('Twitter', $values->nid);
        if(!empty($result)) {
            foreach ($result as $res_data) { 
                $return_count = $return_count+$res_data->twitter_likes;
            }
        }
        return $return_count;
    }

}
