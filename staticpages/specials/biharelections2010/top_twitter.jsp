










<script language="javascript">
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
</script>
<div id="meundiv">
<div id="menuhead" >
<div id="menu_it_logo">
<div class="meun_it_menu">
<div id="chromemenu" class="ddcolortabs">
<ul>
<li><a href="http://indiatoday.intoday.in/">Home</a></li>
<li><a href="http://indiatoday.in/cwg" target="_blank">CWG 2010</a></li>
<li><a href="http://www.indiatoday.in/blogs" target="_blank">Blogs</a></li>
<li><a href="http://indiatoday.intoday.in/site/photo/0/2/photo.html">Photos</a></li>
<li><a href="http://indiatoday.intoday.in/site/Video/0/39/Videos">Videos</a></li>
<li><a href="http://indiatoday.intoday.in/site/section/114/india.html">India</a></li>
<li><a href="http://indiatoday.intoday.in/site/section/113/world.html">World</a></li>
<li><a href="http://indiatoday.intoday.in/site/section/84/sport.html">Sport</a></li>
<li><a href="http://indiatoday.intoday.in/site/section/110/business.html">Business</a></li>
<li><a href="http://indiatoday.intoday.in/site/section/67/cinema.html">Cinema</a></li>
<li><a href="http://indiatoday.intoday.in/site/section/103/lifestyle.html" >Lifestyle</a></li>
<li><a class="it_menu_sublinks" rel="dropmenu1">Magazine</a></li>
<li><a class="it_menu_sublinks" rel="dropmenu2" style="border: medium none;">Supplements</a></li>
</ul>
</div>

<div id="dropmenu1" class="dropmenudiv_a">
<a href="http://indiatoday.intoday.in/site/section?secId=30&page=0">Cover Story</a>
<a href="http://indiatoday.intoday.in/site/section?secId=36&page=0">Nation</a>
<a href="http://indiatoday.intoday.in/site/section?secId=21&page=0">States</a>
<a href="http://indiatoday.intoday.in/site/section?secId=34&page=0">Economy</a>
<a href="http://indiatoday.intoday.in/site/section?secId=146&page=0">Glass House</a>
<a href="http://indiatoday.intoday.in/site/section?secId=41&page=0">Sport</a>
<a href="http://indiatoday.intoday.in/site/section?secId=145&page=0">Up Front</a>
<a href="http://indiatoday.intoday.in/site/section?secId=144&page=0">Third Eye</a>
<a href="http://indiatoday.intoday.in/site/section?secId=141&page=0">Profile</a>
<a href="http://indiatoday.intoday.in/site/section?secId=2&page=0">Eyecatchers</a>
<a href="http://indiatoday.intoday.in/site/section?secId=149&page=0">Glossary</a>
<a href="http://indiatoday.intoday.in/site/archive">Archives</a>

</div>
<div
style="top: 0pt; left: 0pt; clip: rect(0pt, auto, 21px, 0pt); visibility: hidden;"
id="dropmenu2" class="dropmenudiv_a">
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=16">Home</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=17">Aspire</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=28">Spice</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=18">Woman</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=19">Simply Delhi</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=30">Simply Chennai</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=31">Simply Gujarati</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=32">Simply Kolkata</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=33">Simply Punjabi</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=34">Simply Mumbai</a>
<a href="http://indiatoday.intoday.in/site/Simply?secId=20&catId=35">Simply Bangalore</a>
</div>
</div>
<script type="text/javascript">
cssdropdown.startchrome("chromemenu")
</script>
</div></div>

</div>

<div style="border:0px solid red; margin-left:0px; float:left; $float:none; text-align:left; margin-bottom:10px;">
<table  width="822" border="0" cellpadding="0" cellspacing="0">
<tr>

<td width="166"><a href="http://indiatoday.intoday.in/site/twitter/section.jsp"><img src="http://indiatoday.intoday.in/nwbuzz.gif" width="166" border="0" height="40"></a></td>
<td width="654" height="40" bgcolor="#eaeaea" style="background-image: url(http://indiatoday.intoday.in/nwbuzz-bg.gif); background-position: right top; background-repeat: no-repeat; font-family: arial; font-style: normal; font-variant: normal; font-weight: normal; font-size: 11px; line-height: normal; font-size-adjust: none; font-stretch: normal; -x-system-font: none; color: rgb(86, 86, 86);">
<b style="color: rgb(104, 104, 104); font-size: 12px;"> -</b> <span style="font-family: arial; font-style: normal; font-variant: normal; font-weight: normal; font-size: 11px; line-height: normal; font-size-adjust: none; font-stretch: normal; -x-system-font: none; color: rgb(86, 86, 86); margin-left: 7px; margin-top: 1px;"><a href="http://indiatoday.intoday.in/site/twitter/index.jsp?p=1&artid=0" style="font-family: arial; font-style: normal; font-variant: normal; font-weight: normal; font-size: 11px; line-height: normal; font-size-adjust: none; font-stretch: normal; -x-system-font: none; color: rgb(86, 86, 86);">Comment</a>&nbsp; |&nbsp;  <a href="http://indiatoday.intoday.in/site/twitter/section.jsp" style="font-family: arial; font-style: normal; font-variant: normal; font-weight: normal; font-size: 11px; line-height: normal; font-size-adjust: none; font-stretch: normal; -x-system-font: none; color: rgb(86, 86, 86);">More</a>&nbsp;</span>
</td>
</tr>
</table>
</div> 

