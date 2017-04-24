/*
 * @file itg_related.js
 * Contains all functionality Related Content
 */

(function ($) {
  Drupal.behaviors.itg_related = {
    attach: function (context, settings) {
             var uid = settings.itg_related.settings.uid;
             var dta = encodeURIComponent(window.location.href);
             var base_url = settings.itg_related.settings.base_url;
             var typeval = parent.top.jQuery('[name="ntype"]').val();
           
            $(".itg-row-selector-selection-form #edit-submit").hide();
            $(".itg-row-selector-table-select-all").hide();
            $("#insvalue").attr('readonly','readonly');
            $('#filter-save', context).click(function (event) {
                
                var title = $("#edit-label").val();
                var type = $("#edit-bundle").val();
                var search_name = $("#search-title").val();
                var bundle_name = $("#edit-bundle").val();
                var section_id = $("#edit-im-vid-4").val();
                var hash = $("#edit-hash").val();

                var post = "&title=" + title + "&type=" + type + "&search_name=" + search_name + "&uid=" + uid + "&ntype=" + typeval + "&bundle_name=" + bundle_name + "&section_id=" + section_id + "&hash=" + hash + "&dta=" + dta;

                if (search_name === '') {
                    alert('please enter search name');
                    $('#search-title').focus();
                    return false;
                }
                else
                {

                    $.ajax({
                        'url': base_url + '/ajaxcallback',
                        'data': post,
                        'type': 'POST',
                        'success': function (data)
                        {
                           
                            var obj = jQuery.parseJSON(data);
                            if (obj.msg == 'success') {
                                $('.success').fadeIn(200).show(0).delay(2000).hide(1000);
                                parent.jQuery('.search-list').prepend(obj.lnk);

                            } else {
                                $('.erro').fadeIn(200).show(0).delay(2000).hide(1000);
                            }
                        }
                    });
                }
            }); 
              
    }

  };
})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function(){

        jQuery("body").on('click', '#clickme', function () {
             jQuery( ".search-criteria" ).slideToggle();
            });
   // var itemString = parent.jQuery('#edit-field-story-kicker-text-und-0-value').val();
    var itemString = parent.jQuery('#edit-field-common-related-content-und-0-value').val();
    var detailString = parent.jQuery('#edit-field-cm-related-content-detail-und-0-value').val();
    //console.log(detailString);
    var insvalue = '';
    var relatedtit = '';
    jQuery('#insvalue').val(itemString);
    jQuery('#relatedtit').text(detailString);
    jQuery('#insvalue').attr('title', itemString);
    var insvalue = jQuery('#insvalue').val();
    var relatedtit = jQuery('#relatedtit').text();
    var item = [];
    var detail = [];
    if(insvalue){
        item = insvalue.split(",");
    }
    if(relatedtit){
        detail = relatedtit.split(",");
    }
    jQuery('body').on('change', '.itg-row-selector-select', function () {
        var isCheck = jQuery(this).is(':checked');
        var url = jQuery(this).parent().parent().parent().find('.views-field-entity-id span').html();
        var site = jQuery(this).parent().parent().parent().find('.views-field-site').html();
        var label = jQuery(this).parent().parent().parent().find('.views-field-label a').html().replace(/,/g, "");
        var bundle = jQuery(this).parent().parent().parent().find('.views-field-bundle-name').html();
        var urlval = jQuery.trim(url);
        var siteval = jQuery.trim(site);
        var labelval = jQuery.trim(label);
        var bundleval = jQuery.trim(bundle);
        var url_site = siteval + '_' + urlval;
        var site_detail = siteval + '_' + urlval+ '@' + bundleval+'@' + labelval;
        
        if (isCheck) {
            var hasurl = jQuery.inArray(url_site, item);
            if (hasurl == -1) {
                item.push(url_site);
            }
            var hastitle = jQuery.inArray(site_detail, detail);
            if (hastitle == -1) {
                detail.push(site_detail);
            }
        }
        else {
            var hasurl = jQuery.inArray(url_site, item);
            item.splice(hasurl, 1);
            var hastitle = jQuery.inArray(site_detail, detail);
            detail.splice(hastitle, 1);
        }
        
        jQuery('#insvalue').val(item);
        jQuery('#relatedtit').text(detail);
        jQuery('#insvalue').attr('title', item);
        //console.log("hasurl index = " + item);
    });

     jQuery('body').on('click', '.insert-url', function(){
           
         var solr = Drupal.settings.itg_related.settings.solr;
         if (solr != null && solr != undefined) {
            var solr_explict = solr.split(',');

            var slr = [];
            for (i = 0; i < solr_explict.length; i++) {
                var c = solr_explict[i].split('|');
                slr[c[0]] = c[1];

            }
        }
            
           // parent.jQuery('#edit-field-story-kicker-text-und-0-value').val(item);
            parent.jQuery('#edit-field-common-related-content-und-0-value').val(item);
            parent.jQuery('#edit-field-cm-related-content-detail-und-0-value').val(detail);
            var checkedlist = '';
            for ( var i = 0, l = item.length; i < l; i++ ) {
                var site = item[i].split('_');
                var rel_tit = detail[i].split('@');
                if(rel_tit[0] == item[i]) {
                    var final_tit = detail[i].split('@');
                    
                }
                if(final_tit[2] != null && final_tit[2] != undefined) {
                    var display_tit;
                    display_tit = final_tit[2];
                }
                if(final_tit[1] != null && final_tit[1] != undefined) {
                    var display_type;
                    display_type = final_tit[1];
                }
                var solr_uri = slr[site[0]]+'/node/'+site[1];
                checkedlist += '<li class="ui-state-default"><span class="ui-icon ui-icon-arrowthick-2-n-s"></span><span class="item-value" title="'+display_tit+'">' + item[i] + '</span> | '+ display_type +' | <a href="'+solr_uri+'" target="_blank"> view </a><i class="fa fa-times fright" aria-hidden="true"></i></li>';
            }
            parent.jQuery('.checked-list').html(checkedlist);
            if(item.length){
                parent.jQuery('.save-checklist-ordre').html('<span class="add-more save-checklist">Save</span>');
            }
            else{
                parent.jQuery('.save-checklist-ordre').html('<span class="empty-checklist">No content associated for this story yet !</span>');
            }
            
            parent.jQuery.colorbox.close();
//            item.length = 0;
        });
        
        
        jQuery('.insert-url').click(function () {
        if (jQuery('#insvalue').val() == '') {
            alert('Input value can not be blank, please select at least one item');
            return false;
        }
    });

});
