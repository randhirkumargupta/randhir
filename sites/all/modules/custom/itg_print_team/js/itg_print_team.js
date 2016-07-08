/*
 * @file itg_print_team.js
 */

(function ($) {
    Drupal.behaviors.itg_print_team = {
        attach: function (context, settings) {

            //Collect required variables
            var uid = settings.itg_print_team.settings.uid;
            var base_url = settings.itg_print_team.settings.base_url;
            var type = settings.itg_print_team.settings.type;
            var nid = settings.itg_print_team.settings.nid;
            
            //Hide left side vertical tabs in case of simple users
            if (uid != 1) {
                $('.field-edit-link').hide();
                $('#edit-body-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $("#edit-metatags-und-advanced").hide();
                $(".form-item-metatags-und-abstract-value").hide();
            }
            $('input[name="field_survey_end_date[und][0][value][date]"]').attr('readonly', true);
            $('#views-form-manage-print-team-page div .container-inline').hide();
            $('.form-item-pti-issue-date label').hide();
        }
    };

})(jQuery, Drupal, this, this.document);