(function($) {

    Drupal.behaviors.itg_photogallery_form = {
       attach: function(context, settings) {
           $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
           $('.form-item-field-gallery-image-add-more-number').hide();
            var uid = settings.itg_photogallery.settings.uid;
                        // code to hide body text format filter 
                        if (uid != 1) {
                        $('#edit-field-gallery-kicer-und-0-format').hide();
                        $('#edit-field-photogallery-description-und-0-format').hide();
                        $('.vertical-tabs-list').hide();
                        $('#edit-metatags').show();
                        $('#edit-metatags-und-advanced').hide();

                        }
                $(document).ready(function(){
                    if ($('#edit-field-story-extra-large-image .image-preview').length != 0) {
                         $('.img-crt').click();
                    }
                });        
                $('.img-crt').click(function() {
                var pic = $('#edit-field-story-extra-large-image .image-preview').html();
                var pic = '<div class="jqpicmain"><div class="jqpic">' + pic + '</div><span class="remove-image">Remove</span></div>';
                if ($('#edit-field-story-extra-large-image .image-preview').length != 0) {
                    if ((!$('#edit-field-story-large-image .image-widget').hasClass("custompic")) && ($('#edit-field-story-large-image .image-preview').length == 0)) {
                        $('#edit-field-story-large-image .image-widget-data').hide();
                        $('#edit-field-story-large-image .image-widget').append(pic);
                        $('#edit-field-story-large-image .image-widget').addClass('custompic');
                    }
                    if ((!$('#edit-field-story-medium-image .image-widget').hasClass("custompic")) && ($('#edit-field-story-medium-image .image-preview').length == 0)) {
                        $('#edit-field-story-medium-image .image-widget-data').hide();
                        $('#edit-field-story-medium-image .image-widget').append(pic);
                        $('#edit-field-story-medium-image .image-widget').addClass('custompic');
                    }

                    if ((!$('#edit-field-story-small-image .image-widget').hasClass("custompic")) && ($('#edit-field-story-small-image .image-preview').length == 0)) {
                        $('#edit-field-story-small-image .image-widget-data').hide();
                        $('#edit-field-story-small-image .image-widget').append(pic);
                        $('#edit-field-story-small-image .image-widget').addClass('custompic');
                    }

                    if ((!$('#edit-field-story-extra-small-image .image-widget').hasClass("custompic")) && ($('#edit-field-story-extra-small-image .image-preview').length == 0)) {
                        $('#edit-field-story-extra-small-image .image-widget-data').hide();
                        $('#edit-field-story-extra-small-image .image-widget').append(pic);
                        $('#edit-field-story-extra-small-image .image-widget').addClass('custompic');
                    }
                } else {
                    alert('Please upload Extra large image.');
                }

                $('.image-widget span.remove-image').click(function() {

                    var pid = $(this).parent().parent().parent().parent().attr('id');
                    $('#' + pid + ' .image-widget-data').show();
                    $('#' + pid + ' .image-widget .jqpicmain').remove();
                    $('#' + pid + ' .image-widget').removeClass('custompic');

                });
            });

        }
    }
})(jQuery);