
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
                var appenddata = '<div id="smi-popup" class="itg-popup itg-photo-popup">';
                appenddata += '<div class="popup-content">';
                appenddata += '<div class="popup-head">';
                appenddata += '<div class="popup-title">&nbsp;</div>';
                appenddata += '<a class="itg-close-popup_new" href="javascript:;"> <i class="fa fa-times" aria-hidden="true"></i> </a>';
                appenddata += '</div>';
                appenddata += '<div class="popup-body">';
                appenddata += data;
                appenddata += '</div></div> </div>';

                $('#page').append(appenddata);
                $('#smi-popup').show();
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
        jQuery.ajax({
            url: Drupal.settings.basePath + 'imagetagedit',
            type: 'post',
            data: {'fid': imageid, 'field_name': fieldname},
            success: function(data) {
                var appenddata = '<div id="smi-popup" class="itg-popup">';
                appenddata += '<div class="popup-content">';
                appenddata += '<div class="popup-head">';
                appenddata += '<div class="popup-title">&nbsp;</div>';
                appenddata += '<a class="itg-close-popup_new" href="javascript:;"> Close </a>';
                appenddata += '</div>';
                appenddata += '<div class="popup-body">';
                appenddata += data;
                appenddata += '</div></div> </div>';

                $('#page').append(appenddata);
                $('#smi-popup').show();
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

