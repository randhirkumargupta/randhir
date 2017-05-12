<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate storyDetailPage xml feed
 *
 * @return array
 */
function storyDetailPageFeed() {
    echo "<pre>"; print_r(node_load(349459)); echo "</pre>"; exit();
  $output = "";
  if (count(arg()) < 2) {
    $output = "Please pass story node nid in url";
  }
  else {
    $output = generateStoryDetailPageFeed(arg(1));
  }


  echo  $output;  die();
}

/**
 * function for generate generateStoryDetailPageFeed xml feed file
 *
 * @return array
 */
function generateStoryDetailPageFeed($nid,  $file_name="", $term_feed_path="", $type) {
  //echo print_ar(arg());exit();
  //$nid = 664;
  $imgtag = "";
  if(!$file_name){
      $file_name = "story".$nid.".xml";
  }
  if(!$term_feed_path){
     $term_feed_path = getcwd() . "/sites/default/files/xml_it/stories"; 
     //$term_feed_path = "public://xml_it/stories";
     //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
  }
  elseif($type){
     if($type == "photogallery"){
         $term_feed_path = getcwd() . "/sites/default/files/xml_it/photos";
         //$term_feed_path = "public://xml_it/photos";
	 //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
     } 
     
     elseif($type == "story"){
         $term_feed_path = getcwd() . "/sites/default/files/xml_it/stories";
         //$term_feed_path = "public://xml_it/stories";
	 //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
     } 
     elseif($type == "videogallery"){
         $term_feed_path = getcwd() . "/sites/default/files/xml_it/videos";
         //$term_feed_path = "public://xml_it/videos";
	 //file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
     } 
  }
  
  
  //field_image_caption
  $output = "";
  if (!$nid) {
    $output = "Nid is missing";
  }
  else {
     //check into redis
   $redis_key = "itgd_story".$nid;
   $result_get = getRedis($redis_key);
   
   if($result_get['key_value'] !=""){
       $output = $result_get['key_value'];
       //echo "redis get - ". $output; exit();
   }
   else{
    //$output = "photo detail page";
    global $base_url;
    $ttl = 300;
    $node = node_load($nid);
    //print_ar($node); exit();
    // variable for feed
    $title = $node->title;
    $tid = $node->field_primary_category['und'][0]['value'];
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    $comment_cont = $node->comment;
    $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
    $reporter_node = itg_common_get_node_title($byline_id);
    $related_node = relatedContentNodeType($nid, "story");
    $city = getCityByNid($nid);
    //$weburl = $base_url . "/node/" . $nid;
    $alias = drupal_get_path_alias('node/'.$nid.'');
    $weburl = $base_url ."/". $alias;
    $create_date = date("F d, Y", $node->created);
    $create_datetime = date(DATE_ATOM, $node->created);
    $full_body = $node->body['und']['0']['value'];
    $body_android = getBodyDataForAndroid($full_body);

    //call function getMobileFeedXmlHeader
    $output .= getMobileFeedXmlHeader();
    $output .= "\n<item>
                    <storyid>" . $nid . "</storyid> 
                    <idsection>" . $tid . "</idsection> 
                    <section><![CDATA[" . $term_name . "]]> </section>
                    <headline ><![CDATA[" . $title . "]]></headline >
                    <credit><![CDATA[" . $reporter_node . "]]> </credit>
                    <date>$create_date</date>
                    <datetime>" . $create_datetime . "</datetime>
                    <city><![CDATA[" . $city . "]]></city>
                    <courtesy><![CDATA[]]></courtesy>
                    <body><![CDATA[" . $full_body . "]]></body>
                    <body_android><![CDATA[" . $body_android . "]]></body_android>";
    //get video tag
    $videotag = getVideoTag($node);
    if ($videotag) {
      $output .= $videotag;
    }
    //get video tag
    $imgtag = getImgTag($node);
    if ($imgtag) {
      $output .= $imgtag;
    }
    //web url tag
    $output .= "<weburl><![CDATA[" . $weburl . "]]></weburl>";
    //function for get related node xml tag
    //print_ar($related_node);exit();
    if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
      $output .= getRelatedNodeXmlTag($related_node['nid']);
    }
    //function for get comment xml tag
    if ($comment_cont > 0) {
      $output .= getCommentXmlTag($node);
    }
    //call function getMobileFeedXmlFooter
    $output .= "</item>" . getMobileFeedXmlFooter();
    // header('Content-Type: application/xml; charset=utf-8');
    // set into redis
    $result_set = setRedis($redis_key, $output, $ttl);
     //echo "redis set - ". $result_set['set_flag']; exit();
  } 
  }
//header('Content-Type: application/xml; charset=utf-8');
//echo $output; exit();
    if($output){
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
    }
    else{
        $return_flag .="Nid is missing";
    }

  return $return_flag;
}

/**
 * function for generate video xml tag
 *
 * @return array
 */
function getVideoTag($node) {
  $videotag = "";

  $src = "";

  $html = $node->body['und']['0']['value'];
  $doc = new DOMDocument();
  libxml_use_internal_errors(TRUE);
  // loads your html
  $doc->loadHTML($html);
  $xpath = new DOMXPath($doc);
  // find your image
  $nodelist = $xpath->query("//iframe");
  // gets the 1st image
  $node = $nodelist->item(0);
  //$src = $node->attributes->getNamedItem('src')->nodeValue;

  if ($src) {
    $videotag = "\n<video_embed>
                    <videoparts_mp4>
                        <part>" . $src . "</part>
                        <img_url><![CDATA[]]></img_url>
                    </videoparts_mp4>
                    <videoparts_m3u8>
                        <part>" . $src . "</part>
                        <img_url><![CDATA[]]></img_url>
                    </videoparts_m3u8>
                </video_embed>\n";
  }
  return $videotag;
}

/**
 * function for generate image xml tag
 *
 * @return array
 */
function getImgTag($node) {
  $imgtag = "";
  $src = "";

  $html = $node->body['und']['0']['value'];
  $doc = new DOMDocument();
  libxml_use_internal_errors(TRUE);
  // loads your html
  $doc->loadHTML($html);
  $xpath = new DOMXPath($doc);
  // find your image
  $nodelist = $xpath->query("//img");
  // gets the 1st image
  $node = $nodelist->item(0);
  //$src = $node->attributes->getNamedItem('src')->nodeValue;
  if ($src) {
    $imgtag = "\n<bodyimages> 
                    <image>  
                        <lowres><![CDATA[" . $src . "]]></lowres>
                        <highres><![CDATA[" . $src . "]]></highres>
                        <caption></caption>  
                    </image> 
                </bodyimages>\n";
  }

  return $imgtag;
}

