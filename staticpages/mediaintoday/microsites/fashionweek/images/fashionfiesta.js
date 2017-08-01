var totalwallImage = 8;
			var showwallImage = 3;
			var firstwallImg = 1;
			var wallimages = new Array();
			wallimages[0] = "http://media2.intoday.in/indiatoday//images/stories/2011july/b-f-w-1_072211123706.jpg";
			wallimages[1] = "http://media2.intoday.in/indiatoday//images/stories/2011july/b-f-w-2_072211123706.jpg";
			wallimages[2] = "http://media2.intoday.in/indiatoday//images/stories/2011july/b-f-w-3_072211123706.jpg";
			wallimages[3] = "http://media2.intoday.in/microsites/fashionweek/images/LFW_thumb4.jpg";
			wallimages[4] = "http://media2.intoday.in/microsites/fashionweek/images/LFW_thumb5.jpg";

			var wallimagesLinks = new Array();
		    wallimagesLinks[0] = "http://wonderwoman.intoday.in/wonderwoman/photo/695/7/Fashion%20Week%20Special/mugdha-godse-sizzles-on-wifw-ramp!.html";
			wallimagesLinks[1] = "http://wonderwoman.intoday.in/wonderwoman/photo/692/7/Fashion%20Week%20Special/silks-andchiffons-rule-day-2-at-wifw.html";
			wallimagesLinks[2] = "http://wonderwoman.intoday.in/wonderwoman/photo/696/7/Fashion%20Week%20Special/day-5-of-wills-lifestyle-india-fashion-week.html";
			wallimagesLinks[3] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=1950&photocat=12";
			wallimagesLinks[4] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=1957&photocat=12";

			var wallimagesAlt = new Array();
		    wallimagesAlt[0] = "Mugdha Godse sizzles on WIFW ramp!";
			wallimagesAlt[1] = "Silks & chiffons rule Day 2 at WIFW";
			wallimagesAlt[2] = "Wills Lifestyle India Fashion Week";
			wallimagesAlt[3] = "Lakme Fashion Week: Day 5";
			wallimagesAlt[4] = "Tarun Tahiliani's show";
			
			if(totalwallImage > wallimages.length)
			{
				totalwallImage = wallimages.length;
			}
			if(showwallImage > totalwallImage)
			{
				showwallImage = totalwallImage;
			}
			if(firstwallImg > totalwallImage)
			{
				firstwallImg = totalwallImage;
			}
			totalwallImage--;
			firstwallImg--;

			function wallprevious()
			{
				var imgStr = "";
				if(firstwallImg <= 0)
					firstwallImg = totalwallImage;
				else
					firstwallImg--;
				var imageNo = firstwallImg;
				for(var i = 0; i < showwallImage; i++)
				{    
					imgStr +='<a href=\"'+wallimagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+wallimages[imageNo]+'\" hspace=\"5\" alt=\"'+wallimagesAlt[imageNo]+'\" title=\"'+wallimagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
							
					if(imageNo >= totalwallImage)
						imageNo = 0;
					else
						imageNo++;
				}
				document.getElementById("wallimagetd").innerHTML = imgStr;				
			}

			function wallnext()
			{
				var imgStr = "";
				var imageNo = firstwallImg;
				for(var i = 0; i < showwallImage; i++)
				{
					if(imageNo >= totalwallImage)
						imageNo = 0;
					else
						imageNo++;
					imgStr +='<a href=\"'+wallimagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+wallimages[imageNo]+'\" hspace=\"5\" alt=\"'+wallimagesAlt[imageNo]+'\" title=\"'+wallimagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
				}
				firstwallImg++;
				if(firstwallImg > totalwallImage)
					firstwallImg = 0;
				document.getElementById("wallimagetd").innerHTML = imgStr;
			}

			function loadwallImages()
			{
				var imgStr = "";
				var imageNo = firstwallImg;
				for(var i = 0; i < showwallImage; i++)
				{
					if(imageNo > totalwallImage)
						imageNo = 0;
					imgStr +='<a href=\"'+wallimagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+wallimages[imageNo]+'\" hspace=\"5\" alt=\"'+wallimagesAlt[imageNo]+'\" title=\"'+wallimagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
					
					imageNo++;
				}
				document.getElementById("wallimagetd").innerHTML = imgStr;
			}


var i ;
var images1= new Array();
images1[0] = "url(http://media2.intoday.in/microsites/fashionweek/images/tab1.gif)";
images1[1] = "url(http://media2.intoday.in/microsites/fashionweek/images/tab2.gif)";
images1[2] = "url(http://media2.intoday.in/microsites/fashionweek/images/tab3.gif)";
images1[3] = "url(http://media2.intoday.in/microsites/fashionweek/images/tab4.gif)";
images1[4] = "url(http://media2.intoday.in/microsites/fashionweek/images/tab5.gif)";

function changeImage2(i)
{
document.getElementById('image2').style.backgroundImage = images1[i];
//alert(images1[i]);
}


		 
		
function toggle3(theDiv) {

     var elem = document.getElementById(theDiv);
	   
		 var elem1 = document.getElementById("Layer1");
	     var elem2 = document.getElementById("Layer2");
		  var elem3 = document.getElementById("Layer3");
	     var elem4 = document.getElementById("Layer4");
		  var elem5 = document.getElementById("Layer5");
		 
	elem1.style.display="none";
	elem2.style.display="none";
	elem3.style.display="none";
	elem4.style.display="none";
	elem5.style.display="none";
	elem.style.display="block";
		 }


function toggle6(id3)
	{
		var da3 = document.getElementById("day1");
		var ad3 = document.getElementById("day2");
		var dy3 = document.getElementById("day3");
		var yd3 = document.getElementById("day4");
		var ya3 = document.getElementById("day5");
		var main3 = document.getElementById(id3);
		
		da3.style.color = '#000000';
		ad3.style.color = '#000000';
		dy3.style.color = '#000000';
		yd3.style.color = '#000000';
		ya3.style.color = '#000000';
		main3.style.color = '#ffffff';
	}



var totalImage = 8;
			var showImage = 3;
			var firstImg = 1;
			var bofimages = new Array();

                       bofimages[0] = "http://media2.intoday.in/indiatoday//images/stories/2011july/b-f-c-1_072211123706.jpg";
                       bofimages[1] = "http://media2.intoday.in/indiatoday//images/stories/2011july/b-f-c-2_072211123706.jpg";
                       bofimages[2] = "http://media2.intoday.in/indiatoday//images/stories/2011july/b-f-c-3_072211123706.jpg";
                       bofimages[3] = "http://media2.intoday.in/indiatoday//images/stories/2010october/101020045022_neha.jpg";
                       bofimages[4] = "http://media2.intoday.in/indiatoday//images/stories/2010october/101020045022_rani-vidya.jpg";

 

var imagesLinks = new Array();
imagesLinks[0] = "http://wonderwoman.intoday.in/wonderwoman/photo/97/7/Fashion%20Week%20Special/couture-week-suneet-varmas-show.html";
imagesLinks[1] = "http://wonderwoman.intoday.in/wonderwoman/photo/94/7/Fashion%20Week%20Special/kangana-sizzles-at-couture-week.html";
imagesLinks[2] = "http://indiatoday.intoday.in/site/gallery/bollywood-drama-at-hdil-couture-week/1/3742.html";
imagesLinks[3] = "http://wonderwoman.intoday.in/wonderwoman/photo/87/2/Beauty%20&%20Style/couture-week-gaurav-guptas-show.html";
imagesLinks[4] = "http://wonderwoman.intoday.in/wonderwoman/photo/83/2/Beauty%20&%20Style/rani,-vidya-cheer-for-sabyasachi.html";

									var imagesAlt = new Array();
									imagesAlt[0] = "Glitter & glam at Manav Gangwani's show";
                                    imagesAlt[1] = "Sexy Lara walks ramp for Rina Dhaka";
                                    imagesAlt[2] = "Shweta Bachchan walks for Abu-Sandeep";
                                    imagesAlt[3] = "Neha at Gaurav Gupta's show";
                                    imagesAlt[4] = "Rani, Vidya cheer for Sabyasachi";


			
			if(totalImage > bofimages.length)
			{
				totalImage = bofimages.length;
			}
			if(showImage > totalImage)
			{
				showImage = totalImage;
			}
			if(firstImg > totalImage)
			{
				firstImg = totalImage;
			}
			totalImage--;
			firstImg--;

			function previous()
			{
				var imgStrsBof = "";
				if(firstImg <= 0)
					firstImg = totalImage;
				else
					firstImg--;
				var imageNoBof = firstImg;
				for(var i = 0; i < showImage; i++)
				{    
					imgStrsBof +='<a href=\"'+imagesLinks[imageNoBof]+'\" target=\"_blank\"><img src=\"'+bofimages[imageNoBof]+'\" hspace=\"5\" alt=\"'+imagesAlt[imageNoBof]+'\" title=\"'+imagesAlt[imageNoBof]+'\" border=\"0\"/>'+'</a>';
							
					if(imageNoBof >= totalImage)
						imageNoBof = 0;
					else
						imageNoBof++;
				}
				document.getElementById("imagetd").innerHTML = imgStrsBof;				
			}

			function next()
			{
				var imgStrsBof = "";
				var imageNoBof = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					if(imageNoBof >= totalImage)
						imageNoBof = 0;
					else
						imageNoBof++;
					imgStrsBof +='<a href=\"'+imagesLinks[imageNoBof]+'\" target=\"_blank\"><img src=\"'+bofimages[imageNoBof]+'\" hspace=\"5\" alt=\"'+imagesAlt[imageNoBof]+'\" title=\"'+imagesAlt[imageNoBof]+'\" border=\"0\"/>'+'</a>';
				}
				firstImg++;
				if(firstImg > totalImage)
					firstImg = 0;
				document.getElementById("imagetd").innerHTML = imgStrsBof;
			}

			function loadImages()
			{
				var imgStrsBof = "";
				var imageNoBof = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					if(imageNoBof > totalImage)
					imageNoBof = 0;
					imgStrsBof +='<a href=\"'+imagesLinks[imageNoBof]+'\" target=\"_blank\"><img src=\"'+bofimages[imageNoBof]+'\" hspace=\"5\" alt=\"'+imagesAlt[imageNoBof]+'\" title=\"'+imagesAlt[imageNoBof]+'\" border=\"0\"/>'+'</a>';
					
					imageNoBof++;
				}
				document.getElementById("imagetd").innerHTML = imgStrsBof;
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
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult.jsp?pid=180&sid=199";
	var popupHeight = 265;
	var popupWidth = 455;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}
