<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
global $user;
if (isset($view->result[0]->nid)) {
  $this_nid = $view->result[0]->nid;

  $isCookies = itg_poll_isCookies($this_nid);
  $poll_uid = itg_poll_getcurrent_userpoll($this_nid, $user->uid);
}
?>
<?php if ((isset($isCookies) && $isCookies == 'yes' && user_is_anonymous()) || (isset($_SESSION['first_submit_anomoyous']) && $_SESSION['first_submit_anomoyous'] == 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid == $user->uid)) { ?>
  <?php
  if (isset($view->result[0]->_field_data['nid']['entity']->field_poll_end_date)) {
    $end_date = $view->result[0]->_field_data['nid']['entity']->field_poll_end_date[LANGUAGE_NONE][0]['value'];
    $etime = strtotime($end_date);
    //$endtime = mktime(23, 59, 59, date("m", $etime), date("d", $etime), date("Y", $etime));
    $endtime = $etime;
  }
  $display_format = $view->result[0]->_field_data['nid']['entity']->field_display_result[LANGUAGE_NONE][0]['value'];
  ?>
  <?php
  if (($display_format == 1) || ($display_format == 2 && $endtime < time())) {
    ?>
    <?php print $wrapper_prefix; ?>
    <?php if (!empty($title)) : ?>
      <h3><?php print $title; ?></h3>
    <?php endif; ?>
    <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <li class="<?php print $classes_array[$id]; ?>"><?php print $row; ?></li>
    <?php endforeach; ?>
    <?php print $list_type_suffix; ?>
    <?php print $wrapper_suffix; ?>
    <?php
  }
  else {
    print "<div class='poll-complete-message'>You have already polled. We will show result after Poll Completion.</div>";
  }
    unset($_SESSION['first_submit_anomoyous']);
}
?>
