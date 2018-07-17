<?php

/** 
 * @file
 *   Template file for edit profile. 
 */
?>
<?php global $base_url; ?>
<?php print $data['tab']; ?>
<?php print render($data['form']); ?>
<div class="profile-ajax-loader" style="display: none">
    <img class="profile-loader" align="center" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />
</div>
<?php
$arg = arg();
if($arg[0] == 'personalization' && $arg[1] == 'edit-profile') {
?>
<script>
  jQuery(document).ready(function(){
    jQuery("select[name=country]").on("change" , function(){
      jQuery(".profile-ajax-loader").show();
    });
    jQuery("select[name=user_state]").on("change" , function(){
      jQuery(".profile-ajax-loader").show();
    });
    jQuery('#itg-personalization-edit-profile-form').on('submit', function() {
    var ufname = jQuery('#edit-fname').val();
    var ulname = jQuery('#edit-lname').val();
    if(ufname != '' && ulname != '') {
      jQuery(".profile-ajax-loader").show();
    }
    });
  });

  jQuery(document).ajaxComplete(function () {
      jQuery(".profile-ajax-loader").hide();
      jQuery("select[name=country]").on("change", function () {
          jQuery(".profile-ajax-loader").show();
      });
      jQuery("select[name=user_state]").on("change", function () {
          jQuery(".profile-ajax-loader").show();
      });
  });
</script>
<?php } ?>