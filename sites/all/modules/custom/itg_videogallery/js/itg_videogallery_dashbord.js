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
});