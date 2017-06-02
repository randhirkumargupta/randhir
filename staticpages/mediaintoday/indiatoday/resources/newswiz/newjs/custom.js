$(document).ready(function() {
						   
var swiper = new Swiper('.swiper-container', {
    pagination: '.swiper-pagination',
    slidesPerView: 'auto',
	preventClicks: false,
    paginationClickable: true,
    spaceBetween: 0
});  

 $(".thumb").click(function() {
     $(".thumb").removeClass("activethumb")
      $(this).addClass("activethumb");
 })
	
	
})



$(".group_list select").change(function() {
    $(this).find("option:selected").each(function() {
        if ($(this).attr("value") == "group-a") {
            $(".group-box").not(".group-a").hide();
            $(".group-a").show();
        } else if ($(this).attr("value") == "group-b") {
            $(".group-box").not(".group-b").hide();
            $(".group-b").show();
        } else if ($(this).attr("value") == "group-c") {
            $(".group-box").not(".group-c").hide();
            $(".group-c").show();
        } else if ($(this).attr("value") == "group-d") {
            $(".group-box").not(".group-d").hide();
            $(".group-d").show();
        } else if ($(this).attr("value") == "group-e") {
            $(".group-box").not(".group-e").hide();
            $(".group-e").show();
        } else if ($(this).attr("value") == "group-f") {
            $(".group-box").not(".group-f").hide();
            $(".group-f").show();
        } else {
            $(".group-box").hide();
        }
    });
}).change();
$(".match_group select").change(function() {
    $(this).find("option:selected").each(function() {
        if ($(this).attr("value") == "match-group-a") {
            $(".group-box-match").not(".match-group-a").hide();
            $(".match-group-a").show();
        } else if ($(this).attr("value") == "match-group-b") {
            $(".group-box-match").not(".match-group-b").hide();
            $(".match-group-b").show();
        } else if ($(this).attr("value") == "match-group-c") {
            $(".group-box-match").not(".match-group-c").hide();
            $(".match-group-c").show();
        } else if ($(this).attr("value") == "match-group-d") {
            $(".group-box-match").not(".match-group-d").hide();
            $(".match-group-d").show();
        } else if ($(this).attr("value") == "match-group-e") {
            $(".group-box-match").not(".match-group-e").hide();
            $(".match-group-e").show();
        } else if ($(this).attr("value") == "match-group-f") {
            $(".group-box-match").not(".match-group-f").hide();
            $(".match-group-f").show();
        } else if ($(this).attr("value") == "match-group-g") {
            $(".group-box-match").not(".match-group-g").hide();
            $(".match-group-g").show();
        } else if ($(this).attr("value") == "match-group-h") {
            $(".group-box-match").not(".match-group-h").hide();
            $(".match-group-h").show();
        } else if ($(this).attr("value") == "match-group-i") {
            $(".group-box-match").not(".match-group-i").hide();
            $(".match-group-i").show();
        } else if ($(this).attr("value") == "match-group-j") {
            $(".group-box-match").not(".match-group-j").hide();
            $(".match-group-j").show();
        } else if ($(this).attr("value") == "match-group-k") {
            $(".group-box-match").not(".match-group-k").hide();
            $(".match-group-k").show();
        } else if ($(this).attr("value") == "match-group-l") {
            $(".group-box-match").not(".match-group-l").hide();
            $(".match-group-l").show();
        } else if ($(this).attr("value") == "match-group-m") {
            $(".group-box-match").not(".match-group-m").hide();
            $(".match-group-m").show();
        } else if ($(this).attr("value") == "match-group-n") {
            $(".group-box-match").not(".match-group-n").hide();
            $(".match-group-n").show();
        } else if ($(this).attr("value") == "match-group-o") {
            $(".group-box-match").not(".match-group-o").hide();
            $(".match-group-o").show();
       } else if ($(this).attr("value") == "match-group-p") {
            $(".group-box-match").not(".match-group-p").hide();
            $(".match-group-p").show();
       } else if ($(this).attr("value") == "match-group-q") {
            $(".group-box-match").not(".match-group-q").hide();
            $(".match-group-q").show();
        } else {
            $(".group-box").hide();
        }
    });
}).change();
$(document).ready(function() {
    $(".partic_team a").click(function() {
        $(this).next().addClass("active");
    });
    $(".team_close").click(function() {
        $(".tm_lg_box").removeClass("active")
    })
});
$(document).ready(function(e) {
    $('.blast-from-the-past-years ul li').click(function() {
        $('.year-content').slideUp();
        $('.year-content').css('top', '35px')
        $(this).next('div').slideDown('fast');
        $('.blast-from-the-past-years ul li').removeClass('yearcor');
        $(this).addClass('yearcor');
    });
    $('.close').click(function() {
        $(this).parent('div').fadeOut();
        $('.blast-from-the-past-years ul li').removeClass('yearcor');
    });
    $('.2nd').click(function() {
        $('.year-content').css('top', '66px')
    })
});


$(document).ready(function() {
    $('.video_episode_snippets .video_inner a').click(function(e) {
        e.preventDefault();
        var lnk = $(this).attr('href');
        $('.video_pic').addClass('showvideo');
        $('.video_pic > #videoplayer').attr('src', lnk + "&autoplay=true");
    })
    $('#closevideo').click(function() {
        $('.video_pic').removeClass('showvideo');
        $('#videoplayer').attr('src', '');
    });

})