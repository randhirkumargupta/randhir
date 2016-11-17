<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
global $base_url;
?>
<div id="videoupload">
  <div class="browse-ftp">
    <div id="itg_video_content">
      <div class="video-ftp active"><?php print t('Server'); ?></div>
      <div class="video-local"><?php print t('Local Browse'); ?></div>
      <div id="loader-data"><img class="widget-loader" style="display: none" align="center" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>

      <div class="ftp-server">
        <div class="video_filters">
          <div class="video-search">
            <label><?php echo t('Search by title'); ?>:</label><input type="text" id="video_text_search" onkeyup="videosearch()"/>
          </div>
          <label><?php echo t('Filter By') ?>:</label><select class="used-unused-select">
              <option value="unused"><?php print t("Un Published"); ?></option>
              <option value="used"><?php print t("Published"); ?></option>
            </select>
          
          <div class="time-filter">
            <label><?php echo t('Time range') ?>:</label><select class="time-filter-select">
                <option value="-all-"><?php print t("All"); ?></option>  
                <option value="2"><?php print t("2 Hours"); ?></option>
                <option value="4"><?php print t("4 Hours"); ?></option>
                <option value="6"><?php print t("6 Hours"); ?></option>
                <option value="10"><?php print t("10 Hours"); ?></option>
                <option value="24"><?php print t("24 Hours"); ?></option>
              </select>
          </div>
          <div class="reset_video_filter">
            <span class="button reset_video_filters">Reset</span>
          </div>
        </div>
        <div class="video-options-wrapper"></div>
        <a href="javascript:void(0)" class = "button"><?php print t('Associate Video'); ?></a>
      </div>  
      <?php //print drupal_render($form['video_browse_select']); ?>
      <div class="local_browse" style="display: none">
        <span class="button browse-local"><?php print t('Browse Video'); ?></span>
      </div>
    </div>
  </div>
<!--    <div class="ftp_browse_field"><label for="edit-field-upload-video-und-0-upload">Video <span title="This field is required." class="form-required">*</span></label><span class="browse-ftp-click">Browse Video</span></div>
    <span class="error vid-error"></span>
  </div>-->
</div>

<?php 
$field_id = $_GET['input_filed'];
$file_field_name = $_GET['file_filed_name'];
 
  $settings = array();
  $settings['base_url'] = $base_url;
  $settings['video_field_id'] = $field_id;
  $settings['video_field_file'] = $file_field_name;
  drupal_add_js(array('itg_dailymotion' => array('settings' => $settings)), array('type' => 'setting'));
 drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_dailymotion.js', array('weight' => 1));
 
?>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery.easyPaginate.js"></script>