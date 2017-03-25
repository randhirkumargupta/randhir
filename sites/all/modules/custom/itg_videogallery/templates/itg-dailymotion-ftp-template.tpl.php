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
            <div class="video-ftp active"><?php print t('FTP'); ?></div>
            <?php if ($_GET['input_filed'] != 'ckeditor' && $_GET['no_value'] != 'single'  ) { ?>
                <div class="video-local"><?php print t('Local Browse'); ?></div>
            <?php } ?>
                 <?php if ($_GET['field_name'] == 'field_videogallery_video_upload' ) { ?>
                <div class="video-local"><?php print t('Local Browse'); ?></div>
            <?php } ?>
            <div id="loader-data"><img class="widget-loader" style="display: none" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>

            <div class="ftp-server">
                <?php
                if ($_GET['file_filed_name'] == 'field_upload_video[und][0][fid]' || $_GET['field_name'] == 'field_videogallery_video_upload') {
                    if ($_GET['no_value'] == 'single') {
                        ?>
                        <iframe id="video_iframe" src="<?php echo base_path() . 'search-unpublish-video-radio'; ?>" width="900" height="650"></iframe>

                        <?php
                    }
                    else {
                        ?>

                        <iframe id="video_iframe" src="<?php echo base_path() . 'search-unpublish-video'; ?>" width="900" height="650"></iframe>
                    <?php
                    }
                }
                else {
                    if ($_GET['no_value'] == 'single' ) {
                        ?>
                        <iframe id="video_iframe" src="<?php echo base_path() . 'search-publish-video-radio'; ?>" width="900" height="650"></iframe>

                        <?php
                    }
                    else {
                        ?>

                        <iframe id="video_iframe" src="<?php echo base_path() . 'search-publish-video'; ?>" width="900" height="650"></iframe>
                        <?php
                    }
                }
                ?>
                <div class="video-options-wrapper"></div>
<?php if (isset($_GET['input_filed']) && $_GET['input_filed'] == 'ckeditor') { ?>
                    <a href="javascript:void(0)" class = "button asso-with-ckeditor"><?php print t('Associate Video'); ?></a>
                    <input type="hidden" id="single_add" name="single_add" value="0">
                    <?php
                }
                else if ($_GET['no_value'] == 'single') {
                    ?>
                    <input type="hidden" id="single_add" name="single_add" value="1">
                    <a href="javascript:void(0)" class = "button asso-filed_single" btn_name="<?php echo $_GET['btn_name']; ?>" field_name="<?php echo $_GET['field_name']; ?>"><?php print t('Associate Video'); ?></a>

                    <?php
                }
                else {
                    ?>
                    <input type="hidden" id="single_add" name="single_add" value="0">
                    <a href="javascript:void(0)" class = "button asso-filed"><?php print t('Associate Video'); ?></a>
            <?php } ?>
            </div>  
<?php //print drupal_render($form['video_browse_select']);       ?>
            <div class="local_browse" style="display: none;">

                <?php print drupal_render(drupal_get_form('videogallery_new_fileupload_form')); ?>

                    <?php if ($_GET['field_name'] == 'field_story_facebook_video' || $_GET['field_name'] == 'field_story_twitter_video' || $_GET['field_name'] == 'field_videogallery_video_upload' || $_GET['no_value'] == 'single') { ?>
                    <span class="button browse-local" btn_name="<?php echo $_GET['btn_name']; ?>" field_name="<?php echo $_GET['field_name']; ?>">
                        <?php
                        print t('Upload Video');
                        ?>

                    </span>
                    <?php
                }
                else {
                    ?>
                    <span class="button browse-local" btn_name="">
                        <?php
                        print t('Upload Video');
                        ?>

                    </span>
<?php } ?>

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