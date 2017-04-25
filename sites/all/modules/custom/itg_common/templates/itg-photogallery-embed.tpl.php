
  <h1><?php print $data->title; ?></h1>
  <div class="itg-embed-photo-wrapper">
  <div class="itg-embed-photo">
    <ul class="itg-embed-photo-slider">
      <?php
      foreach ($data->field_gallery_image['und'] as $index => $mega_item) {
        $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
        $byline_id = $ans_detail[$mega_item['value']]->field_images['und'][0]['uri'];
        ?>
        <li>
          <figure class="" img-fid=" <?php print $ans_detail[$mega_item['value']]->field_images['und'][0]['fid']; ?>">

            <img src=<?php print file_create_url($byline_id); ?> width="753" height="543" title="" alt="" />
  <?php //theme('image_style', array('style_name' => 'photgallery_landing_slider_753x543', 'path' => $byline_id));  ?> 
          </figure>
        </li>
<?php } ?>
    </ul>
  </div>
  <div class="itg-embed-photo-thumb">
    <ul class="itg-embed-photo-thumb-slider">
      <?php foreach ($data->field_gallery_image['und'] as $index => $mega_item) {
        $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
        $byline_id = $ans_detail[$mega_item['value']]->field_images['und'][0]['uri'];
        ?>
        <li >
          <img src=<?php print file_create_url($byline_id); ?> width="88" height="66" title="" alt="" />
        </li>
<?php } ?>
    </ul>
  </div>
</div>
<style>
  .page-photogallery-embed{background-color: #171717;}
  h1{font-size: 32px; margin: 25px 0; color: #fff; text-align: center;}
  .itg-embed-photo-wrapper{padding: 10px; background-color: #000; max-width: 773px; margin: 0 auto; width: 100%;}
  .itg-embed-photo-thumb{margin-top: 10px;}
  .itg-embed-photo-thumb .slick-slide{outline: none;}
  .itg-embed-photo-thumb img{width: 88px; max-width: 100%; height: 66px; border: 1px solid #000; outline: none;}
  .itg-embed-photo-thumb .slick-current img{border-color: #fff;}
  .itg-embed-photo-slider .slick-next, .itg-embed-photo-slider .slick-prev {
    cursor: pointer;
    width: 50px;
    height: 100px;
    background-color: rgba(255, 255, 255, 0.3);
    font-size: 0;
    position: absolute;
    top: 0;
    bottom: 0;
    margin: auto 0;
    z-index: 9;
    border: none;
  }
  .itg-embed-photo-slider .slick-next{
    border-radius: 90px 0px 0px 90px;
    right: 0;
  }
  .itg-embed-photo-slider .slick-prev {
    border-radius: 0 90px 90px 0;
    left: 0;
  }
  .itg-embed-photo-slider .slick-prev:hover, .itg-embed-photo-slider .slick-next:hover {background-color: rgba(255, 255, 255, 0.6);}
  .itg-embed-photo-slider .slick-next:before, .itg-embed-photo-slider .slick-prev:before {
    font: normal normal normal 32px/100px FontAwesome;
    position: absolute;
    top: 0;
    color: #666;
  }
  .itg-embed-photo-slider .slick-next:before{
    content: '\f054';
    right: 5px;
  }
  .itg-embed-photo-slider .slick-prev:before {
    content: '\f053';
    left: 5px;
  }
  .itg-embed-photo-thumb-slider{
    padding: 0 40px;
  }
  .itg-embed-photo-thumb-slider .slick-next, .itg-embed-photo-thumb-slider .slick-prev {
    cursor: pointer;
    width: 40px;
    height: 66px;
    font-size: 0;
    position: absolute;
    top: 0;
    z-index: 9;
    border: none;
    background-color: #000;
  }
  .itg-embed-photo-thumb-slider .slick-next{left: 0;}
  .itg-embed-photo-thumb-slider .slick-prev{right: 0;}
  .itg-embed-photo-thumb-slider .slick-next:before, .itg-embed-photo-thumb-slider .slick-prev:before {
    font: normal normal normal 32px/66px FontAwesome;
    position: absolute;
    top: 0;
    color: #fff;
  }
  .itg-embed-photo-thumb-slider .slick-next:before{content: '\f053'; left: 10px;}
  .itg-embed-photo-thumb-slider .slick-prev:before{content: '\f054'; right: 10px;}
</style>
<script>
  jQuery(document).ready(function (e) {
    jQuery('.itg-embed-photo-slider').slick({
      slidesToShow: 1,
      slidesToScroll: 1,
      adaptiveHeight: true,
      arrows: true,
      fade: false,
      asNavFor: '.itg-embed-photo-thumb-slider'
    });
    jQuery('.itg-embed-photo-thumb-slider').slick({
      slidesToShow: 7,
      slidesToScroll: 1,
      asNavFor: '.itg-embed-photo-slider',
      dots: false,
      centerMode: false,
      arrows: true,
      focusOnSelect: true,
      responsive: [
        {
          breakpoint: 1024,
          settings: {
            slidesToShow: 7,
            slidesToScroll: 1,
            arrows: false
          }
        },
        {
          breakpoint: 600,
          settings: {
            slidesToShow: 4,
            arrows: false,
            slidesToScroll: 1
          }
        },
        {
          breakpoint: 480,
          settings: {
            slidesToShow: 3,
            arrows: false,
            slidesToScroll: 1
          }
        }
      ]
    });
  });
</script>