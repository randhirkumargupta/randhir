/*
 * @file imagecroping.js
 */

/*
 * @file imagecroping.js
 * Contains all the functionality of image tag edit
 */

(function($) {
   jQuery('.image-preview').live('click',function(){
     var imageid=jQuery(this).next().find('input[type=hidden]').val();
    var fieldname=jQuery(this).next().find('input[type=hidden]').attr('name');
    
     var fieldname=fieldname.split('[');
     jQuery(this).next().append('<div id=tag_edit_'+fieldname[0]+'></div>');
     
         jQuery.ajax({
                    url: Drupal.settings.basePath + 'imagetagedit',
                    type: 'post',
                    data: {'fid': imageid, 'field_name': fieldname},
                    success: function(data) {
                   jQuery('#tag_edit_'+fieldname[0]).html(data);
                  // jQuery('.image-preview').html(data);
                    
                    },
                    error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                    }
                    }); 
   })
})(jQuery)