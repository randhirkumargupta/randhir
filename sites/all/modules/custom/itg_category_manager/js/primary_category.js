/*
 * @file primary_category.js
 * Contains all functionality related to primary category
 */

(function($) {
    // code use for make primary category
    jQuery('.primary_category_radio').click( function()
    {
       if(jQuery(this).is(':checked'))
       {
           var getval = jQuery(this).val();
           jQuery('#edit-field-primary-category-und-0-value').val(getval);
       }

    }); 

})(jQuery, Drupal, this, this.document);

