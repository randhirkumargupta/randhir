(function ($) {
    
    Drupal.behaviors.itg_image_thumb= {
        attach: function (context, settings) {
            var image_checkbox_id = settings.itg_image_thumb.settings.image_checkbox;
            var story_form_id = settings.itg_image_thumb.settings.story_form_id;
            $('#'+image_checkbox_id, context).click(function (event) {
                if ($(this).attr("checked")) {
                    event.preventDefault();

                    // get form value in serialize array      
                    var frm=$("#"+story_form_id).serializeArray();// temp code
                    
                    // fetch position of image element from array
                    var fid =frm[25].value;

                    //console.log(fid);
                    // passing the value using 'POST' method

                    var dt = 'fid='+fid;
                    var base_url = settings.itg_image_thumb.settings.base_url; 

                    $.ajax({
                    'url':base_url + '/itgimagethumb-ajax',
                    'data': dt,
                    'type': 'POST',
                    success: function(data) {
                        jQuery('#edit-field-story-large-image .filefield-source-imce').hide();
                        jQuery('#edit-field-story-large-image').append('<div><img width="100" height="75" alt="" src="http://localhost/itgcms/sites/default/files/styles/thumbnail/public/IMG_2507.JPG?itok=_FLApB6s" typeof="foaf:Image" /></div><div>remove</div>');
                        

                    }
                    });
                }
            // ajax close
            }

            // else close
            );
        }
    };
})(jQuery);
