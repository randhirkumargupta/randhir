<?php if (!empty($data)) : global $base_url, $theme; ?>
  <div class="KeyIssueOuterBorder">
      <div class="row">
          <?php foreach ($data as $value) { ?>
            <div class="col-xs-12 col-sm-6 col-md-6 col-lg-4">
                <?php if (!empty($value->field_story_external_url_value)) { ?>
                  <a href="<?php print $value->field_story_external_url_value; ?>">
                      <div class="keyImgSec"><img alt="<?php print $value->field_story_kicker_text_value; ?>" src="<?php print file_create_url($value->uri); ?>" /> <span class="imgBg"><?php print $value->field_cm_display_title_value; ?></span></div>
                  </a>
                <?php }
                else { ?>
                  <div class="keyImgSec"><img alt="<?php print $value->field_story_kicker_text_value; ?>" src="<?php print file_create_url($value->uri); ?>" /> <span class="imgBg"><?php print $value->field_cm_display_title_value; ?></span></div>
    <?php } ?>
            </div>
  <?php } ?>
      </div>
  </div>
<?php endif; ?>  