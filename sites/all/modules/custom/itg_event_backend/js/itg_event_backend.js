/*
 * @file itg_event_backend.js
 * Contains functionality related event form
 */


(function($) {

    Drupal.behaviors.itg_event_backend_form = {
        attach: function(context, settings) {

            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            $('.form-item-field-gallery-image-add-more-number').hide();
            var uid = settings.itg_event_backend.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                $('#edit-field-event-short-description-und-0-format').hide();
                $('#edit-body-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-scheduler-settings').show();
                $('#edit-metatags-und-advanced').hide();

            }
            // Disable date filed direct enter date
            jQuery('input[name="field_event_start_date[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_event_close_date[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_registration_close_date[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_story_expiry_date[und][0][value][date]').keydown(false);
            jQuery('input[name="publish_on[date]"]').keydown(false);
            jQuery('input[name="unpublish_on[date]"]').keydown(false);
            // end code

            // hide skip button
            $('#edit-skip').hide();
            $('#edit-skip-1').hide();
            $('[data-id="edit-skip"]').hide();
            $('[data-id="edit-skip-1"]').hide();
            // Reset Paid value after click on Free
            $('#edit-field-event-type-und-free').on('click', function(){
                $('#edit-field-group-registration-fee-5-und-0-value').val('');
                $('#edit-field-group-registration-fee-10-und-0-value').val('');
                $('#edit-field-individual-registration-fe-und-0-value').val('');
            });
            $('#edit-field-event-type-und-invite').on('click', function(){
                $('#edit-field-group-registration-fee-5-und-0-value').val('');
                $('#edit-field-group-registration-fee-10-und-0-value').val('');
                $('#edit-field-individual-registration-fe-und-0-value').val('');
                $('#edit-field-no-of-tickets-und-0-value').val('');
            });
            
            $('#edit-field-event-media-und-0-remove-button').hide();
            $('#edit-field-event-highlights-und-0-remove-button').hide();
            $('#edit-field-program-schedule-und-0-remove-button').hide();
            $('#edit-field-associate-sponsors-und-0-remove-button').hide();
         
        }
    }
})(jQuery);
