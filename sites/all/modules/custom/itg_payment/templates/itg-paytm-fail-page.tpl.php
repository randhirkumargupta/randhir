<?php echo t("<h2>Your Payment was failed</h2>") ?>
<?php echo t("Go back to register again <a href='@event_url'>Click</a>" , array('@event_url' => $_SESSION['recent_event_payment_url']));?>