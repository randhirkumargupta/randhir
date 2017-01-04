/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */
Drupal.behaviors.itg_widgets = {
  attach: function (context, settings) {
    jQuery ("input[type='radio'][name='live_tv_switch_2']").click (function () {
         jQuery("#widget-ajex-loader").show();
      var selectedVal = "";
      var selected = jQuery ("input[type='radio'][name='live_tv_switch_2']:checked");
      if (selected.length > 0) {
        selectedVal = selected.val ();
      }
      if (selectedVal === 'yes' || selectedVal === 'no') {
        jQuery.get ("big-story-live-tv-flag/" + selectedVal, function (data) {
           
            if(data) {
                jQuery("#widget-ajex-loader").hide();
            }
//          if(data == 'deleted') {
//            alert("Live tv has been deleted");
//          }
//          else if (data == 'notfound') {
//            alert("Live tv is not activated yet, So can't delete.");
//          }
//          else if (data == 'already_live_tv') {
//            alert("Live tv already activated.");
//          }
//          else if (data == 'success') {
//            alert("Live tv has been actived successfully.");
//          }
//          else if (data == 'error') {
//            console.log("Error found.");
//          }
          
        });
      }
    });
  }
};
