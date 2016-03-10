/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    Drupal.behaviors.itg_photogallery_form = {
       attach: function(context, settings) {
           
           var getOptionAnswerValnew = $( "#edit-field-poll-answer-option-und option:selected" ).val();
            if(getOptionAnswerValnew == 1){
                $('.field-name-field-poll-answer-image').hide();
                $('.field-name-field-poll-answer-text').show();
            } else if(getOptionAnswerValnew == 2){
                $('.field-name-field-poll-answer-image').show();
                $('.field-name-field-poll-answer-text').hide();
            } else if(getOptionAnswerValnew == '_none'){
                $('#edit-field-poll-answer').hide();
            }
                    
           var getOptionAnswerVal;
           $('#edit-field-poll-answer-option-und').on('change', function(){
                getOptionAnswerVal = $( "#edit-field-poll-answer-option-und" ).val();
            if(getOptionAnswerVal == 1){
                $('#edit-field-poll-answer').show();
                $('.field-name-field-poll-answer-image').hide();
                $('.field-name-field-poll-answer-text').show();
            } else if(getOptionAnswerVal == 2){
                $('#edit-field-poll-answer').show();
                $('.field-name-field-poll-answer-image').show();
                $('.field-name-field-poll-answer-text').hide();
            }else if(getOptionAnswerVal == '_none'){
                $('#edit-field-poll-answer').hide();
            }
            });
           
           
           $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
           $('.form-item-field-gallery-image-add-more-number').hide();
            var uid = settings.itg_photogallery.settings.uid;
                        // code to hide body text format filter 
                        if (uid != 1) {
                        $('#edit-field-gallery-kicer-und-0-format').hide();
                        $('#edit-field-photogallery-description-und-0-format').hide();
                        $('.vertical-tabs-list').hide();
                        $('#edit-metatags').show();
                        $('#edit-metatags-und-advanced').hide();

                        }
        }
    }
})(jQuery);