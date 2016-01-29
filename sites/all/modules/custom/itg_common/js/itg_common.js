/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
        Drupal.behaviors.itg_common = {
             attach: function(context) {                
                 // code for Magazine and Supplement field hide and show
                 $('.form-item-roles').hide();
                 $('#edit-metatags').hide();
                 $('#edit-timezone').hide();
                 $('#edit-selected').change(function() {
                     $('#edit-roles :checkbox:enabled').prop('checked', false);
                     var checkboxId = 'edit-roles-'+$(this).val();                     
                     $( '#'+checkboxId ).prop( "checked", true );
                 });
                 
                
             }

 };
})(jQuery, Drupal, this, this.document);