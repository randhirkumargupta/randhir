<?php
$flag = true;
$finaltotal = 0;
global $user;
if (isset($view->result[0]->nid)) {
  $this_nid = $view->result[0]->nid;

  $isCookies = itg_poll_isCookies($this_nid);
}
if (isset($isCookies) && $isCookies == 'yes') {
   drupal_add_js("jQuery(document).ready(function(){jQuery('#block-views-poll-listing-block-1').hide(); });", 'inline');
}

// || (getcurrent_userpoll($this_nid) == $user->uid)
if (isset($isCookies) && $isCookies == 'yes') {
  $result_format = $view->result[0]->_field_data['nid']['entity']->field_result_format['und'][0]['value'];
  $display_format = $view->result[0]->_field_data['nid']['entity']->field_display_result['und'][0]['value'];
  $optionArr = itg_poll_getPollResult($this_nid);
  $opttotal = itg_poll_getTotalPoll($this_nid);

  foreach ($view->result as $item) {
    foreach ($item->_field_data['nid']['entity']->field_poll_answer['und'] as $row) {
      $item_id[] = $row['value'];
    }
  }

  $temp_entities = entity_load('field_collection_item', $item_id);
  if (is_array($optionArr) && count($optionArr) > 0) {

    $finaltotal = $opttotal;
    $outputnew = '';
    foreach ($temp_entities as $temp_ent_id => $temp_ents) {
      $polls_answer_text = isset($temp_ents->field_poll_answer_text[LANGUAGE_NONE]) ? $temp_ents->field_poll_answer_text[LANGUAGE_NONE][0]['value'] : '';
      $polls_answer_image = isset($temp_ents->field_poll_answer_image[LANGUAGE_NONE]) ? trim($temp_ents->field_poll_answer_image[LANGUAGE_NONE][0]['fid']) : '';

      if (isset($polls_answer_image) && $polls_answer_image > 0) {
          $poll_image = theme('image_style', array('style_name' => 'thumbnail', 'path' => file_load($polls_answer_image)->uri));
      }

      $ansId = isset($optionArr[$temp_ent_id]->ansId) ? $optionArr[$temp_ent_id]->ansId : '';
      $uid = isset($optionArr[$temp_ent_id]->uid) ? $optionArr[$temp_ent_id]->uid : 0;
      $preOptionCnt = isset($optionArr[$temp_ent_id]->optionCnt) ? $optionArr[$temp_ent_id]->optionCnt : 0;

      $optionCnt = $preOptionCnt;

      if ($result_format == 1) { // Percent
        if (isset($finaltotal)) {

          $outputnew = number_format(($optionCnt / $finaltotal) * 100, 2);
        }
      }
      elseif ($result_format == 2) { // Number of votes
        $outputnew = $optionCnt;
      }
      ?>

      <div class="poll-main-wrap">
        <div class="poll-list row">
          <div class="pull-left">
              <?php if ($polls_answer_text) { ?>
              <div class="poll-text-container">
              <?php print $polls_answer_text; ?>
              </div>
            <?php } ?>
              <?php if (isset($poll_image)) { ?>
              <div class="poll-image-container">
              <?php print $poll_image; ?>
              </div>
            <?php } ?> 
          </div>		

          <div class="pull-right">

      <?php print $outputnew; ?>			
          </div>
        </div>

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

