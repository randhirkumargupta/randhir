<?php
global $theme_key;

//$cf = system_region_list($theme_key, $show = REGIONS_VISIBLE);
//$widget[2] = 'view';
?>


<h2 class="block-title">Special widgets <span><i class="fa fa-plus-circle hide"></i><i class="fa fa-minus-circle"></i></span></h2>
<ul id="templates-widgets" class="no-bullet pd-10 templates-widgets">
  <?php
    $widget0 = '';
    $widget1 = '';
    $widget2 = '';
    $widget3 = '';
    $widget4 = '';
    foreach($data['special_widget'] as $key => $val) {
     $widget = explode('|', $val['value']);
     if (!empty($widget[0])) {
       $widget0 = $widget[0];
     }
     if (!empty($widget[1])) {
       $widget1 = $widget[1];
     }
     if (!empty($widget[2])) {
       $widget2 = $widget[2];
     }
     if (!empty($widget[3])) {
       $widget3 = $widget[3];
     }
     if (!empty($widget[4])) {
       $widget4 = $widget[4];
     }
  ?>
  <li id="<?php print $widget0;?>" data-widget="<?php print $widget1;?>" data-widget-info="<?php print $widget2.'|'.$widget3.'|'.$widget4;?>">
    <span><?php print $widget0;?></span>
  </li>
  <?php } ?>
<!--    <li data-widget="section_wise_order"><span>Section Wise order</span></li>-->
</ul>
<!--<h2 class="block-title">Poll widgets</h2>-->
<?php
 //print $data['poll_widget'];
?>