/*
 * @file itg_mega_reviews_critics.js
 * Contains all functionality related to Mega Reviews & Critics
 */

(function ($) {
  Drupal.behaviors.mega_reviews_critics = {
    attach: function (context) {
        var storyId = Drupal.settings.itg_mega_reviews_critics.settings.storyid;
        // hide remove button of first field on add form
        if (storyId == 0) {
          jQuery("#edit-field-mega-review-review-und-0-remove-button").hide();
        }
        $('.tabledrag-toggle-weight-wrapper').hide();
        $('.story-title').show();
    }

  };
})(jQuery, Drupal, this, this.document);
