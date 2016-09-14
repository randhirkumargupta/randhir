<div class="magazin-lhs-top">
  <?php foreach ($rows as $index => $row): ?>
    <div class="magazin-top">
      <div class="magazin-top-left">
        <span class="web-excl">web exclusive</span>
        <?php
        $issue_attribute_date = strip_tags($row['field_issue_title_1']);
        print views_embed_view('magazine_top_story', 'block_1', $issue_attribute_date);
        ?>
      </div>


      <div class="magazin-subscribe">
        <span class="latest-issue">latest issue</span>
        <div class="issue-image"><?php print $row['field_issue_large_cover_image']; ?></div>
        <div class="issue-title"><?php print $row['field_issue_title']; ?></div>
        <?php
        $current_issues = itg_msi_get_current_issue();
        $current_issue = explode(' 00:', $current_issues);
        ?>
        <?php if ($current_issue[0] == $issue_attribute_date): ?>
          <div class="issue-subscribe-link"><?php print $row['nothing']; ?></div>
        <?php endif; ?>
        <?php $future_isue = itg_msi_next_week_issue(); ?>
        <?php if ($future_isue): ?>
          <div class="next-issue-out"><span class="text">Next issue out on </span><span class="issue-next-date"><?php print $future_isue; ?></span></div>
        <?php endif; ?>
      </div>
    </div>

    <div class="magazin-bottom">
      <?php print views_embed_view('magazine_top_story', 'block', $issue_attribute_date); ?>
    </div>
  <?php endforeach; ?>
</div>
<div class="row magazin-section">
<?php
// category based story according issue date
$data = itg_msi_issue_category_data($issue_attribute_date);
//pr($data);
$style_name = 'section_ordering_widget';
foreach ($data as $parent_key => $parent_value) {
  $sub_title = '';
  foreach ($parent_value as $key => $value) {
    if ($key == 0) {
      $img_url = '<img src="' . image_style_url($style_name, $value->uri) . '"/>';
      $img = l($img_url, 'node/' . $value->nid, array('html' => TRUE));
      $title = l(t(truncate_utf8($value->title, 40, TRUE, TRUE)), 'node/' . $value->nid);
    }
    elseif ($key > 0 && $key < 3) {
      $sub_title .= '<p>' . l(t(truncate_utf8($value->title, 40, TRUE, TRUE)), 'node/' . $value->nid) . '</p>';
    }
  }

  $output = $img;
  $output .= '<span class="widget-title">' . t($value->name) . '</span>';
  $output .= '<h3>' . $title . '</h3>';
  if (!empty($sub_title)) {
    $output .= $sub_title;
  }
  print '<div class="col-md-6 col-sm-12 col-xs-12 mt-50"><div class="section-ordering">' . $output . '</div></div>';
}



// suppliment based story according issue date
$supplement_value = itg_msi_issue_suppliment_data($issue_attribute_date);
if(isset($supplement_value)){
foreach ($supplement_value as $suppliment_key => $suppliment_value) {
  $sup_sub_title = '';
  foreach ($suppliment_value as $key => $s_value) {
    if ($key == 0) {
      $supp_img_url = '<img src="' . image_style_url($style_name, $s_value->uri) . '"/>';
      $supp_img = l($supp_img_url, 'node/' . $s_value->nid, array('html' => TRUE));
      $supp_title = l(t(truncate_utf8($s_value->title, 40, TRUE, TRUE)), 'node/' . $value->nid);
    }
    elseif ($key > 0 && $key < 3) {
      $sup_sub_title .= '<p>' . l(t(truncate_utf8($s_value->title, 40, TRUE, TRUE)), 'node/' . $value->nid) . '</p>';
    }
  }
  $supp_output = $supp_img;
  $supp_output .= '<span class="widget-title">' . itg_msi_issue_suppliment_title($s_value->field_story_select_supplement_target_id) . '</span>';

  $supp_output .= '<h3>' . $supp_title . '</h3>';
  if (!empty($sup_sub_title)) {
    $supp_output .= $sup_sub_title;
  }
  print '<div class="col-md-6 col-sm-12 col-xs-12 mt-50"><div class="section-ordering">' . $supp_output . '</div></div>';
}
}
?>
</div>