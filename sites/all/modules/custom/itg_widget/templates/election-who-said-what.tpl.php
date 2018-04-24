<?php if (!empty($data)) : global $base_url, $theme; ?>
<div class="whosaidSliderSec">
<div class="flexslider" id="Slider">
<ul class="slides">
  <?php foreach($data as $value){?>
    <li><img alt="<?php print $value->field_story_kicker_text_value;?>" src="<?php print file_create_url($value->uri);?>" />
      <a href="<?php print $value->field_story_external_url_value;?>"><p><?php print $value->field_story_kicker_text_value;?></p></a>
      <span><?php print $value->field_cm_display_title_value;?></span>
    </li>
  <?php }?>
</ul>
</div>
</div>
<script type="text/javascript">
    jQuery('.flexslider#Slider').flexslider({
        animation: "slide",
        controlNav:false,
        slideshow:false,
        //animationLoop:false
      });
</script>
<?php endif;?>  
