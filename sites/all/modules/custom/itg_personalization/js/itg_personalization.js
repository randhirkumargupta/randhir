/**
 * @file
 * A javascript file for itg_personalization module.
 */
jQuery(document).ready(function () {    
    // Hide my content listing 
    var ctype = jQuery("select[name='field_ugc_ctype[und]']").find('option:selected').val();
    if (ctype == '_none') {
            jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').show();
        }
        else {
            jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').hide();
        }
    jQuery("select[name='field_ugc_ctype[und]']").on('change', function () {        
        var ctype = jQuery(this).find('option:selected').val();
        if (ctype == '_none') {
            jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').show();
        }
        else {
            jQuery('#block-views-7a788d5fc14ed02cf09fe6aa1d609c28').hide();
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
