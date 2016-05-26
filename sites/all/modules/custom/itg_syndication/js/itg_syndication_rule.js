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
