function isCheckDelegate(valueGet)
{
var disp = document.getElementById("displayCCV");
if(valueGet==2)
{

document.conclave.ccNumber.value="";
disp.style.display="block";
return true;
}

else 
{

document.conclave.ccNumber.value="";
disp.style.display="none";	
return true;
}
}

function isCheckEarlyBird(valueGet)
{
var disx = document.getElementById("displayEarlyBird");
if(valueGet==2)
{

document.conclave.noEarlyBird.value="";
disx.style.display="block";
return true;
}

else 
{
document.conclave.noEarlyBird.value=1;
disx.style.display="none";	
return true;
}
}



function isEmail(email){
if (document.conclave.email.value.indexOf("@") != "-1" &&
document.conclave.email.value.indexOf(".") != "-1" )
return true;
else return false;
}
function checking(v)
{
var str=/[a-zA-Z]+/;
return str.test(v);

}
function telephone_check()
{
var vl=document.conclave.phone.value;
if(checking(vl))
{
alert("Please enter telephone in digits only");
document.conclave.phone.focus();
return false;
}
}

function conclave_check()
{
if(document.conclave.first_name.value=="")
{
alert("Please enter first name ");
document.conclave.first_name.focus();
return false;
}
else
if(document.conclave.last_name.value=="")
{
alert("Please enter last name ");
document.conclave.last_name.focus();
return false;
}
else
if(document.conclave.designation.value=="")
{
alert("Please enter your designation ");
document.conclave.designation.focus();
return false;
}
else
if(document.conclave.company.value=="")
{
alert("Please enter your company name  ");
document.conclave.company.focus();
return false;
}
else
if (isEmail(document.conclave.email.value) == false)
{
alert("Please enter your e-mail address correctly ")
document.conclave.email.focus()
return false
}
else
if(document.conclave.phone.value=="")
{
alert("Please enter your phone number ");
document.conclave.phone.focus();
return false;
}
if(document.conclave.mobile.value=="")
{
alert("Please enter your mobile number ");
document.conclave.mobile.focus();
return false;
}

else
if(document.conclave.address.value=="")
{
alert("Please enter your mailing address  ");
document.conclave.address.focus();
return false;
}
else
if(document.conclave.city.value=="")
{
alert("Please enter your city  ");
document.conclave.city.focus();
return false;
}

else
if(document.conclave.country.options[document.conclave.country.selectedIndex].value =="")
{
alert("Please select your country  ");
document.conclave.country.focus();
return false;
}
/*else
if(document.conclave.delegate[2].checked && document.conclave.noEarlyBird.value=="")
{
alert("Please enter number of delegates");
document.conclave.noEarlyBird.focus();
return false;
}
else
if(document.conclave.delegate[2].checked && document.conclave.noEarlyBird.value<=1)
{
alert("Please enter two or more delegates");
document.conclave.noEarlyBird.focus();
return false;
}
else if((document.conclave.noEarlyBird.value!="") && (isNaN(document.conclave.noEarlyBird.value)))
{
alert("Delegates members should be in numeric");
document.conclave.noEarlyBird.focus();
return false;
}
*/

else if(document.conclave.number.value=="")
{
alert("Please Enter Code ");
document.conclave.number.focus();
return false
}
}
// JavaScript Document
