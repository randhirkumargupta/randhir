<?php
global $theme_key;
?>

<h2 class="block-title">Custom html widgets <span><i class="fa fa-plus-circle hide"></i><i class="fa fa-minus-circle"></i></span></h2>
<div>
<?php print $data['html_widgets_form']; ?>
<ul id="templates-widgets-html" class="no-bullet pd-10 templates-widgets">
  <?php 
    //foreach($data['custom_widget'] as $key => $val) {
     //$widget = explode('|', $val['value']); 
  ?>
<!--  <li id="<?php //print $val;?>" data-widget="custom_html_widget#<?php //print $key;?>" data-widget-info="">
    <span><?php //print $val;?></span>
  </li>-->
  <?php //} ?>
</ul>
</div>