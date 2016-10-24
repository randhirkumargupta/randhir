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
