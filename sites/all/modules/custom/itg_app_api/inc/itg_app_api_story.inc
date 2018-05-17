<?php

/**
 * Inc file contains the functions story API
 */

/**
 * main function for generate StoryDetailPageRerourceValue array
 * @pram int $id
 *
 * @return array
 */
function StoryDetailPageRerourceValue($id) {
    // variable decalartion
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();
    // list array building
    $data = generateStoryDeatilList($id);
    if (!empty($data['data']['title'])) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }
    $output_array['data'] = $data['data'];
    return $output_array;
}

/**
 * function for generate generateStoryDeatilList JSON
 * @pram int $id
 *
 * @return array
 */
function generateStoryDeatilList($id) {
    // variable declaration
    global $base_url;
    $data = array();
    $nid = $id;
    $photo_list_array = array();
    $data_array = array();
    $node = node_load($nid);

    // variable for feed
    $title = $node->title;
    $tid = $node->field_primary_category['und'][0]['value'];
    $extra_large_image = file_create_url($node->field_story_extra_large_image['und'][0]['uri']);
    $large_image_fid = $node->field_story_extra_large_image['und'][0]['fid'];
    $body_without_html = strip_tags($node->body['und'][0]['value']);

    $director = $node->field_mega_review_director[LANGUAGE_NONE]['0']['value'];
    $movie_plot = $node->field_mega_review_movie_plot[LANGUAGE_NONE]['0']['value'];
    $star_cast = $node->field_mega_review_cast['und'];
    $star_cast_name = "";
    if (count($star_cast) > 0) {
        foreach ($star_cast as $key => $value) {
            $star_cast_name .= getCastName($value['target_id']) . ", ";
        }
        $star_cast_name = rtrim($star_cast_name, ", ");
    }

    $n_body = $node->body['und']['0']['value'];
    //$body_with_html = story_body_with_html($node);
    $body_with_html_data = formateNodeBodyToken($n_body);
    $body_with_html = $body_with_html_data['n_body'];
    $poll_id = $body_with_html_data['poll_id'];
    $polls = getPollsData($poll_id);

    $polls_d = array();
    $polls_d = (array) $polls;

    $load_city = taxonomy_term_load($node->field_stroy_city['und'][0]['tid']);
    $location = $load_city->name;
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;

    $field_story_select_templates = $node->field_story_select_templates['und'][0]['value'];
    if ($field_story_select_templates == "buzz") {
        $buzz_temp_flag = "Yes";
    } else {
        $buzz_temp_flag = "No";
    }

    $alias = drupal_get_path_alias('node/' . $nid . '');
    $weburl = $base_url . "/" . $alias;
    $galleryimg = $node->field_gallery_image['und'];
    $toptlapics = count($galleryimg);
    $changed = $node->changed;
    $changed_datetime = date("Y-m-d H:i:s", $changed);
    $comment_cont = getCommentsCount($nid);
    $tag = array();
    $tag = (array) getTag($node);
    $heighligth = array();
    $heighligth = (array) getHighlight($node);
    $author = array();
    $author = (array) generateAuthorTagStory($node, 1);
    $rating = array();
    $rating = (array) getRatings($node);
    $caption = getImgCaption($large_image_fid);
    $story_tech = array();
    $story_tech = (array) getStoryTechs($node);
    $listicle_data = array();
    $listicle_data = (array) buildListicleNode($node);
    $factoid_data = array();
    $factoid_data = (array) buildFactoidNode($node);
    $buzz_data = array();
    $buzz_data = (array) buildBuzzNode($node);
    $expertchunk_data = array();
    $expertchunk_data = (array) buildExpertchunkNode($node);

    $content = $node->field_story_tech_review_chunk['und'][0]['value'];
    // pros & cons function
    $content_org = $content;
    $tech_pros = array();
    $tech_pros = (array) getTechPros($content_org);
    if (count($buzz_data) > 0) {
        $buzz_temp_flag = "1";
    } else {
        $buzz_temp_flag = "0";
    }

    if (count($story_tech) > 0) {
        $tech_temp_flag = "1";
    } else {
        $tech_temp_flag = "0";
    }

    // custom function for get img byline
    $byline = getImgByline($large_image_fid);
    $published_stamp = $node->workbench_moderation['published']->stamp;

    $published_date = date("Y-m-d H:i:s", $published_stamp);
    $firebase_url = get_node_firebase_weburl($nid);

    $tech_photo_gallery = "";
    $tech_photo_gallery = $node->field_technology_photogallery['und'][0]['target_id'];
    $caption = "";
    $byline = "";
    $img_info = getInfoData($large_image_fid);
    $image_courtesy = $img_info['image_courtesy'];
    $image_caption = $img_info['image_caption'];

    $caption = $node->field_story_extra_large_image['und'][0]['title'];
    $style = '<style>*{ margin:0; padding:0}.allVideoSection{margin:10px auto; }.iframepotr{ width:100%!Important;height: calc(100vw * 1.7425)}.iframeland{ width:100%!Important;height: calc(100vw * 0.5625)}.iframesqu{width:100%!Important;height: calc(100vw)}iframe[src*="https://www.youtube.com/"]{ width:100%;height: calc(100vw * 0.5625)}iframe[src*="https://www.indiatoday.in/"]{width: 100%; height: calc(100vw * 0.5625)}</style>';
    //$style = '<style>*{ margin:0; padding:0}.allVideoSection{margin:10px auto; }.iframepotr{ width:100%!Important;height: calc(100vw * 1.7425)}.iframeland{ width:100%!Important;height: calc(100vw * 0.5625)}.iframesqu{width:100%!Important;height: calc(100vw)}iframe[src*=\"https://www.youtube.com/\"]{ width:100%;height: calc(100vw * 0.5625)}iframe[src*=\"https://www.indiatoday.in/\"]{width: 100%; height: calc((100vw) * 0.5625)}</style>';
    $js = '<script type="text/javascript"> var iframesrc = document.querySelectorAll("iframe[src*=\'www.facebook.com\']");for(var idx=0;idx < iframesrc.length;idx++){var url_string = iframesrc[idx].src;var url = new URL(url_string);var hheight = iframesrc[idx].height;var wwidth = url.searchParams.get("width");if(hheight == wwidth){iframesrc[idx].classList.add(\'iframesqu\')}else if(hheight > wwidth){iframesrc[idx].classList.add(\'iframepotr\')}else{iframesrc[idx].classList.add(\'iframeland\')}}</script>';

    //$body_with_html = $style."".$body_with_html."".$js; 
    //data array building
    $title = strip_tags($title);
    $image_caption = strip_tags($image_caption);

    $data_array['category_id'] = "$tid";
    $data_array['category_title'] = "$term_name";
    $data_array['id'] = "$nid";
    $data_array['title'] = "$title";
    $data_array['large_image'] = "$extra_large_image";
    $data_array['image_credit'] = "$image_courtesy";
    $data_array['image_caption'] = "$image_caption";
    $data_array['updated_datetime'] = "$changed_datetime";
    $data_array['published_datetime'] = "$published_date";
    $data_array['buzzflag'] = "$buzz_temp_flag";
    $data_array['techflag'] = "$tech_temp_flag";
    $data_array['location'] = "$location";
    $data_array['director'] = "$director";
    $data_array['movie_plot'] = "$movie_plot";
    $data_array['star_cast'] = "$star_cast_name";
    $data_array['share_link'] = "$firebase_url";
    $data_array['comment_count'] = "$comment_cont";
    $data_array['is_sponsored'] = "";
    $data_array['sponsored_icon'] = "";
    $data_array['sponsored_url'] = "";
    $data_array['desc_withouthtml'] = "$body_without_html";
    $data_array['desc_withhtml'] = "$body_with_html";
    $data_array['tag'] = $tag;
    $data_array['highlight'] = $heighligth;
    if (count($listicle_data['data']) && $listicle_data['data'][0]['description'] != "") {
        $data_array['listicles'] = $listicle_data;
    } else {
        $listicle_data = (object) array();
        $data_array['listicles'] = $listicle_data;
    }
    if (count($factoid_data['data'])) {
        $data_array['factoids'] = $factoid_data;
    } else {
        $factoid_data = new stdClass();
        $data_array['factoids'] = $factoid_data;
    }
    if ($buzz_temp_flag) {
        $data_array['buzz'] = $buzz_data;
    } else {
        $buzz_data = array();
        $data_array['buzz'] = $buzz_data;
    }

    if ($tech_photo_gallery) {
        $photo_list_array = getPhotolistforPhotostory($tech_photo_gallery);
        $photolist = $photo_list_array;
        $data_array['tech_photo_gallery'][0]['title'] = "PHOTO GALLERY";
        $data_array['tech_photo_gallery'][0]['data'] = (array) $photolist[0]['photos'];
        // $data_array['tech_photo_gallery']['p_id'] = "$tech_photo_gallery";
    } else {
        $tech_photo_gallery = array();
        $data_array['tech_photo_gallery'] = $tech_photo_gallery;
    }
    if (count($story_tech[0]['data']) > 0) {
        $data_array['tech_photos'][0]['title'] = "SAMPLE PHOTOS";
        $data_array['tech_photos'][0]['data'] = $story_tech[0]['data'];
    } else {
        $data_array['tech_photos'] = array();
    }
    if ($tech_pros['listcont'] > 0) {
        unset($tech_pros['listcont']);
        $data_array['tech_pros_cons'] = $tech_pros;
    } else {
        $tech_pros_emp = new stdClass();
        //$tech_pros_emp->id = NULL;
        $data_array['tech_pros_cons'] = $tech_pros_emp;
    }
    if (trim($expertchunk_data['name']) == "" && trim($expertchunk_data['image']) == "" && trim($expertchunk_data['expertise']) == "" && trim($expertchunk_data['description']) == "") {
        $expertchunk_data = new stdClass();
        $data_array['expert-chunk'] = $expertchunk_data;
    } else {
        $data_array['expert-chunk'] = $expertchunk_data;
    }

    $data_array['polls'] = $polls_d;
    if (trim($author['a_id']) == "" && trim($author['a_title']) == "" && trim($author['a_image']) == "" && trim($author['a_twitter_handler']) == "") {
        $author = new stdClass();
        $data_array['author'] = $author;
    } else {

        $data_array['author'] = $author;
    }
    if (trim($rating['r_cur_value']) == "" && trim($rating['r_is_star_rating']) == "") {
        $rating = new stdClass();
        $data_array['rating'] = $rating;
    } else {
        $data_array['rating'] = $rating;
    }
    
          /* work on offline start */

        {
            $byline_data = itg_get_multi_byline_details($nid, 1);
            $aid = $byline_data[0]['nid'];
            $a_title = $byline_data[0]['title'];
            
            $arr_offline = array();
            $author = array();
            $nObject = new stdClass();
            $nObject->nid = $nid;
            $author = (array) generateAuthorTagStory($nObject, 1);
            $a_title = $author['a_title'];
            $arr_offline['no_desc_withouthtml'] = "$body_with_html";
            $arr_offline['no_author']['a_title'] = "$a_title";
            $data_array['n_offline_data'] = $arr_offline;
        }
        /* work on offline end */
        // for emoji
            $n_emoji_left = array();
            $n_emoji_right = array();
            $emoji_left = $node->field_story_select_templates['und'][0]['field_emoji_value'];
            $emoji_right = $node->field_story_select_templates['und'][0]['field_emoji_2_value'];
            if ($emoji_left) {
                $n_emoji_left = itg_rapid_get_emoji($emoji_left);
            }
            if ($emoji_right) {
                $n_emoji_right = itg_rapid_get_emoji($emoji_right);
            }
            $data_array['n_emoji_left'] = $n_emoji_left;
            $data_array['n_emoji_right'] = $n_emoji_right;

    $data['data'] = $data_array;
    return $data;
}

/**
 * function for get story tag
 * @pram object $node
 *
 * @return array
 */
function getTag($node) {
    $tag = array();
    $tag_obj = $node->field_story_itg_tags['und'];
    $loop_cont = 0;
    foreach ($tag_obj as $key => $value) {
        $tid = $value['tid'];
        $term = taxonomy_term_load($tid);
        $term_name = $term->name;
        $tag[$loop_cont]['t_id'] = "$tid";
        $tag[$loop_cont]['t_title'] = "$term_name";
        $loop_cont++;
    }
    return $tag;
}

/**
 * function for get story highlight
 * @pram object $node
 *
 * @return array
 */
function getHighlight($node) {
    $heighlight = array();
    $heighlight_obj = $node->field_story_highlights['und'];
    $loop_cont = 0;
    foreach ($heighlight_obj as $key => $value) {
        $text = $value['value'];
        $heighlight[$loop_cont]['h_title'] = "$text";
        $loop_cont++;
    }
    return $heighlight;
}

/**
 * function for getHighlightByNid
 * @pram int $nid
 *
 * @return array
 */
function getHighlightByNid($nid) {
    $heighlight = array();
    $query = db_select('field_data_field_story_highlights', 'shl');
    $query->fields('shl', array('field_story_highlights_value'));
    $query->condition('shl.entity_id', $nid, '=');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $loop_cont = 0;
    foreach ($result as $reskey => $resvalue) {
        $text = $resvalue['field_story_highlights_value'];
        $heighlight[$loop_cont]['h_title'] = "$text";
        $loop_cont++;
    }
    return $heighlight;
}

/**
 * function for get story rating
 * @pram object $node
 *
 * @return array
 */
function getRating($node) {
    $rating = array();
    $field_story_rating = trim($node->field_story_rating['und'][0]['value']);
    if ($field_story_rating != "") {
        $rating['r_cur_value'] = "$field_story_rating";
        $rating['r_upper_range'] = "$field_story_rating";
        $rating['r_is_star_rating'] = "$field_story_rating";
    }

    return $rating;
}

/**
 *
 * @param type $node
 *
 * @return type
 */
function getRatings($node) {
    $rating = array();
    $field_story_rating = trim($node->field_story_rating['und'][0]['value']);
    $rating['r_cur_value'] = "$field_story_rating";
    $rating['r_upper_range'] = "5";
    $rating['r_is_star_rating'] = "$field_story_rating";
    return $rating;
}

/**
 * function for get story cast name
 * @pram int $nid
 *
 * @return array
 */
function getCastName($nid) {
    $title = "";
    if ($nid) {
        $query = db_select('node', 'n');
        $query->fields('n', array('title'));
        $query->condition('n.nid', $nid);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        //return $result[0]['title'];    
        foreach ($result as $key => $value) {
            $title = $value['title'];
        }
    }
    return $title;
}

/**
 * function for get tech node
 * @pram object $node
 *
 * @return array
 */
function getStoryTechs($node) {
    $storytech = array();
    $storytech_fi = array();
    $listcont = 0;
    $tect_img = array();
    $rating = $node->field_story_technology_rating['und'][0]['value'];
    $content = $node->field_story_tech_review_chunk['und'][0]['value'];
    // pros & cons function
    $content_org = $content;
    /* remove pros & cons from contents start */


    $content = preg_replace('#<div class="tech-pros"(.|\s)+</div>#', '', $content);
    $content = preg_replace('#<div class="tech-cons"(.|\s)+</div>#', '', $content);
    /* remove pros & cons from contents start */


    $tect_img = $node->field_story_technology['und'];

    foreach ($tect_img as $key => $value) {
        $val_fid = $value['value'];
        $load_collection = field_collection_item_load($val_fid);
        $photo_ttile = $load_collection->field_technology_photo_title['und'][0]['value'];
        $img_url = completeFilePath($load_collection->field_technology_sample_photo['und'][0]['fid']);
        $img_info = getInfoData($val_fid);
        $p_credit = $img_info['image_courtesy'];
        $p_captions = $img_info['image_caption'];
        $image_date = $img_info['image_date'];
        $storytech['data'][$listcont]['title'] = "$photo_ttile";
        $storytech['data'][$listcont]['img'] = "$img_url";
        $storytech['data'][$listcont]['photo_date'] = "$img_url";
        $storytech['data'][$listcont]['p_credit'] = "$p_credit";
        $storytech['data'][$listcont]['p_captions'] = "$p_captions";
        $listcont++;
    }
    $storytech_fi[] = (array) $storytech;
    if ($listcont) {
        return $storytech_fi;
    } else {
        $dump = array();
        return $dump;
    }
}

/**
 * function for get build listicle node
 * @pram object $node
 *
 * @return array
 */
function buildListicleNode($node) {
    $listiclenode = array();
    $listcont = 0;
    //get listcle temp
    $field_story_templates = $node->field_story_templates['und'][0]['value'];
    // get title
    $field_story_template_guru = $node->field_story_template_guru['und'][0]['value'];
    $listcont = 0;
    $listiclenode['templates'] = "$field_story_templates";
    $listiclenode['title'] = "$field_story_template_guru";
    //listicle loop data
    $field_story_listicle = $node->field_story_listicle['und'];
    //$listcont = 1;
    foreach ($field_story_listicle as $key => $value) {
        $collection_id = $value['value'];
        $load_collection = field_collection_item_load($collection_id);
        $color = $load_collection->field_listicle_color_new['und'][0]['jquery_colorpicker'];
        $type = $load_collection->field_story_listicle_type['und'][0]['value'];
        $description = $load_collection->field_story_listicle_description['und'][0]['value'];
        // loop data
        $listiclenode['data'][$listcont]['description'] = "$description";
        $listiclenode['data'][$listcont]['type'] = "$type";
        $listiclenode['data'][$listcont]['color'] = "$color";
        $listcont++;
    }
    return $listiclenode;
}

/**
 * function for get build factoid node
 * @pram object $node
 *
 * @return array
 */
function buildFactoidNode($node) {

    $factoidnode = array();
    $listcont = 0;
    // get title
    $field_story_factoids_title = $node->field_story_factoids_title['und'][0]['value'];
    $listcont = 0;
    $factoidnode['title'] = "$field_story_factoids_title";
    $field_story_template_factoids = $node->field_story_template_factoids['und'];
    foreach ($field_story_template_factoids as $key => $value) {
        $factoids = $value['value'];
        $factoidnode['data'][$listcont]['description'] = $factoids;
        $listcont++;
    }
    return $factoidnode;
}

/**
 * function for get build buzz node
 * @pram object $node
 *
 * @return array
 */
function buildBuzzNode($node) {

    $buzznode = array();
    $listcont = 0;
    // loop data
    $field_story_template_buzz = $node->field_story_template_buzz['und'];
    foreach ($field_story_template_buzz as $key => $value) {
        $collection_id = $value['value'];
        $load_collection = field_collection_item_load($collection_id);
        // collection data
        $headLine = $load_collection->field_buzz_headline['und'][0]['value'];
        $img_fid = $load_collection->field_buzz_image['und'][0]['fid'];
        $img_url = completeFilePath($img_fid);
        $description = $load_collection->field_buzz_description['und'][0]['value'];

        $buzznode[$listcont]['headLine'] = "$headLine";
        $buzznode[$listcont]['img'] = "$img_url";
        $buzznode[$listcont]['description'] = "$description";
        $listcont++;
    }

    return $buzznode;
}

/**
 * function for get build buzz node
 * @pram object $node
 *
 * @return array
 */
function buildExpertchunkNode($node) {
    $expert_chunk = array();
    // get data
    $field_story_expert_description = trim($node->field_story_expert_description['und'][0]['value']);
    $field_story_expert_image_fid = trim($node->field_story_expert_image['und'][0]['fid']);
    $field_story_expert_name = trim($node->field_story_expert_name['und'][0]['value']);
    $field_story_expertise = trim($node->field_story_expertise['und'][0]['value']);
    $img_url = trim(completeFilePath($field_story_expert_image_fid));

    $expert_chunk['name'] = "$field_story_expert_name";
    $expert_chunk['image'] = "$img_url";
    $expert_chunk['expertise'] = "$field_story_expertise";
    $expert_chunk['description'] = "$field_story_expert_description";

    return $expert_chunk;
}

/**
 * function for  getTechPros
 * @pram string $content_org
 *
 * @return array
 */
function getTechPros($content_org) {
    $techpross = array();
    $listcont = 0;
    $html = $content_org;
    $dom = new DOMDocument();
    $dom->loadHTML($html);
    $xpath = new DOMXPath($dom);
    $nodes = $xpath->query('//*[@class="tech-pros"]');
    $listcont_flag = 0;

    $data = array();
    for ($i = 0; $i < $nodes->length; $i++) {
        $temp = $nodes->item($i)->textContent;
        $techpross[$listcont]['pros'] = $temp;
        $listcont++;
    }

    $techpross_fi = rtrim($techpross[0]['pros'], '\r\n');
    $techpross_ar = explode("\r\n\t", $techpross_fi);
    $listcont = 0;
    $techpross_data = array();
    $pros_img = getTechProsImg($content_org);
    $tech_h2 = getTechProsh2($content_org);

    if ($tech_h2) {
        $str_html = str_get_html($tech_h2);
        $rate = "";
        foreach ($str_html->find('strong') as $element) {
            $rate = $element;
        }
        $rate = ltrim($rate, "<strong>");
        $rate = rtrim($rate, "</strong>");
    }

    $tech_h2 = strip_tags($tech_h2);
    $tech_h2 = str_replace($rate, "", $tech_h2);

    $techpross_data['label'] = "$tech_h2";
    $techpross_data['rating'] = "$rate";
    $techpross_data['img_url'] = "$pros_img";

    $tech_pros_label = getTechProsLabel($content_org, $flag = 0);
    $techpross_data['pros']['label'] = "$tech_pros_label";

    foreach ($techpross_ar as $key => $value) {
        $value = rtrim($value, '\r\n');
        $techpross_data['pros']['data'][$listcont]['title'] = $value;
        $listcont++;
        if ($value) {
            $listcont_flag = 1;
        }
    }

    $tech_cons = array();
    $tech_cons = getTechCons($content_org);
    $techpross_data['cons'] = $tech_cons;
    $techpross_data['listcont'] = $listcont_flag;

    return $techpross_data;
}

/**
 * function for  getTechCons
 * @pram string $content_org
 *
 * @return array
 */
function getTechCons($content_org) {
    $techpross = array();
    $listcont = 0;
    $html = $content_org;
    $dom = new DOMDocument();
    $dom->loadHTML($html);
    $xpath = new DOMXPath($dom);
    $nodes = $xpath->query('//*[@class="tech-cons"]');

    $data = array();
    for ($i = 0; $i < $nodes->length; $i++) {
        $temp = $nodes->item($i)->textContent;
        $techpross[$listcont]['cons'] = $temp;
        $listcont++;
    }

    $techpross_fi = rtrim($techpross[0]['cons'], '\r\n');
    $techpross_ar = explode("\r\n\t", $techpross_fi);
    $listcont = 0;
    $techpross_data = array();
    $tech_cons_label = getTechProsLabel($content_org, $flag = 1);
    $techpross_data['label'] = "$tech_cons_label";
    foreach ($techpross_ar as $key => $value) {
        $value = rtrim($value, '\r\n');
        $techpross_data['data'][$listcont]['title'] = $value;
        $listcont++;
    }
    return $techpross_data;
}

/**
 * function for  getPollsData
 * @pram int $poll_id
 *
 * @return array
 */
function getPollsData($poll_id) {
    $poll_data = array();
    if ($poll_id > 0) {
        $poll_data = pollsdatalist($poll_id);
    }
    return $poll_data;
}

/**
 * Return the data of  poll
 *
 * @param int $poll_id
 *
 * @return array
 */
function pollsdatalist($poll_id) {

    $news2 = array();
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_question_image', 'qi', 'qi.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));
    $query->fields('qi', array('field_poll_question_image_fid'));

    $query->condition('n.type', 'poll');
    $query->condition('n.nid', $poll_id);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $lcont = 0;
    foreach ($result as $k => $res) {
        $news2[$lcont] = getPollLData($res);
        $lcont++;
    }
    return $news2;
}

/*
 * function for associative array based on expected json
 * @pram array 
 * @return array
 */

function getPollLData($res) {

    $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
    $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);
    $poll_ques_img = completeFilePath($res['field_poll_question_image_fid']);
    $poll_nid = $res['nid'];
    $poll_publish_date_time = $res['field_poll_start_date_value'];
    $poll_title = $res['title'];

    $query2 = db_select('field_data_field_poll_answer', 'pa');
    $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
    $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
    $query2->fields('pa', array('field_poll_answer_value'));
    $query2->fields('ot', array('field_poll_answer_text_value'));
    $query2->fields('ai', array('field_poll_answer_image_fid'));
    $query2->condition('pa.entity_id', $res['nid']);
    $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);

    $options2 = array();
    $lcont = 0;
    foreach ($result_option as $p => $pv) {
        $options['o_id'] = isset($pv['field_poll_answer_value']) ? $pv['field_poll_answer_value'] : "";
        $options['o_title'] = isset($pv['field_poll_answer_text_value']) ? $pv['field_poll_answer_text_value'] : "";
        $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
        $options2[$lcont] = $options;
        $lcont++;
    }
    $news = array();
    $news['p_id'] = "$poll_nid";
    $news['p_is_sponsored'] = "";
    $news['p_sponsored_icon'] = "";
    $news['p_sponsored_link'] = "";
    $news['p_publish_datetime'] = "$poll_publish_date_time";
    $news['p_title'] = "$poll_title";
    $news['p_image'] = "$poll_ques_img";
    $news['p_share_link'] = get_node_firebase_weburl($res['nid']);

    $news['p_option'] = $options2;
    return $news;
}

/**
 * function for  getTechProsLabel
 * @pram $content_org
 *
 * @return array
 */
function getTechProsLabel($content_org, $flag = 0) {
    //include 'simple_html_dom.php';
    $h2 = "";
    if ($content_org) {
        $str_html = str_get_html($content_org);
        $h2 = "";
        $lcont = 0;
        foreach ($str_html->find('span') as $element) {
            $h2 = $element;
            $lcont++;
            if ($flag == 0 && $lcont == 1) {
                break;
            }
        }
        $h2 = ltrim($h2, "<span>");
        $h2 = rtrim($h2, "</span>");
    }

    return $h2;
}

/**
 * function for  getBalanklist
 * @pram int $nid
 *
 * @return array
 */
function getBalanklist($nid) {
    $photolist = array();
    $photolist_loop = array();
    $photolist['tech_pros_cons'] = $photolist_loop;
    return $photolist;
}

/**
 * function for get author list for story
 * @pram object $node
 *
 * @return array
 */
function generateAuthorTagStory($node, $status) {
    //$byline = itg_common_get_latest_byline($node->nid, $status);
    $byline_data = itg_get_multi_byline_details($node->nid, $status);
    $aid = $byline_data[0]['nid'];
    $a_title = $byline_data[0]['title'];
    $extra_laarge_file = file_load($byline_data[0]['extra_large_image']);
    $a_image = file_create_url($extra_laarge_file->uri);
    $a_twitter_handler = $byline_data[0]['twitter_handle'];
    $output = array();
    $output['a_id'] = "$aid";
    $output['a_title'] = "$a_title";
    $output['a_image'] = "$a_image";
    $output['a_twitter_handler'] = "$a_twitter_handler";
    return $output;
}

/**
 * function for get getInfoData
 * @pram int
 *
 * @return array
 */
function getInfoData($fid) {
    $data = array();
    if ($fid) {
        $query = db_select('image_info', 'iminfo');
        $query->fields('iminfo', array('image_courtesy', 'image_caption', 'image_date'));
        $query->condition('iminfo.fid', $fid, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result as $k => $res) {
            $data['image_courtesy'] = $res['image_courtesy'];
            $data['image_caption'] = $res['image_caption'];
            $data['image_date'] = $res['image_date'];
        }
    }
    return $data;
}
