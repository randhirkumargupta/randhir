<script>
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
	
	//alert('answer--'+answer);
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit_latest_21may.jsp?sid="+document.poll.sid.value+"&answer="+answer+"&pid="+document.poll.pid.value+"";
		var popupHeight = 350;
		var popupWidth = 460;
		var popupTop =  (window.screen.availHeight - popupHeight)/2;
		var popupLeft = (window.screen.availWidth - popupWidth)/2;
		var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes', '_blank');
		//return true;
	}
}

function onShow(siteId,pollId)
{
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult_new_21may.jsp?pid="+pollId+"&sid="+siteId;
	var popupHeight = 350;
	var popupWidth = 460;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes', '_blank');
	return true;
}

</script>
<div class="olympiccont">
<p class="header">GAMES POLL</p>
<div class="commoninn">
<form method="POST" onsubmit="return onSubmitPoll();" name="poll">
<input value="243" name="sid" type="HIDDEN">
      <input value="217" name="pid" type="HIDDEN">
 <div class="poll_question">How many medals will India win at the Olympics?
</div>
     <div class="poll_option">
      <span><input value="2000" class="radio_new" name="answer" type="radio"></span>
      <span class="introtext_poll">0</span>
      <span><input value="2001" class="radio_new" name="answer" type="radio">
      </span>
      <span class="introtext_poll">1-4</span>  
       <span><input value="2002" class="radio_new" name="answer" type="radio">
       </span>
      <span class="introtext_poll">5-9</span>
      <span>
      <input value="2003" class="radio_new" name="answer" type="radio">
      </span>
      <span class="introtext_poll">10 or more</span>        
       <span>
       </span>
</div>
<div class="button">
  <div class="subbutton"><input align="absmiddle" type="image" border="0" name="submit" src="/staticpages/main/images/submit.jpg" value="submit" id="button3">
</div>
<div class="seemoretext"><span><a href="#" onclick="return onShow('243','217'); return false;">See Results &raquo;</a></span></div>
<div class="clear"></div>
</div>
</form>
</div>
</div>
