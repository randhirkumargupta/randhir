/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function ($) {
  Drupal.behaviors.itg_common_form = {
    attach: function (context, settings) {
       
      var fid = settings.itg_common.settings.formid;      
      var arg_url = settings.itg_common.settings.arg_url;
      var formstatus = settings.itg_common.settings.formstatus;
      
      if (formstatus == 1 && fid == 'taxonomy_form_term') {
        jQuery("#edit-relations .fieldset-title").hide();
        jQuery(".form-item-weight").hide();
        jQuery(".form-item-parent").hide();
      }
      
      if (arg_url == 'user') {
        jQuery("#skip-link").hide();
      }
      
      // Add JS to hide extra element of menu forms
      if (fid == 'menu_edit_item') {
        jQuery(".form-item-expanded").hide();
        jQuery(".form-item-parent").hide();
        jQuery(".form-item-weight").hide();
      }
      
      if (fid == 'custom_html_widgets_node_form') {
        jQuery(".vertical-tabs").hide();
      }

  }
 };
})(jQuery, Drupal, this, this.document);