/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */
//cancle-itg-btn
(function ($) {
    Drupal.behaviors.itg_common_admin = {
        attach: function (context, settings) {

            var uid = settings.itg_common.settings.uid;
            // checkbox hide for all user of Provide a menu link on all form
            if (uid != 1) {
                jQuery(".form-item-menu-enabled").hide();
            }
            jQuery("#edit-field-highlights-und-0-remove-button").hide();

            // for lock content
            $('.cancle-itg-btn').click(function () {
                var base_url = Drupal.settings.baseUrl.baseUrl;
                var nid = $(this).attr('data-widget');
                var itgurl = $(this).attr('data-dest');

                $.ajax({
                    url: base_url + "/itg-custom-lock-delete",
                    method: 'post',
                    data: {nid: nid},
                    beforeSend: function () {

                    },
                    success: function (data) {
                        window.location.href = base_url + "/" + itgurl;
                    }
                });

            });

    }

  };
})(jQuery, Drupal, this, this.document);
