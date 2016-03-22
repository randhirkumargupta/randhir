/*
 * @file itg_recipe.js
 * Contains all functionality related to Recipe
 */


(function($) {
    Drupal.behaviors.itg_recipe = {
        attach: function(context, settings) {
            $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
            var uid = settings.itg_recipe.settings.uid;
            if (uid != 1) {
                $('#edit-body-und-0-format').hide();
                $('#edit-field-recipe-description-und-0-format').hide();
                $('#edit-metatags').show();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags-und-advanced').hide();
            }
        }
    };
})(jQuery, Drupal, this, this.document);