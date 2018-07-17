function isEmail(email){
	  if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(email)){
		return (true);
	}
	return (false);
}
function loadCaptchaImg(){
//	document.getElementById('captcha').setAttribute('src', //"http://indiatoday.intoday.in/applications/img.jsp?id="+Math.random());
}
function IsNumeric(strString)
{
   var strValidChars = "0123456789";
   var strChar;
   var blnResult = true;
   if (strString.length === 0)
   {
   	return false;
   }
   //  test strString consists of valid characters listed above
   for (i = 0; i < strString.length && blnResult == true; i++)
   {
      strChar = strString.charAt(i);
      if (strValidChars.indexOf(strChar) == -1)
      {
         blnResult = false;
	  }
   }
   	  return blnResult;
}
function numchk(a)  /* onkeypress=\"Javascript:return numchk(this);\ */
{ 
	document.getElementById('phone_err').innerHTML="";
	if ((event.keyCode<48) || (event.keyCode>57))
	{
		//event.keyCode=false;
		document.getElementById('phone_err').innerHTML="Please enter numeric value only.";
		//a.value = '';
		a.focus();
		return false;
	}
}

function validate(){
	document.getElementById('name_err').innerHTML="";
	document.getElementById('email_err').innerHTML="";
	document.getElementById('phone_err').innerHTML="";
	//document.getElementById('captcha_err').innerHTML="";
	var name		=	document.getElementById("name").value;
	var email		=	document.getElementById("email").value;
	var phone		=	document.getElementById("phone").value;
	//var captchaval	=	document.getElementById("captchaval").value;
	var len 	   	= 	document.getElementById("phone").value.length;
	var source		=	document.getElementById("source").value;
	var first_char	= 	document.getElementById("phone").value.substr(0,1);
	var chartest	= 	/^([a-zA-Z]+\s)*[a-zA-Z]+$/;
	
	if(name=='')
	{
		//alert('Please enter name.');
		document.getElementById('name_err').innerHTML="Please enter name.";
		document.getElementById("name").focus();
		return false;
	}
	else
	if(!chartest.test(name))
	{
		document.getElementById('name_err').innerHTML="Do not use special characters in name.";	
		document.getElementById("name").focus();
		return false;
	}
	else 
	if(email=='')
	{
		document.getElementById('email_err').innerHTML="Please enter email.";	
		document.getElementById("email").focus();
		return false;
	}
	else
	if(isEmail(email)==false)
	{
		document.getElementById('email_err').innerHTML="Please enter your E-mail address correctly.";
		document.getElementById("email").focus();
		return false;
	}
	else 
	if(phone=='')
	{
		document.getElementById('phone_err').innerHTML="Please enter phone number.";	
		document.getElementById("phone").focus();
		return false;
	}
	else
	if(len<10)
	{
		document.getElementById('phone_err').innerHTML="Please enter 10 digit phone number.";	
		document.getElementById("phone").focus();
		return false;
	}
	else
	if(IsNumeric(phone)===false) {
		document.getElementById('phone_err').innerHTML="Please enter numeric value for contact number.\nFor mobile, E.g., 9892xxxxxx.";
		document.getElementById("phone").focus();
		return false;
	}
	else 
	if(first_char == 0 || first_char == "")
	{
		document.getElementById('name_err').innerHTML="Please enter a correct 10-digit contact number. Mobile number can not start with zero.";
		document.getElementById("phone").focus();
	    return false;
	}
	//else 
//	if(captchaval=='')
//	{
//		document.getElementById('captcha_err').innerHTML="Please enter captcha.";	
//		document.getElementById("captchaval").focus();
//		return false;
//	}
	else
	{
		$.ajax({
					type:"POST",
					url:"/applications/mobile_msg.jsp",
					data: {    
						//capval:captchaval,
						name:name,
						email:email,
						phone:phone,
						source:source
						},
					success:function(bckk)
					{		
						//alert("bckk before if==>>"+bckk);
						if(bckk.match("correct"))
						{
							     
							//alert(bckk);    
							
						} 
						else 
						{
							alert("Thank You for your interest.");
							
						}
					},
					error:function(bckk)
					{
						
					}
				});
	}
	return false;
	
	
}