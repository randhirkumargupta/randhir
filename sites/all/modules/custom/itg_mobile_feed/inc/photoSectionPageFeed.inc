<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate photoSectionPage xml feed
 *
 * @return array
 */
function photoSectionPageFeed() {
    //check into redis
    $redis_key = "itgd_photoSectionPageFeed";
    $result_get = getRedis($redis_key);

    if ($result_get['key_value'] != "") {
        $output = $result_get['key_value'];
    } else {
        global $base_url;
        $ttl = DEFAULT_REDIS_EXPIRE_TIME;

        $conf_array = tidConfig();
        $output = "";
        $section_list = array();
        $section_list_story = array();
        $term_list = array();
        $node_count = 0;
        $term_name = "";
        $term_url = "";
        $file_name = "";
        $cat_icon_img = "";

        $listcount = 0;
        $return_flag = "";

        // get section list
        $section_list = $conf_array['photo_sec_tid'];
        foreach ($section_list as $key => $value) {
            $node_count = customNodeCount('photogallery', $value);
            $term_status = itg_category_manager_term_state(trim($value), CATEGORY_MANAGMENT);

            if ($node_count > 0 && $term_status == 1) {
                $value = trim($value);
                $term = taxonomy_term_load($value);
                $term_name = $term->name;
                $term_url = nodeCategoryFrontUrl($value, 'term');

                $term_name = drupal_strtolower(str_replace(" ", "-", $term_name));
                $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
                $term_file_name = $term_name . "_photo.xml";
                // section xml feed file name
                $listcount++;
                $cat_icon_img = sectionCategoryIconImg($value);
                // child xml node
                $child_node .= "<item><sectionname><![CDATA[" . $term_name . "]]></sectionname><sectionurl><![CDATA[" . $term_file_name . "]]></sectionurl>";

                $child_node .= getNodeFeedTag($value, 'photogallery', 2);
                $child_node .= "</item>";
            }
        }
        //write xml node of photosectionlisting
        if ($child_node) {
            // xml feed header
            $output .= getMobileFeedXmlHeader();
            $output .= "<idsection>11111</idsection><section>photos</section><totalsections>" . $listcount . "</totalsections><start_index>0</start_index><end_index>" . $listcount . "</end_index>";
            // child node
            $output .= $child_node;
            // xml feed footer
            $output .= getMobileFeedXmlFooter();
        }
        $result_set = setRedis($redis_key, $output, $ttl);
    }
    // write xml file - photosectionlisting.xml

    if ($output) {
        $term_feed_path = getcwd() . "/sites/default/files/xml_it/photos";
        $file_name = "photosectionlisting.xml";
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
    }
    header('Content-Type: application/xml; charset=utf-8');
    echo $output;
    die();
}
