<div id="BasicDetails">
  <?php print drupal_render($form['field_service_association_title']); ?>
  <?php print drupal_render($form['field_footer']); ?>
  <?php print drupal_render($form['field_service_frequency']); ?>
  <?php print drupal_render($form['field_service_frequency_date']); ?>
  <?php print drupal_render($form['field_service_content']); ?>
</div>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
<div id="loader-data"><img class="widget-loader" style="display: none" src="<?php echo base_path(); ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>

<div class="browse-ftp">
    <div id="itg_video_content">
      <div class="video-ftp active"><?php print t('Server'); ?></div>
      <div class="video-local"><?php print t('Local Browse'); ?></div>
      <div id="loader-data"><img class="widget-loader" style="display: none" src="<?php echo base_path(); ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>

      <div class="ftp-server">
        <div class="video_filters">
          <label><?php echo t('Filter') ?>:</label><select class="used-unused-select">
              <option value="unused"><?php print t("Un Published"); ?></option>
              <option value="used"><?php print t("Published"); ?></option>
            </select>
          <div class="time-filter">
            <label><?php echo t('Select Time') ?>:</label><select class="time-filter-select">
                <option value="-all-"><?php print t("All"); ?></option>  
                <option value="2"><?php print t("2 Hours"); ?></option>
                <option value="4"><?php print t("4 Hours"); ?></option>
                <option value="6"><?php print t("6 Hours"); ?></option>
                <option value="10"><?php print t("10 Hours"); ?></option>
                <option value="24"><?php print t("24 Hours"); ?></option>
              </select>
          </div>
        </div>
        <div class="video-options-wrapper"></div>
        <a href="javascript:void(0)" class = "button"><?php print t('Attach Video'); ?></a>
      </div>  
      <?php //print drupal_render($form['video_browse_select']); ?>
      <div class="local_browse" style="display: none">
        <span class="button browse-local"><?php print t('Browse Video'); ?></span>
      </div>
    </div>
  </div>

<!--  <div class="browse-video-form"><?php print drupal_render($form['field_upload_video']); ?>
    <div class="ftp_browse_field"><label for="edit-field-upload-video-und-0-upload">Video <span title="This field is required." class="form-required">*</span></label><span class="browse-ftp-click">Browse Video</span></div>
    <span class="error vid-error"></span>
  </div>-->