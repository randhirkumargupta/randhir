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
                    jQuery("#widget-ajex-loader").css("display", "block");
                    jQuery.get("remove_from_widgets_section/" + nid + "/" + qid + "/" + view_name + "/" + view_page + "/" + c_tid + "/" + type, function(data, status) {
                        if (data == 'deleted') {
                            //window.location.reload();
                        }
                    });
                }
                console.log("section and type found");
            } else {
                if (confirm('Are you sure you want to move this content ?')) {
                    jQuery("#widget-ajex-loader").css("display", "block");
                    jQuery.get("remove_from_widgets/" + nid + "/" + qid + "/" + view_name + "/" + view_page, function(data, status) {

                        if (data == 'deleted') {
                            window.location.reload();

                        }
                        window.location.reload();
                    });
                }
            }
        });

        jQuery(".add-so-sorry-extra-data").click(function() {
            var extra_type = jQuery(this).val();
            var nid = jQuery(this).attr('data-nid');
            window.location.replace("add-so-sorry-extra-data/" + nid + "/" + extra_type);
            jQuery("#widget-ajex-loader").css("display", "block");
        });

        jQuery(".remove-so-sorry-extra-data").click(function() {
            jQuery("#widget-ajex-loader").css("display", "block");
        });

        // This code use form check/uncheck all check box function
        jQuery('.widgets-view .vbo-table-select-all').click(function() {

            var mainids = [];
            var formid = jQuery("input[name='form_id']").val();
            if (jQuery(this).is(':checked'))
            {
                type = 'ADD';

            }
            else {
                type = 'REMOVE';
            }

            jQuery('.vbo-select').each(function() {
                var checkids = jQuery(this).val();
                mainids.push(jQuery(this).val());
                if (type == 'ADD')
                {
                    if (!jQuery(this).is(':checked'))
                    {
                        jQuery('.nodes_id_container').append('<span id="spn_' + checkids + '" class="content-ids">' + checkids + '<a class="removeid" cid="' + checkids + '" href="javascript:void(0)">X</a></span>');
                    }
                } else {
                    jQuery('#spn_' + checkids).remove();
                }
            })
            jQuery.ajax({
                url: Drupal.settings.basePath + 'setids',
                type: 'post', beforeSend:
                        function() {
                            jQuery('#widget-ajex-loader').show();

                        },
                data: {'checkid': mainids, 'formid': formid, 'type': type},
                success: function(data) {
                    setTimeout(function() {

                        jQuery('#widget-ajex-loader').hide();

                    }, 500);

                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });
        });

//This code use remove ids functionality from top 

        jQuery('.widgets-view .removeid').live('click', function() {
            var getids = jQuery(this).attr('cid');
            jQuery(this).parent().remove();
            jQuery('.vbo-select').each(function() {
                if (jQuery(this).val() == getids)
                {
                    jQuery(this).attr('checked', false);

                }

            })
            var formid = jQuery("input[name='form_id']").val();
            var type = 'REMOVE';
            jQuery.ajax({
                url: Drupal.settings.basePath + 'setids',
                type: 'post', beforeSend:
                        function() {
                            jQuery('#widget-ajex-loader').show();
                            jQuery(".vbo-select").attr("disabled", true);
                        },
                data: {'checkid': getids, 'formid': formid, 'type': type},
                success: function(data) {
                    setTimeout(function() {

                        jQuery('#widget-ajex-loader').hide();
                        jQuery(".vbo-select").attr("disabled", false);
                    }, 500);

                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });

        })

//This code use add ids functionality from top 

        jQuery('.widgets-view .vbo-select').click(function() {
            var formid = jQuery("input[name='form_id']").val();
            var checkids = jQuery(this).val();
            if (jQuery(this).is(':checked'))
            {
                type = 'ADD';
                jQuery('.nodes_id_container').append('<span id="spn_' + checkids + '" class="content-ids">' + checkids + '<a class="removeid" cid="' + checkids + '" href="javascript:void(0)">X</a></span>');

            }
            else {
                type = 'REMOVE';
                jQuery('#spn_' + checkids).remove();
            }

            jQuery.ajax({
                url: Drupal.settings.basePath + 'setids',
                type: 'post', beforeSend:
                        function() {
                            jQuery('#widget-ajex-loader').show();
                            jQuery(".vbo-select").attr("disabled", true);
                        },
                data: {'checkid': checkids, 'formid': formid, 'type': type},
                success: function(data) {
                    setTimeout(function() {

                        jQuery('#widget-ajex-loader').hide();
                        jQuery(".vbo-select").attr("disabled", false);
                    }, 500);

                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });
        });


        jQuery(".widgets-view .view-link").parent().attr("target", "_blank");
        //jQuery(".widgets-view .view-link").css("text-transform","capitalize");

        jQuery(".view-section-wise-content-ordering-list span.move-link , .view-at-section-wise-content-ordering-list span.move-link").on('click', function() {
            if (confirm("Are you sure you want to remove this content ?")) {
                return true;
            }
            else {
                return false;
            }
        });

        jQuery(".view-display-id-poll_widget_list span.move-link").on('click', function() {
            if (confirm("Are you sure you want to remove this content ?")) {
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


jQuery(document).ready(function() {
    jQuery(".custom-weight-draggable input[type=number]").change(function(){
        jQuery(this).next().children().find('option').remove().end().append('<option value="'+jQuery(this).val()+'">'+jQuery(this).val()+'</option>').val(jQuery(this).val());
    });
});