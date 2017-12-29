<div class="magazin-lhs-top">
  <?php foreach ($rows as $index => $row): ?>
    <div class="magazin-top">
      <div class="magazin-top-left">
          <?php
          $migrated = $row['field_story_source_type'];
          $year_arr = !empty(arg(1)) ? explode('-', arg(1)) : '';
          if (empty($year_arr[2])) {
            $year = itg_msi_issue_attribute_date();
            $issue_attribute_date = strip_tags(date('Y-m-d', strtotime($year)));
          }
          else {
            $issue_attribute_date = strip_tags($row['field_issue_title_1']);
          }
          $view = views_get_view_result('magazine_top_story', 'block_2', $issue_attribute_date);
          $count_issue = count($view);
          ?>
          <?php if ($row['field_story_source_type'] == 'migrated' && $count_issue > 0) { ?>
            <span class="web-excl"><?php print t('Cover Story'); ?></span>
            <?php
            print_r(views_embed_view('magazine_top_story', 'block_2', $issue_attribute_date));
          }
          else {
            ?>
            <span class="web-excl"><?php print t('web exclusive'); ?></span>
            <?php
            print views_embed_view('magazine_top_story', 'block_1', $issue_attribute_date);
          }
          ?>
      </div>

      <div class="magazin-subscribe magazin-desktop">
        <span class="latest-issue"><?php print t('latest issue'); ?></span>
        <div class="issue-image"><?php print $row['field_issue_large_cover_image']; ?></div>
        <div class="issue-title">
          <?php print $row['field_issue_title']; ?>
        </div>
        <?php
        $current_issues = itg_msi_get_current_issue();
        $current_issue = explode(' 00:', $current_issues);
        ?>
        <?php if ($current_issue[0] == $issue_attribute_date): ?>
          <div class="issue-subscribe-link"><?php print $row['nothing']; ?></div>
        <?php endif; ?>
        <?php $future_isue = itg_msi_next_week_issue(); ?>
        <?php if ($future_isue): ?>
          <div class="next-issue-out"><span class="text"><?php print t('Next issue out on') ?> </span><span class="issue-next-date"><?php print $future_isue; ?></span></div>
        <?php endif; ?>
      </div>
    </div>

    <div class="magazin-bottom">
      <?php 
        if ($row['field_story_source_type'] == 'migrated' && $count_issue > 0) {
          print views_embed_view('magazine_top_story', 'block_3', $issue_attribute_date);
        }
        else {
          print views_embed_view('magazine_top_story', 'block', $issue_attribute_date);
        }
        ?>
    </div>
  <?php endforeach; ?>
</div>
<div class="magazin-lhs-top magazin-mob">
  <div class="magazin-top">
    <div class="magazin-subscribe">
      <span class="latest-issue"><?php print t('latest issue'); ?></span>
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
        <div class="next-issue-out"><span class="text"><?php print t('Next issue out on') ?> </span><span class="issue-next-date"><?php print $future_isue; ?></span></div>
      <?php endif; ?>
    </div>
  </div>
</div>
<div class="row magazin-section">
  <?php
  global $base_url;
// category based story according issue date
  if (function_exists('itg_msi_issue_category_data')) {
    $data = itg_msi_issue_category_data($issue_attribute_date);
  }
  if (function_exists('itg_msi_issue_suppliment_data')) {
    $supplement_value = itg_msi_issue_suppliment_data($issue_attribute_date);
  }
  if (isset($supplement_value)) {
    $class = '';
    print '<div class="col-md-6 col-sm-6 col-xs-12 mt-50">';
  }
  else {

    $class = ' class="col-md-6 col-sm-6 col-xs-12 mt-50"';
  }
  $style_name = 'section_ordering_widget';
  if (!empty($data)) {
    foreach ($data as $parent_key => $parent_value) {
    $sub_title = '';
    $all_terms = array();
    $all_terms = taxonomy_get_parents_all($parent_key);
    $number_parent = count($all_terms);
    $section_key = $number_parent - 1;
    if(TRUE || $parent_key != '1206509' && $all_terms[$section_key]->tid != '1206499' && $migrated == 'migrated') {
      foreach ($parent_value as $key => $value) {
        // get status of lock story
        if (function_exists(itg_msi_get_lock_story_status)) {
          $lock_story = itg_msi_get_lock_story_status($value->nid, 'lock_story');
        }
        if ($key == 0) {
          if (!empty($value->uri)) {
            $img_url = '<img src="' . image_style_url($style_name, $value->uri) . '" alt="" title=""/>';
          }
          else {
            $img_url = "<img src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
          }
          // Get the short headline for a node data
          $shortheadline_cat = $value->field_story_short_headline_value;
          if (!empty($lock_story)) {
            $img = l($img_url, 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage', array('html' => TRUE));
            $title = l(t($shortheadline_cat), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage');
          }
          else {
            $img = l($img_url, 'node/' . $value->nid, array('html' => TRUE));
            $title = l(t($shortheadline_cat), 'node/' . $value->nid);
          }
        }
        elseif ($key > 0) {
          if (!empty($lock_story)) {
            $sub_title .= '<p class="lock">' . l(t($value->field_story_short_headline_value), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage') . '</p>';
          }
          else {
            $sub_title .= '<p>' . l(t($value->field_story_short_headline_value), 'node/' . $value->nid) . '</p>';
          }
        }
      }
      if (!empty($lock_story)) {
        $lock_class = 'class="lock"';
      }

      $output = '<span class="widget-title">' . t($value->name) . '</span>';
      $output .= $img;

      if (!empty($lock_story)) {
        $output .= '<h3 class="lock" title="' . strip_tags($title) . '">' . $title . '</h3>';
      }
      else {
        $output .= '<h3 title="' . strip_tags($title) . '">' . $title . '</h3>';
      }

      if (!empty($sub_title)) {
        $output .= $sub_title;
      }
      print '<div ' . $class . '><div class="section-ordering">' . $output . '</div></div>';
    }
   }
  }
  if (isset($supplement_value) && !empty($supplement_value)) {
    print '</div>';
  }


// suppliment based story according issue date

  if (isset($supplement_value) && !empty($supplement_value)) {
    print '<div class="col-md-6 col-sm-6 col-xs-12 mt-50">';
    foreach ($supplement_value as $suppliment_key => $suppliment_value) {
      $sup_sub_title = '';
      foreach ($suppliment_value as $key => $s_value) {
        // get status of lock story
        if (function_exists(itg_msi_get_lock_story_status)) {
          $lock_story = itg_msi_get_lock_story_status($s_value->nid, 'lock_story');
        }
        if ($key == 0) {
          if (!empty($s_value->uri)) {
            $supp_img_url = '<img src="' . image_style_url($style_name, $s_value->uri) . '" alt="" title="" />';
          }
          else {
            $supp_img_url = "<img src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
          }
          // Get the short headline for a node data
          $shortheadline_supp = $s_value->field_story_short_headline_value;
          if (!empty($lock_story)) {
            $supp_img = l($supp_img_url, 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage', array('html' => TRUE));
            $supp_title = l(t($shortheadline_supp), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage');
          }
          else {
            $supp_img = l($supp_img_url, 'node/' . $s_value->nid, array('html' => TRUE));
            $supp_title = l(t($shortheadline_supp), 'node/' . $s_value->nid);
          }
        }
        elseif ($key > 0) {
          if (!empty($lock_story)) {
            $sup_sub_title .= '<p class="lock">' . l(t($s_value->field_story_short_headline_value), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage') . '</p>';
          }
          else {
            $sup_sub_title .= '<p>' . l(t($s_value->field_story_short_headline_value), 'node/' . $s_value->nid) . '</p>';
          }
        }
      }      
      $supp_output = '<span class="widget-title">' . itg_msi_issue_suppliment_title($s_value->field_story_select_supplement_target_id) . '</span>';
      $supp_output .= $supp_img;
      if (!empty($lock_story)) {
        $supp_output .= '<h3 class="lock">' . $supp_title . '</h3>';
      }
      else {
        $supp_output .= '<h3>' . $supp_title . '</h3>';
      }

      if (!empty($sup_sub_title)) {
        $supp_output .= $sup_sub_title;
      }
      print '<div class="section-ordering">' . $supp_output . '</div>';
    }
    print '</div>';
  }
  ?>
</div>
