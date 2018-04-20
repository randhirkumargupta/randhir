/**
 * @file contains the JS file for Scheduled product price.
 */
 
(function ($) {
  Drupal.behaviors.itg_breaking_new_form = {
    attach: function (context, settings) { 
       // var base_url = settings.itg_breaking_new_form.settings.base_url;
       // var no_id = settings.itg_breaking_new_form.settings.no_id;
       // alert('base_url');
       // alert('no_id test ' + no_id);
        //request(no_id);
        /*
        if(no_id !== undefined) {
            alert('no_id testt ' + no_id);
             
             $.ajax({
                url: '/itg-live-blog-row',
                type: 'post',
                data: {id:no_id},
                beforeSend:function(){
                    $(".load-more").text("Loading...");
                },
                success: function(response){
                      alert(response);  
                    // Setting little delay while displaying new content
                    setTimeout(function() {
                        // appending posts after last post with class="post"
                       // $(".post:last").after(response).show().fadeIn("slow");
                        $('#custom-live-blog tr:first').after(response).show().fadeIn("slow");

                        $('.load-more').text("Hide");
                    }, 2000);

                }
            });
            alert("close Loading");
            $("#cboxClose" ).trigger( "click" );
        }
        /*
        jQuery.fn.live_blog_custom_js = function () {
                alert("test");
                // $("#widget-ajex-loader").css("display", "block");
                
        };
      
       
    
       jQuery('body').on('click', '.itg-custom-blog', function(e){
            e.preventDefault();
            alert("test");
            var desc = jQuery('#edit-blog-description-value').html();
            $.ajax({  
            url:"/itg-live-blog-insert",   
            type:"POST",  
            data: $('form').serialize(), 
            success:function(response)  
            {  
                alert('form was submitted');
                $("#cboxClose" ).trigger( "click" );
                setTimeout(function() {
                      // appending posts after last post with class="post"
                     // $(".post:last").after(response).show().fadeIn("slow");
                      $('#custom-live-blog tr:first').after(response).show().fadeIn("slow");
                  }, 2000);
            }  
        })  
       });
         */
       
    }
  };    
})(jQuery);

function itg_blog_fetch_data(id) {
      alert("hiiiiiiiii = " + id);
      jQuery.ajax({  
            url:"/manage-live-blog/add/"+id,  
            method:"POST",  
            success:function(data){  
              jQuery("#live_data").parent().empty();
              jQuery('#live_data').parent().html(data);  
            }  
      });
  }

