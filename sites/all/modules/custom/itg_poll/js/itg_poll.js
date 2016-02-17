/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

jQuery(document).ready(function($){ 
      
       var optionVal;
       $('#field-poll-answer-values').hide();
       $('.field-add-more-submit').hide();
       $('.field-name-field-poll-answer').hide();
       // code for all question field hide default on poll form
       $('#field-poll-question-text-add-more-wrapper').hide();
       $('.field-name-field-poll-question-image').hide();
       $('.field-name-field-poll-question-video').hide();
       // code for all answer field hide default on poll form 
       $('.form-item-field-poll-answer-und-0-field-poll-answer-text-und-0-value').hide();
       $('.form-item-field-poll-answer-und-0-field-poll-answer-image-und-0').hide();
       $('.field-name-field-poll-answer-video').hide();
       
    $("#edit-field-poll-question-und").change(function () {
       // code for get select option value on poll form
       optionVal = this.value; 
       // code for insert hidden field type on poll form
       $("<input type='hidden' name='custom_ques' id='custom_ques' value=''>").insertAfter(".form-item-field-poll-question-und");  
       $('#custom_ques').val(optionVal);       
       customPollDisplay(optionVal);
    });
    
    $('#edit-field-poll-answer-option-und').change(function(){
        // code for get select option value on poll form
        optionVal = this.value;
        
        customPollAnswerDisplay(optionVal);
    });
    
    // code for get selected value from question option
    var optionQuestionVal = $( "#edit-field-poll-question-und option:selected" ).val();
    
    if(optionQuestionVal != '' && optionQuestionVal != '_none'){
        // code for insert hidden field type on poll form
       $("<input type='hidden' name='custom_ques' id='custom_ques' value=''>").insertAfter(".form-item-field-poll-question-und");  
       $('#custom_ques').val(optionQuestionVal);       
        customPollDisplay(optionQuestionVal);
       //code for get selected value from answer option    
        var optionAnswerVal = $( "#edit-field-poll-answer-option-und option:selected" ).val();
        customPollAnswerDisplay(optionAnswerVal);
    }
    
   
});
   
/**
 * custom function for display question fields by select option on poll.
 * @param type optionVal
 */
	
   function customPollDisplay(optionVal){
        jQuery('#field-poll-answer-values').show();
        jQuery('.field-add-more-submit').show();
        if(optionVal === '1'){ // code for Text
           // code for question
           jQuery('#field-poll-question-text-add-more-wrapper').show();
           jQuery('.field-name-field-poll-question-image').hide();
           jQuery('.field-name-field-poll-question-video').hide();
           
       } else  if(optionVal === '2'){ // code for Image
           // code for question
           jQuery('#field-poll-question-text-add-more-wrapper').hide();
           jQuery('.field-name-field-poll-question-image').show();
           jQuery('.field-name-field-poll-question-video').hide(); 
           
       } else  if(optionVal === '3'){ // code for video
           // code for question
           jQuery('#field-poll-question-text-add-more-wrapper').hide();
           jQuery('.field-name-field-poll-question-image').hide();
           jQuery('.field-name-field-poll-question-video').show();
       } 
       
   }


/**
 * custom function for display answer fields by select option on poll.
 * @param type optionVal
 */

   function customPollAnswerDisplay(optionVal){
        jQuery('#field-poll-answer-values').show();
        jQuery('.field-add-more-submit').show();
        
        jQuery('.field-name-field-poll-answer').show();
           if(optionVal === '1'){ // code for Text
           // code for show image
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-image-und-0').hide();
           // code for hide text
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-text-und-0-value').show();
           jQuery('.field-name-field-poll-answer-video').hide();
 
           
       } else  if(optionVal === '2'){ // code for Image
           // code for show image
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-image-und-0').show();
           // code for hide text
           jQuery('.form-item-field-poll-answer-und-0-field-poll-answer-text-und-0-value').hide();
           jQuery('.field-name-field-poll-answer-video').hide();
           
       } 
       
       
   }


          
/**
 * custom function for display multipal answer fields by select option on poll.
 * @param type optionVal
 * @param type i
 */

    function pollDisplay(optionVal, i){
      if(optionVal === '1'){ // code for Text
           // code for show text
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-text-und-0-value').show();
            // code for hide image and video
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-image-und-0').hide();
           jQuery('.field-name-field-poll-answer-video').hide();
       } else  if(optionVal === '2'){ // code for Image
           // code for show image
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-image-und-0').show();
            
           // code for hide text
           jQuery('.form-item-field-poll-answer-und-'+i+'-field-poll-answer-text-und-0-value').hide();
           jQuery('.field-name-field-poll-answer-video').hide();  
        }  
       
    }


/**
 * Ajax callback function for display multipal fields after add more fields on poll.
 */
    
(function($) {
    $(document).ajaxComplete(function(e, xhr)
    {
        var field = jQuery('.field-name-field-poll-answer-text');
        var items = field.find('.form-item');
        var i=0;
        var custom_ques = $('#custom_ques').val();
        if(custom_ques != 'undefined') {
            for(i=0; i< items.length; i++){
                pollDisplay(custom_ques, i);
            } 
        }
        
    
    });
}(jQuery));
