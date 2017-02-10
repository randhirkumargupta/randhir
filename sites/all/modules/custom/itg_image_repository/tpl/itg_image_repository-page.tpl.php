<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $GLOBALS['language']->language; ?>" xml:lang="<?php print $GLOBALS['language']->language; ?>" class="itg_image_repository">

    <head>
        <title><?php print t('File Browser'); ?></title>
        <meta name="robots" content="noindex,nofollow" />
        <?php
        if (isset($_GET['app'])): drupal_add_js(drupal_get_path('module', 'itg_image_repository') . '/js/itg_image_repository_set_app.js');
        endif;
        ?>
        <?php print drupal_get_html_head(); ?>
        <?php print drupal_get_css(); ?>
        <?php print drupal_get_js('header'); ?>

    </head>

    <body class="itg_image_repository">
        <div id="itg_image_repository-messages"><?php print theme('status_messages'); ?></div>
        <?php print $content; ?>
        <input type="hidden" id="field_name" value="<?php echo $_GET['field_name']; ?>" >
            <input type="hidden" id="image_height" value="<?php echo $_GET['height']; ?>" >
                <input type="hidden" id="image_width" value="<?php echo $_GET['width']; ?>" >
                    <input type="hidden" id="btn_name" value="<?php echo $_GET['btn_name']; ?>" >
                          <input type="hidden" id="is_custom_form" value="<?php echo $_GET['custom_form']; ?>" >
                              
                        <input type="hidden" id="content_type" value="<?php echo arg(3); ?>" >
                        <input type="hidden" id="img_alttext" value="" >
                            <input type="hidden" id="img_title" value="" >
                                <?php
                                $ckeditorcheck = explode('|', $_GET['app']);
                                if ($ckeditorcheck[0] == 'ckeditor') {
                                    echo '<input type="hidden" id="ckeditor_yes" value="1" >';
                 }
                                ?>
                                <script type="text/javascript">
                                    var fieldname = '<?php echo $_GET['field_name']; ?>';
                                    var height = '<?php echo $_GET['height']; ?>';
                                    var width = '<?php echo $_GET['width']; ?>';
                                    var content_type = '<?php echo arg(3); ?>';

                                </script>

                                <?php
                                drupal_add_js(drupal_get_path('module', 'itg_image_repository') . '/js/itg_image_repo.js', array('
  type' => 'file', 'scope' => 'footer'));
                                print drupal_get_js('footer');
                                ?>
                                </body>

                                </html>
