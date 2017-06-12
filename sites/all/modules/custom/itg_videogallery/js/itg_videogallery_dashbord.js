/**
 * @file itg_widget.ipl.js
 * This is used for widgets setting
 */

jQuery(document).ready(function() {
  jQuery("#edit-from-time-timeEntry-popup-1").attr("placeholder", "Time");
  jQuery("#edit-to-time-timeEntry-popup-1").attr("placeholder", "Time");
  jQuery(".dalymotion-video-delete").on("click", function(e) {
    if (!confirm("Are you sure you want to delete this video ?")) {
      e.preventDefault();
    }
  });
  jQuery('#edit-from-time-datepicker-popup-2' ).datepicker({  maxDate: new Date(),
                    minDate: new Date(1970, 01, 01),
                    changeMonth: true,
                    changeYear: true,
             
 });
  jQuery('#edit-to-time-datepicker-popup-2' ).datepicker({  maxDate: new Date(),
                    minDate: new Date(1970, 01, 01),
                    changeMonth: true,
                    changeYear: true,
             
 });

});