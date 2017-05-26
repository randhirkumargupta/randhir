<?php if(isset($_SESSION['recent_event_payment_url'])) : ?>
<?php echo t("<h2>Your Payment was cancel</h2>") ?>
<?php echo t("Go back to register again <a href='@event_url?payment=cancel'>Click</a>" , array('@event_url' => $_SESSION['recent_event_payment_url']));?>
<?php unset($_SESSION['recent_event_payment_url']); else : ?>
<?php drupal_goto("<front>"); ?>
<?php endif; ?>