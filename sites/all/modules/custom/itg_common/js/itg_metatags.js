/*
 * @file itg_metatags.js
 */

(function($) {
  Drupal.behaviors.itg_metatags = {
    attach: function() {
      $("#edit-metatags-und-advanced, #edit-metatags-en-advanced").hide();
      $(".form-item-metatags-und-abstract-value").hide();
      $("#edit-metatags-und-title-value").val("");
      $(".vertical-tabs-list").hide();
      $("#edit-metatags").show();//temp
      $("#edit-metatags a").hide();
      $('.field-edit-link').hide();
      $('#edit-body-und-0-format').hide();
      $('#edit-path').show();//temp
    }
  };
})(jQuery, Drupal, this, this.document);