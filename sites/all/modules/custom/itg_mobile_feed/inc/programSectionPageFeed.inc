<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate programSectionPageFeed xml feed
 *
 * @return array
 */
function programSectionPageFeed() {
  //check into redis
  $redis_key = "itgd_programSectionPageFeed";
  $result_get = getRedis($redis_key);

  if ($result_get['key_value'] != "") {
    $output = $result_get['key_value'];
  }
  else {
    // variable declation
    global $base_url;
    $output = "";
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    // tid conf function
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

    $section_list = $conf_array['program_sec_tid'];
    foreach ($section_list as $key => $value) {
      // check section is story
      $node_count = customNodeCount('videogallery', $value);
      $term_status = itg_category_manager_term_state(trim($value),CATEGORY_MANAGMENT);
      
      if ($node_count > 0 && $term_status == 1) {

	      $value = trim($value);
        $term = taxonomy_term_load($value);
        $term_name = $term->name;
        $term_url = nodeCategoryFrontUrl($value, 'term');
        $child_term_url = nodeCategoryFrontUrl($value, 'term');

        $term_name = drupal_strtolower(str_replace(" ", "-", $term_name));
        $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
        $term_file_name = $term_name . ".xml";
        // section xml feed file name
        $listcount++;
        $cat_icon_img = sectionCategoryIconImg($value);
        // child xml node
        $child_node .= "<item><title><![CDATA[" . $term_name . "]]></title><url>" . $term_file_name . "</url><weburl><![CDATA[" . $base_url . "/" . $child_term_url . "]]></weburl><sectionimage>" . $cat_icon_img . "</sectionimage></item>";
      }
    }
    //write xml node of storysectionlisting
    if ($child_node) {
      // xml feed header
      $output .= program_section_page_feed_header();
      $output .= "<id>1</id><title><![CDATA[programmes]]></title><itemcount>" . $listcount . "</itemcount>";
      // child node
      $output .= $child_node;
      // xml feed footer
      $output .= program_section_page_feed_footer();
    }
    // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
  }

  if ($output) {
    $term_feed_path = getcwd() . "/sites/default/files/xml_it/videos";
    $file_name = "programmes.xml";
    $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
  }
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;
  die();
}
