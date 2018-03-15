<div class="magazin-lhs-top">
  <?php foreach ($rows as $index => $row): ?>
    <div class="magazin-top">
      <div class="magazin-top-left">
          <?php
          $migrated = $row['field_story_source_type'];
          $show_web_exclusive = variable_get('show_web_exclusive');
          $is_magazine_page = FALSE;
          $year_arr = !empty(arg(1)) ? explode('-', arg(1)) : '';
          if (empty($year_arr[2])) {
            $year = itg_msi_issue_attribute_date();
            $issue_attribute_date = strip_tags(date('Y-m-d', strtotime($year)));
            $is_magazine_page = TRUE;
          }
          else {
            $issue_attribute_date = strip_tags($row['field_issue_title_1']);
          }
          ?>
          <?php if ($is_magazine_page && $show_web_exclusive) {
            $view = views_get_view_result('magazine_top_story', 'block_1', $issue_attribute_date);
            $nid_arr[] = $view[0]->nid;
            ?>
            <span class="web-excl"><?php print t('Web Exclusive'); ?></span>
            <?php
            print views_embed_view('magazine_top_story', 'block_1', $issue_attribute_date);             
            }
            else {            
              $view = views_get_view_result('magazine_top_story', 'block_2', $issue_attribute_date);
              $count_issue = count($view);
              if ($count_issue > 0) { 
            ?>
            <span class="web-excl"><?php print t('Cover Story'); ?></span>
            <?php }
                print_r(views_embed_view('magazine_top_story', 'block_2', $issue_attribute_date));
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
        if ($is_magazine_page && $show_web_exclusive) {          
          $view = views_get_view_result('magazine_top_story', 'block', $issue_attribute_date);
          foreach ($view as $key => $view_val) {
            $nid_arr[] = $view_val->nid;
          }
          print views_embed_view('magazine_top_story', 'block', $issue_attribute_date);
        }
        else {
          print views_embed_view('magazine_top_story', 'block_3', $issue_attribute_date);
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
      $data = itg_msi_issue_category_data($issue_attribute_date, $nid_arr);
    }
    if (function_exists('itg_msi_issue_suppliment_data')) {
      $supplement_value = itg_msi_issue_suppliment_data($issue_attribute_date, $nid_arr);
    }
    $style_name = 'section_ordering_widget';
    $final_data_array = array();
    if (!empty($data)) {
      foreach ($data as $parent_key1 => $parent_value1) {
        $sub_title = '';
        $all_terms = array();
        $all_terms = taxonomy_get_parents_all($parent_key1);
        $number_parent = count($all_terms);
        $section_key = $number_parent - 1;
        if ((($is_magazine_page && $show_web_exclusive) || ($parent_key1 != '1206509')) && $all_terms[$section_key]->tid != '1206499') {
          $section_data_final[$parent_key1] = $parent_value1;
        }
        //~ $section_data_final[$parent_key1] = $parent_value1;
      }
    }

    $total_count = count($supplement_value) + count($data);
    $counter = -1;
    foreach ($supplement_value as $supplement_value1) {
      $counter += 2;
      $supplement_value1['type'] = 'suppliment';
      $final_data_array[$counter] = $supplement_value1;
    }
    $counter1 = 0;
    foreach ($section_data_final as $value1) {
      $value1['type'] = 'section';
      $final_data_array[$counter1] = $value1;
      if ($counter1 < $counter) {
        $counter1 += 2;
      }
      else {
        $counter1 += 1;
      }
    }
    ksort($final_data_array);

    $final_data_array_left = array();
    $final_data_array_right = array();
    foreach ($final_data_array as $key => $value) {
      if ($key % 2 == 0) {
        $final_data_array_left[] = $value;
      }
      else {
        $final_data_array_right[] = $value;
      }
    }
    print '<div class="col-md-6 col-sm-6 col-xs-12 mt-50">';
    foreach ($final_data_array_left as $final_key => $final_value) {
      if ($final_value['type'] == 'section') {
        unset($final_value['type']);
        $parent_value = $final_value;        
        $sub_title = '';     
        foreach ($parent_value as $key => $value) {		  
		  // get status of lock story
          if (function_exists(itg_msi_get_lock_story_status)) {
            $lock_story = itg_msi_get_lock_story_status($value->nid, 'lock_story');
          }
          if ($key == 0) {
            $img_url = '';
            $img = '';
            if (!empty($value->uri)) {
              $img_url = '<img src="' . image_style_url($style_name, $value->uri) . '" alt="" title=""/>';
            }
            // Get the short headline for a node data
            $shortheadline_cat = $value->field_story_short_headline_value;
            if (!empty($lock_story)) {
              if(!empty($img_url)) {
                    $img = l($img_url, 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage', array('html' => TRUE));
              }
              $title = l(t($shortheadline_cat), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage');
              $title = '<h3 class="lock" title="' . strip_tags($title) . '">' . $title . '</h3>';
            }
            else {
              if(!empty($img_url)) {  
                $img = l($img_url, 'node/' . $value->nid, array('html' => TRUE));
              }
              $title = l(t($shortheadline_cat), 'node/' . $value->nid);
              $title = '<h3 title="' . strip_tags($title) . '">' . $title . '</h3>';
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
        $output = '<span class="widget-title">' . t($value->name) . '</span>';
        $output .= $img;
        $output .= $title;
        if (!empty($sub_title)) {
          $output .= $sub_title;
        }
        print '<div ' . $class . '><div class="section-ordering">' . $output . '</div></div>';
      }
    }
    print '</div>';

    // for right culmn
    print '<div class="col-md-6 col-sm-6 col-xs-12 mt-50">';
    foreach ($final_data_array_right as $final_key => $final_value) {
      if ($final_value['type'] == 'section') {
        unset($final_value['type']);
        $parent_value = $final_value;   
        $sub_title = '';     
        foreach ($parent_value as $key => $value) {			  
          // get status of lock story
          if (function_exists(itg_msi_get_lock_story_status)) {
            $lock_story = itg_msi_get_lock_story_status($value->nid, 'lock_story');
          }
          if ($key == 0) {
              $img_url = '';
              $img = '';
            if (!empty($value->uri)) {
              $img_url = '<img src="' . image_style_url($style_name, $value->uri) . '" alt="" title=""/>';
            }
            // Get the short headline for a node data
            $shortheadline_cat = $value->field_story_short_headline_value;
            if (!empty($lock_story)) {
              if(!empty($img_url)) {  
                $img = l($img_url, 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage', array('html' => TRUE));
              }
              $title = l(t($shortheadline_cat), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage');
              $title = '<h3 class="lock" title="' . strip_tags($title) . '">' . $title . '</h3>';
            }
            else {
              if(!empty($img_url)) {  
                $img = l($img_url, 'node/' . $value->nid, array('html' => TRUE));
              }
              $title = l(t($shortheadline_cat), 'node/' . $value->nid);
              $title = '<h3 title="' . strip_tags($title) . '">' . $title . '</h3>';
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
        $output = '<span class="widget-title">' . t($value->name) . '</span>';
        $output .= $img;
        $output .= $title;
        if (!empty($sub_title)) {
          $output .= $sub_title;
        }
        print '<div ' . $class . '><div class="section-ordering">' . $output . '</div></div>';
      }
      else if ($final_value['type'] == 'suppliment') {
        unset($final_value['type']);
        $supplement_value = $final_value;
        $sup_sub_title = '';
        foreach ($supplement_value as $key => $s_value) {
          // get status of lock story
          if (function_exists(itg_msi_get_lock_story_status)) {
            $lock_story = itg_msi_get_lock_story_status($s_value->nid, 'lock_story');
          }
          if ($key == 0) {
              $supp_img_url = '';
              $supp_img = '';
            if (!empty($s_value->uri)) {
              $supp_img_url = '<img src="' . image_style_url($style_name, $s_value->uri) . '" alt="" title="" />';
            }
            // Get the short headline for a node data
            $shortheadline_supp = $s_value->field_story_short_headline_value;
            if (!empty($lock_story)) {
              if(!empty($supp_img_url)) {  
                $supp_img = l($supp_img_url, 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage', array('html' => TRUE));
              }
              $supp_title = '<h3 class="lock">'. l(t($shortheadline_supp), 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage'). '</h3>';
            }
            else {
              if(!empty($supp_img_url)) {
                $supp_img = l($supp_img_url, 'node/' . $s_value->nid, array('html' => TRUE));
              }
              $supp_title = '<h3>' . l(t($shortheadline_supp), 'node/' . $s_value->nid) . '</h3>';
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
        $supp_output .= $supp_title;
        if (!empty($sup_sub_title)) {
          $supp_output .= $sup_sub_title;
        }
        print '<div class="section-ordering">' . $supp_output . '</div>';
      }
    }
    print '</div>';
    ?>
</div>
