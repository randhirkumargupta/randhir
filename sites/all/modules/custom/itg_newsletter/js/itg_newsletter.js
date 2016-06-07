/*
 * @file itg_newsletter.js
 */

(function($) {
  Drupal.behaviors.itg_newsletter = {
    attach: function(context, settings) {
      
        //Collect required variables
        var uid = settings.itg_newsletter.settings.uid;
        var base_url = settings.itg_newsletter.settings.base_url;
        var type = settings.itg_newsletter.settings.type;
        var nid = settings.itg_newsletter.settings.nid;
        
        if(nid) {
          $('#edit-field-newsl-add-news-und-0-remove-button').show();
        }
        
       //Hide left side vertical tabs in case of simple users
       if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
       }

     //Automatic and manual field hide and show
      if ($("input[name='field_newsl_newsletter_type[und]']:checked").val() === 'automatic') {
        
        $('#edit-field-newsl-schedule').hide();
        $('#edit-field-newsl-frequency').show();
        $('#edit-field-newsl-newsletter-content').show();
        $('.group-newsl-add-news').hide();
        $('.form-field-name-field-survey-start-date').hide();
        
        //Day, date and time
        if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'daily') {
          $('#edit-field-newsl-time').show();
          $('#edit-field-newsl-time-period').show();
          $('#edit-field-newsl-day').hide();
          $('#edit-field-newsl-date').hide();
        }
        else if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'weekly') {
          $('#edit-field-newsl-day').show();
          $('#edit-field-newsl-time').hide();
          $('#edit-field-newsl-time-period').hide();
          $('#edit-field-newsl-time-date').hide();
        }
        else {
          $('#edit-field-newsl-date').show();
          $('#edit-field-newsl-time').hide();
          $('#edit-field-newsl-time-period').hide();
          $('#edit-field-newsl-day').hide();
        }
      } 
      else {
          $('#edit-field-newsl-schedule').show();
          $('.group-newsl-add-news').show();
          $('#edit-field-newsl-time').show();
          $('.form-field-name-field-survey-start-date').show();
          $('#edit-field-newsl-frequency').hide();
          $('#edit-field-newsl-newsletter-content').hide();
          $('#edit-field-newsl-day').hide();
          $('#edit-field-newsl-date').hide();
          $('#edit-field-newsl-time-period').hide();
      }
      
      //Aautomatic and manual hide/show onclick
      $("input[name='field_newsl_newsletter_type[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        
        if (check_radio_name === 'automatic') {
          
          $('#edit-field-newsl-schedule').hide();
          $('.form-field-name-field-survey-start-date').hide();
          $('#edit-field-newsl-frequency').show();
          $('#edit-field-newsl-newsletter-content').show();
          $('.group-newsl-add-news').hide();
          
          //Day, date and time
          if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'daily') {
            $('#edit-field-newsl-time').show();
            $('#edit-field-newsl-time-period').show();
            $('#edit-field-newsl-day').hide();
            $('#edit-field-newsl-date').hide();
          }
          else if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'weekly') {
            $('#edit-field-newsl-day').show();
            $('#edit-field-newsl-time').show();
            $('#edit-field-newsl-time-period').show();
            $('#edit-field-newsl-time-date').hide();
          }
          else {
            $('#edit-field-newsl-date').show();
            $('#edit-field-newsl-time').show();
            $('#edit-field-newsl-time-period').show();
            $('#edit-field-newsl-day').hide();
          }
        } 
        else {
          $('#edit-field-newsl-schedule').show();
          if($("input[name='field_newsl_schedule[und]']:checked").val() === 'later'){alert('l');
            $('#edit-field-survey-start-date').show();
            $('#edit-field-newsl-time').show();
          } else {
            $('#edit-field-survey-start-date').hide();
            $('#edit-field-newsl-time').hide();
          }
          
          $('.group-newsl-add-news').show();
          $('#edit-field-newsl-frequency').hide();
          $('#edit-field-newsl-newsletter-content').hide();
          $('#edit-field-newsl-day').hide();
          $('#edit-field-newsl-date').hide();
          $('#edit-field-newsl-time-period').hide();
        }
      });
      
      //Day,date and time hide/show on click
      $("input[name='field_newsl_frequency[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        if (check_radio_name === 'daily') {
          $('#edit-field-newsl-time').show();
          $('#edit-field-newsl-time-period').show();
          $('#edit-field-newsl-day').hide();
          $('#edit-field-newsl-date').hide();
        }
        else if (check_radio_name === 'weekly') {
          $('#edit-field-newsl-day').show();
          $('#edit-field-newsl-time').show();
          $('#edit-field-newsl-time-period').show();
          $('#edit-field-newsl-date').hide();
        }
        else {
          $('#edit-field-newsl-date').show();
          $('#edit-field-newsl-time').show();
          $('#edit-field-newsl-time-period').show();
          $('#edit-field-newsl-day').hide();
        }
      });
      
      // Hide/show date and time using scheduler(Now/Later)
      if ($("input[name='field_newsl_schedule[und]']:checked").val() === 'later') {
        $('#edit-field-survey-start-date').show();
        $('#edit-field-newsl-time').show();
      } else {
        $('#edit-field-survey-start-date').hide();
        $('#edit-field-newsl-time').hide();
      }
      
      //Now and Later Hide show
      $("input[name='field_newsl_schedule[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        if (check_radio_name === 'later') {
          $('#edit-field-survey-start-date').show();
          $('#edit-field-newsl-time').show();
        }
        else {
          $('#edit-field-survey-start-date').hide();
          $('#edit-field-newsl-time').hide();
        }
      });
      
     //Read only newsletter date field
     if (type === 'Newsletter') {
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup-0, #edit-field-survey-start-date-und-0-value-datepicker-popup-1').prop("readonly", true);
      }
      
      //Get Newsletter data
      $('body').on('click', '.newsletter-get-content', function() {
        var contentId = $(this).parent().siblings('.field-name-field-news-cid').find('.form-text').val();
        var relval = $(this).attr('rel');
        
        if(contentId === ''){
          alert('Please select Content ID.');
          $(this).parent().siblings('.field-name-field-news-cid').find('.form-text').focus();
        } 
        else {
          var contentIdArr = contentId.split(' (');
          $.ajax({
           url: Drupal.settings.basePath + 'newsletter_data',
           type: "post",
           data: { content_id : contentIdArr[0] },
           cache: false,
           dataType: "JSON",
           success: function(data) {
              $('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-title').find('.form-text').val(data.title);
              $('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-kicker').find('.form-textarea').val(data.kicker);
              $('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-thumbnail').find('div.filefield-source-imce .form-text').attr('value', data.uri);
              $('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-thumbnail').find('div.filefield-source-imce .form-submit').triggerHandler('mousedown');
//              $('#edit-field-newsl-add-news-und-0-field-news-thumbnail-und-0-upload-imce-path').attr('value', data.uri);
//              $('#edit-field-newsl-add-news-und-0-field-news-thumbnail-und-0-upload-imce-select').triggerHandler('mousedown');
           },
            error: function() {
              return false;
            }
         });
        }
      });
  }
 };

})(jQuery, Drupal, this, this.document);