<?php

/** 
 * @file
 *   Template file for edit profile. 
 */
?>
<?php global $base_url; ?>
<?php print $data['tab']; ?>
<?php print render($data['form']); ?>
<div id="widget-ajex-loader" style="display: none">
    <img class="widget-loader" align="center" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />
</div>

<script>
  jQuery(document).ready(function(){
    jQuery("select[name=country]").on("change" , function(){
      jQuery("#widget-ajex-loader").show();
    });
    jQuery("select[name=user_state]").on("change" , function(){
      jQuery("#widget-ajex-loader").show();
    });
    jQuery('#itg-personalization-edit-profile-form').on('submit', function() {
    jQuery("#widget-ajex-loader").show();
    });
  });

  jQuery(document).ajaxComplete(function () {
      jQuery("#widget-ajex-loader").hide();
      jQuery("select[name=country]").on("change", function () {
          jQuery("#widget-ajex-loader").show();
      });
      jQuery("select[name=user_state]").on("change", function () {
          jQuery("#widget-ajex-loader").show();
      });
  });
</script>