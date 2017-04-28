/*
 * @file itg_field_mapping.js
 * Contains all the functionality of mapping image to field 
 */
(function($) {
    var counter = 0;
    var mouseX = 0;
    var mouseY = 0;
    var field_name = jQuery('#field_name').val();
    var image_fiedlid = jQuery('#image_fiedlid').val();

    jQuery("#imgtag img").click(function(e) { // make sure the image is click
        var imgtag = jQuery(this).parent(); // get the div to append the tagging list
        mouseX = (e.pageX - jQuery(imgtag).offset().left) - 50; // x and y axis
        mouseY = (e.pageY - jQuery(imgtag).offset().top) - 50;
        jQuery('#tagit').remove( ); // remove any tagit div first
        jQuery(imgtag).append('<div id="tagit"><div class="box"></div><div class="name"><div class="text">Tag</div><input type="text" name="tagname" id="tagname" placeholder="Title"/><input type="text" name="tagurl" class="error" id="tagurl" placeholder="Tag Url" /><span style="display:none" class="error web-error" for="edit-title" generated="true">Enter currect url .</span><input type="button" name="btnsave" value="Save" id="btnsavetag" /><input type="button" name="btncancel" value="Cancel" id="btncancel" /></div></div>');
        jQuery('#tagit').css({top: mouseY, left: mouseX});
        jQuery('#tagname').focus();
    });
    var mTimer = null;
    // Save button click - save tags
    jQuery('#file-preview').on('click', '#btnsavetag', function() {
        window.clearTimeout(mTimer);
        mTimer = window.setTimeout(function() {

            name = jQuery('#tagname').val();
            tagurl = jQuery('#tagurl').val();

            if (tagurl != "")
            {
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

                                jQuery('#tagit').remove();
                                viewtag(image_fiedlid);

                            }

                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });
                } else {
                    jQuery('.web-error').html('Enter currect url').show();
                    return false;
                }
            } else {
                jQuery('.web-error').html('Enter url').show();
                return false;
            }

        }, 200);
    });
//  cancel image
    jQuery('.cancel-image').click(function() {
        if (jQuery('.div-upload-img').hasClass('active'))
        {
            jQuery('#file-preview').hide();
        } else {
            jQuery('#file-preview').hide();
            jQuery('#search-preview').show();
        }
    })

    // Save button click - save tags
    jQuery('#file-preview').on('click', '#btnsavetagedit', function() {
        name = jQuery('#tagname').val();
        tagurl = jQuery('#tagurl').val();
        tagid = jQuery('#tagid').val();

        var img = jQuery('#imgtag').find('img');
        if (/^(http:\/\/www\.|https:\/\/www\.|http:\/\/|https:\/\/|www\.)[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/.test(tagurl)) {
            jQuery('.web-error').hide();
            jQuery.ajax({
                url: Drupal.settings.basePath + 'edittags',
                type: 'post',
                data: {'tagid': tagid, 'name': name, 'url': tagurl, 'pic_x': mouseX, 'pic_y': mouseY, 'type': 'insert'},
                success: function(data) {
                    var objdata = jQuery.parseJSON(data);
                    if (objdata.status == 1)
                    {
                        jQuery('#tagit').remove();
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
        jQuery('#tagit').remove();
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
    jQuery('#tagbox').on('click', '.remove', function() {
        showloader();
        id = jQuery(this).parent().attr("id");
        id = id.split('_');
        id = id[1];
        // Remove the tag
        $.ajax({
            type: "POST",
            url: Drupal.settings.basePath + 'removetags',
            data: "tag_id=" + id + "&type=remove",
            success: function(data) {
                var img = jQuery('#imgtag').find('img');
                var id = jQuery(img).attr('id');
                //get tags if present

                jQuery('#tagit').remove();
                viewtag(image_fiedlid);

            }
        });
    });

// extra lagre

jQuery('.image_courtesy').on('keyup',function() {
  jQuery('.image_courtesy_img').val(jQuery(this).val());
});
jQuery('.image_keyword').on('keyup',function() {
  jQuery('.image_keyword_img').val(jQuery(this).val());
});

jQuery('.image_tags').on('keyup',function() {
  jQuery('.image_tags_img').val(jQuery(this).val());
});
jQuery('.image_place').on('keyup',function() {
  jQuery('.image_place_img').val(jQuery(this).val());
});
jQuery('.image_photo_grapher').on('keyup',function() {
  jQuery('.image_photo_grapher_img').val(jQuery(this).val());
});
jQuery('.image_date').on('keyup',function() {
  jQuery('.image_date_img').val(jQuery(this).val());
});
jQuery('.image_description').on('keyup',function() {
  jQuery('.image_description_img').val(jQuery(this).val());
});
jQuery('.is_synd_all').click(function() {
  if(jQuery(this).is(':checked')) {
    
    jQuery('.is_synd_all_for').prop('checked',true);
  }else {
   jQuery('.is_synd_all_for').prop('checked',false);
  }
});

jQuery('.alt_text').on('keyup',function() {
  jQuery('.alt_text_image').val(jQuery(this).val());
});
jQuery('.image_title').on('keyup',function() {
  jQuery('.image_title_exta').val(jQuery(this).val());
});

    // Remove tags.
    jQuery('#taglist').on('click', '.remove', function() {
        id = jQuery(this).parent().attr("id");
        id = id.split('_');
        id = id[1];
        // Remove the tag
        $.ajax({
            type: "POST",
            url: Drupal.settings.basePath + 'removetags',
            data: "tag_id=" + id + "&type=remove",
            success: function(data) {
                var img = jQuery('#imgtag').find('img');
                var id = jQuery(img).attr('id');
                //get tags if present
                jQuery('#tagit').remove();
                viewtag(image_fiedlid);

            }
        });
    });
    jQuery('#imgtag').on('click', '.edit', function() {
        id = jQuery(this).parent().attr("id");
        id = id.split('_');
        id = id[1];
        $.ajax({
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
                hideloader()
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });


    }
    jQuery('.maptofield').click(function() {
        showloader();
        var form_value = jQuery('#image_teg_form').serialize();
        jQuery.ajax({
            url: Drupal.settings.basePath + 'saveimageinfo',
            type: 'post',
            data: {'form_value': form_value},
            success: function(data) {
                var getbame = jQuery('#btn_name').val();
                var getis_custom_form = jQuery('#is_custom_form').val();
                var original_img_id = jQuery('#orig_image_fiedlid').val();
                var exist_original_id = parent.jQuery('#original_image_fids').val();
                var is_solr = jQuery('#is_solr').val();
                if (original_img_id != "" && is_solr != '1') {
                    if (exist_original_id == "") {
                        parent.jQuery('#original_image_fids').val(original_img_id);
                    } else {
                        original_img_id = exist_original_id + '#' + original_img_id
                        parent.jQuery('#original_image_fids').val(original_img_id);
                    }
                }
                parent.jQuery('#')
                if (jQuery('#ckeditor_yes').val() == 1)
                {
                    if (jQuery('.is_synd').is(':checked')) {
                        var synd_class = "data-syndication='yes'";
                    } else {
                        synd_class = "data-syndication='no'";
                    }
                    var imagename = jQuery('#imcurl').val();
                    var getimagename = '<img ' + synd_class + ' src="' + imagename + '"  alt="" />';
                    parent.jQuery("body", parent.document).find('input.cke_dialog_ui_input_text').val(getimagename);
//
//                    parent.jQuery("body", parent.document).find('input.cke_dialog_ui_input_text:eq(0)').val(jQuery('#imcurl').val());
//                    parent.jQuery("body", parent.document).find('input.cke_dialog_ui_input_text:eq(2)').val(jQuery('#imcwidth').val());
//                    parent.jQuery("body", parent.document).find('input.cke_dialog_ui_input_text:eq(3)').val(jQuery('#imcheigth').val());
                    parent.jQuery.colorbox.close();
                } else {

                    jQuery('.imagefid').each(function() {
                        var getvalue = jQuery(this).val();
                        getvalue = getvalue.split('#');
                        var newbname = getbame;
                    
                     if(getbame.indexOf("field_gallery_image") >=0)
                     {
                      if(getbame.indexOf(getvalue[1])<0) {
                       var replaced = getbame.replace(/field_images/g, getvalue[1]);
                     }else{
                       replaced = newbname;
                     }
                       
                     }else {
                        var replaced = newbname.substring(newbname.indexOf("[") + 1);
                        replaced = getvalue[1] + '[' + replaced;
                      }
                       
                        var field_name = jQuery('#field_name').val();
                        if (getis_custom_form == 1) {
                            parent.jQuery('[name="' + field_name + '[fid]"]').val(image_fiedlid);
                            parent.jQuery('.div_' + field_name).hide();
                            parent.jQuery("body").find("input[name='" + getbame).trigger('mousedown');
                        }
                       
                        parent.jQuery('[name="' + replaced + '[fid]"]').val(getvalue[0]);
                        parent.jQuery("body").find("input[name='" + replaced + "[filefield_itg_image_repository][button]").trigger('mousedown');
                        parent.jQuery('[name="' + getbame + '[fid]"]').val(image_fiedlid);
                        parent.jQuery("body").find("input[name='" + getbame + "[filefield_itg_image_repository][button]").trigger('mousedown');
                        parent.jQuery(document).ajaxComplete(function(event, request, settings) {

                            if (settings.url.indexOf(field_name) >= 0) {
                                if (image_alttext == "")
                                {
                                    var imagealt = jQuery('#imgtag img').attr('src');
                                    var image_alttext = imagealt.substring(imagealt.lastIndexOf("/") + 1, imagealt.length);
                                    image_alttext = image_alttext.substr(0, image_alttext.lastIndexOf('.'));
                                }
                                if (image_title == "")
                                {
                                    var imagetitle = jQuery('#imgtag img').attr('src');
                                    var image_title = imagetitle.substring(imagetitle.lastIndexOf("/") + 1, imagetitle.length);
                                    image_title = image_title.substr(0, image_title.lastIndexOf('.'));
                                }
                                var image_alttext = jQuery('#alt_text_image').val();
                                var image_title = jQuery('#image_title_exta').val();
                                setTimeout(function() {
                                    if (image_alttext != "")
                                    {
                                       // parent.jQuery('[name="' + getbame + '[alt]"]').val(image_alttext);
                                       // parent.jQuery('[name="' + replaced + '[alt]"]').val(image_alttext);
                                    }
                                    if (image_title != "")
                                    {
                                        //parent.jQuery('[name="' + getbame + '[title]"]').val(image_title);
                                       // parent.jQuery('[name="' + replaced + '[title]"]').val(image_title);
                                    }

                                    var credit = parent.jQuery('#edit-field-credit-name-und-0-value').val();
                                    var captionid = getbame + '[field_image_caption][und][0][value]';
                                    captionid = captionid.replace('[field_images][und][0]', "");
                                    var captionid1 = getbame + '[field_credit][und][0][value]';
                                    captionid1 = captionid1.replace('[field_images][und][0]', "");
                                    var syndi = getbame + '[field_image_syndication][und][yes]';
                                    syndi = syndi.replace('[field_images][und][0]', "");
                                    //  parent.jQuery('[name="' + captionid + '"]').val(image_title);
                                    if (jQuery('.is_synd').is(':checked')) {
                                        parent.jQuery('[name="' + syndi + '"]').prop('checked', true);
                                    }
                                    parent.jQuery('[name="' + captionid1 + '"]').val(credit);
                                    hideloader();
                                    parent.jQuery.colorbox.close();
                                }, 500);
                            }

                        });
                    });
                }

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });

    })



})(jQuery, Drupal, this, this.document);
function showloader()
{
    jQuery('#loader-data').show();
}
function hideloader()
{
    jQuery('#loader-data').hide();
}

