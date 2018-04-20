<div id="live_data"><?php print itg_live_blog_list(); ?></div>
<div id="live_blog_form">
    
</div>

<?php //if ($_SESSION['itg_blog_post']) { ?>
<script>  
  jQuery(document).ready(function($) { 
    $(document).on('click', '#cboxClose', function(e){  
      e.preventDefault();
      alert('click function');
    });
    // $("#cboxClose" ).trigger( "click" );
    // fetch_data(id);
            
});  
</script>   
<?php // } ?>
<script>  

jQuery(document).ready(function($){   
    function fetch_data(id)  
    {  

      $.ajax({  
            url:"/manage-live-blog/add/"+id,  
            method:"POST",  
            success:function(data){  
              $('#live_data').empty();  
              $('#live_data').html(data);  
            }  
      });
     // setTimeout(fetch_data(id),1000 * 60 * 3);  
    }  
 

    /*
    $(document).on('click', '.itg-custom-blog', function(){  
        var first_name = $('#edit-blog-title').text();
        
        $.ajax({  
            url:"/manage-print-form/add/"+id,   
            type:"POST",  
            data: $('form').serialize(), 
            dataType:"text",  
            success:function(data)  
            {  
                alert('form was submitted');
                $('#live_data').empty();  
                $('#live_data').html(data);  
            }  
        })  
    });  
    */
    $(document).on('click', '.btn_edit', function(){  
        var id = $(this).data("id4");
        alert('id' + id);
        var first_name = $('#f'+id).text();
        var last_name = $('#l'+id).text();
        
        $.ajax({  
            url:"/manage-print-form/edit/"+id,  
            type:"POST",  
            data:{id:id},  
            dataType:"text",  
            success:function(data)  
            {  
                alert(data);
                $('#live_data').empty();  
                $('#live_data').html(data);  
            }  
        })  
    });
    
	  $(document).on('click', '.btn_delete', function(){  
        var id=$(this).data("id3");  
        if(confirm("Are you sure you want to delete this?"))  
        {  
            $.ajax({  
                url:"delete.php",  
                method:"POST",  
                data:{id:id},  
                dataType:"text",  
                success:function(data){  
                    alert(data);  
                    fetch_data();  
                }  
            });  
        }  
    });
    
    // Load more data
    $(document).on('click', '.load-more', function(){    
      // alert('test');
        var row = Number($('#row').val());
        var allcount = Number($('#all').val());
        var entityId = Number($('#entity-id').val());
        var rowperpage = 3;
        row = row + rowperpage;
        // alert('row' + row);

        if(row <= allcount){
            $("#row").val(row);

            $.ajax({
                url: '/itg-live-blog-list',
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
                        $('#custom-live-blog tr:last').after(response).show().fadeIn("slow");

                        var rowno = row + rowperpage;

                        // checking row value is greater than allcount or not
                        if(rowno > allcount){

                            // Change the text and background
                            $('.load-more').text("Hide");
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