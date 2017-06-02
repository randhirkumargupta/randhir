// JavaScript Document

/************************Nav Drop down*******************************/
$(document).ready(function(){
	
$("ul.ddchild > li > a").hover(
	function () {
		$(this).stop().animate({ paddingLeft: "10px", width: "150px"  },0);
	}, 
	function () {
		$(this).stop().animate({ paddingLeft: "10px" , width: "150px" });
	}
);

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
$('.nav > ul > li.dropbot').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchildbot').show();
	})
.mouseout(function() {
	//$(this).addClass("");
    $('ul.ddchildbot').hide();
});

});
/************************Nav Drop down*******************************/


  
	$('#state_dropdown').change(function(){
		var currentid = $(this).find("option:selected").attr('value');
		$('.container_panalist').hide();
		$('#panalist_'+currentid).fadeIn();
										
	});

	$('#state_dropdown_tr').change(function(){
		var currentid = $(this).find("option:selected").attr('value');
		$('.container_trailblazer').hide();
		$('#trailblazer_'+currentid).fadeIn();
										
	});



	jQuery(document).ready(function() {
		$('.countdown1').countDown({
			targetDate: {
				'day': 		21,
				'month': 	09,
				'year': 	2013,
				'hour': 	09,
				'min': 		30,
				'sec': 		1
			}
		});
	});


/*<script type="text/javascript" language="javascript" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/youthsummit/2014/delhi/js/jquery.carouFredSel-6.2.1-packed.js"></script>*/

/*	$(function() {
		$('#foo0').carouFredSel();
		$('#foo1').carouFredSel({
			auto: {
				pauseOnHover: 'resume',
				progress: '#timer1'
			}
		}, {
			transition: true
		});
	});*/
     
