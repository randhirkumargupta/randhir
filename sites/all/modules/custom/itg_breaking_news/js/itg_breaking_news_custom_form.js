/**
 * @file contains the JS file for Scheduled product price.
 */
 
(function ($) {
  Drupal.behaviors.itg_breaking_new_form = {
    attach: function (context, settings) { 
      jQuery( ".liveblog-custom-data" ).click( function() {
        var current_object = jQuery( this );
        
        console.log( 'Testing some data' );
        var base_url = settings.itg_breaking_new_form.settings.base_url;
        var slug_id = jQuery( this ).attr( 'data' );
        jQuery('.custom_blog_bid').val(slug_id);
        jQuery('.custom_blog_action').val('update');
        setTimeout(function() {
            jQuery('.form-submit').mousedown();
        }, 5000);
        
        
      } );

       
    }
  };    
})(jQuery);

