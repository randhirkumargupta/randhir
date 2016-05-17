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
            //Reset Paid value after click on Free
            $('#edit-field-event-type-und-free').on('click', function(){
                $('#edit-field-group-registration-fee-5-und-0-value').val('');
                $('#edit-field-group-registration-fee-10-und-0-value').val('');
                $('#edit-field-individual-registration-fe-und-0-value').val('');
            });
            
             //Ajax implement on daywise
//           $('.field-name-field-event-highlights').on('change', '.field-name-field-daywise-event .form-select', function(){
//               var node_id = settings.itg_event_backend_nid.settings.node_id;
//                //$(this).parents('.field-name-field-daywise-event').next().find('.form-select').addClass('vddd');
//                var base_url = Drupal.settings.basePath;
//                 $.ajax({
//                       url: base_url + "event-title/"+node_id,
//                       method: 'POST',
//                       //data: {'daywise': $(this).val()},
//                       data: 'daywise='+$(this).val(),
//                       success: function(data) {                              
//                              // $(this).parents('.field-name-field-daywise-event').next().find('.field-name-field-programe-title .form-select').html(data);
//                               //$(this).next().find('.field-name-field-programe-title .form-select').html(data);
//                               $('#edit-field-event-highlights-und-0-field-programe-title-und').html(data);
//                       }
//                 });
//            });
         
        }
    }
})(jQuery);
