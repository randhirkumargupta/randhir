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
  //check into redis
   $redis_key = "itgd_videoSectionPageFeed";
   $result_get = getRedis($redis_key);
   
   if($result_get['key_value'] !=""){
       $output = $result_get['key_value'];
       //echo "redis get - ". $output; exit();
   } 
   else{
  // variable declation  
  global $base_url;
  $output = "";
  $ttl = 300;
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
  
  // get section list
  //$section_list = categoryManagerSectionTid('videogallery');
  $section_list = $conf_array['video_sec_tid'];
  //fatch & write xml node of all vedio main cat
  foreach ($section_list as $key => $value) {
    // check is story section
    $node_count = customNodeCount('videogallery', $value);
    
    if ($node_count > 0 ) {
        
      $term = taxonomy_term_load($value);
      $term_name = $term->name;
      $term_url = nodeCategoryFrontUrl($value, 'term');
      
      $term_name = drupal_strtolower(str_replace(" ", "-", $term_name));
      $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
      $term_file_name = "video_".$term_name.".xml";
      // section xml feed file name
        $listcount++;        
        $cat_icon_img = sectionCategoryIconImg($value);
        // child xml node
        $child_node .= "\n<item>
                            <sectionname><![CDATA[" . $term_name . "]]></sectionname>
                            <sectionurl><![CDATA[" . $term_file_name . "]]></sectionurl>";

        // get videogallery node tag
        $child_node .= getNodeFeedTag($value, 'videogallery', 2);

        $child_node .= "</item>";     
      
    }
  }
 //write xml node of videosectionlisting
  if ($child_node) {
        // xml feed header
        $output .= getMobileFeedXmlHeader();
        $output .= "\n<idsection>22222</idsection>
                    <section>videos</section>
                    <totalsections>".$listcount."</totalsections>
                    <start_index>0</start_index>
                    <end_index>".$listcount."</end_index>\n";
        // child node
        $output .= $child_node;
        // xml feed footer
        $output .= "\n" . getMobileFeedXmlFooter();
      }
    // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
    //echo "redis set - ". $result_set['set_flag']; exit();
   }  
 // write xml file - videosectionlisting.xml
  
  if ($output) {
        $file_name = "videsectionlist.xml";
        $term_feed_path = getcwd() . "/sites/all/modules/custom/itg_mobile_feed/xml_it/videos"; 
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
      }
  //return $return_flag;
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;  die();
}

