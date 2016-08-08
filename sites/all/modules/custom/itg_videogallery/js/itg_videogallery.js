/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */

(function($) {
    Drupal.behaviors.itg_videogallery = {
        attach: function(context, settings) {
            var uid = settings.itg_videogallery.settings.uid;
            jQuery('input[name="field_story_schedule_date_time[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_story_expiry_date[und][0][value][date]"]').keydown(false);
            if (uid != 1) {
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();
                $('.fieldset-description').hide();
                $('#edit-metatags p').hide();
            }

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
            $('#edit-title').blur(function() {
                $('#edit-field-story-long-head-line-und-0-value').val($('#edit-title').val());
            });

            $('#edit-title').blur(function() {
                $('#edit-field-story-short-headline-und-0-value').val($('#edit-title').val());
            });
            $('.plupload_container').removeAttr("title");
            // Display Byline details
            $('#edit-field-story-reporter-und-0-target-id').blur(function() {
                var base_url = Drupal.settings.basePath;
                $.ajax({
                    url: base_url + "/reporter-details-ajax",
                    method: 'post',
                    data: {'reporter_id': $('#edit-field-story-reporter-und-0-target-id').val()},
                    success: function(data) {
                        $('#reporter-details').html(data);
                    }
                });
            });

            // - multi checkbox ftp 
            /*$('.browse-ftp a').click(function() {
                var ids = [];
                $('#edit-video-browse-select .form-checkbox').each(function() {
                    if ($(this).is(':checked'))
                    {
                        ids.push($(this).val());
                    }
                })
                var count = ids.length;
                $('#edit-field-videogallery-video-upload-add-more-number').val(count);
                $('input[name=field_videogallery_video_upload_add_more]').mousedown();
                setTimeout(function() {
                    $('#edit-field-videogallery-video-upload-add-more-number').val(1);
                    $('#edit-video-browse-select .form-checkbox').prop('checked', false);
                }, 1000);
            });*/

            // end code
            $('document').ready(function(){
                var old_vid = $("input[name='field_upload_video[und][0][fid]']").val();
                if(old_vid != 0){
                    $("input['files[field_upload_video_und_0]']").hide();
                    $("#edit-field-upload-video-und-0-upload-button").hide();
      
                   //window.alert('Please remove exist video file.');
                   $('.vid-error').text('Please remove exist video file.');
                   setTimeout(function() {
                    $('.vid-error').fedout('');
                }, 6000);
            }
            });
            $("input[name='field_upload_video[und][0][fid]']").val();
            
            
            
            $('.browse-ftp').hide();
            $('.browse-ftp-click').click(function() {
               var old_vid = $("input[name='field_upload_video[und][0][fid]']").val(); 
               if(old_vid != 0){
                   //window.alert('Please remove exist video file.');
                   $('.vid-error').text('Please remove exist video file.');
                   setTimeout(function() {
                    $('.vid-error').fedout('');
                }, 6000);    
               }else{
                  var data = $('.browse-ftp').html();
                    $.colorbox({html: "" + data + "",onComplete : function() { 
                        $(this).colorbox.resize(); 
                     }  });
               }
            });
            $('.browse-ftp a').click(function() {
                var vid = $('#edit-video-browse-select .form-radio').val();
                $("input[name='input[name='field_upload_video[und][0][fid]']").val(vid); 
                $("#edit-field-upload-video-und-0-upload-button").mousedown();
                
                setTimeout(function() {
                    $('#edit-video-browse-select .form-radio').prop('checked', false);
                }, 1000);
            });
        }

    };
})(jQuery, Drupal, this, this.document);
