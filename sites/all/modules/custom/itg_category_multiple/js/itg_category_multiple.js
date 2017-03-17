/*
 * @file itg_category_multipal.js
 * Contains all functionality related to multiple category functionality
 */

(function($) {
  Drupal.behaviors.itg_category_multiple = {
    attach: function(context, settings) {

      $('#edit-itg-section').on('change', function() {

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');
        if (categoryies) {
          $.ajax({
            type: 'POST',
            url: Drupal.settings.basePath + 'itg-category-multiple-find',
            data: {data: categoryies, category: $(this).attr('name')},
            success: function(html) {
              $('#edit-itg-category').empty();
              $('#edit-itg-sub-category').empty();
              $('#edit-itg-sub-sub-category').empty();
              $('#edit-itg-sub-sub-sub-category').empty();
              $('#edit-itg-primary-category').empty();
              $('#edit-itg-category').append(html);
              $('#edit-itg-section option:selected').clone().appendTo('#edit-itg-primary-category')
            }
          });
        } else {


        }
      });



      $('#edit-itg-category').on('change', function() {

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');
        if (categoryies) {
          $.ajax({
            type: 'POST',
            url: Drupal.settings.basePath + 'itg-category-multiple-find',
            data: {data: categoryies, category: $(this).attr('name')},
            success: function(html) {
              $('#edit-itg-sub-category').empty();
              $('#edit-itg-sub-sub-category').empty();
              $('#edit-itg-sub-sub-sub-category').empty();
              $('#edit-itg-sub-category').append(html);

              $('#edit-itg-primary-category').empty();
              $('#edit-itg-section option:selected').clone().appendTo('#edit-itg-primary-category')
              $('#edit-itg-category option:selected').clone().appendTo('#edit-itg-primary-category')

            }
          });
        } else {


        }
      });

      $('#edit-itg-sub-category').on('change', function() {

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');
        if (categoryies) {
          $.ajax({
            type: 'POST',
            url: Drupal.settings.basePath + 'itg-category-multiple-find',
            data: {data: categoryies, category: $(this).attr('name')},
            success: function(html) {
              $('#edit-itg-sub-sub-category').empty();
              $('#edit-itg-sub-sub-sub-category').empty();
              $('#edit-itg-sub-sub-category').append(html);
              $('#edit-itg-primary-category').empty();
              $('#edit-itg-section option:selected').clone().appendTo('#edit-itg-primary-category')
              $('#edit-itg-category option:selected').clone().appendTo('#edit-itg-primary-category')
              $('#edit-itg-sub-category option:selected').clone().appendTo('#edit-itg-primary-category')

            }
          });
        } else {


        }
      });


      $('#edit-itg-sub-sub-category').on('change', function() {

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');
        if (categoryies) {
          $.ajax({
            type: 'POST',
            url: Drupal.settings.basePath + 'itg-category-multiple-find',
            data: {data: categoryies, category: $(this).attr('name')},
            success: function(html) {
              $('#edit-itg-sub-sub-sub-category').empty();
              $('#edit-itg-sub-sub-sub-category').append(html);
              $('#edit-itg-primary-category').empty();
              $('#edit-itg-section option:selected').clone().appendTo('#edit-itg-primary-category')
              $('#edit-itg-category option:selected').clone().appendTo('#edit-itg-primary-category')
              $('#edit-itg-sub-category option:selected').clone().appendTo('#edit-itg-primary-category')
              $('#edit-itg-sub-sub-category option:selected').clone().appendTo('#edit-itg-primary-category')

            }
          });
        } else {


        }
      });


      $('#edit-itg-sub-sub-sub-category').on('change', function() {

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');
        if (categoryies) {

          $('#edit-itg-primary-category').empty();
          $('#edit-itg-section option:selected').clone().appendTo('#edit-itg-primary-category')
          $('#edit-itg-category option:selected').clone().appendTo('#edit-itg-primary-category')
          $('#edit-itg-sub-category option:selected').clone().appendTo('#edit-itg-primary-category')
          $('#edit-itg-sub-sub-category option:selected').clone().appendTo('#edit-itg-primary-category')
          $('#edit-itg-sub-sub-sub-category option:selected').clone().appendTo('#edit-itg-primary-category')
          
        } else {


        }
      });






    }

  };
})(jQuery, Drupal, this, this.document);