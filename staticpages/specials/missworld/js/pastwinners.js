/*----------------------------------------gallery---------------------------------*/




			var totalImage = 10;
			var showImage = 6;
			var firstImg = 1;
			var images = new Array();
			images[0] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127103524_yukta.jpg";
			images[1] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_missworld2000officialpict2.jpg";
			images[2] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_nigeria.jpg";
			images[3] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_azraakndr0.jpg";
			images[4] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_Rosanna_Davison_MW2003b.jpg";
			images[5] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_msworld_2004.jpg";
			images[6] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_UnnurBirnaVilhjlmsdttir2.jpg";
			images[7] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_missworld2006.jpg";
			images[8] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_Miss+World+2007.jpg";
			images[9] = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/march09/091127102319_marie-ann-umali-2009-3-7-20.jpg";


			var imagesLinks = new Array();
		    imagesLinks[0] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2358&photocat=2";
			imagesLinks[1] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2353&photocat=2";
			imagesLinks[2] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2357&photocat=2";
			imagesLinks[3] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2354&photocat=2";
			imagesLinks[4] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2355&photocat=2";
			imagesLinks[5] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2356&photocat=2";
			imagesLinks[6] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2359&photocat=2";
			imagesLinks[7] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2360&photocat=2";
			imagesLinks[8] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2361&photocat=2";
			imagesLinks[9] = "http://indiatoday.intoday.in/site/PhotoGallery?gId=2362&photocat=2";



			var imagesAlt = new Array();
		    imagesAlt[0] = "Miss Universe 1999";
			imagesAlt[1] = "Miss Universe 2000";
			imagesAlt[2] = "Miss Universe 2001";
			imagesAlt[3] = "Miss Universe 2002";
			imagesAlt[4] = "Miss Universe 2003";
			imagesAlt[5] = "Miss Universe 2004";
			imagesAlt[6] = "Miss Universe 2005";
			imagesAlt[7] = "Miss Universe 2006";
			imagesAlt[8] = "Miss Universe 2007";
			imagesAlt[9] = "Miss Universe 2008";

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
				//alert("aaa");
				var imgStrs = "";
				if(firstImg <= 0)
					firstImg = totalImage;
				else
					firstImg--;
				var imageNo = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					imgStrs +='<a href=\"'+imagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+images[imageNo]+'\" hspace=\"5\" alt=\"'+imagesAlt[imageNo]+'\" title=\"'+imagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';

					if(imageNo >= totalImage)
						imageNo = 0;
					else
						imageNo++;
				}
				//alert(imgStr);
				document.getElementById("imagetd").innerHTML = imgStrs;
			}

			function next()
			{
				var imgStrs = "";
				var imageNo = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					if(imageNo >= totalImage)
						imageNo = 0;
					else
						imageNo++;
					imgStrs +='<a href=\"'+imagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+images[imageNo]+'\" hspace=\"5\" alt=\"'+imagesAlt[imageNo]+'\" title=\"'+imagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
					//alert(imgStr);
				}
				firstImg++;
				if(firstImg > totalImage)
					firstImg = 0;
				document.getElementById("imagetd").innerHTML = imgStrs;
			}

			function loadImages()
			{
				var imgStrs = "";
				var imageNo = firstImg;
				for(var i = 0; i < showImage; i++)
				{
					if(imageNo > totalImage)
					imageNo = 0;
					imgStrs +='<a href=\"'+imagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+images[imageNo]+'\" hspace=\"5\" alt=\"'+imagesAlt[imageNo]+'\" title=\"'+imagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';

					imageNo++;
				}
				//alert (imgStr);
				document.getElementById("imagetd").innerHTML = imgStrs;
			}
