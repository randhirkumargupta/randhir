/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_widget = {
    attach: function(context, settings) {
        console.log(settings.itg_widget.data);
        if (settings.itg_widget.data) {
            var node_queue_id = settings.itg_widget.data;
            // for top stories widget
            if (node_queue_id == 1) {
                jQuery('#edit-qids').empty(); //remove all child nodes
                var newOption = jQuery('<option value="1" selected="selected">Top Stories</option>');
                jQuery('#edit-qids').append(newOption);
                jQuery('#edit-qids').trigger("chosen:updated");
                jQuery("#edit-actionnodequeue-add-action").val("Add To Top Story");
            }
            //jQuery("#edit-submit").attr("value", "Yes");
        }
    }

};