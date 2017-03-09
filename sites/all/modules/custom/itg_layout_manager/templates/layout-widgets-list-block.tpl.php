<?php
global $theme_key;

//$cf = system_region_list($theme_key, $show = REGIONS_VISIBLE);
//$widget[2] = 'view';
?>


<h2 class="block-title">Template widgets <span><i class="fa fa-plus-circle hide"></i><i class="fa fa-minus-circle"></i></span></h2>
<ul id="templates-widgets" class="no-bullet pd-10 templates-widgets">
  <?php
  //p($data['default_widget']);
  $widget0 = '';
  $widget1 = '';
  $widget2 = '';
  $widget3 = '';
  $widget4 = '';
  if (!empty($data['default_widget'])) {
    foreach($data['default_widget'] as $key => $val) {
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
     //pr($widget);
  ?>
  <li id="<?php print $widget[0];?>" data-widget="<?php print $widget[1];?>" data-widget-info="<?php print $widget[2].'|'.$widget[3].'|'.$widget[4];?>">
    <span><?php print $widget[0];?></span>
  </li>
  <?php } }?>
<!--    <li data-widget="section_wise_order"><span>Section Wise order</span></li>-->
</ul>
<!--<h2 class="block-title">Poll widgets</h2>-->
<?php
 //print $data['poll_widget'];
?>