<?php
$flag = true;
$finaltotal = 0;
global $user;
if (isset($view->result[0]->nid)) {
  $this_nid = $view->result[0]->nid;

  $isCookies = itg_poll_isCookies($this_nid);
  $poll_uid = itg_poll_getcurrent_userpoll($this_nid, $user->uid);
}

if ((isset($isCookies) && $isCookies == 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid == $user->uid)) {
  drupal_add_js("jQuery(document).ready(function(){jQuery('#block-views-poll-listing-block-1').hide(); });", 'inline');
}

if ((isset($isCookies) && $isCookies == 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid == $user->uid)) {
  $result_format = $view->result[0]->_field_data['nid']['entity']->field_result_format[LANGUAGE_NONE][0]['value'];
  $display_format = $view->result[0]->_field_data['nid']['entity']->field_display_result[LANGUAGE_NONE][0]['value'];
  $optionArr = itg_poll_getPollResult($this_nid);
  $opttotal = itg_poll_getTotalPoll($this_nid);

  foreach ($view->result as $item) {
    foreach ($item->_field_data['nid']['entity']->field_poll_answer[LANGUAGE_NONE] as $row) {
      $item_id[] = $row['value'];
    }
  }

  $temp_entities = entity_load('field_collection_item', $item_id);
  if (is_array($optionArr) && count($optionArr) > 0) {

    $finaltotal = $opttotal;
    $outputnew = '';
    $poll_manipulate_allval = '';
    foreach ($temp_entities as $temp_ent_id => $temp_ents) {
       $poll_manipulate_allval += isset($temp_ents->field_poll_manipulate_value[LANGUAGE_NONE]) ? $temp_ents->field_poll_manipulate_value[LANGUAGE_NONE][0]['value'] : '';
    }
    $finaltotal += $poll_manipulate_allval;

    foreach ($temp_entities as $temp_ent_id => $temp_ents) {
      $polls_answer_text = isset($temp_ents->field_poll_answer_text[LANGUAGE_NONE]) ? $temp_ents->field_poll_answer_text[LANGUAGE_NONE][0]['value'] : '';
      $polls_answer_image = isset($temp_ents->field_poll_answer_image[LANGUAGE_NONE]) ? trim($temp_ents->field_poll_answer_image[LANGUAGE_NONE][0]['fid']) : '';
      
      // Poll Manipulate value
      $poll_manipulate_val = isset($temp_ents->field_poll_manipulate_value[LANGUAGE_NONE]) ? $temp_ents->field_poll_manipulate_value[LANGUAGE_NONE][0]['value'] : '';
      
      if (isset($polls_answer_image) && $polls_answer_image > 0) {
        $poll_image = theme('image_style', array('style_name' => 'thumbnail', 'path' => file_load($polls_answer_image)->uri));
      }

      $ansId = isset($optionArr[$temp_ent_id]->ansId) ? $optionArr[$temp_ent_id]->ansId : '';
      $uid = isset($optionArr[$temp_ent_id]->uid) ? $optionArr[$temp_ent_id]->uid : 0;
      $preOptionCnt = isset($optionArr[$temp_ent_id]->optionCnt) ? $optionArr[$temp_ent_id]->optionCnt : 0;

      $optionCnt = $preOptionCnt + $poll_manipulate_val;

      if ($result_format == 1) { // Percent
        if (isset($finaltotal)) {

          $outputnew = '<strong>'.t('Percent:').' </strong> ' . number_format(($optionCnt / $finaltotal) * 100) . '%';
        }
      }
      elseif ($result_format == 2) { // Number of votes
        $outputnew = '<strong>'.t('Number of votes:').' </strong> ' . $optionCnt;
      }
      ?>


      <div class="poll-list">
        <?php if ($polls_answer_text) { ?>
          <div class="poll-text">
            <?php print $polls_answer_text; ?>
          </div>
        <?php } ?>
        <?php if (isset($poll_image)) { ?>
          <div class="poll-image">
            <?php print $poll_image; ?>
          </div>
        <?php } ?>
        <div class="pole-vote"> <?php print $outputnew; ?></div>
      </div>  
      <?php
    }
  }
}
else {
  // unset data	
  unset($view->result);
}
?>

