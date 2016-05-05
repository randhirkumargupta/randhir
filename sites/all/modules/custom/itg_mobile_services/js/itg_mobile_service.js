/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {

    Drupal.behaviors.itg_mobile_service_form = {
        attach: function (context, settings) {
            // jQuery('.field-name-field-service-audio').hide();
            jQuery('.field-name-field-story-expert-description').hide();
            jQuery('.field-name-field-story-large-image').hide();
            jQuery('.field-name-field-service-video').hide();
            jQuery('.field-name-field-service-audio').hide();

            var content_format = jQuery('#content-format-hidden').val();

            var content_format_arr = jQuery('#content-format-hidden').val().split(',');

            jQuery.each(content_format_arr, function (key, value) {

                console.log(value)
                // content-format-hidden
                if (value == 'text') { //alert(" val" + value );
                    jQuery('.field-name-field-story-expert-description').show();
                } else if (value == 'image') {
                    jQuery('.field-name-field-story-large-image').show();

                } else if (value == 'video') {
                    jQuery('.field-name-field-service-video').show();
                } else if (value == 'audio') {
                    jQuery('.field-name-field-service-audio').show();
                } else if (value == 'wap(image,text,videoandaudio)') {
                    jQuery('.field-name-field-story-expert-description').show();
                    jQuery('.field-name-field-story-large-image').show();
                    jQuery('.field-name-field-service-video').show();
                    jQuery('.field-name-field-service-audio').show();
                }
            });

            $('#edit-field-service-association-title-und').change(function () {
                $('#edit-field-story-expert-description-und-0-value').val('');
                $('#edit-field-story-large-image .button-remove').mousedown();
                $('#edit-field-service-audio .button-remove').mousedown();
                $('#edit-field-service-video .button-remove').mousedown();
            });
            $('#edit-actions').css('display', 'block');
            $('.form-layout-default .column-main .column-wrapper > .form-actions').show();

            // hide defaut service-frequency-date
            jQuery('#edit-field-service-frequency-date').hide();

            var selectedVal = "";
            var selected = $("#edit-field-service-frequency-und input[type='radio']:checked");
            if (selected.length > 0) {
                selectedVal = selected.val();
                if (selectedVal > 1) {
                    jQuery('#edit-field-service-frequency-date').show();
                }
            }

            jQuery('input[type="radio"]').click(function () {
                if ($(this).attr("value") == "1") {
                    jQuery('#edit-field-service-frequency-date').hide();
                } else if ($(this).attr("value") == "2") {
                    jQuery('#edit-field-service-frequency-date').show();
                } else if ($(this).attr("value") == "3") {
                    jQuery('#edit-field-service-frequency-date').show();
                }
            });


            //  var selectedDate = jQuery('#edit-field-service-content-und-0-field-service-content-date-und-0-value-datepicker-popup-1').datepicker('getDate');
            jQuery("#edit-field-service-frequency-date-und-0-value-datepicker-popup-1").datepicker({
                defaultDate: "+1w",
                changeMonth: true,
                numberOfMonths: 1,
                minDate: 0,
                onSelect: show_days,
                onClose: function (selectedDate) {
                    jQuery("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker("option", "minDate", selectedDate);
                }
            });
            jQuery("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker({
                defaultDate: "+1w",
                changeMonth: true,
                numberOfMonths: 1,
                onSelect: show_days,
                onClose: function (selectedDate) {
                    jQuery("#edit-field-service-frequency-date-und-0-value-datepicker-popup-1").datepicker("option", "maxDate", selectedDate);
                }
            });


            function show_days() {

                var start = jQuery('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').datepicker('getDate');
                var end = jQuery('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').datepicker('getDate');
                var oneDay = 24 * 60 * 60 * 1000;
                var diff = 0;
                if (start && end) {
                    diff = 1 + Math.round(Math.abs((end.getTime() - start.getTime()) / (oneDay)));
                }


                var rowCount = jQuery(".page-node-add-create-content .field-multiple-table tbody tr").length;
                if (rowCount == '0') {
                    var rowCount = jQuery(".node-type-create-content .field-multiple-table tbody tr").length;
                }

                if (rowCount > 0) {
                    diff = diff - rowCount;
                }

                //field_service_content_und_1_remove_button
                alert('rowCount : ' + rowCount);
                var i = 1;
                for (; i <= rowCount; ) {
                    jQuery("input[name$='field_service_content_und_" + i + "_remove_button']").mousedown();
                    i++;
                }
                jQuery('#edit-field-service-content-add-more-number').val(diff);
                jQuery('.field-name-field-service-content .field-add-more-submit').mousedown();

                //reshow_hide(content_format_arr);

            }

            set_dates();

            function set_dates() {

                var today = new Date();
                var today_date = today.getDate();
                var from_date = jQuery('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val().split('/');
                var start_date = from_date[1];

                if (start_date < 10) {
                    start_date = start_date[start_date.length - 1]
                }
                start_date = start_date - today_date;
                var no_of_days = jQuery('#edit-field-service-content-add-more-number').val();

                var i = 0;
                for (; i <= no_of_days + 1; ) {

                    var tomorrow = new Date(new Date().getTime() + start_date * 24 * 60 * 60 * 1000);
                    var dd = tomorrow.getDate();
                    var mm = tomorrow.getMonth() + 1; //January is 0!

                    var yyyy = tomorrow.getFullYear();

                    if (dd < 10) {
                        dd = '0' + dd
                    }
                    if (mm < 10) {
                        mm = '0' + mm
                    }
                    tomorrow = mm + '/' + dd + '/' + yyyy;
                    jQuery('input[name="field_service_content[und][' + i + '][field_service_content_date][und][0][value][date]"]').val(tomorrow);
                    i++;
                    start_date++;
                }

            }

        }
    }
})(jQuery);



jQuery('document').ready(function () {
    var maxLen = 0
    jQuery('#edit-field-service-association-title-und').change(function () {
        jQuery('#remain').text('');
        if (jQuery('#edit-field-service-association-title-und').val() != '_none') {
            var nid = jQuery('#edit-field-service-association-title-und').val();
            jQuery.ajax({
                type: "POST",
                url: Drupal.settings.basePath + 'countchar_validation',
                data: 'nidvalue=' + nid,
                success: function (msg) {
                    maxLen = parseInt(msg);
                },
            });
        }
    });
    
    
    jQuery('#edit-field-story-expert-description-und-0-value').keyup(function () {
        var tlength = jQuery(this).val().length;
        console.log(maxLen);
        console.log(tlength);
        jQuery(this).val(jQuery(this).val().substring(0, maxLen));
        var tlength = jQuery(this).val().length;
        remain = maxLen - parseInt(tlength);
        jQuery('#remain').text(remain + ' characters remaining from ' + maxLen);
    });
});