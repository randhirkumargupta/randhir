/*
 * @file itg_quiz_front.js
 */

(function($) {
  Drupal.behaviors.itg_quiz_front = {
    attach: function() {

      // Hide title form take quiz page
      var quizStr = $(location).attr('href');
      if (quizStr.indexOf("itg-quiz") > 0) {
        $("#page-title").hide();
      }

      // Scroll at top to show result in case of all question at a time
      if ($("input[name=question_format]").val() == 'All questions at a time') {
        $('#itg-quiz-quiz-form .quiz-submit').mousedown(function() {
          $(this).ajaxSuccess(function() {
            $('html, body').animate({
              scrollTop: $(".survey-form-main-container").offset().top
            }, 1000);
          });
        });
      }
      
 //  js for quiz(lallan top)     
        $('.question-container .form-radio').on('click', function() {
        ansid = $(this).attr('id'); 
        
        res = ansid.split("-");
        
        var ans_no = res[2].split("option");
        var correct_ans = $("input[name='correct_answer"+ans_no[1]+"']").val();
        
        anslastid = res[2].substr(res[2].length - 1);
        $('input[name='+$(this).attr('name')+']').attr('readonly', 'true');
        $(this).parent().parent().parent().parent().find('.answer-container-actual').html('');

         var qnid = $("input[name='nid']").val();
            if ($(this).is(':checked')) {
                var ans_val= $(this).val();
                jQuery.ajax({      
                    method:"post",
                    data: {nid:qnid, ans_val:ans_val, correct_ans:correct_ans},
                    url: Drupal.settings.basePath+"quiz-response",
                    success: function(data) {                  
                        ansvalue = data.split('-');    
                        var cls = "";
                        if(ansvalue[1] == "correct"){
                          cls = "correct-ans";
                        }
                        else{
                          cls  = "incorrect-ans";
                        }
                        $('#answer-container-'+anslastid+' .answer-container-actual').html("<div class='" + cls + "'>" + ansvalue[1] + " !</div><strong>" + ansvalue[0] + "</strong>");
                    }
               });        
            }    
      
  });
 
 //multi answer
   $('body').on('click', '#show_answer', function() {
      buttonClass = $(this).attr('class');
      $(this).closest('.answer-container').find('.form-checkbox').attr('readonly', true);
      var qnid = $("input[name='nid']").val();
      var ans_class = $(this).attr('class');      
      var correct_ans = $("input[name='correct_"+ans_class+"']").val();
      
      var container_no = $(this).attr('data-type');
      var selected = [];
      $('.answer_block_'+container_no+' input:checked').each(function() {
        selected.push($(this).val());            
      });      
     
      jQuery.ajax({      
                    method:"post",                    
                    data: {nid:qnid, correct_ans:correct_ans, ans_val:JSON.stringify(selected)},
                    url: Drupal.settings.basePath+"quiz-response-checkbox",
                    success: function(data) {
                        ansvalue = data.split('-'); 
                        var cls = "";
                        if(ansvalue[1] == "correct"){
                          cls = "correct-ans";
                        }
                        else{
                          cls  = "incorrect-ans";
                        }
                        $('.'+buttonClass).siblings('.answer-container-actual').html("<div class='" + cls + "'>" + ansvalue[1] + "</div><strong>" + ansvalue[0] + "</strong>");
                    }
               });
      return false;
    });
    
//    chnage position of show answer button
      var prthis;
      jQuery('.question-container').each(function () {
        prthis = jQuery(this).find('.answer-container');        
        jQuery(this).find('#show_answer, .answer-container-actual').appendTo(prthis);
      });
  
      $('.question-container').on('click', '#show_answer', function(){
        $(this).closest('.answer-container').find('span.right-answer').addClass('rightbg');
        $(this).closest('.answer-container').find('span.wrong-answer').addClass('wrongbg');
      });

    }
  };
})(jQuery, Drupal, this, this.document);