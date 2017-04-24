/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

jQuery (document).ready (function () {
  jQuery ("input[type='radio'][name='live_tv_switch_2']").click (function () {
    jQuery ("#widget-ajex-loader").show ();
    var selectedVal = "";
    var selected = jQuery ("input[type='radio'][name='live_tv_switch_2']:checked");
    if (selected.length > 0) {
      selectedVal = selected.val ();
    }
    if (selectedVal === 'yes' || selectedVal === 'no') {
      jQuery.get ("big-story-live-tv-flag/" + selectedVal, function (data) {

        if (data) {
          jQuery ("#widget-ajex-loader").hide ();
        }
      });
    }
  });
});
