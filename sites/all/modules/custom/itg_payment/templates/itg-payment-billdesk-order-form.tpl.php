<?php echo t("Please wait we are redirecting payment gateway..."); ?>
<div class="hide">
    <?php echo drupal_render_children($form); ?>
</div>
<script>
  document.getElementById("itg-payment-billdesk-order-form").submit();
</script>