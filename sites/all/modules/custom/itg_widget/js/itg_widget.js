/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_widgets = {
    attach: function(context, settings) {

        jQuery(".remove_from_nodequeue_draggable_view").click(function() {
            var nid = jQuery(this).attr("data-nid");
            var qid = jQuery(this).attr("data-queueid");
            var view_name = jQuery(this).attr("data-view");
            var view_page = jQuery(this).attr("data-page");
            // get query parameter
            var c_tid = get_url_parameter('field_story_category_tid');
            var type = get_url_parameter('type');
            if (typeof (c_tid) != "undefined" && c_tid !== null && typeof (type) != "undefined" && type !== null) {
                if (confirm('Are you sure you want to move this content ?')) {
                    jQuery.get("remove_from_widgets_section/" + nid + "/" + qid + "/" + view_name + "/" + view_page + "/" + c_tid + "/" + type, function(data, status) {
                        if (data == 'deleted') {
                            //window.location.reload();
                        }
                    });
                }
                console.log("section and type found");
            } else {
                if (confirm('Are you sure you want to move this content ?')) {
                    jQuery.get("remove_from_widgets/" + nid + "/" + qid + "/" + view_name + "/" + view_page, function(data, status) {

                        if (data == 'deleted') {
                            window.location.reload();

                        }
                        window.location.reload();
                    });
                }
            }
        });
        
        jQuery(".widgets-view .view-link").parent().attr("target","_blank");
        //jQuery(".widgets-view .view-link").css("text-transform","capitalize");
        
        jQuery(".view-section-wise-content-ordering-list span.move-link").on('click', function() {
            if (confirm("Are you sure you want to move this content ?")) {
                return true;
            }
            else {
                return false;
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
