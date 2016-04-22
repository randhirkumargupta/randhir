(function ($) {
  Drupal.behaviors.itg_row_selector = {
    attach: function(context) {
      $('.itg-row-selector-selection-form', context).each(function() {
        Drupal.itgRowSelector.initTableBehaviors(this);
        Drupal.itgRowSelector.initGenericBehaviors(this);
      });
    }
  }

  Drupal.itgRowSelector = Drupal.itgRowSelector || {};
  Drupal.itgRowSelector.initTableBehaviors = function(form) {
    $('.itg-row-selector-table-select-all', form).show();
    // This is the "select all" checkbox in (each) table header.
    $('.itg-row-selector-table-select-all', form).click(function() {
      var table = $(this).closest('table')[0];
      $('input[id^="edit-itg-row-selector"]:not(:disabled)', table).attr('checked', this.checked);

      var values = $('input[id^="edit-itg-row-selector"]:checked').map(function () {
        return this.value;
      }).get();
      $('.itg-row-selector-fieldset-selected-rows').val(values);
    });

    $('.itg-row-selector-select', form).click(function() {
      var values = $('input[id^="edit-itg-row-selector"]:checked').map(function () {
        return this.value;
      }).get();
      $('.itg-row-selector-fieldset-selected-rows').val(values);
    });
  }

  Drupal.itgRowSelector.initGenericBehaviors = function(form) {
    // Show the "select all" fieldset.
    $('.itg-row-selector-select-all-markup', form).show();

    $('.itg-row-selector-select-this-page', form).click(function() {
      $('input[id^="edit-itg-row-selector"]', form).attr('checked', this.checked);

      // Toggle the "select all" checkbox in grouped tables (if any).
      $('.itg-row-selector-table-select-all', form).attr('checked', this.checked);

      var values = $('input[id^="edit-itg-row-selector"]:checked').map(function () {
        return this.value;
      }).get();
      $('.itg-row-selector-fieldset-selected-rows').val(values);
    });

    $('.itg-row-selector-select', form).click(function() {
      // If a checkbox was deselected, uncheck any "select all" checkboxes.
      if (!this.checked) {
        $('.itg-row-selector-select-this-page', form).attr('checked', false);

        var table = $(this).closest('table')[0];
        if (table) {
          // Uncheck the "select all" checkbox in the table header.
          $('.itg-row-selector-table-select-all', table).attr('checked', false);
        }
      }

      var values = $('input[id^="edit-itg-row-selector"]:checked').map(function () {
        return this.value;
      }).get();
      $('.itg-row-selector-fieldset-selected-rows').val(values);
    });
  }

})(jQuery);