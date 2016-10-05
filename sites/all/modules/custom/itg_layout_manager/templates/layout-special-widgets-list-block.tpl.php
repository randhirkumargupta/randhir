<?php
global $theme_key;

//$cf = system_region_list($theme_key, $show = REGIONS_VISIBLE);
//$widget[2] = 'view';
?>


<h2 class="block-title">Special widgets <span><i class="fa fa-plus-circle hide"></i><i class="fa fa-minus-circle"></i></span></h2>
<ul id="templates-widgets" class="no-bullet pd-10 templates-widgets">
  <?php 
    foreach($data['special_widget'] as $key => $val) {
     $widget = explode('|', $val['value']); 
  ?>
  <li id="<?php print $widget[0];?>" data-widget="<?php print $widget[1];?>" data-widget-info="<?php print $widget[2].'|'.$widget[3].'|'.$widget[4];?>">
    <span><?php print $widget[0];?></span>
  </li>
  <?php } ?>
<!--    <li data-widget="section_wise_order"><span>Section Wise order</span></li>-->
</ul>
<!--<h2 class="block-title">Poll widgets</h2>-->
<?php
 //print $data['poll_widget'];
?>