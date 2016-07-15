/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_widget = {
    attach: function(context, settings) {
        //console.log(settings.itg_widget.data);
        // settings for entire widgets which is using nodequeue module as bulk operation
        if (settings.itg_widget.data) {
            var select_option = settings.itg_widget.data;
            console.log(select_option.qid);
//            if (jQuery("li").hasClass("nodequeue-ajax-toggle nodequeue-toggle-q-" + select_option.qid)) {
//                //alert("test");
//                jQuery('li.nodequeue-ajax-toggle.nodequeue-toggle-q-' + select_option.qid).siblings().remove();
//                jQuery('li.nodequeue-ajax-toggle.nodequeue-toggle-q-' + select_option.qid).find('a.toggle-remove').siblings().remove();
//                jQuery('li.nodequeue-ajax-toggle a.toggle-remove').html('<span class="delete-link">delete</span>');
//                jQuery('li.nodequeue-ajax-toggle a.toggle-remove').click(function() {
//                    window.location.reload();
//                });
//            }
            jQuery('#edit-qids').empty(); // remove all child nodes
            var newOption = jQuery('<option value="' + select_option.qid + '" selected="selected">' + select_option.title + '</option>');
            jQuery('#edit-qids').append(newOption);
            jQuery('#edit-qids').trigger("chosen:updated");
        }

        jQuery(".remove_from_nodequeue_draggable_view").click(function() {
            var nid = jQuery(this).attr("data-nid");
            var qid = jQuery(this).attr("data-queueid");
            var view_name = jQuery(this).attr("data-view");
            var view_page = jQuery(this).attr("data-page");
            // get query parameter
            var c_tid = get_url_parameter('field_story_category_tid');
            var type = get_url_parameter('type');
            if (typeof (c_tid) != "undefined" && c_tid !== null && typeof (type) != "undefined" && type !== null) {
                if (confirm('Are you sure ?')) {
                    jQuery.get("remove_from_widgets_section/" + nid + "/" + qid + "/" + view_name + "/" + view_page + "/" + c_tid + "/" + type, function(data, status) {
                        if (data == 'deleted') {
                            window.location.reload();
                        }
                    });
                }
                console.log("section and type found");
            } else {
                if (confirm('Are you sure ?')) {
                    jQuery.get("remove_from_widgets/" + nid + "/" + qid + "/" + view_name + "/" + view_page, function(data, status) {
                        if (data == 'deleted') {
                            window.location.reload();
                        }
                        console.log("section and type not found");
                    });
                }
            }

        });
    }

};


var get_url_parameter = function get_url_parameter(sParam) {
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
            sURLVariables = sPageURL.split('&'),
            sParameterName,
            i;
    for (i = 0; i < sURLVariables.length; i++) {
        sParameterName = sURLVariables[i].split('=');

        if (sParameterName[0] === sParam) {
            return sParameterName[1] === undefined ? true : sParameterName[1];
        }
    }
};