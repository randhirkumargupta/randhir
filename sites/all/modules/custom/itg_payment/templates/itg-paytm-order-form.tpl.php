<?php echo t("Please wait we are redirecting payment gateway..."); ?>
<?php
header("Pragma: no-cache");
header("Cache-Control: no-cache");
header("Expires: 0");
print "<div class='hide'>";
print drupal_render_children($form);
print "</div>";
?>
<script>
  document.getElementById("itg-payment-order-form").submit();
</script>