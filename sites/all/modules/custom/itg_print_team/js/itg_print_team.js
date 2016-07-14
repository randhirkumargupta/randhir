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

            if (nid) {
                $('input[name="field_pti_print_media_und_0_remove_button"]').show();
            } else {
                $('#edit-field-print-media-und-0-remove-button').hide();
            }
            
            $('input[name="field_survey_end_date[und][0][value][date]"]').attr('readonly', true);
            $('#views-form-manage-print-team-page div .container-inline').hide();
            $('.form-item-pti-issue-date label').hide();

            if ($("input[name='field_pti_idea_status[und]']:checked").val() === 'Approved') {
              $('#edit-field-pti-words-limit').show();
              $('#edit-field-survey-end-date').show();

            }
            else {
              $('#edit-field-pti-words-limit').hide();
              $('#edit-field-survey-end-date').hide();
            }

            $("input[name='field_pti_idea_status[und]").on("click", function() {
              if ($("input[name='field_pti_idea_status[und]']:checked").val() === 'Approved') {
                $('#edit-field-pti-words-limit').show();
                $('#edit-field-survey-end-date').show();
              }
              else {
                $('#edit-field-pti-words-limit').hide();
                $('#edit-field-survey-end-date').hide();
              }
            });
        }
    };

})(jQuery, Drupal, this, this.document);