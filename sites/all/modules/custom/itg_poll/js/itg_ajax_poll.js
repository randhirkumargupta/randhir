/*
 * @file itg_ajax_poll.js
 * Contains all functionality related to poll
 */

(function ($) { 

  Drupal.behaviors.itg_ajax_poll = { 
    attach: function(context, settings) {
    		//alert("hello");		
	        //function validateData()
		$('#subsPollFormghgh ').on('submit', function(e)
		{	
		//alert("hi ");		
		var flag = "";		
		if ($("#pole-radio-answer:checked").length == 0)
		{	alert("Enter select any one answer");
			flag = "error";
			return false;
		}
		
		if (flag != "") {
			return false;
		} else {	
			
				var subsForm = $("#subsPollForm");
				var sendData= subsForm.serialize();
				var src = Drupal.settings.basePath + '?q=poll-details-ajax';
				//var src = Drupal.settings.basePath + 'poll-details-ajax';
				
				$.ajax({
					type: 'POST',
					url: src,
					data: sendData,
					success: function (response) {
					    //alert("Data from Server"+(response));
			                      //  console.log(Drupal.settings);		
	        				//debugger;
					
						var htmlData = response;
						$('.poll-main').empty();
						$('.poll-main').html(htmlData);
						//alert('Great!');
						location.reload();	
					},
					error: function(jqXHR, textStatus, errorThrown) {
					  console.log('Fail');
					  alert('Fail');
					  return false;
					}
				});
			
			}
	
			return false;	
		}); // close function
		
    }
  }
})(jQuery);
