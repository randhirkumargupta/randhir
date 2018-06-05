<?php
/**
 * Implement itg_newsletter_content_preview_data_before_download
 * {@inheritdoc}
 */
function itg_newsletter_content_preview_data_before_download() {
  echo itg_newsletter_content_preview_data(FALSE);
}

/**
 * Implement itg_newsletter_content_preview_data
 * {@inheritdoc}
 */
function itg_newsletter_content_preview_data($download_action = TRUE) {
  global $base_url;
  if ($download_action) {
    $timestamp = time();
    $filename = "newsletter-preview-$timestamp.html";
    header('Content-disposition: attachment; filename=' . $filename);
    header('Content-type: text/html');
  }
  // Node Load for Get Template for Newsletter
  $tmplateLoad = node_load(arg(1));
  
  // Node Load for Get Newsletter Contents
  $newslettercontents = node_load($_GET['nid']);
  $type = $newslettercontents->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value'];
  if ($type == 'manual') {
    $prev_contents = $newslettercontents->field_newsl_add_news[LANGUAGE_NONE];
    foreach ($prev_contents as $prev_key => $prev_values) {
      $load_fc = field_collection_item_load($prev_values['value']);
      $story_nodes[] = $load_fc->field_news_cid[LANGUAGE_NONE][0]['target_id'];
    }
  }
  if (!empty(arg(4))) {
    $nid = arg(4);
    $previoustimestamp = itg_newsletter_get_previous_time($nid);
  }
  if (arg(2) == 'select_section') {
    $content_limit = variable_get('newsletter_content_limit');
    if (isset($content_limit) && is_numeric($content_limit)) {
      $renge = $content_limit;
    } else {
      $renge = 20;
    }
    $selectedCid = arg(3);
    $getTids = explode("," , $selectedCid);
    if (is_array($getTids) && !empty($getTids)) {
      foreach ($getTids as $key => $values) {
        $cat_array[] = $values;
      }
      $query = db_select('node' , 'n');
      $query->leftjoin('field_data_field_story_category' , 'fsc' , 'n.nid = fsc.entity_id');
      $query->condition('n.status' , 1 , '=');
      $query->fields('n');
      $query->condition('n.type' , 'story' , '=');
      $query->condition('fsc.field_story_category_tid' , $cat_array , 'IN');
      $query->orderBy('n.nid' , 'DESC');
      $query->groupBy('n.nid');
      $query->range(0 , $renge);
      $result = $query->execute();
      while ($records = $result->fetchAssoc()) {
        $story_nodes[] = $records['nid'];
      }
    }
  }
  elseif (arg(2) == 'top_20_most_viewed') {
    if (function_exists('_get_most_popular_nodes_based_on_top_20_most_viewed')) {
      $story_nodes = _get_most_popular_nodes_based_on_top_20_most_viewed($previoustimestamp);
    }
  }
  elseif (arg(2) == 'top_20_shared') {
    if (function_exists('_get_most_popular_nodes_based_on_top_20_shared')) {
      $story_nodes = _get_most_popular_nodes_based_on_top_20_shared($previoustimestamp);
    }
  }
  elseif (arg(2) == 'top_20_trending') {
    if (function_exists('_get_most_popular_nodes_based_on_top_20_trending')) {
      $story_nodes = _get_most_popular_nodes_based_on_top_20_trending($previoustimestamp);
    }
  }
  else {
    $story_nodes = explode(',', arg(2));
  }
  $banner = file_create_url($tmplateLoad->field_newst_banner[LANGUAGE_NONE][0]['uri']);
  $footerData = $tmplateLoad->body[LANGUAGE_NONE][0]['value'];
  $footer = preg_replace("/[0-9]{4}/" , date('Y') , $footerData);
  $content = '<!DOCTYPE html> 
  <html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Newsletter</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>a{text-decoration: none; color: #323232; line-height: 24px;}</style>
  </head>
  <body><table cellspacing="0" align="center" width="650px" cellpadding="0" style="width:650px; margin: 0 auto; border: 5px solid #d9d9d9; font-family: Arial"><tr><td colspan="2" style="text-align: center;padding: 10px;"><img src="' . $banner . '" alt="" title="" /></td></tr>';
  $content .= '<tr>
        <td colspan="2" style="padding: 10px 20px;">
          <table cellspacing="0" cellpadding="0" style="width: 100%;">';
  $counter = 1;
  foreach ($story_nodes as $news_array) {
    $news_detail = node_load($news_array);
    if(!empty($news_detail)) {
    $title =  htmlspecialchars_decode(drupal_html_to_text($news_detail->title));
    $kicker = $news_detail->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
    if ($news_detail->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']) {
      $thumbnail = image_style_url("thumbnail" , $news_detail->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
      if(empty(file_get_contents($thumbnail))) {
        $thumbnail = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/newlatter_default_350X350.jpg';
      }
    }
    else {
      $thumbnail = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/newlatter_default_350X350.jpg';
    }
     $url = explode('/', FRONT_URL);
     if(count($url) == 4) {
        $front_url = FRONT_URL;
      }
      else {
        $front_url = FRONT_URL . '/';
      }

      $link = $front_url . drupal_get_path_alias('node/' . $news_detail->nid);
      if ($counter == 3) {
        $content .= newsletter_app_link();
      }
      $counter++;	
      $content .= '<tr class="node-'.$news_detail->nid.'">
               <td style="padding: 20px 10px 20px 20px; vertical-align: top; border-bottom: 2px solid #d9d9d9;"><img style="width:100px; height: 62px" src="' . $thumbnail . '" alt="" title="" /></td>
               <td style="padding: 20px 20px 20px 10px; border-bottom: 2px solid #d9d9d9;">
                <h2 style="margin: 0; color: #337ab7; font-size: 18px; padding-bottom: 10px;">' . l($title , $link , array('attributes' => array('target' => '_blank'))) . '</h2>
                <p style="margin: 0; font-size: 14px;">' . t($kicker) . '.</p>
              </td></tr>';
    }
  }
  $content .= '</table>
      </td>
    </tr>';
  $content .= '<tr>
      <td colspan="2">
         <table border="0" cellpadding="0" cellspacing="0" width="98%" id="container" align="center">
    <tr>
      <td align=left valign=top><table style="display: block; width: 225px;" align=left border=0 cellpadding="0" cellspacing="0" class="reco">
          <tr>
          <td valign=top class="body"><a href="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.click?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=1"> <img width="200px" class="original" src="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.get?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=1"/> </a></td>
        </tr>
        </table>
        <table style="display: block; width: 226px;" align=left border=0 cellpadding="0" cellspacing="0" class="reco">
          <tr>
            <td valign=top class="body"><a href="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.click?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=2"> <img width="200px" class="original" src="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.get?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=2"/> </a></td>
          </tr>
        </table>
        <table style="display: block; width: 200px;" align=left border=0 cellpadding="0" cellspacing="0" class="reco">
          <tr>
            <td valign=top class="body"><a href="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.click?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=3"> <img width="200px" class="original" src="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.get?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=3"/> </a></td>
          </tr>
        </table>
        <table style="display: block; width: 225px;" align=left border=0 cellpadding="0" cellspacing="0" class="reco">
          <tr>
            <td valign=top class="body"><a href="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.click?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=4"> <img width="200px" class="original" src="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.get?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=4"/> </a></td>
          </tr>
        </table>
        <table style="display: block; width: 226px;" align=left border=0 cellpadding="0" cellspacing="0" class="reco">
          <tr>
            <td valign=top class="body"><a href="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.click?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=5"> <img width="200px" class="original" src="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.get?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=5"/> </a></td>
          </tr>
        </table>
        <table style="display: block; width: 200px;" align=left border=0 cellpadding="0" cellspacing="0" class="reco">
          <tr>
            <td valign=top class="body"><a href="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.click?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=6"> <img width="200px" class="original" src="http://mb.taboola.com/1.1/png/indiatoday-newsletter/recommendations.get?recipient.hash.hex=f065723f94e16d3eaea142618f9060fa31ea0a19355bc40545ec5c0ae6ef0f7b&instance.id=25892e17-80f6-415f-9c65-7395632f0&widget.placement=bottom_of_ema
il&widget.mode=thumbnails-a&source.url=http%3A%2F%2Fmailtoday.in&widget.slot=6"/> </a></td>
          </tr>
        </table></td>
    </tr>
  </table>

      </td>
    </tr>';

  $content .= '<tr>
      <td colspan="2">
        <table cellspacing="0" cellpadding="0" style="width: 100%; text-align: center; font-size: 14px;">' . $footer . '</table>
      </td>
    </tr>';
  $content .= '</table><p>&nbsp;</p><p>Thanks,</p><p>India Today Group</p>';
  if (!$download_action) {
    $node = node_load($_GET['nid']);
    $selectedTemplatenid = $node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'];
    if($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value'] == 'automatic'){
      $newletterContents = $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'];
      $current_nid = $node->nid;
        if ($newletterContents == 'top_20_trending') {
          if (function_exists('_get_most_popular_nodes_based_on_top_20_trending')) {
            $story_nodes = _get_most_popular_nodes_based_on_top_20_trending($previoustimestamp);
            foreach ($story_nodes as $new_array) {
              $news_detail = node_load($new_array);
              $manual_nids[] = $news_detail->nid;
            }
          }
          $manualnids = implode(',' , $manual_nids);
          $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $manualnids . '/' . $current_nid, array('attributes' => array('class' => 'download-html') , 'html' => true));
        } 
        elseif ($newletterContents == 'top_20_shared') {
          if (function_exists('_get_most_popular_nodes_based_on_top_20_shared')) {
            $story_nodes = _get_most_popular_nodes_based_on_top_20_shared($previoustimestamp);
            foreach ($story_nodes as $new_array) {
              $news_detail = node_load($new_array);
              $manual_nids[] = $news_detail->nid;
            }
          }
          $manualnids = implode(',' , $manual_nids);
          $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $manualnids . '/' . $current_nid, array('attributes' => array('class' => 'download-html') , 'html' => true));
        } 
        elseif ($newletterContents == 'top_20_most_viewed') {
          if (function_exists('_get_most_popular_nodes_based_on_top_20_most_viewed')) {
            $story_nodes = _get_most_popular_nodes_based_on_top_20_most_viewed($previoustimestamp);
            foreach ($story_nodes as $new_array) {
              $news_detail = node_load($new_array);
              $manual_nids[] = $news_detail->nid;
            }
          }
          $manualnids = implode(',' , $manual_nids);
          $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $manualnids . '/' . $current_nid, array('attributes' => array('class' => 'download-html') , 'html' => true));
        }
        elseif ($newletterContents == 'select_section') {
          foreach ($node->field_story_category[LANGUAGE_NONE] as $key => $values) {
            $cat_array[] = $values['tid'];
          }
          // $cat_array = array(1206686, 1206620); // for testing purpose
          $tid_val = implode(',' , $cat_array);
          $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $tid_val . '/' . $current_nid, array('attributes' => array('class' => 'download-html') , 'html' => true));
        }
      } 
    else {
      foreach($node->field_newsl_add_news[LANGUAGE_NONE] as $k => $v){
        $load_fc = field_collection_item_load($v['value']);
        $manual_nids[] = $load_fc->field_news_cid[LANGUAGE_NONE][0]['target_id'];
      }
      $manualnids = implode(',' , $manual_nids);
      $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $manualnids, array('attributes' => array('class' => 'download-html') , 'html' => true));
    }
    $content .=  '<p>' .$output . '</p>';
  }
  $content .= '</body></html>';
  print $content;
  exit;
}
