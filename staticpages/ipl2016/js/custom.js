var swiper = new Swiper('.swiper-container', {
        pagination: '.swiper-pagination',
        slidesPerView: 'auto',
        paginationClickable: true,
        spaceBetween: 0
    });

/// end swiper js 

$(document).ready(function(){
	$(".thumb").click(function(){
	$(".thumb").removeClass("activethumb")
	$(this).addClass("activethumb");
	
	})
})
// end active thumb slide

 $("select").change(function(){
            $(this).find("option:selected").each(function(){
                if($(this).attr("value")=="group-a"){
                    $(".group-box").not(".group-a").hide();
                    $(".group-a").show();
                }
                else if($(this).attr("value")=="group-b"){
                    $(".group-box").not(".group-b").hide();
                    $(".group-b").show();
                }
                else if($(this).attr("value")=="group-c"){
                    $(".group-box").not(".group-c").hide();
                    $(".group-c").show();
                }
                else{
                    $(".group-box").hide();
                }
            });
        }).change();

/*BLAST FROM THE PAS*/
$(document).ready(function(e) {
        $('.blast-from-the-past-years ul li').click(function(){
			$('.year-content').slideUp();
			$('.year-content').css('top', '35px')
			$(this).next('div').slideDown('fast');
			$('.blast-from-the-past-years ul li').removeClass('yearcor');
			$(this).addClass('yearcor');
		});
		
		$('.close').click(function(){
			$(this).parent('div').fadeOut();
			$('.blast-from-the-past-years ul li').removeClass('yearcor');
		});
		
		$('.2nd').click(function(){
			$('.year-content').css('top', '66px')
		})
    });