<!doctype html>
<html>
<!-- Begin comScore Tag -->
<script>
  var _comscore = _comscore || [];
  _comscore.push({ c1: "2", c2: "8549097" });
  (function() {
    var s = document.createElement("script"), el = document.getElementsByTagName("script")[0];
    s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js";
    el.parentNode.insertBefore(s, el);
  })();
</script>
<noscript>
  <img src="http://b.scorecardresearch.com/p?c1=2&c2=8549097&cv=2.0&cj=1"  />
</noscript>
<!-- End comScore Tag -->


<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-795349-17', 'auto');
  ga('send', 'pageview');

</script>

    
    
<head>
<meta charset="utf-8">
<title>Arvind Kejriwal's oath taking ceremony - take a pledge with CM</title>
<meta name="description" content="Pledge with Arvind Kejriwal to make Delhi a better cleaner and developed city to live in." />
<meta name="keywords" content="arvind kejriwal, delhi elections, delhi elections 2015, delhi, aam admi party, oath taking ceremony, arvind kejriwal's oath taking ceremony,Ramlila Maidan
" />
<meta property="og:url" content="/pledgewithCM/index.jsp" />
<meta property="og:image" content="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/FB-share.png" />
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900,100' rel='stylesheet' type='text/css'>
<link rel="stylesheet" type="text/css" href="/pledgewithCM/css/style.css" />
<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/js/jquery.min.1.8.2.js" type="text/javascript"></script>
<script>
function validate()
{
if(document.dcm.FNAME.value=="")
	{
		alert("Please Enter Your NAME ");
		document.dcm.FNAME.focus();
		return false
	}
	else
	if(document.dcm.EMAIL.value=="")
	{
		alert("Please Enter Your Email");
		document.dcm.EMAIL.focus();
		return false
	}
	else
	if(document.dcm.mobile.value=="")
	{
		alert("Please Enter Your mobile");
		document.dcm.mobile.focus();
		return false
	}
	}
	</script>
<script type="text/javascript">
(function($,W,D)
{
    var JQUERY4U = {};

    JQUERY4U.UTIL =
    {
        setupFormValidation: function()
        {
            //form validation rules
            $("#register-form").validate({
                rules: {
					 email: {
                        required: true,
                        email: true
                    },
					mobile :  {
						required : true,
						digits : true,
						minlength: 10,
						maxlength : 12
        			},
                    name: "required",
                    comment: "required",
					number: "required"
                },
                messages: {
                    email: "Please enter a valid Email Address",
					name: "Please enter your Name",
                    mobile :  {
					required : 'Please enter your Moblie',
					digits : 'Please enter numbers only',
					minlength: 'Please enter a vaild moblie number',
					maxlength: 'Please enter a vaild moblie number'
        			},
					comment: "Please enter your Message",
					number: "Please enter the code"
                },
                submitHandler: function(form) {
                    form.submit();
                }
            });
        }
    }
	});
	</script>

 
<script>
$(document).ready(function() {
	var w_height = $(document).height();
	$('.overlay').css('height', w_height);
	
    $('.pledge-button').click(function(){
			$('.overlay').show();
			$('.popup').show();	
	});
	
	$('.close').click(function(){
		$(this).parent('div').hide();
		$('.overlay').hide();
	});
});
</script>
<script>
$(document).ready(function(){
		$('.share-icon').click(function(){
			$('.share-icon').show();
			if(!$(this).next('ul').html().match('facebook')) {		
				contentURL = $(this).attr('url');
				contentTitle = $(this).attr('ctitle');
				var contenttotwrite = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href=http://indiatoday.intoday.in/"+contentURL+"&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=80&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:80px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1346833764.html#_=1346847881207&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=http://indiatoday.intoday.in/"+contentURL+"&amp;size=m&amp;text="+escape(contentTitle)+"%20-%20India%20Today&amp;url=http://indiatoday.intoday.in/"+contentURL+"&amp;via=indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 20px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url=http://indiatoday.intoday.in/"+contentURL+"' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>";
				var thisss = $(this);	
				$('.open').css({display:'none'});	
				$(this).css({display:'none'}).next('ul,ul li,.frame').css({display:'block'}).html(contenttotwrite);
				$(this).next('ul,ul li,.frame').mouseleave(function(){thisss.css({display:'block'});$('.share-story ul').css({display:'none'}); });
			} else {
				var thisss = $(this);	
				$('.share-story ul').css({display:'none'});	
				$(this).css({display:'none'}).next('ul,ul li,.frame').css({display:'block'});
				$(this).next('ul,ul li,.frame').mouseleave(function(){thisss.css({display:'block'});$('.share-story ul').css({display:'none'}); });
			}
		});
	});
</script>

</head>

<body>
 



<!-- /////////////////// FB LOGIN //////////////// --> <div class="trans" style="display:none;"></div>

<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css'> <style> #comment_box {
    background-color:#fff;
    border: none;
    float: left;
    font: 12px arial;
    margin: 0;
    padding: 0px;

}
#comment_box #right {

    color: rgb(102, 102, 102);
    float: left;
    font: 11px georgia;
}
#fb-auth{height:41px;}
.facebook { width:207px; height:40px; background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/education/sign-fb.png); display:block; text-indent:-999px;} .googleplus { width:207px; height:40px; background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/education/sign-twit.png); display:block; text-indent:-999px;} .fl { float:left;} .post_comment { width:95%; border-bottom:1px solid #d6d6d6; } .posted_message { float:right; width:575px;} #surfercommt { width:650px;} #logoutText {
    background: url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/comment2-2.gif") !important;
	height:25px !important;
	width:90px !important;
}
.zocial.googleplus:before{ background:none!important;height:0px !important; width:0px !important;} #comment_box #right input.submit_button { display:block !important} .removewordclass{
	padding: 5px; display: block; background: none repeat scroll 0px 0px rgb(228, 228, 228); border: 1px solid rgb(215, 215, 215); margin-bottom: 10px;color:#CF2F0F; } </style>

<!-- Google Api   -->
<script type="text/javascript">
var msgCount=0;
 function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + "; " + expires; }

function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) return c.substring(name.length,c.length);
    }
    return "";
}
	// var clientId = '1035464217329.apps.googleusercontent.com';
	 var clientId='873028034025-qvn73jcllagnknd21p3ql7f7cio2ch98.apps.googleusercontent.com';
	 var apiKey='AIzaSyAWcB4cYEAwyZk0e8wF6E7eBP6zb-Upl6Y';
	// var apiKey = 'AIzaSyDlV1SiXso7T4svl2yef3Xv7Tdp9i5itlI';
	 var scopes = 'https://www.googleapis.com/auth/plus.me https://www.googleapis.com/auth/userinfo.email';
	  function handleClientLoad() {
        gapi.client.setApiKey(apiKey);
        window.setTimeout(checkAuth,1);
      }
      function checkAuth() {
        gapi.auth.authorize({client_id: clientId, scope: scopes, immediate: true}, handleAuthResult);
      }
	 function handleAuthResult(authResult) {
        var authorizeButton = document.getElementById('authorize-button');
        if (authResult && !authResult.error) {
		    $('#authorize-button').hide();
			$('#logoutText').show();
			
		//	document.getElementById('fill-details').style.display ="none";		
			//document.getElementById('facebook').style.display ="none";
		//document.getElementById('linkedin').style.display ="none";
			
		    makeApiCall();
        } else {
          authorizeButton.style.visibility = '';
          authorizeButton.onclick = handleAuthClick;
        }
      }
	  function handleAuthClickLogout(event) {
     	window.location.href='http://accounts.google.com/Logout';	   
        return false;
      } 
	     
	   function startLogoutPolling() {
            $('#authorize-button').show();
            $('#logoutText').hide();
			//	document.getElementById('fill-details').style.display ="block";
				document.getElementById("googleplus").style.backgroundImage="url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/login-g.jpg)";
				document.getElementById('facebook').style.display ="block";
				document.getElementById("user-info").innerHTML   ='';
				document.getElementById('debug').innerHTML     = "";
                document.getElementById('other').style.display = "none";
                document.getElementById('FNAME').value		   = "";
				document.getElementById('EMAIL').value		   = "";
				document.getElementById('FNAME').type		   = "text";
				document.getElementById('EMAIL').type	 	   = "text";
				// document.getElementById('RFNAME').value		   = "";
			//	document.getElementById('REMAIL').value		   = "";
			//	document.getElementById('RFNAME').type		   = "hidden";
			//	document.getElementById('REMAIL').type		   = "hidden";
				document.getElementById('sn_image').value	   = "";
				document.getElementById('sn_source').value	   = "";
			//	document.getElementById('repFNAME').value	   = "";
			//	document.getElementById('repEMAIL').value	   = "";
			//	document.getElementById('repFNAME').type	   = "text";
			//	document.getElementById('repEMAIL').type	   = "text";
			//	document.getElementById("repName").style.display   = 'block';
			//	document.getElementById("repEmail").style.display  = 'block';
				//document.getElementById("txtName").style.display   = 'block';
				//document.getElementById("txtEmail").style.display  = 'block';
				//document.getElementById('user-text').style.marginLeft = '0px';
			//	document.getElementById('message').style.width = '610px';
				document.getElementById('fb_button').style.display ="block";
				
			//	document.getElementById('please-text').style.display ="block";
			//	document.getElementById('linkedin').style.display ="block";
		 }
	   
      function handleAuthClick(event) {
        gapi.auth.authorize({client_id: clientId, scope: scopes, immediate: false}, handleAuthResult);
        return false;
      }

      // Load the API and make an API call.  Display the results on the screen.
      function makeApiCall() {

				// Load the oauth2 libraries to enable the userinfo methods.
			gapi.client.load('oauth2', 'v2', function() {
				  var request = gapi.client.oauth2.userinfo.get();
				  request.execute(getEmailCallback);
				});
		
		
		  function getEmailCallback(obj){
					
			if (obj['email']) {
			  document.getElementById('EMAIL').value =obj['email'];
			}		
			
		  }
		 
	 
        gapi.client.load('plus', 'v1', function() {
          var request = gapi.client.plus.people.get({
            'userId': 'me'
          });
		
          request.execute(function(resp) {
			$('#authorize-button').hide();
	        $('#logoutText').show();
			
			var heading = document.createElement('h4');
            var image = document.createElement('img');
			var br = document.createElement('br');
			heading.appendChild(br);
			
			if(resp.image != null && resp.image != undefined && resp.image !="" ) {
            	image.src = resp.image.url;  
            	heading.appendChild(image);
				document.getElementById('sn_image').value = resp.image.url;
            } else {
				image.src = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/images/common/p2.png";
				heading.appendChild(image);
				document.getElementById('sn_image').value = "http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/images/common/p2.png";
			}
			
			if(resp.displayName != null && resp.displayName != undefined && resp.displayName !="" ) {
            	var displayName = resp.displayName;  
            } else {
				var displayName = document.getElementById('EMAIL').value;
			}
			
			heading.appendChild(br);
			heading.appendChild(document.createTextNode(displayName));
			document.getElementById('user-info').appendChild(heading);	
//			document.getElementById('fill-details').style.display ="none";		
			document.getElementById('FNAME').value		   = displayName;
	//		document.getElementById('repFNAME').value	   = displayName;
	//		document.getElementById('repEMAIL').value	   = document.getElementById('EMAIL').value;
	//		document.getElementById('repFNAME').type	   = "hidden";
	//		document.getElementById('repEMAIL').type	   = "hidden";
	//		document.getElementById("repName").style.display = 'none';
	//		document.getElementById("repEmail").style.display = 'none';
			//document.getElementById("txtName").style.display = 'none';
	       // document.getElementById("txtEmail").style.display = 'none';
			//document.getElementById('RFNAME').type		   = "hidden";
	//		document.getElementById('REMAIL').type		   = "hidden";
			document.getElementById('FNAME').type		   = "hidden";
			document.getElementById('EMAIL').type	  	   = "hidden";
			//document.getElementById('RFNAME').value		   = displayName;
	//		document.getElementById('REMAIL').value		   = document.getElementById('EMAIL').value;
			
			document.getElementById('sn_source').value	   = 'googleplus';
			//document.getElementById('user-text').style.marginLeft = '80px';
//			document.getElementById('message').style.width = '510px';
			document.getElementById('fb_button').style.display ="none";
			document.getElementById('please-text').style.display ="none";
		//	document.getElementById('linkedin').style.display ="none";
			document.getElementById('authorize-button').style.display ="none";	
			document.getElementById("googleplus").style.backgroundImage="url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/comment2-2.gif)";	
			
			
			 $.post("fb_registered_submit.jsp?sn_image="+image.src+"&source=googleplus",{fullname:displayName,username:displayName,regemail:displayName,snImage:image.src},function(data,status){
				 
				 try{
				 var chk = getCookie('itfacebook');
				 
				 if(chk!=undefined && chk!=null && chk!="") {
					
				 } else {
					setCookie('itfacebook','done', 7);
					//window.location.href="http://indiatoday.intoday.in/pledgewithCM/index.jsp"; 
					 $('.trans').hide();
			 		$('.popup,.overlay').hide();
				 }
				 }catch(err){}
				 /*alert("Data: " + data + "\nStatus: " + status);*/
			
			 
			 
			});
			
		  });
        });
      }
    </script>
<script src="https://apis.google.com/js/client.js?onload=handleClientLoad"></script>
<!-- Google Api End -->


<!--Face Book Api -->
<div id="fb-root"></div>
<script type="text/javascript">
	var button;
	var userInfo;
	
	window.fbAsyncInit = function() {
		FB.init({ appId: '613580381995012', //change the appId to your appId
			status: true, 
			cookie: true,
			xfbml: true,
			oauth: true});

	   function updateButton(response) {
			button       =   document.getElementById('fb-auth');
			userInfo     =   document.getElementById('user-info');
			
			if (response.authResponse) {
				//user is already logged in and connected
				FB.api('/me', function(info) {
					login(response, info);
				});
				
				button.onclick = function() {
					FB.logout(function(response) {
					
					userInfo.innerHTML                             = "";
					document.getElementById('authorize-button').style.display ="block";
			//	document.getElementById('please-text').style.display ="block";
			//	document.getElementById('linkedin').style.display ="block";
			//	document.getElementById('clear-topmarg').style.display ="block";
			//	document.getElementById('fill-details').style.display ="block";
					//document.getElementById('debug').innerHTML     = "";
				//	document.getElementById('other').style.display = "none";
					document.getElementById('FNAME').type		   = "";
					document.getElementById('EMAIL').type	 	   = "";
					document.getElementById('FNAME').value		   = "";
					document.getElementById('EMAIL').value		   = "";
			//		document.getElementById('repFNAME').value	   = "";
			//		document.getElementById('repEMAIL').value	   = "";
					document.getElementById('sn_image').value	   = "";
					document.getElementById('sn_source').value	   = "";
					//document.getElementById('RFNAME').type		   = "hidden";
			//		document.getElementById('REMAIL').type		   = "";
					//document.getElementById('user-text').style.marginLeft = '0px';
//					document.getElementById('message').style.width = '610px';
					logout(response);
					});
				};
			} else {
				//user is not connected to your app or logged out
				button.innerHTML = 'Sign in';
				button.onclick = function() {
					FB.login(function(response) {
						if (response.authResponse) {
							FB.api('/me', function(info) {
								login(response, info);
							});	   
						} else {
							//user cancelled login or did not grant authorization
						
						}
					}, {scope:'email,user_birthday,status_update,publish_stream,user_about_me'});  	
				}
			}
		}
		
		// run once with current status and whenever the status changes
		FB.getLoginStatus(updateButton);
		FB.Event.subscribe('auth.statusChange', updateButton);	
	};
	(function() {
		var e = document.createElement('script'); e.async = true;
		e.src = document.location.protocol 
			+ '//connect.facebook.net/en_US/all.js';
		document.getElementById('fb-root').appendChild(e);
	}());
	
	
	function login(response, info){
		if (response.authResponse) {
			var accessToken                                =  response.authResponse.accessToken;
			userInfo.innerHTML                             =  '<img src="https://graph.facebook.com/' + info.id + '/picture"><br>' + info.name;
			button.innerHTML                               = 'Logout';
		//	document.getElementById('FNAME').type		   = "hidden";
		//	document.getElementById('EMAIL').type		   = "hidden";
		    document.getElementById('sn_image').type	   = "hidden";
			document.getElementById('sn_source').type		= "hidden";
			
			
			//document.getElementById("facebook").style.backgroundImage="url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/education/logout-fb.png)";
			document.getElementById('FNAME').value		   = info.name;
			document.getElementById('EMAIL').value		   = info.email;
			//document.getElementById('sn_image').value		   = info.sn_image;
			 $.post("fb_registered_submit.jsp?sn_image="+document.getElementById('sn_image').value+"&source="+document.getElementById('sn_source').value,{fullname:info.name,username:info.name,regemail:info.email,snImage:info.picture},function(data,status){
				 
				 try{
				 var chk = getCookie('itfacebook');
				 
				 if(chk!=undefined && chk!=null && chk!="" && document.getElementById('entername1').value!="" && document.getElementById('entername2').value!="") {
					 $('.popup,.overlay').hide();
					FB.ui({
								method: 'feed',
								name: 'I, '+document.getElementById('entername1').value+' take the oath along with new Delhi Chief Minister @ArvindKejriwal to '+document.getElementById('entername2').value,
								link: '/pledgewithCM/index.jsp',
								picture: 'http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/FB-share.png'/*,
								description: ''*/
							});
				 } else {
					setCookie('itfacebook','done', 7);
					//window.location.href="http://indiatoday.intoday.in/pledgewithCM/index.jsp"; 
					 $('.trans').hide();
			 		$('.popup,.overlay').hide();
				 }
				 }catch(err){}
				 /*alert("Data: " + data + "\nStatus: " + status);*/
			
			 
			 
			});
			
		//	document.getElementById('repFNAME').value		   = info.name;
		//	document.getElementById('repEMAIL').value		   = info.email;
			//document.getElementById("txtName").style.display = 'none';
		    //document.getElementById("txtEmail").style.display = 'none';
			//document.getElementById('user-text').style.marginLeft = '80px';
//			document.getElementById('message').style.width = '510px';
			//document.getElementById('authorize-button').style.display ="none";
		//	document.getElementById('please-text').style.display ="none";
		//	document.getElementById('linkedin').style.display ="none";
		//	document.getElementById('fill-details').style.display ="none";
			
	//		document.getElementById('repFNAME').type		   = "hidden";
	//		document.getElementById('repEMAIL').type		   = "hidden";
	//		document.getElementById("repName").style.display   = 'none';
	//		document.getElementById("repEmail").style.display  = 'none';
			
			//document.getElementById('RFNAME').type		   = "hidden";
	//		document.getElementById('REMAIL').type		   = "hidden";
			//document.getElementById('RFNAME').value		   = info.name;
	//		document.getElementById('REMAIL').value		   = info.email;
			document.getElementById('sn_image').value	   = 'https://graph.facebook.com/' + info.id + '/picture';
			document.getElementById('sn_source').value	   = 'facebook';
	//		document.getElementById('EMAIL-LOGIN').value		   = 'loginfacebook';				
			//document.getElementById('other').style.display = "block";
			
			//$.post("fb_registered_submit.jsp",{fullname:info.name,regemail:info.email},function(data,status){/*alert("Data: " + data + "\nStatus: " + status);*/
			 // $('.trans').hide();
			 // $('#popuplogin').hide();
			//});
			
			
		}
	}
	
	function logout(response){
		userInfo.innerHTML                             = "";
		//document.getElementById('debug').innerHTML     = "";
		//document.getElementById('other').style.display = "none";
		document.getElementById("facebook").style.backgroundImage="url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/education/sign-fb.png)";
		document.getElementById('FNAME').value		   = "";
		document.getElementById('EMAIL').value		   = "";
		//document.getElementById('FNAME').type		   = "text";
		//document.getElementById('EMAIL').type	 	   = "text";
		//document.getElementById('RFNAME').value		   = "";
//		document.getElementById('REMAIL').value		   = "";
		//document.getElementById('RFNAME').type		   = "hidden";
//		document.getElementById('REMAIL').type		   = "hidden";
		document.getElementById('sn_image').value	   = "";
		document.getElementById('sn_source').value	   = "";
//		document.getElementById('repFNAME').value	   = "";
//		document.getElementById('repEMAIL').value	   = "";
//		document.getElementById('repFNAME').type	   = "text";
//		document.getElementById('repEMAIL').type	   = "text";
//		document.getElementById("repName").style.display   = 'block';
//		document.getElementById("repEmail").style.display  = 'block';
		//document.getElementById("txtName").style.display   = 'block';
		//document.getElementById("txtEmail").style.display  = 'block';
		//document.getElementById('user-text').style.marginLeft = '0px';
//		document.getElementById('message').style.width = '610px';
		//document.getElementById('authorize-button').style.display ="block";
	//	document.getElementById('please-text').style.display ="block";
	//	document.getElementById('linkedin').style.display ="block";
	//	document.getElementById('fill-details').style.display ="block";
	}	
	
		//stream publish method
	function streamPublish(name, description, hrefTitle, hrefLink, userPrompt){
	
		FB.ui(
		{
		
			method: 'stream.publish',
			message: '',
			attachment: {
				name: name,
				caption: '',
				description: (description),
				href: hrefLink
			},
			action_links: [
				{ text: hrefTitle, href: hrefLink }
			],
			user_prompt_message: userPrompt
		},
		function(response) {
		
		});

	}
	function showStream(){
		FB.api('/me', function(response) {
			//message = document.getElementById('message').value;
			message ="";
			streamPublish(location.href, message,'hrefTitle',location.href, "Share IndiaToday");
		});
	}

	function share(){
		
		var share = {
			method: 'stream.share',
			u: 'http://thinkdiff.net/'
		};

		FB.ui(share, function(response) { 
			
			console.log(response); 
		});
	}
	
</script>
<!--Face Book Api Ends -->




<link href="/staticpages/main/education/css/style-sheet.css" rel="stylesheet" type="text/css"> <script src="/staticpages/main/js/sitejs.js"></script>



<script type="text/javascript" src="http://learntoday.in/js/validate.js"></script>
<script type="text/javascript">
  $().ready(function(){
	  		//$('input[name=chTerms]').is(':checked');
      jQuery.validator.addMethod("alpha", function(name, element) {
    		name = name.replace(/\s+/g, "");
			return this.optional(element) || name.match(/^[a-zA-Z]*$/);}, "Please enter only alphabets");	

    $("#login-form").validate({
        rules:{
			"treatment-type[]":{required:true},
			"color-frequency[]":{required:true},
			"st-frequency[]":{required:true},
			"blow-frequency[]":{required:true},
			"problem-type[]":{required:true},
			
            email: {required:true,email:true},			
			password:{required:true},	
		},
		messages: {
			password: "Password is case-sensitive. Use 5 to 10 characters",
			email: "Please specify your email ID you are registered with"
		}
    }); 		
  });
  </script>
  <script type="text/javascript">
  $().ready(function(){
      jQuery.validator.addMethod("alpha", function(name, element) {
    name = name.replace(/\s+/g, "");
	return this.optional(element) || name.match(/^[a-zA-Z]*$/);}, "Please enter only alphabets");

    $("#register-form").validate({
        rules:{
			"treatment-type[]":{required:true},
			"color-frequency[]":{required:true},
			"st-frequency[]":{required:true},
			"blow-frequency[]":{required:true},
			"problem-type[]":{required:true},			
            username: {required:true},
			password1: {required: true, minlength: 5}, 
          	cpassword: { required: true, equalTo: "#password1", minlength: 5}, 
			regemail:{required:true, email:true},
			regphone:{ required: true, minlength: 10, digits: true},
			number:{required:true},
			//courses:{required:true},		 
        },
		messages: {
			username: "Please specify your name",
			password1: "Password is case-sensitive. Use 5 to 10 characters",
			cpassword: {required:"This must be the same as the password entered above",
						equalTo: "This must be the same as the password entered above"
			},
			regemail: "Please specify your email ID.",
			regphone:"Please specify your phone",
			number:"Please enter the code shown",
			//courses:"Please select a course"
		}
    });		
  });
  </script>  
  
  <!-- FORGOT PASSWORD PAGE START --->
 
<div id="userreg" class="registpopup" style="display:none;"> <div class="trans"></div> <div class="regpopbox fog">
 
<div style="position:absolute;z-index: 10; right:35px; top:-7px;"><a href="javascript:void(0);" id="cancelregpopup" class="trans"><img src="http://www.learntoday.in/images/close.png" class="close" border="0"></a></div>
	
   <div class="popmsg"></div>
	<div class="frmtitle">Forgot password</div>
    <form method=post action="checkemail.jsp" name="change-pwd-form" id="change-pwd-form" >
    	<div class="frmfielddiv">
        	<div class="label">Email:</div>
            <div class="inputfield">
            	<input type="email" name="email" id="email" value="" />  
            </div>
            <div class="clear"></div>
        </div>       
        <div class="frmfielddiv">
        	<div class="label">&nbsp;</div>
            <div class="inputfield">
            	<input type="submit" name="submit" id="submit" value="SUBMIT" />  
            </div>
            <div class="clear"></div>
        </div>
        
    </form>
    
    </div>    
</div> 

  <!-- FORGOT PASSWORD PAGE ENDS --->
  
   <!-- REGISTER SINGUP PAGE START --->
  
<div class="registpopup" style="display:none;">

<div class="regpopbox">

<div style="position:absolute;z-index: 10; right:35px; top:-7px;"><a href="javascript:void(0);" id="cancelregpopup" class="trans"><img src="http://www.learntoday.in/images/close.png" class="close" border="0"></a></div>

<div class="frmtitle">Sign up Learn Today</div> <div class="sign_up_byline">By signing up, you agree to Learn Today <a href="http://www.learntoday.in/terms.jsp">Terms &amp; Conditions</a></div> <div class="enrollfrm">Learn Today is the simplest way to skillup yourself</div>


</div>
</div>
  
   <!-- REGISTER SINGUP PAGE ENDS--->
   
   <!-- LOGIN PAGE START --->
  
<form method=post action="checkusername.jsp" name="login-form" id="login-form"  > <input type="hidden" name="file_ref" value="" /> <input type="hidden" name="paymentcourseid" value="" /> <input type="hidden" name="validity" value="" /> </form> <div class="popup">
  <h2>YOUR OATH</h2>
  <div class="login-area">
  <div id="user-info" style="display:none"></div>
  	<span>Sign in with</span>
    
    <ul class="social-boom">
         <li id="fb_button" ><img  id="fb-auth" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/FB_icon.png"  /></li>                                  
 
    	<!--<li id="authorize-button"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/Googlr.png" id="googleplus" /></li>-->
     </ul>
     

                    
  </div>
  <br>
          <input type="hidden" id="sn_image" name="sn_image" value="" />
				<input type="hidden" id="sn_source" name="sn_source" value="signup" />
  
  
         <form action="save_user.jsp" method="post" name="dcm" ONSUBMIT="return validate()" id="register-form" >
             
         <div class="login-area">
   		<input name="FNAME" type="text" id="FNAME" class="input-box" placeholder="name">
        <input name="EMAIL" id="EMAIL" type="text" class="input-box" placeholder="email">
        <input name="mobile" type="text" class="input-box" placeholder="mobile">
      
        <input name="" type="submit" class="submit-btn"  value="SUBMIT">
        </div>
        </form>
        
      <div class="close">X</div>
        
   </div>
  
</div>





 <!-- Begin comScore Tag -->
<script >
  var _comscore = _comscore || [];
  _comscore.push({ c1: "2", c2: "8549097" });
  (function() {
    var s = document.createElement("script"), el = document.getElementsByTagName("script")[0];
    s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js";
    el.parentNode.insertBefore(s, el);
  })();
</script>
<noscript>
  <img src="http://b.scorecardresearch.com/p?c1=2&c2=8549097&cv=2.0&cj=1" /> </noscript>
<!-- End comScore Tag -->

	<script type="text/javascript" >
	var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
	document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
	</script>
	<script type="text/javascript">
	try {
	var pageTracker = _gat._getTracker("UA-795349-17");
	pageTracker._trackPageview();
	pageTracker._trackPageLoadTime();
	} catch(err) {}</script>

.

<div class="overlay"></div>
<div id="header">
  <div class="header">
    <div class="logo"><a href="#"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/ITG_LOGO.png" width="96" height="91" /></a></div>
    <div class="top-add"> 
      <!-- begin ZEDO for channel: IT Home Page Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 --> 
      <script language="JavaScript">
                var zflag_nid="821"; var zflag_cid="1138/1137"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
                </script> 
      <script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script> 
      <!-- end ZEDO for channel: IT Home Page Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 --> 
    </div>
  </div>
</div>
<div id="banner">
  <div class="banner"> </div>
</div>
<div id="container">
  <div class="conatiner">
 <div class="social-icons">
 	<a href="https://www.facebook.com/dialog/feed?app_id=613580381995012&display=popup&caption=&description=&link=/pledgewithCM/index.jsp&redirect_uri=/pledgewithCM/index.jsp&picture=http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/FB-share.png" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/FB.png" width="78" height="81" border="0"></a>
    <a href="http://twitter.com/?status=/pledgewithCM/index.jsp%20via%20%40indiatoday" target="_blank"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/Twitter.png" width="78" height="81" border="0"></a>
        <a href="https://plus.google.com/share?url=/pledgewithCM/index.jsp" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/Google.png" width="78" height="81" border="0"></a>
   
 </div>
  
    <div class="left-section">
      <div class="video">
      <iframe width="660" height="371" src="https://www.youtube.com/embed/5VKWx1dOYjQ" frameborder="0" allowfullscreen></iframe>
      </div>
    </div>
    <div class="right-section">
      <div class="pledge-meter">
        <h2>PLEDGE METER</h2>
        <div class="count">
         <span>
        
      
       
       <em class="firstem">0</em>
       
       
        <em>0</em>
       
       
        <em>1</em>
       
       
        <em>6</em>
       
       
        <em>2</em>
       
       
       </span>
    
        
        </div>
      <!--  <ul class="count">
          <li><a href="#">0</a></li>
          <li><a href="#">0</a></li>
          <li><a href="#">2</a></li>
          <li><a href="#">5</a></li>
          <li><a href="#">7</a></li>
        </ul>-->
      </div>
      <div class="right-add"> 
        <script language="JavaScript">
                    var zflag_nid="821"; var zflag_cid="1218/1137"; var zflag_sid="2"; var zflag_width="300"; var zflag_height="250"; var zflag_sz="9";
                    </script> 
        <script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script> 
      </div>
    </div>
    <div class="clr"></div>
    <div class="oth-pledge">
      <h2><span>TAKE THE</span> OATH HERE</h2>
      <div class="oth-container"> I,
        <input type="text" id="entername1" name="naentername1" />
        take the oath along with new Delhi Chief Minister <span>@ArvindKejriwal</span> to    <input type="text" id="entername2" name="naentername2" /></div>
      <div class="pledge-button">
        <input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/arvind/Pledge_buton.gif" />
      </div>
    </div>
    <div class="janta-pledge">
      <h2><span>PEOPLE WHO HAVE </span> ALREADY  TAKEN THE PLEDGE</h2>
       <ul class="pledge-list">
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000505966523/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002336195221/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100001158114332/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/555663636/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/1844633631/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000243949268/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000859720217/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002910444572/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002593513775/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100001333780000/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/1453850831/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100008132075783/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/1679260710/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002279114806/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000850229029/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/1825306916/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100001056020706/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000139069710/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002530768413/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100001444226039/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000088598978/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002271616099/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002229916116/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002111784635/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100001249472826/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100002271597876/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000605230726/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100006848446235/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100001330829005/picture" width="50" height="39" /></div>
        </li>
      
      
           
           
     
        <li>
          <div class="box"><img src="https://graph.facebook.com/100000506404555/picture" width="50" height="39" /></div>
        </li>
      
        
      </ul>
      
            
    </div>
  </div>
</div>
<!--container end-->
<div class="clr"></div>

<div id="footer-bg">
<div class="footertag"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/btm-logo.jpg" height="43" border="0" style="float:left;" class="btm-itlogo">
  <nav class="nav">
    <ul>
      <div class="home" style="background:none"><a href="/index.jsp"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/home-cion.jpg" height="43" border="0"></a></div>
      <li><a href="/news.html" class="nav_padding">News</a></li>
      <li><a href="/section/114/1/india.html" class="nav_padding">India</a> </li>
      <li><a href="/section/113/1/world.html" class="nav_padding">World</a> </li>
      <li><a href="/videos" class="nav_padding">Videos</a></li>
      <li><a href="/galleries" class="nav_padding">Photos</a></li>
      <li><a href="/section/214/1/cricket.html" class="nav_padding">Cricket</a></li>
      <li><a href="/section/67/1/movies.html" class="nav_padding">Movies</a></li>
      <li><a href="/section/230/1/auto.html" class="nav_padding">Auto</a></li>
      <li><a href="/section/84/1/sports.html" class="nav_padding">Sports</a></li>
      <li><a href="/section/103/1/lifestyle.html" class="nav_padding">Lifestyle</a></li>
      <li><a href="/technology" class="nav_padding">Tech</a></li>
      <li><a href="/education" class="nav_padding">Education</a></li>
      <li><a href="http://businesstoday.intoday.in/" target="_blank" class="nav_padding">business</a></li>
    </ul>
    <div class="clear"></div>
  </nav>
  <div>
</div>
  
    <div id="footer1" style="display:block !important">
      <iframe width="98%" scrolling="no" height="170" frameborder="0" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/common/common_it_footer.html"></iframe>
    </div>
  </div>
</div>



</body>
</html>
