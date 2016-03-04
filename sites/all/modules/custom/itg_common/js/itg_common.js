/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
  Drupal.behaviors.itg_common = {
    attach: function (context) {
      
      $('#edit-title').val(moment().format('L'));
      
      // Show numerology values
      $("#edit-field-numerology-und-1").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $("#edit-field-field-astro-date-range2").css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-story-source-id label:first").html('Enter Number<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-buzz-description label:first").html('Enter Text<span class="form-required" title="This field is required."> *</span>');
      });
      
      $("#edit-field-numerology-und-0").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'none');
        $('#edit-field-astro-frequency2').css('display', 'none');
        $("#edit-field-field-astro-date-range2").css('display', 'none');
      });
      
      var num = $('input[name="field_numerology[und]"]:checked').val();
      if (num == 1) {
        $("#edit-field-field-astro-date-range2").css('display', 'block');
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-story-source-id label:first").html('Enter Number<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-buzz-description label:first").html('Enter Text<span class="form-required" title="This field is required."> *</span>');
      }
      
      // Code for astro node form to expand sef url and meta fields.
      var uid = Drupal.settings.uid;      
      if (uid != 1) {
        $('#edit-field-recipe-description-und-0-format').hide();
        $('#edit-metatags').show();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags-und-advanced').hide();
      }

    }

  };
})(jQuery, Drupal, this, this.document);