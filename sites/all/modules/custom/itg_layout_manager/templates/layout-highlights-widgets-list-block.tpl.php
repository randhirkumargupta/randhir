<?php
global $theme_key;

?>


<h2 class="block-title">Highlights widgets <span><i class="fa fa-plus-circle hide"></i><i class="fa fa-minus-circle"></i></span></h2>
<?php print $data['highlights_widgets_form']; ?>
<ul id="templates-widgets" class="no-bullet pd-10 templates-widgets">
  <?php 
    foreach($data['highlights_widget'] as $key => $val) {    
  ?>
  <li id="<?php print $val;?>" data-widget="highlights_widget#<?php print $key;?>" data-widget-info="">
    <span><?php print $val;?></span>
  </li>
  <?php } ?>
</ul>