/**
 * @file
 * A javascript file for itg_personalization module.
 */
jQuery(document).ready(function () {
    // Hide my content listing 
    var ctype = jQuery("select[name='field_ugc_ctype[und]']").find('option:selected').val();
    if (ctype == '_none') {
        jQuery('#block-views-c3b0c328c45542af0b403435a6097179').show();
        jQuery('.form-field-name-field-user-message').hide();
    } else {
        jQuery('#block-views-c3b0c328c45542af0b403435a6097179').hide();
    }
    if (ctype == 'blog') {
        jQuery('.form-field-name-field-user-message').show();
    }
    jQuery("select[name='field_ugc_ctype[und]']").on('change', function () {
        var ctype = jQuery(this).find('option:selected').val();
        // Show hide content listing block.
        if (ctype == '_none') {
            jQuery('#block-views-c3b0c328c45542af0b403435a6097179').show();
        } else {
            jQuery('#block-views-c3b0c328c45542af0b403435a6097179').hide();
        }        
        
        switch (ctype) {
            case 'story':                
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'blog':                
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'photogallery':                
                jQuery('.form-field-name-field-user-message').hide();
                break;
            case 'recipe':                
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'videogallery':                
                jQuery('.form-field-name-field-user-message').show();
                break;
            default:
                jQuery('.form-field-name-field-user-message').hide();
        }
        
    });
    // Remove not required options from ugc_content_type.
    jQuery("#edit-field-ugc-ctype-und option[value='podcast']").remove();
    // Change text of select option.
    jQuery("#edit-field-ugc-ctype-und option[value='photogallery']").text('Photogallery');
    jQuery("#edit-field-ugc-ctype-und option[value='videogallery']").text('Videogallery');

    jQuery("#views-form-personalization-my-preferences-block #edit-reset")
            .appendTo("#views-form-personalization-my-preferences-block #edit-actions");

    // Hide remove button
    jQuery('input[name="field_ugc_personalization_photo_und_0_remove_button"]').hide();
});
