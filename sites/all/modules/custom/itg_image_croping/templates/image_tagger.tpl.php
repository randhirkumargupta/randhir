<style>
    
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
    }
    #tagit .box
    {
        width: 100px;
        height: 100px;
        float: left;
        border: 2px solid rgba(0, 0, 0, 0.5);
        margin-right: 1px;
    }
    #tagit .name
    {
        float: left;
        width: 200px;
        position: relative;
    }
    #tagit .name div.text{display: none;}
    #tagit .name span.error{
        top: 100px;
        position: absolute;
        left: 0;
    }
    #tagit input[type="text"]{
        width: 100%;
        background-color: rgba(0,0,0,.5);
        color: #fff;
        height: 33px;
        border: none;
    }
    #tagit #tagname{
        margin-bottom: 1px;
    }
    #btnsavetag{
        background-color: rgba(31,181,173,.9);
        border: 1px solid rgba(31,181,173,.9);
        border-radius: 0;
        color: #fff;
        cursor: pointer;
        font-size: 14px;
        font-weight: 300;
        padding: 6px 12px;
        text-align: center;
        text-decoration: none;
        white-space: nowrap;
        height: 33px;
        width: 50%;
        
    }
    #btncancel{
        background-color: rgba(208,11,38,.9);
        border: 1px solid rgba(208,11,38,.9);
        border-radius: 0;
        color: #fff;
        cursor: pointer;
        font-size: 14px;
        font-weight: 300;
        padding: 6px 12px;
        text-align: center;
        text-decoration: none;
        white-space: nowrap;
        height: 33px;
        width: 50%;
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
<script type="text/javascript" src="<?php echo base_path() . 'sites/all/modules/custom/itg_image_croping/js/jquery.min.js'; ?>"></script>

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
            id=id.split('_');
            id=id[1];
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
        jQuery('#imgtag').on('click', '.remove', function() {
           id = jQuery(this).parent().attr("id");
            id=id.split('_');
            id=id[1];
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