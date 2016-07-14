<?php

/**
 * Send newsletter functionality
 * @file newsletter_mail.inc
 */

/**
 * @param object $node
 * @param string $news_eng_type
 * @param string $type
 * @return bool
 */
function itg_send_mail_newsletter($node, $news_eng_type, $type = NULL) {

  $template_node = node_load($node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id']);
  // TODO: Define globally
  $user_email_arr = array('haripalrao@gmail.com', 'neha.rani@kelltontech.com', 'vikash.kumar@kelltontech.com', 'ashish.singh@kelltontech.com', 'gourav.walia@kelltontech.com');
  $user_email_str = implode(',', $user_email_arr);

  // Get Mail content
  if ($type == 'stories') {
    $mail_content = itg_get_newsletter_mail_content_stories($template_node);
  }
  else {
    $mail_content = itg_get_newsletter_mail_content($node, $template_node);
  }

  $params = array(
    'body' => $mail_content,
    'subject' => 'India Today Newsletter | ' . $template_node->title,
  );

  $mail = drupal_mail('itg_newsletter', 'send_newsletter', $user_email_str, language_default(), $params, 'no-reply@kelltontech.com', TRUE);

  if ($mail['result']) {
    drupal_set_message(t('Newsletter has been sent successfully.'));
    if ($news_eng_type == 'automatically') {
      itg_update_newsletter_cron_tbl($node->nid);
    }
  }
  else {
    $error_msg = 'Failed to send the newsletter mail!';
    watchdog('newsletter-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}

/**
 * Generate newsletter whole body
 * @global string $base_url
 * @param object $node
 * @param object $template_node
 * @return string
 */
function itg_get_newsletter_mail_content($node, $template_node) {
  global $base_url;

  $banner = $base_url . str_replace('public://', '/sites/default/files/', $template_node->field_newst_banner[LANGUAGE_NONE][0]['uri']);
  $footer = $template_node->body[LANGUAGE_NONE][0]['value'];

  $content = '<!DOCTYPE html> 
  <html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Newsletter</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body><table cellspacing="0" cellpadding="0" style="width: 333px; margin: 0 auto; border: 5px solid #d9d9d9; font-family: Arial"><tr><td colspan="2"><img src="' . $banner . '" alt="" /></td></tr>';

  $content .= '<tr>
        <td colspan="2" style="padding: 10px 20px;">
          <table cellspacing="0" cellpadding="0" style="width: 100%;">';

  foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
    $news_detail = entity_load('field_collection_item', array($news_arr['value']));
    $title = $news_detail[$news_arr['value']]->field_news_title[LANGUAGE_NONE][0]['value'];
    $kicker = $news_detail[$news_arr['value']]->field_news_kicker[LANGUAGE_NONE][0]['value'];

    if ($news_detail[$news_arr['value']]->field_news_thumbnail[LANGUAGE_NONE][0]['uri']) {
      $thumbnail = image_style_url("thumbnail", $news_detail[$news_arr['value']]->field_news_thumbnail[LANGUAGE_NONE][0]['uri']);
    }
    else {
      $thumbnail = $base_url . '/' . drupal_get_path('module', 'itg_newsletter') . '/image/no-image.png';
    }

    // Set flag for empty records
    if (empty($title) && empty($kicker)) {
      $flag = FALSE;
    }
    else {
      $flag = TRUE;
    }

    // Set link for newsletter title
    if ($news_detail[$news_arr['value']]->field_news_type[LANGUAGE_NONE][0]['value'] == 'internal') {
      $link = $base_url . '/node/' . $news_detail[$news_arr['value']]->field_news_cid[LANGUAGE_NONE][0]['target_id'];
    }
    else {
      $link = $news_detail[$news_arr['value']]->field_news_external_url[LANGUAGE_NONE][0]['value'];
    }

    $news_content = '';
    if ($flag) {
      $news_content .= '<tr>
               <td style="padding: 20px 10px 20px 20px; vertical-align: top; border-bottom: 2px solid #d9d9d9;"><img style="width:100px; height: 100px" src="' . $thumbnail . '" alt="" /></td>
               <td style="padding: 20px 20px 20px 10px; border-bottom: 2px solid #d9d9d9;">
                <h2 style="margin: 0; color: #337ab7; font-size: 18px; padding-bottom: 10px;">' . l($title, $link, array('attributes' => array('target' => '_blank'))) . '</h2>
                <p style="margin: 0; font-size: 14px;">' . $kicker . '.</p>
              </td></tr>';
    }
  }

  $content .= $news_content . '</table>
      </td>
    </tr><tr>
      <td colspan="2">
        <table cellspacing="0" cellpadding="0" style="width: 100%; text-align: center; font-size: 14px;">' . $footer . '</table>
      </td>
    </tr>';

  $content .= '</table><p>&nbsp;</p><p>Thanks,</p><p>India Today Group</p></body></html>';

  return $content;
}

/**
 * Generate newsletter whole body for stories
 * @global string $base_url
 * @param object $template_node
 * @return string
 */
function itg_get_newsletter_mail_content_stories($template_node) {
  global $base_url;

  $banner = $base_url . str_replace('public://', '/sites/default/files/', $template_node->field_newst_banner[LANGUAGE_NONE][0]['uri']);
  $footer = $template_node->body[LANGUAGE_NONE][0]['value'];

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

  $story_nodes = itg_newsletter_get_top_stories();

  foreach ($story_nodes as $news_array) {
    $news_detail = node_load($news_array);

    $title = $news_detail->field_story_long_head_line[LANGUAGE_NONE][0]['value'];
    $kicker = $news_detail->field_story_kicker_text[LANGUAGE_NONE][0]['value'];

    if ($news_detail->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']) {
      $thumbnail = image_style_url("thumbnail", $news_detail->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    }
    else {
      $thumbnail = $base_url . '/' . drupal_get_path('module', 'itg_newsletter') . '/image/no-image.png';
    }

    $link = $base_url . '/node/' . $news_detail->nid;

    $news_content = '<tr>
               <td style="padding: 20px 10px 20px 20px; vertical-align: top; border-bottom: 2px solid #d9d9d9;"><img style="width:100px; height: 100px" src="' . $thumbnail . '" alt="" /></td>
               <td style="padding: 20px 20px 20px 10px; border-bottom: 2px solid #d9d9d9;">
                <h2 style="margin: 0; color: #337ab7; font-size: 18px; padding-bottom: 10px;">' . l($title, $link, array('attributes' => array('target' => '_blank'))) . '</h2>
                <p style="margin: 0; font-size: 14px;">' . $kicker . '.</p>
              </td></tr>';
  }

  $content .= $news_content . '</table>
      </td>
    </tr><tr>
      <td colspan="2">
        <table cellspacing="0" cellpadding="0" style="width: 100%; text-align: center; font-size: 14px;">' . $footer . '</table>
      </td>
    </tr>';

  $content .= '</table><p>&nbsp;</p><p>Thanks,</p><p>India Today Group</p></body></html>';

  return $content;

}

/**
 * Update cron table after sending mail
 * @param int $nid
 */
function itg_update_newsletter_cron_tbl($nid) {

  $query = db_select('itg_cron_newsletter', 'nc')
    ->fields('nc', array('nid', 'type', 'scheduled_time', 'frequency'))
    ->condition('nc.nid', $nid);
  $result = $query->execute();
  $records = $result->fetchAssoc();

  if ($records['type'] == 'manual') {
    db_update('itg_cron_newsletter')
      ->fields(array(
        'status' => 1,
      ))
      ->condition('nid', $nid, '=')
      ->execute();
  }
  else {

    switch ($records['frequency']) {
      case 'daily':
        $scheduled_time = strtotime('+1 day', $records['scheduled_time']);
        break;

      case 'weekly':
        $scheduled_time = strtotime('+7 days', $records['scheduled_time']);
        break;

      case 'monthly':
        $scheduled_time = strtotime('+1 month', $records['scheduled_time']);
        break;

      default:
        break;
    }

    // Update cron table scheduled time after sending mail
    db_update('itg_cron_newsletter')
      ->fields(array(
        'scheduled_time' => $scheduled_time,
      ))
      ->condition('nid', $nid, '=')
      ->execute();
  }
}