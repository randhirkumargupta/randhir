/**
 * @file
 * A javascript file for itg_personalization module.
 */
jQuery(document).ready(function () {
    // Hide my content listing 
    var ctype = jQuery("select[name='field_ugc_ctype[und]']").find('option:selected').val();
    if (ctype == '_none') {
        jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').show();
        jQuery('.form-field-name-field-user-message').hide();
    } else {
        jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').hide();
    }
    if (ctype == 'blog') {
        jQuery('.form-field-name-field-user-message').show();
    }
    jQuery("select[name='field_ugc_ctype[und]']").on('change', function () {
        var ctype = jQuery(this).find('option:selected').val();
        // Show hide content listing block.
        if (ctype == '_none') {
            jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').show();
        } else {
            jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').hide();
        }        
        
        switch (ctype) {
            case 'story':
                jQuery('.form-item-title label').html('Story Title <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-item-field-user-message-und-0-value label').html('Story Body <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'blog':
                jQuery('.form-item-title label').html('Title <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-item-field-user-message-und-0-value label').html('Description <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'photogallery':
                jQuery('.form-item-title label').html('Photo Title <span class="form-required" title="This field is required.">*</span>');                
                jQuery('.form-field-name-field-user-message').hide();
                break;
            case 'recipe':
                jQuery('.form-item-title label').html('Title <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-item-field-user-message-und-0-value label').html('Description <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'videogallery':
                jQuery('.form-item-title label').html('Video Title <span class="form-required" title="This field is required.">*</span>');
                jQuery('.form-item-field-user-message-und-0-value label').html('Video Description <span class="form-required" title="This field is required.">*</span>');                
                jQuery('.form-field-name-field-user-message').show();
        }
        
    });
    // Remove not required options from ugc_content_type.
    jQuery("#edit-field-ugc-ctype-und option[value='podcast']").remove();
    // Change text of select option.
    jQuery("#edit-field-ugc-ctype-und option[value='photogallery']").text('Photo');
    jQuery("#edit-field-ugc-ctype-und option[value='videogallery']").text('Video');

    jQuery("#views-form-personalization-my-preferences-block #edit-reset")
            .appendTo("#views-form-personalization-my-preferences-block #edit-actions");

    // Hide remove button
    jQuery('input[name="field_ugc_personalization_photo_und_0_remove_button"]').hide();
});
