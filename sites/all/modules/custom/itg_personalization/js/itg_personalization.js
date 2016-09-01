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
});
