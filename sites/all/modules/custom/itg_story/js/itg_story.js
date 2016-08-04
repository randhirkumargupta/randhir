/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
    Drupal.behaviors.itg_story = {
        attach: function(context, settings) {
            var uid = settings.itg_story.settings.uid;
            jQuery('input[name="field_story_schedule_date_time[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_story_expiry_date[und][0][value][date]"]').keydown(false);
            if (uid != 1) {
                $('.field-edit-link').hide();
                var magazine = $('#edit-field-story-select-magazine-und').val();

                if (magazine == '_none') {
                    $('.form-item-field-story-configurations-und-display-lock').hide();
                }

                $('#edit-body-und-0-format').hide();
                $('#edit-field-story-archive').hide();
                $('#edit-path').show();
            }

            $('#edit-field-story-select-magazine-und').change(function() {
                $('.form-item-field-story-configurations-und-display-lock').show();
            });


            // Code for Magazine, Supplement and date field value set Null
            $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function() {
                if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(":not(:checked)")) {
                    $('#edit-field-story-configurations-und-display-lock').attr('checked', false);
                    $('.form-item-field-story-configurations-und-display-lock').hide();
                    $("#edit-field-story-select-magazine-und").val('_none');
                    $('[name="field_story_select_supplement[und]"]').val('_none');
                    $("#edit-field-story-issue-date-und-0-value-datepicker-popup-1").val('');
                }
            });

            // Code for client Title field value set Null
            $('#edit-field-story-configurations-und-syndication').click(function() {
                if ($("#edit-field-story-configurations-und-syndication").is(":not(:checked)")) {
                    $("#edit-field-story-client-title-und-0-value").val('');
                    $('#edit-field-story-media-files-syndicat-und-yes').attr('checked', false);
                }
            });

            // Code for client Title field value set Null
            $('#edit-field-story-configurations-und-comment').click(function() {
                if ($("#edit-field-story-configurations-und-comment").is(":not(:checked)")) {
                    $("#edit-field-story-comment-question-und-0-value").val('');
                }
            });

            // Code for facebook field value set Null
            $('#edit-field-story-social-media-integ-und-facebook').click(function() {
                if ($("#edit-field-story-social-media-integ-und-facebook").is(":not(:checked)")) {
                    $("#edit-field-story-facebook-narrative-und-0-value").val('');
                }
            });

            // Code for tweet field value set Null
            $('#edit-field-story-social-media-integ-und-twitter').click(function() {
                if ($("#edit-field-story-social-media-integ-und-twitter").is(":not(:checked)")) {
                    $("#edit-field-story-tweet-und-0-value").val('');
                }
            });

            // Code for story expiry date field value set Null
            $('#edit-field-story-expires-und-yes').click(function() {
                if ($("#edit-field-story-expires-und-yes").is(":not(:checked)")) {
                    $("#edit-field-story-expiry-date").val('');
                }
            });

            // code to copy story longheadline to story title
            $('#edit-title').on('keyup keypress blur change', function(e) {
                $('#edit-field-story-long-head-line-und-0-value').val($('#edit-title').val());
            });

            $('#edit-title').on('keyup keypress blur change', function(e) {
                $('#edit-field-story-short-headline-und-0-value').val($('#edit-title').val());
            });

            $('#edit-field-story-long-head-line-und-0-value').val($('#edit-title').val());
            $('#edit-field-story-short-headline-und-0-value').val($('#edit-title').val());


            // Display Byline details
            $('#edit-field-story-reporter-und-0-target-id').blur(function() {
                var base_url = settings.itg_story.settings.base_url;
                $.ajax({
                    url: base_url + "/reporter-details-ajax",
                    method: 'post',
                    data: {'reporter_id': $('#edit-field-story-reporter-und-0-target-id').val()},
                    success: function(data) {
                        $('#reporter-details').html(data);
                    }
                });
            });
            jQuery('.add-to-dropbox').mousedown(function()
            {
                var selectvalue = jQuery('.selects > .form-select:last option:selected').val();
                var comptext = "";
                var makeradio = "";
                var flag = 0;
                if (selectvalue != "")
                {
                    jQuery('.selects > .form-select').each(function()
                    {
                        var getid = jQuery(this).attr('id');
                        var selopttext = jQuery('#' + getid + ' option:selected').text();
                        var selval = jQuery('#' + getid + ' option:selected').val();
                        if (selval.indexOf("label") != 0)
                        {
                            comptext = comptext + selopttext + '›';
                        }

                    })
                    comptext = comptext.slice(0, -1);
                    jQuery('.primary_cat').each(function()
                    {
                        var existvalue = jQuery(this).val();
                        if (selectvalue == existvalue)
                        {
                            flag = 1;
                        }

                    })
                    if (comptext != "" && flag == 0)
                    {
                        makeradio = '<input type="radio" name="primary_category" class="primary_cat" value="' + selectvalue + '">' + comptext;
                        jQuery('.append_primary').append(makeradio);
                        jQuery('.primary_cat').each(function() {
                            if(jQuery(this).is(':checked'))
                            {
                                jQuery(this).trigger('click');
                            }
                        })

                    }
                }

            })
            jQuery('.primary_cat').click(function()
            {
                var gethtml = jQuery('.append_primary').html();
                jQuery('#primary_cat_html').val(gethtml);

            })

            // Code issue date exit or not.
            $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').blur(function() {
                var base_url = settings.itg_story.settings.base_url;
                $.ajax({
                    url: base_url + "/issue-date-check-ajax",
                    method: 'post',
                    data: {'issue': $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').val()},
                    success: function(data) {
                        $("#idIssue").remove();
                        $(".form-item-field-story-issue-date-und-0-value-date").append(data);
                    }
                });
            });


        }

    };

    function filterhtml()
    {
        
    }
})(jQuery, Drupal, this, this.document);
