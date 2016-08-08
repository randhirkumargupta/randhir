/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
    Drupal.behaviors.itg_story = {
        attach: function(context, settings) {
           

            // code use for make primary category
            jQuery('.add-to-dropbox').mousedown(function()
            {
                var selectvalue = jQuery('.selects > .form-select:last option:selected').val();
                var comptext = "";
                var makeradio = "";
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

                    })
                    comptext = comptext.slice(0, -1);
                    jQuery('#primary-cat-data option').each(function()
                    {
                        var existvalue = jQuery(this).val();
                        if (selectvalue == existvalue)
                        {
                            flag = 1;
                        }

                    })
                    if (comptext != "" && flag == 0)
                    {
                        makeradio = '<option value="' + selectvalue + '">' + comptext + '</option>';
                        jQuery('#primary-cat-data').append(makeradio);

                        var gethtml = jQuery('#primary-cat-data').html();
                        jQuery('#edit-field-primary-cat-html-und-0-value').val(gethtml);
                    }
                }

            })
            jQuery('.dropbox-remove a').click(function() {
                var getdattext = jQuery(this).parent().siblings('td').find('.dropbox-selected-item').text();
                $('#primary-cat-data option').each(function() {
                    if (jQuery(this).text().indexOf(getdattext) >= 0) {
                        jQuery(this).remove();


                    }
                });

            })

            jQuery('#primary-cat-data').change(function() {
                var getval = jQuery(this).val();
                jQuery('#edit-field-primary-cat-und-0-value').val(getval);
                jQuery('#primary-cat-data option').attr('selected', false);
                jQuery('#primary-cat-data option[value=' + getval + ']').attr('selected', 'selected');
                var gethtml = jQuery('#primary-cat-data').html();
                jQuery('#edit-field-primary-cat-html-und-0-value').val(gethtml);
            })

        


        }

    };


})(jQuery, Drupal, this, this.document);

//   code load the selectd option and add to select box
jQuery(window).load(function() {
    //jQuery('#edit-field-primary-cat-html-und-0-value').hide();
    // executes when complete page is fully loaded, including all frames, objects and images
    var getvaluehtml = jQuery('#edit-field-primary-cat-html-und-0-value').val();

    if (getvaluehtml != "")
    {
        jQuery('#primary-cat-data').html(getvaluehtml);
    }
});
