<h2 class="block-title">Template widgets</h2>
<ul id="templates-widgets" class="no-bullet pd-10">
  <?php 
    foreach($data as $key => $val) {
     $widget = explode('|', $val['value']); 
  ?>
  <li data-widget="<?php print $widget[1];?>"><span><?php print $widget[0];?></span></li>
  <?php } ?>   
</ul>
<?php
//print views_embed_view('test_views','block');
?>