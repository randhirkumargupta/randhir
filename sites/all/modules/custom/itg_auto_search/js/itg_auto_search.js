/**
 * @file itg_auto_search.js
 * This is used for auto search form validation
 */
jQuery(document).ready(function () {
    jQuery('.itg_auto_search_form #edit-submit').click(function (event) {
        var auto_brand = jQuery('.itg_auto_search_form [name="auto_brand"]').val();
        var auto_brand_2 = jQuery('.itg_auto_search_form [name="auto_brand_2"]').val();
        if (auto_brand == 0 && auto_brand_2 == 0) {
            alert(Drupal.t('Please select Brand'));
            return false;
        }
        if (auto_brand != 0) {
            var auto_model = jQuery('.itg_auto_search_form [name="auto_model"]').val();
            if (auto_model == 0 || auto_model == '') {
                alert(Drupal.t('Please select Model'));
                return false;
            }

        }

        if (auto_brand_2 != 0) {
            var auto_model_2 = jQuery('.itg_auto_search_form [name="auto_model_2"]').val();
            if (auto_model_2 == 0 || auto_model_2 == '') {
                alert(Drupal.t('Please select Model'));
                return false;
            }
            if (auto_model == auto_model_2) {
                alert(Drupal.t('You can not compare same model of brands,Please choose different'));
                return false;
            }
            var auto_price_range_2 = jQuery('.itg_auto_search_form [name="auto_price_range_2"]').val();
            if (auto_price_range_2 == 0 || auto_price_range_2 == '') {
                alert(Drupal.t('Please select price range'));
                return false;
            }
        }
        return true;
    });
});
