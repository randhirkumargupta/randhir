/*
 * @file itg_print_team.js
 */

(function($) {
  Drupal.behaviors.itg_print_team = {
    attach: function(context, settings) {

      // Collect required variables
      var uid = settings.itg_print_team.settings.uid;
      var base_url = settings.itg_print_team.settings.base_url;
      var type = settings.itg_print_team.settings.type;
      var nid = settings.itg_print_team.settings.nid;
      var print_media = settings.itg_print_team.settings.print_media;

      // Hide left side vertical tabs in case of simple users
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        $("#edit-metatags-und-advanced").hide();
        $(".form-item-metatags-und-abstract-value").hide();
      }

      // Make posted by filter field empty on click of reset button
      $('#edit-reset').click(function() {
        $('.views-widget-filter-uid #edit-uid').val('');
      });

      // Hide operation fieldset from view listing page
      $('.view-manage-print-team #edit-select').hide();

      // If print media content exists
      if (print_media) {
        $('input[name="field_pti_print_media_und_0_remove_button"]').show();
      } else {
        $('input[name="field_pti_print_media_und_0_remove_button"]').hide();
      }

      $('input[name="field_survey_end_date[und][0][value][date]"]').attr('readonly', true);
      $('#views-form-manage-print-team-page div .container-inline').hide();
      $('.form-item-pti-issue-date label').hide();

      if ($("input[name='field_pti_idea_status[und]']:checked").val() === 'Approved') {
        $('#edit-field-pti-words-limit').show();
        $('#edit-field-survey-end-date').show();

      }
      else {
        $('#edit-field-pti-words-limit').hide();
        $('#edit-field-survey-end-date').hide();
      }

      $("input[name='field_pti_idea_status[und]").on("click", function() {
        if ($("input[name='field_pti_idea_status[und]']:checked").val() === 'Approved') {
          $('#edit-field-pti-words-limit').show();
          $('#edit-field-survey-end-date').show();
        }
        else {
          $('#edit-field-pti-words-limit').hide();
          $('#edit-field-survey-end-date').hide();
        }

        // Scroll page to show comment section
        $('html, body').animate({
          scrollTop: $("#edit-field-pti-idea-status").offset().top
        }, 1000);
      });

      // Code use for make primary category
      jQuery('.add-to-dropbox').mousedown(function()
      {
        var selectvalue = jQuery('.selects > .form-select:last option:selected').val();
        var comptext = "";
        var makeradio = "";
        var flag = 0;
        if (selectvalue != "")
        {
          jQuery('.selects > .form-select').each(function()
          {
            var getid = jQuery(this).attr('id');
            var selopttext = jQuery('#' + getid + ' option:selected').text();
            var selval = jQuery('#' + getid + ' option:selected').val();
            if (selval.indexOf("label") != 0)
            {
              comptext = comptext + selopttext + '›';
            }

          });
          comptext = comptext.slice(0, -1);
          jQuery('#primary-category-data option').each(function()
          {
            var existvalue = jQuery(this).val();
            if (selectvalue == existvalue)
            {
              flag = 1;
            }

          })
          if (comptext != "" && flag == 0)
          {
            makeradio = '<option value="' + selectvalue + '">' + comptext + '</option>';
            jQuery('#primary-category-data').append(makeradio);

            var gethtml = jQuery('#primary-category-data').html();
            jQuery('#edit-field-primary-category-html-und-0-value').val(gethtml);
          }
        }

      });

      jQuery('.dropbox-remove a').click(function() {
        var getdattext = jQuery(this).parent().siblings('td').text();
        $('#primary-category-data option').each(function() {
          var getdoptiontext = jQuery(this).text();
          if (getdoptiontext == getdattext) {
            jQuery(this).remove();
          }
        });
      });

      jQuery('#primary-category-data').change(function() {
        var getval = jQuery(this).val();
        jQuery('#edit-field-primary-category-und-0-value').val(getval);
        jQuery('#primary-category-data option').attr('selected', false);
        jQuery('#primary-category-data option[value=' + getval + ']').attr('selected', 'selected');
        var gethtml = jQuery('#primary-category-data').html();
        jQuery('#edit-field-primary-category-html-und-0-value').val(gethtml);
      });
    }
  };

})(jQuery, Drupal, this, this.document);

// Assign old selected category in to primary category
jQuery(window).load(function() {
  // executes when complete page is fully loaded, including all frames, objects and images
  var getvaluehtml = jQuery('#edit-field-primary-category-html-und-0-value').val();
  if (getvaluehtml != "")
  {
    jQuery('#primary-category-data').html(getvaluehtml);
  }
});