jQuery(document).ready(function () {
  jQuery(".recommended-slider").slick({
    slidesToShow: 3,
    slidesToScroll: 1,
    centerPadding: "40px",
    prevArrow: "<button class = \'slick-prev\'><i class = \'fa fa-angle-left\'></i></button>",
    nextArrow: "<button class = \'slick-next\'><i class = \'fa fa-angle-right\'></i></button>",
    responsive: [
      {
        breakpoint: 1024,
        settings: {
          slidesToShow: 2,
          slidesToScroll: 1
        }
      },
      {
        breakpoint: 680,
        settings: {
          slidesToShow: 1,
          slidesToScroll: 1
        }
      }
    ]
  });
});