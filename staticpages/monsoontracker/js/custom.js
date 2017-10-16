// JavaScript Document

$(document).ready(function(e) {
	var lenr = $(".img_section > ul > li").length;
	var widthr = $(".img_section > ul > li").width();
	widthr = (widthr) * lenr;
	$(".img_section ul").css('width', widthr);
	 var counter = 1;
	 
	 //NEXT
	 $('.nextbtn').click(function(){
		 if(counter < lenr){
		   $(".img_section > ul").animate({'left' :'-=350'});
		   counter +=1;
		 }
		 else{
			 
		 }
	 });
	 //PREV
	 $('.prevbtn').click(function(){
		 if(counter == 1){
		 }else{
			 
			 $(".img_section > ul").animate({'left' :'+=350'});
		     counter -=1;
		 }
	 });
	 
	var lenrsec = $(".img_section_sec > ul > li").length;
	var widthrsec = $(".img_section_sec > ul > li").width();
	widthrsec = (widthrsec) * lenrsec;
	$(".img_section_sec ul").css('width', widthrsec);
	 var countersec = 1;
	 
	 //NEXT
	 $('.nextbtn01').click(function(){
		 if(countersec < lenrsec){
		   $(".img_section_sec > ul").animate({'left' :'-=350'});
		   countersec +=1;
		 }
		 else{
			 
		 }
	 });
	 //PREV
	 $('.prevbtn01').click(function(){
		 if(countersec == 1){
		 }else{
			 
			 $(".img_section_sec > ul").animate({'left' :'+=350'});
		     countersec -=1;
		 }
	 });
	 
	 
	var lenrthd = $(".dontmiss > ul > li").length;
	var widthrthd = $(".dontmiss > ul > li").width();
	widthrthd = (widthrthd+2) * lenrthd;
	$(".dontmiss ul").css('width', widthrthd);
	 var counterthd = 1;
	 
	 //NEXT
	 $('.dontmiss_next').click(function(){
		 if(counterthd < lenrthd){
		   $(".dontmiss > ul").animate({'left' :'-=302'});
		   counterthd +=1;
		 }
		 else{
			 
		 }
	 });
	 //PREV
	 $('.dontmiss_prev').click(function(){
		 if(counterthd == 1){
		 }else{
			 
			 $(".dontmiss > ul").animate({'left' :'+=302'});
		     counterthd -=1;
		 }
	 });
	 
});















