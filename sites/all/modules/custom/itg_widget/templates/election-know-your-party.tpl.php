<?php if (!empty($data)) : global $base_url, $theme; ?>
<div class="karnataka-partylist">
  <div class="partylist-body">
  <ul>
    <?php foreach($data as $value){?>
      <?php if(!empty($value->field_story_external_url_value)){ ?>
        <li><a href="<?php print $value->field_story_external_url_value;?>"><span class="party-logo"><img src="<?php print file_create_url($value->uri);?>" alt="<?php print $value->field_cm_display_title_value;?>"></span><span class="party-details"><h6><?php print $value->field_cm_display_title_value;?></h6><p><?php print $value->field_story_kicker_text_value;?></p></span></a></li>
        <?php } else{?>
        <li><span class="party-logo"><img src="<?php print file_create_url($value->uri);?>" alt="<?php print $value->field_cm_display_title_value;?>"></span><span class="party-details"><h6><?php print $value->field_cm_display_title_value;?></h6><p><?php print $value->field_story_kicker_text_value;?></p></span></li>
      <?php }?>
    <?php }?>
  </ul>
</div> 
</div>
<?php endif;?>  