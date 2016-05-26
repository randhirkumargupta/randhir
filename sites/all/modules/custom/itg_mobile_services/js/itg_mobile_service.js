/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
var firstTime = 1;
var genrateFlag = 1;
var rowCount = 1;
var firstDate = 1;
var fixedDate = '';

(function ($) {

    Drupal.behaviors.itg_mobile_service_form = {
        attach: function (context, settings) {
            jQuery('#client_entity_wrapper').hide();
            jQuery('#field-service-content-add-more-wrapper').hide();
            jQuery('.field-name-field-story-expert-description').hide();
            jQuery('.field-name-field-story-large-image').hide();
            jQuery('.field-name-field-service-audio').hide();
            jQuery('.field-name-field-service-video').hide();
            jQuery('input[name="field_service_content_add_more"]').hide();

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
            jQuery("#edit-field-service-frequency-date-und-0-show-todate").prop('checked', true);
            jQuery('#edit-field-service-frequency-date-und-0-show-todate').hide();
            jQuery('.form-item-field-service-frequency-date-und-0-value2').show();

            var selectedVal = "";
            var selected = $("#edit-field-service-frequency-und input[type='radio']:checked");
            if (selected.length > 0) {

                if (Drupal.settings.itg_mobile_services.settings.service_content_type) {
                    var content_format_arr = Drupal.settings.itg_mobile_services.settings.service_content_type;
                    jQuery.each(content_format_arr, function (key, value) {
                        // content-format-hidden
                        jQuery('#field-service-content-add-more-wrapper').show();
                        if (value == 1) {
                            jQuery('.field-name-field-story-expert-description').show();
                        } else if (value == 2) {
                            jQuery('.field-name-field-story-large-image').show();
                        } else if (value == 3) {
                            jQuery('.field-name-field-service-video').show();
                        } else if (value == 4) {
                            jQuery('.field-name-field-service-audio').show();
                        } else if (value == 5) {
                            jQuery('.field-name-field-story-expert-description').show();
                            jQuery('.field-name-field-story-large-image').show();
                            jQuery('.field-name-field-service-video').show();
                            jQuery('.field-name-field-service-audio').show();
                        }
                    });
                }

                var content_format = jQuery('#content-format-hidden').val();
                var content_format_array = jQuery('#content-format-hidden').val().split(',');
                if (content_format_array) {
                    jQuery.each(content_format_array, function (keys, values) {
                        console.log(values)
                        // content-format-hidden
                        if (values == 'text') { //alert(" val" + value );
                            jQuery('.field-name-field-story-expert-description').show();
                        } else if (values == 'image') {
                            jQuery('.field-name-field-story-large-image').show();

                        } else if (values == 'video') {
                            jQuery('.field-name-field-service-video').show();
                        } else if (values == 'audio') {
                            jQuery('.field-name-field-service-audio').show();
                        } else if (values == 'wap(image,text,videoandaudio)') {
                            jQuery('.field-name-field-story-expert-description').show();
                            jQuery('.field-name-field-story-large-image').show();
                            jQuery('.field-name-field-service-video').show();
                            jQuery('.field-name-field-service-audio').show();
                        }
                    });
                }


                selectedVal = selected.val();

                if (selectedVal == 2) {
                    fixedDate = "+6 D";
                    fixedDay = 6;
                } else if (selectedVal == 3) {
                    fixedDate = "+1M";
                    fixedDay = 30;
                }

                if (selectedVal > 1) {
                    jQuery('#edit-field-service-frequency-date').show();
                    $('#edit-field-service-content').show();
                }
            }

            jQuery('#edit-field-service-frequency-und input[type="radio"]').click(function () {
                if ($(this).attr("value") == "1") {
                    jQuery('#edit-field-service-content').show();
                    jQuery('#edit-field-service-frequency-date').hide();
                    jQuery('#edit-field-service-content-und-0-remove-button').hide();
                    jQuery('#edit-field-service-content-und-add-more').hide();
                } else if ($(this).attr("value") == "2") {
                    jQuery('#edit-field-service-content').show();
                    jQuery('#edit-field-service-frequency-date').show();
                    fixedDate = "+6 D";
                    fixedDay = 6;
                } else if ($(this).attr("value") == "3") {
                    jQuery('#edit-field-service-content').show();
                    jQuery('#edit-field-service-frequency-date').show();
                    fixedDate = "+1M";
                    fixedDay = 30;
                }
            });

            if (firstTime == 1) {
                jQuery('#reset-date-button').hide();
                $('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val('').removeAttr('disabled');
                $('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val('').removeAttr('disabled');
                firstTime++;
            }

            jQuery('#reset-date-button').on("click", function (event) {
                event.preventDefault();
                location.reload(true);
            });

            $("#edit-field-service-frequency-date-und-0-value-datepicker-popup-1").datepicker({
                minDate: 0,
                showOn: "focus",
                dateFormat: 'dd/mm/yy',
                onSelect: function (selected) {
                    var date = $(this).datepicker('getDate');
                    if (fixedDay > 7) {
                        month = date.getMonth() + 1,
                                year = date.getFullYear();
                        fixedDay = days_in_month(month, year) - 1;
                    }
                    date.setDate(date.getDate() + fixedDay); // Add 7 days
                    $("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker("option", "minDate", selected);
                    $("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker("option", "maxDate", date);
                    $('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val('').removeAttr('disabled');
                }
            });

            if (firstDate == 1) {
                $("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker({
                    minDate: 0,
                    maxDate: fixedDate,
                    dateFormat: 'dd/mm/yy',
                    onSelect: show_days,
                });
                firstDate++;
            } else {
                $("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker({
                    maxDate: fixedDate,
                    dateFormat: 'dd/mm/yy',
                    onSelect: show_days,
                });
            }

            function show_days() {
                var start = jQuery('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').datepicker('getDate');
                var end = jQuery('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').datepicker('getDate');
                var oneDay = 24 * 60 * 60 * 1000;
                if (start == null) {
                    $('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val('').removeAttr('disabled');
                    $('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val('').removeAttr('disabled');
                    $('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').focus();
                }
                var diff = 0;
                if (start && end) {
                    diff = Math.round(Math.abs((end.getTime() - start.getTime()) / (oneDay)));
                }
                jQuery('#edit-field-service-content-add-more-number').val(diff);


            }

            if (genrateFlag == 1) {
                jQuery(document).on("click", "#content-enable-button", function (event) {
                    event.preventDefault();
                    if (genrateFlag == 1) {
                        jQuery('#reset-date-button').show();
                        jQuery('#content-enable-button').hide();
                        jQuery('#edit-field-service-content-und-add-more').mousedown();
                        setTimeout(function () {  //Beginning of code that should run AFTER the timeout
                            console.log('calender update');
                            set_dates();
                            //lots more code
                        }, 3000);
                        genrateFlag++;
                    }
                });
            }




            function set_dates() {
                var today = new Date();
                var today_date = today.getDate();
                var from_date = jQuery('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val().split('/');
                var start_date = from_date[0];
                if (start_date < 10) {
                    start_date = start_date[start_date.length - 1]
                }
                start_date = start_date - today_date;
                var no_of_days = 1 + parseInt(jQuery('#edit-field-service-content-add-more-number').val());
                if (no_of_days > 1) {
                    for (var i = 0; i <= no_of_days; ) {
                        var tomorrow = new Date(new Date().getTime() + start_date * 24 * 60 * 60 * 1000);
                        var dd = tomorrow.getDate();
                        var mm = tomorrow.getMonth() + 1;
                        var yyyy = tomorrow.getFullYear();
                        if (dd < 10) {
                            dd = '0' + dd
                        }
                        if (mm < 10) {
                            mm = '0' + mm
                        }
                        tomorrow = dd + '/' + mm + '/' + yyyy;
                        jQuery('input[name="field_service_content[und][' + i + '][field_service_content_date][und][0][value][date]"]').val(tomorrow).addClass('itg-date-disabled');
                        i++;
                        start_date++;
                    }
                }


            }

        }
    }
})(jQuery);


//Month is 1 based
function days_in_month(month, year) {
    return new Date(year, month, 0).getDate();
}

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