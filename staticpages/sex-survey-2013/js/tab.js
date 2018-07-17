function changeMustWatch( name, arg, total_arg){
	
	for (var i=1;i <= total_arg;i++){
		if(i == arg ){
			document.getElementById( name+i+"_0").style.display="block";
			document.getElementById( name+i+"_1").style.display="none";
		}
		else{
			document.getElementById( name+i+"_0").style.display="none";
			document.getElementById( name+i+"_1").style.display="block";
		}
	}
}

function validateForm()
{
var z=document.forms["mailer"]["textMessage"].value;
var x=document.forms["mailer"]["textName"].value;
var y=document.forms["mailer"]["textEmail"].value;
var a=document.forms["mailer"]["key"].value;
	
var atpos=y.indexOf("@");
var dotpos=y.lastIndexOf(".");



if (x==null || x=="")
  {
  alert("Please Enter Your Name");
  return false;
  }

if (atpos<1 || dotpos<atpos+2 || dotpos+2>=y.length)
  {
  alert("Not a valid e-mail address");
  return false;
  }
if (z==null || z=="")
  {
  alert("Please post your comments");
  return false;
  }
  if (a==null || z=="" || a=="null")
  {
  alert("Please enter the code");
  return false;
  }
}