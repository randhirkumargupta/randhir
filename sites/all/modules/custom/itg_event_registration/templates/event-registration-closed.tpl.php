<?php
/**
 * @file
 * Event Registration Page
 * 
 */
?>

<h2>Registration</h2>

<div class="event-registration-main-container">
<h1>Thank you for visiting the page.</h1>
 <div class="event-registration-link"><i class="fa fa-frown-o" aria-hidden="true"></i> Online Registration are now closed. <i class="fa fa-frown-o" aria-hidden="true"></i></div>
 <div class="buy-ticket-txt">YOU CAN BY TICKETS FROM VENUE: <a href="#" class="siri-audi-link"><?php print $node->field_story_kicker_text[LANGUAGE_NONE][0]['value']; ?></a> </br> PLEASE CARRY A VALID PHOTO AND ID PROOF.</div>
  <?php
  if(!empty($node->field_story_expert_description)): ?>
  <div class="tc-txt"><span>*T&C:</span> <?php print $node->field_story_expert_description[LANGUAGE_NONE][0]['value'] ?> </span></div>
  <?php endif; ?>
</div> 
