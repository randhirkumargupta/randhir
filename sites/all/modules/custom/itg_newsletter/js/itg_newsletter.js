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
        $('.group-newsl-add-news').show();
        $('#edit-field-newsl-frequency').hide();
        $('#edit-field-newsl-newsletter-content').hide();
        $('#edit-field-newsl-time').hide();
        $('#edit-field-newsl-day').hide();
        $('#edit-field-newsl-date').hide();
        $('#edit-field-newsl-time-period').hide();
      }
      
      //Aautomatic and manual hide/show onclick
      $("input[name='field_newsl_newsletter_type[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        if (check_radio_name === 'automatic') {
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
          $('.group-newsl-add-news').show();
          $('#edit-field-newsl-frequency').hide();
          $('#edit-field-newsl-newsletter-content').hide();
          $('#edit-field-newsl-time').hide();
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
          $('#edit-field-newsl-time').hide();
          $('#edit-field-newsl-time-period').hide();
          $('#edit-field-newsl-date').hide();
        }
        else {
          $('#edit-field-newsl-date').show();
          $('#edit-field-newsl-time').hide();
          $('#edit-field-newsl-time-period').hide();
          $('#edit-field-newsl-day').hide();
        }
      });
      
      //Inline validation
       $("#newsletter-node-form").validate({
        submitHandler: function (form) {
          $('input:submit').attr('disabled', 'disabled');
          form.submit();
        },
        onfocusout: function (element) {
          $(element).valid();
        },
        ignore: '',
        errorElement: 'span',
        errorPlacement: function (error, element) {
          var elementName = element.attr('name');
          var errorPlaceHolder = '';
          switch (elementName) {
            
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: {
          'field_newsl_frequency[und]': {
            required: {
              depends: function() {
                var answerType = $("input[name='field_newsl_newsletter_type[und]']:checked").val();
                if (answerType === 'automatic') {
                  return true;
                }
                else {
                  return false;
                }
              }
            }
          }
        },
                
        messages: {
          'field_newsl_frequency[und]': {
            required: 'Frequency field is required.'
          }
        }
      });
    
    }
 };
})(jQuery, Drupal, this, this.document);