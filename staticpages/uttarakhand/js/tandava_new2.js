$(document).ready( function() {
        $('#popupBoxClose2').click( function() {			
                 unloadPopupBox();
         });
        $('#container2 h1').click( function() {
                 loadPopupBox();
         });
function unloadPopupBox() {	
         $('#popup_box2').fadeOut("slow");
         $("#container2 h1").css({ 
                 "opacity": "1"  
         }); 
         }	
                                        
function loadPopupBox() {	
         $('#popup_box2').fadeIn("slow");
         $("#container h1").css({ 
         "opacity": "0.3"  
         }); 		
         }
		 
         });
		 
$(document).ready( function() {
		$('#popupBoxClose1').click( function() {			
			unloadPopupBox1();
		});
		
		$('#container1 h1').click( function() {
			loadPopupBox1();
		});

		function unloadPopupBox1() {	
			$('#popup_box1').fadeOut("slow");
			$("#container1 h1").css({ 
				"opacity": "1"  
			}); 
		}	
		
		function loadPopupBox1() {	
			$('#popup_box1').fadeIn("slow");
			$("#container1 h1").css({ 
				"opacity": "0.3"  
			}); 		
		}
		
	});
	
var r = 0;
var i = 0;
var n = 0;
var q = 0;
	
function showDiv() {

 if ($(window).scrollTop() > 2500 && i==0 && $(window).scrollTop() <= 3500) 
	{
		 $('#video2').fadeIn('slow');
			i= 1;
    }
	 else if ($(window).scrollTop() > 3500) 
	{
		$('#video2').fadeOut('fast');
	   i= 0;
	 
    }	

   if ($(window).scrollTop() > 7200 && n==0 && $(window).scrollTop() <= 8500) {
		$('#video3').fadeIn('slow');
		n= 1;
	}

    else if ($(window).scrollTop() > 8500) 
	{
		$('#video3').fadeOut('slow');
       n= 0;
	 
    }	

	if ($(window).scrollTop() > 3800 && q==0 && $(window).scrollTop() <= 6000) {
		 $('#video4').fadeIn('slow');
		q= 1;
	}

    else if ($(window).scrollTop() > 6000) 
	{
       $('#video4').fadeOut('slow');
	   q= 0;
	 
    }	
}
$(window).scroll(showDiv);
showDiv();

   