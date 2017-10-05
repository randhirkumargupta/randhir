/*
 * @file itg_event_backend.js
 * Contains functionality related event form
 */


(function ($) {

    Drupal.behaviors.itg_event_backend_form = {
        attach: function (context, settings) {

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
            $('#edit-field-event-type-und-free').on('click', function () {
                $('#edit-field-group-registration-fee-5-und-0-value').val('');
                $('#edit-field-group-registration-fee-10-und-0-value').val('');
                $('#edit-field-individual-registration-fe-und-0-value').val('');
            });
            $('#edit-field-event-type-und-invite').on('click', function () {
                $('#edit-field-group-registration-fee-5-und-0-value').val('');
                $('#edit-field-group-registration-fee-10-und-0-value').val('');
                $('#edit-field-individual-registration-fe-und-0-value').val('');
                $('#edit-field-no-of-tickets-und-0-value').val('');
            });

            $('#edit-field-event-media-und-0-remove-button').hide();
            if (jQuery(".cancel").is("#edit-field-event-highlights-und-1-remove-button")) {
                $('#edit-field-event-highlights-und-0-remove-button').show();
            } else {
                $('#edit-field-event-highlights-und-0-remove-button').hide();
            }
            
            if (jQuery(".cancel").is("#edit-field-event-tabs-und-1-remove-button")) {
                $('#edit-field-event-tabs-und-0-remove-button').show();
            } else {
                $('#edit-field-event-tabs-und-0-remove-button').hide();
            }
            
            $('#edit-field-program-schedule-und-0-remove-button').hide();
            $('#edit-field-associate-sponsors-und-0-remove-button').hide();

            $('input[name="field_registration_date_checkbox[und][1]"]').change(function () {
                $('input[name="field_story_expiry_date[und][0][value][date]"]').val('');
                $('input[name="field_story_expiry_date[und][0][value][time]"]').val('');
                $('input[name="field_registration_close_date[und][0][value][date]"]').val('');
                $('input[name="field_registration_close_date[und][0][value][time]"]').val('');
            });
            $('.field-name-field-early-bird-individual-regi').hide();
            $('.field-name-field-early-bird-group-registrat').hide();
            $('.field-name-field-early-bird-group-10-reg').hide();
            if ($('input[name="field_early_bird[und][early_bird_offer]"]').prop('checked')) {
                $('.field-name-field-early-bird-individual-regi').show();
                $('.field-name-field-early-bird-group-registrat').show();
                $('.field-name-field-early-bird-group-10-reg').show();
                $('.field-name-field-individual-registration-fe').hide();
                $('.field-name-field-group-registration-fee-5').hide();
                $('.field-name-field-group-registration-fee-10').hide();
            } else {
                $('.field-name-field-early-bird-individual-regi').hide();
                $('.field-name-field-early-bird-group-registrat').hide();
                $('.field-name-field-early-bird-group-10-reg').hide();
                $('.field-name-field-individual-registration-fe').show();
                $('.field-name-field-group-registration-fee-5').show();
                $('.field-name-field-group-registration-fee-10').show();
            }
            $('input[name="field_early_bird[und][early_bird_offer]"]').change(function () {
                if ($(this).prop('checked')) {
                    $('.field-name-field-early-bird-individual-regi').show();
                    $('.field-name-field-early-bird-group-registrat').show();
                    $('.field-name-field-early-bird-group-10-reg').show();
                    $('.field-name-field-individual-registration-fe').hide();
                    $('.field-name-field-group-registration-fee-5').hide();
                    $('.field-name-field-group-registration-fee-10').hide();
                    $('.field-name-field-individual-registration-fe input').val('');
                    $('.field-name-field-group-registration-fee-5 input').val('');
                    $('.field-name-field-group-registration-fee-10 input').val('');
                } else {
                    $('.field-name-field-early-bird-individual-regi').hide();
                    $('.field-name-field-early-bird-group-registrat').hide();
                    $('.field-name-field-early-bird-group-10-reg').hide();
                    $('.field-name-field-early-bird-individual-regi input').val('');
                    $('.field-name-field-early-bird-group-registrat input').val('');
                    $('.field-name-field-early-bird-group-10-reg input').val('');
                    $('.field-name-field-individual-registration-fe').show();
                    $('.field-name-field-group-registration-fee-5').show();
                    $('.field-name-field-group-registration-fee-10').show();
                }
            });

            jQuery('.form-field-name-field-event-tabs .form-radio').on('change', function () {
                var value = jQuery(this).val();
                var tabsefFields = jQuery(this).parents('tr.draggable').find('.field-name-field-tab-sef, .field-name-field-tabs-description');
                var taburlFields = jQuery(this).parents('tr.draggable').find('.field-name-field-tab-url');

                if (value === 'tab_url') {
                    taburlFields.find('input').val('');
                    taburlFields.find('textarea').html('');
                    taburlFields.show();
                    tabsefFields.hide();
                } else if (value === 'tab_sef') {
                    tabsefFields.find('input').val('');
                    tabsefFields.find('textarea').html('');
                    tabsefFields.show();
                    taburlFields.hide();
                }

            });


            jQuery('.form-field-name-field-event-tabs tr.draggable').each(function () {
                jQuery(this).find('.field-name-field-tab-sef-tab-url .form-type-radio').each(function () {
                    var defaltVal = jQuery(this).find('input[type="radio"]:checked').val();
                    var taburlFields = jQuery(this).parents('td').find('.field-name-field-tab-sef, .field-name-field-tabs-description');
                    var tabsefFields = jQuery(this).parents('td').find('.field-name-field-tab-url');

                    if (defaltVal === 'tab_url') {
                        taburlFields.hide();
                        tabsefFields.show();
                    } else if (defaltVal === 'tab_sef') {
                        tabsefFields.hide();
                        taburlFields.show();
                    }
                });
            });
        }
    }
})(jQuery);


