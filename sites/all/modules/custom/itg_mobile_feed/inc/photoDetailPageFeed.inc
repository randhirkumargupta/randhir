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
    $output = "";
    if (count(arg()) < 2) {
        $output = "Please pass photogallery node nid in url";
    } else {
        $output = generatePhotoDetailPageFeed(arg(1));
    }
    echo $output;
    die();
}

/**
 * function for generate generatePhotoDetailPageFeed xml feed file
 *
 * @return array
 */
function generatePhotoDetailPageFeed($nid, $file_name = "", $term_feed_path = "", $type) {
    $imgtag = "";

    if (!$file_name) {
        $file_name = "photo" . $nid . ".xml";
    }
    if (!$term_feed_path) {
        $term_feed_path = getcwd() . "/sites/default/files/xml_it/photos";
    } elseif ($type) {
        if ($type == "photogallery") {
            $term_feed_path = "public://xml_it/photos";
            file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
        } elseif ($type == "story") {
            $term_feed_path = "public://xml_it/stories";
            file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
        } elseif ($type == "videogallery") {
            $term_feed_path = "public://xml_it/videos";
            file_prepare_directory($term_feed_path, FILE_CREATE_DIRECTORY);
        }
    }
    //field_image_caption
    $output = "";
    if (!$nid) {
        $output = "Nid is missing";
    } else {

        //check into redis
        $redis_key = "itgd_photo" . $nid;
        $result_get = getRedis($redis_key);

        if ($result_get['key_value'] != "") {
            $output = $result_get['key_value'];
        } else {
            global $base_url;
            $ttl = DEFAULT_REDIS_EXPIRE_TIME;
            $node = node_load($nid);
            $title = $node->title;
            $tid = $node->field_primary_category['und'][0]['value'];
            $term = taxonomy_term_load($tid);
            $term_name = $term->name;
            $comment_cont = $node->comment;
            $related_node = relatedContentNodeType($nid, "photogallery");
            $alias = drupal_get_path_alias('node/' . $nid . '');
            $weburl = $base_url . "/" . $alias;
            $galleryimg = $node->field_gallery_image['und'];
            $toptlapics = count($galleryimg);
            $output .= getMobileFeedXmlHeader();
            $output .= "<idgallery>" . $nid . "</idgallery><gallery><![CDATA[" . $title . "]]></gallery><idsection>" . $tid . "</idsection><section>" . $term_name . "</section><totalpics>" . $toptlapics . "</totalpics><weburl><![CDATA[" . $weburl . "]]></weburl>";
            //get gallery img tag
            $imgtag = getGalleryImgTag($galleryimg);
            if ($imgtag) {
                $output .= $imgtag;
            }
            //function for get related node xml tag
            if (isset($related_node['nid']) && count($related_node['nid']) > 0) {
                $output .= getRelatedNodeXmlTag($related_node['nid']);
            } else {
                $output .= emptygetRelatedNodeXmlTag();
            }
            //function for get comment xml tag
            if ($comment_cont > 0) {
                $output .= getCommentXmlTag($node);
            } else {
                $output .= emptygetCommentXmlTag();
            }
            $output .= getMobileFeedXmlFooter();
            // set into redis
            $result_set = setRedis($redis_key, $output, $ttl);
        }
    }
    if ($output) {
        $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
    } else {
        $return_flag .= "Nid is missing";
    }

    return $return_flag;
}

/**
 * function for generate getGalleryImgTag xml tag
 *
 * @return array
 */
function getGalleryImgTag($galleryimg) {
    $output = "";
    if (count($galleryimg) > 0) {
        $output = "";
        foreach ($galleryimg as $key => $value) {
            $fid = $value['value'];
            $fid_file = $value['revision_id'];
            $img_url = completeFilePath($fid_file);
            // custom function for get img caption
            $caption = getImgCaption($fid);
            // custom function for get img byline
            $byline = getImgByline($fid);
            $output .= "<item><imageid>" . $fid . "</imageid><image><![CDATA[" . $img_url . "]]></image><largeimage><![CDATA[" . $img_url . "]]></largeimage><caption><![CDATA[" . $caption . "]]> </caption><byline>" . $byline . "</byline></item>";
        }
    }
    return $output;
}
