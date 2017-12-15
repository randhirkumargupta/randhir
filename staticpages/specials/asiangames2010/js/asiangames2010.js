
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
	
	
	function toggle1(theDiv1,theDiv2,theDiv3) {

     var elem = document.getElementById(theDiv1);
	 
	   		var elem1 = document.getElementById("Layer1");
		 	var elem2 = document.getElementById("Layer2");
	     	var elem3= document.getElementById("Layer3");
			
		 elem1.style.display="none";
		 elem2.style.display="none";
		 elem3.style.display="none";
	
		 document.getElementById("image4").className ='tab_nothighlighted';
		 document.getElementById("image5").className ="tab_nothighlighted";
		 document.getElementById("image6").className ="tab_nothighlighted";

		 document.getElementById("a").className ='tabtext_nothighlight';
		 document.getElementById("b").className ="tabtext_nothighlight";
		 document.getElementById("c").className ="tabtext_nothighlight";
	
		 elem.style.display="block";
		document.getElementById(theDiv2).className= "tab_highlighted";
		document.getElementById(theDiv3).className= "tabtext_highlight";
	}
	
	function toggle2(theDiv4,theDiv5) {

     var elem = document.getElementById(theDiv4);
	 
	   		var elem4 = document.getElementById("Layer4");
		 	var elem5 = document.getElementById("Layer5");
	     	var elem6= document.getElementById("Layer6");
			var elem7= document.getElementById("Layer7");
			
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
	 var elem1 = document.getElementById("Layer8");
	 var elem2 = document.getElementById("Layer9");
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
	
	function toggle4(id4,id5,id6) {

     var elem = document.getElementById(id4);
	 var elem1 = document.getElementById("Layer11");
	 var elem2 = document.getElementById("Layer12");
	 elem1.style.display="none";
	 elem2.style.display="none";
	document.getElementById("player").className ='tab_nothighlighted';
	document.getElementById("team").className ="tab_nothighlighted";
	 document.getElementById("f").className ='tabtext_nothighlight';
	document.getElementById("g").className ="tabtext_nothighlight";
		 elem.style.display="block";
		document.getElementById(id5).className= "tab_highlighted";
		document.getElementById(id6).className= "tabtext_highlight";
	}
	
	function toggle5(theDiv11,theDiv12,theDiv13) {

     var elem = document.getElementById(theDiv11);
	 
	   		//var elem1 = document.getElementById("Layer13");
		 	var elem2 = document.getElementById("Layer14");
	     	var elem3= document.getElementById("Layer15");
			
		// elem1.style.display="none";
		 elem2.style.display="none";
		 elem3.style.display="none";
	
		 //document.getElementById("stay").className ='tab_nothighlighted';
		 document.getElementById("travel").className ="tab_nothighlighted";
		 document.getElementById("what").className ="tab_nothighlighted";

		// document.getElementById("h").className ='tabtext_nothighlight';
		 document.getElementById("i").className ="tabtext_nothighlight";
		 document.getElementById("j").className ="tabtext_nothighlight";
	
		 elem.style.display="block";
		document.getElementById(theDiv12).className= "tab_highlighted";
		document.getElementById(theDiv13).className= "tabtext_highlight";
	}


function toggle6(ex1,ex2,ex3) {

     var elem = document.getElementById(ex1);
	 var elem1 = document.getElementById("Layer16");
	 var elem2 = document.getElementById("Layer17");
	 elem1.style.display="none";
	 elem2.style.display="none";
	document.getElementById("focus").className ='tab_nothighlighted';
	document.getElementById("world").className ="tab_nothighlighted";
	 document.getElementById("foc").className ='tabtext_nothighlight';
	document.getElementById("wor").className ="tabtext_nothighlight";
		 elem.style.display="block";
		document.getElementById(ex2).className= "tab_highlighted";
		document.getElementById(ex3).className= "tabtext_highlight";
	}
	
	
function toggle7(id1,id2,id3) {

     var elem = document.getElementById(id1);
	 var elem1 = document.getElementById("Layer30");
	 var elem2 = document.getElementById("Layer31");
	 var elem3 = document.getElementById("Layer32");
	 elem1.style.display="none";
	 elem2.style.display="none";
	 elem3.style.display="none";
	document.getElementById("spoofs").className ='tab_nothighlighted';
	document.getElementById("jokes").className ="tab_nothighlighted";
	document.getElementById("cart").className ="tab_nothighlighted";
	 document.getElementById("spo").className ='tabtext_nothighlight';
	document.getElementById("joke").className ="tabtext_nothighlight";
	document.getElementById("car").className ="tabtext_nothighlight";
		 elem.style.display="block";
		document.getElementById(id2).className= "tab_highlighted";
		document.getElementById(id3).className= "tabtext_highlight";
		//document.getElementById(id3).className= "tabtext_highlight";
		
	}
	
	
function onSubmitPoll2()
{
	var form = document.poll2;			
	var radio		= form.player;
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
		alert('No selection has been made. Please try again..');
		return false;
	}
	else
	{
			
		var strURL = "http://specials.indiatoday.com/specials/bt_event/pollSubmit_latest.jsp?sid="+document.poll2.sid.value+"&answer="+answer+"&pid="+document.poll2.pid.value+"";
		var popupHeight = 400;
		var popupWidth = 460;
		var popupTop =  (window.screen.availHeight - popupHeight)/2;
		var popupLeft = (window.screen.availWidth - popupWidth)/2;
		
		var window1 = window.open(strURL ,'messageWindow','top=' + popupTop + ',left=' + popupLeft + ',height=' + popupHeight + ',width=' + popupWidth + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=yes,resizable=yes,copyhistory=yes');
		
		return true;
	}
}

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
str = str + "<img src=\"http://media2.intoday.in/indiatoday/images/star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
}
if(total1>00)
{
//alert("inside if");
str = str + "<img src=\"http://media2.intoday.in/indiatoday/images/red-grey-half-star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
total = total+1;
}
//alert(total);
for(var i=total; i<5; i++)
{
str = str + "<img src=\"http://media2.intoday.in/indiatoday/images/grey-full-star.gif\" width=\"10\" height=\"10\" align=\"absmiddle\">";
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






			var totalImage = 42;
			var showImage = 15;
			var firstImg = 1;
			var images = new Array();
			
			images[0] = "http://media2.intoday.in/microsites/asiangames2010/Aquatics.gif";
			images[1] = "http://media2.intoday.in/microsites/asiangames2010/Archery.gif";
			images[2] = "http://media2.intoday.in/microsites/asiangames2010/Athletics.gif";
			images[3] = "http://media2.intoday.in/microsites/asiangames2010/Badminton.gif";
			images[4] = "http://media2.intoday.in/microsites/asiangames2010/Baseball.gif";
			images[5] = "http://media2.intoday.in/microsites/asiangames2010/Billiard-Sports.gif";
			images[6] = "http://media2.intoday.in/microsites/asiangames2010/Basketball.gif";
			images[7] = "http://media2.intoday.in/microsites/asiangames2010/Bowling.gif";
			images[8] = "http://media2.intoday.in/microsites/asiangames2010/Boxing.gif";
			images[9] = "http://media2.intoday.in/microsites/asiangames2010/Canoe-Kayak.gif";
			images[10] = "http://media2.intoday.in/microsites/asiangames2010/Chess.gif";
			images[11] = "http://media2.intoday.in/microsites/asiangames2010/Cricket.gif";
			images[12] = "http://media2.intoday.in/microsites/asiangames2010/Cycling.gif";
			images[13] = "http://media2.intoday.in/microsites/asiangames2010/DanceSport.gif";
			images[14] = "http://media2.intoday.in/microsites/asiangames2010/Dragon-Boat.gif";
			images[15] = "http://media2.intoday.in/microsites/asiangames2010/Equestrian.gif";
			images[16] = "http://media2.intoday.in/microsites/asiangames2010/Fencing.gif";
			images[17] = "http://media2.intoday.in/microsites/asiangames2010/Football.gif";
			images[18] = "http://media2.intoday.in/microsites/asiangames2010/Golf.gif";
			images[19] = "http://media2.intoday.in/microsites/asiangames2010/Gymnastics.gif";
			images[20] = "http://media2.intoday.in/microsites/asiangames2010/Handball.gif";
			images[21] = "http://media2.intoday.in/microsites/asiangames2010/Hockey.gif";
			images[22] = "http://media2.intoday.in/microsites/asiangames2010/Judo.gif";
			images[23] = "http://media2.intoday.in/microsites/asiangames2010/Kabaddi.gif";
			images[24] = "http://media2.intoday.in/microsites/asiangames2010/Karate.gif";
			images[25] = "http://media2.intoday.in/microsites/asiangames2010/Modern-Pentathlon.gif";
			images[26] = "http://media2.intoday.in/microsites/asiangames2010/Roller-Sports.gif";
			images[27] = "http://media2.intoday.in/microsites/asiangames2010/Rowing.gif";
			images[28] = "http://media2.intoday.in/microsites/asiangames2010/Rugby.gif";
			images[29] = "http://media2.intoday.in/microsites/asiangames2010/Sailing.gif";
			images[30] = "http://media2.intoday.in/microsites/asiangames2010/Sepaktakraw.gif";
			images[31] = "http://media2.intoday.in/microsites/asiangames2010/Shooting.gif";
			images[32] = "http://media2.intoday.in/microsites/asiangames2010/Softball.gif";
			images[33] = "http://media2.intoday.in/microsites/asiangames2010/Squash.gif";
			images[34] = "http://media2.intoday.in/microsites/asiangames2010/Table-Tennis.gif";
			images[35] = "http://media2.intoday.in/microsites/asiangames2010/Taekwondo.gif";
			images[36] = "http://media2.intoday.in/microsites/asiangames2010/Tennis.gif";
			images[37] = "http://media2.intoday.in/microsites/asiangames2010/Triathlon.gif";
			images[38] = "http://media2.intoday.in/microsites/asiangames2010/Volleyball.gif";
			images[39] = "http://media2.intoday.in/microsites/asiangames2010/Weightlifting.gif";
			images[40] = "http://media2.intoday.in/microsites/asiangames2010/Wrestling.gif";
			images[41] = "http://media2.intoday.in/microsites/asiangames2010/Wushu.gif";


			var imagesLinks = new Array();
		    imagesLinks[0] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Aquatics%20(Asiad)&scid=70&page=0";
			imagesLinks[1] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Archery%20(Asiad)&scid=71&page=0";
			imagesLinks[2] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Athletics%20(Asiad)&scid=74&page=0";
			imagesLinks[3] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Badminton%20(Asiad)&scid=75&page=0";
			imagesLinks[4] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Baseball%20(Asiad)&scid=76&page=0";
			imagesLinks[5] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Billiard%20(Asiad)&scid=78&page=0";
			imagesLinks[6] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Basketball%20(Asiad)&scid=114&page=0";
			imagesLinks[7] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Bowling%20(Asiad)&scid=80&page=0";
			imagesLinks[8] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Boxing%20(Asiad)&scid=79&page=0";
			imagesLinks[9] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Canoeing%20(Asiad)&scid=81&page=0";
			imagesLinks[10] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Chess%20(Asiad)&scid=82&page=0";
			imagesLinks[11] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Cricket%20(Asiad)&scid=83&page=0";
			imagesLinks[12] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Cycling%20(Asiad)&scid=84&page=0";
			imagesLinks[13] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Dance%20Sport%20(Asiad)&scid=85&page=0";
			imagesLinks[14] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Dragon%20Boat%20(Asiad)&scid=86&page=0";
			imagesLinks[15] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Equestrian%20(Asiad)&scid=87&page=0";
			imagesLinks[16] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Fencing%20(Asiad)&scid=88&page=0";
			imagesLinks[17] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Football%20(Asiad)&scid=89&page=0";
			imagesLinks[18] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Golf%20(Asiad)&scid=90&page=0";
			imagesLinks[19] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Gymnastics%20(Asiad)&scid=91&page=0";
			imagesLinks[20] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Handball%20(Asiad)&scid=92&page=0";
			imagesLinks[21] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Hockey%20(Asiad)&scid=93&page=0";
			imagesLinks[22] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Judo%20(Asiad)&scid=94&page=0";
			imagesLinks[23] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Kabbadi%20(Asiad)&scid=95&page=0";
			imagesLinks[24] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Karate%20(Asiad)&scid=96&page=0";
			imagesLinks[25] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Modern%20Pentathlon%20(Asiad)&scid=97&page=0";
			imagesLinks[26] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Roller%20Sports%20(Asiad)&scid=98&page=0";
			imagesLinks[27] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Rowing%20(Asiad)&scid=99&page=0";
			imagesLinks[28] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Rugby%20(Asiad)&scid=100&page=0";
			imagesLinks[29] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Sailing%20(Asiad)&scid=101&page=0";
			imagesLinks[30] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Sepaktakraw%20(Asiad)&scid=102&page=0";
			imagesLinks[31] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Shooting%20(Asiad)&scid=104&page=0";
			imagesLinks[32] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Softball%20(Asiad)&scid=103&page=0";
			imagesLinks[33] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Squash%20(Asiad)&scid=105&page=0";
			imagesLinks[34] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Table%20Tennis%20(Asiad)&scid=106&page=0";
			imagesLinks[35] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Taekwondo%20(Asiad)&scid=107&page=0";
			imagesLinks[36] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Lawn%20Tennis%20(Asiad)&scid=108&page=0";
			imagesLinks[37] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Triathlon%20(Asiad)&scid=109&page=0";
			imagesLinks[38] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Volleyball%20(Asiad)&scid=110&page=0";
			imagesLinks[39] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Weightlifting%20(Asiad)&scid=111&page=0";
			imagesLinks[40] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Wrestling%20(Asiad)&scid=112&page=0";
			imagesLinks[41] = "http://indiatoday.intoday.in/site/specials/asiangames2010/subsubsection.jsp?sid=84&sn=Sports&cn=Asian%20Games%202010%20Guangzhou%20China%202010&cid=260&scatn=Wushu%20(Asiad)&scid=113&page=0";

			

			var imagesAlt = new Array();
		    imagesAlt[0] = "Aquatics";
			imagesAlt[1] = "Archery";
			imagesAlt[2] = "Athletics";
			imagesAlt[3] = "Badminton";
			imagesAlt[4] = "Baseball";
			imagesAlt[5] = "Billiard Sports";
			imagesAlt[6] = "Basketball";
			imagesAlt[7] = "Bowling";
			imagesAlt[8] = "Boxing";
			imagesAlt[9] = "Canoe-Kayak";
			imagesAlt[10] = "Chess";
			imagesAlt[11] = "Cricket";
			imagesAlt[12] = "Cycling";
			imagesAlt[13] = "Dance Sport";
			imagesAlt[14] = "Dragon Boat";
			imagesAlt[15] = "Equestrian";
			imagesAlt[16] = "Fencing";
			imagesAlt[17] = "Football";
			imagesAlt[18] = "Golf";
			imagesAlt[19] = "Gymnastics";
			imagesAlt[20] = "Handball";
			imagesAlt[21] = "Hockey";
			imagesAlt[22] = "Judo";
			imagesAlt[23] = "Kabaddi";
			imagesAlt[24] = "Karate";
			imagesAlt[25] = "Modern Pentathlon";
			imagesAlt[26] = "Roller Sports";
			imagesAlt[27] = "Rowing";
			imagesAlt[28] = "Rugby";
			imagesAlt[29] = "Sailing";
			imagesAlt[30] = "Sepaktakraw";
			imagesAlt[31] = "Shooting";
			imagesAlt[32] = "Softball";
			imagesAlt[33] = "Squash";
			imagesAlt[34] = "Table Tennis";
			imagesAlt[35] = "Taekwondo";
			imagesAlt[36] = "Tennis";
			imagesAlt[37] = "Triathlon";
			imagesAlt[38] = "Volleyball";
			imagesAlt[39] = "Weightlifting";
			imagesAlt[40] = "Wrestling";
			imagesAlt[41] = "Wushu";
			
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
					imgStrs +='<a href=\"'+imagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+images[imageNo]+'\" hspace=\"2\" alt=\"'+imagesAlt[imageNo]+'\" title=\"'+imagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
							
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
					imgStrs +='<a href=\"'+imagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+images[imageNo]+'\" hspace=\"2\" alt=\"'+imagesAlt[imageNo]+'\" title=\"'+imagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
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
					imgStrs +='<a href=\"'+imagesLinks[imageNo]+'\" target=\"_blank\"><img src=\"'+images[imageNo]+'\" hspace=\"2\" alt=\"'+imagesAlt[imageNo]+'\" title=\"'+imagesAlt[imageNo]+'\" border=\"0\"/>'+'</a>';
					
					imageNo++;
				}
				//alert (imgStr);
				document.getElementById("imagetd").innerHTML = imgStrs;
			}




function validate1()
{

if((document.searchform1.sea1[0].checked==false) && (document.searchform1.sea1[1].checked==false))
{
alert("Please select one search option")
return false;
}
if(document.searchform1.searchword.value.length < 3) 
{
alert("Please Enter Atleast 3 characters");
document.searchform1.searchword.focus();
return false;
}
else
{
if(document.searchform1.sea1[1].checked==true)
{

window.open("http://www.google.com/search?hl=en&q="+document.searchform1.searchword.value+"&btnG=Search")			//document.searchform1.action="http://www.google.com/search?hl=en&q="+document.searchform1.searchword.value+"&btnG=Search";
return false;
}

return true;
}
}
// JavaScript Document
