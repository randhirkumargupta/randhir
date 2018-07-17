jQuery(document).ready(function () {
    jQuery("#edit-section-child").on('change', function () {
        var section_chlid = jQuery(this).val();
        jQuery("#edit-section-id").val(section_chlid);
    });
});