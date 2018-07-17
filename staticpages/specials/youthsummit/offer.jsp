



<!DOCTYPE HTML PUBLIC "-//SoftQuad//DTD HoTMetaL PRO 4.0::19971010::extensions to HTML 4.0//EN"
 "hmpro4.dtd">

<HTML>

  <HEAD>
   <script type="text/javascript">

	function cemail(val){
		if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(val.value)){
		return (true)
		}
		return false;
		}

    function ajaxFunction(){
		var frm=document.feedback;
		if(frm.FNAME.value=="")
		{
		  alert("Please enter First Name");
		  frm.FNAME.focus();
		  return false;
		}

		if (frm.FNAME.value!="") {
				var alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
						for (var i=0;i<frm.FNAME.value.length;i++){
							temp=frm.FNAME.value.substring(i,i+1);
							if (alp.indexOf(temp)==-1){
								alert("First name should accept only alphabets[a-z,A-Z]");
								frm.FNAME.focus();
								return false;
							}
						}
		    	}


		if(frm.EMAIL.value=="")
		{
		  alert("Please enter Email Id");
		  frm.EMAIL.focus();
		  return false;
		}
		if(cemail(frm.EMAIL)==false)
			{
					alert( "Please enter valid email ID" );
					frm.EMAIL.focus();
					return false;
			}


		if(frm.PHONE.value=="")
		{
		  alert("Please enter your phone number");
		  frm.PHONE.focus();
		  return false;
		}
		if(frm.MOBILE.value=="")
		{
		  alert("Please enter your mobile number");
		  frm.MOBILE.focus();
		  return false;
		}
		if(frm.COMPNAME.value=="")
		{
		  alert("Please enter your company name");
		  frm.COMPNAME.focus();
		  return false;
		}
		if(frm.message.value=="")
		{
		  alert("Please enter your requirements");
		  frm.message.focus();
		  return false;
		}

		 if(frm.number.value=="")
			{
				alert( "Please Enter the  Code" );
				frm.number.focus();
				return false;
			}
		frm.submit();
}

    </script>
    <TITLE>Combo offer - Print or Web images @ FLAT 20% Discount - Syndications
    Today</TITLE>
    <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=iso-8859-1">
    <LINK HREF="stylesheet.css" REL="stylesheet" TYPE="text/css">
  </HEAD>

  <BODY BGCOLOR="#221414" LEFTMARGIN="0" TOPMARGIN="0">

<!-- ImageReady Slices (3.psd) -->

     <form name="feedback" action="offer_thanks.jsp" method="post" onSubmit="javascript:return ajaxFunction()">
    <TABLE WIDTH="1003" BORDER="0" CELLPADDING="0" CELLSPACING="0"
    ALIGN="CENTER">
      <TR>
        <TD><IMG SRC="images/index_01.jpg" WIDTH="179" HEIGHT="219" ALT=""></TD>
        <TD><IMG SRC="images/index_02.jpg" WIDTH="251" HEIGHT="219" ALT=""></TD>
        <TD><IMG SRC="images/index_03.jpg" WIDTH="393" HEIGHT="219" ALT=""></TD>
        <TD><IMG SRC="images/index_04.jpg" WIDTH="180" HEIGHT="219" ALT=""></TD>
      </TR>
      <TR>
        <TD><IMG SRC="images/index_05.jpg" WIDTH="179" HEIGHT="130" ALT=""></TD>
        <TD><IMG SRC="images/index_06.jpg" WIDTH="251" HEIGHT="130" ALT=""></TD>
        <TD><IMG SRC="images/index_07.jpg" WIDTH="393" HEIGHT="130" ALT=""></TD>
        <TD><IMG SRC="images/index_08.jpg" WIDTH="180" HEIGHT="130" ALT=""></TD>
      </TR>
      <TR>
        <TD COLSPAN="2"><IMG SRC="images/index_09.jpg" WIDTH="430" HEIGHT="36" ALT=""></TD>
        <TD COLSPAN="2" BACKGROUND="images/index_10.jpg"><INPUT TYPE="TEXT" NAME="FNAME" SIZE="42" CLASS="tour-en"> </TD>
      </TR>
      <TR>
        <TD COLSPAN="4"><IMG SRC="images/index_11.jpg" WIDTH="1003" HEIGHT="25" ALT=""></TD>
      </TR>
      <TR>
        <TD COLSPAN="2"><IMG SRC="images/index_12.jpg" WIDTH="430" HEIGHT="35" ALT=""></TD>
        <TD COLSPAN="2" BACKGROUND="images/index_13.jpg"><INPUT TYPE="TEXT" NAME="EMAIL" SIZE="42" CLASS="tour-en"></TD>
      </TR>
      <TR>
        <TD COLSPAN="4"><IMG SRC="images/index_14.jpg" WIDTH="1003" HEIGHT="27" ALT=""></TD>
      </TR>
      <TR>
        <TD COLSPAN="2"><IMG SRC="images/index_15.jpg" WIDTH="430" HEIGHT="34" ALT=""></TD>
        <TD COLSPAN="2" BACKGROUND="images/index_16.jpg"><INPUT TYPE="TEXT" NAME="PHONE" SIZE="42" CLASS="tour-en"></TD>
      </TR>
      <TR>
        <TD COLSPAN="4"><IMG SRC="images/index_17.jpg" WIDTH="1003" HEIGHT="27" ALT=""></TD>
      </TR>
      <TR>
        <TD COLSPAN="2"><IMG SRC="images/index_18.jpg" WIDTH="430" HEIGHT="34" ALT=""></TD>
        <TD COLSPAN="2" BACKGROUND="images/index_19.jpg"><INPUT TYPE="TEXT" NAME="MOBILE" SIZE="42" CLASS="tour-en"></TD>
      </TR>
      <TR>
        <TD COLSPAN="4"><IMG SRC="images/index_20.jpg" WIDTH="1003" HEIGHT="24" ALT=""></TD>
      </TR>
      <TR>
        <TD COLSPAN="2"><IMG SRC="images/index_21.jpg" WIDTH="430" HEIGHT="35" ALT=""></TD>
        <TD COLSPAN="2" BACKGROUND="images/index_22.jpg"><INPUT TYPE="TEXT" NAME="COMPNAME" SIZE="42" CLASS="tour-en"></TD>
      </TR>
      <TR>
        <TD COLSPAN="4"><IMG SRC="images/index_23.jpg" WIDTH="1003" HEIGHT="26" ALT=""></TD>
      </TR>
      <TR>
        <TD COLSPAN="2"><IMG SRC="images/index_24.jpg" WIDTH="430" HEIGHT="192" ALT=""></TD>
        <TD BACKGROUND="images/index_25.jpg" VALIGN="TOP">
        <DIV><TEXTAREA NAME="message" ROWS="4" COLS="42" CLASS="tour-en1"></TEXTAREA></DIV><BR>
         <DIV><INPUT TYPE="TEXT" NAME="number" SIZE="15" CLASS="tour-en"> <img src="img.jsp" /></DIV><BR>
        <DIV><INPUT TYPE="IMAGE" NAME="Image1" SRC="images/submit.gif"></DIV></TD>
        <TD><IMG SRC="images/index_26.jpg" WIDTH="180" HEIGHT="192" ALT=""></TD>
      </TR>
      <TR>
        <TD><IMG SRC="images/index_27.jpg" WIDTH="179" HEIGHT="132" ALT=""></TD>
        <TD><IMG SRC="images/index_28.jpg" WIDTH="251" HEIGHT="132" ALT=""></TD>
        <TD><IMG SRC="images/index_29.jpg" WIDTH="393" HEIGHT="132" ALT=""></TD>
        <TD><IMG SRC="images/index_30.jpg" WIDTH="180" HEIGHT="132" ALT=""></TD>
      </TR>
    </TABLE></FORM>

<!-- End ImageReady Slices -->


  </BODY>
</HTML>
