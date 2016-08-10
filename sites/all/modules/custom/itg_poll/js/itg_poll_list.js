/*
 * @file itg_event_backend.js
 * Contains functionality related Poll form
 */

(function($) {

    Drupal.behaviors.itg_poll_list = {
        attach: function(context, settings) {
       
        $('#subspollform .form-submit').click(function(e){
            e.preventDefault();
            
            alert('jjj');
            
        });
         

        }
    }
})(jQuery);