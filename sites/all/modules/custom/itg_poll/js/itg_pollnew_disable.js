/*
 * @file itg_event_backend.js
 * Contains functionality related Poll
 */

(function($) {

    Drupal.behaviors.itg_poll_form_disable = {
        attach: function(context, settings) {

            $('.field-name-field-poll-answer-image .button-remove').remove();
            $('#edit-field-poll-answer-option').remove();
            $('#edit-field-poll-question').remove();
            $('.field-name-field-poll-answer-text input').attr('readonly', true);
            $('#edit-field-poll-question-image .button-remove').remove();
            $('.field-name-field-poll-manipulate-value').remove();

        }
    }
})(jQuery);