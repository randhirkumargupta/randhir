<span class="calendar-title">calendar</span>
<?php

/**
 * @file
 * Theme implementation for Magazine Calendar.
 * 
 */
$count = 1;
foreach ($data as $year) {
  if ($count % 24 == 1) {
    $output .= "<li>";
  }
  $class = '';
  if($year == arg(2)){
    $class = 'menu_active';
  }
  $output .= '<span>' . l($year, 'calendar/0/' . $year . '/magazine.html', array('attributes' => array('class' => array($class)))) . '</span>';
  if ($count % 24 == 0) {
    $output .= "</li>";
  }
  $count++;
}
?>
<?php print '<ul class="calanderslide">' . $output . '</ul>'; ?>

<script>
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
</script>