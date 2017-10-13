$(document).ready(function() {
	var photolen1  = $('#electionphoto .photo-slider .photobelt .photo-list').length;
	var photolistwidth1 = $('#electionphoto .photo-slider .photobelt .photo-list').width();
	var photowidth1 = photolen1*(photolistwidth1+5);
	//alert(photowidth);
	$('#electionphoto .photo-slider .photobelt').css('width', photowidth1);
	var photocounters = 1;
	$('#photoprev-elec16').css('display', 'none');
	$('#photonext-elec16').click(function(){

		if(photocounters < photolen1)
		{
				$('#electionphoto .photo-slider .photobelt').animate({
					left : '-=310'
				});
				photocounters +=1;
				
				$('#photoprev-elec16').css('display', 'block');
		}
		else{
			$('#photonext-elec16').css('display', 'none');
			
		}
	});	
	
	$('#photoprev-elec16').click(function(){
		if(photocounters == 1)
		{
				$('#photoprev-elec16').css('display', 'none');
				$('#photonext-elec16').css('display', 'block');
		}
		else{
			$('#electionphoto .photo-slider .photobelt').animate({
					left : '+=310'
				});
			photocounters -= 1;
			$('#photonext-elec16').css('display', 'block');
			
		}
	});
	});