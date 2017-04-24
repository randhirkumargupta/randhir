/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*! jQuery v1.7 jquery.com | jquery.org/license */
var mTimer = null;
jQuery(document).ready(function() {
    var counter = 0;
    var mouseX = 0;
    var mouseY = 0;
    var image_fiedlid = document.getElementById("image_fiedlid").value;

    jQuery("#imgtag img").on('click', function(e) { // make sure the image is click
        var imgtag = jQuery(this).parent(); // get the div to append the tagging list
        mouseX = (e.pageX - jQuery(imgtag).offset().left) - 50; // x and y axis
        mouseY = (e.pageY - jQuery(imgtag).offset().top) - 50;
        jQuery('#tagit').remove( ); // remove any tagit div first
        jQuery(imgtag).append('<div id="tagit"><div class="box"></div><div class="name"><div class="text">Tag</div><input type="text" name="tagname" id="tagname" placeholder="Title"/><input type="text" name="tagurl" class="error" id="tagurl" placeholder="Tag Url" /><span style="display:none" class="error web-error" for="edit-title" generated="true">Enter currect url .</span><input type="button" name="btnsave" value="Save" id="btnsavetag" /><input type="button" name="btncancel" value="Cancel" id="btncancel" /></div></div>');
        jQuery('#tagit').css({top: mouseY, left: mouseX});
        jQuery('#tagname').focus();
    });

    // Save button click - save tags
    jQuery(document).on('click', '#tagit #btnsavetag', function() {
        name = jQuery('#tagname').val();
        tagurl = jQuery('#tagurl').val();

        window.clearTimeout(mTimer);
        mTimer = window.setTimeout(function() {

            var img = jQuery('#imgtag').find('img');
            if (/^(http:\/\/www\.|https:\/\/www\.|http:\/\/|https:\/\/|www\.)[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/.test(tagurl)) {
                jQuery('.web-error').hide();
                showloader();
                jQuery.ajax({
                    url: Drupal.settings.basePath + 'savetags',
                    type: 'post',
                    data: {'pic_id': image_fiedlid, 'name': name, 'url': tagurl, 'pic_x': mouseX, 'pic_y': mouseY, 'type': 'insert'},
                    success: function(data) {
                        var objdata = jQuery.parseJSON(data);
                        if (objdata.status == 1)
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

        }, 200);
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
    jQuery('.tagview').live('mouseover', function( ) {
        var pos = jQuery(this).position();
        jQuery(this).css({opacity: 1.0});
        jQuery(this).siblings('.square-tag').hide();// div appears when opacity is set to 1.
    }).live('mouseout', '.tagview', function( ) {
        jQuery(this).css({opacity: 0.0});
        jQuery(this).siblings('.square-tag').show(); // hide the div by setting opacity to 0.
    });
    // Save button click - save tags
    jQuery('#btnsavetagedit').live('click', function() {
        name = jQuery('#tagname').val();
        tagurl = jQuery('#tagurl').val();
        tagid = jQuery('#tagid').val();


        var img = jQuery('#imgtag').find('img');
        if (/^(http:\/\/www\.|https:\/\/www\.|http:\/\/|https:\/\/|www\.)[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/.test(tagurl)) {
            jQuery('.web-error').hide();
            showloader();
            jQuery.ajax({
                url: Drupal.settings.basePath + 'edittags',
                type: 'post',
                data: {'tagid': tagid, 'name': name, 'url': tagurl, 'pic_x': mouseX, 'pic_y': mouseY, 'type': 'insert'},
                success: function(data) {
                    var objdata = jQuery.parseJSON(data);
                    if (objdata.status == 1)
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


    // Remove tags.
    jQuery('.remove').live('click', function() {
        id = jQuery(this).parent().attr("id");
        id = id.split('_');
        id = id[1];
        showloader();
        // Remove the tag
        jQuery.ajax({
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
    jQuery('.edit').live('click', function() {
        id = jQuery(this).parent().attr("id");
        id = id.split('_');
        id = id[1];
        jQuery.ajax({
            type: "POST",
            url: Drupal.settings.basePath + 'gettags',
            data: "tag_id=" + id,
            success: function(data) {
                var objdata = jQuery.parseJSON(data);
                var tags = objdata.tag_title;
                var url = objdata.tag_url;
                var xcord = objdata.x_coordinate;
                var ycord = objdata.y_coordinate;
                jQuery('#tagit').remove( ); // remove any tagit div first
                jQuery('#imgtag').append('<div id="tagit"  style="top: ' + ycord + 'px; left: ' + xcord + 'px;"><div class="box"></div><div class="name"><div class="text">Tag</div><input type="text" name="tagname" id="tagname" placeholder="Title" value="' + tags + '"/><input type="hidden" name="tagid" id="tagid" value="' + id + '"/><input type="text" value="' + url + '" name="tagurl" class="error" id="tagurl" placeholder="Tag Url" /><span style="display:none" class="error web-error" for="edit-title" generated="true">Enter currect url .</span><input type="button" name="btnsave" value="Save" id="btnsavetagedit" /><input type="button" name="btncancel" value="Cancel" id="btncancel" /></div></div>');
                jQuery('#tagname').focus();

            }
        });
    });
    jQuery('#imgtag').on('click', '.remove', function() {
        id = jQuery(this).parent().attr("id");
        id = id.split('_');
        id = id[1];
        showloader();
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
    viewtag(image_fiedlid);

});

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
            hideloader();
        },
        error: function(xhr, desc, err) {
            console.log(xhr);
            console.log("Details: " + desc + "\nError:" + err);
        }
    });


}

function showloader()
{
    jQuery('#loader-data').show();
}
function hideloader()
{
    jQuery('#loader-data').hide();
}
 