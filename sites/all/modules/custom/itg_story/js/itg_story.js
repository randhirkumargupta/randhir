/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
    Drupal.behaviors.itg_story = {
        attach: function(context, settings) {
            var uid = settings.itg_story.settings.uid;
            
            $('#edit-path-pathauto').click(function() {
              if ($("#edit-path-pathauto").is(":checked")) {                
                $("#edit-path-alias").attr('readonly', 'readonly');
              } else {                
                $("#edit-path-alias").removeAttr('readonly');
              }  
            });
            
            
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
            
            // code for lock story check uncheck based on condition
            $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function () {
                if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(":checked")) {
                    $(".form-item-field-story-configurations-und-lock-story").show('');
                    $('#edit-field-story-configurations-und-lock-story').attr('checked', true);
                }
                else {
                    $(".form-item-field-story-configurations-und-lock-story").hide('');
                    $('#edit-field-story-configurations-und-lock-story').attr('checked', false);
                }
            });


            if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(":checked")) {
                $(".form-item-field-story-configurations-und-lock-story").show('');
                $('#edit-field-story-configurations-und-lock-story').attr('checked', true);
            }
            else {
                $(".form-item-field-story-configurations-und-lock-story").hide('');
                $('#edit-field-story-configurations-und-lock-story').attr('checked', false);
            }
          

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
            
            
            // Code for tv field value set Null
            $('#edit-field-story-configurations-und-tv').click(function() {
                if ($("#edit-field-story-configurations-und-tv").is(":not(:checked)")) {
                    $("#edit-field-poll-start-date-und-0-value-datepicker-popup-0").val('');
                    $('[name="field_story_tv_time[und]"]').val('_none');
                }
            });
            
            
            // auto fill time when user remove time in expiry date field
            d = new Date();
            datetext = d.getHours() + ":" + d.getMinutes();
            $('#edit-field-story-expiry-date-und-0-value-timeEntry-popup-1').blur(function () {
                if ($("#edit-field-story-expiry-date-und-0-value-timeEntry-popup-1").val() == '') {
                    $("#edit-field-story-expiry-date-und-0-value-timeEntry-popup-1").val(datetext);
                }
            });
            
            
            // code for uncheck expiry date
                var newdate = new Date();
                newdate.setDate(newdate.getDate() + 7);
                var dd = newdate.getDate();
                var mm = newdate.getMonth() + 1;
                var yy = newdate.getFullYear();
                var someFormattedDate = mm + '/' + dd + '/' + yy;
                
            $('#edit-field-story-expires-und-yes').click(function () {
                if ($("#edit-field-story-expires-und-yes").is(":not(:checked)")) {
                    $("#edit-field-story-expiry-date-und-0-value-datepicker-popup-0").val(someFormattedDate);
                    $("#edit-field-story-expiry-date-und-0-value-timeEntry-popup-1").val(datetext);
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
            $('#edit-field-facebook-gallery-associate-und-0-remove-button').hide();

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
            
            // Code to create breaking news.
            $('#breaking_text').click(function () {
                var base_url = settings.itg_story.settings.base_url;
                var uid = settings.itg_story.settings.uid;
                var title = jQuery('#edit-title').val();
                if ($(this).is(':checked')) {
                    
                    var associate_id = $(this).attr('id');

                    if (associate_id == 'breaking_text') {
                        var msg = confirm("Are you sure you want to pubish long headline as breaking band?");
                    }

                    if (msg == true && title.length != 0) {
                        
                        var post_data = "&title=" + title + "&uid=" + uid;
                        $.ajax({
                            'url': base_url + '/breaking-news-ajax',
                            'data': post_data,
                            'cache': false,
                            'type': 'POST',
                            // dataType: 'json',
                            beforeSend: function () {
                                $('#widget-ajex-loader').show();
                            },
                            'success': function (result)
                            {
                                var obj = jQuery.parseJSON(result);

                                $('#widget-ajex-loader').hide();
                                console.log(obj.story_nid);
                                jQuery('#edit-field-story-source-id-und-0-value').val(obj.story_nid);
                            }
                        });
                        
                        return true;
                    }
                    
                    return false;
                }

            });


        }

    };


})(jQuery, Drupal, this, this.document);
