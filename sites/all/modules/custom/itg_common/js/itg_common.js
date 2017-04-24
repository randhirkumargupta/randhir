/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function ($) {
  Drupal.behaviors.itg_common = {
    attach: function (context, settings) {     

      
        jQuery('.reject-ugc').click(function() {                 
        var reject_status = 'reject';
        if (reject_status == 'reject') {                   
           var msg = confirm('Are you sure you want to reject this content?');
           if (msg == true) {
               return true;
           }
           return false; 
        }
        return true;                     
    });           

    }

  };
})(jQuery, Drupal, this, this.document);