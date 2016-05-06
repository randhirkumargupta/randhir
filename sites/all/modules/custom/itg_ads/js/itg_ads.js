/*
 * @file itg_mega_reviews_critics.js
 * Contains all functionality related to Mega Reviews & Critics
 */

(function ($) {
  Drupal.behaviors.itg_ads = {
    attach: function (context) {
        // Module Code start
        //$('.tabledrag-toggle-weight-wrapper').hide();
        $('.vertical-tabs').hide();
       
        // Disable edit mode of date fields
        $('input[name="field_ads_start_date[und][0][value][date]"]').keydown(false);
        $('input[name="field_ads_end_date[und][0][value][date]"]').keydown(false);
        
        // Module code end
    }

  };
})(jQuery, Drupal, this, this.document);