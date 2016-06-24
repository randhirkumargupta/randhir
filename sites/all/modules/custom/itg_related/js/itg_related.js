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
            // alert(window.location.href);
//             var spt = iframe_url.split("&");
//             alert(spt.split('&')[0]);
             //var typeval = getParameterByName('type');
            var typeval = parent.top.jQuery('[name="ntype"]').val();
           
            $(".itg-row-selector-selection-form #edit-submit").hide();
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
                                $("#search-title").val('');
                            }
                            else
                            {
                                $('.erro').fadeIn(200).show();
                            }
                        }
                    });
                }
            }); 
            
            
            // assign type value in field
//            $("#ctype").change(function () {
//            var ctypevalue = $(this).val();
//            
//            if(ctypevalue == '_none') {
//              $ctype_value = '';  
//            }
//            else
//            {
//              $ctype_value = ctypevalue;   
//            }
//            
//            $('#edit-bundle-name').val($ctype_value);
//        });


// assign category value in field
//            $("#ctgry").change(function () {
//            var ctgryvalue = $(this).val();
//            
//            if(ctgryvalue == '_none') {
//              $ctgry_value = '';  
//            }
//            else
//            {
//              $ctgry_value = ctgryvalue;   
//            }
//            alert(ctgryvalue);
//            
//            $('#edit-im-vid-4').val($ctgry_value);
//        });
//        
        // assign site value in field
        
//            $(document).ready(function () {
//                $checks = $('#site_name .form-radio');
//                $('#site_name').on('change', '.form-radio', function () {
//                    var string = $checks.filter(":checked").map(function (i, v) {
//                        return this.value;
//                    }).get().join(",");
//                    $('#edit-hash').val(string);
//                });
//            });


        
        
    }

  };
})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function(){

        jQuery("body").on('click', '#clickme', function () {
             jQuery( ".search-criteria" ).slideToggle();
            });

    var item = [];
    jQuery('body').on('change', '.itg-row-selector-select', function () {
        var isCheck = jQuery(this).is(':checked');
        var url = jQuery(this).parent().parent().parent().find('.views-field-entity-id').html();
        var urlval = jQuery.trim(url);
        if (isCheck) {
            var hasurl = jQuery.inArray(urlval, item);
            if (hasurl == -1) {
                item.push(urlval);
            }
        }
        else {
            var hasurl = jQuery.inArray(urlval, item);
            item.splice(hasurl, 1);
        }
      
        console.log("hasurl index = " + item);
    });
    
//    jQuery('body').on('click', '.insert-url', function(){
//
//          jQuery('.field-name-field-story-related-content .form-text').val(item);  
//       
//         jQuery(window).colorbox.close();
//        // jQuery('#cboxClose').trigger('click');
//        item.length = 0;
//    });
    
     jQuery('body').on('click', '.insert-url', function(){
         // parent.jQuery('#edit-field-s-related-content-und-0-value').val(item); edit-title
            parent.jQuery('#edit-title').val(item);
            parent.jQuery.colorbox.close();
            item.length = 0;
        });
        
        jQuery("body").on('click', '.rset-form', function () {
            jQuery('input[type="text"], select').val('');
            jQuery('input:radio, input:checkbox').prop('checked', false);
        });
    
//jQuery(document).ajaxComplete(function() {
//    jQuery('#views-form-related-content-new-page table tbody tr').each(function(){
//    var url = jQuery(this).find('.views-field-url').html();
//    var urlval = jQuery.trim(url);
//    var hasurl = jQuery.inArray(urlval, item);
//    console.log("hasurl index = " + hasurl);
//    if(hasurl != -1){
//        jQuery(this).find('.itg-row-selector-select').attr('checked', true);
//    }
//});
//});

});

//function getParameterByName(name, url) {
//    if (!url) url = window.location.href;
//    name = name.replace(/[\[\]]/g, "\\$&");
//    var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
//        results = regex.exec(url);
//    if (!results) return null;
//    if (!results[2]) return '';
//    return decodeURIComponent(results[2].replace(/\+/g, " "));
//}

