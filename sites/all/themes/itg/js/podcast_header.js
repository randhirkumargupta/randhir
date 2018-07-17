jQuery(document).ready(function () {
  jQuery('.slider-header').slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    arrows: false,
    fade: true,
    asNavFor: '.other-list'
  });
  jQuery('.other-list').slick({
    slidesToShow: 7,
    slidesToScroll: 1,
    arrows: true,
    prevArrow: '<i class=\"fa fa-chevron-left slick-prev\" aria-hidden=\"true\"></i>',
    nextArrow: '<i class=\"fa fa-chevron-right slick-next\" aria-hidden=\"true\"></i>',
    asNavFor: '.slider-header',
    focusOnSelect: true
  });
});