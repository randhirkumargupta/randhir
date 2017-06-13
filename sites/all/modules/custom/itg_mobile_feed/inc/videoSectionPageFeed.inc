<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate videoSectionPage xml feed
 *
 * @return array
 */
function videoSectionPageFeed() {
  $redis_key = "itgd_videoSectionPageFeed";
  $result_get = getRedis($redis_key);

  if ($result_get['key_value'] != "") {
    $output = $result_get['key_value'];
  }
  else {
    // variable declation
    global $base_url;
    $output = "";
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $conf_array = tidConfig();
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
    $section_list = $conf_array['video_sec_tid'];
    foreach ($section_list as $key => $value) {
      $node_count = customNodeCount('videogallery', $value);

      if ($node_count > 0) {

        $term = taxonomy_term_load($value);
        $term_name = $term->name;
        $term_url = nodeCategoryFrontUrl($value, 'term');

        $term_name = drupal_strtolower(str_replace(" ", "-", $term_name));
        $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
        $term_file_name = "video_" . $term_name . ".xml";
        // section xml feed file name
        $listcount++;
        $cat_icon_img = sectionCategoryIconImg($value);
        // child xml node
        $child_node .= "<item><sectionname><![CDATA[" . $term_name . "]]></sectionname><sectionurl><![CDATA[" . $term_file_name . "]]></sectionurl>";

        // get videogallery node tag
        $child_node .= getNodeFeedTag($value, 'videogallery', 2);

        $child_node .= "</item>";
      }
    }
    //write xml node of videosectionlisting
    if ($child_node) {
      // xml feed header
      $output .= getMobileFeedXmlHeader();
      $output .= "<idsection>22222</idsection><section>videos</section><totalsections>" . $listcount . "</totalsections><start_index>0</start_index><end_index>" . $listcount . "</end_index>";
      // child node
      $output .= $child_node;
      // xml feed footer
      $output .= getMobileFeedXmlFooter();
    }
    // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
  }
  // write xml file - videosectionlisting.xml

  if ($output) {
    $file_name = "videsectionlist.xml";
    $term_feed_path = getcwd() . "/sites/default/files/xml_it/videos";
    $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
  }
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;
  die();
}
