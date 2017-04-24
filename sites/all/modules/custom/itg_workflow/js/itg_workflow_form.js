/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function ($) {
  Drupal.behaviors.itg_workflow_form = {
    attach: function (context, settings) {     

      var form_id = settings.itg_workflow.settings.form_id;
      
      if (form_id == 'views-exposed-form-strory-menegment-page') {
        // Code for Bulk opration related work for story
        jQuery("#edit-actionviews-bulk-operations-modify-action").val("Archive");
        var myInputBoxID = "edit-bundle-story-appendfield-story-archive";
        jQuery("label[for=" + myInputBoxID + "]").hide();
        jQuery("#edit-bundle-story-appendfield-story-archive").hide();
        jQuery("#edit-tokens").hide();
        jQuery("#edit-actions-submit").val("Archive");
        jQuery("#edit-bundle-story-field-story-archive-und-yes").attr("checked", true);
        jQuery("#edit-bundle-story-field-story-archive-und").hide();
    }
    
    if (form_id == 'views-exposed-form-photo-gallery-management-page') {
        // Code for Bulk opration related work for Gallery        
        jQuery("#edit-actionviews-bulk-operations-modify-action").val("Archive");
        var myInputBoxID = "edit-bundle-photogallery-appendfield-story-archive";
        jQuery("label[for=" + myInputBoxID + "]").hide();
        jQuery("#edit-bundle-photogallery-appendfield-story-archive").hide();
        jQuery("#edit-tokens").hide();
        jQuery("#edit-actions-submit").val("Archive");
        jQuery("#edit-bundle-photogallery-field-story-archive-und-yes").attr("checked", true);
        jQuery("#edit-bundle-photogallery-field-story-archive-und").hide(); 
    }
    
    if (form_id == 'views-exposed-form-blogs-management-page') {        
        // Code for Bulk opration related work for Blog
        jQuery("#edit-actionviews-bulk-operations-modify-action").val("Archive");
        var myInputBoxID = "edit-bundle-blog-appendfield-story-archive";
        jQuery("label[for=" + myInputBoxID + "]").hide();
        jQuery("#edit-bundle-blog-appendfield-story-archive").hide();
        jQuery("#edit-tokens").hide();
        jQuery("#edit-actions-submit").val("Archive");
        jQuery("#edit-bundle-blog-field-story-archive-und-yes").attr("checked", true);
        jQuery("#edit-bundle-blog-field-story-archive-und").hide();
    }
    
    if (form_id == 'views-exposed-form-podcast-management-page') {        
        // Code for Bulk opration related work for podcast
        jQuery("#edit-actionviews-bulk-operations-modify-action").val("Archive");
        var myInputBoxID = "edit-bundle-podcast-appendfield-story-archive";
        jQuery("label[for=" + myInputBoxID + "]").hide();
        jQuery("#edit-bundle-podcast-appendfield-story-archive").hide();
        jQuery("#edit-tokens").hide();
        jQuery("#edit-actions-submit").val("Archive");
        jQuery("#edit-bundle-podcast-field-story-archive-und-yes").attr("checked", true);
        jQuery("#edit-bundle-podcast-field-story-archive-und").hide();
    }
    
    if (form_id == 'views-exposed-form-videogallery-management-page') {        
        // Code for Bulk opration related work for videogallery
        jQuery("#edit-actionviews-bulk-operations-modify-action").val("Archive");
        var myInputBoxID = "edit-bundle-videogallery-appendfield-story-archive";
        jQuery("label[for=" + myInputBoxID + "]").hide();
        jQuery("#edit-bundle-videogallery-appendfield-story-archive").hide();
        jQuery("#edit-tokens").hide();
        jQuery("#edit-actions-submit").val("Archive");
        jQuery("#edit-bundle-videogallery-field-story-archive-und-yes").attr("checked", true);
        jQuery("#edit-bundle-videogallery-field-story-archive-und").hide();
    }
    
    if (form_id == 'views-exposed-form-strory-menegment-page-5') {
        jQuery("#edit-field-story-schedule-date-time-value-value-wrapper").hide();
    }
    
    if (form_id == 'views-exposed-form-strory-menegment-page-1' || form_id == 'views-exposed-form-strory-menegment-page-12') {
        jQuery("#edit-field-story-schedule-date-time-value-value-wrapper").hide();
            jQuery("#edit-field-story-schedule-date-time-value-op").click(function() {                     
              jQuery("#edit-field-story-schedule-date-time-value-value-wrapper").hide();                     
            });
    }
      
  }

 };
})(jQuery, Drupal, this, this.document);