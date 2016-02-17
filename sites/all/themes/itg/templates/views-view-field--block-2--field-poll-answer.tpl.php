<?php

$flag=true;
$finaltotal = 0;
if(isset($view->result[0]->nid)) {
	$this_nid = $view->result[0]->nid;

	$isCookies = isCookies($this_nid);

}

if(isset($isCookies) && $isCookies == 'yes') {

$optionArr = getPollResult($this_nid);
$opttotal = getTotalPoll($this_nid);
foreach ($view->result as $item) {
	foreach($item->_field_data['nid']['entity']->field_poll_answer['und'] as $row) {
		$item_id[] = $row['value'];
	}
}

$temp_entities = entity_load('field_collection_item', $item_id);

if(is_array($optionArr) && count($optionArr) > 0) {

// get total poll value
foreach ( $temp_entities as $temp_ent_id => $temp_ents) {

  $polls_answe_default = isset($temp_ents->field_poll_answe_default_value[LANGUAGE_NONE]) ? $temp_ents->field_poll_answe_default_value[LANGUAGE_NONE][0]['value'] : 0;

  $finaltotal += isset($polls_answe_default) ? $polls_answe_default : 0;
}

$finaltotal = $finaltotal + $opttotal;

foreach ( $temp_entities as $temp_ent_id => $temp_ents) {
$polls_answer_text   = isset($temp_ents->field_poll_answer_text[LANGUAGE_NONE]) ? $temp_ents->field_poll_answer_text[LANGUAGE_NONE][0]['value'] : '';
$polls_answer_image  = isset($temp_ents->field_poll_answer_image[LANGUAGE_NONE]) ? trim($temp_ents->field_poll_answer_image[LANGUAGE_NONE][0]['fid']) : '';

if(isset($polls_answer_image) && $polls_answer_image > 0) {
	$poll_image = theme('image', array('path' => file_load($polls_answer_image)->uri, 'alt' => t(''), 'style_name' => 'my_image_style'));
}


$polls_answer_video  = isset($temp_ents->field_poll_answer_video[LANGUAGE_NONE]) ? $temp_ents->field_poll_answer_video[LANGUAGE_NONE][0]['value'] : '';
$polls_answer_default = isset($temp_ents->field_poll_answe_default_value[LANGUAGE_NONE]) ? $temp_ents->field_poll_answe_default_value[LANGUAGE_NONE][0]['value'] : '';

$ansId = isset($optionArr[$temp_ent_id]->ansId) ? $optionArr[$temp_ent_id]->ansId : '';
$uid = isset($optionArr[$temp_ent_id]->uid) ? $optionArr[$temp_ent_id]->uid : 0;
$preOptionCnt = isset($optionArr[$temp_ent_id]->optionCnt) ? $optionArr[$temp_ent_id]->optionCnt : 0;

$optionCnt = $preOptionCnt + $polls_answer_default; 
if(isset($finaltotal)) {

$percentage = number_format(($optionCnt / $finaltotal) * 100, 2);
?>

 <div class="poll-main-wrap">
	<div class="poll-list row">
		<div class="pull-left">
			<?php if($polls_answer_text) { ?>
			<div class="poll-text-container">
			<?php  print $polls_answer_text; ?>
			</div>
                        <?php } ?>
			<?php if(isset($poll_image)) { ?>
			<div class="poll-image-container">
			<?php  print $poll_image; ?>
			</div>
                        <?php } ?> 
			<?php if($polls_answer_video) { ?>
			<div class="poll-video-container">
			<?php  print $polls_answer_video; ?>
			</div>
                        <?php } ?>  


		</div>		
		  
		<div class="pull-right">
			
			<?php print $percentage; ?>			
		</div>
	</div>
	
</div>
  

<?php
       } 
     }
  }

}
else
{
	// unset data	
	unset($view->result);

}
?>

