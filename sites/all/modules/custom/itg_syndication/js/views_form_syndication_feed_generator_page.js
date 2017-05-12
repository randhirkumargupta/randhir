jQuery(document).ready(function () {
    jQuery("#edit-changed-max-datepicker-popup-0 , #edit-changed-min-datepicker-popup-0").datepicker({
        dateFormat: 'dd/mm/yy',
        changeMonth: true,
        changeYear: true,
        maxDate: new Date(),
    });
    jQuery(".item-list").hide();
    jQuery("div").parents("#itg-cutom-pager").find(".item-list").show();
});