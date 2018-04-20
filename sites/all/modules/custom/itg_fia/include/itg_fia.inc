<?php

/**
 * Implementing itg_fia_data().
 */
function itg_fia_data() {  
  $start_time = strtotime("-7 day");
  $end_time = strtotime("now");    
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_social_media_integ', 'fsmi', 'n.nid = fsmi.entity_id');
  $query->fields('n', array('nid', 'created'));
  $query->condition('n.created', array($start_time, $end_time), 'BETWEEN'); 
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->condition('fsmi.field_story_social_media_integ_value', 'facebook_instant_article', '=');
  $query->orderBy('n.created', 'DESC');
  $query->range(0, 100);
  $query = $query->execute()->fetchCol();
  $xml = itg_fia_xml_node_feed($query);
  $xml_path = 'public://fbinsight/';
  $file_name = 'indiatoday-latestnews.xml';
  $file_path = $xml_path . $file_name;
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Generates and prints a custom XML feed.
 */
function itg_fia_xml_node_feed($query) {
  global $base_url;
  $xml_base = FRONT_URL . '/' . current_path();
  $fia_ga_data = variable_get('ga_code');
  $fia_ga = isset($fia_ga_data) ? $fia_ga_data : " ";
  $nodes = node_load_multiple($query);
  $items = '';
  $last_build = FALSE;
  $last_build_date = '';  
  foreach ($nodes as $node) {
    $body_vals = array();
    $img_path = '';
    $get_place_name = '';
    $imgs_path = '';
    if (!is_lock_story()) {
      if ($node->workbench_moderation['current']->state == 'published') {
        $op_pub = date('F j, h:i a', $node->workbench_moderation['current']->timestamp);
        $pubdate = date('Y-m-d\TH:i:s\+05:30', $node->workbench_moderation['current']->timestamp);
      }
      else {
        $op_pub = date('F j, h:i a', $node->created);
        $pubdate = date('Y-m-d\TH:i:s\+05:30', $node->created);
      }
      if (!$last_build) {
        $last_build_date = $pubdate;
        $last_build = TRUE;
      }
      $guid = $node->nid;
      $op_modified = date('F j, h:i a', $node->changed);
      $modified = date('Y-m-d\TH:i:s\+05:30', $node->changed);
      $auth_name = get_author_name($node->nid);
      $desc = $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
      $embed_code_pos = $node->field_social_embed_code_position[LANGUAGE_NONE][0]['value'];
      $embed_code_data = $node->field_social_embed_code[LANGUAGE_NONE][0]['value'];
      $audio_pos = $node->field_facebook_audio_position[LANGUAGE_NONE][0]['value'];
      $audio_url = $node->field_facebook_instant_audio_url[LANGUAGE_NONE][0]['value'];
      $img_position = $node->field_animated_image_position[LANGUAGE_NONE][0]['value'];
      if (!empty($node->field_facebook_animated_image[LANGUAGE_NONE][0]['uri'])) {
        $img_path = file_create_url($node->field_facebook_animated_image[LANGUAGE_NONE][0]['uri']);
      }

      if (!empty($node->field_story_big_image[LANGUAGE_NONE][0]['uri'])) {
        $fb_instant_image = file_create_url($node->field_story_big_image[LANGUAGE_NONE][0]['uri']);
      }
      else if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
        $fb_instant_image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
      }
      else {
        $fb_instant_image = '';
      }

      $map_pos = $node->field_facebook_map_position[LANGUAGE_NONE][0]['value'];
      if (isset($node->field_map_embed_code[LANGUAGE_NONE][0]['value']) && !empty($node->field_map_embed_code[LANGUAGE_NONE][0]['value'])) {
        $map_data = $node->field_map_embed_code[LANGUAGE_NONE][0]['value'];
        // getting map data from map <iframe>
        if (strpos($map_data, '<iframe') !== false) {
          $map_data_iframe = $map_data;
          $get_map_iframe = explode(" ", $map_data_iframe);
          $get_map_data = explode("!", $get_map_iframe[1]);
          $get_map_lat = explode("2d", $get_map_data[5]);
          $get_map_lng = explode("3d", $get_map_data[6]);
          $lat = number_format($get_map_lat[1], 6);
          $lng = number_format($get_map_lng[1], 6);
          $get_iframe_place = $get_map_data[18];
          $get_iframe_places = explode('2s', $get_map_data[18]);
          $get_place_name = str_replace("+", " ", $get_iframe_places[1]);
        }
        else {
          // getting map data from map url
          $get_map = explode("place", $map_data);
          $get_map_coordinate = explode("@", $get_map[1]);
          $get_place = str_replace("/", "", $get_map_coordinate[0]);
          $get_place_name = str_replace("+", " ", $get_place);
          $coordinate_map = explode(",", $get_map_coordinate[1]);
          $lat = $coordinate_map[0];
          $lng = $coordinate_map[1];
        }
      }

      // getting gallery data
      $target_nids = NULL;
      $gall_position = NULL;
      if (is_array($node->field_facebook_gallery_associate[LANGUAGE_NONE]) && !empty($node->field_facebook_gallery_associate[LANGUAGE_NONE])) {
        $associate_gallery = $node->field_facebook_gallery_associate[LANGUAGE_NONE];
        foreach ($associate_gallery as $fc_k => $fc_v) {
          $fc_ids = $fc_v['value'];
          $load_fc = field_collection_item_load($fc_ids);
          $gall_position = $load_fc->field_gallery_position[LANGUAGE_NONE][0]['value'];
          $target_nids[$gall_position][] = $load_fc->field_associate_gallery_id[LANGUAGE_NONE];
          $query = db_select('field_data_field_gallery_image', 'n');
          $query->leftJoin('field_data_field_api_image', 'fdfi', 'n.field_gallery_image_value = fdfi.entity_id');
          $query->fields('fdfi', array('field_api_image_fid'));
          $query->condition('n.entity_id', $load_fc->field_associate_gallery_id[LANGUAGE_NONE]);
          $result = $query->execute();
          $get_fc = $result->fetchAll();
          $get_script = '';
          foreach ($get_fc as $get_fck => $get_fcv) {
            if (!empty($get_fcv->field_api_image_fid)) {
              $file = file_load($get_fcv->field_api_image_fid);
              $imgs_path = file_create_url($file->uri);
              $get_script .= '<figure><img src="' . $imgs_path . '" alt="" title="" /></figure>';
            }
          }
          if (isset($get_script) && !empty($get_script)) {
            $full_script_slider[$gall_position][] = '<figure class="op-slideshow">' . $get_script . '</figure>';
          }
        }
      }

      // facebook instant article body placement
      $node_body = $node->body[LANGUAGE_NONE][0]['value'];
      //$node_body = str_replace("'", '&#39;', $node_body);
      $numLine = explode("<p>", $node_body);

      unset($numLine[0]);
      foreach ($numLine as $body_key => $body_val) {
        $bk[$body_key] = $body_key;
        $body_vals[$body_key] = $numLine[$body_key];
      }

      // facebook instant article audio placement
      if (!empty($audio_url)) {
        if (in_array($audio_pos, $bk)) {
          $body_vals[$audio_pos] = $body_vals[$audio_pos] .
              '<figure><img src="' . $img_path . '" alt="" title=""><audio title="audio title" autoplay="autoplay" muted="muted"><source src="' . $audio_url . '"></audio></figure>';
        }
        else {
          $last_postion = end($bk);
          $body_vals[$last_postion] = $body_vals[$last_postion] .
              '<figure><img src="' . $img_path . '" alt="" title=""><audio title="audio title" autoplay="autoplay" muted="muted"><source src="' . $audio_url . '"></audio></figure>';
        }
      }

      // facebook instant article animated image placement
      if (isset($img_path) && !empty($img_path)) {
        if (in_array($img_position, $bk)) {
          $body_vals[$img_position] = $body_vals[$img_position] .
              '<figure><img src="' . $img_path . '" alt="" title="" /></figure>';
        }
        else {
          $last_postion = end($bk);
          $body_vals[$last_postion] = $body_vals[$last_postion] .
              '<figure><img src="' . $img_path . '" alt="" title="" /></figure>';
        }
      }

      // facebook instant article map placement
      if (isset($get_place_name) && !empty($get_place_name)) {
        if (in_array($map_pos, $bk)) {
          $body_vals[$map_pos] = $body_vals[$map_pos] .
              '<figure class="op-map"><script type="application/json" class="op-geotag">{"type": "Feature", "geometry":{"type": "Point", "coordinates": [' . $lat . ', ' . $lng . ']},"properties":{"title": "' . $get_place_name . '", "radius": 10000, "pivot": true, "style": "satellite",}}</script></figure>';
        }
        else {
          $last_postion = end($bk);
          $body_vals[$last_postion] = $body_vals[$last_postion] .
              '<figure class="op-map"><script type="application/json" class="op-geotag">{"type": "Feature", "geometry":{"type": "Point", "coordinates": [' . $lat . ', ' . $lng . ']},"properties":{ "title": "' . $get_place_name . '", "radius": 10000, "pivot": true, "style": "satellite",}}</script></figure>';
        }
      }

      // Creating Slideshow for facebook instant article data
      if (isset($imgs_path) && !empty($imgs_path)) {
        $slider_keys = array_keys($full_script_slider);
        foreach ($slider_keys as $k => $sliderkey) {
          $body_vals[$sliderkey] = $body_vals[$sliderkey] . $full_script_slider[$sliderkey][0];
        }
      }

      // Creating Social Embed Code for facebook instant article data
      if (!empty($embed_code_data)) {
        if (in_array($embed_code_pos, $bk)) {
          $eic = substr_count($embed_code_data, '<iframe');
          if ($eic > 1) {
            $newiframe = str_replace(" />", "></iframe>", $embed_code_data);
            $fie = explode("<iframe", $newiframe);
            unset($fie[0]);
            foreach ($fie as $fie_key => $fie_val) {
              $body_vals[$embed_code_pos] = $body_vals[$embed_code_pos] . '<figure class="op-interactive"><iframe ' . $fie_val . '</figure>';
            }
          }
          else {
            $body_vals[$embed_code_pos] = $body_vals[$embed_code_pos] . '<figure class="op-interactive">' . $embed_code_data . '</figure>';
          }
        }
        else {
          $last_postion = end($bk);
          $eic = substr_count($embed_code_data, '<iframe');
          if ($eic > 1) {
            $newiframe = str_replace(" />", "></iframe>", $embed_code_data);
            $fie = explode("<iframe", $newiframe);
            unset($fie[0]);
            foreach ($fie as $fie_key => $fie_val) {
              $body_vals[$last_postion] = $body_vals[$last_postion] . '<figure class="op-interactive"><iframe ' . $fie_val . '</figure>';
            }
          }
          else {
            $body_vals[$last_postion] = $body_vals[$last_postion] . '<figure class="op-interactive">' . $embed_code_data . '</figure>';
          }
        }
      }
      $node_body = implode("<p>", $body_vals);
      $node_body = str_replace(['<iframe', '</iframe>'], ['<figure class="op-interactive"><iframe', '</iframe></figure>'], $node_body);
      preg_match_all('#<div class="itg-mosimage"[^>]*>(.*?)</div>#', $node_body, $matches);
      if (!empty($matches[1])) {
        foreach ($matches[1] as $val) {
          $arr = explode('/>', $val);
          if (!empty($arr[1])) {
            $node_body = str_replace($arr[1], '<figcaption>' . $arr[1] . '</figcaption></figure>', $node_body);
          }
        }
      }
      $node_body = preg_replace("/<\/?div[^>]*\>/i", "$1", $node_body);
      $node_body = preg_replace('/(<img\b\s+.*?data-mosimage=\")/', '<figure>$1', $node_body);
      $node_body = preg_replace("/(<img data-mosimage='([^\"]*)')/", '<figure>$1', $node_body);
      if ($node->field_story_source_type['und'][0]['value'] != 'migrated') {
        $node_body = preg_replace('/(<img([^>]*)>)/i', '<figure>$1</figure>', $node_body );
      }
      $node_body = str_replace('<p><figure', '<figure', $node_body);
      $node_body = str_replace('</figure></p>', '</figure>', $node_body);
      $node_body = str_replace('</figcaption></p>', '</figcaption>', $node_body);
      $node_body = preg_replace("#<p>(\s|&nbsp;|</?\s?br\s?/?>)*</?p>#", "", $node_body);
      $node_body = str_replace('<p>&nbsp;</p>', '', $node_body);
      $node_body = str_replace('</p></p>', '</p>', $node_body);
      $node_body = str_replace('<p></p>', '', $node_body);
      $node_body = str_replace('<p> </p>', '', $node_body);
      $node_body = str_replace(array('<li></li>', '<li> </li>', '<li>   </li>'), '', $node_body);
      $node_body = str_replace('</ul></ul>', '</ul>', $node_body);
      $node_body = str_replace('</figure></iframe>', '</iframe></figure>', $node_body);
      $node_body = str_replace('</iframe></figure></p>', '</iframe></figure>', $node_body);
      $node_body = str_replace('<figcaption></figcaption>', '', $node_body);
      $node_body = str_replace('<blockquote class="twitter-tweet" lang="en"><blockquote class="twitter-tweet" lang="en">', '<blockquote class="twitter-tweet" lang="en">', $node_body);
      $node_body = str_replace('</blockquote></blockquote>', '</blockquote>', $node_body);
      $node_body = str_replace('</blockquote><script async="" src="//platform.twitter.com/widgets.js" mce_src="//platform.twitter.com/widgets.js" charset="utf-8"></script>', '</blockquote><script charset="utf-8" src="//platform.twitter.com/widgets.js"></script>', $node_body);
      //$node_body = str_replace('<blockquote', '<figure class="op-interactive"><iframe><blockquote ', $node_body);
      $node_body = preg_replace('/(<blockquote class="([^\"]*)")/', '<figure class="op-interactive"><iframe>$1', $node_body);
      $node_body = preg_replace("/(<blockquote class='([^\"]*)')/", "<figure class='op-interactive'><iframe>$1", $node_body);
      $node_body = str_replace('<script async="" src="//platform.twitter.com/widgets.js" mce_src="//platform.twitter.com/widgets.js" charset="utf-8"></script>', '<script charset=utf-8 src=//platform.twitter.com/widgets.js></script></iframe></figure>', $node_body);
      $node_body = str_replace('<script charset=utf-8 src=//platform.twitter.com/widgets.js type=mce-no/type></script>', '<script charset=utf-8 src=//platform.twitter.com/widgets.js type=mce-no/type></script></iframe></figure>', $node_body);
      $node_body = str_replace('<script async="" src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>', '<script async="" src="https://platform.twitter.com/widgets.js" charset="utf-8"></script></iframe></figure>', $node_body);
      $node_body = str_replace('<script async="" src="https://platform.twitter.com/widgets.js" mce_src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>', '<script async="" src="https://platform.twitter.com/widgets.js" charset="utf-8"> </script></iframe></figure>', $node_body);
      $node_body = str_replace('<script async="" src="https://platform.twitter.com/widgets.js" mce_src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>', '<script async="" src="https://platform.twitter.com/widgets.js" charset="utf-8"></script></iframe></figure>', $node_body);
      $node_body = str_replace('<script async="" src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>', '<script async="" src="https://platform.twitter.com/widgets.js" charset="utf-8"> </script></iframe></figure>', $node_body);
      $node_body = str_replace('<script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>', '<script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script></iframe></figure>', $node_body);
      //$ad_code = "<figure class='op-ad'><iframe width='300' height='250' style='border:0; margin:0;' src='https://www.facebook.com/adnw_request?placement=1634971070080984_1635110376733720&adtype=banner300x250'></iframe></figure>";
      $node_body = preg_replace("/ITG:SURVEY:([0-9]+)/", "", $node_body);
      $node_body = preg_replace("/ITG:QUIZ:([0-9]+)/", "", $node_body);
      $node_body = preg_replace("/ITG:POLL:([0-9]+)/", "", $node_body);
      $node_body = str_replace("[ITG:FACTOIDS]", "", $node_body);
      $node_body = str_replace("[ITG:EXPERT-CHUNK]", "", $node_body);
      $node_body = str_replace("[ITG:TECH-PHOTOS]", "", $node_body);
      $node_body = str_replace("[ITG:TECH-PHOTO-GALLERY]", "", $node_body);
      //$node_body = str_replace("[ITG:LISTICLES]", "", $node_body);
      //Code for the listicle token
      if (strpos($node_body, '[ITG:LISTICLES]')) {
        $listicle_output = '';
        if (!empty($node->field_story_listicle[LANGUAGE_NONE]) && !empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
          if (isset($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
            $listicle_output .= '<span>' . $node->field_story_template_guru[LANGUAGE_NONE][0]['value'] . '</span>';
          }
          $buzz_output.= '';
          $num = 1;
          $listicle_output.= '<ul>';
          foreach ($node->field_story_listicle['und'] as $buzz_item) {
            $listicletype = '';
            $field_collection_id = $buzz_item['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $type = $entity[$field_collection_id]->field_story_listicle_type['und'][0]['value'];
            $description = $entity[$field_collection_id]->field_story_listicle_description['und'][0]['value'];
            $listicle_output.= '<li>' . $listicletype . $description . '</li>';
            $num++;
          }
          $listicle_output.= '</ul>';
          $node_body = str_replace('[ITG:LISTICLES]', $listicle_output, $node_body);
        }
      }
      $node_body = str_replace("100%", "300", $node_body);
      $node_body = preg_replace('/&(?!#?[a-z0-9]+;)/', '&amp;', $node_body);
      //$node_body = itg_fia_split_by_words($node_body, $node->nid, $ad_code);
      //$node_body .= $ad_string;
      $node_body = trim(preg_replace('/\s+/', ' ', $node_body));
      $node_body = trim($node_body);
      $node_body_content = '<p>' . $node_body;
      $node->link = url("node/$node->nid", ['absolute' => TRUE]);
      $kicker = $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
      $node_body_content = str_replace('<br />', '', $node_body_content);
      $desc = str_replace('<br />', '', $desc);
      $desc = str_replace("'", "&#39;", $desc);
      $node_title = str_replace("'", "&#39;", $node->title);
      $items .= itg_fia_xml_format_rss_item('story-' . $node->nid, $kicker, $target_nids, $fb_instant_image, $guid, $node_body_content, $node_title, $node->link, $pubdate, $auth_name, $desc, $op_pub, $modified, $op_modified, $node->nid);
    }
  }
  global $base_url;
  $channel_defaults = array(
      'title' => variable_get('site_name', 'Drupal'),
      'link' => FRONT_URL . '/' . current_path(),
  );

  /*$output = "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\" ?>";
  $output .= "<rss version='2.0' xml:base='" . $xml_base . "' xmlns:dc='http://purl.org/dc/elements/1.1/' xmlns:atom='http://www.w3.org/2005/Atom'>";
  $output .= itg_fia_xml_format_rss_channel($channel_defaults['title'], $channel_defaults['link'], $items);
  drupal_add_http_header('Content-Type:application/rss+xml; charset=utf-8');*/
  $output = "<rss xmlns:content=\"http://purl.org/rss/1.0/modules/content/\" version=\"2.0\">";
  $output .= itg_fia_xml_format_rss_channel($channel_defaults['title'], $channel_defaults['link'], $items, $last_build_date);  
  return $output;
}

/**
 * Creates the xml channel.
 */
function itg_fia_xml_format_rss_channel($title, $link, $items, $last_build_date) {

  $output = "<channel>";
  $output .= "<title>" . $title . "</title>";
  $output .= "<link>" . FRONT_URL . "</link>";
  $output .= "<description>" . t("India Today News - Check out the latest breaking News from India and around the world. The latest news headlines, world, politics, business, sport, entertainment and technology news from IndiaToday.in") . "</description>";
  $output .= "<language>en</language>";
  $output .= "<lastBuildDate>" . $last_build_date . "</lastBuildDate>";
  //$output .= "    <atom:link href='" . check_url($link) . "' rel='self' type='application/rss+xml' />";
  $output .= $items;
  $output .= "</channel>";
  $output .= "</rss>";

  return $output;
}

/**
 * Creates the xml item.
 */
function itg_fia_xml_format_rss_item($id, $kicker, $target_nids, $fb_instant_image, $guid, $node_body_content, $title, $link, $pubdate, $name, $desc, $op_pub, $modified, $op_modified, $nid) {
  $desc = preg_replace("#<p>(\s|&nbsp;|</?\s?br\s?/?>)*</?p>#", "", $desc);
  $desc = preg_replace('/&(?!#?[a-z0-9]+;)/', '&amp;', $desc);
  $title = preg_replace('/&(?!#?[a-z0-9]+;)/', '&amp;', $title);
  $ad_string = '<section class="op-ad-template">
    <figure class="op-ad">
       <iframe width="300" height="250" style="border:0; margin:0;" src="https://www.facebook.com/adnw_request?placement=1634971070080984_1635110376733720&adtype=banner300x250"></iframe>
    </figure>
      <figure class="op-ad">
       <iframe width="300" height="250" style="border:0; margin:0;" src="https://www.facebook.com/adnw_request?placement=1634971070080984_1635110396733718&adtype=banner300x250"></iframe>
    </figure>
          <figure class="op-ad">
       <iframe width="300" height="250" style="border:0; margin:0;" src="https://www.facebook.com/adnw_request?placement=1634971070080984_1767534293491327&adtype=banner300x250"></iframe>
    </figure>
<figure class="op-ad">
       <iframe width="300" height="250" style="border:0; margin:0;" src="https://www.facebook.com/adnw_request?placement=1634971070080984_2041485232762897&adtype=banner300x250"></iframe>
    </figure>
<figure class="op-ad op-ad-default">
       <iframe width="300" height="250" style="border:0; margin:0;" src="https://www.facebook.com/adnw_request?placement=1634971070080984_2041485232762897&adtype=banner300x250"></iframe>
    </figure>

</section>';
  $output = "<item>";
  $output .= "<title>" . $title . "</title>";
  $output .= "<link>" . check_url($link) . "?sr=fbia</link>";
  $output .= "<guid>" . $guid . "</guid>";
  $output .= "<pubDate><![CDATA[" . $pubdate . "]]></pubDate>";
  $output .= "<author>" . $name . "</author>";
  $output .= "<description>" . $desc . "</description>";
  $output .= "<content:encoded>";
  $output .= "<![CDATA[";
  $output .= "<!doctype html>";
  $output .= "<html lang='en' prefix='op: http://media.facebook.com/op#'>";
  $output .= "<head>";
  $output .= "<meta charset='utf-8'>";
  $output .= "<meta property ='fb:op-recirculation-ads' content=placement_id=".'1634971070080984_1853363621575060'.">";
  $output .= "<meta property='fb:use_automatic_ad_placement' content='enable=true ad_density=default'>";
  $output .= "<meta property='op:markup_version' content='v1.0'>";
  $output .= "<meta property='fb:use_automatic_ad_placement' content='true'>";
  $output .= "<meta property='og:title' content='" . $title . "'>";
  $output .= "<meta property='og:description' content='" . $desc . "'>";
  $output .= "<link rel='canonical' href='" . $link . "?sr=fbia'>";
  //$output .= "    <link rel='stylesheet' title='default' href='#'>";
  //$output .= "    <meta property='op:markup_version' content='v1.0'>";
  $output .= "</head>";
  $output .= "<body>";
  $output .= "<article>";
  $output .= '<figure class="op-tracker"><iframe hidden><!-- DO NOT MODIFY --><!-- Quora Pixel Code (JS Helper) --><script>!function(q,e,v,n,t,s){if(q.qp) return; n=q.qp=function(){n.qp?n.qp.apply(n,arguments):n.queue.push(arguments);}; n.queue=[];t=document.createElement(e);t.async=!0;t.src=v; s=document.getElementsByTagName(e)[0]; s.parentNode.insertBefore(t,s);';
  $output .= "}(window, 'script', 'https://a.quora.com/qevents.js');qp('init', 'a50e46d4d6b444a7ab8308928a6df8f0');qp('track', 'ViewContent');</script>";
  $output .= '<noscript><img height="1" width="1" style="display:none" src="https://q.quora.com/_/ad/a50e46d4d6b444a7ab8308928a6df8f0/pixel?tag=ViewContent&noscript=1"/></noscript><!-- End of Quora Pixel Code --></iframe></figure>';
  $output .= "<header>";
  //$output .= "<figure class='op-ad'> <iframe width='300' height='250' style='border:0; margin:0;' src='https://www.facebook.com/adnw_request?placement=1634971070080984_1635110376733720&adtype=banner300x250'></iframe></figure>";
  $output .= $ad_string;
  // <!-- The header image shown inside your article --> 
  if((isset($fb_instant_image)) && (!empty($fb_instant_image))){
    $output .= "<figure>";  
    $output .= "<img src='" . $fb_instant_image . "' alt='' title='' />";
    $output .= "</figure>";
  }
  $output .= "<h1>" . $title . "</h1>";
  $output .= "<h2>" . $kicker . "</h2>";
  // <!-- A kicker for your article -->
  $output .= "<details><summary>" . $kicker . "</summary></details>";
  // <!-- The author of your article -->
  $comscorecode = "<!-- Begin comScore Tag --><figure class='op-tracker'><iframe><script>var _comscore = _comscore || [ ];_comscore.push({ c1: '2', c2: '8549097', options: { url_append:'comscorekw=fbia' }});(function() {var s = document.createElement('script'), el = document.getElementsByTagName('script')[0];s.async = true; s.src = (document.location.protocol == 'https:' ? 'https://sb' : 'http://b') + '.scorecardresearch.com/beacon.js';el.parentNode.insertBefore(s, el); })();</script><noscript><img src='https://sb.scorecardresearch.com/p?c1=2&c2=8549097&cv=2.0&cj=1&comscorekw=fbia' /></noscript></iframe></figure><!-- End comScore Tag -->";
  $relatednode = itg_fia_related_node($nid);
  $output .= "<address>" . $name . "</address>";
  $output .= "<time class='op-published' dateTime='" . $pubdate . "'>" . $op_pub . "</time>";
  $output .= "<time class='op-modified' dateTime='" . $modified . "'>" . $op_modified . "</time>";
  $output .= "</header>";
  $output .= "<div property='content:encoded'>" . $node_body_content . "</div>"; 
  $output .= $relatednode;
  $output .= "<figure class='op-tracker'><iframe><script>(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){ (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o), m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m) })(window,document,'script','//www.google-analytics.com/analytics.js','ga'); ga('create', 'UA-795349-17', 'auto'); ga('set', 'referrer', 'http://instant.facebook.com/c_id=story-1122321'); ga('send', 'pageview');</script></iframe></figure> <figure class='op-tracker'><iframe>".$comscorecode."</iframe></figure><footer><aside>India Today Editorial</aside><small>Copyright &#169; 2018 Living Media India Limited</small></footer>";
  $output .= "</article>";
  $output .= "</body>";
  $output .= "</html>";
  $output .= "]]>";
  $output .= "</content:encoded>";
  $output .= "</item>";
  return $output;
}

/*
 * Return Author Name
 */

function get_author_name($auid) {
  $get_author_id = db_query("SELECT byline_id from {itg_multi_byline_info} mbi WHERE mbi.nid = :nid AND mbi.publish_status = :status", array(":nid" => $auid, ":status" => 1))->fetchField();
  $author_name = db_query("SELECT title from {node} n WHERE n.nid = :nid", array(":nid" => $get_author_id))->fetchField();
  return $author_name;
}

/*
 * ITG FIA Configuration form
 */
function itg_fia_config_form($form, &$form_state) {
  $form['itg_fia_config'] = array(
    '#type' => 'textfield',
    '#title' => t('Add the App Id'),
    '#description' => t('Add Your Facebook Application Id'),
    '#default_value' => variable_get('itg_fia_config'),
  );
  $form = system_settings_form($form);
  return $form;
}

/*
 * ITG FIA related node  $relatednode .="";
 */
function itg_fia_related_node($nid = 0) {
    $relatednode = "";   
    $relatednode .='<h1> More from Related stories </h1><ul class="op-related-articles">';
        //$nid = 1143479;
        $query = db_select('field_data_field_common_related_content', 'frc');
        $query->fields('frc', array('field_common_related_content_value'));
        $query->condition('frc.entity_id', $nid);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $node_str = $result[0]['field_common_related_content_value'];
        
        // replace enviroment name
        // stage related node structure: 'IT_1146622|~|IT_849473|~|IT_1146628|~|IT_1146629|~|IT_1146631|~|IT_1146630'
        $node_str = str_replace("|~|IT_", ",", $node_str);
        $node_str = str_replace("IT_", "", $node_str); 

        $nid_list = explode(",", $node_str);
        //p($nid_list);
        $flag_fia_cont = 0;
        if(count($nid_list) > 0){
            //related node
            foreach ($nid_list as $key => $value) {                
                $flag_fia = 0;
                $flag_fia = checkFIANodeBynid($value);
                if($flag_fia){
                    $firebase_url = get_node_firebase_weburl($value);
                    $relatednode .='<li><a href="'.$firebase_url.'"> </a></li>';
                    $flag_fia_cont++;
                }
            }
        }
        elseif($flag_fia_cont == 0){
            // related content of primary cat
            $prime_cat = getNodePrimeCatByNid($nid);
            $prime_section_ar = taxonomy_get_parents($prime_cat->tid);
            foreach ($prime_section_ar as $key => $value) {
                $prime_section = $value->tid;
            }
            
            
            $order = fia_get_order_node_by_nid($nid, $prime_section);
            $related_content_primary_cat = "";
            $related_content_primary_cat = fia_related_content_primary_cat($nid, $prime_section, $order);      
            $relatednode .= $related_content_primary_cat;
        }
      
    $relatednode .='</ul>';
    //no any node found
    if($flag_fia_cont == 0  && $related_content_primary_cat == "" ){
        $relatednode = "";
    }
    
    return $relatednode;
}

/*
 * ITG FIA function for get content of primary cat
 */

function fia_related_content_primary_cat($nid, $prime_section, $order = 0) {    
    $relatednode = "";
    if ($prime_section) {
        $query = db_select('node', 'n');
        $query->join('field_data_field_story_social_media_integ', 'fsmi', 'n.nid = fsmi.entity_id');
        //$query->join('field_data_field_primary_category', 'fpc', 'n.nid=fpc.entity_id');
        //$query->leftJoin('taxonomy_index', 'ti', 'n.nid=ti.nid');  
        $query->join('field_data_field_story_category', 'pc', 'pc.entity_id=n.nid');
        $query->join('itg_widget_order', 'iwo', 'n.nid=iwo.nid');
        $query->fields('n', array('nid'));
        $query->condition('fsmi.field_story_social_media_integ_value', 'facebook_instant_article', '=');
        $query->condition('n.type', 'story', '=');
        $query->condition('n.status', '1', '=');
        $query->condition('iwo.widget', $order, '<');
        $query->condition('iwo.widget', 'section_wise_widget');
        $query->condition('iwo.cat_id', $prime_section);
        //$query->condition('fpc.field_primary_category_value', $prime_cat, '=');
        $query->condition('pc.field_story_category_tid', '$prime_section', '');
        //$query->condition('ti.tid', $prime_section, '=');
        $query->range(0, 3);
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);        
        foreach ($result as $reskey => $resvalue) {            
            $firebase_url = get_node_firebase_weburl($resvalue['nid']);
            $relatednode .= '<li><a href="' . $firebase_url . '"> </a></li>';
        }
    }
    return $relatednode;
}

/*
 * ITG FIA function for get order of current node
 */
function fia_get_order_node_by_nid($nid, $prime_section){
    $order = 0;
    if($nid){
        $query = db_select('itg_widget_order', 'iwo');
        $query->fields('iwo', array('weight'));
        $query->condition('iwo.nid', $nid);
        $query->condition('iwo.cat_id', $prime_section);
        $query->condition('iwo.widget', 'section_wise_widget');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $order = $result[0]['weight'];
    }
    return $order;
}
/*
 * ITG FIA function for get node is FIA or not by nid
 */
function checkFIANodeBynid($nid){
    $nid_f = 0;
    
    if($nid){
        $query = db_select('node', 'n');
        $query->join('field_data_field_story_social_media_integ', 'fsmi', 'n.nid = fsmi.entity_id');
        $query->fields('n', array('nid'));
        $query->condition('n.type', 'story', '=');
        $query->condition('n.status', '1', '=');
        $query->condition('n.nid', $nid, '=');
        $query->condition('fsmi.field_story_social_media_integ_value', 'facebook_instant_article', '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
         
        $nid_f = $result[0]['nid'];
    }
    return $nid_f;
}
