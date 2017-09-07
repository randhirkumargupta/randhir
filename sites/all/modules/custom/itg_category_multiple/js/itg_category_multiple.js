/*
 * @file itg_category_multipal.js
 * Contains all functionality related to multiple category functionality
 */

$ = jQuery;
$(document).ready(function() {
    var currentSectionRequest = null;
    var currentCategoryRequest = null;
    var currentsubCategoryRequest = null;
    var currentsubsubCategoryRequest = null;
    var currentsubsubsubCategoryRequest = null;

    // Hiding category
    $('.form-field-name-field-story-category').hide();

    if (!$('#edit-itg-category').val()) {
        $('.form-item-itg-category').hide();
    }

    if (!$('#edit-itg-sub-category').val()) {
        $('.form-item-itg-sub-category').hide();
    }

    if (!$('#edit-itg-sub-sub-category').val()) {
        $('.form-item-itg-sub-sub-category').hide();
    }

    if (!$('#edit-itg-sub-sub-sub-category').val()) {
        $('.form-item-itg-sub-sub-sub-category').hide();
    }

    //Adding css for  primary category
    $("#edit-itg-primary-category").css("height", "100px");
    $("#edit-itg-primary-category").css("overflow-x", "auto");

    $('#edit-itg-section').on('change', function() {
        var categoryies = $(this).val();

        var actual_dom_name = $(this).attr('name');

        // Saving the extra data for the section 
        var category_extra_data = {};
        category_extra_data.section = $(this).val(); // Setting for section 
        $('input[name="field_story_extra_data[und][0][value]"]').val(btoa(JSON.stringify(category_extra_data)));

        if (categoryies) {
            $('#edit-field-story-category-und').val('');
            $('#edit-field-story-category-und').val($('#edit-itg-section').val());

            // show/hiding some fields  
            $('.form-item-itg-sub-category').hide();
            $('.form-item-itg-sub-sub-category').hide();
            $('.form-item-itg-sub-sub-sub-category').hide();


            currentSectionRequest = $.ajax({
                type: 'POST',
                url: Drupal.settings.basePath + 'itg-category-multiple-find',
                beforeSend: function() {
                    if (currentSectionRequest != null) {
                        currentSectionRequest.abort();
                    }
                },
                data: {
                    type: $(this).attr('name'),
                    section: JSON.stringify(categoryies),
                    pcat: $('#edit-field-primary-category-und-0-value').attr('value')
                },
                success: function(html) {
                    var item = JSON.parse(html);
                    if (item.main.length > 0) {
                        $('.form-item-itg-category').show();
                    }
                    else {
                        $('.form-item-itg-category').hide();
                    }
                    $('#edit-itg-category').empty();
                    $('#edit-itg-sub-category').empty();
                    $('#edit-itg-sub-sub-category').empty();
                    $('#edit-itg-sub-sub-sub-category').empty();
                    $('#edit-itg-primary-category').empty();
                    $('#edit-itg-category').append(item.main);
                    $('#edit-itg-primary-category').append(item.primary);
                    if (item.pcat.length > 0) {
                      $('#edit-field-primary-category-und-0-value').attr('value', item.pcat)
                      $('#edit-itg-primary-category').val(item.pcat);
                    }
                }
            });
        } else {


        }
    });

    $('#edit-itg-category').on('change', function() {

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');

        // Saving the extra data for the category 
        var category_extra_data = {};
        category_extra_data.section = jQuery('#edit-itg-section').val(); // Setting for section 
        category_extra_data.category = jQuery('#edit-itg-category').val(); // Setting for category 
        $('input[name="field_story_extra_data[und][0][value]"]').val(btoa(JSON.stringify(category_extra_data)));

        if (categoryies) {
            jQuery('#edit-field-story-category-und').val('');
            jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()));

            $('.form-item-itg-sub-sub-category').hide();
            $('.form-item-itg-sub-sub-sub-category').hide();

            currentCategoryRequest = $.ajax({
                type: 'POST',
                url: Drupal.settings.basePath + 'itg-category-multiple-find',
                beforeSend: function() {
                    if (currentCategoryRequest != null) {
                        currentCategoryRequest.abort();
                    }
                },
                data: {
                    type: $(this).attr('name'),
                    section: JSON.stringify($('#edit-itg-section').val()),
                    category: JSON.stringify(categoryies),
                    pcat: $('#edit-field-primary-category-und-0-value').attr('value')
                },
                success: function(html) {
                    var item = JSON.parse(html);

                    if (item.main.length > 0) {
                        $('.form-item-itg-sub-category').show();
                    }
                    else {
                        $('.form-item-itg-sub-category').hide();
                    }

                    $('#edit-itg-sub-category').empty();
                    $('#edit-itg-sub-sub-category').empty();
                    $('#edit-itg-sub-sub-sub-category').empty();
                    $('#edit-itg-primary-category').empty();
                    $('#edit-itg-sub-category').append(item.main);
                    $('#edit-itg-primary-category').append(item.primary);
                    if (item.pcat.length > 0) {
                        $('#edit-field-primary-category-und-0-value').attr('value', item.pcat)
                        $('#edit-itg-primary-category').val(item.pcat);
                    }

                }
            });
        } else {

        }
    });

    $('#edit-itg-sub-category').on('change', function() {

        // Saving the extra data for the sub category 
        var category_extra_data = {};
        category_extra_data.section = jQuery('#edit-itg-section').val(); // Setting for section 
        category_extra_data.category = jQuery('#edit-itg-category').val(); // Setting for category 
        category_extra_data.sub_category = jQuery('#edit-itg-sub-category').val(); // Setting for sub category
        $('input[name="field_story_extra_data[und][0][value]"]').val(btoa(JSON.stringify(category_extra_data)));

        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');

        if (categoryies) {
            jQuery('#edit-field-story-category-und').val('');
            jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()).concat($(this).val()));

            $('.form-item-itg-sub-sub-sub-category').hide();
            currentsubCategoryRequest = $.ajax({
                type: 'POST',
                url: Drupal.settings.basePath + 'itg-category-multiple-find',
                beforeSend: function() {
                    if (currentsubCategoryRequest != null) {
                        currentsubCategoryRequest.abort();
                    }
                },
                data: {
                    type: $(this).attr('name'),
                    section: JSON.stringify($('#edit-itg-section').val()),
                    category: JSON.stringify($('#edit-itg-category').val()),
                    sub_category: JSON.stringify(categoryies),
                    pcat: $('#edit-field-primary-category-und-0-value').attr('value')
                },
                success: function(html) {
                    var item = JSON.parse(html);
                    if (item.main.length > 0) {
                        $('.form-item-itg-sub-sub-category').show();
                    }
                    else {
                        $('.form-item-itg-sub-sub-category').hide();
                    }
                    $('#edit-itg-sub-sub-category').empty();
                    $('#edit-itg-sub-sub-sub-category').empty();
                    $('#edit-itg-primary-category').empty();
                    $('#edit-itg-sub-sub-category').append(item.main);
                    $('#edit-itg-primary-category').append(item.primary);
                    if (item.pcat.length > 0) {
                      $('#edit-field-primary-category-und-0-value').attr('value', item.pcat)
                      $('#edit-itg-primary-category').val(item.pcat);
                    }

                }
            });
        } else {

        }
    });


    $('#edit-itg-sub-sub-category').on('change', function() {
        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');

        // Saving the extra data for the sub sub category 
        var category_extra_data = {};
        category_extra_data.section = jQuery('#edit-itg-section').val(); // Setting for section 
        category_extra_data.category = jQuery('#edit-itg-category').val(); // Setting for category 
        category_extra_data.sub_category = jQuery('#edit-itg-sub-category').val(); // Setting for sub category
        category_extra_data.sub_sub_category = jQuery('#edit-itg-sub-sub-category').val(); // Setting for sub sub category
        $('input[name="field_story_extra_data[und][0][value]"]').val(btoa(JSON.stringify(category_extra_data)));

        jQuery('#edit-field-story-category-und').val('');
        jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()).concat(jQuery('#edit-itg-sub-category').val()).concat($(this).val()));

        if (categoryies) {
            currentsubsubCategoryRequest = $.ajax({
                type: 'POST',
                url: Drupal.settings.basePath + 'itg-category-multiple-find',
                beforeSend: function() {
                    if (currentsubsubCategoryRequest != null) {
                        currentsubsubCategoryRequest.abort();
                    }
                },
                data: {
                    type: $(this).attr('name'),
                    section: JSON.stringify($('#edit-itg-section').val()),
                    category: JSON.stringify($('#edit-itg-category').val()),
                    sub_category: JSON.stringify($('#edit-itg-sub-category').val()),
                    sub_sub_category: JSON.stringify(categoryies),
                    pcat: $('#edit-field-primary-category-und-0-value').attr('value')

                },
                success: function(html) {
                    var item = JSON.parse(html);

                    if (item.main.length > 0) {
                        $('.form-item-itg-sub-sub-sub-category').show();
                    }
                    else {
                        $('.form-item-itg-sub-sub-sub-category').hide();
                    }

                    $('#edit-itg-sub-sub-sub-category').empty();
                    $('#edit-itg-primary-category').empty();
                    $('#edit-itg-sub-sub-sub-category').append(item.main);
                    $('#edit-itg-primary-category').append(item.primary);
                     if (item.pcat.length > 0) {
                      $('#edit-field-primary-category-und-0-value').attr('value', item.pcat)
                      $('#edit-itg-primary-category').val(item.pcat);
                    }

                }
            });
        } else {

        }
    });


    $('#edit-itg-sub-sub-sub-category').on('change', function() {
        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');

        // Saving the extra data for the sub sub sub category 
        var category_extra_data = {};
        category_extra_data.section = jQuery('#edit-itg-section').val(); // Setting for section 
        category_extra_data.category = jQuery('#edit-itg-category').val(); // Setting for category 
        category_extra_data.sub_category = jQuery('#edit-itg-sub-category').val(); // Setting for sub category
        category_extra_data.sub_sub_category = jQuery('#edit-itg-sub-sub-category').val(); // Setting for sub sub category
        category_extra_data.sub_sub_sub_category = jQuery('#edit-itg-sub-sub-sub-category').val(); // Setting for sub sub sub category
        $('input[name="field_story_extra_data[und][0][value]"]').val(btoa(JSON.stringify(category_extra_data)));

        jQuery('#edit-field-story-category-und').val('');
        jQuery('#edit-field-story-category-und').val(jQuery('#edit-itg-section').val().concat(jQuery('#edit-itg-category').val()).concat(jQuery('#edit-itg-sub-category').val()).concat(jQuery('#edit-itg-sub-sub-category').val()).concat($(this).val()));

        if (categoryies) {
            currentsubsubsubCategoryRequest = $.ajax({
                type: 'POST',
                url: Drupal.settings.basePath + 'itg-category-multiple-find',
                beforeSend: function() {
                    if (currentsubsubsubCategoryRequest != null) {
                        currentsubsubsubCategoryRequest.abort();
                    }
                },
                data: {
                    type: $(this).attr('name'),
                    section: JSON.stringify($('#edit-itg-section').val()),
                    category: JSON.stringify($('#edit-itg-category').val()),
                    sub_category: JSON.stringify($('#edit-itg-sub-category').val()),
                    sub_sub_category: JSON.stringify($('#edit-itg-sub-sub-category').val()),
                    sub_sub_sub_category: JSON.stringify(categoryies),
                    type: $(this).attr('name'),
                    pcat: $('#edit-field-primary-category-und-0-value').attr('value')

                },
                success: function(html) {
                    var item = JSON.parse(html);
                    $('#edit-itg-primary-category').empty();
                    $('#edit-itg-primary-category').append(item.primary);
                     if (item.pcat.length > 0) {
                      $('#edit-field-primary-category-und-0-value').attr('value', item.pcat)
                      $('#edit-itg-primary-category').val(item.pcat);
                    }

                }
            });
        } else {

        }
    });



    // Setting the value for  the primary category
    $('#edit-itg-primary-category').on('change', function() {
        var categoryies = $(this).val();
        var actual_dom_name = $(this).attr('name');

        // Saving the extra data for the primary category 
        var category_extra_data = {};
        category_extra_data.section = jQuery('#edit-itg-section').val(); // Setting for section 
        category_extra_data.category = jQuery('#edit-itg-category').val(); // Setting for category 
        category_extra_data.sub_category = jQuery('#edit-itg-sub-category').val(); // Setting for sub category
        category_extra_data.sub_sub_category = jQuery('#edit-itg-sub-sub-category').val(); // Setting for sub sub category
        category_extra_data.sub_sub_sub_category = jQuery('#edit-itg-sub-sub-sub-category').val(); // Setting for sub sub sub category
        category_extra_data.primary_category = jQuery('#edit-itg-primary-category').val(); // Setting for primary category
        $('input[name="field_story_extra_data[und][0][value]"]').val(btoa(JSON.stringify(category_extra_data)));

        if (categoryies) {
            jQuery('#edit-field-primary-category-und-0-value').attr('value', categoryies);
        } else {

        }
    });

});