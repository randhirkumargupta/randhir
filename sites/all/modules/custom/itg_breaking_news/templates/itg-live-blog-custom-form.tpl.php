<?php $nid = (arg(2)) ? arg(2) : ''; ?>
<div id="live_data"><?php print itg_live_blog_list($nid); ?></div>
<div id="live_blog_form" class="table-bordered">    
<?php
    
    print drupal_render(drupal_get_form('itg_manage_breking_news', $nid, 'insert'));
?>
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
                url: '/itg-live-blog-row',
                type: 'post',
                data: {row:row,entityId:entityId},
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
    
   // jQuery(".filter-wrapper").hide();
    
});  
</script>

<style>

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
</style>    