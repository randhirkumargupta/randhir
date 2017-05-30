<?php if(isset($_SESSION['recent_event_payment_url'])) : ?>
<div class="payment-success-message">
  <?php echo t("<h2>Your Payment was successful</h2>") ?>
  <p><?php echo t("Thank you for your payment. Your transaction has been completed. <br/>"); ?>
  <?php echo t("Go back to register again <a href='@event_url?payment=done'>Click</a>" , array('@event_url' => $_SESSION['recent_event_payment_url']));?>
  </p>
</div>
<?php unset($_SESSION['recent_event_payment_url']); else : ?>
<?php drupal_goto("<front>"); ?>
<?php endif; ?>
