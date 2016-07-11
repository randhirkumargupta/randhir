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
                var type = $("#edit-bundle-name").val();
                var search_name = $("#search-title").val();
                var bundle_name = $("#edit-bundle-name").val();
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
                            var tmp = data.split("######");

                            //console.log(data);

                            if (tmp[0])
                            {
                                $('.success').fadeIn(200).show();
                                //$("#search-title").val('');
                            }
                            else
                            {
                                $('.erro').fadeIn(200).show();
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
    var insvalue = '';
    jQuery('#insvalue').val(itemString);  
    var insvalue = jQuery('#insvalue').val();
    var item = [];
    if(insvalue){
        item = insvalue.split(",");
    }
    jQuery('body').on('change', '.itg-row-selector-select', function () {
        var isCheck = jQuery(this).is(':checked');
        var url = jQuery(this).parent().parent().parent().find('.views-field-entity-id span').html();
        var site = jQuery(this).parent().parent().parent().find('.views-field-site').html();
        var urlval = jQuery.trim(url);
        var siteval = jQuery.trim(site);
        var url_site = siteval + '_' + urlval;
        if (isCheck) {
            var hasurl = jQuery.inArray(url_site, item);
            if (hasurl == -1) {
                item.push(url_site);
            }
        }
        else {
            var hasurl = jQuery.inArray(url_site, item);
            item.splice(hasurl, 1);
        }
        jQuery('#insvalue').val(item);
        //console.log("hasurl index = " + item);
    });

     jQuery('body').on('click', '.insert-url', function(){
         
           // parent.jQuery('#edit-field-story-kicker-text-und-0-value').val(item);
            parent.jQuery('#edit-field-common-related-content-und-0-value').val(item);
            var checkedlist = '';
            for ( var i = 0, l = item.length; i < l; i++ ) {
                checkedlist += '<li class="ui-state-default"><span class="ui-icon ui-icon-arrowthick-2-n-s"></span><span class="item-value">' + item[i] + '</span><i class="fa fa-times fright" aria-hidden="true"></i></li>';
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
