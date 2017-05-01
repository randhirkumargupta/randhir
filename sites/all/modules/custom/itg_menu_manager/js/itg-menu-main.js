(function ($) {
    Drupal.behaviors.itg_menu_manager_form = {
        attach: function (context, settings) {

            jQuery(document).ajaxStart(function () {
                jQuery("#widget-ajex-loader").show();
            });

            jQuery(document).ajaxSuccess(function () {
                $("#widget-ajex-loader").css("display", "none");
                var url_type = $('input[name=url_type]:checked').val();
                var menu_level_val = jQuery("select[name=menu_level]").val();
                if (url_type == 'internal') {
                    $('#edit-category-icon-ajax-wrapper').css("display", "none");
                } else {
                    $('#edit-category-icon-ajax-wrapper').css("display", "block");
                }

                if (menu_level_val == 'vertical') {
                    //jQuery("input[name=title]").removeAttr("disabled");
                    jQuery(".form-item-sections").css("display", "none");
                    jQuery(".form-item-display-icon").css("display", "none");
                }

                var spnr_val = jQuery("input[name='sponsored_category[Yes]']").is(':checked');
                color_picker_condition(spnr_val);
                jQuery("input[name='sponsored_category[Yes]']").on('click', function () {
                    var spnr_val = jQuery("input[name='sponsored_category[Yes]']").is(':checked');
                    color_picker_condition(spnr_val);
                });

            });


            jQuery("#edit-section-child").on('change', function () {
                var section_chlid = jQuery(this).val();
                jQuery("#edit-section-id").val(section_chlid);
            });

        }
    };
})(jQuery);

jQuery(document).ready(function () {
    var url_type = jQuery('input[name=url_type]:checked').val();
    var menu_level_val = jQuery("select[name=menu_level]").val();
    var sponsored_category = jQuery("sponsored_category['Yes']").val();
    if (url_type == 'internal') {
        jQuery('#edit-category-icon-ajax-wrapper').css("display", "none");
    } else {
        jQuery('#edit-category-icon-ajax-wrapper').css("display", "block");
    }

    if (menu_level_val == 'vertical') {
        console.log(sponsored_category);
        //jQuery("input[name=title]").removeAttr("disabled");
        jQuery(".form-item-sections").css("display", "none");
    }

    //console.log(menu_level_val);
});