(function($) {

    Drupal.behaviors.itg_photogallery_form = {
        attach: function(context, settings) {
            
            jQuery("#edit-field-featured-value-op").on('change',function(){
              var operator = jQuery(this).val();
              if(operator == 'and') {
                jQuery('#edit-field-featured-value option[value=yes]').attr('selected','selected');
              }
              if(operator == 'or' || operator == 'empty') {
                jQuery('#edit-field-featured-value option[value=All]').attr('selected','selected');
              }
              console.log(jQuery(this).val());
            });
        }
    }
})(jQuery);