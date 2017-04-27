<?php

function itg_newsletter_content_preview_data_before_download() {
  echo itg_newsletter_content_preview_data(FALSE);
}

function itg_newsletter_content_preview_data($download_action = TRUE) {
  global $base_url;
  if ($download_action) {
    $timestamp = time();
    $filename = "newsletter-preview-$timestamp.html";
    header('Content-disposition: attachment; filename=' . $filename);
    header('Content-type: text/html');
  }
  $tmplateLoad = node_load(arg(1));
  if (arg(2) == 'select_section') {
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
      $query->range(0 , 20);
      $result = $query->execute();
      while ($records = $result->fetchAssoc()) {
        $story_nodes[] = $records['nid'];
      }
    }
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
  </head>
  <body><table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; border: 5px solid #d9d9d9; font-family: Arial"><tr><td colspan="2"><img src="' . $banner . '" alt="" /></td></tr>';
  $content .= '<tr>
        <td colspan="2" style="padding: 10px 20px;">
          <table cellspacing="0" cellpadding="0" style="width: 100%;">';
  foreach ($story_nodes as $news_array) {
    $news_detail = node_load($news_array);
    $title = $news_detail->field_story_long_head_line[LANGUAGE_NONE][0]['value'];
    $kicker = $news_detail->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
    if ($news_detail->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']) {
      $thumbnail = image_style_url("thumbnail" , $news_detail->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    }
    else {
      $thumbnail = $base_url . '/' . drupal_get_path('module' , 'itg_newsletter') . '/image/no-image.png';
    }
    $link = 'node/' . $news_detail->nid;
    $content .= '<tr>
               <td style="padding: 20px 10px 20px 20px; vertical-align: top; border-bottom: 2px solid #d9d9d9;"><img style="width:100px; height: 100px" src="' . $thumbnail . '" alt="" /></td>
               <td style="padding: 20px 20px 20px 10px; border-bottom: 2px solid #d9d9d9;">
                <h2 style="margin: 0; color: #337ab7; font-size: 18px; padding-bottom: 10px;">' . l($title , $link , array('attributes' => array('target' => '_blank'))) . '</h2>
                <p style="margin: 0; font-size: 14px;">' . t($kicker) . '.</p>
              </td></tr>';
  }
  $content .= '</table>
      </td>
    </tr><tr>
      <td colspan="2">
        <table cellspacing="0" cellpadding="0" style="width: 100%; text-align: center; font-size: 14px;">' . $footer . '</table>
      </td>
    </tr>';

  $content .= '</table><p>&nbsp;</p><p>Thanks,</p><p>India Today Group</p>';
  if (!$download_action) {
    $node = node_load($_GET['nid']);
    $selectedTemplatenid = $node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'];
    $newletterContents = $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'];
    foreach ($node->field_story_category[LANGUAGE_NONE] as $key => $values) {
      $cat_array[] = $values['tid'];
    }
    $tid_val = implode(',' , $cat_array);
    $output .= l(t('Download HTML') , 'newsletter_data_preview/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $tid_val , array('attributes' => array('class' => 'download-html') , 'html' => true));
    $content .=  '<p>' .$output . '</p>';
  }
  $content .= '</body></html>';
  print $content;
  exit;
}
