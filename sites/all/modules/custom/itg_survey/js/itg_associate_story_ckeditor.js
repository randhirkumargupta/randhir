/*
 * @file itg_survey.js
 */

(function($) {
  Drupal.behaviors.itg_survey = {
    attach: function(context, settings) {
      
    $('#submit-ass').on('click',function(){
        var appendtext="";
       $('.form-checkbox').each(function(){
           if($(this).is(':checked'))
           {
               appendtext=appendtext+$(this).val()+',';
           }
           
       })
       window.opener.document.getElementById("edit-body-und-0-value").value=appendtext;
    })
      
    }
  };
})(jQuery, Drupal, this, this.document);