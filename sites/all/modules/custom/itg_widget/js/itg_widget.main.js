/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_widget = {
    attach: function(context, settings) {
        console.log(settings.itg_widget.data);
        // settings for entire widgets which is using nodequeue module as bulk operation
        if (settings.itg_widget.data) {
            var select_option = settings.itg_widget.data;
            jQuery('#edit-qids').empty(); // remove all child nodes
            var newOption = jQuery('<option value="' + select_option.qid + '" selected="selected">' + select_option.title + '</option>');
            jQuery('#edit-qids').append(newOption);
            jQuery('#edit-qids').trigger("chosen:updated");
        }
    }

};