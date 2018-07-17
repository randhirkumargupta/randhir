$(document).ready(
		function($) {
			//alert("hi-->");
			$('.slideshow').live(
					'mouseover mouseout',
					function(event) {
						if (event.type == 'mouseover') {
							$(this).children('.left-button, .right-button')
									.stop(true, true).fadeIn();
						} else {
							$(this).children('.left-button, .right-button')
									.stop(true, true).fadeOut();
						}
					});
			var loadlinkk = window.location.hash + "";
			//alert("hi-->"+loadlinkk);
			if (loadlinkk) {
				//alert("hi");
				var server_name = 'http://indiatoday.intoday.in/sachin-odi-gallery';
				var newlinkid = loadlinkk.replace("#", "");
				$('#show').load(
						'http://indiatoday.intoday.in/sachin-odi-gallery/gallery_data.jsp?galleryId='
								+ galleryId + '&currentPhotoNo=' + newlinkid,
						function() {
							simpleSlide( {
								'swipe' : 'true'
							});
							addNotranslate();
						});
			}
			$('.switch_button')
					.live(
							'click',
							function() {
								if ($(this).hasClass('next')) {
									var load_link = $(this).attr('rel');
									var pageTitle = $(this).attr('name');
									document.title = pageTitle;
									$('meta[name=Keywords]').attr('content',
											pageTitle);
									var loadlin = window.location.hash;
									if (loadlin) {
										var hrrrrf = window.location + "";
										window.location = hrrrrf.replace(
												loadlin, "")
												+ $(this).attr('title');
										
									} else
										window.location = window.location
												+ $(this).attr('title');
									loadLink(load_link);
									pageTracker._trackPageview(load_plink);
									return false;
								}if ($(this).hasClass('curr')) {
									var load_link = $(this).attr('rel');
									var pageTitle = $(this).attr('name');
									document.title = pageTitle;
									$('meta[name=Keywords]').attr('content',pageTitle);
									var loadlin = window.location.hash;									
									if (loadlin) {
										var hrrrrf = window.location + "";
										window.location = hrrrrf.replace(loadlin, "")+ $(this).attr('title');
									} else
										window.location = window.location+ $(this).attr('title');									
									loadLink(load_link);
									pageTracker._trackPageview(load_plink);
									return false;
								}
								if ($(this).hasClass('prev')) {
									var load_plink = $(this).attr('rel');
									var pageTitle = $(this).attr('name');
									document.title = pageTitle;
									$('meta[name=Keywords]').attr('content',
											pageTitle);
									var ploadlin = window.location.hash;
									if (ploadlin) {
										var phref = window.location + "";
										window.location = phref.replace(
												ploadlin, "")
												+ $(this).attr('title');
									} else {
										window.location = window.location
												+ $(this).attr('title');
									}
									loadLink(load_plink);
									pageTracker._trackPageview(load_plink);
									return false;
								}
							});
			$('.right-button, .left-button').live(
					'click',
					function() {
						var action = $(this).attr('class');
						pageTracker._trackEvent('Slide Interactions', 'Clicks',
								action);
					});
			$('#bigboy, #mini').live(
					'click',
					function() {
						var version = $(this).attr('id');
						pageTracker._trackEvent('simpleSlide Downloads',
								'Downloaded', version);
					});
		});

function loadLink(load_link) {
	//alert("his");
	//alert("his-->"+load_link);
	
	$('#show')
			.html(
					"<div align='center' style='width:675px;height:300px;text-allign:center; '><img src='http://wonderwoman.intoday.in/static/images/photoloading.gif' border='0'></div>");
	$('#show').css('position', 'relative');
	$('#show')
			.animate(
					{
						'left' : '0px',
						'opacity' : '100'
					},
					100,
					"swing",
					function() {
						$
								.ajax( {
									url : '' + load_link,
									dataType : 'html',
									success : function(html) {
										$('#show').html(html);
										simpleSlide( {
											'swipe' : 'true',
											'callback' : function() {
												$('#show').animate(
														{
															'left' : '0px',
															'opacity' : '1'
														},
														300,
														"swing",
														function() {
															$('#show').css(
																	'position',
																	'static');
														});
											}
										});
										var pagenextnumber = parseInt(getUrlVars(load_link)["currentPhotoNo"]);
										var pagetotalnumber = parseInt(getUrlVars(load_link)["totalPhotoCount"]);
										//alert(load_link	+ " -- pagenextnumber->"+ pagenextnumber+ " -- pagetotalnumber"+ pagetotalnumber);
										if (pagenextnumber == pagetotalnumber) {
											$('#photooverlay').delay(7200)
													.fadeIn(500);
											//alert(load_link);
										}
										$('.auto-slider')
												.each(
														function() {
															var related_group = $(
																	this).attr(
																	'rel');
															clearInterval($.autoslide);
															$.autoslide = setInterval(
																	"simpleSlideAction('.right-button', "
																			+ related_group
																			+ ");",
																	4000);
														});
									}
								});
					});
}
function addNotranslate() {
	$('.codeblock').addClass('notranslate');
	$('code').addClass('notranslate');
}