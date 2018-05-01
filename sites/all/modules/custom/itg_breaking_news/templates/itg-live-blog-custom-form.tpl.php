<?php 
global $user;
$user = !empty($user->uid) ? user_load($user->uid) : '';
$user_name = ($user->field_last_name[LANGUAGE_NONE][0]['value']) ? $user->field_first_name[LANGUAGE_NONE][0]['value'] . " " . $user->field_last_name[LANGUAGE_NONE][0]['value'] : $user->field_first_name[LANGUAGE_NONE][0]['value'];
$nid = (arg(2)) ? arg(2) : ''; ?>
<div class="blog-referesh"><a class="referesh-custom-data" data="<?php print $nid; ?>" href="javascript:void(0);">Click to Refresh</a><span class="itg-blog-user">User : <?php print $user_name; ?></span></div>
<div class="blog-loader-container">
<div id="blog-loader-data" style="display: none"><img class="blog-loader" src="<?php echo base_path(); ?>sites/all/themes/itg/images/tab-loading.gif" alt="Loading..." /></div>
<div id="live_data"><?php print itg_live_blog_list($nid); ?></div></div>
<div id="live_blog_form" class="table-bordered">   
<?php
    
    print drupal_render(drupal_get_form('itg_manage_breking_news', $nid, 'insert'));
?>
</div>

<script>  

jQuery(document).ready(function($){
    
    $(document).on('click', '.liveblog-custom-data', function() {  
        var current_object = jQuery( this );
        
        console.log( 'Testing some data' );
        jQuery('#blog-loader-data').show();
        // var base_url = settings.itg_breaking_new_form.settings.base_url;
        var slug_id = jQuery( this ).attr( 'data' );
        jQuery('.custom_blog_bid').val(slug_id);
        jQuery('.custom_blog_action').val('update');
        setTimeout(function() {
            jQuery('.form-submit').mousedown();
        }, 3000);    
    });
      
    jQuery( ".referesh-custom-data" ).click( function() {
      console.log( 'refresh data' );
      var entityId = jQuery( this ).attr( 'data' );
      var row = 0;
      if(entityId) {
        $.ajax({
            url: '/itg-live-blog-refresh',
            type: 'post',
            data: {row:row,entityId:entityId},
            success: function(response){
              if(response) {
                $('#live_data').html(response);
              }                                    
            }
        });
      } 
    });
    
     
      
    $(document).on('click', '.blog_highlight_checkbox', function() {
        if ($(this).attr("checked")) 
        {
            jQuery('.blog_highlights_status').val('1');
            return;
        }
       jQuery('.blog_highlights_status').val('2');
    });
   
	  $(document).on('click', '.btn_delete', function(){  
        var id=$(this).data("id3");
        if(confirm("Are you sure you want to delete this?"))  
        {  
            $.ajax({  
                url: '/itg-live-bog-delete',
                type: 'post',
                data:{id:id},
                beforeSend:function(){
                    //$(".load-ajax-box").show();
                    jQuery("#custom-live-blog #"+id).animate({ backgroundColor: "#d9d9d9" }, "slow");
                },
                success:function(data){
                    jQuery('.load-ajax-box').hide();
                    jQuery("#custom-live-blog #"+id).animate({ backgroundColor: "#d9d9d9" }, "slow")
  .animate({ opacity: "hide" }, "slow");
                }  
            });  
        }  
    });
    
    // Load more data
    $(document).on('click', '.load-more', function(){    
        var row = Number($('#row').val());
        var allcount = Number($('#all').val());
        var entityId = Number($('#entity-id').val());
        var rowperpage = 3;
        row = row + rowperpage;
       
        if(row <= allcount){
            $("#row").val(row);

            $.ajax({
                url: '/itg-live-blog-row',
                type: 'post',
                data: {row:row,entityId:entityId},
                beforeSend:function(){
                    $(".load-more").text("Loading...");
                },
                success: function(response){
                    // Setting little delay while displaying new content
                    setTimeout(function() {
                        // appending posts after last post with class="post"
                       // $(".post:last").after(response).show().fadeIn("slow");
                        $('#custom-live-blog tr:first').after(response).show().fadeIn("slow");

                        var rowno = row + rowperpage;

                        // checking row value is greater than allcount or not
                        if(rowno > allcount){

                            // Change the text and background
                            jQuery('.load-more').hide();
                            $('.load-more').css("background","darkorchid");
                        }else{
                            $(".load-more").text("Load more");
                        }
                    }, 2000);

                }
            });
        }else{
            $('.load-more').text("Loading...");

            // Setting little delay while removing contents
            setTimeout(function() {

                // When row is greater than allcount then remove all class='post' element after 3 element
                $('.post:nth-child(3)').nextAll('.post').remove();

                // Reset the value of row
                $("#row").val(0);

                // Change the text and background
                $('.load-more').text("Load more");
                $('.load-more').css("background","#15a9ce");
                
            }, 2000);


        }

    });
           
});


</script>

<style>
.blog-referesh {
  padding: 5px 0;
  font-weight: bold;
}

.itg-blog-user{
    float:right;
}
   
span.inline-error-messages.error {
    text-align: center;
    background: #a8c1e4;
    font-size: 20px;
}

.load-ajax-box {
    display:none;
    text-align: center;
    background: #158ece;
}

.itg-blog-empty-data {
    text-align: center;
    font-family: sans-serif;
    background: #158ece;
}

.filter-wrapper {display: none;}
/* post */
.post{
    width: 97%;
    min-height: 200px;
    padding: 5px;
    border: 1px solid gray;
    margin-bottom: 15px;
}

.post h1{
    letter-spacing: 1px;
    font-weight: normal;
    font-family: sans-serif;
}


.post p{
    letter-spacing: 1px;
    text-overflow: ellipsis;
    line-height: 25px;
}

/* Load more */
.load-more{
    width: 99%;
    background: #15a9ce;
    text-align: center;
    color: white;
    padding: 10px 0px;
    font-family: sans-serif;
}

.load-more:hover{
    cursor: pointer;
}
/* more link */
.more{
    color: blue;
    text-decoration: none;
    letter-spacing: 1px;
    font-size: 16px;
}

div#blog_highlight_replace_wrapper {
    margin-left: 248px;
}


.blog-loader-container{ position: relative;}
   .blog-loader-container #blog-loader-data{position: absolute; top: 0px; width: 100%; height: 100%;background: rgba(255,255,255,0.5);}
   .blog-loader-container #blog-loader-data img.blog-loader{ width: 32px;height: 32px; position: absolute; left: 50%; top: 45%;transform: translate(-50%,-50%);}
</style>    