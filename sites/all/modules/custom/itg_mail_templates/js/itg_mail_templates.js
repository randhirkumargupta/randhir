jQuery(document).ready(function () {
    var default_title = jQuery('#edit-field-mail-templates-category-und option:selected').text(); 
    jQuery('#edit-title').val(default_title);
    
    jQuery('#edit-field-mail-templates-category-und').change(function(){
        var select_option = jQuery('#edit-field-mail-templates-category-und option:selected').text(); 
        jQuery('#edit-title').val(select_option);
    });
    var selected_value = jQuery('.form-field-name-field-mail-templates-category select option:selected').val();
        jQuery('.node-mail_templates-form').find('.mail-template-category').hide().siblings('.' + selected_value).show();
        jQuery('.form-field-name-field-mail-templates-category').on('change', 'select', function(){
        var selected_value = jQuery(this).val();
        jQuery('.node-mail_templates-form').find('.mail-template-category').hide().siblings('.' + selected_value).show();
    });
    jQuery('#edit-field-mail-templates-category-und').change(function(){
        var select_option = jQuery('#edit-field-mail-templates-category-und option:selected').val();
        var select_option_title = jQuery('#edit-field-mail-templates-category-und option:selected').text();
        jQuery('#mail-templates-node-form').trigger('reset');
        jQuery('#edit-field-mail-templates-category-und').val(select_option);
        jQuery('#edit-title').val(select_option_title);
    });
    
     jQuery('#edit-field-mail-templates-category-und').change(function(){
         changeHeading();
     });
     changeHeading();
});

function changeHeading(){
    var select_option = jQuery('#edit-field-mail-templates-category-und option:selected').val();
    if(select_option == 'my_following'){
        jQuery('.node-mail_templates-form').find('.mail-template-category.my_following').find('h2').html('<span>My Following</span>');
    }
    if(select_option == 'loyalty_points_expiration'){
        jQuery('.node-mail_templates-form').find('.mail-template-category.my_following').find('h2').html('<span>Loyalty Points</span>');
    }
    if(select_option == 'redeem_points'){
        jQuery('.node-mail_templates-form').find('.mail-template-category.my_following').find('h2').html('<span>Redeem Points</span>');
    }
}
