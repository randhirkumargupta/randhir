/*
 * @file itg_recipe.js
 * Contains all functionality related to Recipe
 */


(function($) {
    Drupal.behaviors.itg_recipe = {
        attach: function(context, settings) {
             $('#edit-field-recipe-content-type-und').change(function() {
                var queVal = $('#edit-field-recipe-content-type-und').val();
                if (queVal == 'Audio') { // Image question
                     $('#edit-field-recipe-video-und-0-remove-button').mousedown();
                } else if (queVal == 'Video') { // Text Question
                    $('#edit-field-recipe-audio-und-0-remove-button').mousedown();
                } else if(queVal == 'Text'){
                    $('#edit-field-recipe-audio-und-0-remove-button').mousedown();
                    $('#edit-field-recipe-video-und-0-remove-button').mousedown();
                }
            });
            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            var uid = settings.itg_recipe.settings.uid;
            if (uid != 1) {
                $('#edit-body-und-0-format').hide();
                $('#edit-field-recipe-description-und-0-format').hide();
                $('#edit-metatags').show();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags-und-advanced').hide();
            }
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
            $("#cooking-tips-node-form").validate({
        onfocusout: function (element) {
          $(element).valid();
        },
        onclick: function (element) {
          $(element).valid();
        },
        ignore: '',
        errorElement: 'span',
     
    });  
    
      $("#food-news-node-form").validate({
        onfocusout: function (element) {
          $(element).valid();
        },
        onclick: function (element) {
          $(element).valid();
        },
        ignore: '',
        errorElement: 'span',
     
    });  
    
            $("#recipe-node-form").validate({
        onfocusout: function (element) {
          $(element).valid();
        },
        onclick: function (element) {
          $(element).valid();
        },
        //ignore: '',
        errorElement: 'span',
        errorPlacement: function (error, element) {
          var elementName = element.attr('name');
          var errorPlaceHolder = '';
          switch (elementName) {
            case 'field_recipe_food_type[und]':
              errorPlaceHolder = element.parent().parent().parent();
              break;
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: { 
        'field_recipe_cuisine_type[und]': {
            required: true,
            validateSignName: true
          },
         'field_recipe_meal_for[und]': {
            required: true,
            validateSignName: true
          }, 
          'field_recipe_meal_type[und]': {
            required: true,
            validateSignName: true
          },
          'field_recipe_description[und][0][value]': {
            required: true,
            validateSignName: true
          },
          'field_recipe_food_type[und]': {
            required: true,
            validateSignName: true
          },
          'field_story_extra_large_image[und][0]': {
            required: true,
            validateSignName: true
          },
          
      }
      });
      // code use for make primary category
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
                    jQuery('#primary-category-data option').each(function()
                    {
                        var existvalue = jQuery(this).val();
                        if (selectvalue == existvalue)
                        {
                            flag = 1;
                        }

                    })
                    if (comptext != "" && flag == 0)
                    {
                        makeradio = '<option value="' + selectvalue + '">' + comptext + '</option>';
                        jQuery('#primary-category-data').append(makeradio);

                        var gethtml = jQuery('#primary-category-data').html();
                        jQuery('#edit-field-primary-category-html-und-0-value').val(gethtml);
                    }
                }

            })
            jQuery('.dropbox-remove a').click(function() {
                var getdattext = jQuery(this).parent().siblings('td').text();
               
                $('#primary-category-data option').each(function() {
                   
                    var getdoptiontext=jQuery(this).text();
                    if (getdoptiontext== getdattext) {
                        jQuery(this).remove();
                    }
                });

            })


            jQuery('#primary-category-data').change(function() {
                var getval = jQuery(this).val();
                jQuery('#edit-field-primary-category-und-0-value').val(getval);
                jQuery('#primary-category-data option').attr('selected', false);
                jQuery('#primary-category-data option[value=' + getval + ']').attr('selected', 'selected');
                var gethtml = jQuery('#primary-category-data').html();
                jQuery('#edit-field-primary-category-html-und-0-value').val(gethtml);
            })
      function validateSignNameValue(event, element) {
        if ($(element).val() == '_none') {
          return false;
        }
        else {
          return true;
        }
      }
      jQuery.validator.addMethod("validateSignName", function (value, element) {
        return validateSignNameValue(value, element);
      }, " This field is required.");
 
        }
    };
})(jQuery, Drupal, this, this.document);
//   code load the selectd option and add to select box
jQuery(window).load(function() {
    //jQuery('#edit-field-primary-category-html-und-0-value').hide();
    // executes when complete page is fully loaded, including all frames, objects and images
    var getvaluehtml = jQuery('#edit-field-primary-category-html-und-0-value').val();

    if (getvaluehtml != "")
    {
        jQuery('#primary-category-data').html(getvaluehtml);
    }
});
