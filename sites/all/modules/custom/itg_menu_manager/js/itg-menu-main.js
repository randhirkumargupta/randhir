(function($) {
    Drupal.behaviors.itg_menu_manager_form = {
        attach: function(context, settings) {
          
            jQuery(document).ajaxStart(function() {
                jQuery("#widget-ajex-loader").show();
            });
            
            jQuery(document).ajaxSuccess(function() {
                $("#widget-ajex-loader").css("display", "none");
                var url_type = $('input[name=url_type]:checked').val();
                if(url_type == 'internal') {
                  $('#edit-category-icon-ajax-wrapper').css("display", "none");
                }
                else{
                  $('#edit-category-icon-ajax-wrapper').css("display", "block");
                }
            });
            
            
            jQuery("#edit-section-child").on('change', function() {
                var section_chlid = jQuery(this).val();
                jQuery("#edit-section-id").val(section_chlid);
            });
            
            jQuery(document).ready(function(){
              var url_type = $('input[name=url_type]:checked').val();
              if(url_type == 'internal') {
                $('#edit-category-icon-ajax-wrapper').css("display", "none");
              }
              else{
                $('#edit-category-icon-ajax-wrapper').css("display", "block");
              }
            });

        }
    };
})(jQuery);