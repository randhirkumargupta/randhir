function getmenu(t, e, o, s) {
    $(s).addClass("active"), $(".drop-box-left a").parent("li").removeClass("active"), $(s).parent("li").addClass("active");
    var i = 0;
    if (0 == parseInt(t) && parseInt(t) > 0) var a = "cat",
        i = e;
    else if (parseInt(t) > 0) var a = "sec",
        i = t;
    if (0 == parseInt(e) && parseInt(t) > 0) var a = "sec",
        i = t;
    else if (parseInt(e) > 0) var a = "cat",
        i = e;
    $(s).parent("li").parent("ul").parent("div").next("div.drop-box-right").show();
    var n = $(s).parent("li").parent("ul").parent("div").next("div.drop-box-right");
    if (i > 0) {
        var l = a + "_" + i;
        if (void 0 != menu_arr[l] && null != menu_arr[l]) return void n.html(menu_arr[l]);
        n.html('<div class="load_data">LOADING....</div>'), $.ajax({
            url: siteurl + "/navigation_topnav_menu_ajax_2015.jsp",
            type: "GET",
            data: "id=" + i + "&ctype=" + o + "&type=" + a,
            success: function(t) {
                if (t.match("Error")) $(this).click();
                else {
                    n.html(t);
                    var e = a + "_" + i;
                    menu_arr[e] = t
                }
            },
            error: function(t) {}
        })
    }
}

function auto() {
    btm_counter >= btm_len - 4 ? ($(".btm_belt ul li.current_" + btm_counter).removeClass("active"), $(".btm_belt ul li").removeClass("active"), $(".catlist").removeClass("active").css({
        display: "none"
    }), $(".box" + btm_counter).addClass("active").css({
        display: "block"
    }), $(".btm_belt ul li.current_" + btm_counter).addClass("active"), btm_counter += 1) : ($(".btm_belt ul").animate({
        left: "-=100"
    }), $(".btm_belt ul li").removeClass("active"), $(".btm_right").hide(), btm_counter += 1, $(".catlist").removeClass("active").css({
        display: "none"
    }), $(".btm_left").show(), $(".btm_belt ul li.current_" + btm_counter).addClass("active"), $(".box" + btm_counter).addClass("active").css({
        display: "block"
    })), btm_counter > btm_len && (btm_counter = 0, $(".btm_belt ul").animate({
        left: "0"
    }), $(".btm_right").show(), $(".btm_left").show(), $(".box" + btm_counter).addClass("active").css({
        display: "block"
    }), $(".btm_belt ul li.current_" + btm_counter).addClass("active"))
}

function popup(t, e) {
    if (!window.focus) return !0;
    var o;
    return o = "string" == typeof t ? t : t.href, window.open(o, e, "width=400,height=200,scrollbars=yes"), !1
}

function sectionslider() {
    $(".alpha > .left-column1").css("display", "none"), $(".thumb ul li").removeClass("active"), $(".thumb ul li").eq(sec_counter).addClass("active"), $(".alpha > .left-column1").eq(sec_counter).css("display", "block"), sec_counter += 1, sec_counter > 3 && (sec_counter = 0)
}

function validatesearch() {
    if ("" == document.searchform1.searchword.value || "Type here" == document.searchform1.searchword.value) return alert("Please enter a search keyword"), document.searchform1.searchword.focus(), !1;
    if ("" != document.searchform1.searchword.value) {
        if ("Search..." == document.searchform1.searchword.value || "Search.." == document.searchform1.searchword.value || "Search." == document.searchform1.searchword.value || "Search" == document.searchform1.searchword.value) return alert("Please enter a valid search keyword"), document.searchform1.searchword.focus(), !1;
        if ("null" == document.searchform1.searchword.value) return alert("Please enter a search keyword"), document.searchform1.searchword.focus(), !1;
        if (document.searchform1.searchword.value.length < 3) return alert("Please enter atleast 3 characters"), document.searchform1.searchword.focus(), !1;
        var t = document.searchform1.searchword.value.trim(),
            e = t.split(" ").join("+");
        return window.location.href = "http://indiatoday.intoday.in/advanced_search.jsp?option=com_search&searchword=" + e, !1
    }
    if ("" != document.searchform1.fromdate.value) {
        var o = document.searchform1.fromdate.value;
        if (0 == isDate1(o)) return document.searchform1.fromdate.focus(), !1
    }
    if ("" != document.searchform1.fromdate.value && "" == document.searchform1.todate.value) return alert("Please Select To Date"), document.searchform1.todate.focus(), !1;
    if ("" != document.searchform1.todate.value) {
        var o = document.searchform1.fromdate.value,
            s = document.searchform1.todate.value;
        if (0 == isDate1(s)) return document.searchform1.todate.focus(), !1;
        if (0 == datefun1(o, s, "To Date Should Be Greater Than From Date")) return document.searchform1.todate.focus(), !1
    }
}
var menu_arr = new Array,
    box1_len = $(".catlist.active span").length,
    btm_counter = 0,
    btm_len = $(".btm_belt ul li").length,
    btm_width = $(".btm_belt ul li").width();
$(document).ready(function() {
    function t(t) {
        for (var e = (new Date).getTime(), o = 0; 1e7 > o && !((new Date).getTime() - e > t); o++);
    }
    t(1e4), setInterval(auto, 1e4), $(".drop-box-left ul li.no-dropbox").mouseenter(function() {
        $(".drop-box-right").css("display", "none"), $(".drop-box-left ul li").removeClass("active")
    })
}), $(document).ready(function() {
    $(".trending_box_cont .see_more_btn").click(function() {
        $(this).toggleClass("down_more_btn"), $("ul#moretraend0list").slideToggle(600)
    }), $("h1.section-heading").click(function() {
        $("#section-nav").slideToggle(600)
    }), $(".homeleft .see_more_btn").click(function() {
        $(this).toggleClass("down_more_btn"), $("#sectionlistmore").slideToggle(600)
    }), $(window).width() > 800 && ($(".top-menu > ul > li.news > ul").mouseleave(function() {
        $(this).slideUp(300), $(".top-menu > ul > li.news").removeClass("active")
    }), $(".top-menu > ul > li").mouseleave(function() {
        $(this).children("ul").slideUp(300)
    }), $(".closeslider h2").click(function() {
        $(this).parent("div").removeClass("closeslider"), $(this).next(".slider-cover").slideDown(200), $(this).children("a").removeClass("not-active")
    })), $(".belt-outer").children(".catlist:last").addClass("active").css({
        display: "block"
    }), $(".belt-outer").children(".heading:last").addClass("active").css({
        display: "block"
    }), $(".btm_belt ul li").eq(0).addClass("active");
    $(".btm_belt ul li").click(function() {
        $(".slide-next").show(), $(".slide-back").show(), $(".catlist").css("left", "0"), $(".btm_belt ul li").removeClass("active"), $(this).addClass("active");
        var t = $(".btm_belt ul li").index($(this));
        $(".catlist").removeClass("active").css({
            display: "none"
        }), $(".box" + t).addClass("active").css({
            display: "block"
        }), $(".heading").removeClass("active").css({
            display: "none"
        }), $(".slider_heading" + t).addClass("active").css({
            display: "block"
        }), box1_len = $(".catlist.active span").length;
        var e = $(".catlist.active span").width(),
            e = e * box1_len;
        $(".catlist.active").css("width", e)
    });
    var t = $(".catlist.active span").width(),
        t = t * box1_len;
    $(".catlist.active").css("width", t);
    var e = 0;
    $(".slide-next").click(function() {
        $(".slide-back").show(), box1_len > e ? ($(".catlist.active").animate({
            left: "-=605"
        }), e += 1) : $(".slide-next").show()
    }), $(".slide-back").click(function() {
        $(".slide-next").show(), e >= 2 ? ($(".catlist.active").animate({
            left: "+=605"
        }), e -= 1) : $(".slide-back").show()
    }), btm_width = btm_width * btm_len + 5;
    var o = $(".btm_belt ul").css("left");
    $(".btm_right").click(function() {
        $(".btm_left").show(), o = $(".btm_belt ul").css("left").replace("px").trim(), o = parseInt(o), 0 == o && ($(".btm_belt ul").animate({
            left: "-=100"
        }), $(".btm_right").hide())
    }), $(".btm_left").click(function() {
        $(".btm_right").show(), o = $(".btm_belt ul").css("left").replace("px").trim(), o = parseInt(o), 0 > o && ($(".btm_belt ul").animate({
            left: "+=100"
        }), $(".btm_left").hide())
    }), $(".openNav").click(function() {
        $(this).toggleClass("open"), $(".sub_topnav").slideToggle(300)
    }), $("#navnext").click(function() {
        $(".mainnavigation-slider ul").animate({
            top: "-=304"
        }), $(this).hide(), $("#navprev").show()
    }), $("#navprev").click(function() {
        $(".mainnavigation-slider ul").animate({
            top: "+=304"
        }), $(this).hide(), $("#navnext").show()
    }), $("a#menuclose").click(function() {
        return $(".sub_topnav").slideUp(300), $("a#menu").show(), $(this).hide(), !1
    }), $("li.grouplinks a#menu_h").click(function() {
        $(".sub_topnav").slideUp(300), $("a#menu").show(), $("a#menuclose").hide(), $(this).parent("li.grouplinks").toggleClass("active"), $(".right_t_menu").slideToggle(300)
    }), $(".right_t_menu").mouseleave(function() {
        $(this).slideUp(300), $(".top-menu li.grouplinks").removeClass("active")
    })
}), $(document).ready(function() {
    var t = $(".hotshowing #listhot .list-showing").length,
        e = $(".hotshowing #listhot .list-showing").height(),
        o = t * (e + 3);
    $(".hotshowing #listhot").css("height", o);
    var s = 1;
    $(".rigthnext-arrow").click(function() {
        t > s ? ($(".hotshowing #listhot").animate({
            top: "-=186"
        }), s += 1) : $(".rigthpre-arrow").css("display", "block")
    }), $(".rigthpre-arrow").click(function() {
        1 == s ? $(".rigthnext-arrow").css("display", "block") : ($(".hotshowing #listhot").animate({
            top: "+=186"
        }), s -= 1)
    })
}), $(document).ready(function() {
    var t = $(".anchores #listanchores .list-showing").length,
        e = $(".anchores #listanchores .list-showing").height(),
        o = t * (e + 3);
    $(".anchores #listhot").css("height", o);
    var s = 1;
    $(".rigthnext-arrow-anchors").click(function() {
        t > s ? ($(".anchores #listanchores").animate({
            top: "-=186"
        }), s += 1) : ($(".rigthnext-arrow-anchors").css("display", "none"), $(".rigthpre-arrow-anchors").css("display", "block"))
    }), $(".rigthpre-arrow-anchors").click(function() {
        1 == s ? ($(".rigthpre-arrow-anchors").css("display", "none"), $(".rigthnext-arrow-anchors").css("display", "block")) : ($(".anchores #listanchores").animate({
            top: "+=186"
        }), s -= 1)
    })
}), $(document).ready(function() {
    var t = $(".newsshowing #listnews > .list-showing").length,
        e = $(".newsshowing #listnews > .list-showing").height(),
        o = t * e;
    $(".newsshowing #listnews").css("height", o);
    var s = 1;
    $(".rigthnext-arrow-news").click(function() {
        t > s ? ($(".newsshowing #listnews").animate({
            top: "-=186"
        }), s += 1) : ($(".rigthnext-arrow-news").css("display", "none"), $(".rigthpre-arrow-news").css("display", "block"))
    }), $(".rigthpre-arrow-news").click(function() {
        1 == s ? ($(".rigthpre-arrow-news").css("display", "none"), $(".rigthnext-arrow-news").css("display", "block")) : ($(".newsshowing #listnews").animate({
            top: "+=186"
        }), s -= 1)
    })
}), $(document).ready(function() {
    var t = $(".story_thumb_container ul li").length,
        e = $(".story_thumb_container ul li").height(),
        o = t * e;
    $(".story_thumb_container ul").css("height", o);
    var s = 1;
    s > 3 && $(".bidstory-navslider").hide(), $("#next-bigstory").click(function() {
        t - 2 > s ? ($(".story_thumb_container ul").animate({
            top: "-=78"
        }), s += 1, $("#prev-bigstory").css("opacity", "1")) : $("#next-bigstory").css("opacity", "0.5")
    }), $("#prev-bigstory").click(function() {
        1 == s ? $("#prev-bigstory").css("opacity", "0.5") : ($(".story_thumb_container ul").animate({
            top: "+=78"
        }), s -= 1, $("#next-bigstory").css("opacity", "1"))
    })
}), $(document).ready(function() {
		
//===================new js	=======================
	
	var photo_ga_len = $('.photo-slider .photobelt .photo-list').length;
	//console.log(photo_ga_len);
	var photo_ga_width = $('.photo-slider .photobelt .photo-list').width()+3;
	var photo_ga_ulwidth = photo_ga_width * photo_ga_len;
	$('.photo-slider .photobelt').css('width', photo_ga_ulwidth);
	var photo_ga_counter = 0;

	$('#photonext').click(function(){
	
		if (photo_ga_counter <= photo_ga_len-2 ){
			$('.photo-slider .photobelt').animate({
				left : '-='+ photo_ga_width
			});
			
				photo_ga_counter+=1;
			$('#photoprev').show();
		}		
		else{
			//alert("stop");
			$(this).hide();
		}
	});
	
	
	$('#photoprev').click(function(){
		if (photo_ga_counter == 0 ){
			$(this).hide();
		}
		else{
			$('.photo-slider .photobelt').animate({
				left : '+='+ photo_ga_width
			});
			
			photo_ga_counter-=1;
			$('#photonext').show();
		}
	});
	

}), $(document).ready(function() {
    var t = $("#photoipad ul li").length,
        e = $("#photoipad ul li").width(),
        o = t * e;
    $("#photoipad ul").css("width", o);
    var s = 1;
    $("#ipadphoto-next").click(function() {
        t > s ? ($("#photoipad ul").animate({
            left: "-=" + e
        }), s += 1, $("#ipadphoto-prev").css("display", "block")) : $("#ipadphoto-next").css("display", "none")
    }), $("#ipadphoto-prev").click(function() {
        1 == s ? ($("#ipadphoto-prev").css("display", "none"), $("#ipadphoto-next").css("display", "block")) : ($("#photoipad ul").animate({
            left: "+=" + e
        }), s -= 1, $("#ipadphoto-next").css("display", "none"))
    })
}), $(document).ready(function() {
    var t = $(".hotshow #listshow .list-show").length,
        e = $(".hotshow #listshow .list-show").height(),
        o = t * e;
    $(".hotshow #listshow").css("height", o);
    var s = 1;
    $(".show-showmore a#progdown").click(function() {
        t - 1 > s ? ($(".hotshow #listshow").animate({
            top: "-=249"
        }), s += 1, $(".show-showmore a#progup").css("opacity", "1")) : $(".show-showmore a#progdown").css("opacity", "0.5")
    }), $(".show-showmore a#progup").click(function() {
        1 == s ? $(".show-showmore a#progup").css("opacity", "0.5") : ($(".hotshow #listshow").animate({
            top: "+=249"
        }), s -= 1, $(".show-showmore a#progdown").css("opacity", "1"))
    })
}), $(document).ready(function(t) {
    var e = $(".story-listall li").length,
        o = ($(".story-listall li").height(), 1);
    $("#topprev01").click(function() {
        e > o && ($(".story-listall").animate({
            top: "-=368"
        }), o += 1, $("#topprev01").css("opacity", "0.5"), $("#topnext01").css("opacity", "1"))
    }), $("#topnext01").click(function() {
        1 == o || ($("#topprev01").css("opacity", "1"), $("#topnext01").css("opacity", "0.5"), $(".story-listall").animate({
            top: "+=368"
        }), o -= 1)
    })
}), $(document).ready(function(t) {
    var e = $("#sectionpage .story-listall li").length,
        o = ($("#sectionpage .story-listall li").height(), 1);
    $("#sectionpage #sectopprev01").click(function() {
        e - 10 > o && ($(".story-listall").animate({
            top: "-=308"
        }), o += 1, $("#sectionpage #sectopprev01").css("opacity", "0.5"), $("#sectionpage #sectopnext01").css("opacity", "1"))
    }), $("#sectionpage #sectopnext01").click(function() {
        1 == o || ($("#sectionpage #sectopprev01").css("opacity", "1"), $("#sectionpage #sectopnext01").css("opacity", "0.5"), $(".story-listall").animate({
            top: "+=308"
        }), o -= 1)
    }), $("#scrolltop").click(function() {
        $("html, body").animate({
            scrollTop: 0
        }, 1e3)
    })
});
var num = 150;
$(window).bind("scroll", function() {
    $(window).scrollTop() > num ? $(".nav_bar").addClass("navfixed") : $(".nav_bar").removeClass("navfixed")
}), $(document).ready(function() {
    var t = 400;
    $(window).bind("scroll", function() {
        $(window).scrollTop() > t ? $("#scrolltop").css("opacity", "1") : $("#scrolltop").css("opacity", "0")
    });
    var e = $(document).height() - $(window).height() - 500;
    $(window).bind("scroll", function() {
        $(window).scrollTop() > e && $("#scrolltop").css("opacity", "0")
    })
}), $(document).ready(function() {
    $(".share-icon").click(function() {
        if ($(".share-icon").show(), $(this).next("ul").html().match("facebook")) {
            var t = $(this);
            $(".share-story ul").css({
                display: "none"
            }), $(this).css({
                display: "none"
            }).next("ul,ul li,.frame").css({
                display: "block"
            }), $(this).next("ul,ul li,.frame").mouseleave(function() {
                t.css({
                    display: "block"
                }), $(".share-story ul").css({
                    display: "none"
                })
            })
        } else {
            contentURL = $(this).attr("url"), contentURL.match("http") || (contentURL = "http://indiatoday.intoday.in/" + contentURL), contentTitle = $(this).attr("ctitle");
            var e = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href=" + contentURL + "&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=84&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:84px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1346833764.html#_=1346847881207&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=" + contentURL + "&amp;size=m&amp;text=" + escape(contentTitle) + "%20-%20India%20Today&amp;url=" + contentURL + "&amp;via=indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 20px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url=" + contentURL + "' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>",
                t = $(this);
            $(".open").css({
                display: "none"
            }), $(this).css({
                display: "none"
            }).next("ul,ul li,.frame").css({
                display: "block"
            }).html(e), $(this).next("ul,ul li,.frame").mouseleave(function() {
                t.css({
                    display: "block"
                }), $(".share-story ul").css({
                    display: "none"
                })
            })
        }
    })
}), $(document).ready(function() {
    $(".adt_s").click(function() {
        $(this).toggleClass("lesssocial"), $("#more_social").fadeToggle("fast")
    })
}), $(document).ready(function() {
    $(".mediumcontent p a").mouseenter(function() {
        $(this).children("img").show()
    }), $(".mediumcontent p a").mouseleave(function() {
        $(this).children("img").hide()
    })
});
var sec_counter = 0;
$(document).ready(function(t) {
    $(".thumb ul li").eq(0).addClass("active"), setInterval(sectionslider, 1e4), $(".thumb ul li").click(function() {
        var t = $(this).index();
        sec_counter = t, $(".thumb ul li").removeClass("active"), $(this).addClass("active"), $(".alpha > .left-column1").css("display", "none"), $(".alpha > .left-column1").eq(sec_counter).css("display", "block"), sec_counter > 3 && (sec_counter = 0)
    })
}), $(document).ready(function() {
    $("#topstories").click(function() {
        $("#top_story_cont").show(), $("#mail_today_cont").hide(), $("#breaking > .arr_down").css({
            display: "none"
        }), $("#topstories > .arr_down").css({
            display: "inline-block"
        }), $("#topstories").addClass("active"), $("#breaking").removeClass("active")
    }), $("#breaking").click(function() {
        $("#top_story_cont").hide(), $("#mail_today_cont").show(), $("#topstories").removeClass("active"), $("#breaking > .arr_down").css({
            display: "inline-block"
        }), $("#topstories > .arr_down").css({
            display: "none"
        }), $("#breaking").addClass("active")
    })
}), $(document).ready(function() {
    var t = $(".relatestory-container > .strinnerbox").length;
    t > 3 && ($(".relatestory-container").css("height", "595px"), $(".relatestory-container").mCustomScrollbar({
        horizontalScroll: !1,
        autoDraggerLength: !0,
        autoHideScrollbar: !0,
        advanced: {
            autoScrollOnFocus: !1,
            updateOnContentResize: !0,
            updateOnBrowserResize: !0
        }
    }))
}), $(document).ready(function() {
    if ($(window).width() < 800) {
        var t = $(".footer_lnk_m .ft_lnks_h").length,
            e = $(".footer_lnk_m .ft_lnks_h").width(),
            e = t * (e + 6);
        $(".footer_lnk_m").css("width", e);
        var o = 1;
        $("#footernext").click(function() {
            t - 4 > o ? ($(".footer_lnk_m").animate({
                left: "-=144"
            }), o += 1, $("#footerprev").css("display", "block")) : $("#footernext").css("display", "none")
        }), $("#footerprev").click(function() {
            1 == o ? ($("#footerprev").css("display", "none"), $("#footernext").css("display", "block")) : ($(".footer_lnk_m").animate({
                left: "+=144"
            }), o -= 1, $("#footernext").css("display", "none"))
        }), $("#middlepanel, #main_container, #wapper, .news_w").on("click", function() {
            $(".drop-box-right").css("display", "none"), $(".drop-box-left ul li").removeClass("active")
        })
    }
}), $(document).ready(function() {
    $(window).width() > 800 && ($(".top-menu > ul > li.news > ul").mouseout(function() {
        $(this).slideUp(300), $(".top-menu > ul > li.news").removeClass("active")
    }), $(".static-content").mouseleave(function() {
        $(".drop-box-right").hide(), $(".drop-box-left ul li").removeClass("active")
    })), $("#vd2").on("click", function() {
        $("#vd1").show(1e3), $("#vd2").hide(1e3)
    }), $(".storyimgclose").on("click", function() {
        $("#vd1").hide(1e3), $("#vd2").show(1e3)
    })
}), $(document).ready(function() {
    $(".tabs a").click(function(t) {
        t.preventDefault(), $(this).parent().addClass("active"), $(this).parent().siblings().removeClass("active");
        var e = $(this).attr("href");
        $(".tabcontent").not(e).css("display", "none"), $(e).fadeIn(300)
    })
}), $(document).ready(function() {
    var t = $(".drop-box-left ul li").length,
        e = $(".drop-box-left ul li").outerWidth(),
        o = e * t;
    $(".drop-box-left ul").css("width", o);
    8 >= t ? $(".scroll-arrow-right").css("opacity", "0") : $(".scroll-arrow-right").css("opacity", "1");
    var s = 0;
    $(".scroll-arrow-left").click(function() {
        if (0 == s) $(this).fadeOut();
        else {
            var t = $(".drop-box-left ul li").eq(s - 1).outerWidth();
            $(".drop-box-left ul").animate({
                left: "+=" + t
            }), s -= 1, $(".scroll-arrow-right").fadeIn()
        }
    }), $(".scroll-arrow-right").click(function() {
        if ($(".scroll-arrow-left").css("opacity", "1"), t - 7 >= s) {
            var e = $(".drop-box-left ul li").eq(s).outerWidth();
            $(".drop-box-left ul").animate({
                left: "-=" + e
            }), s += 1, $(".scroll-arrow-left").css("opacity", "1")
        } else $(".scroll-arrow-right").fadeOut()
    }), $(".icon-search").click(function() {
        $("#searchword").toggleClass("search-show")
    })
});

function popupFeatures(t, e) {
    if (!window.focus) return !0;
    var o;
    return o = "string" == typeof t ? t : t.href, window.open(o, e, "width=400,height=200,scrollbars=yes"), !1
}

