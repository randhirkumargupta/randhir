/*
 * @file itg_category_multipal.js
 * Contains all functionality related to multiple category functionality
 */

$ = jQuery;
$(document).ready(function() {
  $('#edit-itg-section').on('change', function() {
    var categoryies = $(this).val();
    var actual_dom_name = $(this).attr('name');
    if (categoryies) {
      $('#edit-field-story-category-und').val('');
      $('#edit-field-story-category-und').val($('#edit-itg-section').val());
      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + 'itg-category-multiple-find',
        data: {section: categoryies, type: $(this).attr('name')},
        success: function(html) {
          var item = JSON.parse(html);
          $('#edit-itg-category').empty();
          $('#edit-itg-sub-category').empty();
          $('#edit-itg-sub-sub-category').empty();
          $('#edit-itg-sub-sub-sub-category').empty();
          $('#edit-itg-primary-category').empty();
          $('#edit-itg-category').append(item.main);
          $('#edit-itg-primary-category').append(item.primary);
        }
      });
    } else {


    }
  });



  $('#edit-itg-category').on('change', function() {


    var categoryies = $(this).val();
    var actual_dom_name = $(this).attr('name');

    if (categoryies) {

      jQuery('#edit-field-story-category-und').val('');
      jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()));


      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + 'itg-category-multiple-find',
        data: {
          section: $('#edit-itg-section').val(),
          category: categoryies,
          type: $(this).attr('name')
        },
        success: function(html) {
          var item = JSON.parse(html);
          $('#edit-itg-sub-category').empty();
          $('#edit-itg-sub-sub-category').empty();
          $('#edit-itg-sub-sub-sub-category').empty();
          $('#edit-itg-primary-category').empty();
          $('#edit-itg-sub-category').append(item.main);
          $('#edit-itg-primary-category').append(item.primary);

        }
      });
    } else {

    }
  });

  $('#edit-itg-sub-category').on('change', function() {

    var categoryies = $(this).val();
    var actual_dom_name = $(this).attr('name');

    if (categoryies) {

      jQuery('#edit-field-story-category-und').val('');
      jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()).concat($(this).val()));


      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + 'itg-category-multiple-find',
        data: {
          section: $('#edit-itg-section').val(),
          category: $('#edit-itg-category').val(),
          sub_category: categoryies,
          type: $(this).attr('name')
        },
        success: function(html) {
          var item = JSON.parse(html);
          $('#edit-itg-sub-sub-category').empty();
          $('#edit-itg-sub-sub-sub-category').empty();
          $('#edit-itg-primary-category').empty();
          $('#edit-itg-sub-sub-category').append(item.main);
          $('#edit-itg-primary-category').append(item.primary);

        }
      });
    } else {


    }
  });


  $('#edit-itg-sub-sub-category').on('change', function() {



    var categoryies = $(this).val();
    var actual_dom_name = $(this).attr('name');

    jQuery('#edit-field-story-category-und').val('');
    jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()).concat(jQuery('#edit-itg-sub-category').val()).concat($(this).val()));


    if (categoryies) {
      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + 'itg-category-multiple-find',
        data: {
          section: $('#edit-itg-section').val(),
          category: $('#edit-itg-category').val(),
          sub_category: $('#edit-itg-sub-category').val(),
          sub_sub_category: categoryies,
          type: $(this).attr('name')
        },
        success: function(html) {
          var item = JSON.parse(html);
          $('#edit-itg-sub-sub-sub-category').empty();
          $('#edit-itg-primary-category').empty();
          $('#edit-itg-sub-sub-sub-category').append(item.main);
          $('#edit-itg-primary-category').append(item.primary);

        }
      });
    } else {


    }
  });


  $('#edit-itg-sub-sub-sub-category').on('change', function() {
    var categoryies = $(this).val();
    var actual_dom_name = $(this).attr('name');

    jQuery('#edit-field-story-category-und').val('');
    jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()).concat(jQuery('#edit-itg-sub-category').val()).concat(jQuery('#edit-itg-sub-sub-category').val()).concat($(this).val()));



    if (categoryies) {
      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + 'itg-category-multiple-find',
        data: {
          section: $('#edit-itg-section').val(),
          category: $('#edit-itg-category').val(),
          sub_category: $('#edit-itg-sub-category').val(),
          sub_sub_category: $('#edit-itg-sub-sub-category').val(),
          sub_sub_sub_category: categoryies,
          type: $(this).attr('name')
        },
        success: function(html) {
          var item = JSON.parse(html);
          $('#edit-itg-primary-category').empty();
          $('#edit-itg-primary-category').append(item.primary);

        }
      });
    } else {
    }
  });
});



// }

// };
//})(jQuery, Drupal, this, this.document);