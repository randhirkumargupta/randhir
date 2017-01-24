/*
 * @file itg_byline.js
 * Contains all functionality related to Flag Management
 */

(function ($) {
    Drupal.behaviors.itg_byline = {
        attach: function (context, settings) {
            var uid = settings.itg_byline.settings.uid;
            var base_url = settings.itg_byline.settings.base_url;
            jQuery('body').find(".byline-ul").sortable();
            jQuery('body').find(".byline-ul").disableSelection();
            var listLength = jQuery('.byline-ul li').length;
            console.log(listLength);
            if (listLength <= 1) {
                jQuery('.save-byline').hide();
            }
            // jquery for front user activity
            $('.multi-byline').click(function (event) {
                console.log(jQuery(this).val());
                var nd_id = jQuery('#edit-field-story-reporter-und-0-target-id').val();
                var unique_id = jQuery('#edit-field-reporter-unique-id-und-0-value').val();
                byline_event = 'unpublish';
                var post_data = "&nd_id=" + nd_id + "&unique_id=" + unique_id + "&byline_event=" + byline_event;

                $.ajax({
                    'url': base_url + '/multibyline-save',
                    'data': post_data,
                    'cache': false,
                    'type': 'POST',
                    // dataType: 'json',
                    beforeSend: function () {
                        jQuery('#widget-ajex-loader').show();
                    },
                    'success': function (result)
                    {
                        var obj = jQuery.parseJSON(result);
                        if (obj.msg == 'success') {
                            jQuery('.byline-ul').append(obj.lnk);
                            jQuery('#edit-field-story-reporter-und-0-target-id').val('');
                            var listLength = jQuery('.byline-ul').find('li').length;
                            if (listLength > 0) {
                                console.log('add' + listLength);
                                jQuery('.save-byline').show();
                            }
                            else
                            {
                                jQuery('.save-byline').hide();
                            }
                        }
                        if (obj.msg == 'error') {

                        }
                        jQuery('#widget-ajex-loader').hide();
                    }
                });

            });

            $('body').on('click', '.byline_publish', function (event) {
                var nd_id = jQuery(this).val();
                var bl_id = jQuery(this).attr('data-tag');
                var unique_id = jQuery('#edit-field-reporter-unique-id-und-0-value').val();
                var status = '0';
                //byline_event = 'publish';
                if (jQuery(this).is(":checked")) {
                    status = '1';
                    byline_event = 'publish';
                }
                var post_data = "&nd_id=" + nd_id + "&unique_id=" + unique_id + "&byline_event=" + byline_event + "&status=" + status + "&bl_id=" + bl_id;

                $.ajax({
                    'url': base_url + '/multibyline-save',
                    'data': post_data,
                    'cache': false,
                    'type': 'POST',
                    // dataType: 'json',
                    beforeSend: function () {

                    },
                    'success': function (result)
                    {
                        var obj = jQuery.parseJSON(result);
                        if (obj.msg == 'success') {

                        }
                        if (obj.msg == 'error') {

                        }

                    }
                });

            });


            // code for remove byline
            $('body').on('click', '.remove-byline', function (event) {
                console.log(jQuery(this).attr('data-tag'));
                var nd_id = jQuery(this).attr('data-tag');
                var byline_nid = jQuery(this).attr('data-val');
                byline_event = 'remove';
                byline_id = jQuery('#edit-field-reporter-publish-id-und-0-value').val().split(",");
                var post_data = "&nd_id=" + nd_id + "&byline_event=" + byline_event;

                $.ajax({
                    'url': base_url + '/multibyline-save',
                    'data': post_data,
                    'cache': false,
                    'type': 'POST',
                    beforeSend: function () {
                        jQuery('#widget-ajex-loader').show();
                    },
                    'success': function (result)
                    {
                        var obj = jQuery.parseJSON(result);
                        if (obj.msg == 'delete') {
                            console.log(obj.byline);
                            jQuery('#' + obj.byline).remove();
                        }
                        var listLength = jQuery('.byline-ul').find('li').length;

                        if (listLength > 0) {
                            console.log('remove' + listLength);
                            jQuery('.save-byline').show();
                        }
                        else
                        {
                            jQuery('.save-byline').hide();
                        }
                        byline_id.splice($.inArray(byline_nid, byline_id), 1);
                        jQuery('#edit-field-reporter-publish-id-und-0-value').val(byline_id);
                        jQuery('#widget-ajex-loader').hide();
                    }
                });

            });


            // end here
        }

    };
})(jQuery, Drupal, this, this.document);

// byline order reorder
jQuery('body').on('click', '.save-byline', function () {
    console.log('click');
    var item = [];

    jQuery(this).closest('.byline-list').find('.byline-ul li').each(function (i) {
        item.push(jQuery(this).find('.byline_publish').val());
    });
    jQuery('#edit-field-reporter-publish-id-und-0-value').val(item);
    alert('Changes made successfully');
});