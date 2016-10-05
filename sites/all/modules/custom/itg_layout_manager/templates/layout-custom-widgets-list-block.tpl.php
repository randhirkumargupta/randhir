<?php
global $theme_key;
//p($data['custom_widget']);
//$cf = system_region_list($theme_key, $show = REGIONS_VISIBLE);
//$widget[2] = 'view';
?>


<h2 class="block-title">Custom widgets <span><i class="fa fa-plus-circle hide"></i><i class="fa fa-minus-circle"></i></span></h2>
<ul id="templates-widgets" class="no-bullet pd-10 templates-widgets">
  <?php 
    foreach($data['custom_widget'] as $key => $val) {
     //$widget = explode('|', $val['value']); 
  ?>
  <li id="<?php print $val;?>" data-widget="custom_html_widget#<?php print $key;?>" data-widget-info="">
    <span><?php print $val;?></span>
  </li>
  <?php } ?>
<!--    <li data-widget="section_wise_order"><span>Section Wise order</span></li>-->
</ul>
<!--<h2 class="block-title">Poll widgets</h2>-->
<?php
 //print $data['poll_widget'];
?>