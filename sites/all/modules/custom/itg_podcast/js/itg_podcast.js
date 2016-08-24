/*
 * @file itg_podcast.js
 * Contains all functionality related to podcast
 */

(function ($) {
    Drupal.behaviors.itg_podcast = {
        attach: function (context, settings) {
            var uid = settings.itg_podcast.settings.uid;
            if (uid != 1) {

            }
            jQuery('#edit-path').show();    
            jQuery('.add-to-dropbox').mousedown(function ()
            {
                var selectvalue = jQuery('.selects > .form-select:last option:selected').val();
                var comptext = "";
                var makeradio = "";
                var flag = 0;
                if (selectvalue != "")
                {
                    jQuery('.selects > .form-select').each(function ()
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
                    jQuery('#primary-category-data option').each(function ()
                    {
                        var existvalue = jQuery(this).val();
                        if (selectvalue == existvalue)
                        {
                            flag = 1;
                        }

                    });
                    if (comptext != "" && flag == 0)
                    {
                        makeradio = '<option value="' + selectvalue + '">' + comptext + '</option>';
                        jQuery('#primary-category-data').append(makeradio);

                        var gethtml = jQuery('#primary-category-data').html();
                        jQuery('#edit-field-primary-category-html-und-0-value').val(gethtml);
                    }
                }

            });
            jQuery('.dropbox-remove a').click(function () {
                var getdattext = jQuery(this).parent().siblings('td').text();

                $('#primary-category-data option').each(function () {

                    var getdoptiontext = jQuery(this).text();
                    if (getdoptiontext == getdattext) {
                        jQuery(this).remove();
                    }
                });

            });

            jQuery('#primary-category-data').change(function () {
                var getval = jQuery(this).val();
                jQuery('#edit-field-primary-category-und-0-value').val(getval);
                jQuery('#primary-category-data option').attr('selected', false);
                jQuery('#primary-category-data option[value=' + getval + ']').attr('selected', 'selected');
                var gethtml = jQuery('#primary-category-data').html();
                jQuery('#edit-field-primary-category-html-und-0-value').val(gethtml);
            });
        }

    };
})(jQuery, Drupal, this, this.document);

//   code load the selectd option and add to select box
jQuery(window).load(function() {
    // executes when complete page is fully loaded, including all frames, objects and images
    var getvaluehtml = jQuery('#edit-field-primary-category-html-und-0-value').val();
    if (getvaluehtml != "")
    {
        jQuery('#primary-category-data').html(getvaluehtml);
    }
});
