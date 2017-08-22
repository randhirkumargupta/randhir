<?php
/**
 * @file : itg-follow-unfollow-template.tpl.php
 */
?>
<div class="follow-social">
  <?php
    global $user; $user->uid = 261;
    $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    // prepare url for sharing
    $uri = base64_encode($actual_link);
    if ($user->uid > 0) {
     $follow_status = itg_get_front_activity_info($nid, '', $user->uid, $activity, '');

    if (!empty($follow_status['nid']) && $follow_status['status'] == '1') { ?>
        <div class="mhide follow-activity"><a title = "<?php print $unfollow_title; ?>" href="javascript:" id="<?php print $class; ?>" data-rel="<?php print $nid; ?>" data-tag="<?php print $source_type; ?>" data-activity="<?php print $activity; ?>" data-ftitle="<?php print $follow_title; ?>" data-untitle="<?php print $unfollow_title; ?>" data-status="0" class="def-cur-pointer"><?php print $unfollow_title; ?></a></div>
    <?php } else { ?>
        <div class="mhide follow-activity"><a title = "<?php print $follow_title; ?>" href="javascript:" id="<?php print $class; ?>" data-rel="<?php print $nid; ?>" data-tag="<?php print $source_type; ?>" data-activity="<?php print $activity; ?>" data-ftitle="<?php print $follow_title; ?>" data-untitle="<?php print $unfollow_title; ?>" data-status="1" class="def-cur-pointer"><?php print $follow_title; ?></a></div>
    <?php          }
  } else {
    ?>
      <div class="mhide">
          <a title="follow anchor" href="http://<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri;?>">
            <?php print t('follow anchor'); ?>
          </a>
      </div>
  <?php } ?>

</div>