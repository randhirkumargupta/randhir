<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate videoDetailPage xml feed
 *
 * @return string $output
 */
function videoDetailPageFeed() {
    $output = "";
    if (count(arg()) < 2) {
        $output = "Please pass video node nid in url";
    } else {
        $output = generateVideoDetailPageFeed(arg(1));
    }
    echo $output;
    drupal_exit();
}

/**
 * function for generate generateVideoDetailPageFeed xml feed file
 * @pram int $nid
 * @pram string $file_name, $term_feed_path, $type
 *
 * @return string $return_flag
 */
function generateVideoDetailPageFeed($nid, $file_name = '', $term_feed_path = '', $type) {
    $imgtag = "";
    if (!$file_name) {
        $file_name = "video" . $nid . ".xml";
    }
    if (!$term_feed_path) {
        $term_feed_path = "public://xml_it/videos";
    } elseif ($type) {
        if ($type == "photogallery") {
            $term_feed_path = "public://xml_it/photos";
        } elseif ($type == "story") {
            $term_feed_path = "public://xml_it/stories";
        } elseif ($type == "videogallery") {
            $term_feed_path = "public://xml_it/videos";
        }
    }
    //field_image_caption
    $output = "";
    if (!$nid) {
        $output = "Nid is missing";
    } else {
        //check into redis
        $redis_key = "itgd_video" . $nid;
        $result_get = getRedis($redis_key);
        if ($result_get['key_value'] != "") {
            $output = $result_get['key_value'];
        } else {
            global $base_url;
            $ttl = DEFAULT_REDIS_EXPIRE_TIME;
            $node = node_load($nid);
            $title = html_entity_decode($node->title);
            $tid = $node->field_primary_category['und'][0]['value'];
            $term = taxonomy_term_load($tid);
            $term_name = $term->name;
            $comment_cont = $node->comment;
            $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
            $reporter_node = itg_common_get_node_title($byline_id);
            if (is_null($reporter_node)) {
                $reporter_node = "";
            }
            $related_node = relatedContentNodeType($nid, "videogallery");
            $city = getCityByNid($nid);
            $alias = drupal_get_path_alias('node/' . $nid . '');
            $weburl = FRONT_URL . "/" . $alias;
            $create_date = date("F d, Y", $node->created);
            $create_datetime = date(DATE_ATOM, $node->created);
            $thumbimage = completeFilePath($node->field_story_medium_image['und'][0]['fid']);
            $is_fav = getNidIsFavorite($nid);
            $syndications = getNidIsSyndications($nid);
            $field_video_upload = $node->field_video_upload['und'][0]['value'];
            $file_id = file_usage($field_video_upload);
            $load_collection = field_collection_item_load($field_video_upload);
            $daily_motion_fid = $load_collection->field_videogallery_video_upload['und'][0]['fid'];
            // get video path
            //$video_path_info = videoCheckExistFile($daily_motion_fid, $nid, $field_video_upload);
            $metatags_title = html_entity_decode($node->metatags['und']['keywords']['value']);
            $metatags_description = html_entity_decode($node->metatags['und']['description']['value']);
            $output .= program_section_page_feed_header();
            $createddate = format_date($node->created, 'custom', 'd/m/Y');
            $output .= "<item><videoid>" . $nid . "</videoid><idsection>" . $tid . "</idsection><section><![CDATA[" . $term_name . "]]></section><credit>".xml_cdata_filter($reporter_node)."</credit><createddate>".xml_cdata_filter($create_datetime)."</createddate><date>".$create_date."</date><datetime><![CDATA[" . $create_datetime . "]]></datetime><title><![CDATA[" . $title . "]]></title><thumbimage>".xml_cdata_filter($thumbimage)."</thumbimage><mediaid></mediaid><uurl></uurl>";
            //get video tag
            $source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
            $videotag = video_detail_formats($nid, $source_type);
            $video_size = migrated_video_transcoding($nid);
            // migrated video
            if (!empty($videotag['migrated'])) {
              $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
              foreach ($videoids as $keys => $video_value) {
                $url = $video_value->field_migrated_video_url_value;
              }
              $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
              $bitrate_url = $data_video['bitrate_url'];
              $mp4_url = $data_video['file_url'];
              $output .= "<videoparts><part>" . $bitrate_url . "</part></videoparts><size_364bit>" . $video_size . "</size_364bit><videoparts_mp4><part>" . $mp4_url . "</part></videoparts_mp4><videoparts_m3u8><part>" . $bitrate_url . "</part></videoparts_m3u8><flvvideoparts><part>" . $mp4_url . "</part></flvvideoparts><videoparts_3gp><part>" . $mp4_url . "</part></videoparts_3gp>";
            } elseif (!empty($videotag['dailymotion'])) {
                $videoids = get_video_in_fieldcollection_by_nid($nid);
                foreach ($videoids as $keys => $video_value) {
                  if ($video_value->video_id != '') {
                    $video_id = $video_value->video_id;
                  } elseif ($video_value->solr_video_id != '') {
                    $video_id = $video_value->solr_video_id;
                  }
                }
                $inter_video_details = internal_video_bitrate_data($video_id);
                $output .= "<videoparts><part>" . $inter_video_details['bitrate_url'] . "</part></videoparts><size_364bit>" . $videotag['dailymotion']['filsize'] . "</size_364bit><videoparts_mp4><part>" . $inter_video_details['file_url'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $inter_video_details['bitrate_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $inter_video_details['file_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $inter_video_details['file_url'] . "</part></videoparts_3gp>";
            }
            $output .= "<create_date><![CDATA[" . $create_date . "]]></create_date><create_datetime><![CDATA[" . $create_datetime . "]]></create_datetime><syndications>" . $syndications . "</syndications><is_favorite>" . $is_fav . "</is_favorite><metakeyword>".xml_cdata_filter($metatags_title)."</metakeyword><longdescription>".xml_cdata_filter($metatags_description)."</longdescription><weburl>" . $weburl . "</weburl>";
            //get body img tag
            $imgtag = getImgTagDetail($node);
            if ($imgtag) {
              $output .= $imgtag;
            } else {
              $output .= emptygetImgTagDetail();
            }
            //related node
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
            $output .= "</item>" . program_section_page_feed_footer();
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
 * function for generate all_video_format
 * @pram int $file_id
 *
 * @return array $all_video_data
 */
function all_video_format($file_id) {
    if ($file_id) {
        $query = db_select('dailymotion_response_details', 'avf');
        $query->innerJoin('itg_video_bitrates_data', 'dma', 'dma.video_id = avf.video_id');
        $query->fields('dma', array('bitate_url'));
        $query->condition('avf.fid', $file_id);
        $all_result = $query->execute()->fetchField();
        return $all_video_data = json_decode($all_result, TRUE);
    }
}

/**
 * function for generate video xml tag
 * @pram array $video_path_info
 * @pram int  $file_id
 *
 * @return string $output
 */
function getVideoTagDetail($video_path_info, $file_id = NULL) {
    $output = "";
    $video_path_mp4 = $video_path_info['video_path_mp4'];
    $filesize = $video_path_info['filesize'];
    $flv_url = str_replace(".mp4", ".flv", $video_path_mp4);
    $videoparts_3gp = str_replace(".mp4", ".3gp", $video_path_mp4);
    //to get the video of all the other formats
    $video_formats = all_video_format($file_id);
    if ($video_path_info['dailymtion_flag'] == "yes") {
        $output .= "<videoparts><part>" . $videoparts_3gp . "</part></videoparts><size_364bit>" . $filesize . "</size_364bit><videoparts_mp4><part>" . $video_path_mp4 . "</part></videoparts_mp4><videoparts_m3u8><part>" . $video_formats['stream_h264_hd_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $video_formats['stream_h264_hq_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $video_formats['stream_h264_ld_url'] . "</part></videoparts_3gp>";
    } else {
        $flv_url = str_replace(".mp4", ".flv", $video_path_mp4);
        $videoparts_3gp = str_replace(".mp4", ".3gp", $video_path_mp4);
        $output .= "<videoparts><part>" . $videoparts_3gp . "</part></videoparts><size_364bit>" . $filesize . "</size_364bit><videoparts_mp4><part>" . $video_path_mp4 . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videoparts_3gp . "</part></videoparts_m3u8><flvvideoparts><part>" . $flv_url . "</part></flvvideoparts><videoparts_3gp><part>" . $videoparts_3gp . "</part></videoparts_3gp>";
    }
    return $output;
}

/**
 * function for generate image xml tag
 * @pram object $node
 *
 * @return string $imgtag
 */
function getImgTagDetail($node) {
    $field_story_small_image = $node->field_story_small_image['und'][0]['fid'];
    $field_story_large_image = $node->field_story_large_image['und'][0]['fid'];
    $lowres = completeFilePath($field_story_small_image);
    $highres = completeFilePath($field_story_large_image);
    // custom function for get img caption
    $caption = getImgCaption($field_story_small_image);
    $imgtag = "";
    $imgtag = "<images><image><thumbimage>".xml_cdata_filter($lowres)."</thumbimage><caption>" . xml_cdata_filter($caption) . "</caption></image></images>";
    return $imgtag;
}

/**
 * function for generate Empty image xml tag
 *
 * @return string $imgtag
 */
function emptygetImgTagDetail() {
    $imgtag = "";
    $imgtag = "<images><image><thumbimage></thumbimage><caption></caption></image></images>";
    return $imgtag;
}

/**
 * Function check file id
 * filename
 *
 * @param int $fid
 *
 * @return int $ids
 */
function file_usage($id) {
    $ids = "";
    if ($id) {
        $query = db_select('file_usage', 'fu');
        $query->condition('fu.id', $id);
        $query->fields('fu', array('fid'));
        $results = $query->execute()->fetchAll();
        $ids = $results[0]->fid;
        return $ids;
    }
}

/**
 * Function check exist video filename
 *
 * @param int fid, $nid, $field_video_upload
 *
 * @return array $video_path_info
 */
function videoCheckExistFile($fid, $nid, $field_video_upload) {
    $video_path_info = array();
    $dailymtion_flag = "no";
    $filesize = "";
    $query = db_select('file_managed', 'fm');
    $query->condition('fm.fid', $fid);
    $query->fields('fm', array('filename', 'uri', 'filemime', 'filesize', 'status'));
    $query->orderBy('fm.fid', 'DESC');
    $query->range(0, 1);
    $results = $query->execute()->fetchAll();
    $uri = $results[0]->uri;
    $filename = $results[0]->filename;
    $filesize = $results[0]->filesize;
    // for daily motion vedio
    if (strpos($uri, 'dailymotion_video_dir') !== FALSE) {
        $dailymotion_path = getDailymotionPath($fid, $filename);
        $dailymtion_flag = "yes";
    } else {
        $query = db_select('field_data_field_migrated_video_url', 'fmv');
        $query->condition('fmv.entity_id', $field_video_upload);
        $query->fields('fmv', array('field_migrated_video_url_value'));
        $results = $query->execute()->fetchAll();
        $uri = $results[0]->field_migrated_video_url_value;
        $dailymtion_flag = "no";
        $dailymotion_path = $uri;
    }

    $video_path_info['dailymtion_flag'] = $dailymtion_flag;
    $video_path_info['video_path_mp4'] = $dailymotion_path;
    $video_path_info['filesize'] = $filesize;
    return $video_path_info;
}

/**
 * Function get dailymotion video path
 *
 * @param int $fid
 * @pram string $filename
 *
 * @return string $video_path
 */
function getDailymotionPath($fid, $filename) {
    $query = db_select('dailymotion_response_details', 'drd');
    $query->condition('drd.name', $filename);
    $query->fields('drd', array('title', 'channel', 'type', 'video_id', 'video_duration', 'dailymotion_thumb_url', 'name', 'upload_time'));
    $results = $query->execute()->fetchAll();
    $channel = $results[0]->channel;
    $video_id = $results[0]->video_id;
    $dailymotion_thumb_url = $results[0]->dailymotion_thumb_url;
    $name = $results[0]->name;
    $ext = pathinfo($name, PATHINFO_EXTENSION);
    $type = $results[0]->type;
    $filename_ar = explode(".", $filename);
    $final_filename = $filename_ar[0];
    $final_filename = str_replace("_", "-", $final_filename);
    $video_path = "https://www.dailymotion.com/video/" . $video_id . "";
    return $video_path;
}

/**
 * All video format responce
 *
 * @param int $nid
 * @pram string $source_type
 *
 * @return array $video_detail
 */
function video_detail_formats($nid, $source_type) {
    $video_detail = array();
    if ($source_type != 'migrated') {
        $video_status = 'dailymotion';
        $videoids = get_video_in_fieldcollection_by_nid($nid);
        foreach ($videoids as $keys => $video_value) {
            if ($video_value->video_id != '') {
                $video_id = $video_value->video_id;
            } elseif ($video_value->solr_video_id != '') {
                $video_id = $video_value->solr_video_id;
            }
            $video_detail[$video_status]['video_id'] = $video_id;
            $file_id = $video_value->fid;
        }
        $query = db_select('file_managed', 'fm');
        $query->condition('fm.fid', $file_id);
        $query->fields('fm', array('filename', 'uri', 'filemime', 'filesize', 'status'));
        $query->orderBy('fm.fid', 'DESC');
        $query->range(0, 1);
        $results = $query->execute()->fetchAll();
        $uri = $results[0]->uri;
        $video_detail[$video_status]['filename'] = $results[0]->filename;
        $video_detail[$video_status]['filsize'] = $results[0]->filesize;
        $query = db_select('itg_video_bitrates_data', 'itgv');
        $query->fields('itgv', array('bitate_url', 'bitates_field'));
        $query->condition('itgv.video_id', $video_id);
        $result2 = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $video_format = array();
        foreach ($result2 as $res_data) {
            $video_format[$res_data['bitates_field']] = $res_data['bitate_url'];
        }
        $video_path_mp4 = "https://www.dailymotion.com/video/" . $video_id . "";
        $video_format['videoparts_mp4'] = $video_path_mp4;
        $video_detail[$video_status]['bitate_url'] = $video_format;
        $dailymotion_download = dailymotion_download_video_uri($video_id);
        $video_detail[$video_status]['bitate_url']['download_url'] = "$dailymotion_download";
    } elseif ($source_type == 'migrated') {
        $video_status = 'migrated';
        $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
        foreach ($videoids as $keys => $video_value) {
            $video_path_mp4 = $video_value->field_migrated_video_url_value;
        }
        $video_path_mp4 = str_replace('http://medias3d.intoday.in/', 'http://indiatoday-pdelivery.akamaized.net/', $video_path_mp4);
        $video_detail[$video_status]['video_path_mp4'] = $video_path_mp4;
        $flv_url = str_replace(".mp4", ".flv", $video_path_mp4);
        $rr = explode('/', $video_path_mp4);
        $mp4_last_fname = end($rr);
        $gp_file_path = '3gp/' . $mp4_last_fname . '';
        $videoparts_3gp1 = str_replace($mp4_last_fname, $gp_file_path, $video_path_mp4);
        // m3u8
        $videoparts_3gp = str_replace(".mp4", ".3gp", $videoparts_3gp1);
        $m3u8_tags = mcu8_tags($nid);
        if (!empty($m3u8_tags)) {
            $m3 = implode(',', $m3u8_tags);
            $new_m3 = ',' . $m3 . ',.mp4.csmil/master.m3u8';
            $videoparts_m3u = str_replace('512.mp4', $new_m3, $video_path_mp4);
        } else {
            $m3 = "";
            $new_m3 = ',' . $m3 . ',.mp4.csmil/master.m3u8';
            $videoparts_m3u = str_replace('.mp4', $new_m3, $video_path_mp4);
        }
        $videoparts_m3u8 = str_replace('http://indiatoday-pdelivery.akamaized.net', 'http://indiatoday-vh.akamaihd.net/i', $videoparts_m3u);
        //end
        $videoparts_3gp1 = str_replace($mp4_last_fname, $gp_file_path, $video_path_mp4);
        $video_detail[$video_status]['flv_url'] = $flv_url;
        $video_detail[$video_status]['videoparts_m3u8'] = $videoparts_m3u8;
        $video_detail[$video_status]['videoparts_3gp'] = $videoparts_3gp;
    }
    return $video_detail;
}

/**
 * Get the dailymotion download video url
 *
 * @param type $video_id
 *
 * @return type
 */
function dailymotion_download_video_uri($video_id) {
    $query = db_select('field_data_field_bitrate_video_id', 'bvi');
    $query->leftJoin('field_data_field_video_url', 'v_url', 'v_url.entity_id = bvi.entity_id');
    $query->fields('v_url', array('field_video_url_value'));
    $query->condition('bvi.field_bitrate_video_id_value', $video_id);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result[0]['field_video_url_value'];
}

/**
 * function for getmcu8 url of vedio
 *
 * @param type $nid
 *
 * @return type
 */
function mcu8_tags($nid) {
    //$nid = 17378;
    $query = db_select('field_data_field_multi_bitrate', 'mvr');
    $query->fields('mvr', array('field_multi_bitrate_value'));
    $query->condition('mvr.entity_id', $nid);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $tags = array();
    if (count($result) > 0) {
        foreach ($result as $data) {
            $first_char = strstr($data['field_multi_bitrate_value'], '@', TRUE);
            if ($first_char == 'B' || $first_char == 'M') {
                $tags[] = substr(strstr($data['field_multi_bitrate_value'], '@'), 1);
            }
        }
    }
    return $tags;
}

/**
 * Get the internal uploaded video on the Site
 */
function internal_video_bitrate_data($video_id) {
    $data_video_info = xml_itg_videogallery_get_all_video_info_by_video_id($video_id);
    if ($data_video_info[0]->video_type == 'INTERNAL' || $_POST['getvideo_repo'] == 'INTERNAL') {
        $data_from_solr = xml_itg_videogallery_getsolr_data_for_internal_video($data_video_info[0]->video_id);
        $video_data = $data_from_solr[0];
        $video_all_data = json_decode($video_data, TRUE);
        $player_content = itg_videogallery_make_parm_for_jwpalyer($video_all_data);
    }
    return $player_content;
}
/**
 * Implements itg_videogallery_get_all_video_info_by_video_id
 * @param string $video_id
 * @param array $result
 */
function xml_itg_videogallery_get_all_video_info_by_video_id($video_id) {
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $query->condition('video_id', $video_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}
/**
 * Implement itg_videogallery_getsolr_data_for_internal_video
 * @param string $video_id
 */
function xml_itg_videogallery_getsolr_data_for_internal_video($video_id) {
    if (function_exists('apachesolr_server_status')) {
        $ping = apachesolr_server_status(variable_get('solr_server_url'));
    }
    if ($ping) {
        $solr = apachesolr_get_solr();
        if (function_exists('itg_apache_solr_get_site_hash')) {
            $hash = itg_apache_solr_get_site_hash();
        }
        $all_video_ids = array();
        $hashvalue = implode(' OR ', array_keys($hash));
        $str = 'hash:(' . $hashvalue . ')';
        $query = apachesolr_drupal_query("custom");
        $query->addParam('rows', '1'); // How many rows of result to display default it is 10.
        $query->addParam('qf', 'sm_field_video_id'); // Only search in title
//The bundle which you want to search
        $query->replaceParam("fq", '(' . $str . ')');
        $query->addFilter("bundle", "itg_solr_video");
        $query->addFilter("sm_field_video_id", $video_id);
        $query->setSolrsort('sort_label', 'desc');
        $resp_search = $query->search();
        $all_data = $resp_search->response->docs;
        if (!empty($all_data)) {
            return $all_data[0]->sm_field_all_xml_content;
        }
    }
}
