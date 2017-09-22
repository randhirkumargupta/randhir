<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate video_rss_feed
 *
 * @return string
 */
function video_rss_feed() {
    global $base_url;
    $section_id = $_GET['section_id'];
    $output = "";
    $term_name = '';
    $section_url = NULL;
    if(!empty($section_id)){
        $term_name = taxonomy_term_load($section_id)->name;
        $section_url = $base_url . "/" . drupal_get_path_alias('taxonomy/term/' . $section_id);
    }
    $redis_key = "itgd_rss_videoRSSFeed_".$section_id;
    //$result_get = getRedis($redis_key);

    if (FALSE && $result_get['key_value'] != "") {
        $output = $result_get['key_value'];
    } else {
        //videoRSSFeed writing...
        //$ttl = DEFAULT_REDIS_EXPIRE_TIME;
        $output .= get_rss_feed_header();
        $output .= get_rss_feed_sub_header_video($term_name, $section_url);

        $output .= get_video_item_rss($section_id, $term_name, $section_url);

        $output .= get_rss_feed_footer();
        // set into redis
       // $result_set = setRedis($redis_key, $output, $ttl);
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
function get_video_item_rss($section_id, $term_name, $section_url) {
    global $base_url;
    $tid_list = array();
    $tid = $section_id;    
    $tid_list = array();
    if(!empty($tid)){
        $tid_list[] = $tid;
    }
    $output = "";
    $range_min = 0;
    $range_max = 25;
    //$type = array("videogallery", "photogallery", "story");
    $type = array("videogallery");

    if (!empty($tid)) {
        $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
    }
    $term_tree_count = count($term_tree);
    if ($term_tree_count) {
        foreach ($term_tree as $key => $value) {
            $tid_list[] = $value->tid;
        }
    }
       
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_expert_description', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');    

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('field_story_expert_description_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    if (!empty($section_id)) {
        $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
        $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range($range_min, $range_max);
    
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $counter = 0;
    foreach ($result as $reskey => $resvalue) {
        $counter++;
        if($counter == 5){
            $output .= '<item>';
            $output .= '<title><![CDATA[Subscribe Now]]></title>';
            $output .= '<link><![CDATA[http://indiatoday.intoday.in/subscription.html?utm_source=rss]]></link>';
            $output .= '<description><![CDATA[Subscribe now for your favourite magazines]]></description>';
            $output .= '</item>';
        }
        $title = $resvalue['title'];
        $nid = $resvalue['nid'];
        $body_value = $resvalue['field_story_expert_description_value'];
        $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
        $url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
        $image_data = get_thumbnail_by_fid($field_story_extra_large_image_fid);
        $img_url = $image_data->imageurl;
        $created = $resvalue['created'];
        date_default_timezone_set("GMT");
        $created_date = date("D, d M Y H:i:s e", $created);  
        $output .= '<item>';
        $output .= '<title><![CDATA[' . $title . ']]></title>';
        $output .= '<link><![CDATA[' . $url . ']]></link>';
        $output .= '<description><a href="'.$url.'"><img src="'.$img_url.'" align="left" hspace="2" height="82" width="107" alt="" border="0" /></a><![CDATA[' . $body_value . ']]></description>';
        $output .= '<pubDate>' . $created_date . '></pubDate>';
        $output .= '<media:content type="video/quicktime" expression="full" url= "' . $url . '">';
        $output .= '<media:category scheme="'. $url . '">' . $term_name . '</media:category>';
        $output .= '<media:text type="plain">' . $title . '</media:text>';
        $output .= '<media:rating scheme="urn:simple">nonadult</media:rating>';
        $output .= '<media:thumbnail width="107" height="82" url="' . $img_url . '"/>';
        $output .= '</media:content>';
        $output .= '</item>';
    }
    return $output;
}
