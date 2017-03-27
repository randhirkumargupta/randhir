/*
 * @file itg_ads.js
 * Contains all functionality related to Ads Management
 */

(function($) {
  Drupal.behaviors.itg_ads = {
    attach: function(context) {

      // Disable edit mode of date fields
      $('input[name="field_ads_start_date[und][0][value][date]"]').keydown(false);
      // $('input[name="field_ads_end_date[und][0][value][date]"]').keydown(false);
      // Module code end
      $('#edit-field-ads-template-selection-und').change(function() {

        var val = $('#edit-field-ads-template-selection-und').val();

        if (val == "Section") { // if section select then template variant should be reset
          var opt = $('select[name="field_ads_select_secton_option[und]"]').val();
          if (opt != '_none') {
            $('select[name="field_ads_select_secton_option[und]"]').html('<option value="_none">-None-</option>');
          }
          //    $('#edit-field-ads-template-variants-und').val('');
        } else if (val == "Home") { // if home select then content/section selection should be reset
          $('#edit-field-ads-section-selection-und').val('');
          //    $('#edit-field-ads-content-selection-und').val('');
        } else if (val == "Rest") { // if rest select then content/section selection and template variant should be reset 
          //  $('#edit-field-ads-template-variants-und').val('');
          $('#edit-field-ads-section-selection-und').val('');
          //  $('#edit-field-ads-content-selection-und').val('');

        }

      });
      $('#edit-field-ads-section-selection-und').change(function() {
        $('#edit-field-ads-placeholder-und--3').find('option').remove();
      });

      $('select[name="field_ads_select_secton_option[und]"]').change(function() {
        var val = $(this).val();
        if (val == "_none") { // if section select then template variant should be reset
          $('select[name="field_ads_placeholder[und]"]').html("");
        }
      });


      $('select[name="field_ads_placeholder[und]"]').html();

      // This is for hiding some default values
      jQuery('[name="field_ads_ex_headerscript_und_0_remove_button"]').hide();
      jQuery('[name="field_ads_ex_body_start_und_0_remove_button"]').hide();
      jQuery('[name="field_ads_ex_body_close_und_0_remove_button"]').hide();

    }

  };
})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function() {
  jQuery('#itg_ads_ttype_replace').hide();

  jQuery('[name="field_select_template_type[und]"]').on('click', function() {

    switch (jQuery(this).val()) {
      case 'Home':
        var home_option = "<option value='Home'>Home</option>";
        jQuery('[name="field_ads_template_selection[und]"]').append(home_option);
        jQuery('[name="field_ads_template_selection[und]"]').val('Home');
        jQuery('[name="field_ads_template_selection[und]"]').trigger('change');
        jQuery('#itg_ads_ttype_replace').hide();

        break;
      case 'Rest':
        var rest_option = "<option value='Rest'>Rest of the Site</option>";
        jQuery('[name="field_ads_template_selection[und]"]').append(rest_option);
        jQuery('[name="field_ads_template_selection[und]"]').val('Rest');
        jQuery('[name="field_ads_template_selection[und]"]').trigger('change');
        jQuery('#itg_ads_ttype_replace').hide();
        break;

      case 'Section':
        jQuery('[name="field_ads_template_selection[und]"]').find('option[value=Home]').remove();
        jQuery('[name="field_ads_template_selection[und]"]').find('option[value=Rest]').remove();
        jQuery('#itg_ads_ttype_replace').show();
        break;

    }


  });

  try {
    if (jQuery('[name="field_select_template_type[und]"]:checked').val() == "Section") {
      jQuery('#itg_ads_ttype_replace').show();
    }
  } catch (e) {

  }

  jQuery('.itg-ads-preview-ads').on('click', function(e) {
    e.preventDefault();
    jQuery.colorbox({
      open: true,
      scrolling: false,
      innerWidth: '800',
      innerHeight: '600',
      href: Drupal.settings.basePath + "itg-ads-preview-ads",
      data: jQuery("#ads-management-node-form").serializeArray(),
      onClosed: function() {
        //Do something on close.
      }
    });

  });

});