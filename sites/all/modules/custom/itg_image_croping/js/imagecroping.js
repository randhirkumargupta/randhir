/*
 * @file imagecroping.js
 */

/*
 * @file imagecroping.js
 * Contains all the functionality of image tag edit
 */


(function($) {
    jQuery('.image-preview img').live('click', function() {
        var imageid = jQuery(this).parent().next().find('input[type=hidden]').val();
        var fieldname = jQuery(this).parent().next().find('input[type=hidden]').attr('name');

        var fieldname = fieldname.split('[');


        jQuery.ajax({
            url: Drupal.settings.basePath + 'imagetagedit',
            type: 'post',
            data: {'fid': imageid, 'field_name': fieldname},
            success: function(data) {
                $.colorbox({html: "" + data + "", onComplete: function() {
                        $(this).colorbox.resize();
                    }});


            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    })
})(jQuery);
function showimagerepopopu(iframeurl)
{
    jQuery.colorbox({href: iframeurl, iframe: true, width: "90%", height: "95%", fixed: true});

}

