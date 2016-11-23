<?php
/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 */
?>
<?php print t("<h1>Send us feedback</h1>"); ?>
<?php print t("Fiedls marked with * are manadatory."); ?>
<div class="webform-conatiner">
  <div class="feeback-container">
    <div class="webform-name-field feedback">
      <?php print drupal_render($form['submitted']['feedback']); ?>
    </div>
  </div>
  <div class="webform-submit-social">
    <?php print t("Submit feedback via"); ?>
    <?php if ($_SERVER['HTTP_HOST'] == PARENT_SSO) { ?>
      <a href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, 'http://<?php print PARENT_SSO; ?>/saml_login/other/domain_info', 'indiatoday');" class="user-icon"><i class="fa fa-user"></i></a>
      <a href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, 'http://<?php print PARENT_SSO; ?>/signup/domain_info', 'indiatoday');" class="register-icon" style="display:none;"><i class="fa fa-user"></i></a>

      <?php
    }
    else {
      ?>
      <a onclick="Go (550, 500, 50, 'indiatoday', '', '<?php print PARENT_SSO; ?>', '/saml_login/other')" class="user-icon">
        <input type="button" class="btn" value="Twitter">
        <input type="button" class="btn" value="Facebook">
        <input type="button" class="btn" value="Google+">
        <input type="button" class="btn" value="Linkedin">
      </a>

      <?php
    }
    ?>
  </div>
    <?php print t("Or share following details."); ?>
  <div class="name-email-continer">
    <div class="webform-name-field user-name">
      <?php print drupal_render($form['submitted']['name']); ?>
    </div>
    <div class="webform-name-field user-email">
      <?php print drupal_render($form['submitted']['email']); ?>
    </div>
  </div>
  <?php
// Print out the main part of the form.
// Feel free to break this up and move the pieces within the array.
  print drupal_render($form['submitted']);

// Always print out the entire $form. This renders the remaining pieces of the
// form that haven't yet been rendered above.
  print drupal_render_children($form);
  ?>
</div>