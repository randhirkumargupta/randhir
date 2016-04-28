/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    Drupal.behaviors.itg_mobile_service_form = {
        attach: function(context, settings) {
            $('#edit-field-service-association-title-und').change(function() {
                 $('#edit-field-story-expert-description-und-0-value').val('');
                 $('#edit-field-story-large-image .button-remove').mousedown();
                 $('#edit-field-service-audio .button-remove').mousedown();
                 $('#edit-field-service-video .button-remove').mousedown();
            });
                 $('#edit-actions').css('display','block');
                 $('.form-layout-default .column-main .column-wrapper > .form-actions').show();
        }
    }
})(jQuery);

jQuery('document').ready(function() {
    var maxLen = 0
    jQuery('#edit-field-service-association-title-und').change(function() {
        jQuery('#remain').text('');
        if (jQuery('#edit-field-service-association-title-und').val() != '_none') {
            var nid = jQuery('#edit-field-service-association-title-und').val();
            jQuery.ajax({
                type: "POST",
                url: Drupal.settings.basePath + 'countchar_validation',
                data: 'nidvalue=' + nid,
                success: function(msg) {
                    maxLen = parseInt(msg);                                        
                },
            });
        }
    });
jQuery('#edit-field-story-expert-description-und-0-value').keyup(function() {
                       var tlength = jQuery(this).val().length;
                       console.log(maxLen);
                       console.log(tlength);
                       jQuery(this).val(jQuery(this).val().substring(0, maxLen));
                       var tlength = jQuery(this).val().length;
                       remain = maxLen - parseInt(tlength); 
                       jQuery('#remain').text(remain + ' characters remaining from '+ maxLen);
                    });
});