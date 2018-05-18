<?php
/**
 * Implements function for insert video from xml
 * @return array
 */
/**
 * Call back function for video insert API
 * @pram $_POST in XML formate
 *
 * @return array - The processed information array.
 */
function itg_videogallery_xml_file_video_insert() {
    $data = file_get_contents('php://input');
    $xml_data = simplexml_load_string($data);
    $xml_resp = "<?xml version='1.0' encoding='utf-8'?><Root> ";
    foreach ($xml_data->article as $xml) {
        $long_headline = $xml->long_headline;
        $short_headline = $xml->short_headline;
        $description = $xml->description;
        $city = $xml->city;
        $anchor = (int) $xml->anchor;
        $video_kicker = $xml->video_kicker;
        $section_id = (int) $xml->section_id;
        $cat_id = (int) $xml->cat_id;
        $extra_large_img = $xml->extra_large_img;
        $large_img = $xml->large_img;
        $medium_img = $xml->medium_img;
        $small_img = $xml->small_img;
        $extra_small_img = $xml->extra_small_img;
        $video_file_name = $xml->video_file_name;
        //prepare node object
        $node = new stdClass();
        $node->title = trim(html_entity_decode($long_headline));
        $node->type = "videogallery";
        node_object_prepare($node);
        $node->language = LANGUAGE_NONE;
        $node->uid = 1522; //itgsiteadmin
        $node->promote = 0;
        $node->comment = 0;
        $node->status = 0;
        $node->body[$node->language][0]['value'] = $description;
        $node->body[$node->language][0]['format'] = 'full_html';
        //$node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($long_headline));                    
        $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($short_headline));

        $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'videogallery';
        if (!empty($cat_id)) {
            $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $cat_id;
            $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $section_id;
        }

        $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'] = trim($anchor);
        $node->field_stroy_city[LANGUAGE_NONE][0]['value'] = trim($city);
        $node->field_story_expert_description[LANGUAGE_NONE][0]['value'] = $video_kicker;
        $node->field_video_file_name[LANGUAGE_NONE][0]['value'] = $video_file_name;

        $node = node_submit($node); // Prepare node for saving
        $node->created = $publish_date_timestamp;
//p($node);
        $fid_extra_large_image = itg_videogallery_rap_upload_img($extra_large_img);
        $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid_extra_large_image;
        $fid_large_img = itg_videogallery_rap_upload_img($large_img);
        $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] = $fid_large_img;
        $fid_medium_img = itg_videogallery_rap_upload_img($medium_img);
        $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] = $fid_medium_img;
        $fid_small_img = itg_videogallery_rap_upload_img($small_img);
        $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] = $fid_small_img;
        $fid_extra_small_img = itg_videogallery_rap_upload_img($extra_small_img);
        $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] = $fid_extra_small_img;
        try {
            node_save((object) $node);
            $success = TRUE;
        } catch (Exception $e) {           
            $success = FALSE;
        }
        if ($success) {
            $data['status_code'] = "1";
            $data['status_message'] = "";
            $xml_resp .= "<item>";
            $xml_resp .= "<sucess_code>1</sucess_code>";
            $xml_resp .= "<video_file_name>".$video_file_name."</video_file_name>";
            $xml_resp .= "</item>";
        }
        else{
            $data['status_code'] = "1";
            $data['status_message'] = "";
            $xml_resp .= "<item>";
            $xml_resp .= "<sucess_code>0</sucess_code>";
            $xml_resp .= "<video_file_name>".$video_file_name."</video_file_name>";
            $xml_resp .= "</item>";
        }
    }
    $xml_resp .= "</Root> ";
}
/**
 * itg_videogallery_rap_upload_img
 * @param type $url
 * @return type
 */

function itg_videogallery_rap_upload_img($url){
    $fid = 0;
    if($url){
        $extra_large_image_url = file_get_contents($url);
        $extra_large_image = base64_encode($extra_large_image_url);
        $fid = $fid_extra_large_image = uplodaProfileImg_Rapid($extra_large_image);
    }
    return $fid;
}