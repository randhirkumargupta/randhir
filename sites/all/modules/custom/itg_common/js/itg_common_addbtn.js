/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 * @file itg_common_addbtn.js
 * Contains all functionality of all btn show on top in all content type
 */

(function($) {

    var actionbtnshtml = jQuery('#edit-actions, #edit-actions--2').html();
    if (actionbtnshtml != null)
    {
        actionbtnshtml = actionbtnshtml.replace(/id=/g, "data-id=");
        actionbtnshtml = actionbtnshtml.replace(/form-submit/g, 'form-submit btn-trigger');
        jQuery('#page-title').after('<div class="top-actions">' + actionbtnshtml + '</div>');


        jQuery('.top-actions .btn-trigger').click(function() {
            var id_to_trigger = jQuery(this).attr('data-id');
            jQuery('#' + id_to_trigger).trigger('click');
        });
        jQuery('.top-actions .button').click(function() {
            var id_to_trigger = jQuery(this).attr('data-id');
            jQuery('#' + id_to_trigger).trigger('click');
        });

    }
    
    // code for loyalty form custom image field image repo
    
    jQuery('input[name="lrp_gold_star_one_icon_remove_button"]').on('mousehover', function() {
        jQuery(document).on('ajaxComplete',function(event, request, settings) {
           if(jQuery('input[name="lrp_gold_star_one_icon[fid]"]').val() ==0) {
            jQuery('.div_lrp_gold_star_one_icon').show();
        }
        });
    });
    jQuery('input[name="itg_twitter_img_remove_button"]').on('mousehover', function() {
        jQuery(document).on('ajaxComplete',function(event, request, settings) {
           if(jQuery('input[name="itg_twitter_img[fid]"]').val() ==0) {
            jQuery('.div_itg_twitter_img').show();
        }
        });
    });
    jQuery('input[name="itg_fb_img_remove_button"]').on('mousehover', function() {
        jQuery(document).on('ajaxComplete',function(event, request, settings) {
           if(jQuery('input[name="itg_fb_img[fid]"]').val() ==0) {
            jQuery('.div_itg_fb_img').show();
        }
        });
    });
    
     jQuery('input[name="lrp_gold_star_two_icon_remove_button"]').on('mousedown', function() {
        jQuery(document).ajaxComplete(function(event, request, settings) {
           
           if(jQuery('input[name="lrp_gold_star_two_icon[fid]"]').val() ==0) {
            jQuery('.div_lrp_gold_star_two_icon').show();
        }
        });
    });
    
     jQuery('input[name="lrp_gold_star_three_icon_remove_button"]').on('mousedown', function() {
        jQuery(document).ajaxComplete(function(event, request, settings) {
            if(jQuery('input[name="lrp_gold_star_three_icon[fid]"]').val() ==0) {
            jQuery('.div_lrp_gold_star_three_icon').show();
        }
        });
    });
     jQuery('input[name="lrp_gold_star_four_icon_remove_button"]').on('mousedown', function() {
        jQuery(document).ajaxComplete(function(event, request, settings) {
            if(jQuery('input[name="lrp_gold_star_four_icon[fid]"]').val() ==0) {
            jQuery('.div_lrp_gold_star_four_icon').show();
        }
        });
    });
    jQuery('input[name="lrp_gold_star_five_icon_remove_button"]').on('mousedown', function() {
        jQuery(document).ajaxComplete(function(event, request, settings) {
            if(jQuery('input[name="lrp_gold_star_five_icon[fid]"]').val() ==0) {
            jQuery('.div_lrp_gold_star_five_icon').show();
        }
        });
    });
    
    
    jQuery(document).on('ajaxComplete', function(event, xhr, settings) {
        var html = jQuery('.image-fullname').find('a').attr('target', '_blank');
    });

})(jQuery, Drupal, this, this.document);

