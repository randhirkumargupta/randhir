(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_syndication_rule = {
    attach: function (context, settings) {
      jQuery (".form-item-title").hide ();
      jQuery ("#edit-field-syndication-rule-title-und").change (function () {
        jQuery ("#edit-title").val (jQuery (this).val ());
        jQuery ('#edit-field-syndication-rule-title-und').attr ('readonly', true);
      })
    }
  };


}) (jQuery, Drupal, this, this.document);

function syndication_rules_show_filed (number_of_tr) {
  for (i = 0; i <= number_of_tr; i++) {
    var field_syndication_frequency = jQuery ('input[name="field_syndication_rule_details[und][' + i + '][field_syndication_frequency][und]"]:checked').val ();

    if (field_syndication_frequency == "Weekly") {
      jQuery ('[id^=\"edit-field-syndication-rule-details-und-' + i + '-field-syndication-set-day-und\"]').parent ().parent ().show ();
    }

    if (field_syndication_frequency == "Monthly") {
      jQuery ('[id^=\"edit-field-syndication-rule-details-und-' + i + '-field-syndication-set-day-month\"]').parent ().parent ().show ();
    }
    
  }
}

jQuery (document).ajaxSuccess (function () {
  var number_of_tr = jQuery('#field-syndication-rule-details-values tr').length;
  syndication_rules_show_filed (number_of_tr);
});

jQuery(document).ready(function(){
  var number_of_tr = jQuery('#field-syndication-rule-details-values tr').length;
  syndication_rules_show_filed (number_of_tr);
});
