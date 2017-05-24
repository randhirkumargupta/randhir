<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate photoDetailPage xml feed
 *
 * @return array
 */
function photoDetailPageFeed() {
  //echo getImgByline();
  $output = "";
  if (count(arg()) < 2) {
    $output = "Please pass photogallery node nid in url";
  }
  else {
    $output = generatePhotoDetailPageFeed(arg(1));
  }


  echo $output; die();
}

/**
 * function for generate generatePhotoDetailPageFeed xml feed file
 *
 * @return array
 */
function generatePhotoDetailPageFeed($nid, $file_name="", $term_feed_path="") {
  //echo print_ar(arg());exit();
 // $nid = 626;
  $imgtag = "";
  
  
  if(!$file_name){
      $file_name = "photo" . $nid . ".xml";
  }
  if(!$term_feed_path){
     $term_feed_path = getcwd() . "/sites/all/modules/custom/itg_mobile_feed/xml_it/photos"; 
  }
  //field_image_caption
  $output = "";
  if (!$nid) {
    $output = "Nid is missing";
  }
  else {
    
    //check into redis
   $redis_key = "itgd_photo".$nid;
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
    $related_node = relatedContentNodeType($nid);
    //$weburl = $base_url . "/node/" . $nid;
    $alias = drupal_get_path_alias('node/'.$nid.'');
    $weburl = $base_url ."/". $alias;
    $galleryimg = $node->field_gallery_image['und'];
    $toptlapics = count($galleryimg);
    //call function getMobileFeedXmlHeader
    $output .= getMobileFeedXmlHeader();
    $output .= "\n<idgallery>" . $nid . "</idgallery>
                    <gallery><![CDATA[" . $title . "]]></gallery>
                    <idsection>" . $tid . "</idsection>
                    <section>" . $term_name . "</section>
                    <totalpics>" . $toptlapics . "</totalpics>
                    <weburl><![CDATA[" . $weburl . "]]></weburl>";
    //get gallery img tag
    $imgtag = getGalleryImgTag($galleryimg);
    if ($imgtag) {
      $output .= $imgtag;
    }
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
    $output .= getMobileFeedXmlFooter();
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
 * function for generate getGalleryImgTag xml tag
 *
 * @return array
 */
function getGalleryImgTag($galleryimg) {
  //print_ar(file_load(576));exit();
  // print_ar($galleryimg, "getGalleryImgTag");exit();
  $output = "";
  if (count($galleryimg) > 0) {
    // loop on gallery img
    $output = "";
    foreach ($galleryimg as $key => $value) {
      //print_ar($value, "getGalleryImgTag");exit();
      $fid = $value['value'];
      $fid_file = $value['revision_id'];
      $img_url = completeFilePath($fid_file);
      // custom function for get img caption
      $caption = getImgCaption($fid);
      // custom function for get img byline
      $byline = getImgByline($fid);
      $output .= "\n<item> 
                        <imageid>" . $fid . "</imageid> 
                        <image><![CDATA[" . $img_url . "]]></image>
                        <largeimage><![CDATA[" . $img_url . "]]></largeimage>
                        <caption><![CDATA[" . $caption . "]]> </caption>
                        <byline>" . $byline . "</byline> 
                        </item>";
    }
  }
  return $output;
}

