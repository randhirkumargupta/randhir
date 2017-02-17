/*
 * @file itg_mega_reviews_critics.js
 * Contains all functionality related to Mega Reviews & Critics
 */

(function ($) {
  Drupal.behaviors.task_allocation = {
    attach: function (context) {
      //$('.tabledrag-toggle-weight-wrapper').hide();
      jQuery ('input[name="field_task_finish_date_and_time[und][0][value][date]"]').keydown (false);

      $ ('#edit-created-min-datepicker-popup-0').one ('focus', function () {
        $ ('#edit-created-min-datepicker-popup-0').datepicker ('option', {
          onClose: function (selected) {
            $ ('#edit-created-max-datepicker-popup-0').one ('focus', function () {
              $ ('#edit-created-max-datepicker-popup-0').datepicker ('option', 'minDate', selected);
            });
            $ ('#edit-created-max-datepicker-popup-0').datepicker ('option', 'minDate', selected);
          }
        });
      });

      jQuery ("#belly").click (function (event) {
        jQuery.ajax ({
          url: Drupal.settings.basePath + "notify-detail",
          type: 'POST',
          success: function (msg) {
            jQuery (".bell-notice").html (msg);
            jQuery (".bell-notice").show ();
          }
        });
      });
    }

  };
}) (jQuery, Drupal, this, this.document);


jQuery (document).ajaxSuccess (function () {
  var number_of_tr = jQuery ('#edit-field-highlights table.field-multiple-table tbody tr').length;
  hightlights_show_fields (number_of_tr);
});

jQuery (document).ready (function () {
  
  jQuery(".form-radio").live("click" , function(){
  var get_id = jQuery(this).attr("id");
  var n = get_id.indexOf("emoji-condition-und");
  if(n>0) {
    var radioButtonValue = jQuery(this).filter(":checked").val();
      if(radioButtonValue == 1) {
        jQuery(this).parent().parent().parent().parent().nextAll("div").show();
      }
      if(radioButtonValue == 0) {
        jQuery(this).parent().parent().parent().parent().nextAll("div").hide();
      }
      if(radioButtonValue == "none") {
        jQuery(this).parent().parent().parent().parent().nextAll("div").hide();
      }
  }
  });
  
  jQuery(".form-radio").each( function(){
  var get_id = jQuery(this).attr("id");
  var n = get_id.indexOf("emoji-condition-und");
  if(n>0) {
      var radioButtonValue = jQuery(this).filter(":checked").val();
      if(radioButtonValue == 1) {
        jQuery(this).parent().parent().parent().parent().nextAll("div").show();
      }
      if(radioButtonValue == 0) {
        jQuery(this).parent().parent().parent().parent().nextAll("div").hide();
      }
      if(radioButtonValue == "none") {
        jQuery(this).parent().parent().parent().parent().nextAll("div").hide();
      }
  }
  });
      
});

function hightlights_show_fields (number_of_tr) {
  for (i = 0; i <= number_of_tr; i++) {
    var field_highlights = jQuery ('input[name="field_highlights[und][' + i + '][field_emoji_condition][und]"]:checked').val ();
    if (field_highlights == 1) {
      jQuery('input[name="field_highlights[und][' + i + '][field_emoji_condition][und]"]').parent().parent().parent().parent().nextAll("div").show();
    }
    if (field_highlights == 0) {
      jQuery('input[name="field_highlights[und][' + i + '][field_emoji_condition][und]"]').parent().parent().parent().parent().nextAll("div").hide();
    }
    if (field_highlights == "none") {
        jQuery('input[name="field_highlights[und][' + i + '][field_emoji_condition][und]"]').parent().parent().parent().parent().nextAll("div").hide();
    }
  }
}