<div class="program-rhs">
  <h3><span><?php print t("Programmes") ?></span></h3>
  <ul>
    <?php
    global $base_url;
    foreach ($rows as $row) :
      $status = itg_category_manager_term_state($row['tid']);
      if ($status) {
        $view = views_get_view('programme_content');
        $args = array($row['tid']);
        $view->preview('block', $args);
        $view_result = $view->result;
        $recent_video_under_cat = $view_result[0]->nid;
        ?>
        <li>
          <h4>
            <?php if (!empty($row['field_cm_display_title'])) : ?>
              <?php print l($row['field_cm_display_title'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
            <?php endif; ?>
          </h4>

          <span class="time"> <?php if (!empty($row['field_user_city'])) : ?>
              <?php print $row['field_user_city']; ?>
            <?php endif; ?></span>
          <div class="detail">
            <div class="pic">
              <?php if (isset($row['field_sponser_logo'])) : ?>
                <?php
                $img = $row['field_sponser_logo'];
                ?>
                <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
              <?php else : ?>
                <?php
                $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />";
                ?>
                <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>

              <?php endif; ?>
            </div>
            <div class="discription">
              <?php if (!empty($row['description'])) : ?>
                <?php print l($row['description'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
              <?php endif; ?>

            </div>
          </div>
        </li>
      <?php } endforeach; ?>
  </ul>
</div>