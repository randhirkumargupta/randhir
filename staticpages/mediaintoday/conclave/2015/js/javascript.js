$(document).ready(function(){
						   
						   
						   
var arr_team_a = ['','','','','','','','','','','','','','','','','','','','','','','','',''];
var arr_team_b = ['','','','','','','','','','','',''];
$('.team-b').addClass('deactive').attr("disabled", "disabled").off('click');
$('.team-a').addClass('deactive');
$('.all-players').addClass('selectsakshi');
var counters =1;
$('.form-submit').hide();

$('.team-b').click(function(){
$('html,body').animate({
        scrollTop: $('body').position().top += 800
    });							
});
$('.team-a').click(function(){
$('#players li').off('click');
$('span.tooltip-captsk').show();
$('.team-a').removeClass('deactive');							
$('html,body').animate({
        scrollTop: $('body').position().top += 800
    });
if(counters >= 13){
 //alert('SAKSHI Team is Ready');
//alert('SAKSHI Team is Ready. Please Select ANUSHKA Team Now');
//$('.team-a').addClass('deactive').attr("disabled", "disabled").off('click');
//$('.team-b').removeClass('deactive').removeAttr("disabled").off('click');
//$('.all-players').removeClass('selectsakshi');
//$('.all-players').addClass('selectanu');
//$('.selectanu #players .ply-img').live('click',function(){
// //alert(counters);
// 	for(i=0;i<arr_team_b.length;i++) {
//		if(arr_team_a[i]=='') {
//			arr_team_a[i] = 'yes';
//			y = i+1;
//			$(this).clone().appendTo('#an_'+ y +'> .ply-img');
//		
//		
//			break;
//		}
//	}
//$(this).addClass('disable');
//counters +=1;
//});
$('.team-anu .closeplayer').live('click', function(){
var playid = $(this).attr('id');
var whatindex = $(this).parent('div').parent('li').parent('div').parent('li').attr('id').replace('an_','');
$(this).parent().remove();
//alert(playid);
$('a#'+ playid).parent().removeClass('disable');
whatindex = parseInt(whatindex)-1;
arr_team_b[whatindex] = '';
counters -=1;

});

}

else

{
//alert(counters);	
	
$('.selectsakshi #players li').live('click', function(e){	


 for(i=0;i<arr_team_a.length;i++) {
		if(arr_team_a[i]=='') {
			arr_team_a[i] = 'yes';
			y = i+1;
		//////			
		var $textval2 = $('#nameval').val();
		//alert("nameval-->"+$textval2);
		$('#nameval').val($textval2 + y+",");	
		var imgvalID = $(this).children('div').children('img').attr('id');

		//alert("this"+this);
		//alert ("imgvalID"+imgvalID)
		imgvalID = imgvalID + ",";
		var $textval = $('#ids').val();
		$('#ids').val($textval + imgvalID);
		/////////
		$(this).clone().appendTo('#sa_'+ y +'> .ply-img-new');
			break;
		}
	}

$(this).addClass('disable').attr("disabled", "disabled").off('click');
counters +=1;
if(counters == 13){
	$('span.tooltip-captanu').show();
   alert('TEAM SAKSHI is ready. Now select TEAM ANUSHKA');
   $('.team-saksh a.closeplayer').css({'display':'none'});  
   
}
if(counters == 2){   
   $('span.tooltip-captsk').css({'display':'none'});  
}

//alert(counters);
if(counters >=13){
//alert('TEAM SAKSHI is ready. Now select TEAM ANUSHKA');
$('.team-sakshi a.closeplayer').css({'display':'none'});
$('.all-players').removeClass('selectsakshi');
$('.all-players').addClass('selectanu');
$('.team-a').addClass('deactive').attr("disabled", "disabled").off('click');
$('.team-b').removeClass('deactive');
$('.selectanu #players li').live('click',function(){
//alert('sandeep');
 	for(i=13;i<arr_team_a.length;i++) {
		if(arr_team_a[i]=='') {
			arr_team_a[i] = 'yes';
			y = i+1;
			//////			
		var $textval2 = $('#nameval').val();
		//alert("nameval-->"+$textval2);
		$('#nameval').val($textval2 + i+",");	
		//var imgvalID = $(this).children('img').attr('id');
		var imgvalID = $(this).children('div').children('img').attr('id');
		imgvalID = imgvalID + ",";
		var $textval = $('#ids').val();
		$('#ids').val($textval + imgvalID);
		/////////
			$(this).clone().appendTo('#an_'+ y +'> .ply-img-new');
			break;
		}
	}
$(this).addClass('disable');
counters +=1;
if(counters == 14){   
   $('span.tooltip-captanu').css({'display':'none'});  
}
if(counters == 25){
   alert('BRILLIANT TEAM-MAKING! Now click on SUBMIT button below to share your Masala World Cup 2015 on social media');
   $('.team-a').removeClass('deactive');
   $('.team-anu a.closeplayer,span.tooltip').css({'display':'none'});
   $('html,body').animate({
        scrollTop: $('body').position().top +=2200
    });
   $('.form-submit').show();
}

});

$('.team-anu .closeplayer').live('click', function(){
var playid = $(this).attr('id');
var whatindex = $(this).parent('li').parent('div').parent('li').attr('id').replace('an_','');
$(this).parent().remove();
//alert(playid);
/////////////
		$selectVal = (whatindex-1) + ",";
		//alert("=="+$selectVal);		
		var current_dropcontain = "10"+playid;
	$("#ids").val($("#ids").val().replace("," +current_dropcontain +',', ","));
		$("#nameval").val($("#nameval").val().replace("," +$selectVal, ","));

//////////////

$('a#'+ playid).parent().removeClass('disable');
whatindex = parseInt(whatindex)-1;
arr_team_a[whatindex] = '';
counters -=1;

});

	}
	
	
	$('.sakshi-team .closeplayer').live('click', function(){
														  
var playid = $(this).attr('id');
var whatindex = $(this).parent('li').parent('div').parent('li').attr('id').replace('sa_','');
$(this).parent().remove();

//alert(playid);

/////////////
		$selectVal = whatindex + ",";		
		var current_dropcontain = "10"+playid;
	$("#ids").val($("#ids").val().replace("," +current_dropcontain +',', ","));
		$("#nameval").val($("#nameval").val().replace("," +$selectVal, ","));

//////////////
$('a#'+ playid).parent().removeClass('disable');
whatindex = parseInt(whatindex)-1;
arr_team_a[whatindex] = '';
counters -=1;

	
});
});



}
$(this).off('click');
});


$('#players li').click(function(){
	alert('CLICK ON SAKSHIS PHOTO ABOVE TO PROCEED')
	$('html,body').animate({
        scrollTop: $('body').position().top += 10
    });		
});

							
							
});








