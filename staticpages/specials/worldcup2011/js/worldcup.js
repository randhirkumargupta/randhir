// JavaScript Document
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
			
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit_latest.jsp?sid="+document.poll.sid.value+"&answer="+answer+"&pid="+document.poll.pid.value+"";
		var popupHeight = 350;
		var popupWidth = 460;
		var popupTop =  (window.screen.availHeight - popupHeight)/2;
		var popupLeft = (window.screen.availWidth - popupWidth)/2;
		
		var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
		
		//return true;
	}
}

function onShow(siteId,pollId)
{
	
	var strURL = "http://specials.indiatoday.com/specials/bt_event/showResult_new.jsp?pid="+pollId+"&sid="+siteId;
	var popupHeight = 350;
	var popupWidth = 460;
	var popupTop =  (window.screen.availHeight - popupHeight)/2;
	var popupLeft = (window.screen.availWidth - popupWidth)/2;
	
	var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
	
	return true;
}

function toggle2(theDiv4,theDiv5) {
     var elem = document.getElementById(theDiv4);
	   		var elem4 = document.getElementById("wcmaillead1");
		 	var elem5 = document.getElementById("wcmaillead2");
	     	var elem6= document.getElementById("wcmaillead3");
			var elem7= document.getElementById("wcmaillead4");
		 elem4.style.display="none";
		 elem5.style.display="none";
		 elem6.style.display="none";
		 elem7.style.display="none";
		 document.getElementById("lead1").className ='lead_nothighlighted';
		 document.getElementById("lead2").className ="lead_nothighlighted";
		 document.getElementById("lead3").className ="lead_nothighlighted";
		 document.getElementById("lead4").className ="lead_nothighlighted";
		elem.style.display="block";
		document.getElementById(theDiv5).className= "lead_highlighted";
	}
	
	 function toggle3(id1,id2,id3) {
         var elem = document.getElementById(id1);
         var elem1 = document.getElementById("key_player");
         var elem2 = document.getElementById("team_player");
         elem1.style.display="none";
         elem2.style.display="none";
         document.getElementById("need1").className ='tab_nothighlighted';
         document.getElementById("need2").className ="tab_nothighlighted";
         document.getElementById("d").className ='tabtext_nothighlight';
         document.getElementById("e").className ="tabtext_nothighlight";
         elem.style.display="block";
         document.getElementById(id2).className= "tab_highlighted";
         document.getElementById(id3).className= "tabtext_highlight";
        } 		
	
function group_toggle(id1,id2,id3) {
	var elem = document.getElementById(id1);
	var elem1 = document.getElementById("group_a");
	var elem2 = document.getElementById("group_b");
	elem1.style.display="none";
	elem2.style.display="none";
	document.getElementById("group1").className ='tab_nothighlighted';
	document.getElementById("group2").className ="tab_nothighlighted";
	document.getElementById("a").className ='tabtext_nothighlight';
	document.getElementById("b").className ="tabtext_nothighlight";
	elem.style.display="block";
	document.getElementById(id2).className= "tab_highlighted";
	document.getElementById(id3).className= "tabtext_highlight";
} 
	
		function bgimagechange300_over(idnew) 

            {

                        document.getElementById(idnew).className= "chunkheader_310_top_mover";

            }

            

function bgimagechange300_out(idnew) 

            {

                        document.getElementById(idnew).className= "chunkheader_310_top";

            }

 

function bgimagechange335_over(idnew) 

            {

                        document.getElementById(idnew).className= "chunkheader_345_top_mover";

            }

            

function bgimagechange335_out(idnew) 

            {

                        document.getElementById(idnew).className= "chunkheader_345_top";

            }


var rootdomain="http://"+window.location.hostname

function ajaxinclude(url) {
var page_request = false
if (window.XMLHttpRequest) // if Mozilla, Safari etc
page_request = new XMLHttpRequest()
else if (window.ActiveXObject){ // if IE
try {
page_request = new ActiveXObject("Msxml2.XMLHTTP")
} 
catch (e){
try{
page_request = new ActiveXObject("Microsoft.XMLHTTP")
}
catch (e){}
}
}
else
return false
page_request.open('GET', url, false) //get page synchronously 
page_request.send(null)
writecontent(page_request)
}

function writecontent(page_request){
if (window.location.href.indexOf("http")==-1 || page_request.status==200)
document.write(page_request.responseText)
}


var cssdropdown={
disappeardelay: 250, //set delay in miliseconds before menu disappears onmouseout
dropdownindicator:'', //specify full HTML to add to end of each menu item with a drop down menu
enableswipe: 1, //enable swipe effect? 1 for yes, 0 for no
enableiframeshim: 1, //enable "iframe shim" in IE5.5/IE6? (1=yes, 0=no)

//No need to edit beyond here////////////////////////

dropmenuobj: null, asscmenuitem: null, domsupport: document.all || document.getElementById, standardbody: null, iframeshimadded: false, swipetimer: undefined, bottomclip:0,

getposOffset:function(what, offsettype){
	var totaloffset=(offsettype=="left")? what.offsetLeft : what.offsetTop;
	var parentEl=what.offsetParent;
	while (parentEl!=null){
		totaloffset=(offsettype=="left")? totaloffset+parentEl.offsetLeft : totaloffset+parentEl.offsetTop;
		parentEl=parentEl.offsetParent;
	}
	return totaloffset;
},

swipeeffect:function(){
	if (this.bottomclip<parseInt(this.dropmenuobj.offsetHeight)){
		this.bottomclip+=10+(this.bottomclip/10) //unclip drop down menu visibility gradually
		this.dropmenuobj.style.clip="rect(0 auto "+this.bottomclip+"px 0)"
	}
	else
		return
	this.swipetimer=setTimeout("cssdropdown.swipeeffect()", 30)
},

css:function(el, targetclass, action){
	var needle=new RegExp("(^|\\s+)"+targetclass+"($|\\s+)", "ig")
	if (action=="check")
		return needle.test(el.className)
	else if (action=="remove")
		el.className=el.className.replace(needle, "")
	else if (action=="add" && !needle.test(el.className))
		el.className+=" "+targetclass
},

showhide:function(obj, e){
	this.dropmenuobj.style.left=this.dropmenuobj.style.top="-500px"
	if (this.enableswipe==1){
		if (typeof this.swipetimer!="undefined")
			clearTimeout(this.swipetimer)
		obj.clip="rect(0 auto 0 0)" //hide menu via clipping
		this.bottomclip=0
		this.swipeeffect()
	}
	obj.visibility="visible"
	this.css(this.asscmenuitem, "selected", "add")
},

clearbrowseredge:function(obj, whichedge){
	var edgeoffset=0
	if (whichedge=="rightedge"){
		var windowedge=document.all && !window.opera? this.standardbody.scrollLeft+this.standardbody.clientWidth-15 : window.pageXOffset+window.innerWidth-15
		this.dropmenuobj.contentmeasure=this.dropmenuobj.offsetWidth
		if (windowedge-this.dropmenuobj.x < this.dropmenuobj.contentmeasure)  //move menu to the left?
			edgeoffset=this.dropmenuobj.contentmeasure-obj.offsetWidth
	}
	else{
		var topedge=document.all && !window.opera? this.standardbody.scrollTop : window.pageYOffset
		var windowedge=document.all && !window.opera? this.standardbody.scrollTop+this.standardbody.clientHeight-15 : window.pageYOffset+window.innerHeight-18
		this.dropmenuobj.contentmeasure=this.dropmenuobj.offsetHeight
		if (windowedge-this.dropmenuobj.y < this.dropmenuobj.contentmeasure){ //move up?
			edgeoffset=this.dropmenuobj.contentmeasure+obj.offsetHeight
			if ((this.dropmenuobj.y-topedge)<this.dropmenuobj.contentmeasure) //up no good either?
				edgeoffset=this.dropmenuobj.y+obj.offsetHeight-topedge
		}
	}
	return edgeoffset
},

dropit:function(obj, e, dropmenuID){
	if (this.dropmenuobj!=null) //hide previous menu
		this.hidemenu() //hide menu
	this.clearhidemenu()
	this.dropmenuobj=document.getElementById(dropmenuID) //reference drop down menu
	this.asscmenuitem=obj //reference associated menu item
	this.showhide(this.dropmenuobj.style, e)
	this.dropmenuobj.x=this.getposOffset(obj, "left")
	this.dropmenuobj.y=this.getposOffset(obj, "top")
	this.dropmenuobj.style.left=this.dropmenuobj.x-this.clearbrowseredge(obj, "rightedge")+"px"
	this.dropmenuobj.style.top=this.dropmenuobj.y-this.clearbrowseredge(obj, "bottomedge")+obj.offsetHeight+1+"px"
	this.positionshim() //call iframe shim function
},

positionshim:function(){ //display iframe shim function
	if (this.enableiframeshim && typeof this.shimobject!="undefined"){
		if (this.dropmenuobj.style.visibility=="visible"){
			this.shimobject.style.width=this.dropmenuobj.offsetWidth+"px"
			this.shimobject.style.height=this.dropmenuobj.offsetHeight+"px"
			this.shimobject.style.left=this.dropmenuobj.style.left
			this.shimobject.style.top=this.dropmenuobj.style.top
		}
	this.shimobject.style.display=(this.dropmenuobj.style.visibility=="visible")? "block" : "none"
	}
},

hideshim:function(){
	if (this.enableiframeshim && typeof this.shimobject!="undefined")
		this.shimobject.style.display='none'
},

isContained:function(m, e){
	var e=window.event || e
	var c=e.relatedTarget || ((e.type=="mouseover")? e.fromElement : e.toElement)
	while (c && c!=m)try {c=c.parentNode} catch(e){c=m}
	if (c==m)
		return true
	else
		return false
},

dynamichide:function(m, e){
	if (!this.isContained(m, e)){
		this.delayhidemenu()
	}
},

delayhidemenu:function(){
	this.delayhide=setTimeout("cssdropdown.hidemenu()", this.disappeardelay) //hide menu
},

hidemenu:function(){
	this.css(this.asscmenuitem, "selected", "remove")
	this.dropmenuobj.style.visibility='hidden'
	this.dropmenuobj.style.left=this.dropmenuobj.style.top=0
	this.hideshim()
},

clearhidemenu:function(){
	if (this.delayhide!="undefined")
		clearTimeout(this.delayhide)
},

addEvent:function(target, functionref, tasktype){
	if (target.addEventListener)
		target.addEventListener(tasktype, functionref, false);
	else if (target.attachEvent)
		target.attachEvent('on'+tasktype, function(){return functionref.call(target, window.event)});
},

startchrome:function(){
	if (!this.domsupport)
		return
	this.standardbody=(document.compatMode=="CSS1Compat")? document.documentElement : document.body
	for (var ids=0; ids<arguments.length; ids++){
		var menuitems=document.getElementById(arguments[ids]).getElementsByTagName("a")
		for (var i=0; i<menuitems.length; i++){
			if (menuitems[i].getAttribute("rel")){
				var relvalue=menuitems[i].getAttribute("rel")
				var asscdropdownmenu=document.getElementById(relvalue)
				this.addEvent(asscdropdownmenu, function(){cssdropdown.clearhidemenu()}, "mouseover")
				this.addEvent(asscdropdownmenu, function(e){cssdropdown.dynamichide(this, e)}, "mouseout")
				this.addEvent(asscdropdownmenu, function(){cssdropdown.delayhidemenu()}, "click")
				try{
					menuitems[i].innerHTML=menuitems[i].innerHTML+" "+this.dropdownindicator
				}catch(e){}
				this.addEvent(menuitems[i], function(e){ //show drop down menu when main menu items are mouse over-ed
					if (!cssdropdown.isContained(this, e)){
						var evtobj=window.event || e
						cssdropdown.dropit(this, evtobj, this.getAttribute("rel"))
					}
				}, "mouseover")
				this.addEvent(menuitems[i], function(e){cssdropdown.dynamichide(this, e)}, "mouseout") //hide drop down menu when main menu items are mouse out
				this.addEvent(menuitems[i], function(){cssdropdown.delayhidemenu()}, "click") //hide drop down menu when main menu items are clicked on
			}
		} //end inner for
	} //end outer for
	if (window.createPopup && !window.XmlHttpRequest &&!this.iframeshimadded){ //if IE5.5 to IE6, create iframe for iframe shim technique
		document.write('<IFRAME id="iframeshim"  src="" style="display: none; left: 0; top: 0; z-index: 90; position: absolute; filter: progid:DXImageTransform.Microsoft.Alpha(style=0,opacity=0)" frameBorder="0" scrolling="no"></IFRAME>')
		this.shimobject=document.getElementById("iframeshim") //reference iframe object
		this.iframeshimadded=true
	}
} //end startchrome

}
function Open_win(uv,utwidth, utheight) {
var remoteWin = null;
var params;
params = "toolbar=0,location=0,directories=0,status=0,scrollbars=1,scrolling=1,resizable=0,menubar=0,width="+utwidth+",height="+utheight+" ";
remoteWin = window.open("","colorpicker",params);
remoteWin.location.href = uv;     
}

function handleHttpResponse2()
{
if (http2.readyState == 4)
{
var results = http2.responseText
var str = "";
var count = 0;
//alert(results);
//alert(results.substring(0,1));
var total = parseInt(results.substring(0,1));
var total1 = parseInt(results.substring(2,4));
//alert (total1);
for(var i=0; i<total; i++)
{
str = str + "<img src=\"http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
}
if(total1>00)
{
//alert("inside if");
str = str + "<img src=\"http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/red-grey-half-star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
total = total+1;
}
//alert(total);
for(var i=total; i<5; i++)
{
str = str + "<img src=\"http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/grey-full-star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
}
//alert(str);
document.getElementById("score").innerHTML = str;
}
}

function showStar(i,j)
{

var url="http://indiatoday.intoday.in/site_special/specials/cwg/rateArtical.jsp?id=" +encodeURI(i)+"&id1="+encodeURI(j);
//alert (url);
http2.open("GET", url, true);
http2.onreadystatechange = handleHttpResponse2;
http2.send(null);
if(i>0)
{
alert("Thanks for voting.");
}
}

function getHTTPObject()
{
var xmlhttp;
if(window.XMLHttpRequest)
{
xmlhttp = new XMLHttpRequest();
}
else if (window.ActiveXObject)
{
xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
if (!xmlhttp)
{
xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
}
}
return xmlhttp;
}

var http2 = getHTTPObject();

//-->


function fnValidate()
{

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
//This function will check the blank field.
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
//This function check Email field. Like @,.,etc...........
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
        var min=8;
var max=17;
function increaseFontSize() {
   var p = document.getElementsByTagName('p');
   for(i=0;i<p.length;i++) {
      if(p[i].style.fontSize) {
         var s = parseInt(p[i].style.fontSize.replace("px",""));
      } else {
         var s = 12;
      }
      if(s!=max) {
         s += 1;
      }
      p[i].style.fontSize = s+"px"
   }
}
function decreaseFontSize() {
   var p = document.getElementsByTagName('p');
   for(i=0;i<p.length;i++) {
      if(p[i].style.fontSize) {
         var s = parseInt(p[i].style.fontSize.replace("px",""));
      } else {
         var s = 12;
      }
      if(s!=min) {
         s -= 1;
      }
      p[i].style.fontSize = s+"px"
   }   
}	
function resetFontSize() {
   var p = document.getElementsByTagName('p');
   for(i=0;i<p.length;i++) {
     
     p[i].style.fontSize = "14px"
      
   }   
}

