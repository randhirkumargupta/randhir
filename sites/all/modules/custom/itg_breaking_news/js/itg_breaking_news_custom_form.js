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
        // jQuery("#custom-live-blog #"+id).animate({ backgroundColor: "#d9d9d9" }, "slow");
        setTimeout(function() {
            jQuery('.form-submit').mousedown();
        }, 5000);
                     
        
      });
      
      setTimeout(function() {
            console.log("itg-live-blog-row");
        }, 5000);
       function fetch_data() {
          $.ajax({
              url: '/itg-live-blog-row',
              type: 'post',
              data: {row:row,entityId:entityId},
              beforeSend:function(){
                  $(".load-more").text("Loading...");
              },
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

