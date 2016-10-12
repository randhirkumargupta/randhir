/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


jQuery(".itg_menu_manager_form").ajaxSuccess(function(event, xhr, settings) {
    var menu_level_val = jQuery("select[name=menu_level]").val();
    var section_value = jQuery("select[name=sections]").val();
    var url_type = jQuery("input[name=url_type]").val();
    if (menu_level_val == 'third' && section_value == 0) {
        jQuery("input[type=text]").val("");
        jQuery("input[name=title]").attr("disabled", "disabled");
        jQuery("input[name=url]").attr("disabled", "disabled");
        jQuery("div#decided-section").css("display", "inline-block !important");
    }

    if (menu_level_val == 'second') {
        jQuery("input[name=title]").removeAttr("disabled");
        jQuery("input[name=url]").removeAttr("disabled");
    }

    if (url_type == 'internal' && menu_level_val.length <= 0) {
        jQuery("#itg-menu-manager-form input[type=text]").attr("disabled", "disabled");
    }
});


jQuery(".itg_menu_manager_form").ready(function() {
    jQuery("#itg-menu-manager-form input[type=text]").attr("disabled", "disabled");
});


(function($) {
    Drupal.behaviors.itg_menu_manager_form = {
        attach: function(context, settings) {
            jQuery(document).ajaxStart(function() {
                jQuery("#widget-ajex-loader").show();
            });
            $(document).ajaxSuccess(function() {
                $("#widget-ajex-loader").css("display", "none");
            });
        }
    };
})(jQuery);