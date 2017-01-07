(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_syndication_rule = {
    attach: function (context, settings) {
      jQuery(".form-item-title").hide();
      jQuery("#edit-field-syndication-rule-title-und").change(function() {
        jQuery("#edit-title").val(jQuery(this).val());        
        jQuery('#edit-field-syndication-rule-title-und').attr('readonly', true);
      })
    }
  };


})(jQuery, Drupal, this, this.document);

jQuery (document).ajaxSuccess (function () {
  for (i = 0; i <= 25; i++) {
    var field_syndication_frequency = jQuery ('input[name="field_syndication_rule_details[und]['+i+'][field_syndication_frequency][und]"]:checked').val ();

    if (field_syndication_frequency == "Weekly") {
      jQuery ('[id^=\"edit-field-syndication-rule-details-und-'+i+'-field-syndication-set-day-und\"]').parent ().parent ().show ();
    }

    if (field_syndication_frequency == "Monthly") {
      jQuery ('[id^=\"edit-field-syndication-rule-details-und-'+i+'-field-syndication-set-day-month\"]').parent ().parent ().show ();
    }
  }
});
