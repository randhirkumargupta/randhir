/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
var session = 1;
var firstTime = 1;
var genrateFlag = 1;
var rowCount = 1;
var firstDate = 1;
var fixedDate = '';
var maxLen = 0;
var astroFlag = 0;
(function ($) {

    Drupal.behaviors.itg_mobile_service_form = {
        attach: function (context, settings) {

            jQuery.fn.mobile_astro_custom_js = function () {
                jQuery('#edit-field-service-content-und-add-more').mousedown();
            };

            if (Drupal.settings.itg_mobile_services.settings.astro_service) {
                jQuery(".field-type-text.field-name-field-client-short-description.field-widget-text-textfield.form-wrapper").hide();
                jQuery('#edit-field-service-content-und-0-field-service-content-date-und-0-value-datepicker-popup-1').val('');
                //jQuery("input[id*='field-service-content-date-und-0-value']").hide();
                jQuery("[id*='field-service-content-date']").hide();
                astroFlag = 1;
            }
            if (Drupal.settings.itg_mobile_services.settings.service_content_first_row_hide) {
                var first_row_hide = Drupal.settings.itg_mobile_services.settings.service_content_first_row_hide;
                if (first_row_hide) {
                    jQuery("#edit-field-service-content tbody tr:first").css("display", "none");
                }
            }

            jQuery('.form-field-name-field-service-content .cancel').hide();
            jQuery('.form-field-name-field-service-content .form-type-date-popup input').addClass('itg-disabled');
            jQuery('input[name="field_service_content[und][0][field_service_content_date][und][0][value][date]"]').removeClass('itg-disabled');
            jQuery('#edit-field-service-frequency-und input').click(function () {
                if ($(this).val() == 2) { // weekly
                    jQuery('#edit-field-service-content-und-0-field-service-content-date-und-0-value-datepicker-popup-1').val('');
                } else if ($(this).val() == 3) { // monthly
                    jQuery('#edit-field-service-content-und-0-field-service-content-date-und-0-value-datepicker-popup-1').val('');
                }
            });
            jQuery('#content-enable-button').hide();
            jQuery('#client_entity_wrapper').hide();
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

            // session
            if (Drupal.settings.itg_mobile_services.settings.session_service_title) {
                if (session == 1) {
                    var session_service_title = Drupal.settings.itg_mobile_services.settings.session_service_title;
                    var session_content_format = Drupal.settings.itg_mobile_services.settings.session_content_format;
                    var session_client_name = Drupal.settings.itg_mobile_services.settings.session_client_name;
                    var session_service_frequency_id = Drupal.settings.itg_mobile_services.settings.session_service_frequency_id;
                    jQuery('#edit-title').val(session_service_title);
                    jQuery('#content-format-hidden').val(session_content_format);
                    jQuery('#edit-field-footer-und-0-value').val(session_client_name);
                    jQuery('#edit-field-service-frequency-und-' + session_service_frequency_id).prop('checked', true);
                    jQuery('#edit-field-service-frequency').show();
                    jQuery('#edit-field-service-frequency-date').show();
                    if (astroFlag == 1) {
                        jQuery('#content-enable-button').hide();
                    } else {
                        jQuery('#content-enable-button').show();
                    }

                    session++;
                } else {
                    jQuery('#edit-field-service-frequency-date').hide();
                }

            } else {
                // hide defaut 
                jQuery("#edit-field-service-frequency-date-und-0-show-todate").prop('checked', true);
                jQuery('#edit-field-service-frequency-date').hide();
            }

            jQuery.fn.content_create_custom_js = function () {
                jQuery('#edit-field-service-frequency-und-1').prop('checked', true);
                var today_date = custom_today_date();
                jQuery('input[name="field_service_content[und][0][field_service_content_date][und][0][value][date]"]').val(today_date);
                $('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val(today_date).removeAttr('disabled');
                $('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val(today_date).removeAttr('disabled');
            };
            // hide defaut service-frequency-date
            jQuery('#edit-field-service-frequency-date-und-0-show-todate').hide();
            jQuery('.form-item-field-service-frequency-date-und-0-value2').show();

            var selectedVal = "";
            var selected = $("#edit-field-service-frequency-und input[type='radio']:checked");
            if (selected.length > 0) {

                if (Drupal.settings.itg_mobile_services.settings.service_content_type) {
                    // set alt text and title text
                    jQuery("input[id*='field-story-large-image-und-0-alt']").attr('placeholder', 'description');
                    jQuery("input[id*='field-story-large-image-und-0-title']").attr('placeholder', 'keywords');

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
                        // content-format-hidden
                        jQuery('#field-service-content-add-more-wrapper').show();
                        // content-format-hidden
                        if (values == 'text') {
                            jQuery('.field-name-field-story-expert-description').show();
                        } else if (values == 'image') {
                            jQuery('.field-name-field-story-large-image').show();

                        } else if (values == 'video') {
                            jQuery('.field-name-field-service-video').show();
                        } else if (values == 'audio') {
                            jQuery('.field-name-field-service-audio').show();
                        } else if (values == 'wap(image') {
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

                }
            }

            var service_asso = jQuery("#edit-field-service-association-title-und option:selected").val();
            if (service_asso != '_none' && service_asso > 1) {
                $('#edit-field-service-content').show();
            }

            jQuery('#edit-field-service-frequency-und input[type="radio"]').click(function () {
                if ($(this).attr("value") == "1") {
                    jQuery('#content-enable-button').hide();
                    jQuery('#edit-field-service-content-und-0-remove-button').hide();
                    jQuery('#field-service-content-add-more-wrapper').show();
                    jQuery('#edit-field-service-frequency-date').hide();
                    jQuery('#edit-field-service-content-und-0-remove-button').hide();
                    jQuery('#edit-field-service-content-und-add-more').hide();

                    var today_date = custom_today_date();
                    if (astroFlag == 1) {
                        jQuery("#edit-field-service-content tbody tr:first").css("display", "hide");
                    } else {
                        jQuery("#edit-field-service-content tbody tr:first").css("display", "block");
                        jQuery('input[name="field_service_content[und][0][field_service_content_date][und][0][value][date]"]').val(today_date);
                    }
                    jQuery('input[name="field_service_frequency_date[und][0][value][date]"]').val(today_date);
                    jQuery('input[name="field_service_frequency_date[und][0][value2][date]"]').val(today_date);
                } else if ($(this).attr("value") == "2") {
                    jQuery('#edit-field-service-content-und-0-remove-button').show();
                    jQuery('#field-service-content-add-more-wrapper').hide();
                    if (astroFlag == 1) {
                        jQuery('#content-enable-button').hide();
                    } else {
                        jQuery('#content-enable-button').show();
                    }
                    jQuery('#edit-field-service-content').show();
                    jQuery('#edit-field-service-frequency-date').show();
                    fixedDate = "+6 D";
                    fixedDay = 6;
                    jQuery('input[name="field_service_frequency_date[und][0][value][date]"]').val('');
                    jQuery('input[name="field_service_frequency_date[und][0][value2][date]"]').val('');
                } else if ($(this).attr("value") == "3") {
                    jQuery('#edit-field-service-content-und-0-remove-button').show();
                    jQuery('#field-service-content-add-more-wrapper').hide();
                    if (astroFlag == 1) {
                        jQuery('#content-enable-button').hide();
                    } else {
                        jQuery('#content-enable-button').show();
                    }
                    jQuery('#edit-field-service-content').show();
                    jQuery('#edit-field-service-frequency-date').show();
                    fixedDate = "+1M";
                    fixedDay = 30;
                    jQuery('input[name="field_service_frequency_date[und][0][value][date]"]').val('');
                    jQuery('input[name="field_service_frequency_date[und][0][value2][date]"]').val('');
                }
            });

            if (firstTime == 1) {
                jQuery('<span id="custom_service_content_0"></span>').insertAfter('textarea[name="field_service_content[und][0][field_story_expert_description][und][0][value]"]');
                var length_textarea = jQuery("#field-service-content-values > tbody > tr").length;

                for (var ii = 1; ii <= length_textarea; ) {
                    jQuery('<span id="custom_service_content_' + ii + '"></span>').insertAfter('textarea[name="field_service_content[und][' + ii + '][field_story_expert_description][und][0][value]"]');
                    ii++;
                }
                jQuery('#field-service-content-add-more-wrapper').hide();
                if (Drupal.settings.itg_mobile_services.settings.session_service_title == 'undefined' || Drupal.settings.itg_mobile_services.settings.session_service_title == null || Drupal.settings.itg_mobile_services.settings.session_service_title == '') {
                    jQuery('#edit-field-service-frequency').hide();
                }

                jQuery('#reset-date-button').hide();
                if (Drupal.settings.itg_mobile_services.settings.service_content_edit_mode == false) {
                    if (Drupal.settings.itg_mobile_services.settings.session_service_title == 'undefined' || Drupal.settings.itg_mobile_services.settings.session_service_title == null || Drupal.settings.itg_mobile_services.settings.session_service_title == '') {
                        jQuery('#edit-field-service-frequency-und-1').prop('checked', true);
                        var today_date = custom_today_date();
                        jQuery('input[name="field_service_content[und][0][field_service_content_date][und][0][value][date]"]').val(today_date);
                        $('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val(today_date).removeAttr('disabled');
                        $('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val(today_date).removeAttr('disabled');
                    }
                }
                firstTime++;
            }

            jQuery('#reset-date-button').on("click", function (event) {
                event.preventDefault();
                location.reload(true);
            });
            var currentTime = new Date();
            // First Date Of the month 
            var startDateFrom = new Date(currentTime.getFullYear(), currentTime.getMonth(), 1);
            $("#edit-field-service-content-und-0-field-service-content-date-und-0-value-datepicker-popup-1").datepicker({
                minDate: startDateFrom,
                showOn: "focus",
                dateFormat: 'dd/mm/yy',
                onSelect: function (selected) {
                    $('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val(selected);
                    $('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val(selected);
                }
            }).attr('readonly', 'readonly');

            $("#edit-field-service-frequency-date-und-0-value-datepicker-popup-1").datepicker({
                minDate: startDateFrom,
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
            }).attr('readonly', 'readonly');

            if (firstDate == 1) {
                $("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker({
                    minDate: 0,
                    maxDate: fixedDate,
                    dateFormat: 'dd/mm/yy',
                    onSelect: show_days,
                }).attr('readonly', 'readonly');
                firstDate++;
            } else {
                $("#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").datepicker({
                    maxDate: fixedDate,
                    dateFormat: 'dd/mm/yy',
                    onSelect: show_days,
                }).attr('readonly', 'readonly');
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
                    var sdate = jQuery('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val();
                    var edate = jQuery('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val();
                    if (sdate == '') {
                        jQuery(".form-item-field-service-frequency-date-und-0-value-date span").empty('');
                        jQuery('.form-item-field-service-frequency-date-und-0-value2 span').empty('');
                        jQuery('.form-item-field-service-frequency-date-und-0-value-date').append('<span class="error">Please enter start date.</span>');
                        return false;
                    } else if (edate == '') {
                        jQuery(".form-item-field-service-frequency-date-und-0-value-date span").empty('');
                        jQuery('.form-item-field-service-frequency-date-und-0-value2 span').empty('');
                        jQuery('.form-item-field-service-frequency-date-und-0-value2').append('<span class="error">Please enter end date.</span>');
                        return false;
                    }
                    jQuery(".form-item-field-service-frequency-date-und-0-value-date span").remove();
                    jQuery('.form-item-field-service-frequency-date-und-0-value2 span').remove();

                    var sTitle = jQuery("#edit-field-service-association-title-und option:selected").val();
                    if (sTitle == '_none') {
                        return false;
                    }

                    if (genrateFlag == 1) {
                        jQuery("#edit-field-service-association-title-und, #edit-field-footer-und-0-value--2, #edit-field-service-frequency-date-und-0-value-datepicker-popup-1, #edit-field-service-frequency-date-und-0-value2-datepicker-popup-1").addClass("itg-disabled");
                        jQuery('#edit-field-service-frequency-und').addClass('itg-disabled-radio');
                        var hideContent = 1;
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

            jQuery("input[id*='field-client-short-description-und']").attr("placeholder", "Title");
            jQuery('#edit-field-service-content textarea').attr("placeholder", "Content Text");

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
                        jQuery('input[name="field_service_content[und][' + i + '][field_service_content_date][und][0][value][date]"]').addClass('itg-disabled');
                        jQuery('<span id="custom_service_content_' + i + '"></span>').insertAfter('textarea[name="field_service_content[und][' + i + '][field_story_expert_description][und][0][value]"]');
                        i++;
                        start_date++;
                    }
                }

            }

            if (Drupal.settings.itg_mobile_services.settings.service_content_edit_mode) {
                var content_edit_mode = Drupal.settings.itg_mobile_services.settings.service_content_edit_mode;
                jQuery('#field-service-content-add-more-wrapper').show();
                jQuery('#edit-field-service-frequency').show();
                jQuery('#edit-field-service-frequency-und').addClass('itg-disabled-radio');
                jQuery('#edit-field-service-content-und-0-field-service-content-date-und-0-value-datepicker-popup-1, #edit-field-service-association-title-und, #edit-field-footer-und-0-value--2, #edit-field-service-frequency-date-und-0-value-datepicker-popup-1, #edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').addClass('itg-disabled');
                if (Drupal.settings.itg_mobile_services.settings.service_frequency) {
                    if (Drupal.settings.itg_mobile_services.settings.service_frequency == 1) {
                        var sdate = jQuery('#edit-field-service-frequency-date-und-0-value-datepicker-popup-1').val();
                        jQuery('#edit-field-service-frequency-date-und-0-value2-datepicker-popup-1').val(sdate);
                    }
                }
            }

            function custom_today_date() {
                var today = new Date();
                var dd = today.getDate();
                var mm = today.getMonth() + 1;
                var yyyy = today.getFullYear();
                if (dd < 10) {
                    dd = '0' + dd
                }
                if (mm < 10) {
                    mm = '0' + mm
                }
                return today = dd + '/' + mm + '/' + yyyy;
            }

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


            jQuery('.field-name-field-story-expert-description .form-textarea').on('keyup', function () {
                if (Drupal.settings.itg_mobile_services.settings.countchar) {
                    maxLen = Drupal.settings.itg_mobile_services.settings.countchar;
                }
                var id = jQuery(this).attr("id");
                var string = id.split("-");
                var tlength = jQuery(this).val().length;
                console.log(maxLen);
                jQuery(this).val(jQuery(this).val().substring(0, maxLen));
                remain = maxLen - parseInt(tlength);
                jQuery('#custom_service_content_' + string[5]).text(remain + ' characters remaining out of ' + maxLen);
            });
        }
    }
})(jQuery);


//Month is 1 based
function days_in_month(month, year) {
    return new Date(year, month, 0).getDate();
}

