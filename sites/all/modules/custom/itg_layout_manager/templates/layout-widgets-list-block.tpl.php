<h2 class="block-title">Template widgets</h2>
<ul id="templates-widgets" class="no-bullet pd-10 templates-widgets">
  <?php 
    foreach($data['default_widget'] as $key => $val) {
     $widget = explode('|', $val['value']); 
  ?>
  <li id="<?php print $widget[0];?>" data-widget="<?php print $widget[1];?>"><span><?php print $widget[0];?></span></li>
  <?php } ?>
<!--    <li data-widget="section_wise_order"><span>Section Wise order</span></li>-->
</ul>
<?php
 print $data['poll_widget'];
?>