// JavaScript Document

$(document).ready(function(){
$("ul.ddchild > li > a").hover(
	function () {
		
		$(this).stop().animate({ paddingLeft: "10px", width: "150px"  },0);
		
		
	}, 
	function () {
		
		$(this).stop().animate({ paddingLeft: "10px" , width: "150px" });
	});

$('.nav > ul > li.drop').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchild').show();
}).mouseout(function() {
	//$(this).addClass("");
    $('ul.ddchild').hide();
});

$('.nav > ul > li.drop1').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchild1').show();
	})
.mouseout(function() {
	//$(this).addClass("");
    $('ul.ddchild1').hide();
});
});

