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
anslastid = res[2].substr(res[2].length - 1);
$('input[name='+$(this).attr('name')+']').attr('disabled', 'disabled');
$(this).parent().parent().parent().parent().find('.answer-container-actual').html('');

         var qnid = $("input[name='nid']").val();
            if ($(this).is(':checked')) {
                var ans_val= $(this).val();
                jQuery.ajax({      
                    method:"post",
                    data: {nid:qnid, ans_val:ans_val},
                    url: Drupal.settings.basePath+"quiz-response",
                    success: function(data) {
                      console.log(data);
                        ansvalue = data.split('-');
                      
                      $('#answer-container-'+anslastid+' .answer-container-actual').html(ansvalue[0]+'<br/>'+ansvalue[1]);

                    }
               });        
            }    
      
  });
    $('body').on('click', '#show_answer', function() {
        
	   $(this).closest('.answer-container').find('.form-checkbox').attr('disabled', true);
      var qnid = $("input[name='nid']").val();
      var selected = [];
	$('.form-checkboxes input:checked').each(function() {
	    selected.push($(this).val());
	});
      var not_selected = [];
	$('.form-checkboxes input:checkbox:not(:checked)').each(function() {
	    not_selected.push($(this).val());
	});
     
      jQuery.ajax({      
                    method:"post",
                    //data: "{'nid':'" + qnid+ "', 'value':'" + val+ "'}",
                    data: {nid:qnid, ans_val:JSON.stringify(selected), not_select:JSON.stringify(not_selected)},
                    url: Drupal.settings.basePath+"quiz-response-checkbox",
                    success: function(data) {
                      
                      $('.answer-container-actual').html(data);

                    }
               });
      return false;
    });
      
    }
  };
})(jQuery, Drupal, this, this.document);