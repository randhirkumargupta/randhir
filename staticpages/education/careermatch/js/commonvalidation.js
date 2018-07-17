/**
 *	This function validate the fields and their value at the time of registration 
 * If all field have correct value, return true; otherwise false.
 */
function validatefields() {
	var flag = true;
	var userNameVal = document.registerform.userName.value;
	var userEmailVal = document.registerform.userEmail.value;
	var userPwdVal = document.registerform.password.value;
	var userCnfrmPwdVal = document.registerform.confirmPassword.value;
	var expression = /^([0-9]|[a-z])+([0-9a-z]+)$/i;
	
	if(userNameVal == undefined || userNameVal == ""){
		document.getElementById("userNameErr").innerHTML = 'Please specify your name.';
		document.getElementById("userNameErr").style.display = 'block';
		flag = false;
	} else if(userNameVal != undefined && userNameVal != ""){
		if(!userNameVal.match(expression)) {
			document.getElementById("userNameErr").innerHTML = 'Name is not alphanumeric.';
			document.getElementById("userNameErr").style.display = 'block';
			flag = false;
		} else {
			document.getElementById("userNameErr").innerHTML = '';
			document.getElementById("userNameErr").style.display = 'none';
		}
	}else {
		document.getElementById("userNameErr").innerHTML = '';
		document.getElementById("userNameErr").style.display = 'none';
	}
	if(userEmailVal == undefined || userEmailVal == ""){
		document.getElementById("emailErr").innerHTML = 'Please specify your email ID.';
		document.getElementById("emailErr").style.display = 'block';
		flag = false;
	} else if (userEmailVal != undefined && userEmailVal != "") {
		var atPos = userEmailVal.indexOf("@");
		var dotPos = userEmailVal.indexOf(".");
		
		if(atPos < 1 || dotPos < atPos+2 || dotPos+2 >= userEmailVal.length){
			document.getElementById("emailErr").innerHTML = 'Not a valid e-mail address.';
			document.getElementById("emailErr").style.display = 'block';
			flag = false;
		} else {
			document.getElementById("emailErr").innerHTML = '';
		}
	}else {
		document.getElementById("emailErr").style.display = 'none';
	}
	if(userPwdVal == undefined || userPwdVal == ""){
		document.getElementById("pwdErr").innerHTML = 'Password is required.';
		document.getElementById("pwdErr").style.display = 'block';
		flag = false;
	} else if(userPwdVal > 10 || userPwdVal < 5) {
		document.getElementById("pwdErr").innerHTML = 'Password is case-sensitive. Use 5 to 10 characters.';
		document.getElementById("pwdErr").style.display = 'block';
		flag = false;
	}else {
		document.getElementById("pwdErr").innerHTML = '';
		document.getElementById("pwdErr").style.display = 'none';
	}
	if(userPwdVal != userCnfrmPwdVal){
		document.getElementById("cnfmPwdErr").innerHTML = 'This must be the same as the password entered above.';
		document.getElementById("cnfmPwdErr").style.display = 'block';
		flag = false;
	}  else {
		document.getElementById("cnfmPwdErr").innerHTML = '';
		document.getElementById("cnfmPwdErr").style.display = 'none';
	}
	
	if(flag) {
		var resgisterForm = $("#register-form").serialize();
		$.ajax({
			type : "POST",
			url  : "registration.jsp",
			data : resgisterForm,
			success:function(returnData){
				var getResponseValue = returnData;
				var response = getResponseValue.split("-");
				if(response[0] != null && response[0] != undefined && response[0].trim() == "FAIL"){
					$('.popup-sign-up').show();
					$('#successMsgId').hide();
					document.getElementById("errorsMsgId").innerHTML = response[1].trim();
					$('#errorsMsgId').show();
					document.registerform.password.value = '';
					document.registerform.confirmPassword.value = '';
				} else if(response[0] != null && response[0] != undefined && response[0].trim() == "SUCCESS"){
					$('#errorsMsgId').hide();
					$('#successMsgId').show();								
				}
			},
			error:function(){
				$('.popup-sign-up').show();
				$('#errorsMsgId').show();
			}
		});
	}
}
/**
 *	This function validate the login input, whether the user is authorised to logged-in into system 
 *  Showing error, if either login-id or password is in-correct.
 *  @param siteUrl
 */
function validatelogin(siteUrl) {
	var loginForm = $("#login-form").serialize();
	$.ajax({
		type	:	"POST",
		url		:	"checkusername.jsp",
		data	:	loginForm,
		success	:	function(loginData){
			var returnedRes = loginData;
			if(returnedRes.trim() == "FAIL"){
				$('#loginMsgId').show();
			} else {
				setTimeout(function (){
					window.location.href = siteUrl+"careermatch/personalitytest.jsp";
				}, 900);
			}
		},
		error	: 	function(loginData) {
		}
	});
}
/**
 *	This function validate the registered email is valid or not. 
 *  If email-id is valid, password send into mail; otherwise populate error on related popup.
 */
function forgotpassword(){
	var forgotForm = $("#forgotPassword").serialize();
	$.ajax({
		type	:	"POST",
		url		:	"forgotpassword.jsp",
		data	:	forgotForm,
		success	:	function(returnForgotData) {
			var returnRes = returnForgotData;
			if(returnRes.trim() == "FAIL") {
				document.getElementById("failPwdId").style.display = 'block';
				document.getElementById("successPwdId").style.display = 'none';
			} else {
				document.getElementById("failPwdId").style.display = 'none';
				document.getElementById("successPwdId").style.display = 'block';
			}
		},
		error	:	function(returnForgotData){
		}
	});
}