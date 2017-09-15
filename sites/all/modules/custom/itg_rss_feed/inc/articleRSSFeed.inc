<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate articleRSSFeed
 *
 * @return string
 */
function articleRSSFeed() {
    global $base_url;
    
    $section_id = $_GET['section_id'];
    $output = "";

    $redis_key = "itgd_rss_articleRSSFeed_".$section_id;
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $output = $result_get['key_value'];
    } else {
        //anchorRSSFeed writing...
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $output .= getRSSFeedHeader();
        $output .= getRSSFeedSubHeader();

        $output .= getArticleItem_RSS($section_id);

        $output .= getRSSFeedFooter();
        // set into redis
        $result_set = setRedis($redis_key, $output, $ttl);
    }
    header('Content-Type: application/xml; charset=utf-8');
    echo $output;
    die;
}

/**
 * function for get anchor node item
 *
 * @return string
 */
function getArticleItem_RSS($section_id) {
    global $base_url;
    $tid_list = array();
    $tid = $section_id;    
    $tid_list[] = $tid;
    $output = "";
    $range_min = 0;
    $range_max = 25;
    //$type = array("videogallery", "photogallery", "story");
    $type = array("story");

    if ($tid > 0) {
        $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
    }
    $term_tree_count = count($term_tree);
    if ($term_tree_count) {
        foreach ($term_tree as $key => $value) {
            $tid_list[] = $value->tid;
        }
    }

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('kt', array('field_story_kicker_text_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    if (count($tid_list) > 0) {
        $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $list_cont = 0;
    
    foreach ($result as $reskey => $resvalue) {
        $title = $resvalue['title'];
        $nid = $resvalue['nid'];
        $body_value = $resvalue['body_value'];
        $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
        $url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
        $img_url = completeFilePath($field_story_extra_large_image_fid);
        $created = $resvalue['created'];
        $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
        $created_date = date("D, d M Y H:i:s", $created);  

        $output .= '<item><title><![CDATA[' . $title . ']]></title><link><![CDATA[' . $url . '?utm_source=rss]]></link><description><![CDATA[<a href="' . $url . '?utm_source=rss"><img src="' . $img_url . '" align="left" hspace="2" height="180" width="305" alt="" border="0"/></a>' . $field_story_kicker_text_value . ']]></description><pubDate>' . $created_date . ' GMT</pubDate></item>';
    }
    return $output;
}
