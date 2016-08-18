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
            // FTP browse js
            $('document').ready(function(){
                var old_vid = $("input[name='field_upload_video[und][0][fid]']").val();
                if(old_vid == 0){
                    $("#edit-field-upload-video-und-0-upload").hide();
                    $("#edit-field-upload-video-und-0-upload-button").hide();
                }else{
                    $(".browse-ftp-click").hide();
                }
            });           
            
            
            $('.browse-ftp').hide();
           
            $('.ftp-server a').click(function() {
                var vid = $('#edit-video-browse-select .form-radio:checked').val();
                if(vid !== "" && !$.isNumeric(vid)){
                    alert('Please select video file.');
                } else {
                $("input[name='field_upload_video[und][0][fid]']").val(vid);
                $("#edit-field-upload-video-und-0-upload-button").mousedown();
                $.colorbox.close();
                setTimeout(function() {
                    $('#edit-video-browse-select .form-radio').prop('checked', false);
                }, 1000);
            }
            });
              // popup show hide
            $(".video-local").click(function(){
                $(".local_browse").show();
                $(".ftp-server").hide();
                $('.video-ftp').removeClass('active');
                 $(this).addClass('active');
            });
            $(".video-ftp").click(function(){
                $(".local_browse").hide();
                $(".ftp-server").show();
                $(this).addClass('active');
                 $('.video-local').removeClass('active');
                 $('.used-unused-select').val('used');
                  $('.used-unused-select').trigger('change');

            });
            $(".browse-local").click(function(){
                $("#edit-field-upload-video-und-0-upload").show();
                $("#edit-field-upload-video-und-0-upload-button").show();
                $("#edit-field-upload-video-und-0-upload").trigger('click');
                $("#edit-field-upload-video-und-0-upload").change(function(){
                    $("#edit-field-upload-video-und-0-upload-button").mousedown();
                    $.colorbox.close();
                }); 
            });
            // check ajax upload button

            $('#videogallery-node-form').ajaxComplete(function(event,request, settings) {
                if (form_build_id = settings.url.match(/file\/ajax\/field_upload_video\d*\/(.*)$/)) {
                 
                    if($('#videogallery-node-form').find("input[name='field_upload_video_und_0_remove_button']").val()=='Remove') {
                        $(".browse-ftp-click").hide(); 
                        
                       
                    }else {
                       
                      $(".browse-ftp-click").show();
                      $("input[name='field_video_duration[und][0][value]']").val('');
                    }
                }
               
           });           
        }

    };
})(jQuery, Drupal, this, this.document);

jQuery('document').ready(function(){
     jQuery('.browse-ftp-click').click(function() {
               var old_vid = jQuery("input[name='field_upload_video[und][0][fid]']").val(); 
               if(old_vid != 0){
  
               }else{
                   jQuery('.video-ftp').trigger('click');
                  jQuery('.video-local').removeClass('active');
                 jQuery('.used-unused-select').val('used');
                  jQuery('.used-unused-select').trigger('change');
                  var data = jQuery('.browse-ftp').html();
                //  jQuery.colorbox({width: "80%", height: "80%",fixed: true});
                    jQuery.colorbox({html: "" + data + "", width: "80%", height: "80%",fixed: true, onComplete : function() { 
                        
                     }  });
               }
            });
});

// new code
jQuery('document').ready(function(){
jQuery('.used-unused-select').live('change',function(){
   jQuery('#loader-data img').show();
    var select_value = jQuery(this).val();
     jQuery.ajax({
            url: 'http://localhost/itg-new-work/dailymotion-ftp-videos-post',
            type: 'post',
            data: {'case': select_value},
            success: function(data) {
              jQuery('#loader-data img').hide();
              jQuery('.video-options-wrapper').html(data);
              
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    
  });
  });
 