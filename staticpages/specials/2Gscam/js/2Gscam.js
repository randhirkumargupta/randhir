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
	
	
	
/*--------------------------------hometab------------------------------------*/
var i ;
var images1= new Array();
images1[0] = "url(images/lead_photos-tab.gif)";
images1[1] = "url(images/lead_video-tab.gif)";
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
		
		ph3.style.color = '#002F5E';
		vd3.style.color = '#002F5E';
		main3.style.color = '#B0530D';
	}
	
		 
		
		 
/*-----------------------------------------Top Tab-----------------------------------*/

function mouseoverAT()
{
document.getElementById("share1T").style.backgroundColor='#E9E9E9';
}
function mouseoutAT()
{
document.getElementById("share1T").style.backgroundColor='#ffffff';
}
function mouseoverBT()
{
document.getElementById("share2T").style.backgroundColor='#E9E9E9';
}
function mouseoutBT()
{
document.getElementById("share2T").style.backgroundColor='#ffffff';
}


function show_share_listT() {
        document.getElementById('vt_share_listT').style.display="block";
}
function hide_share_listT() {
        document.getElementById('vt_share_listT').style.display="none";
}

/*----------------------------------------gallery---------------------------------*/




			var totalImage = 7;
			var showImage = 3;
			var firstImg = 1;
			var images = new Array();
			images[0] = "images/thumbs1.jpg";
			images[1] = "images/thumbs2.jpg";
			images[2] = "images/thumbs3.jpg";
			images[3] = "images/thumbs1.jpg";
			images[4] = "images/thumbs2.jpg";
			images[5] = "images/thumbs3.jpg";
			images[6] = "images/thumbs1.jpg";
			images[7] = "images/8.gif";
			if(totalImage > images.length)
			{
				alert("correcting totalImage value from "+totalImage+" to "+images.length);
				totalImage = images.length;
			}
			if(showImage > totalImage)
			{
				alert("correcting showImage value from "+showImage+" to "+totalImage);
				showImage = totalImage;
			}
			if(firstImg > totalImage)
			{
				alert("correcting firstImage value from "+firstImg+" to "+totalImage)
				firstImg = totalImage;
			}
			totalImage--;
			firstImg--;

			function previous()
			{
				var imgStr = "";
				if(firstImg <= 0)
					firstImg = totalImage;
				else
					firstImg--;
				var imageNo = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					imgStr += "<img src=\""+images[imageNo]+"\"  hspace=\"5\"/>";
					if(imageNo >= totalImage)
						imageNo = 0;
					else
						imageNo++;
				}
				document.getElementById("imagetd").innerHTML = imgStr;				
			}

			function next()
			{
				var imgStr = "";
				var imageNo = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					if(imageNo >= totalImage)
						imageNo = 0;
					else
						imageNo++;
					imgStr += "<img src=\""+images[imageNo]+"\" hspace=\"5\"/>";
				}
				firstImg++;
				if(firstImg > totalImage)
					firstImg = 0;
				document.getElementById("imagetd").innerHTML = imgStr;
			}

			function loadImages()
			{
				var imgStr = "";
				var imageNo = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					if(imageNo > totalImage)
						imageNo = 0;
					imgStr += "<img src=\""+images[imageNo]+"\" hspace=\"5\"/>";
					imageNo++;
				}
				document.getElementById("imagetd").innerHTML = imgStr;
			}
	
	
	var totalName = 7;
			var showName = 3;
			var firstName = 1;
			var names = new Array();
			names[0] = "Deepak";
			names[1] = "Dinesh";
			names[2] = "Saurabh";
			names[3] = "sangeeta";
			names[4] = "Sanjay";
			names[5] = "Jagdish";
			names[6] = "vipin";
			
			if(totalName > names.length)
			{
				alert("correcting totalName value from "+totalName+" to "+names.length);
				totalImage = images.length;
			}
			if(showName > totalName)
			{
				alert("correcting showName value from "+showName+" to "+totalName);
				showName = totalName;
			}
			if(firstName > totalName)
			{
				alert("correcting firstName value from "+firstName+" to "+totalName)
				firstName= totalName;
			}
			totalName--;
			firstName--;

			function previous2()
			{
				var nameStr = "";
				if(firstName <= 0)
					firstName = totalName;
				else
					firstName--;
				var nameNo = firstName;
				for(var i = 0; i < showName; i++)
				{
					nameStr += names[nameNo]  ;
					if(NameNo >= totalName)
						NameNo = 0;
					else
						NameNo++;
				}
				document.getElementById("Nametd").innerHTML = nameStr;				
			}

			function next2()
			{
				var nameStr = "";
				var NameNo = firstName;
				for(var i = 0; i < showName; i++)
				{
					if(NameNo >= totalName)
						NameNo = 0;
					else
						NameNo++;
					nameStr += images[imageNo];
				}
				firstName++;
				if(firstName > totalName)
					firstName = 0;
				document.getElementById("Nametd").innerHTML = nameStr;
			}

			function loadName()
			{
				var nameStr = "";
				var NameNo = firstName;
				for(var i = 0; i < showName; i++)
				{
					if(NameNo > totalName)
						NameNo = 0;
					nameStr += images[imageNo];
					NameNo++;
				}
				document.getElementById("Nametd").innerHTML = nameStr;
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
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult.jsp?pid=109&sid=132";
	var popupHeight = 265;
	var popupWidth = 455;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}


<!---------------------------------------------------------Story Page(Font size increase or decrease)---------------------------------------------------->

var min=8;
var max=18;
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

/*-------------------------------------------- states Schedules----------------------------*/

function toggle(theDiv) 
{

	var elem = document.getElementById(theDiv);
	var elem1 = document.getElementById("Layer4");
	var elem2 = document.getElementById("Layer5");
	var elem3 = document.getElementById("Layer6"); 
	var elem4 = document.getElementById("Layer7");
	var elem5 = document.getElementById("Layer8");
	var elem6 = document.getElementById("Layer9"); 
	var elem7 = document.getElementById("Layer10");
	
	
		elem1.style.display="none";
		elem2.style.display="none";
		elem3.style.display="none";
		elem4.style.display="none";
		elem5.style.display="none";
		elem6.style.display="none";
		elem7.style.display="none";
		elem.style.display="block";
}

function toggle2(txt) 
{

	var togg = document.getElementById(txt);
	var togg1 = document.getElementById("Layer1");
	var togg2 = document.getElementById("Layer2");
	
	
		togg1.style.display="none";
		togg2.style.display="none";
		togg.style.display="block";
}