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
      var nid = settings.itg_breaking_news.settings.no_id;
      
      if(nid == 0) {
        jQuery("#edit-field-story-highlights-und-0-remove-button").hide();
        jQuery("#edit-field-breaking-content-details-und-0-remove-button").hide();
      }
      
      var type = $('#edit-field-type-und').val();
      if (type == 'Cricket Live Blog') {
        $('#edit-field-breaking-coverage-end-time').show();
      }
       $('#custom_add_another_item').click(function() {
         //ajax-new-content
         $('input[name="field_breaking_content_details_add_more"]').mousedown();
       })
      
      
      // type check for add form
      $("#edit-field-type-und").change(function () {
        
        if (this.value == 'Live Blog' || this.value == 'Cricket Live Blog') {
          $(".field-name-field-mark-as-breaking-band").hide();
          $(".field-name-field-breaking-publish-time").hide();
          $(".form-item-field-section-und").hide();
          $("input[id*=field-mark-as-breaking-band]").removeAttr('checked');
          $(".highlight-title").show();
          $('#edit-field-section-und').prop('selectedIndex',0);
          $('#edit-field-breaking-display-on-und').prop('selectedIndex',0);
          $('#edit-field-section > .form-type-select > label').html('Section');
           // Start code for category shift
          // If User Selected Live Blog
            $('.form-item-itg-section').show()
            $('.form-item-itg-category').show();
            $('.form-item-itg-sub-category').show();
            $('.form-item-itg-sub-sub-category').show();
            $('.form-item-itg-sub-sub-sub-category').show();
            $('.form-item-itg-primary-category').show();

            if (!$('#edit-itg-category').val()) {
             $('.form-item-itg-category').hide();
            }

            if (!$('#edit-itg-sub-category').val()) {
             $('.form-item-itg-sub-category').hide();
            }

            if (!$('#edit-itg-sub-sub-category').val()) {
             $('.form-item-itg-sub-sub-category').hide();
            }

            if (!$('#edit-itg-sub-sub-sub-category').val()) {
            $('.form-item-itg-sub-sub-sub-category').hide();
            }
           // End code for category shift
        
        }
        else {
          $(".highlight-title").hide();
          $(".field-name-field-mark-as-breaking-band").show();
          $(".form-item-field-section-und").show();
          $(".field-name-field-breaking-publish-time").show();
          $('#edit-field-section > .form-type-select > label').html('Section<span class="form-required">*</span>');
              // Start code for cateogry shift
           // If user selected other than live blog
            $('.form-item-itg-section').hide()
            $('.form-item-itg-category').hide();
            $('.form-item-itg-sub-category').hide();
            $('.form-item-itg-sub-sub-category').hide();
            $('.form-item-itg-sub-sub-sub-category').hide();
            $('.form-item-itg-primary-category').hide();
           // End code for category shift
        }
        
        // hide Live tv checkbox if type is breaking news
        var typevalue = $('#edit-field-type-und').val();
        if (typevalue == 'Breaking News') {
          $('#edit-field-story-expires-und-yes').attr('checked', false);
        }
        if (typevalue == 'Cricket Live Blog') {
          $('#edit-field-breaking-coverage-end-time').show();
        }
      });

      // type check for edit form
      if (type == 'Live Blog' || type == 'Cricket Live Blog') {
        $(".field-name-field-mark-as-breaking-band").hide();
        $(".field-name-field-breaking-publish-time").hide();
        $(".form-item-field-section-und").hide();
        
          // Start code for category shift
          // User Selected Live Blog
            $('.form-item-itg-section').show()
            $('.form-item-itg-category').show();
            $('.form-item-itg-sub-category').show();
            $('.form-item-itg-sub-sub-category').show();
            $('.form-item-itg-sub-sub-sub-category').show();
            $('.form-item-itg-primary-category').show();

            if (!$('#edit-itg-category').val()) {
             $('.form-item-itg-category').hide();
            }

            if (!$('#edit-itg-sub-category').val()) {
             $('.form-item-itg-sub-category').hide();
            }

            if (!$('#edit-itg-sub-sub-category').val()) {
             $('.form-item-itg-sub-sub-category').hide();
            }

            if (!$('#edit-itg-sub-sub-sub-category').val()) {
            $('.form-item-itg-sub-sub-sub-category').hide();
            }
           // End code for category shift
        
        
      }
      
      // type check for edit form
      if (type == 'Breaking News') {
        $(".highlight-title").hide();
        $('#edit-field-section > .form-type-select > label').html('Section<span class="form-required">*</span>');
        // Start code for cateogry shift
        // If user selected other than live blog
            $('.form-item-itg-section').hide()
            $('.form-item-itg-category').hide();
            $('.form-item-itg-sub-category').hide();
            $('.form-item-itg-sub-sub-category').hide();
            $('.form-item-itg-sub-sub-sub-category').hide();
            $('.form-item-itg-primary-category').hide();
        // End code for category shift
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

    }

  };
})(jQuery, Drupal, this, this.document);
