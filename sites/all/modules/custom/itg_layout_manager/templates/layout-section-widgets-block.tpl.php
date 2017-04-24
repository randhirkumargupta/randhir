<h2 class="block-title">Section Card <span><i class="fa fa-plus-circle"></i><i class="fa fa-minus-circle hide"></i></span></h2>
<div class="section-widgets-detail hide">
<?php
  print $data['section_widgets_form'];
?>
<div id="section_widgets_list">
  <?php  
    if (!empty($data['widgets_list'])) {
      print $data['widgets_list'];
    }    
  ?>
</div>
</div>