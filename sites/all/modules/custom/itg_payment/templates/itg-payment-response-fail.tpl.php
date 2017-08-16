<?php if(isset($_SESSION['recent_event_payment_url'])) : ?>
<?php echo t("<h2>Your Payment was failed</h2>") ?>
<?php echo t("Go back to register again <a href='@event_url?payment=fail'>Click</a>" , array('@event_url' => $_SESSION['recent_event_payment_url']));?>
<?php else : ?>
<?php
unset($_SESSION['recent_event_payment_url']);
drupal_set_message(t("Payment fail"));
drupal_goto("<front>"); 
?>
<?php endif; ?>