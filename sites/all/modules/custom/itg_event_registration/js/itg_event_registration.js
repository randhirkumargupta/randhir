/*
 * @file itg_event_registration.js
 */

(function($) {
  Drupal.behaviors.itg_event_registration = {
    attach: function(context, settings) {
      
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_event_registration.settings.uid;
      var nid = settings.itg_event_registration.settings.nid;
      $('#edit-title').val('event-'+nid);
      $('.form-item-title').hide();
      
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        $("#edit-field-story-source-id").hide();
      }
      
      //Hide skip button
      $('#edit-skip').hide();
      $('#edit-skip-1').hide();

      if(nid == '' || nid == null) {
          $('input[name="field_erf_registration_und_0_remove_button"]').hide();
          $('#edit-field-erf-registration-fee-und-0-remove-button').hide();
        }
 
      $("#edit-field-erf-registration-fee-und-0-remove-button").hide();
      
      //Validation of event registration fields
      $('#edit-field-last-name-und-0-value, #edit-title').keyup(function() {
        this.value = this.value.replace(/[^a-zA-Z\s.]/g, '');
      });
      
      $('#edit-field-erf-mobile-und-0-value, #edit-field-erf-postal-code-und-0-value').keyup(function() {
        this.value = this.value.replace(/[^0-9]/g, '');
      }); 
      
      $('.form-field-name-field-erf-registration-fee').on('click', 'legend', function(){            
        $(this).next('.fieldset-wrapper').stop().slideToggle();            
      });
      
    }
  };
})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function(){
        var offset = jQuery('.form-field-name-field-erf-payment-gateway').offset();   
          //event regestration
        jQuery('.event-form-add').click(function() {
            jQuery('html, body').animate({
                            scrollTop:offset.top - 200
                            }, 'slow');
            var $eventNum = jQuery(".event-form-number");
            var a = $eventNum.val();
            a++;        
            $eventNum.val(a);
            jQuery(".field-add-more-submit").trigger("mousedown");                      
        });        
        
        jQuery('.event-form-remove').click(function() {
            var $eventNum = jQuery(".event-form-number");
            var b = $eventNum.val();
            console.log(b);
            if (b > 1) {
              jQuery("table.field-multiple-table tr td:last").prev().find(".cancel.form-submit").trigger("mousedown");
              jQuery('html, body').animate({
               scrollTop:offset.top - 200
               }, 'slow');   
               jQuery("table.field-multiple-table tr").eq(b).remove();  
              b--;
              $eventNum.val(b);              
            }             
            priceCalc();
            var totalMember = jQuery('.event-total-fees-text .event-number-of-members');
            var a = $eventNum.val();                        
            totalMember.html(a);                         
        });                              
        
        var priceCalc = function(){
            var memberPrice = 0;
            jQuery('.form-radio').each(function(){   
               if(jQuery(this).is(':checked'))
               {
                   memberPrice =  parseInt(memberPrice) +  parseInt(jQuery(this).val());                     
               }                                        
            });                 
            var $total = jQuery('#edit-total-fees-container .event-fees-amount');           
            $total.html("Rs " + memberPrice);            
        }
        
        jQuery(document).on('change', 'input[type="radio"]', function() {  
            var $eventNum = jQuery(".event-form-number");
            var totalMember = jQuery('.event-total-fees-text .event-number-of-members');
            var a = $eventNum.val();                        
            totalMember.html(a); 
            priceCalc();
        });
        
        
        jQuery(document).on('click','.event-registration-form-header', function(){        
            jQuery('.event-registration-form-header').removeClass('.event-registration-header-open');
            var nextContent = jQuery(this).next('.event-registration-form-content');            
            if(nextContent.is(":visible")){
                nextContent.stop().slideUp();
                jQuery(this).addClass('event-registration-header-close'); 
                jQuery(this).removeClass('event-registration-header-open');
            }else{
                nextContent.stop().slideDown();
                jQuery(this).addClass('event-registration-header-open');                
                jQuery(this).removeClass('event-registration-header-close');
            }
            
        });
        
        
});