var rootdomain="http://"+window.location.hostname
function validate1()
{
	if((document.searchform1.sea1[0].checked==false) && (document.searchform1.sea1[1].checked==false))
	{
		alert("Please select one search option")
		return false;
	}
	if(document.searchform1.searchword.value.length < 3) 
	{
		alert("Please Enter Atleast 3 characters");
		document.searchform1.searchword.focus();
		return false;
	}
	else
	{
		if(document.searchform1.sea1[1].checked==true)
		{
		window.open("http://www.google.com/search?hl=en&q="+document.searchform1.searchword.value+"&btnG=Search")			//document.searchform1.action="http://www.google.com/search?hl=en&q="+document.searchform1.searchword.value+"&btnG=Search";
		return false;
		}
		return true;
	}
}

function openWin3(url)
{
	w = screen.availWidth;
	h = screen.availHeight;
	var popW = 383;  
	var popH = 365;  
	var leftPos = (w/2-popW/2), topPos = (h/2-popH/2);
	window.open(url,"popup",'toolbar=no,scrollbars=no,width=383,height=365,left=0,top=' + topPos + ',left=' + leftPos);
}

function top_change(tabid) {
	for (p=1;p<=5;p++)	{
		var tabcontent='mainStory'+p;
		var tabli = 'take5'+p;
		if(p==tabid) {
			document.getElementById(tabcontent).style.display="block";
			document.getElementById(tabli).className="bg";
		} else {
			document.getElementById(tabcontent).style.display="none";
			document.getElementById(tabli).className="bg1";
		}
	}
}

function submitbutton1() {
	var form 		= document.pollxtd;			
	var radio		= form.voteid;
	var radioLength = radio.length;
	var check 		= 0;
	if ( 'z' != 'z' ) {
		alert('You already voted for this poll today!');
		return false;
	}
	for(var i = 0; i < radioLength; i++) {
		if(radio[i].checked) {
			form.submit();
			check = 1;					
		}
	}		
	if (check == 0) {
		alert('No selection has been made. Please try again.');
		return false;
	}
}