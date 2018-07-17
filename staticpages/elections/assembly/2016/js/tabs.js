$(document).ready(function() {
	$("#tabs2").hide();
	$("#tabs3").hide();
	$("#tabas a").click(function(){
		$("#tabs1").show().slideDown(300);
		$("#tabs2").hide().slideUp(300);
		$("#tabs3").hide().slideUp(300);
		$("#tabas").removeClass("grey");
		$("#tabbbs").addClass("grey");
		$("#tabbs").addClass("grey");
	});
	
	$("#tabbs a").click(function(){
		$("#tabs2").show().slideDown(300);
		$("#tabs1").hide().slideUp(300);
		$("#tabs3").hide().slideUp(300);
		$("#tabbbs").addClass("grey");
		$("#tabbs").removeClass("grey");
		$("#tabas").addClass("grey");
	});
	
	
	$("#tabbbs a").click(function(){
		$("#tabs2").hide().slideUp(300);
		$("#tabs1").hide().slideUp(300);
		$("#tabs3").show().slideDown(300);
		$("#tabbbs").removeClass("grey");
		$("#tabbs").addClass("grey");
		$("#tabas").addClass("grey");
	});
	
$(".icon-search").click(function(){
$("#searchword").toggleClass("search-show");
});
});

