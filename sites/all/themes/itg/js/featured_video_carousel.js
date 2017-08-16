jQuery(document).ready(function () {
  var winWidth = jQuery(window).width();
  if (winWidth > 1024) {
    jQuery('.carousel').carousel({
      frontWidth: 645,
      frontHeight: 365,
      carouselWidth: 1170,
      carouselHeight: 450,
      buttonNav: 'none'
    });
  } else {
    jQuery('.carousel .slides').slick({
      infinite: true,
      autoplay: true,
      dots: true,
      prevArrow: false,
      nextArrow: false
    });
  }
});