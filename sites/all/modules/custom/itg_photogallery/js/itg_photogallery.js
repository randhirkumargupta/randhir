/*
 * @file itg_photogallery.js
 * Contains all functionality related to photogallery
 */

(function ($) {

    Drupal.behaviors.itg_photogallery_form = {
        attach: function (context, settings) {
            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            $('.form-item-field-gallery-image-add-more-number').hide();
            var uid = settings.itg_photogallery.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                $('#edit-field-gallery-kicer-und-0-format').hide();
                $('#edit-field-photogallery-description-und-0-format').hide();
            }

            // Code for comment question field hide and show
            $('#edit-field-photogallery-configuration-und-commentbox').click(function () {
                if ($("#edit-field-photogallery-configuration-und-commentbox").is(":not(:checked)")) {
                    $("#edit-field-story-comment-question-und-0-value").val('');
                }
            });

            jQuery('.plupload_start').on('click', function () {
                $('#photogallery-node-form').ajaxComplete(function (event, request, settings) {
                    if (jQuery('input[name="field_gallery_image[und][0][field_images][und][0][fid]"]').val() == 0) {
                        jQuery('.field-multiple-table tbody tr:first .cancel').mousedown();
                        jQuery(this).off(event);
                    }

                });
            });


        }
    }
})(jQuery);

jQuery('document').ready(function () {
    jQuery("#edit-field-story-syndication-und-yes").click(function () {
        if (jQuery(this).is(':checked')) {
            jQuery('.check_syndication input:checkbox').each(function () {
                jQuery(this).prop('checked', true);
            });
        } else {
            jQuery('.check_syndication input:checkbox').each(function () {
                jQuery(this).prop('checked', false);
            });
        }
    });

//    jQuery('.check_syndication input:checkbox').click(function () {
//        var checkflag = 0;
//        jQuery('.check_syndication input:checkbox').each(function () {
//            if (jQuery(this).is(':checked')) {
//                checkflag = 1;
//            }
//        });
//
//        if (checkflag == 0) {
//            jQuery("#edit-field-story-syndication-und-yes").prop('checked', false);
//        }
//    });
});

