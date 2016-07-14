<style>
    #logo
    {
        width: 505px;
        margin: 0 auto;
        text-align: center;
    }
    #pgtitle
    {
        margin: 0px 0px 20px;
        font-size: 18pt;
    }
    #container
    {
        display: block;
        width: 850px;
        height: 300px;
        margin: 0 auto;
    }
    #imgtag
    {
        position: relative;
        min-width: 300px;
        min-height: 300px;
        float: none;
        border: 3px solid #FFF;
        cursor: crosshair;
        text-align: center;
    }
    .tagview
    {
        border: 1px solid #F10303;
        width: 100px;
        height: 100px;
        position: absolute;
        /*display:none;*/
        opacity: 0;
        color: #FFFFFF;
        text-align: center;
    }
    .square
    {
        display: block;
        height: 79px;
    }
    .person
    {
        background: #282828;
        border-top: 1px solid #F10303;
    }
    #tagit
    {
        position: absolute;
        top: 0;
        left: 0;
        width: 240px;
        border: 1px solid #D7C7C7;
    }
    #tagit .box
    {
        border: 1px solid #F10303;
        width: 100px;
        height: 100px;
        float: left;
    }
    #tagit .name
    {
        float: left;
        background-color: #FFF;
        width: 127px;
        height: 92px;
        padding: 5px;
        font-size: 10pt;
    }
    #tagit DIV.text
    {
        margin-bottom: 5px;
    }
    #tagit INPUT[type=text]
    {
        margin-bottom: 5px;
    }
    #tagit #tagname
    {
        width: 110px;
    }
    #taglist
    {
        width: 300px;
        min-height: 200px;
        height: auto !important;
        height: 200px;
        float: left;
        padding: 10px;
        margin-left: 20px;
        color: #000;
    }
    #taglist OL
    {
        padding: 0 20px;
        float: left;
        cursor: pointer;
    }
    #taglist OL A
    {
    }
    #taglist OL A:hover
    {
        text-decoration: underline;
    }
    .tagtitle
    {
        font-size: 14px;
        text-align: center;
        width: 100%;
        float: left;
    }

</style>	

<?php $url = file_create_url($data->uri);?>
<div id="container">
    <div id="imgtag"> 

        <img id="" src="<?php echo $url;?>" /> 
        <div id="tagbox">
        </div>
    </div> 
    <div id="taglist"> 
        <ol> 
        </ol> 
    </div> 
     <button class="add-more maptofield">Next</button>
</div>

<script type="text/javascript">
    jQuery(document).ready(function() {
        var counter = 0;
        var mouseX = 0;
        var mouseY = 0;
        var field_name='<?php echo $field_name;?>';
        var image_fiedlid='<?php echo $data->fid;?>';

        jQuery("#imgtag img").click(function(e) { // make sure the image is click
            var imgtag = jQuery(this).parent(); // get the div to append the tagging list
            mouseX = (e.pageX - jQuery(imgtag).offset().left) - 50; // x and y axis
            mouseY = (e.pageY - jQuery(imgtag).offset().top) - 50;
            jQuery('#tagit').remove( ); // remove any tagit div first
            jQuery(imgtag).append('<div id="tagit"><div class="box"></div><div class="name"><div class="text">Tag</div><input type="text" name="tagname" id="tagname" placeholder="Title"/><input type="text" name="tagurl" class="error" id="tagurl" placeholder="Tag Url" /><span style="display:none" class="error web-error" for="edit-title" generated="true">Enter currect url .</span><input type="button" name="btnsave" value="Save" id="btnsavetag" /><input type="button" name="btncancel" value="Cancel" id="btncancel" /></div></div>');
            jQuery('#tagit').css({top: mouseY, left: mouseX});
            jQuery('#tagname').focus();
        });

        // Save button click - save tags
    jQuery('#file-preview').on('click', '#btnsavetag', function() {
            name = jQuery('#tagname').val();
             tagurl = jQuery('#tagurl').val();
           
    
            var img = jQuery('#imgtag').find('img');
            if(/^(http:\/\/www\.|https:\/\/www\.|http:\/\/|https:\/\/|www\.)[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/.test(tagurl)){
       jQuery('.web-error').hide();
         jQuery.ajax({
                    url: Drupal.settings.basePath + 'savetags',
                    type: 'post',
                    data: {'pic_id': image_fiedlid, 'name': name , 'url':tagurl , 'pic_x':mouseX , 'pic_y':mouseY , 'type':'insert'},
                    success: function(data) {
                        var objdata = jQuery.parseJSON(data);
                        if(objdata.status==1)
                            {
                                jQuery('#tagit').fadeOut();
                                viewtag(image_fiedlid);
                                
                            }
                    
                    },
                    error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                    }
                    }); 
    } else {
       jQuery('.web-error').show();
       return false;
    }
           

        });

        // Cancel the tag box.
        jQuery(document).on('click', '#tagit #btncancel', function() {
            jQuery('#tagit').fadeOut();
        });

        // mouseover the taglist 
        jQuery('#taglist').on('mouseover', 'li', function( ) {
            id = jQuery(this).attr("id");
            jQuery('#view_' + id).css({opacity: 1.0});
        }).on('mouseout', 'li', function( ) {
            jQuery('#view_' + id).css({opacity: 0.0});
        });

        // mouseover the tagboxes that is already there but opacity is 0.
        jQuery('#tagbox').on('mouseover', '.tagview', function( ) {
            var pos = jQuery(this).position();
            jQuery(this).css({opacity: 1.0}); // div appears when opacity is set to 1.
        }).on('mouseout', '.tagview', function( ) {
            jQuery(this).css({opacity: 0.0}); // hide the div by setting opacity to 0.
        });

        // Remove tags.
        jQuery('#taglist').on('click', '.remove', function() {
            id = jQuery(this).parent().attr("id");
            // Remove the tag
            $.ajax({
                type: "POST",
                url: Drupal.settings.basePath + 'removetags',
                data: "tag_id=" + id + "&type=remove",
                success: function(data) {
                    var img = jQuery('#imgtag').find('img');
                    var id = jQuery(img).attr('id');
                    //get tags if present
                     jQuery('#tagit').fadeOut();
                     viewtag(image_fiedlid);
                   
                    
                }
            });
        });

//        // load the tags for the image when page loads.
//        var img = jQuery('#imgtag').find('img');
//        var id = jQuery(img).attr('id');

        viewtag(image_fiedlid); // view all tags available on page load
//
        function viewtag(pic_id)
        {
            
             jQuery.ajax({
                    url: Drupal.settings.basePath + 'gettaglist',
                    type: 'post',
                    data: {'fid': pic_id},
                    success: function(data) {
                         var objdata = jQuery.parseJSON(data);
                     jQuery('#taglist ol').html(objdata.lists);
                     jQuery('#tagbox').html(objdata.boxes);
                    },
                    error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                    }
                    }); 
          

        }
      jQuery('.maptofield').click(function(){
          
        jQuery(window.opener.document).find('[name="' + field_name + '[und][0][fid]"]').val(image_fiedlid);

           window.opener.jQuery("body").find("input[name='" + field_name + "[und][0][filefield_itg_image_repository][button]").trigger('mousedown');
       window.close();
      })

    });
</script> 
<?php die; ?>