<?php if (!empty($data)) : global $base_url, $theme; ?>
<div class="whosaidSliderSec">
<div class="flexslider" id="Slider">
<ul class="slides">
  <?php foreach($data as $value){?>
    <li><img alt="<?php print $value->field_story_kicker_text_value;?>" src="<?php print file_create_url($value->uri);?>" />
      <?php if(!empty($value->field_story_external_url_value)){ ?>
        <a href="<?php print $value->field_story_external_url_value;?>"><p><?php print $value->field_story_kicker_text_value;?></p></a>
      <?php } else{?>
        <p><?php print $value->field_story_kicker_text_value;?></p>
      <?php }?>
      <span><?php print $value->field_cm_display_title_value;?></span>
    </li>
  <?php }?>
</ul>
</div>
</div>
<?php endif;?>  
