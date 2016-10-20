(function($) {

    Drupal.behaviors.itg_common_form = {
        attach: function(context, settings) {
            var large_uri = Drupal.settings.itg_common.settings.large_uri;
            $('.img-crt').click(function() {
                if (large_uri) {
                    //alert(large_uri);
                    jQuery('#edit-field-story-large-image-und-0-upload-imce-path').attr('value', large_uri);
                    jQuery('#edit-field-story-medium-image-und-0-upload-imce-path').attr('value', large_uri);
                    jQuery('#edit-field-story-small-image-und-0-upload-imce-path').attr('value', large_uri);
                    jQuery('#edit-field-story-extra-small-image-und-0-upload-imce-path').attr('value', large_uri);

                    jQuery('#edit-field-story-large-image-und-0-upload-imce-select').triggerHandler('mousedown');
                    jQuery('#edit-field-story-small-image-und-0-upload-imce-select').triggerHandler('mousedown');
                    jQuery('#edit-field-story-medium-image-und-0-upload-imce-select').triggerHandler('mousedown');
                    jQuery('#edit-field-story-extra-small-image-und-0-upload-imce-select').triggerHandler('mousedown');

                     jQuery('#edit-field-story-large-image-und-0-upload-itg_image_repository-path').attr('value', large_uri);
                    jQuery('#edit-field-story-medium-image-und-0-upload-itg_image_repository-path').attr('value', large_uri);
                    jQuery('#edit-field-story-small-image-und-0-upload-itg_image_repository-path').attr('value', large_uri);
                    jQuery('#edit-field-story-extra-small-image-und-0-upload-itg_image_repository-path').attr('value', large_uri);

                    jQuery('#edit-field-story-large-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                    jQuery('#edit-field-story-small-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                    jQuery('#edit-field-story-medium-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                    jQuery('#edit-field-story-extra-small-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                    jQuery('.generate-image-error').text('');
                } else {
                    var large_node_uri = Drupal.settings.itg_common.settings.large_node_uri;
                    if (large_node_uri) {
                        jQuery('#edit-field-story-large-image-und-0-upload-imce-path').attr('value', large_node_uri);
                        jQuery('#edit-field-story-medium-image-und-0-upload-imce-path').attr('value', large_node_uri);
                        jQuery('#edit-field-story-small-image-und-0-upload-imce-path').attr('value', large_node_uri);
                        jQuery('#edit-field-story-extra-small-image-und-0-upload-imce-path').attr('value', large_node_uri);

                        jQuery('#edit-field-story-large-image-und-0-upload-imce-select').triggerHandler('mousedown');
                        jQuery('#edit-field-story-small-image-und-0-upload-imce-select').triggerHandler('mousedown');
                        jQuery('#edit-field-story-medium-image-und-0-upload-imce-select').triggerHandler('mousedown');
                        jQuery('#edit-field-story-extra-small-image-und-0-upload-imce-select').triggerHandler('mousedown');


                         jQuery('#edit-field-story-large-image-und-0-upload-itg_image_repository-path').attr('value', large_node_uri);
                        jQuery('#edit-field-story-medium-image-und-0-upload-itg_image_repository-path').attr('value', large_node_uri);
                        jQuery('#edit-field-story-small-image-und-0-upload-itg_image_repository-path').attr('value', large_node_uri);
                        jQuery('#edit-field-story-extra-small-image-und-0-upload-itg_image_repository-path').attr('value', large_node_uri);

                        jQuery('#edit-field-story-large-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                        jQuery('#edit-field-story-small-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                        jQuery('#edit-field-story-medium-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                        jQuery('#edit-field-story-extra-small-image-und-0-upload-itg_image_repository-select').triggerHandler('mousedown');
                        jQuery('.demo').text('');
                    } else {
                        jQuery('.generate-image-error').text('Please first select extra large image');
                        // document.getElementById("demo").innerHTML = "Please first select extra large image";
                    }

                }
            });

        }
    }
})(jQuery);
