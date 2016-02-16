/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

jQuery(document).ready(function($){ 
      
       var optionVal;
       $('#field-poll-answer-values').hide();
       $('.field-add-more-submit').hide();
       $('.field-name-field-poll-answer').hide();
       // hide default all question fields
       $('#field-poll-question-text-add-more-wrapper').hide();
       $('.field-name-field-poll-question-image').hide();
       $('.field-name-field-poll-question-video').hide();
       // hide default all answer fields
       $('.form-item-field-poll-answer-und-0-field-poll-answer-text-und-0-value').hide();
       $('.form-item-field-poll-answer-und-0-field-poll-answer-image-und-0').hide();
       $('.field-name-field-poll-answer-video').hide();
       
    $("#edit-field-poll-question-und").change(function () {
       // get select option value
       optionVal = this.value; 
        // insert hidden field
       $("<input type='hidden' name='custom_ques' id='custom_ques' value=''>").insertAfter(".form-item-field-poll-question-und");  
       $('#custom_ques').val(optionVal);       
       customPollDisplay(optionVal);
    });
    
    $('#edit-field-poll-answer-option-und').change(function(){
        // get select option value
        optionVal = this.value;
        
        customPollAnswerDisplay(optionVal);
    });
    
    // get selected value from question option
    var optionQuestionVal = $( "#edit-field-poll-question-und option:selected" ).val();
    //alert('test '+optionQuestionVal);
    if(optionQuestionVal != '' && optionQuestionVal != '_none'){
        // insert hidden field
       $("<input type='hidden' name='custom_ques' id='custom_ques' value=''>").insertAfter(".form-item-field-poll-question-und");  
       $('#custom_ques').val(optionQuestionVal);       
        customPollDisplay(optionQuestionVal);
    // get selected value from answer option    
        var optionAnswerVal = $( "#edit-field-poll-answer-option-und option:selected" ).val();
        customPollAnswerDisplay(optionAnswerVal);
    }
    
   
});

   function customPollDisplay(optionVal){
        //alert('hi');
        jQuery('#field-poll-answer-values').show();
        jQuery('.field-add-more-submit').show();
        //jQuery('.field-name-field-poll-answer').show();
        if(optionVal === '1'){ // for Text
           // for question
           jQuery('#field-poll-question-text-add-more-wrapper').show();
           jQuery('.field-name-field-poll-question-image').hide();
           jQuery('.field-name-field-poll-question-video').hide();
           
       } else  if(optionVal === '2'){ // for Image
           // for question
           jQuery('#field-poll-question-text-add-more-wrapper').hide();
           jQuery('.field-name-field-poll-question-image').show();
           jQuery('.field-name-field-poll-question-video').hide(); 
           
       } else  if(optionVal === '3'){ // for video
           // for question
           jQuery('#field-poll-question-text-add-more-wrapper').hide();
           jQuery('.field-name-field-poll-question-image').hide();
           jQuery('.field-name-field-poll-question-video').show();
       } 
       
   }


// for answer
   function customPollAnswerDisplay(optionVal){
        jQuery('#field-poll-answer-values').show();
        jQuery('.field-add-more-submit').show();
        
        jQuery('.field-name-field-poll-answer').show();
           if(optionVal === '1'){ // for Text
           // show image
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-image-und-0').hide();
           // hide text
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-text-und-0-value').show();
           jQuery('.field-name-field-poll-answer-video').hide();
 
           
       } else  if(optionVal === '2'){ // for Image
           // show image
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-image-und-0').show();
           // hide text
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-text-und-0-value').hide();
           jQuery('.field-name-field-poll-answer-video').hide();
           
       } 
       
       
   }


          

    function pollDisplay(optionVal, i){
      if(optionVal === '1'){ // for Text
           // show text
           //alert('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-text-und-0-value');
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-text-und-0-value').show();
           //alert('dfgdf');
            // hide image and video
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-image-und-0').hide();
           jQuery('.field-name-field-poll-answer-video').hide();
       } else  if(optionVal === '2'){ // for Image
           // show image
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-image-und-0').show();
            
           // hide text
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-text-und-0-value').hide();
           jQuery('.field-name-field-poll-answer-video').hide();  
        }  
       
    }
    
(function($) {
    $(document).ajaxComplete(function(e, xhr)
    {
        var field = jQuery('.field-name-field-poll-answer-text');
        var items = field.find('.form-item');
        var i=0;
        var custom_ques = $('#custom_ques').val();
        //alert('custom_ques '+custom_ques);
        if(custom_ques != 'undefined') {
            for(i=0; i< items.length; i++){
                pollDisplay(custom_ques, i);
            } 
        }
        
    
    });
}(jQuery));