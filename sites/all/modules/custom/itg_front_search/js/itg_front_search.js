/*
 * @file itg_related.js
 * Contains all functionality Related Content
 */

(function ($) {
    Drupal.behaviors.itg_related = {
        attach: function (context, settings) {

   var custom_field_val = getParameterByName('custom_drp');
      
   
   $('#edit-custom-drp').change(function() {
                var datetypevalue = $('#edit-custom-drp').val();
                // alert(contenttypevalue);
                if (datetypevalue == 'calender') { // Image question
                    $(".ds_min").show();
                    $(".ds_max").show();
                }
                else
                {
                    $(".ds_min").hide();
                    $(".ds_max").hide();
                    $('#edit-ds-changed-datepicker-popup-0').val("");
                    $('#edit-ds-changed-max-datepicker-popup-0').val("");
                    
                }
                
               
            });
            
            if(custom_field_val != 'calender') {
                    $(".ds_min").hide();
                    $(".ds_max").hide();
                    $('#edit-ds-changed-datepicker-popup-0').val("");
                    $('#edit-ds-changed-max-datepicker-popup-0').val("");
            }
            
        }

    };
})(jQuery, Drupal, this, this.document);


function getParameterByName(name, url) {
    if (!url) url = window.location.href;
    name = name.replace(/[\[\]]/g, "\\$&");
    var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
        results = regex.exec(url);
    if (!results) return null;
    if (!results[2]) return '';
    return decodeURIComponent(results[2].replace(/\+/g, " "));
}