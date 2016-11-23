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
 <div class="event-registration-link"><i class="fa fa-frown-o" aria-hidden="true"></i> Tickets are not available now. <i class="fa fa-frown-o" aria-hidden="true"></i></div>
 <?php
  if(!empty($node->field_story_expert_description)): ?>
  <div class="tc-txt"><span>*T&C:</span> <?php print $node->field_story_expert_description[LANGUAGE_NONE][0]['value'] ?> </span></div>
  <?php endif; ?>
</div> 
