(function($) {

    Drupal.behaviors.itg_photogallery_form = {
       attach: function(context, settings) {
            var uid = settings.itg_photogallery.settings.uid;
                        // code to hide body text format filter 
                        if (uid != 1) {
                        $('#edit-field-gallery-kicer-und-0-format').hide();
                        $('#edit-field-photogallery-description-und-0-format').hide();
                        $('.vertical-tabs-list').hide();
                        $('#edit-metatags').show();
                        $('#edit-metatags-und-advanced').hide();

                        }        
        }
    }
})(jQuery);