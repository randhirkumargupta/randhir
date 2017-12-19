function myOpen(abc) { 	window.open(abc.value, '_blank' ); } 		
/********************************************************/	  
	  <!-- Add our jQuery code to Document -->
		$(document).ready(function(){
			$(".content").hide();
			$(".first .content").show();
			$(".rightfirst .content").show();
			
			$('<img src="http://indiatoday.intoday.in/education/images/off.gif" class="arrow" />').insertAfter('.block a h5');
			$(".first a img:last-child").remove();
			$(".rightfirst a img:last-child").remove();
			$('<img src="http://indiatoday.intoday.in/education/images/on.gif" class="arrow" />').insertAfter('.first a h5'); 				   
			$('<img src="http://indiatoday.intoday.in/education/images/on.gif" class="arrow" />').insertAfter('.rightfirst a h5');
			
			$(".accrodion a h5").click(function(){
				if($(this).is(".accrodion .active")) {
				 $(this).toggleClass("active");
				 $('.accrodion .arrow.active').attr('src','http://indiatoday.intoday.in/education/images/off.gif'); // change the image src of the current ACTIVE image to have an INACTIVE state.
				 $(this).parent().next(".accrodion .content").slideToggle();
				 return false;
				} else {
					$(".accrodion .content:visible").slideUp("slow"); // close all visible divs with the class of .content
					$(".accrodion h5.active").removeClass("active");  // remove the class active from all h5's with the class of .active
					$(this).toggleClass("active");
					$('.accrodion .arrow.active').attr('src','http://indiatoday.intoday.in/education/images/off.gif'); // change the image src of the current ACTIVE image to have an INACTIVE state.
					$(".accrodion .arrow").addClass('active');
					$(this).siblings('.accrodion .arrow.active').attr('src','http://indiatoday.intoday.in/education/images/on.gif'); // change the image src of the new active image to have an active state.
					$(this).parent().next(".accrodion .content").slideToggle();
					return false;
				}
			});
			
			/********** For right side *******************/
			$(".mustreaddiv a h5").click(function(){
				if($(this).is(".active")) {
				 $(this).toggleClass("active");
				 $('.mustreaddiv .arrow.active').attr('src','http://indiatoday.intoday.in/education/images/off.gif'); // change the image src of the current ACTIVE image to have an INACTIVE state.
				 $(this).parent().next(".mustreaddiv .content").slideToggle();
				 return false;
				} else {
					$(".mustreaddiv .content:visible").slideUp("slow"); // close all visible divs with the class of .content
					$(".mustreaddiv h5.active").removeClass("active");  // remove the class active from all h5's with the class of .active
					$(this).toggleClass("active");
					$('.mustreaddiv .arrow.active').attr('src','http://indiatoday.intoday.in/education/images/off.gif'); // change the image src of the current ACTIVE image to have an INACTIVE state.
					$(".mustreaddiv .arrow").addClass('active');
					$(this).siblings('.mustreaddiv .arrow.active').attr('src','http://indiatoday.intoday.in/education/images/on.gif'); // change the image src of the new active image to have an active state.
					$(this).parent().next(".mustreaddiv .content").slideToggle();
					return false;
				}
			});
		});
		
		
/*************************************/
 	$('.scrollbar').scrollbar();
	
	
	$('#demo2 a:first').click(function(ev){
		ev.preventDefault();
	 	$('#demo2').find('.scrollbar-pane').children(':first').clone().appendTo('.scrollbar-pane');
	 	$('#container2').scrollbar('repaint');
	});
	$('#demo2 a:last').click(function(ev){
	  ev.preventDefault();
	  $('#demo2').find('.scrollbar-pane').children(':first').remove();
	  $('#container2').scrollbar('repaint');
	});

/***************Plan Your Career****************************/
$(document).ready(function(){
	$(".catrgory_li").hover(function (){
		$(this).parent().addClass("active-cate");
		$(this).find('.sub-cates').show("");
		
	  },
	  function () {
		$(this).parent().removeClass("active-cate");
		$(this).find('.sub-cates').hide("");
//		$(this).find('.categorybg')
	  }
	);
});



/********************** Custom Select Box******************************/
var selectWidth = "168"; 
document.write('<style type="text/css">input.styled { display: none; } select.styled { position: relative; width: ' + selectWidth + 'px; opacity: 0; filter: alpha(opacity=0); z-index: 5; } .disabled { opacity: 0.5; filter: alpha(opacity=50); }</style>');
var Custom = {
	init: function() {
		var inputs = document.getElementsByTagName("input"), span = Array(), textnode, option, active;
		for(a = 0; a < inputs.length; a++) {
			if((inputs[a].type == "checkbox" || inputs[a].type == "radio") && inputs[a].className == "styled") {
				span[a] = document.createElement("span");
				span[a].className = inputs[a].type;

				if(inputs[a].checked == true) {
					if(inputs[a].type == "checkbox") {
						position = "0 -" + (checkboxHeight*2) + "px";
						span[a].style.backgroundPosition = position;
					} else {
						position = "0 -" + (radioHeight*2) + "px";
						span[a].style.backgroundPosition = position;
					}
				}
				inputs[a].parentNode.insertBefore(span[a], inputs[a]);
				inputs[a].onchange = Custom.clear;
				if(!inputs[a].getAttribute("disabled")) {
					span[a].onmousedown = Custom.pushed;
					span[a].onmouseup = Custom.check;
				} else {
					span[a].className = span[a].className += " disabled";
				}
			}
		}
		inputs = document.getElementsByTagName("select");
		for(a = 0; a < inputs.length; a++) {
			if(inputs[a].className == "styled") {
				option = inputs[a].getElementsByTagName("option");
				active = option[0].childNodes[0].nodeValue;
				textnode = document.createTextNode(active);
				for(b = 0; b < option.length; b++) {
					if(option[b].selected == true) {
						textnode = document.createTextNode(option[b].childNodes[0].nodeValue);
					}
				}
				span[a] = document.createElement("span");
				span[a].className = "select";
				span[a].id = "select" + inputs[a].name;
			//	span[a].setAttribute("onchange","javascript:alert(this.value);");
				span[a].appendChild(textnode);
				inputs[a].parentNode.insertBefore(span[a], inputs[a]);
				if(!inputs[a].getAttribute("disabled")) {
					inputs[a].onchange = Custom.choose;
					//alert(Custom.choose);
				} else {
					inputs[a].previousSibling.className = inputs[a].previousSibling.className += " disabled";
				}
			}
		}
		document.onmouseup = Custom.clear;
	},
	pushed: function() {
		element = this.nextSibling;
		if(element.checked == true && element.type == "checkbox") {
			this.style.backgroundPosition = "0 -" + checkboxHeight*3 + "px";
		} else if(element.checked == true && element.type == "radio") {
			this.style.backgroundPosition = "0 -" + radioHeight*3 + "px";
		} else if(element.checked != true && element.type == "checkbox") {
			this.style.backgroundPosition = "0 -" + checkboxHeight + "px";
		} else {
			this.style.backgroundPosition = "0 -" + radioHeight + "px";
		}
	},
	check: function() {
		element = this.nextSibling;
		if(element.checked == true && element.type == "checkbox") {
			this.style.backgroundPosition = "0 0";
			element.checked = false;
		} else {
			if(element.type == "checkbox") {
				this.style.backgroundPosition = "0 -" + checkboxHeight*2 + "px";
			} else {
				this.style.backgroundPosition = "0 -" + radioHeight*2 + "px";
				group = this.nextSibling.name;
				inputs = document.getElementsByTagName("input");
				for(a = 0; a < inputs.length; a++) {
					if(inputs[a].name == group && inputs[a] != this.nextSibling) {
						inputs[a].previousSibling.style.backgroundPosition = "0 0";
					}
				}
			}
			element.checked = true;
		}
	},
	clear: function() {
		inputs = document.getElementsByTagName("input");
		for(var b = 0; b < inputs.length; b++) {
			if(inputs[b].type == "checkbox" && inputs[b].checked == true && inputs[b].className == "styled") {
				inputs[b].previousSibling.style.backgroundPosition = "0 -" + checkboxHeight*2 + "px";
			} else if(inputs[b].type == "checkbox" && inputs[b].className == "styled") {
				inputs[b].previousSibling.style.backgroundPosition = "0 0";
			} else if(inputs[b].type == "radio" && inputs[b].checked == true && inputs[b].className == "styled") {
				inputs[b].previousSibling.style.backgroundPosition = "0 -" + radioHeight*2 + "px";
			} else if(inputs[b].type == "radio" && inputs[b].className == "styled") {
				inputs[b].previousSibling.style.backgroundPosition = "0 0";
			}
		}
	},
	choose: function() {
		option = this.getElementsByTagName("option");
		for(d = 0; d < option.length; d++) {
			if(option[d].selected == true) {
				document.getElementById("select" + this.name).childNodes[0].nodeValue = option[d].childNodes[0].nodeValue;
				window.open(option[d].value); //// optional
			}
		}
	}
}
window.onload = Custom.init;
/**************************************************************************/


var rootdomain="http://"+window.location.hostname
function ajaxinclude(url){
	var page_request=false
	if(window.XMLHttpRequest)
		page_request=new XMLHttpRequest()
	else if(window.ActiveXObject){
		try{
			page_request=new ActiveXObject("Msxml2.XMLHTTP")
		} catch(e) { 
			try{
				page_request=new ActiveXObject("Microsoft.XMLHTTP")
			} catch(e){}}
		} else
			return false
	page_request.open('GET',url,false)
	page_request.setRequestHeader("If-Modified-Since","Thu, 1 Jan 1970 00:00:00 GMT");page_request.send(null)
	if(window.location.href.indexOf("http")==-1||page_request.status==200)
		document.write(page_request.responseText)
}
function validate()
{
	var srchstr = '~`!@#$%^&*()_+{}|":\';[]\?><,./';
	var strlen = srchstr.length;
	var srchwrd = document.getElementById('mod_search_searchwordup').value;
	if(srchwrd=='' || srchwrd==' ' || srchwrd=='Search...') {
		return false;
	}
	var wrdlen = srchwrd.length;
	var runtime = strlen;
	var runtimet = wrdlen;
	var stopp = 'n';
	if(strlen>wrdlen) {
		for(i=0;i<runtime;i++) {
			for(j=0;j<runtimet;j++) {
				if(srchstr[i]==srchwrd[j]) {
					stopp = 'y';
					break;
				}
			}
			if(stopp=='y') {
				alert("Special characters are not allowed in search");
				break;
			}
		}
	} else {
		for(i=0;i<runtimet;i++) {
			for(j=0;j<runtime;j++) {
				if(srchwrd[i]==srchstr[j]) {
					stopp = 'y';
					break;
				}
			}
			if(stopp=='y') {
				alert("Special characters are not allowed in search");
				break;
			}
		}
	}
	if(stopp=='y') {
		return false;
	}
	return true;
}






$(document).ready(function(){
						$('#mustreadid').click(function() {
							$('#righttabing').removeClass('topsongid');
							$('#righttabing').addClass('mustreadid');
							$('#topsongsdiv').slideUp();
							$('#mustreaddiv').slideDown();
						});
						$('#topsongid').click(function() {
							$('#righttabing').removeClass('mustreadid');
							$('#righttabing').addClass('topsongid');
							$('#mustreaddiv').slideUp();
							$('#topsongsdiv').slideDown();
						});
					});
					
					
$(document).ready(function(){
							$(".timeline li.current").hover(function(){
								$(this).css('background-image','url(images/dot-hover.png)');
								$(this).css('margin-top','1px');
								$(this).find(".timeline_bubble").slideDown(100);
							},function(){
								$(this).css('background-image','url(images/blue-dot.png)');
								$(this).css('margin-top','0');
								$('.current').css('background-image','url(images/orange-dot.png)');
								$(".timeline_bubble").slideUp(100); 
							});
						});
						
						
$(document).ready(function(){
								$('.onlinecourse').hover(function(e) {
                                   var src = $(this).find('a').attr('rel'); 
								   $('#onlinecourseimg').find('img').attr('src',src);
                                });
							});
							
							
			

