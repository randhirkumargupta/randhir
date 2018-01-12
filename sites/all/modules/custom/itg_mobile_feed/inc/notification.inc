<?php

/**
 * Inc file contains global configurations
 */

/**
 * Common function to define the some Primary values
 *
 * @return string
 */
function get_notification_config() {
    $config = array();
    $config['start_index'] = 0;
    $config['end_index'] = 20;
    $config['idsection'] = 1;
    $config['section'] = 'Notifications';
    $config['footersharemsg'] = 'Shared via India Today News App  http://bit.ly/1DBXcjS';
    return $config;
}

/**
 * Common function to build notification page
 */
function notification_page() {
    $params = drupal_get_query_parameters();
    generate_notification_all($params);
}

/**
 * Create notification file based on args
 *
 * @param type $params
 */
function generate_notification_all($params) {
    $idsection = 1;
    $section = 'Notifications';
    $file_name = '';
    $output = '';
    $app_file_name = '';
    $app_output = '';
    $return_flag .= '';
    $footersharemsg = isset($params['title']) ? $params['title'] : '';
    $website = isset($params['website']) ? $params['website'] : '';
    //Application ID 1-India Today 4-India Today Ipad 6:test all devices
    $app_id = isset($params['app_id']) ? $params['app_id'] : '';
    //1 - iOS; 2 - BB; 3 - Android; 4 - Nokia ASHA; 5 - Windows Phone; 7 - OS X; 8 - Windows 8; 9 - Amazon; 10 - Safari; 11 - Chrome
    $device = isset($params['device']) ? $params['device'] : '';
    //defined the path in tidconfig.inc
    $term_feed_path = "public://xml_it/notifications";
    //XML Files Generation Based on App Id
    if ($app_id == '4') {
        $app_file_name = 'notification_ipad.xml';
        $app_output .= ipad_notification_xml();
    } elseif ($app_id == '6') {
        // XML Files Generation Based on Device Id
        $dev = explode(',', $params['device']);
        foreach ($dev as $dev_id) {
            if ($dev_id == '1') {
                $file_name = 'notification_ios_test.xml';
                $output .= default_xml_feed();
            } elseif ($dev_id == '2') {
                $file_name = 'notification_bb_test.xml';
                $output = bb_notification_xml();
            } elseif ($dev_id == '3') {
                $file_name = 'notification_android_test.xml';
                $output = default_xml_feed();
            } elseif ($dev_id == '4') {
                $file_name = 'notification_nokiaasha_test.xml';
                $output = nokiaasha_notification_xml();
            } elseif ($dev_id == '5') {
                $file_name = 'notification_windowsphone_test.xml';
                $output = default_xml_feed();
            } elseif ($dev_id == '7') {
                $file_name = 'notification_osx_test.xml';
                $output = osx_notification_xml();
            } elseif ($dev_id == '8') {
                $file_name = 'notification_windows8_test.xml';
                $output = windows8_notification_xml();
            } elseif ($dev_id == '9') {
                $file_name = 'notification_amazon_test.xml';
                $output = amazon_notification_xml();
            } elseif ($dev_id == '10') {
                $file_name = 'notification_safari_test.xml';
                $output = safari_notification_xml();
            } elseif ($dev_id == '11') {
                $file_name = 'notification_chrome_test.xml';
                $output = chrome_notification_xml();
            }
            if ($output && $output != '') {
                $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
            }
        }
    } elseif ($app_id == '1') {
        // XML Files Generation Based on Device Id
        $dev = explode(',', $params['device']);
        foreach ($dev as $dev_id) {
            if ($dev_id == '1') {
                $file_name = 'notification_ios.xml';
                $output .= default_xml_feed();
            } elseif ($dev_id == '2') {
                $file_name = 'notification_bb.xml';
                $output = bb_notification_xml();
            } elseif ($dev_id == '3') {
                $file_name = 'notification_android.xml';
                $output = default_xml_feed();
            } elseif ($dev_id == '4') {
                $file_name = 'notification_nokiaasha.xml';
                $output = nokiaasha_notification_xml();
            } elseif ($dev_id == '5') {
                $file_name = 'notification_windowsphone.xml';
                $output = default_xml_feed();
            } elseif ($dev_id == '7') {
                $file_name = 'notification_osx.xml';
                $output = osx_notification_xml();
            } elseif ($dev_id == '8') {
                $file_name = 'notification_windows8.xml';
                $output = windows8_notification_xml();
            } elseif ($dev_id == '9') {
                $file_name = 'notification_amazon.xml';
                $output = amazon_notification_xml();
            } elseif ($dev_id == '10') {
                $file_name = 'notification_safari.xml';
                $output = safari_notification_xml();
            } elseif ($dev_id == '11') {
                $file_name = 'notification_chrome.xml';
                $output = chrome_notification_xml();
            }

            if ($output && $output != '') {
                $return_flag .= writeFeedFile($term_feed_path, $file_name, $output);
            }
        }
    }
    $default_output = default_xml_feed();
    $default_file_name = 'notification_all.xml';
    $return_flag .= writeFeedFile($term_feed_path, $default_file_name, $default_output);

    if (isset($app_output) && $app_output != '') {
        $return_flag .= writeFeedFile($term_feed_path, $app_file_name, $app_output);
    }
    echo $return_flag;
    drupal_exit();
}

/**
 * Common Function to get weburl
 * @global type $base_url
 *
 * @param type $nid
 *
 * @return string
 */
function get_web_url($nid) {
    global $base_url;
    $alias = drupal_get_path_alias('node/' . $nid . '');
    $weburl = FRONT_URL . "/" . $alias;
    return $weburl;
}

/**
 * Function for getting the xml output for notification_all, android, ios
 *
 * @return string $output
 */
function default_xml_feed() {
    $totalarticle = count(message_data());
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index><footersharemsg>" . $config['footersharemsg'] . "</footersharemsg>";
    $output .= notifications_article();
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the Ipad notification Xml Output
 *
 * @return string $output
 */
function ipad_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;

            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }

                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the chrome notification Xml Output
 *
 * @return string $output
 */
function chrome_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index><footersharemsg>" . $config['footersharemsg'] . "</footersharemsg>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;
            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><weburl><![CDATA[" . $weburl . "]]></weburl><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }
                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><url>" . $url . "</url><weburl>" . $web_url . "</weburl ><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the safari notification Xml Output
 *
 * @return string $output
 */
function safari_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;

            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }
                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the amazon notification Xml Output
 *
 * @return string $output
 */
function amazon_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;

            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;

            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }

                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the Window 8 notification Xml Output
 *
 * @return string $output
 */
function windows8_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);

            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;

            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;

            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }
                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the osx notification Xml Output
 *
 * @return string $output
 */
function osx_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;

            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }

                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }

    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the Nokia Asha notification Xml Output
 *
 * @return string $output
 */
function nokiaasha_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;

            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }
                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting the BB Xml Output
 *
 * @return string $output
 */
function bb_notification_xml() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    $config = get_notification_config();
    $output = '';
    $output .= getMobileFeedXmlHeader();
    $output .= "<idsection>" . $config['idsection'] . "</idsection><section>" . $config['section'] . "</section><totalarticle>" . $totalarticle . "</totalarticle><start_index>" . $config['start_index'] . "</start_index><end_index>" . $config['end_index'] . "</end_index>";
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;
            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $msg_node->title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }
                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
        }
    }
    $output .= getMobileFeedXmlFooter();
    return $output;
}

/**
 * Function for getting notifications article
 *
 * @return string $output
 */
function notifications_article() {
    $all_data = message_data();
    $totalarticle = count($all_data);
    if ($totalarticle > 0) {
        foreach ($all_data as $data) {
            $msg_node = node_load($data->content_id);
            $android_header = $data->android_header;
            $thumb_image = isset($msg_node->field_story_small_image['und'][0]['uri']) ? file_create_url($msg_node->field_story_small_image['und'][0]['uri']) : '';
            $kicker_image = '';
            $primary_cat = $msg_node->field_story_category['und'][0]['tid'];
            $cat = taxonomy_term_load($primary_cat);
            $section = $cat->name;
            $weburl = isset($msg_node->nid) ? get_web_url($msg_node->nid) : '';
            $title = isset($msg_node->title) ? $msg_node->title : '';
            if ($msg_node->type == 'story') {
                $url = 'story' . $msg_node->nid . '.xml';
                generateStoryDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'videogallery') {
                $url = 'video' . $msg_node->nid . '.xml';
                generateVideoDetailPageFeed($msg_node->nid);
            } elseif ($msg_node->type == 'photogallery') {
                $url = 'photo' . $msg_node->nid . '.xml';
                generatePhotoDetailPageFeed($msg_node->nid);
            }
            $created_date = $data->schedule_datetime;
            $created_date_time = $data->schedule_datetime;
            if ($data->content_id > 0) {
                $output .= "<article><title><![CDATA[" . $title . "]]></title><header><![CDATA[" . $android_header . "]]></header><section_name><![CDATA[" . $section . "]]></section_name><thumbimage>" . $thumb_image . "</thumbimage><kickerimage>" . $thumb_image . "</kickerimage><url>" . $url . "</url><weburl><![CDATA[" . $weburl . "]]></weburl><create_date>" . $created_date . "</create_date><create_datetime>" . $created_date_time . "</create_datetime></article>";
            } else {
                $msg_created_date = $data->schedule_datetime;
                $msg_created_date_time = $data->schedule_datetime;
                $header = $data->android_header;
                $section = $data->category;
                $thumb_img = $data->android_banner;
                $web_url = $data->mobile_url;
                if ($data->message_url != '') {
                    $live_url = strpos($data->message_url, 'livetv.jsp');
                    if ($live_url !== FALSE) {
                        $url = '/hltapps/api/livetv.xml';
                        $section = $data->category;
                    } else {
                        $url = '';
                        $section = '';
                    }
                }
                $output .= "<article><title><![CDATA[" . $data->message . "]]></title><header>" . $header . "</header><section_name>" . $section . "</section_name><thumbimage>" . $thumb_img . "</thumbimage><kickerimage>" . $thumb_img . "</kickerimage><url>" . $url . "</url><weburl>" . $web_url . "</weburl><create_date>" . $msg_created_date . "</create_date><create_datetime>" . $msg_created_date_time . "</create_datetime></article>";
            }
            //Attach the node type details
        }
    }
    return $output;
}

/**
 * Function for getting message_data
 *
 * @return string $res
 */
function message_data() {
    $config = get_notification_config();
    $params = drupal_get_query_parameters();
    $message_data_url = NOTIFICATION_FEED_PATH . $params['app_id'] . '&devices=' . $params['device'] . '';
    $all_data = file_get_contents($message_data_url);
    $message_data = json_decode($all_data);
    return $message_data;
}
