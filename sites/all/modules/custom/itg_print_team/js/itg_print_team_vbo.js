/**
 * @file
 * A JavaScript file for the theme.
 */
(function ($, Drupal, window, document, undefined) {
Drupal.behaviors.itg_print_vbo = {
  attach: function(context, settings) {
    // module code start here.    
    $('#views-form-manage-print-team-page-1 .form-checkbox').change(function() {        
        if($(this).is(":checked")) {
            var magazine = $(this).parent().siblings().text();            
            $('#edit-pti-magazine option:contains("' + magazine + '")').attr('selected', 'selected');
            $( "#edit-pti-magazine" ).trigger( "change" );
        }        
    });
    
    $('#edit-submit--2').hide();
    $('#edit-submit-rating').hide();
    
    $('.itg-associate').on('click', function(event) {
        event.preventDefault();
        $('#edit-submit--2').trigger('click');
    });
    $('.itg-rating').on('click', function(event) {
        event.preventDefault();
        $('#edit-submit-rating').trigger('click');
    });
    // Module code ends here.
  }
};


})(jQuery, Drupal, this, this.document);
