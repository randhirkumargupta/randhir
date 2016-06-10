<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
?>
<div class="tv-schedule tv-schedule-time slider">
<?php foreach($output as $val): ?>
   <?php if($val['day'] == 'MON'): ?>
    <div>
        <span><?php print $val['time']; ?></span>   
    </div>    
<?php endif; ?>
<?php endforeach; ?>
</div>
<div class="tv-schedule tv-schedule-news slider">
<?php foreach($output as $val): ?>
   <?php if($val['day'] == 'MON'): ?>

    <div class="tv-schedule-task"> 
        <span><?php print $val['program']; ?></span>   
    </div>    
<?php endif; ?>

<?php endforeach; ?>
</div>

<div class="tv-schedule tv-schedule-time slider">
<?php foreach($output as $val): ?>
   <?php if($val['day'] == 'MON'): ?>

    <div>
        <span><?php print $val['time']; ?></span>    
    </div>    
<?php endif; ?>

<?php endforeach; ?>
</div>

<style type="text/css">
    .slider{width: 820px;margin: 20px auto;}
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