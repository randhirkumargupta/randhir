function validateform()
	{	
		
	
		if ((document.myform.textarea.value.length >250) ||(document.myform.textarea.value.length <10))
		{
			alert(" characters should not be less than 10 & greater than 250 ");
			return false;
		}	
		
		if (document.myform.textfield.value.length ==0 )
		{ 
			alert("Enter ur name");
			document.myform.textfield.focus();
			return false;
		}	
		
		if (document.myform.textfield2.value.length== 0 )
		{
			alert("E-mail should not be blank");
			document.myform.textfield2.focus();
			return false;
		}
		else
		{
			var a = "@";
			var dot = ".";
			var s= document.myform.textfield2.value ;
			if (( s.indexOf(a)==-1) || (s.indexOf(a)==0) || (s.indexOf(a)== (s.length) - 1 ))
			{
				alert("invalid E-mail address");
				document.myform.textfield2.focus();
				return false;
			}
			if ((s.indexOf(dot)==-1) || (s.indexOf(dot)==0) || (s.indexOf(dot)==s.length-1 ))
			{
				alert("invalid E-mail address");
				document.myform.textfield2.focus();
				return false;
			}
		}
		return true;
	}
	
	

	$(document).ready(function(){
                $(".flashshow").click(function(){
                    $(".slidingDiv").hide();
                    $("."+$(this).find('a').attr("name")).show();
					$(".slidingone").show();					
                });
                $(".show_hide").click(function(){
					$(".slidingone").hide();
					$(".slidingDiv").hide();
					
				});
				$(window).scroll(function() {
					$(".slidingone").css({top:getScrollY()+100});				
				});
           
            });
			function getScrollY() {
				scrOfY = 0;
				if( typeof( window.pageYOffset ) == "number" ) {
					scrOfY = window.pageYOffset;
				} else if( document.body && ( document.body.scrollLeft || document.body.scrollTop ) ) {
					scrOfY = document.body.scrollTop;
				} else if( document.documentElement && ( document.documentElement.scrollLeft || document.documentElement.scrollTop ) ) {
					scrOfY = document.documentElement.scrollTop;
				}
				return scrOfY;
			}
	
/*--------------------------------hometab------------------------------------*/
var i ;
var images1= new Array();
images1[0] = "url(images/photo-tab.png)";
images1[1] = "url(images/video_tab.png)";
function changeImage2(i)
{
document.getElementById('image2').style.backgroundImage = images1[i];
//alert(images1[i]);
}


		 
		
function toggle3(theDiv) {

     var elem = document.getElementById(theDiv);
	   
		 var elem5 = document.getElementById("Layer5");
	     var elem6 = document.getElementById("Layer6");
		 
		 elem5.style.display="none";
	elem6.style.display="none";
	elem.style.display="block";
		 }
		 
function toggle6(id3)
	{
		var ph3 = document.getElementById("video3");
		var vd3 = document.getElementById("photo3");
		var main3 = document.getElementById(id3);
		
		ph3.style.color = '#6a6a6a';
		vd3.style.color = '#6a6a6a';
		main3.style.color = '#FFFFFF';
	}

	/*----------------------------------------------Poll-----------------------------------------*/

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
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult.jsp?pid=223&sid=238";
	var popupHeight = 275;
	var popupWidth = 460;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}
