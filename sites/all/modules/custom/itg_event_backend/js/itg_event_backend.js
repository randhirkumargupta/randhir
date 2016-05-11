/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    Drupal.behaviors.itg_event_backend_form = {
        attach: function(context, settings) {

            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            $('.form-item-field-gallery-image-add-more-number').hide();
            var uid = settings.itg_event_backend.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                $('#edit-field-event-short-description-und-0-format').hide();
                $('#edit-body-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();

            }
            //Disable date filed direct enter date
            jQuery('input[name="field_event_start_date[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_event_close_date[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_registration_close_date[und][0][value][date]"]').keydown(false);
            // end code

            //hide skip button
            $('#edit-skip').hide();
            $('#edit-skip-1').hide();
         
        }
    }
})(jQuery);