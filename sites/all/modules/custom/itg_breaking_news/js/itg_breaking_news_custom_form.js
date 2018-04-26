/**
 * @file contains the JS file for Scheduled product price.
 */
 
(function ($) {
  Drupal.behaviors.itg_breaking_new_form = {
    attach: function (context, settings) { 
      jQuery( ".liveblog-custom-data" ).click( function() {
        var current_object = jQuery( this );
        
        console.log( 'Testing some data' );
        jQuery('#blog-loader-data').show();
        var base_url = settings.itg_breaking_new_form.settings.base_url;
        var slug_id = jQuery( this ).attr( 'data' );
        jQuery('.custom_blog_bid').val(slug_id);
        jQuery('.custom_blog_action').val('update');
        setTimeout(function() {
            jQuery('.form-submit').mousedown();
        }, 5000);
                     
        
      });
      
      setTimeout(function() {
            var entityId = Number($('#entity-id').val());
            console.log("data autoreload " + entityId);
           // fetch_data('0',entityId);
        }, 5000);
       function fetch_data(row, entityId) {
          $.ajax({
              url: '/itg-live-blog-row',
              type: 'post',
              data: {row:row,entityId:entityId},
              success: function(response){
                  setTimeout(function() {
                      $('#custom-live-blog tr:first').after(response).show().fadeIn("slow");                      
                  }, 2000);

              }
          });
      }
    }
  };    
})(jQuery);

