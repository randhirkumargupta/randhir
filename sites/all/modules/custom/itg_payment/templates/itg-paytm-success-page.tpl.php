<?php if(isset($_SESSION['recent_event_payment_url'])) : ?>
<?php echo t("<h2>Your Payment was successful</h2>") ?>
<?php echo t("Thank you for your payment. Your transaction has been completed. <br/>"); ?>
<?php echo t("Go back to register again <a href='@event_url?payment=done'>Click</a>" , array('@event_url' => $_SESSION['recent_event_payment_url']));?>
<?php unset($_SESSION['recent_event_payment_url']); else : ?>
<?php drupal_goto("<front>"); ?>
<?php endif; ?>