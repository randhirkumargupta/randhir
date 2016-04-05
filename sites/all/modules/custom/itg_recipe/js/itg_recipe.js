/*
 * @file itg_recipe.js
 * Contains all functionality related to Recipe
 */


(function($) {
    Drupal.behaviors.itg_recipe = {
        attach: function(context, settings) {
            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            var uid = settings.itg_recipe.settings.uid;
            if (uid != 1) {
                $('#edit-body-und-0-format').hide();
                $('#edit-field-recipe-description-und-0-format').hide();
                $('#edit-metatags').show();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags-und-advanced').hide();
            }
            
            
            $("#recipe-node-form").validate({
        submitHandler: function (form) {
          $('input:submit').attr('disabled', 'disabled');
          form.submit();
        },
        onfocusout: function (element) {
          $(element).valid();
        },
        onclick: function (element) {
          $(element).valid();
        },
        ignore: '',
        errorElement: 'span',
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
      }, "* This field is required.");
 
        }
    };
})(jQuery, Drupal, this, this.document);