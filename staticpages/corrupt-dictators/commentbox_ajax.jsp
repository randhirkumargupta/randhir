<script src="http://indiatoday.intoday.in/js/story.js" type="text/javascript"></script>
<script type='text/javascript' src='http://ajax.googleapis.com/ajax/libs/jquery/1.4/jquery.min.js'></script>

<script>
  $(document).ready(function(){
    $('.submit_button').click(function(){
      if (ChkBlank("userDetails.FNAME","Please enter Name") == false) {
        return false;
      }
      if (ChkBlank("userDetails.Location","Please enter place") == false) {
        return false;
      }
      if (ChkBlank("userDetails.EMAIL","Please enter your email ID") == false) {
        return false;
      }
      if (ChkEmail("userDetails.EMAIL","Please enter valid email ID") == false) {
        return false;
      }
      if (ChkBlank("userDetails.message","Please enter your comment") == false) {
        return false;
      }
      if (ChkBlank("userDetails.number","Please enter the code") == false) {
        return false;
      }
      var fullform = $('#userDetails').serialize();
      //alert(fullform);

      $.ajax({
          type:"POST",
          url:"http://indiatoday.intoday.in/commentbox_ajax_save.jsp",
          data: fullform,
          success:function(bckk){
            alert(bckk);
            if(bckk.match("Thanks"))
              document.userDetails.reset();
          },
          error:function(bckk){
            alert('Please reload the page and try again');
          }
        });
    });
  });
</script>

<style>
  .commentitle{ font:12px/22px arial;}
  .commentfrm .textbox{ height:20px;}
  body{background-color:transparent;}
.commentfrm input.submit_button {
    background: url("http://indiatoday.intoday.in/images/btn_image.png") repeat scroll 0 0 transparent;
    border: medium none;
    cursor: pointer;
    float: left;
    height: 21px;
    margin: 0;
    padding: 0;
    width: 67px;
}
.commentfrm {
    color: #FFFFFF;
    font: bold 14px arial;
    text-align: left;
}input, textarea, select, button {
    font-family: Arial,Helvetica,sans-serif;
    font-size: inherit;
    font-weight: inherit;
}
</style>
<form method="post" name="userDetails" id="userDetails" action="" onsubmit="return false;">
<table width="280" cellspacing="0" cellpadding="0" border="0" align="left" class="commentfrm frm_outer">
<a name="comment"></a>

  <input name="ac_contentid" value="0" type="hidden" />
  <input name="ac_slideid" value="0" type="hidden" />
  <input name="ac_contenttype" value="" type="hidden" />
  <input name="ac_source" value="" type="hidden" />
  <input name="ac_sourceurl" value="" type="hidden" />
  <input name="ac_contenttitle" value="" type="hidden" />
  <input name="disp_email" value="0" type="hidden" />

  <tr><td align="left" colspan="2"><img align="absmiddle" class="postimg" src="http://indiatoday.intoday.in/site/static/post-comment_icon.gif"><strong style="padding-left: 10px">Post your comments</strong></td></tr>
  <tr><td colspan="2">&nbsp;</td></tr>
  <tr><td colspan="2" align="left" class="commentitle">Comment:</td></tr>
  <tr><td colspan="2"><label><textarea name="message" style=" width:280px;"></textarea></label></td></tr>
  <tr><td height="11" colspan="2" align="left"></td></tr>
  <tr><td width="90" align="left" class="commentitle">Name :</td><td valign="middle" align="right"><input type="text" name="FNAME" style=" width:185px;" class="textbox"></td></tr>
  <tr><td height="3" colspan="2" align="left"></td></tr>
  <tr><td align="left" class="commentitle">Place :</td><td  valign="middle" align="right"><input type="text" style=" width:185px;" name="Location" class="textbox"></td></tr>
  <tr><td height="3" colspan="2" align="left"></td></tr>
  <tr><td align="left" class="commentitle">E-mail :</td><td  valign="middle" align="right"><input type="text" style=" width:185px;" name="EMAIL" class="textbox"></td></tr>
  <tr><td height="5" colspan="2"></td></tr>
  <tr><td valign="top" align="left" colspan="2"><table width="100%" cellpadding="0" cellspacing="0" class="commentfrm" border="0">
  <tr><td valign="middle" class="commentitle">Enter the Code Shown:</td>
  <td><img align="absmiddle" src="http://indiatoday.intoday.in/img.jsp?uniqueRandomId=3fed7dfadcb8db21" style="margin:0 6px;"> <input type="text" size="4" name="number"></td>
    </tr><tr>
    <td colspan="2">  <input type="submit" name="send" id="send" value="" class="submit_button"></td>
  </tr></table></td></tr>

  </table></form>



