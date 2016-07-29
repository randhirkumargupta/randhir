/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_widget = {
    attach: function (context, settings) {
        //console.log(settings.itg_widget.data);
        // settings for entire widgets which is using nodequeue module as bulk operation
        if (settings.itg_widget.data) {
            var select_option = settings.itg_widget.data;
            jQuery('#edit-qids').empty(); // remove all child nodes
            var newOption = jQuery('<option value="' + select_option.qid + '" selected="selected">' + select_option.title + '</option>');
            jQuery('#edit-qids').append(newOption);
            jQuery('#edit-qids').trigger("chosen:updated");

            // Added code that hide node queue multiple select and add text next to this div
            jQuery('<p>Are you sure you want add this content</p>').insertAfter(jQuery('#views-form-photo-carousel-widget-photo-carousel-list , #views-form-story-widget-page-1').find('.form-item-qids'));
            jQuery('#views-form-photo-carousel-widget-photo-carousel-list,#views-form-story-widget-page-1').find('#edit-submit').val('Confirm');
            jQuery('#views-form-photo-carousel-widget-photo-carousel-list, #views-form-story-widget-page-1').find('.form-item-qids').hide();

            // End code that hide node queue multiple select and add text next to this div

        }


    }

};