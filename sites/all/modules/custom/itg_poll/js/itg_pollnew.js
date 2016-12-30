/*
 * @file itg_event_backend.js
 * Contains functionality related Poll form
 */

(function($) {

    Drupal.behaviors.itg_poll_form = {
        attach: function(context, settings) {
            $('#edit-field-poll-itg-state').hide();
            jQuery('input[name="field_poll_start_date[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_poll_end_date[und][0][value][date]"]').keydown(false);
            var getOptionAnswerValnew = $("#edit-field-poll-answer-option-und option:selected").val();
            if (getOptionAnswerValnew == 1) {
                $('.field-name-field-poll-answer-image').hide();
                $('.field-name-field-poll-answer-text').show();
            } else if (getOptionAnswerValnew == 2) {
                $('.field-name-field-poll-answer-image').show();
                $('.field-name-field-poll-answer-text').hide();
            } else if (getOptionAnswerValnew == '_none') {
                $('#edit-field-poll-answer').hide();
            }


            var getOptionAnswerVal;
            $('#edit-field-poll-answer-option-und').on('change', function() {
                $('.field-name-field-ans-caption input').val(''); // caption value reset
                getOptionAnswerVal = $("#edit-field-poll-answer-option-und").val();
                if (getOptionAnswerVal == 1) {
                    $('#edit-field-poll-answer').show();
                    $('.field-name-field-poll-answer-image').hide();
                    $('.field-name-field-poll-answer-text').show();
                    $('.field-name-field-poll-manipulate-value input').val('');
                    $('.field-name-field-poll-answer-image .button-remove').mousedown();
                } else if (getOptionAnswerVal == 2) {
                    $('#edit-field-poll-answer').show();
                    $('.field-name-field-poll-answer-image').show();
                    $('.field-name-field-poll-answer-text').hide();
                    $('.field-name-field-poll-answer-text input').val('');
                    $('.field-name-field-poll-manipulate-value input').val('');
                } else if (getOptionAnswerVal == '_none') {
                    $('#edit-field-poll-answer').hide();
                }
            });


            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            $('.form-item-field-gallery-image-add-more-number').hide();
            var uid = settings.itg_poll.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                $('#edit-field-gallery-kicer-und-0-format').hide();
                $('#edit-field-photogallery-description-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();

            }

            //Reset form element
            //Reset end date field
            $("#edit-field-display-result-und-2").prop("disabled", true);
            $('#edit-field-show-end-date-und-1').click(function() {
                if ($("#edit-field-show-end-date-und-1").is(":not(:checked)")) {
                    $("#edit-field-poll-end-date-und-0-value-datepicker-popup-2").val('');
                    $("#edit-field-poll-end-date-und-0-value-timeEntry-popup-1").val('');
                    $("#edit-field-display-result-und-1").prop("checked", true);
                    $("#edit-field-display-result-und-2").prop("disabled", true);
                } else {
                    var dval = $('#edit-field-poll-start-date-und-0-value-datepicker-popup-2').val().split('/');

                    var ndval = dval[1] + '/' + dval[0] + '/' + dval[2];
                    var myDate = new Date(ndval);
                    myDate.setDate(myDate.getDate() + parseInt(7));
                    $("#edit-field-poll-end-date-und-0-value-datepicker-popup-2").val($.datepicker.formatDate('dd/mm/yy', myDate));

                    $("#edit-field-poll-end-date-und-0-value-timeEntry-popup-1").val($.datepicker.formatDate('23:00', myDate));
                    if ($('#edit-field-poll-end-date-und-0-value-datepicker-popup-2').val()) {
                        $("#edit-field-display-result-und-2").prop("disabled", false);
                    } else {
                        $("#edit-field-display-result-und-1").prop("checked", true);
                        $("#edit-field-display-result-und-2").prop("disabled", true);
                    }
                }
            });
            $('document').ready(function() {
                if ($('#edit-field-poll-end-date-und-0-value-datepicker-popup-2').val()) {
                    $("#edit-field-display-result-und-2").prop("disabled", false);
                } else {
                    $("#edit-field-display-result-und-1").prop("checked", true);
                    $("#edit-field-display-result-und-2").prop("disabled", true);
                }
                jQuery("#edit-field-poll-end-date-und-0-value-datepicker-popup-2").datepicker({
                    minDate: 0,
                    dateFormat: 'dd/mm/yy',
                    onClose: function() {
                        if ($('#edit-field-poll-end-date-und-0-value-datepicker-popup-2').val()) {
                            $("#edit-field-display-result-und-2").prop("disabled", false);
                        } else {
                            $("#edit-field-display-result-und-2").prop("disabled", true);
                            $("#edit-field-display-result-und-1").prop("checked", true);
                        }
                    }
                });
            });

            $('#edit-field-poll-question-und').change(function() {
                var queVal = $('#edit-field-poll-question-und').val();
                if (queVal == 2) { // Image question
                    $('#edit-field-poll-question-text-und-0-value').val('');
                    $('#edit-field-poll-question-video-und-0-remove-button').mousedown();
                } else if (queVal == 1) { // Text Question
                    $('#edit-field-poll-question-image-und-0-remove-button').mousedown();
                    $('#edit-field-poll-question-video-und-0-remove-button').mousedown();
                } else if (queVal == 3) { // Video question
                    $('#edit-field-poll-question-image-und-0-remove-button').mousedown();
                    $('#edit-field-poll-question-text-und-0-value').val('');
                }
            });

        }
    }
})(jQuery);