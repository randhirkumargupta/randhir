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

    var actionbtnshtml = jQuery('#edit-actions').html();
    if(actionbtnshtml!=null)
    {
    actionbtnshtml = actionbtnshtml.replace(/id=/g, "data-id=");
    actionbtnshtml = actionbtnshtml.replace(/form-submit/g, 'form-submit btn-trigger');
    jQuery('#page-title').after('<div class="top-actions">' + actionbtnshtml + '</div>');


    jQuery('.top-actions .btn-trigger').click(function() {
        var id_to_trigger = jQuery(this).attr('data-id');
        jQuery('#' + id_to_trigger).trigger('click');
    });
    jQuery('.top-actions .published').click(function() {
        var id_to_trigger = jQuery(this).attr('data-id');
        jQuery('#' + id_to_trigger).trigger('click');
    });

    }

})(jQuery, Drupal, this, this.document);

