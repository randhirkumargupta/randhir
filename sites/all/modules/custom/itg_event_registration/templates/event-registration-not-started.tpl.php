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
 <div class="event-registration-link"><i class="fa fa-frown-o" aria-hidden="true"></i> Online Registration are not started yet. <i class="fa fa-frown-o" aria-hidden="true"></i></div>
 <div class="buy-ticket-txt">START DATE: <?php print date('d/m/Y', strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']));?></div>
<!-- <div class="buy-ticket-txt">YOU CAN BY TICKETS FROM VENUE: <a href="#" class="siri-audi-link">SIRI FORT AUDITORIUM</a> </br> PLEASE CARRY A VALID PHOTO AND ID PROOF.</div>-->
 <div class="tc-txt"><span>*T&C:</span> Living Media India Ltd. reserves the right to terminate, extend or change this offer or any part thereof at any times. It also reserves the right to accept or reject any or all forms received at their absolute discretion without assigning any reason.  </span></div>
</div>