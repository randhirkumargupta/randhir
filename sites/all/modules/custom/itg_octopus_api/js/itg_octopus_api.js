/*
 * @file itg_octopus_api.js
 * Contains all functionality related to octopus
 */

(function($) {
    Drupal.behaviors.itg_octopus_api = {
        attach: function(context, settings) {
        }

    };
})(jQuery, Drupal, this, this.document);


jQuery('document').ready(function() {
    jQuery(".octopus-slug-data").click(function() {
        var current_object = jQuery(this);
        var base_url = Drupal.settings.baseUrl.baseUrl;
        var slug_id = jQuery(this).attr('data');
        jQuery.ajax({
            url: base_url + '/slug-details/' + slug_id,
            type: 'post',
            data: {'id': slug_id},
            beforeSend: function() {
                current_object.closest('tr').siblings('.octopus-slug-data-row').remove();
                current_object.closest('tr').after('<tr class="octopus-slug-data-row" style="text-align: center;"><td colspan="5"><img width="50" src="'+Drupal.settings.itg_octopus_holder.settings.loader_url+'" alt=""/></td></tr>');
            },
            success: function(data) {
                current_object.closest('tr').siblings('.octopus-slug-data-row').remove();
                current_object.closest('tr').after('<tr class="octopus-slug-data-row"><td colspan="5">' + data + '</td></tr>');
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });


    });
});