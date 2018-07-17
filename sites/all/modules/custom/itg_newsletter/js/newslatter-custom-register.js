jQuery(document).ready(function(){ 
    jQuery('#itg-newslatter-register-form label').hide(); 
});

jQuery(document).ajaxSuccess (function () { jQuery('#edit-email').val(''); 
jQuery('#edit-name').val(''); jQuery('#edit-mobile').val(''); });