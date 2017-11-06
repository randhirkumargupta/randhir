/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


jQuery(document).ready(function() {
    jQuery('.add-more-block').on('click', function() {
        jQuery(this).hide();
        jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').slideDown( 1000);
        jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.removes-more-block').show();
        jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.add-more-block').show();
         if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').next('.itg-common-section').is(':visible')) {
          jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').find('.add-more-block').hide();
        }
    });
    jQuery('.add-more-block').each(function() {
        if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').is(':visible')) {
            jQuery(this).hide();
        }
        if(jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').html() ==null) {
            jQuery(this).remove();
        }
    });
    jQuery('.removes-more-block').on('click', function() {
        jQuery(this).hide();
        jQuery(this).parent('.itg-common-section').hide();
        jQuery(this).parent('.itg-common-section').prev('.itg-common-section').find('.add-more-block').show();
    });
      
});

