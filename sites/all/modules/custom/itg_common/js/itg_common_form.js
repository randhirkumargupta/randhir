/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function ($) {
    Drupal.behaviors.itg_common_form = {
        attach: function (context, settings) {

            var fid = settings.itg_common.settings.formid;

            if (fid == 'views-exposed-form-photo-gallery-management-page-1'
                    || fid == 'views-exposed-form-movie-review-list-page'
                    || fid == 'views-exposed-form-blogs-management-page-1'
                    || fid == 'views-exposed-form-manage-quiz-page') {
                // remove space from title search field.
                jQuery(".tabledrag-toggle-weight-wrapper").hide();
            }

            if (fid == 'views-exposed-form-category-manager-dev-page'
                    || fid == 'views-exposed-form-tags-management-page') {
                jQuery(".form-submit").click(function () {
                    jQuery("#edit-name").val(jQuery.trim(jQuery("#edit-name").val()));
                });
            }

            if (fid == 'views-exposed-form-recipe-management-page'
                    || fid == 'views-exposed-form-recipe-management-page-1'
                    || fid == 'views-exposed-form-recipe-management-page-2') {
                jQuery(".form-submit").click(function () {
                    jQuery("#edit-title").val(jQuery.trim(jQuery("#edit-title").val()));
                });
            }

            if (fid == 'views-exposed-form-manage-users-page') {
                jQuery(".form-submit").click(function () {
                    jQuery("#edit-mail").val(jQuery.trim(jQuery("#edit-mail").val()));
                    jQuery("#edit-field-first-name-value").val(jQuery.trim(jQuery("#edit-field-first-name-value").val()));
                    jQuery("#edit-field-mobile-number-value").val(jQuery.trim(jQuery("#edit-field-mobile-number-value").val()));
                });
            }

            if (fid == 'views-exposed-form-ask-an-expert-page'
                    || fid == 'views-exposed-form-ask-an-expert-page-2') {
                jQuery(".form-submit").click(function () {
                    jQuery("#edit-field-user-email-value").val(jQuery.trim(jQuery("#edit-field-user-email-value").val()));
                    jQuery("#edit-title").val(jQuery.trim(jQuery("#edit-title").val()));

                });
            }

            // bulk operation
            if (fid == 'views-exposed-form-manage-users-page') {
                jQuery("#edit-submit--2").click(function () {
                    var searchIDs = [];
                    var operation = jQuery("#edit-operation").val();
                    jQuery("#views-form-manage-users-page input:checkbox:checked").map(function () {
                        searchIDs.push(jQuery(this).val());
                    });
                    if (searchIDs.length != 0 && operation == "action::user_block_user_action") {
                        var msg = confirm("Are you sure, you want to block user?");
                        if (msg == true) {
                            return true;
                        }
                        return false;
                    }

                });
            }

            // remove space from title search field.
            jQuery(".form-submit").click(function () {
                var title = jQuery.trim(jQuery("#edit-title").val());

                if (title == "") {
                    jQuery("#edit-title").val("");
                }

                var nid = jQuery.trim(jQuery("#edit-nid").val());
                if (nid == "") {
                    jQuery("#edit-nid").val("");
                }

            });

        }

    };
})(jQuery, Drupal, this, this.document);

// code to reset breaking news listing when user click on back button
jQuery(document).ready(function () {
    jQuery('form').each(function () {
        this.reset();
        // code to restrict user to enter only numeric value
        jQuery('#edit-nid').keyup(function () {
            this.value = this.value.replace(/[^0-9\.]/g, '');
        });
    });

//    /* Comma Separated Values (.csv) */
//    jQuery.fn.tableExport.csv = {
//        defaultClass: "csv",
//        buttonContent: "Export to csv",
//        separator: ",",
//        mimeType: "application/csv",
//        fileExtension: ".csv",
//    };
    jQuery("#export-csv").click(function () {
        jQuery(".views-table").tableToCSV();
    });

    if (jQuery('table').hasClass('data-export-tags')) {
        jQuery("#data-export-tags").tableExport({
            bootstrap: false,
            headings: false,
            footers: false,
            formats: ["csv"],
            fileName: "tags",
            ignoreCols: [0, 2, 5],
        });
    }
});