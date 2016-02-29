/*
 * @file itg_breaking_news.js
 */

/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
  Drupal.behaviors.itg_breaking_news = {
    attach: function (context, settings) {
      var uid = settings.itg_breaking_news.settings.uid;
      var type = $('#edit-field-type-und').val();


      // code to hide body text format filter 
      if (uid != 1) {
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        $('#edit-metatags-und-advanced').hide();

      }

      // type check for add form
      $("#edit-field-type-und").change(function () {
        //alert(this.value);
        if (this.value == 'Live Blog') {

          $("input[id*=field-mark-as-breaking-band]").hide();
          $("input[id*=field-mark-as-breaking-band]").removeAttr('checked');
          $('label[for*="field-mark-as-breaking-band"]').hide();



        }
        else
        {

          $("input[id*=field-mark-as-breaking-band]").show();
          $('label[for*="field-mark-as-breaking-band"]').show();

        }
      });

      // type check for edit form
      if (type == 'Live Blog') {
        $('input[id*=field-mark-as-breaking-band]').hide();
        $('label[for*="field-mark-as-breaking-band"]').hide();
      }



      $('body').on('change', '.field-name-field-mobile-subscribers .form-checkbox', function () {
        var el_value = $(this).attr('value');
        var el_check = $(this).is(':checked');
        var iOS = $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox[value="iOS"]').is(':checked');
        var Android = $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox[value="Android"]').is(':checked');
        var Windows = $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox[value="Windows"]').is(':checked');
        if (el_value == "All" && el_check == true) {
          $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox').attr('checked', true);
        }
        else if (el_value == "All" && el_check == false) {
          $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox').attr('checked', false);
        }
        else if (el_value != "All" && el_check == false) {
          $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox[value="All"]').attr('checked', false);
        }
        else if (el_value != "All" && iOS == true && Android == true && Windows == true) {
          $(this).parents('.field-name-field-mobile-subscribers').find('.form-checkbox[value="All"]').attr('checked', true);
        }
      });
      $('body').find('.field-name-field-notification- .form-checkbox:checked').parents('.field-name-field-notification-').next().show();
      $('body').on('change', '.field-name-field-notification- .form-checkbox', function () {
        var el_check = $(this).is(':checked');
        if (el_check == true) {
          $(this).parents('.field-name-field-notification-').next().show();
          $(this).parents('.field-name-field-notification-').next().find('.form-checkbox').attr('checked', true);
        }
        else {
          $(this).parents('.field-name-field-notification-').next().find('.form-checkbox').attr('checked', false);
          $(this).parents('.field-name-field-notification-').next().hide();
        }
      });
      
      
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').siblings().find('.field-name-field-mark-as-breaking-band .form-checkbox').attr({checked: false, disabled: true});
  $('body').on('change', '.field-name-field-mark-as-breaking-band .form-checkbox', function () {
    var el_check = $(this).is(':checked');
    if(el_check == true){
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox').attr({checked: false, disabled: true});
      $(this).attr({checked: true, disabled: false});
    }
    else{
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox').attr({checked: false, disabled: false});
    }
  });
  $('#edit-field-section > .form-type-select > label').html('Section<span class="form-required">*</span>');


    }

  };
})(jQuery, Drupal, this, this.document);
