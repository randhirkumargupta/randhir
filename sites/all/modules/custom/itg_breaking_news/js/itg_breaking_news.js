/*
 * @file itg_breaking_news.js
 */

/*
 * @file itg_breaking_news.js
 * Contains all functionality related to story
 */

(function ($) {
  Drupal.behaviors.itg_breaking_news = {
    attach: function (context, settings) {
      var uid = settings.itg_breaking_news.settings.uid;
      var type = $('#edit-field-type-und').val();
      
       $('#custom_add_another_item').click(function() {         
         //edit-field-breaking-content-details
         //ajax-new-content
         $('input[name="field_breaking_content_details_add_more"]').mousedown();
       })
      
      
      // type check for add form
      $("#edit-field-type-und").change(function () {
        
        if (this.value == 'Live Blog') {
          $(".field-name-field-mark-as-breaking-band").hide();
          $(".field-name-field-breaking-publish-time").hide();
          $(".form-item-field-section-und").hide();
          $("input[id*=field-mark-as-breaking-band]").removeAttr('checked');
          $(".highlight-title").show();
          $('#edit-field-section-und').prop('selectedIndex',0);
          $('#edit-field-breaking-display-on-und').prop('selectedIndex',0);
          $('#edit-field-section > .form-type-select > label').html('Section');
        }
        else {
          $(".highlight-title").hide();
          $(".field-name-field-mark-as-breaking-band").show();
          $(".form-item-field-section-und").show();
          $(".field-name-field-breaking-publish-time").show();
          $('#edit-field-section > .form-type-select > label').html('Section<span class="form-required">*</span>');
        }
        
        // hide Live tv checkbox if type is breaking news
        var typevalue = $('#edit-field-type-und').val();
        if (typevalue == 'Breaking News') {
          $('#edit-field-story-expires-und-yes').attr('checked', false);
        }
      });

      // type check for edit form
      if (type == 'Live Blog') {
        $(".field-name-field-mark-as-breaking-band").hide();
        $(".field-name-field-breaking-publish-time").hide();
        $(".form-item-field-section-und").hide();
      }
      
      // type check for edit form
      if (type == 'Breaking News') {
        $(".highlight-title").hide();
        $('#edit-field-section > .form-type-select > label').html('Section<span class="form-required">*</span>');
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
      
      
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').siblings().find('.field-name-field-mark-as-breaking-band .form-checkbox').attr({checked: false});
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').find('.collapsed .fieldset-legend a').css('background-color', '#bcf2fc');
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').find('.collapsible .fieldset-legend a').css('background-color', '#bcf2fc');
      $(document).ajaxComplete(function(){
        $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').find('.collapsed .fieldset-legend a').css('background-color', '#bcf2fc');
        $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').find('.collapsible .fieldset-legend a').css('background-color', '#bcf2fc');
      });
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox:checked').parents('tr').find('#edit-field-breaking-content-details-und-0 .fieldset-legend a').css('background-color', '#bcf2fc');
    $('body').on('change', '.field-name-field-mark-as-breaking-band .form-checkbox', function () {
    var el_check = $(this).is(':checked');
    if(el_check == true){
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox').attr({checked: false});
      $(this).attr({checked: true});
    }
    else{
      $('body').find('.field-name-field-mark-as-breaking-band .form-checkbox').attr({checked: false});
    }
  });
  //$('#edit-field-section > .form-type-select > label').html('Section<span class="form-required">*</span>');
  
  
//  $( 'input[name="field_breaking_content_details_add_more"]' ).ajaxComplete(function() {
//    var offSet = 200;
//    var dataOffset = $(this).offset().top;
//    var targetOffset = dataOffset - offSet;
//    $("body, html").animate({scrollTop: targetOffset}, 300);
//  });


    }

  };
})(jQuery, Drupal, this, this.document);
