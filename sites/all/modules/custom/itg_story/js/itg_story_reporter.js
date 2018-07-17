/*
 * @file itg_reporter.js
 * Contains all functionality related to Reporter
 */

(function($) {
    Drupal.behaviors.itg_reporter = {
        attach: function(context, settings) {
            var uid = settings.itg_reporter.settings.uid;
            var reporter = settings.itg_reporter.settings.reporter;
            var cmpny = $('#edit-field-byline-company-und').val();
            var dprt = $('#edit-field-byline-department-und').val();
            var intialcelebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
            if (intialcelebrityvalue) {
                var initialhasexist_reporter = intialcelebrityvalue.indexOf(reporter) != -1;
            }
            if (initialhasexist_reporter) {
                $('#edit-field-reporter-profile-type').show();
                $('#edit-field-byline-company').show();
                $('#edit-field-byline-department').show();
            } else {
                $('#edit-field-reporter-profile-type').hide();
                $('#edit-field-byline-company').hide();
                $('#edit-field-byline-department').hide();
            }
            $('#edit-field-celebrity-pro-occupation-und').change(function() {
                var celebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
                var initial_repo = celebrityvalue.indexOf(reporter) != -1;
                if (initial_repo) {
                    $('#edit-field-reporter-profile-type').show();
                    $('#edit-field-byline-company').show();
                    $('#edit-field-byline-department').show();
                } else {
                    $('#edit-field-reporter-profile-type').hide();
                    $("#edit-field-reporter-profile-type option:selected").prop('selected', false);
                    $('#edit-field-byline-company').hide();
                    $("#edit-field-byline-company option:selected").prop('selected', false);
                    $('#edit-field-byline-department').hide();
                    $("#edit-field-byline-department option:selected").prop('selected', false);
                }
            });

            // Common function to reset all values.
            function clear_form_elements(class_name) {
                jQuery("." + class_name).find(':input').each(function() {
                    switch (this.type) {
                        case 'text':
                        case 'textarea':
                            $(this).val('');
                            break;

                        case 'select-one':
                            $(this).val('_none');
                            break;
                    }
                });
            }

            // restrict mouse down on datefield.
            // date-clear form-text hasDatepicker date-popup-init valid
            $('input .hasDatepicker').keypress(function(e) {
                return false
            });

            // validation in case of internal author
            $("#reporter-node-form").validate({                
                onfocusout: function(element) {
                    $(element).valid();
                },
                ignore: '',
                errorElement: 'span',
                errorPlacement: function(error, element) {
                    var elementName = element.attr('name');
                    var errorPlaceHolder = '';
                    switch (elementName) {

                        default:
                            errorPlaceHolder = element.parent();
                    }
                    error.appendTo(errorPlaceHolder);
                },
                rules: {
                    'title': {
                        required: true

                    },
                    'field_reporter_email_id[und][0][value]': {
                        laxEmail: true

                    },
                    'field_celebrity_pro_occupation[und][]': {
                        required: true

                    },
                    'field_byline_company[und]': {
                        validatecompany: {
                            depends: function() {
                                var profile = $('#edit-field-reporter-profile-type-und').val();
                                if (profile == 'internal') {
                                    return true;
                                }
                                else {
                                    return false;
                                }
                            }
                        }
                    },
                    'field_byline_department[und]': {
                        validatedepartment: {
                            depends: function() {
                                var profile = $('#edit-field-reporter-profile-type-und').val();
                                if (profile == 'internal') {
                                    return true;
                                }
                                else {
                                    return false;
                                }
                            }
                        }
                    },
                },
                messages: {
                    'title': {
                        required: 'Name field is required.'
                    },
                    'field_celebrity_pro_occupation[und][]': {
                        required: 'occupation field is required.'
                    },
                    'field_byline_company[und]': {
                        required: 'Company field is required.'
                    },
                    'field_byline_department[und]': {
                        required: 'Department field is required.'
                    }
                }
            });
            jQuery.validator.addMethod("laxEmail", function(value, element) {
                // allow any non-whitespace characters as the host part
                return this.optional(element) || /^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(value);
            }, 'Please enter a valid email address.');

            jQuery.validator.addMethod("validatecompany", function(value, element) {
                return validate_company_name_value(value, element);
            }, "Company name is required.");
            jQuery.validator.addMethod("validatedepartment", function(value, element) {
                return validate_department_name_value(value, element);
            }, "Department name is required.");

            // Validate company name drop down.
            function validate_company_name_value(event, element) {
                if ($(element).val() == '_none') {

                    return false;
                }
                else {
                    return true;
                }
            }
            // Validate department name drop down.
            function validate_department_name_value(event, element) {
                if ($(element).val() == '_none') {

                    return false;
                }
                else {
                    return true;
                }
            }

            // end here

        }

    };
})(jQuery, Drupal, this, this.document);
