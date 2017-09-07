/*
 * @file itg_magazine_supplement_listing.js
 * Contains all functionality related to itg_magazine_supplement_listing functionality
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_common = {
        attach: function (context, settings) {
            var base_url = settings.itg_common.settings.base_url;
            //code for magazine callback
            jQuery('#edit-field-story-select-magazine-target-id-wrapper').css("display", "none");
            jQuery('#edit-field-story-select-supplement-target-id-wrapper').css("display", "none");
            jQuery('#edit-field-story-issue-date-value-wrapper').css("display", "none");
            
            jQuery('#edit-list-magazine', context).change(function (event) {

                var magazine = $("#edit-list-magazine").val();

                var post = "&magazine=" + magazine;

                jQuery.ajax({
                    'url': base_url + '/get-magazine-issue',
                    'data': post,
                    'type': 'POST',
                    // dataType: 'json',
                    'success': function (data)
                    {

                        $('#edit-list-issue').html(data);

                    }
                });

            });
            
            
            jQuery('#edit-list-issue', context).change(function (event) {

                var issue = $("#edit-list-issue").val();

                var post = "&issue=" + issue;

                jQuery.ajax({
                    'url': base_url + '/get-supplement-issue',
                    'data': post,
                    'type': 'POST',
                    // dataType: 'json',
                    'success': function (data)
                    {

                        $('#edit-list-supplement').html(data);

                    }
                });

            });

        }
    };


})(jQuery, Drupal, this, this.document);