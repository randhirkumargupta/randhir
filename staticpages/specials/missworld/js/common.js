function Open_win(uv,utwidth, utheight) {
var remoteWin = null;
var params;
params = "toolbar=0,location=0,directories=0,status=0,scrollbars=1,scrolling=1,resizable=0,menubar=0,width="+utwidth+",height="+utheight+" ";
remoteWin = window.open("","colorpicker",params);
remoteWin.location.href = uv;     
}

function handleHttpResponse2()
{
if (http2.readyState == 4)
{
var results = http2.responseText
var str = "";
var count = 0;
//alert(results);
//alert(results.substring(0,1));
var total = parseInt(results.substring(0,1));
var total1 = parseInt(results.substring(2,4));
//alert (total1);
for(var i=0; i<total; i++)
{
str = str + "<img src=\"http://media2.intoday.in/indiatoday/images/star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
}
if(total1>00)
{
//alert("inside if");
str = str + "<img src=\"http://media2.intoday.in/indiatoday/images/red-grey-half-star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
total = total+1;
}
//alert(total);
for(var i=total; i<5; i++)
{
str = str + "<img src=\"http://media2.intoday.in/indiatoday/images/grey-full-star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
}
//alert(str);
document.getElementById("score").innerHTML = str;
}
}

function showStar(i,j)
{

var url="http://10.1.114.4:8080/site_special/specials/missworld/rateArtical.jsp?id=" +encodeURI(i)+"&id1="+encodeURI(j);
http2.open("GET", url, true);
http2.onreadystatechange = handleHttpResponse2;
http2.send(null);
if(i>0)
{
alert("Thanks for voting.");
}
}

function getHTTPObject()
{
var xmlhttp;
if(window.XMLHttpRequest)
{
xmlhttp = new XMLHttpRequest();
}
else if (window.ActiveXObject)
{
xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
if (!xmlhttp)
{
xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
}
}
return xmlhttp;
}

var http2 = getHTTPObject();

//-->


function fnValidate()
{

if (ChkBlank("userDetails.FNAME","Please enter Name") == false) 
return false
if (ChkBlank("userDetails.Location","Please enter place") == false) 
return false
if (ChkBlank("userDetails.EMAIL","Please enter your email ID") == false) 
return false
if (ChkEmail("userDetails.EMAIL","Please enter valid email ID") == false) 
return false
if (ChkBlank("userDetails.message","Please enter your comment") == false) 
return false
if (ChkBlank("userDetails.number","Please enter the code") == false) 
return false


}
//This function will check the blank field.
function ChkBlank(frmFieldName,errorMsg)
{
	var tmpString = eval("String(document."+frmFieldName+".value)");
	var i;
	for(i=0;i<tmpString.length;i++)
	{
			if (tmpString.charAt(i) != ' ')
			break;
	}
	if (i == tmpString.length)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	else
		return true;
}
//This function check Email field. Like @,.,etc...........
function ChkEmail(frmFieldName,errorMsg)
{
	var tmpString = eval("String(document."+frmFieldName+".value)");
	if (tmpString.search('@') == -1)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}		
	if (tmpString.indexOf('.') == -1 || tmpString.indexOf('.') == tmpString.length-1)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	if (tmpString.indexOf("@.") != -1)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	if (tmpString.indexOf(".@") != -1)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	if (tmpString.indexOf("<") != -1)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	if (tmpString.indexOf(">") != -1)
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	if (tmpString.charAt(tmpString.length-1) == ".")
	{
		alert(errorMsg);
		eval("String(document."+frmFieldName+".focus())");
		return false;
	}
	
	var firstoccur = tmpString.indexOf("@");
	if (tmpString.indexOf("@",firstoccur+1) != -1)
	{	alert(errorMsg);
		eval("document."+frmFieldName+".focus()");
		return false;
	}
	
	
	return true;
}
        var min=8;
var max=17;
function increaseFontSize() {
   var p = document.getElementsByTagName('p');
   for(i=0;i<p.length;i++) {
      if(p[i].style.fontSize) {
         var s = parseInt(p[i].style.fontSize.replace("px",""));
      } else {
         var s = 12;
      }
      if(s!=max) {
         s += 1;
      }
      p[i].style.fontSize = s+"px"
   }
}
function decreaseFontSize() {
   var p = document.getElementsByTagName('p');
   for(i=0;i<p.length;i++) {
      if(p[i].style.fontSize) {
         var s = parseInt(p[i].style.fontSize.replace("px",""));
      } else {
         var s = 12;
      }
      if(s!=min) {
         s -= 1;
      }
      p[i].style.fontSize = s+"px"
   }   
}	
function resetFontSize() {
   var p = document.getElementsByTagName('p');
   for(i=0;i<p.length;i++) {
     
     p[i].style.fontSize = "12px"
      
   }   
}

var i ;
var images1= new Array();
images1[0] = "url(http://media2.intoday.in/microsites/missworld09/images/schedule-tab.gif)";
images1[1] = "url(http://media2.intoday.in/microsites/missworld09/images/venue-tab.gif)";
function changeImage2(i)
{
document.getElementById('image2').style.backgroundImage = images1[i];
//alert(images1[i]);
}


		 
		
function toggle3(theDiv) {

     var elem = document.getElementById(theDiv);
	   
		 var elem1 = document.getElementById("Layer1");
	     var elem2 = document.getElementById("Layer2");
		 
		 elem1.style.display="none";
	elem2.style.display="none";
	elem.style.display="block";
		 }

function toggle6(id3)
	{
		var ph3 = document.getElementById("venue3");
		var vd3 = document.getElementById("schedule3");
		var main3 = document.getElementById(id3);
		
		ph3.style.color = '#ffffff';
		vd3.style.color = '#ffffff';
		main3.style.color = '#000000';
	}
	var rootdomain="http://"+window.location.hostname

function ajaxinclude(url) {
var page_request = false
if (window.XMLHttpRequest) // if Mozilla, Safari etc
page_request = new XMLHttpRequest()
else if (window.ActiveXObject){ // if IE
try {
page_request = new ActiveXObject("Msxml2.XMLHTTP")
} 
catch (e){
try{
page_request = new ActiveXObject("Microsoft.XMLHTTP")
}
catch (e){}
}
}
else
return false
page_request.open('GET', url, false) //get page synchronously 
page_request.send(null)
writecontent(page_request)
}

function writecontent(page_request){
if (window.location.href.indexOf("http")==-1 || page_request.status==200)
document.write(page_request.responseText)
}

function cemail(val){
		if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(val.value)){
		return (true)
		}
		
		return false;
		}
function ajaxFunction(){
		var frm=document.feedback;
		if(frm.FNAME.value=="")
		{
		  alert("Please enter First Name");
		  frm.FNAME.focus();
		  return false;
		}
		
		if (frm.FNAME.value!="") {
				var alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
						for (var i=0;i<frm.FNAME.value.length;i++){
							temp=frm.FNAME.value.substring(i,i+1);
							if (alp.indexOf(temp)==-1){
								alert("First name should accept only alphabets[a-z,A-Z]");
								frm.FNAME.focus();
								return false;
							}
						}
				
				
		    	}
		if (frm.LNAME.value!="") {
				var alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
						for (var i=0;i<frm.LNAME.value.length;i++){
							temp=frm.LNAME.value.substring(i,i+1);
							if (alp.indexOf(temp)==-1){
								alert("Last name should accept only alphabets[a-z,A-Z]");
								frm.LNAME.focus();
								return false;
							}
						}
				
				
		    	}
		
		if(frm.EMAIL.value=="")
		{
		  alert("Please enter Email Id");
		  frm.EMAIL.focus();
		  return false;
		}
		if(cemail(frm.EMAIL)==false)
			{
				
					alert( "Please enter valid email ID" );
					frm.EMAIL.focus();
					return false;
				
			}
			
			 if((frm.dob_date.value!=-1 && frm.dob_month.value==-1) )
			{
				alert( "Please select Month")
				frm.dob_month.focus();
				return false;
			}
			
			 if(frm.dob_month.value!=-1 && frm.dob_year.value==-1)
			{
				alert( "Please select Year" )
				frm.dob_year.focus();
				return false;
			}
		
		if(frm.Location.value=="")
		{
		  alert("Please enter city");
		  frm.Location.focus();
		  return false;
		}
		if (frm.Location.value!="") {
				var alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
						for (var i=0;i<frm.Location.value.length;i++){
							temp=frm.Location.value.substring(i,i+1);
							if (alp.indexOf(temp)==-1){
								alert("City should accept only alphabets[a-z,A-Z]");
								frm.Location.focus();
								return false;
							}
						}
				
				
		}
		if (frm.country.value!="") {
				var alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
						for (var i=0;i<frm.country.value.length;i++){
							temp=frm.country.value.substring(i,i+1);
							if (alp.indexOf(temp)==-1){
								alert("Country should accept only alphabets[a-z,A-Z]");
								frm.country.focus();
								return false;
							}
						}
				
				
		}
		 if(frm.reg_code.value=="")
			{
				alert( "Please Enter the  Code" );	
				frm.reg_code.focus();
				return false;
			} 
		frm.submit();
}

 function onSubmitPoll2()
{
	var form = document.poll2;			
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
		alert('No selection has been made. Please try again..');
		return false;
	}
	else
	{
			
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit2.jsp?sid="+document.poll2.sid.value+"&answer="+answer+"&pid="+document.poll2.pid.value+"";
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
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult2.jsp?pid=121&sid=204";
	var popupHeight = 265;
	var popupWidth = 455;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}