/*
 * @file primary_category.js
 * Contains all functionality related to primary category
 */

(function($) {
            // code use for make primary category
            jQuery('.add-to-dropbox').live('mousedown',function()
            {
                var selectvalue = jQuery('.selects > .form-select:last option:selected').val();
                var comptext = "";
                var makeradio = "";
                var datahtml=jQuery('.dropbox-title').html();
                var flag = 0;
                if (selectvalue != "")
                {
                    jQuery('.selects > .form-select').each(function()
                    {
                        var getid = jQuery(this).attr('id');
                        var selopttext = jQuery('#' + getid + ' option:selected').text();
                        var selval = jQuery('#' + getid + ' option:selected').val();
                        if (selval.indexOf("label") != 0)
                        {
                            comptext = comptext + selopttext + '›';
                        }

                    });
                    comptext = comptext.slice(0, -1);
                    jQuery('.select-prim').each(function()
                    {
                        var existvalue = jQuery(this).val();
                        if (selectvalue == existvalue)
                        {
                            flag = 1;
                        }

                    });
                    

                    jQuery( document ).on('ajaxComplete',function( event, xhr, settings ) {

  if (settings.url.indexOf('hierarchical_select_ajax') >= 0) {

if (comptext != "" && flag == 0)
                    {
                       
                        makeradio = '<span class="hiddenradio"><input type="radio" class="select-prim" value="' + selectvalue + '"><span class="primary-text">' + comptext + '</span></span>';
                       datahtml = datahtml.replace(makeradio, ""); 
                       datahtml=datahtml+makeradio;
                                                jQuery('.dropbox-title').html(datahtml).hide();
                     jQuery(".hiddenradio").each(function(){
          var gettoptext=jQuery(this).find(".primary-text").text();
          var selectvalue=jQuery(this).find(".select-prim").val();
          
        makeradio = '<input class="primary-radio" name="primary_radio" type=radio  value="'+selectvalue+'">';

                        
                         jQuery(".dropbox-entry").each(function(){
                            var gettrtext=jQuery(this).children("td:first").text();
                            if(gettoptext==gettrtext)
                            {
                                
                               if(! jQuery(this).children("td:first").find('input').hasClass('primary-radio'))
                               {
                                jQuery(this).children("td:first").find(".dropbox-item:first").before(makeradio);
                            }
                            }
                          });

           });
                        var gethtml = jQuery('.dropbox-title').html();
                        jQuery('#edit-field-primary-category-html-text-und-0-value').val(gethtml);
                    }

  }
  
});

                }

            });
            jQuery('.dropbox-remove a').live('mousedown',function() {
              var getdattext = jQuery(this).parent().siblings('td').text();
                jQuery( document ).on('ajaxComplete',function( event, xhr, settings ) {
  if (settings.url.indexOf('hierarchical_select_ajax') >= 0) {

       var getdoptiontext=jQuery(this).text();
 jQuery('.dropbox-title .primary-text').each(function() {
                
                    var getdoptiontext=jQuery(this).text();

                    if (getdoptiontext== getdattext) {
                       
                        jQuery(this).parent('.hiddenradio').remove();
                    }
                });
             
}
});
                
            });

            jQuery('.primary-radio').live('mousedown',function() {
                var getval = jQuery(this).val();

                jQuery('#edit-field-primary-category-und-0-value').val(getval);

                var gethtml = jQuery('.dropbox-title').html();
                
                jQuery('#edit-field-primary-category-html-text-und-0-value').val(gethtml);
            });

})(jQuery, Drupal, this, this.document);

