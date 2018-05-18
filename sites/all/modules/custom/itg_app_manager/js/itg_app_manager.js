/*
 * @file itg_app_manager.js
 * Contains all functionality related to itg app manager
 */
jQuery(document).ready(function () {
    jQuery(".delete-m-menu").click(function (event) {
        if (confirm("Are you sure you want to delete this?")) {
            idsstr = event.target.id;
            ids = idsstr.replace(/[^\d.]/g, '');
            jQuery.ajax({
                url: Drupal.settings.basePath + 'm-menu/' + ids + '/delete',
                success: function (data) {
                    location.reload();
                }

            });
        }

    });


});






