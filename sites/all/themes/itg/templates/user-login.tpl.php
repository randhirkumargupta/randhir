<?php
if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
  if (strpos($_GET['ReturnTo'], 'domain_info') !== false) {
    $shr = 'domain_info';
  }
  else {
    $shr = '';
  }
}
?>
<?php if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) { ?>
<div class="social-share">
<a href="saml_login/twitter/<?php echo $shr; ?>" class="sso-twitter">Twitter</a>
<a href="#" class="sso-facebook">Facebook</a>
</div>
<?php print '<div class="sign-border">or sign in using your email address</div>';
 } else { ?>
  <h2>Log in</h2>
<?php } ?>
  <div class="login-wrapper">
    <?php print drupal_render($form['name']); 
          print drupal_render($form['pass']);
          print drupal_render($form['remember_me']); ?>
    <div class="form-actions">
      <?php print drupal_render($form['actions']['submit']);
        
        if (isset($_GET['ReturnTo']) && !empty($_GET['ReturnTo'])) {
          if (strpos($_GET['ReturnTo'], 'domain_info') !== false) {
                   $forgot = 'forgot-password/domain_info';
                   $signup = 'signup/domain_info';
                 }
                 else
                 {
                   $forgot = 'forgot-password';
                   $signup = 'signup';
                 }
          print '<div class="bottom-link">'. l('Forgot Your Password?',$forgot, array('attributes' => array('class' => 'sso-forgot-link')));
          print l('New Here ? Signup',$signup, array('attributes' => array('class' => 'sso-register-link')));
          print '</div>';
          
          } 
          else { 
          print l('Forgot Password?','user/password', array('attributes' => array('class' => 'forgot-link'))); 
        } 
        
        ?>
    </div>
    <?php print drupal_render_children($form) ?>
    
  </div>