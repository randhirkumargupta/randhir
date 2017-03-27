/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


jQuery(".itg_menu_manager_form").ajaxSuccess(function (event, xhr, settings) {
    var menu_level_val = jQuery("select[name=menu_level]").val();
    var section_value = jQuery("select[name=sections]").val();
    var url_type = jQuery("input[name=url_type]").val();
    if (menu_level_val == 'third' && section_value == 0) {
        jQuery("input[type=text]").val("");
        //jQuery("input[name=title]").attr("disabled", "disabled");
        jQuery("input[name=url]").attr("disabled", "disabled");
        jQuery("div#decided-section").css("display", "inline-block !important");
    }

    if (menu_level_val == 'second') {
        //jQuery("input[name=title]").removeAttr("disabled");
        jQuery("input[name=url]").removeAttr("disabled");
    }

    if (url_type == 'internal' && menu_level_val.length <= 0) {
        jQuery("#itg-menu-manager-form input[type=text]").attr("disabled", "disabled");
    }
});


jQuery(document).ready(function () {
    jQuery("#edit-section-child").on('change', function () {
        var section_chlid = jQuery(this).val();
        jQuery("#edit-section-id").attr("value", section_chlid);
        jQuery("#views-exposed-form-menu-manager-menu-manager-page").submit();
        jQuery("#widget-ajex-loader").show();
    });

//    jQuery("input[name=title]").on('keydown', function (event) {
//        var key_code = event.keyCode;
//        if (key_code == 8) {
//            jQuery(this).attr("value", "");
//        }
//    });
});

function isValidKey(e) {
    var url_type = jQuery("input[name=url_type]").val();
    if (url_type == 'internal') {
        var charCode = e.keyCode || e.which;
        if (charCode == 8 || charCode == 46) {
            jQuery("input[name=title]").attr("value", "");
            jQuery("input[name=url]").attr("value", "");
        }
        return true;
    }
}