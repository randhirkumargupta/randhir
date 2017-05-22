<?php
/**
 * @file
 * Event Registration Page
 * 
 */
?>

<h2><?php print t('Registration'); ?></h2>

<div class="event-registration-main-container">
<h1><?php print t('Thank you for visiting the page.');?></h1>
 <div class="event-registration-link"><i class="fa fa-frown-o" aria-hidden="true"></i> <?php print t('Online Registration are not started yet.'); ?> <i class="fa fa-frown-o" aria-hidden="true"></i></div>
 <div class="buy-ticket-txt"><?php print t('START DATE'); ?>: <?php print format_date(strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']), $type = 'itg_date_with_time', $format = '', $timezone = NULL, $langcode = NULL); ?></div>

<?php
if(!empty($node->field_story_expert_description)): ?>
<div class="tc-txt"><span>*T&C:</span> <?php print $node->field_story_expert_description[LANGUAGE_NONE][0]['value'] ?> </span></div>
<?php endif; ?>
</div>