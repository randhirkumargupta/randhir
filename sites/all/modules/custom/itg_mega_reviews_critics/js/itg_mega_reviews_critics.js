/*
 * @file itg_mega_reviews_critics.js
 * Contains all functionality related to Mega Reviews & Critics
 */

(function ($) {
  Drupal.behaviors.mega_reviews_critics = {
    attach: function (context) {
        $('.tabledrag-toggle-weight-wrapper').hide();
        $('.story-title').show();
    }

  };
})(jQuery, Drupal, this, this.document);