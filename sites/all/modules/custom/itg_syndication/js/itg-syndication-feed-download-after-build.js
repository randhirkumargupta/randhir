jQuery(document).ready(function () {
    jQuery(".form-item-feed-download-value").hide();

    jQuery("#edit-download-feed").click(function () {
        jQuery("#edit-changed-min-datepicker-popup-0").val("");
        jQuery("#edit-changed-max-datepicker-popup-0").val("");
        jQuery("#edit-feed-download-value").val("yes");
    });

    jQuery("#edit-submit").click(function () {
        jQuery("#edit-changed-min-datepicker-popup-0").val("");
        jQuery("#edit-changed-max-datepicker-popup-0").val("");
        jQuery("#edit-feed-download-value").val("");
    });

});