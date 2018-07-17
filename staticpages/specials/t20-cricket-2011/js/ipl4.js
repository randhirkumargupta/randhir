function toggle3(id1,id2,id3) {
         var elem = document.getElementById(id1);
         var elem1 = document.getElementById("key_player");
         var elem2 = document.getElementById("team_player");
         elem1.style.display="none";
         elem2.style.display="none";
         document.getElementById("need1").className ='tab_nothighlighted';
         document.getElementById("need2").className ="tab_nothighlighted";
         document.getElementById("d").className ='tabtext_nothighlight';
         document.getElementById("e").className ="tabtext_nothighlight";
         elem.style.display="block";
         document.getElementById(id2).className= "tab_highlighted";
         document.getElementById(id3).className= "tabtext_highlight";
        } 
		
function toggle2(id1,id2,id3) {
         var elem = document.getElementById(id1);
         var elem1 = document.getElementById("features");
         var elem2 = document.getElementById("interviews");
         elem1.style.display="none";
         elem2.style.display="none";
         document.getElementById("need3").className ='tabs_nothighlighted';
         document.getElementById("need4").className ="tabs_nothighlighted";
         document.getElementById("f").className ='tabtext_nothighlight';
         document.getElementById("i").className ="tabtext_nothighlight";
         elem.style.display="block";
         document.getElementById(id2).className= "tabs_highlighted";
         document.getElementById(id3).className= "tabtext_highlight";
        } 	
			
function toggle1(theDiv4,theDiv5) {
     var elem = document.getElementById(theDiv4);
	   		var elem4 = document.getElementById("wcmaillead1");
		 	var elem5 = document.getElementById("wcmaillead2");
	     	var elem6= document.getElementById("wcmaillead3");
		 elem4.style.display="none";
		 elem5.style.display="none";
		 elem6.style.display="none";
		 document.getElementById("lead1").className ='lead_nothighlighted';
		 document.getElementById("lead2").className ="lead_nothighlighted";
		 document.getElementById("lead3").className ="lead_nothighlighted";
		elem.style.display="block";
		document.getElementById(theDiv5).className= "lead_highlighted";
	}

// JavaScript Document
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



 function onSubmitPoll2()
{
	var form = document.poll2;			
	var radio		= form.player;
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
		alert('No selection has been made. Please try again..');
		return false;
	}
	else
	{
			
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit.jsp?sid="+document.poll2.sid.value+"&answer="+answer+"&pid="+document.poll2.pid.value+"";
		var popupHeight = 265;
		var popupWidth = 435;
		var popupTop =  (window.screen.availHeight - popupHeight)/2;
		var popupLeft = (window.screen.availWidth - popupWidth)/2;
		
		var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
		
		return true;
	}
}