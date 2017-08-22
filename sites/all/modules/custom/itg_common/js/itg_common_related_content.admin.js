/*
 * @file itg_common_related_content.admin.js
 * Contains all functionality related to common related content functionality
 */

(function ($) {
    Drupal.behaviors.itg_common_related_content_admin = {
        attach: function (context, settings) {

        }

    };
})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function () {

    // jQuery code for related content on edit page
    jQuery('#relatedtit').hide();
    relatedContent();
    function relatedContent() {
        var solr = Drupal.settings.itg_common.settings.solr;
        
        if (solr != null && solr != undefined) {
            var solr_explict = solr.split(',');
            var slr = [];
            for (i = 0; i < solr_explict.length; i++) {
                var c = solr_explict[i].split('|');
                slr[c[0]] = c[1];
            }
        }

        var item = [];
        var detail = [];
        var index_arr = [];
        var rel_tit_arr = [];
        var new_arr = [];
        var new_arr_detail;
        var detail_default_arr;
        var itemString = jQuery('#edit-field-common-related-content-und-0-value').val();
        var detail_default = jQuery('#edit-field-cm-related-content-detail-und-0-value').val();
        if (itemString) {
            item = itemString.split("|~|");
        }
        if (detail_default) {
            detail_default_arr = detail_default.split("|~|");
        }
        checkedlist = '';

        for (var i = 0, l = item.length; i < l; i++) {
            if (detail_default_arr != null && detail_default_arr != undefined) {
                var rel_tit = detail_default_arr[i].split('@');

                rel_tit_arr.push(rel_tit[0]);
            }
        }
        for (var i = 0, l = item.length; i < l; i++) {
            var rel_index = jQuery.inArray(item[i], rel_tit_arr);
            index_arr.push(rel_index);
            if (detail_default_arr != null && detail_default_arr != undefined) {
                new_arr.push(detail_default_arr[index_arr[i]]);
                new_arr_detail = new_arr.join('|~|');
            }
        }
        
        jQuery('#edit-field-cm-related-content-detail-und-0-value').val(new_arr_detail);
        //console.log(index_arr);
        //console.log(new_arr);
        var detailString = jQuery('#edit-field-cm-related-content-detail-und-0-value').val();
        var inputValArray = [];
        if (detailString) {
          detail = detailString.split("|~|");
        }
        for (var i = 0, l = item.length; i < l; i++) {
            var site = item[i].split('_');
            var solr_uri = slr[site[0]] + '/node/' + site[1];
            if (detail[i] != null && detail[i] != undefined) {
                var final_tit = detail[i].split('@');
                if (final_tit[2] != null && final_tit[2] != undefined) {
                    var display_tit;
                    display_tit = final_tit[2];
                    inputValArray.push(display_tit);
                }
                if (final_tit[1] != null && final_tit[1] != undefined) {
                    var display_type;
                    display_type = final_tit[1];
                }
            }
            checkedlist += '<li class="ui-state-default"><div class="rc-top"><span class="ui-icon ui-icon-arrowthick-2-n-s"></span><span class="item-value" title="' + display_tit + '">' + item[i] + '</span> | <span class="item-type">' + display_type + '</span> | <a href="' + solr_uri + '" target="_blank"> view </a><i class="fa fa-times fright" aria-hidden="true"></i></div><div class="rc-bottom"><input class="rc-title" type="text" value="' + display_tit + '" /></div></li>';
        }
        jQuery('.checked-list').html(checkedlist);
        jQuery('.checked-list li').each(function (i) {
            jQuery(this).find('.rc-title').val(inputValArray[i]);
        }); 
    }
    // end of code

    
    if (checkedlist) {
        jQuery('.save-checklist-ordre').html('<span class="add-more save-checklist">Save order</span>');
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

    try {
    jQuery('body').find(".checked-list").sortable();
            } catch(e) {

    }
    jQuery('body').find(".checked-list").disableSelection();

    // jQuery code to remove checked list item
    jQuery('.checked-list').on('click', '.fa-times', function () {
        jQuery(this).parent().parent().remove();
    });
    // end of code

    // jQuery code to save check list after re-order
    jQuery('body').on('click', '.save-checklist', function () {
        var item_new = [];
        var item_new_detail;
        var contentRow = [];
        var contentFinal = '';
        jQuery('.checked-list li').each(function(i){
          var itemVal = jQuery(this).find('.item-value').text();
          var itemType = jQuery(this).find('.item-type').text();
          var itemTitle = jQuery(this).find('.rc-title').val();
          var str = itemVal+'@'+itemType+'@'+itemTitle;
          contentRow[i] = str;
          contentFinal = contentRow.join('|~|');
        });
        jQuery('#edit-field-cm-related-content-detail-und-0-value').val(contentFinal);
        var listLength = jQuery(this).closest('.checked-list-parent').find('.checked-list li').length;
        if (!listLength) {
            //alert('Changes made successfully');
            jQuery(this).parent().html('<span class="empty-checklist">No content associated for this story yet !</span>');
        }
        jQuery(this).closest('.checked-list-parent').find('.checked-list li').each(function (i) {
            item_new.push(jQuery(this).find('.item-value').text());
            item_new_detail = item_new.join('|~|');
            
        });
        jQuery('#edit-field-common-related-content-und-0-value').val(item_new_detail);
        relatedContent();   
        alert('Changes made successfully');
    });
    // end of code

});


// open save search in popup
function showrelatedpopup(iframeurl) {
  jQuery.colorbox({href: iframeurl, iframe: true, width: "1030", height: "730", fixed: true});
}