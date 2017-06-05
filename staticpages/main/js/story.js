function Open_win(uv,utwidth, utheight) {
	var remoteWin = null;
	var params;
	params = "toolbar=0,location=0,directories=0,status=0,scrollbars=1,scrolling=1,resizable=0,menubar=0,width="+utwidth+",height="+utheight+" ";
	remoteWin = window.open("","colorpicker",params);
	remoteWin.location.href = uv;     
}

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



function fnValidate() {
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

function Open(id) {
	document.getElementById(id).style.display = "block";
}
function Close(id) {
	document.getElementById(id).style.display = "none";
}