/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    Drupal.behaviors.itg_event_sponsor_form = {
        attach: function(context, settings) {
            var uid = settings.itg_event_sponsor.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                $('#edit-body-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();

            }
        }
    }
})(jQuery);