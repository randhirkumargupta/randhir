/*
 * @file itg_event_backend.js
 * Contains functionality related Poll form
 */

(function($) {

  Drupal.behaviors.itg_poll_form = {
    attach: function(context, settings) {
     jQuery(document).ready(function(){ 
       jQuery('input[name=field_poll_answer_add_more]').mousedown();});

    }
  }
})(jQuery);
