// JavaScript Document

function toggle2(theDiv4,theDiv5) {

     var elem = document.getElementById(theDiv4);
	 
	   		var elem1 = document.getElementById("Layer1");
		 	var elem2 = document.getElementById("Layer2");
	     	var elem3= document.getElementById("Layer3");
			
			
		 elem1.style.display="none";
		 elem2.style.display="none";
		 elem3.style.display="none";
		 
	
		 document.getElementById("lead1").className ='awdheadtabselect';
		 document.getElementById("lead2").className ="awdheadtabselect";
		 document.getElementById("lead3").className ="awdheadtabselect";
		

		elem.style.display="block";
		document.getElementById(theDiv5).className= "awdhedertab";
		
	}




</script>
<script language="javascript">
function breaking()
{
document.getElementById('breaking_news').style.display="none";
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
			
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit_latest.jsp?sid="+document.poll.sid.value+"&answer="+answer+"&pid="+document.poll.pid.value+"";
		var popupHeight = 350;
		var popupWidth = 460;
		var popupTop =  (window.screen.availHeight - popupHeight)/2;
		var popupLeft = (window.screen.availWidth - popupWidth)/2;
		
		var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
		
		//return true;
	}
}

function onShow(siteId,pollId)
{
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult_new.jsp?pid="+pollId+"&sid="+siteId;
	var popupHeight = 350;
	var popupWidth = 460;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}