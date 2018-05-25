/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
    Drupal.behaviors.itg_story = {
        attach: function (context, settings) {
            var uid = settings.itg_story.settings.uid;
            var sef_url_access = settings.itg_story.settings.sef_url_access;
            console.log('sef_url_access = ' + sef_url_access);
            if (typeof (sef_url_access) != undefined && sef_url_access != null) {
                jQuery('#edit-path-pathauto').attr('disabled','disabled');
                jQuery('#edit-path-alias').attr('disabled','disabled');
            }
            var StoryId = settings.itg_story.settings.storyid;
            if (StoryId == 0) {
                // jquery to open question field.
                // jQuery("#edit-field-story-configurations-und-commentbox").trigger("click");

                // hide remove button of first field on add form
                jQuery("#edit-field-story-highlights-und-0-remove-button").hide();
                jQuery("#edit-field-story-template-buzz-und-0-remove-button").hide();
                jQuery("#edit-field-story-template-guru-und-0-remove-button").hide();
                jQuery("#edit-field-story-template-quotes-und-0-remove-button").hide();
                jQuery("#edit-field-story-template-factoids-und-0-remove-button").hide();
                jQuery("#edit-field-story-reporter-und-0-remove-button").hide();
            }
            //$("#edit-field-itg-content-publish-date").hide();
            $(".form-item-field-story-configurations-und-breaking-news").hide('');
            $("label[for='edit-field-story-configurations-und-tv']").html("Associate Story with TV");
            // enable check box of developing story based on condition 
            var longheadline = $('#edit-title').val();

            if (longheadline == '') {
                $('#breaking_text').prop("disabled", true);
            }

            $("#edit-title").on('keyup blur', function () {
                if (this.value != '') {
                    $('#edit-field-story-long-head-line-und-0-value').val(this.value);
                    $('#edit-field-story-short-headline-und-0-value').val(this.value);
                    $('#breaking_text').removeAttr('disabled');
                } else {
                    $('#breaking_text').prop('disabled', true);
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

            $('#edit-field-story-select-magazine-und').change(function () {
                $('.form-item-field-story-configurations-und-display-lock').show();
            });


            // Code for Magazine, Supplement and date field value set Null
            $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function () {
                if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(":not(:checked)")) {
                    $('#edit-field-story-configurations-und-display-lock').attr('checked', false);
                    $('.form-item-field-story-configurations-und-display-lock').hide();
                    $("#edit-field-story-select-magazine-und").val('_none');
                    $('[name="field_story_select_supplement[und]"]').val('_none');
                    $("#edit-field-story-issue-date-und-0-value-datepicker-popup-1").val('');
                    $("#edit-field-story-issue-date-und-0-value-datepicker-popup-0").val('');
                }
            });

            // Code for client Title field value set Null
            $('#edit-field-story-configurations-und-syndication').click(function () {
                if ($("#edit-field-story-configurations-und-syndication").is(":not(:checked)")) {
                    $("#edit-field-story-client-title-und-0-value").val('');
                    $('#edit-field-story-media-files-syndicat-und-yes').attr('checked', false);
                }
            });

            // code for lock story check uncheck based on condition
            $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function () {
                if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(":checked")) {
                    $('#edit-field-story-configurations-und-lock-story').attr('checked', true);
                } else {
                    $('#edit-field-story-configurations-und-lock-story').attr('checked', false);
                }
            });

            // Code for client Title field value set Null
            $('#edit-field-story-configurations-und-commentbox').click(function () {
                if ($("#edit-field-story-configurations-und-commentbox").is(":not(:checked)")) {
                    $("#edit-field-story-comment-question-und-0-value").val('');
                }
            });

            // Code for tv field value set Null
            $('#edit-field-story-configurations-und-tv').click(function () {
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
            $('#edit-field-story-social-media-integ-und-twitter').click(function () {
                if ($("#edit-field-story-social-media-integ-und-twitter").is(":not(:checked)")) {
                    $("#edit-field-story-tweet-und-0-value").val('');
                }
            });

            // Code for story expiry date field value set Null
            $('#edit-field-story-expires-und-yes').click(function () {
                if ($("#edit-field-story-expires-und-yes").is(":not(:checked)")) {
                    $("#edit-field-story-expiry-date").val('');
                }
            });

            $('#edit-field-facebook-gallery-associate-und-0-remove-button').hide();

            // Code issue date exit or not.
            // $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').blur(function () {
            $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').change(function () {
                var base_url = settings.itg_story.settings.base_url;
                $.ajax({
                    url: base_url + "/issue-date-check-ajax",
                    method: 'post',
                    data: { 'issue': $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').val() },
                    success: function (data) {
                        $("#idIssue").remove();
                        $(".form-item-field-story-issue-date-und-0-value-date").append(data);
                    }
                });
            });

            // handle issue checked on unchecked
            jQuery("#edit-field-story-magazine-story-issue-und-magazine-issue-story").click(function () {
                if (!jQuery(this).is(':checked')) {
                    jQuery("#edit-field-story-source-type-und-0-value").val("");
                }
            });			
            jQuery('.plupload_start').on('click', function () {
                $('#story-node-form').ajaxComplete(function (event, request, settings) {
                    if (jQuery('input[name="field_story_technology[und][0][field_technology_sample_photo][und][0][fid]"]').val() == 0) {
                        jQuery('.form-field-name-field-story-technology .field-multiple-table tbody tr:first .cancel').mousedown();
                        jQuery(this).off(event);
                    }
                });
            });
            // story discription iframe wrap in div
          //  var tagIframe = jQuery('.story-section .story-right .description');
           // tagIframe.find('iframe').removeAttr('height', 'width').wrap('<div class="iframe-video"></div>');
           // Code to Disable Submit button
           jQuery('.top-actions input[type="submit"]').click(function (){
               if(jQuery('.node-story-form').valid()){
                jQuery(this).css("background-color", "#d9d9d9"); 
                jQuery(this).css("border-color", "#d9d9d9");
                jQuery(this).parent().children().css( 'pointer-events', 'none' );
                jQuery(this).parent().children().last().css( 'pointer-events', 'auto' );
               }               
           });
           jQuery('.top-actions .published.btn-submit').click(function (){
               if(jQuery('.node-story-form').valid()){
                jQuery(this).css("background-color", "#d9d9d9"); 
                jQuery(this).css("border-color", "#d9d9d9");
                jQuery(this).parent().children().css( 'pointer-events', 'none' );
                jQuery(this).parent().children().last().css( 'pointer-events', 'auto' );
               }               
           });
           jQuery('.itg-form-action .form-actions input[type="submit"]').click(function (){
               if(jQuery('.node-story-form').valid()){
                jQuery(this).css("background-color", "#d9d9d9"); 
                jQuery(this).css("border-color", "#d9d9d9"); 
                jQuery(this).parent().children().css( 'pointer-events', 'none' );
                jQuery(this).parent().children().last().css( 'pointer-events', 'auto' );
               }               
           });
           jQuery('.itg-form-action .form-actions .published.btn-submit').click(function (){
               if(jQuery('.node-story-form').valid()){
                jQuery(this).css("background-color", "#d9d9d9"); 
                jQuery(this).css("border-color", "#d9d9d9"); 
                jQuery(this).parent().children().css( 'pointer-events', 'none' );
                jQuery(this).parent().children().last().css( 'pointer-events', 'auto' );
               }               
           });
        }

    };


})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function () {
    // Code to create breaking news.
    jQuery('#breaking_text').click(function () {
        var title = jQuery('#edit-title').val();
        if (jQuery(this).is(':checked')) {

            var associate_id = jQuery(this).attr('id');

            if (associate_id == 'breaking_text') {
                var msg = confirm("Are you sure you want to publish long headline as breaking band?");
            }

            if (msg == true && title.length != 0) {
                var post_data = "&title=" + title;
                jQuery.ajax({
                    'url': Drupal.settings.baseUrl.baseUrl + '/breaking-news-ajax',
                    'data': post_data,
                    'cache': false,
                    'type': 'POST',
                    beforeSend: function () {
                        jQuery('#widget-ajex-loader').show();
                    },
                    'success': function (result) {
                        var obj = jQuery.parseJSON(result);
                        jQuery('#edit-field-story-configurations-und-breaking-news').attr('checked', true);
                        jQuery('#widget-ajex-loader').hide();
                        jQuery('#breaking_text').attr('checked', true);
                        jQuery('#edit-field-story-source-id-und-0-value').val(obj.story_nid);
                        jQuery('#edit-field-story-source-type-und-0-value').val('breaking');
                    }
                });

                return true;
            }

            return false;
        }

    });
});

