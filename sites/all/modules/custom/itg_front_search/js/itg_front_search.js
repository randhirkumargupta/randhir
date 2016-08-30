/*
 * @file itg_related.js
 * Contains all functionality Related Content
 */

(function ($) {
    Drupal.behaviors.itg_front_search = {
        attach: function (context, settings) {

            var custom_field_val = getParameterByName('custom_drp');
            $("#edit-submit-front-end-global-search").hide();
            $("#edit-reset").hide();

            $('#edit-custom-drp').change(function () {
                var datetypevalue = $('#edit-custom-drp').val();

                if (datetypevalue == 'calender') { // Image question
                    $(".caln").show();
                    $(".caln").show();
                } else
                {
                    $(".caln").hide();
                    $(".caln").hide();
                    $('#edit-ds-changed-datepicker-popup-0').val("");
                    $('#edit-ds-changed-max-datepicker-popup-0').val("");

                }


            });

            if (custom_field_val != 'calender') {
                $(".caln").hide();
                $(".caln").hide();
                $('#edit-ds-changed-datepicker-popup-0').val("");
                $('#edit-ds-changed-max-datepicker-popup-0').val("");
            }

            // trigger submit button
            $('#search_button').click(function () {
                $('#edit-submit-front-end-global-search').trigger('click');
            });

            // trigger reset button
            $('#reset_button').click(function () {
                $('#edit-reset').trigger('click');
            });

            $(function () {
                $("#edit-ds-changed-datepicker-popup-0").datepicker({
                    dateFormat: 'yy-mm-dd',
                    changeMonth: true,
                    changeYear: true,
                    onSelect: function (selected) {
                        var dt = new Date(selected);
                        dt.setDate(dt.getDate() + 1);
                        $("#edit-ds-changed-max-datepicker-popup-0").datepicker("option", "minDate", dt);
                    }
                });
                $("#edit-ds-changed-max-datepicker-popup-0").datepicker({
                    dateFormat: 'yy-mm-dd',
                    changeMonth: true,
                    changeYear: true,
                    onSelect: function (selected) {
                        var dt = new Date(selected);
                        dt.setDate(dt.getDate() - 1);
                        $("#edit-ds-changed-datepicker-popup-0").datepicker("option", "maxDate", dt);
                    }
                });
            });

            // for online story archive
            if (Drupal.settings.itg_front_search.settings.archive_story) {
                jQuery(".caln").show();
                jQuery('#edit-bundle-name-wrapper').hide();
                jQuery('.form-item-ds-changed label').hide();

            }

            jQuery('.atleta a').click(function (e) {
                e.preventDefault();
                var h = jQuery(this).attr('href');
                jQuery('#edit-ds-changed-datepicker-popup-0').val(h);
                jQuery('#edit-submit-archive-story').trigger('click');
            });
        }

    };
})(jQuery, Drupal, this, this.document);


function getParameterByName(name, url) {
    if (!url)
        url = window.location.href;
    name = name.replace(/[\[\]]/g, "\\$&");
    var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
            results = regex.exec(url);
    if (!results)
        return null;
    if (!results[2])
        return '';
    return decodeURIComponent(results[2].replace(/\+/g, " "));
}