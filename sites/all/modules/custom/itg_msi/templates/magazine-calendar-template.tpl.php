<span class="widget-title"><?php print t('MAGAZINE ISSUES'); ?></span>
<?php

/**
 * @file
 * Theme implementation for Magazine Calendar.
 * 
 */
/*$count = 1;
foreach ($data as $year) {
  if ($count % 24 == 1) {
    $output .= "<li>";
  }
  $class = '';
  if($year == arg(2)){
    $class = 'menu_active';
  }
  $output .= '<span>' . l($year, 'magazine/' . itg_msi_last_issue_calendar($year), array('attributes' => array('class' => array($class)))) . '</span>';
  if ($count % 24 == 0) {
    $output .= "</li>";
  }
  $count++;
}*/
?>
<?php //print '<ul class="calanderslide">' . $output . '</ul>'; ?>

<!--<script>
    jQuery(document).ready(function(){    
        jQuery('.calanderslide').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: true,
            fade: false,  
            prevArrow:'<button class="slick-prev"><i class="fa fa-chevron-right"></i></button>',
            nextArrow:'<button class="slick-next"><i class="fa fa-chevron-left"></i></button>'
        });    
    });
</script>-->


<div class="magazine-calendar">

  <div class="calendar-year">

<span><a href="<?php print base_path().'magazine/'.itg_msi_last_issue_calendar(2018); ?>">2018</a></span>

<span><a href="<?php print base_path(); ?>magazine/04-12-2017">2017</a></span>

<span><a href="<?php print base_path(); ?>magazine/26-12-2016">2016</a></span>

<span><a href="<?php print base_path(); ?>magazine/28-12-2015">2015</a></span>

</div>

<div class="msg-archive">The archives will return soon.</div>

</div>

<style>

.magazine-calendar{position: relative;border: 1px solid #ddd;overflow: hidden;}
.magazine-calendar .calendar-year{ display: block; overflow: hidden;}
.magazine-calendar .calendar-year span{float: left;width: 25%;height: 34px;display: inline-block;vertical-align: top;text-align: center;line-height: 34px;border: 1px solid #ddd;border-top: none;border-left: none;}

.magazine-calendar .calendar-year span a{display: block;font-family: "Roboto-Regular";color: #808080;}

.magazine-calendar .calendar-year span a:active{color: #000;background: #eaeaea;}

.msg-archive{background: #eaeaea; font-size:14px; color:#808080; padding:3px 0; text-align: center; line-height:16px;}

</style>