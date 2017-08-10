<div class="program-rhs">
    <h3><span><?php print t("Programmes") ?></span></h3>
    <ul>
        <?php
        global $base_url;
        foreach ($rows as $row) :
          if (function_exists('itg_category_manager_term_state')) {
            $status = itg_category_manager_term_state($row['tid']);
          } else {
            $status = 0;
          }
          if ($status) {
            $view = views_get_view('programme_content');
            $args = array($row['tid']);
            $view->preview('block', $args);
            $view_result = $view->result;
            $recent_video_under_cat = !empty($view_result[0]->nid) ? $view_result[0]->nid : '';
            ?>
            <li>
                <h4>
                    <?php if (!empty($row['field_cm_display_title'])) : ?>
                      <?php print l(__html_output_with_tags($row['field_cm_display_title']), 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
                    <?php endif; ?>
                </h4>
                <span class="time">
                    <?php if (!empty($row['field_program_timing_in_days'])) : ?>
                      <?php print $row['field_program_timing_in_days']; ?>
                    <?php endif; ?>

                    <?php print t(" at ") ?>

                    <?php if (!empty($row['field_user_city'])) : ?>
                      <?php print $row['field_user_city']; ?>
                    <?php endif; ?>

                    <?php if (!empty($row['field_time_period'])) : ?>
                      <?php print $row['field_time_period']; ?>
                    <?php endif; ?>
                </span>


                <div class="detail">
                    <div class="pic">
                        <?php if (isset($row['field_sponser_logo'])) : ?>
                          <?php
                          $img = $row['field_sponser_logo'];
                          ?>
                          <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
                        <?php else : ?>
                          <?php
                          $img = "<img width='88' height='66'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image88x66.jpg' alt='' />";
                          ?>
                          <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>

                        <?php endif; ?>
                    </div>
                    <div class="discription">
                        <?php if (!empty($row['description'])) : ?>
                          <?php print l(__html_output_with_tags($row['description']), 'node/' . $recent_video_under_cat, array('html' => TRUE , 'query' => array('category' => $row['tid']))); ?>
                        <?php endif; ?>

                    </div>
                </div>
            </li>
          <?php } endforeach; ?>
    </ul>
</div>