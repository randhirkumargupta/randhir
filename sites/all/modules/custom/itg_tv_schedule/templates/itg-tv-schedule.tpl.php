<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
  
 ?>
<?php global $base_url;
  $mon = $base_url."/tv-show/MON";
  $tue = $base_url."/tv-show/TUE";
  $wed = $base_url."/tv-show/WED";
  $thu = $base_url."/tv-show/THU";
  $fri = $base_url."/tv-show/FRI";
  $sat = $base_url."/tv-show/SAT";
  $sun = $base_url."/tv-show/SUN";
  print render(drupal_get_form('itg_tv_schedule_search_form'));
 ?>
    
<div class="tv-schedule-parent">
<ul class="no-bullet schedule-days">
    <li><a href="<?php print $mon; ?>"><?php print t('Monday'); ?></a></li>
    <li><a href="<?php print $tue; ?>"><?php print t('Tuesday'); ?></a></li>
    <li><a href="<?php print $wed; ?>"><?php print t('Wednesday'); ?></a></li>
    <li><a href="<?php print $thu; ?>"><?php print t('Thursday'); ?></a></li>
    <li><a href="<?php print $fri; ?>"><?php print t('Friday'); ?></a></li>
    <li><a href="<?php print $sat; ?>"><?php print t('Saturday'); ?></a></li>
    <li><a href="<?php print $sun; ?>"><?php print t('Sunday'); ?></a></li>
</ul>
<div class="tv-schedule tv-schedule-time slider">
<?php foreach($output as $val): ?>
  
    <div>
        <span><?php print $val['time']; ?></span>   
    </div>    

<?php endforeach; ?>
</div>
<div class="tv-schedule tv-schedule-news slider">
<?php foreach($output as $val): ?>
   

    <div class="tv-schedule-task"> 
        <span><?php print $val['program']; ?></span>   
    </div>    


<?php endforeach; ?>
</div>

<div class="tv-schedule tv-schedule-time slider">
<?php foreach($output as $val): ?>
  

    <div>
        <span><?php print $val['time']; ?></span>    
    </div>    


<?php endforeach; ?>
</div>
</div>

<style type="text/css">
    .slider{width: 1000px;margin: 20px auto;}
    .slider{width: 820px;margin: 0 auto;}
    .tv-schedule{max-width: 820px;}
    .tv-schedule .slick-list{display: inline-block; width: 100%; vertical-align: top;}
    .tv-schedule-time .slick-slide span{display: block; padding: 10px; text-align: center;border-left: 1px solid #d9d9d9;}
    .tv-schedule-time .slick-slide:first-child span{border-left: none;}
    .tv-schedule-time{border: 1px solid #d9d9d9;}
    .tv-schedule .slick-arrow{position: absolute; top: 0; bottom: 0; margin: auto 10px; width: 0; height: 0; border: 10px solid; background: none; font-size: 0; cursor: pointer;}
    .tv-schedule .slick-prev{right: 100%; border-color: transparent #d9d9d9 transparent transparent;}
    .tv-schedule .slick-next{left: 100%; border-color: transparent transparent transparent #d9d9d9;}
    .tv-schedule-news .slick-slide span{display: block;}
    .tv-schedule-news{border: 1px solid #d9d9d9;}
    .tv-schedule-news .tv-schedule-task span{padding: 10px; border: 1px solid #d9d9d9; overflow: hidden; height: 100px;}
    .schedule-days{text-align: center;}
    .schedule-days li{display: inline-block; vertical-align: top; color: #008eb1;}
    .schedule-days li a{display: block; color: #008eb1; text-decoration: none; padding: 5px 30px;}
</style>
<script type="text/javascript">
    jQuery(document).on('ready', function() {
      jQuery(".tv-schedule").slick({
        dots: false,
        infinite: true,
        slidesToShow: 7,
        slidesToScroll: 1,
        asNavFor:'.tv-schedule'
      });
    });
  </script>