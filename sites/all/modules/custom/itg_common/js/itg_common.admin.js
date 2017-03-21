/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */
//cancle-itg-btn
(function ($) {
  Drupal.behaviors.itg_common_admin = {
    attach: function (context, settings) {     

      var uid = settings.itg_common.settings.uid;  
      // checkbox hide for all user of Provide a menu link on all form
      if (uid != 1) {
        jQuery(".form-item-menu-enabled").hide();  
      }
      jQuery("#edit-field-highlights-und-0-remove-button").hide(); 
      
      // for lock content
        $('.cancle-itg-btn').click(function() {
            var base_url =  Drupal.settings.baseUrl.baseUrl;
            var nid = $(this).attr('data-widget');
            var itgurl = $(this).attr('data-dest');
            
            $.ajax({
                url: base_url + "/itg-custom-lock-delete",
                method: 'post',
                data: {nid: nid},
                beforeSend: function() {
                    
                },
                success: function(data) {
                    window.location.href = base_url + "/" + itgurl; 
                }
            });
           
        });

    }

  };
})(jQuery, Drupal, this, this.document);

/*jQuery(document).ready(function () {

    var solr = Drupal.settings.itg_common.settings.solr;

    if (solr != null && solr != undefined) {
        var solr_explict = solr.split(',');

        var slr = [];

        for (i = 0; i < solr_explict.length; i++) {
            var c = solr_explict[i].split('|');
            slr[c[0]] = c[1];
        }
    }
    // jQuery code for related content on edit page
    var item = [];
    var itemString = jQuery('#edit-field-common-related-content-und-0-value').val();
    if (itemString) {
        item = itemString.split(",");
    }
    var checkedlist = '';
    for (var i = 0, l = item.length; i < l; i++) {
        var site = item[i].split('_');
        var solr_uri = slr[site[0]] + '/node/' + site[1];
        checkedlist += '<li class="ui-state-default"><span class="ui-icon ui-icon-arrowthick-2-n-s"></span><span class="item-value">' + item[i] + '</span><a href="' + solr_uri + '" target="_blank"> <i class="fa fa-eye" aria-hidden="true"></i> </a><i class="fa fa-times fright" aria-hidden="true"></i></li>';
    }
    // end of code

    jQuery('.checked-list').html(checkedlist);
    if (checkedlist) {
        jQuery('.save-checklist-ordre').html('<span class="add-more save-checklist">Save</span>');
    }
    else {
        jQuery('.save-checklist-ordre').html('<span class="empty-checklist">No content associated for this story yet !</span>');
    }


    jQuery('.saved-search-link').click(function (e) {
        e.stopPropagation();
        jQuery(this).parent().parent().find('.my-saved-search').slideToggle();
    });
    jQuery('body').click(function () {
        jQuery(this).find('.my-saved-search').slideUp();
    });
    jQuery('body').click(function () {
        jQuery(this).find('.my-saved-search').slideUp();
    });

    jQuery('body').find(".checked-list").sortable();
    jQuery('body').find(".checked-list").disableSelection();

    // jQuery code to remove checked list item
    jQuery('.checked-list').on('click', '.fa-times', function () {
        jQuery(this).parent().remove();
    });
    // end of code

    // jQuery code to save check list after re-order
    jQuery('body').on('click', '.save-checklist', function () {
        var item = [];
        var listLength = jQuery(this).closest('.checked-list-parent').find('.checked-list li').length;
        if (!listLength) {
            //alert('Changes made successfully');
            jQuery(this).parent().html('<span class="empty-checklist">No content associated for this story yet !</span>');
        }
        jQuery(this).closest('.checked-list-parent').find('.checked-list li').each(function (i) {
            item.push(jQuery(this).find('.item-value').text());
        });
        jQuery('#edit-field-common-related-content-und-0-value').val(item);
        alert('Changes made successfully');
    });
    // end of code


});*/


// open save search in popup
function showrelatedpopup(iframeurl)
{
    jQuery.colorbox({href: iframeurl, iframe: true, width: "1030", height: "730", fixed: true});

}