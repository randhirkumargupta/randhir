/* 
 * Javascript for manageing the multiple category 
 */

jQuery('document').ready(function() {

  jQuery('.itg-category-section').click(function() {

    jQuery.ajax({
      type: 'POST',
      url: Drupal.settings.basePath + "itg-category-multiple-find",
      data: itg_category,
      dataType: "text",
      success: function(resultData) {

      }
    });
  });

});