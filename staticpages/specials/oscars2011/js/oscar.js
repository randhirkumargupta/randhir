	images_gallery=new Array();
	currentIndx=0;
	totalindex = 2;
		images_gallery[0]='vid4.html';
		images_gallery[1]='vid5.html';
		
	imagesPreloaded = new Array(totalindex)
	for (var i = 0; i < images_gallery.length ; i++) 
	{
				imagesPreloaded[i].src=images_gallery[i]
	}



	function Next1(id)
	{
		//alert(imagesPreloaded[0]);
		if (currentIndx<imagesPreloaded.length-1){
			currentIndx=currentIndx+1;
			document.getElementById(id).src = images_gallery[currentIndx];
		}
		else {
			currentIndx=0
			document.getElementById(id).src=images_gallery[currentIndx];
		}
	}
	function Back1(id){
		if (currentIndx>0){
			currentIndx=currentIndx-1;
			document.getElementById(id).src=images_gallery[currentIndx];
		}
		else {
			currentIndx=totalindex-1
			
			document.getElementById(id).src=images_gallery[currentIndx];
		}

		}
		function current(x)
		{
			
			document.getElementById(id).src=images_gallery[x];
			}
	function automaticly() {
		if (document.form1.automatic.checked) {
			if (currentIndx<imagesPreloaded.length){
				currentIndx=currentIndx
			}
		else {
			currentIndx=0
		}	
		document.theImage.src=imagesPreloaded[currentIndx].src
		document.form1.text1.innerHTML=titles_gallery[currentIndx];
		currentIndx=currentIndx+1;
		var delay = setTimeout("automaticly()",3500)
	}
}


function onSubmitPoll()
{
	var form = document.poll;			
	var radio		= form.answer;
	var radioLength = radio.length;
	var check 		= 0;
	var answer = 0;
	var radioIndex = 0;

	for(var i = 0; i < radioLength; i++)
	{
		if(radio[i].checked)
		{
				answer=radio[i].value;
				check = 1;	
				radioIndex = i;
		}
	}		
	if (check == 0)
	{
		alert('No selection has been made. Please try again.');
		return false;
	}
	else
	{
			
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit.jsp?sid="+document.poll.sid.value+"&answer="+answer+"&pid="+document.poll.pid.value+"";
		var popupHeight = 265;
		var popupWidth = 435;
		var popupTop =  (window.screen.availHeight - popupHeight)/2;
		var popupLeft = (window.screen.availWidth - popupWidth)/2;
		
		var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
		
		return true;
	}
}

function onShow()
{
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult.jsp?pid=192&sid=227";
	var popupHeight = 265;
	var popupWidth = 455;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}
