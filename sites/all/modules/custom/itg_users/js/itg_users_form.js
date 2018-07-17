/*
 * @file itg_users_form.js
 * Contains all functionality related to users
 */



jQuery(document).ready(function() {
    jQuery('#edit-name').blur(function(){
        jQuery('#user-pass .login-wrapper span.error').text('');
        jQuery('#user-pass .login-wrapper span.error').text('Please enter Email Address.');
    });
    
    jQuery('#edit-submit').on('click', function(){
      setInterval(function() {
      jQuery('#user-pass .login-wrapper span.error').text('');
      jQuery('#user-pass .login-wrapper span.error').text('Please enter Email Address.');
        }, 0.1);
    });
});