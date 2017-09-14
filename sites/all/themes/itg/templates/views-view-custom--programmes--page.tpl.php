<?php
$episodes_text = '';
global $base_url;
?>
<div class="programe-container">
    <?php
    foreach ($rows as $row) :
      $view = views_get_view('programme_content');
      $args = array($row['tid']);
      $view->preview('block' , $args);
      $view_result = $view->result;
      $recent_video_under_cat = $view_result[0]->nid;
      ?>
      <div class="program-row">
          <?php if (!empty($row['field_sponser_logo'])) : ?>
            <div class="pic">
                <?php if ($recent_video_under_cat) : ?>
                  <?php print l($row['field_sponser_logo'] , 'node/' . $recent_video_under_cat , array('query' => array('category' => $row['tid']) , 'html' => TRUE)); ?>
                <?php else : ?>
                  <?php echo $row['field_sponser_logo']; ?>
                <?php endif; ?>
            </div>
          <?php else : ?>
            <div class="pic">
                <?php
                $img = "<img width='88' height='66'  src='" . $base_url . '/' . drupal_get_path('theme' , 'itg') . "/images/itg_image88x66.jpg' alt='' />";
                ?>
                <?php if ($recent_video_under_cat) : ?>
                  <?php print l($img , 'node/' . $recent_video_under_cat , array('query' => array('category' => $row['tid']) , 'html' => TRUE)); ?>
                <?php else : ?>
                  <?php echo $img; ?>
                <?php endif; ?>
            </div>
          <?php endif; ?>
          <div class="program-right">
              <?php if (isset($row['field_cm_display_title'])) : ?>
                <div class="programe-title">
                    <?php if ($recent_video_under_cat) : ?>
                      <?php print html_entity_decode(l($row['field_cm_display_title'] , 'node/' . $recent_video_under_cat , array('query' => array('category' => $row['tid']) , 'html' => TRUE))); ?>
                    <?php else : ?>
                      <?php echo html_entity_decode($row['field_cm_display_title']); ?>
                    <?php endif; ?>
                </div>
              <?php endif; ?>

              <?php if (isset($row['field_program_timing_in_days'])) : ?>
                <div class="programe-timing">
                    <?php print $row['field_program_timing_in_days']; ?>

                    <?php print t(" at ") ?>

                    <span class="time">
                        <?php if (!empty($row['field_user_city'])) : ?>
                          <?php print $row['field_user_city']; ?>
                        <?php endif; ?>

                        <?php if (!empty($row['field_time_period'])) : ?>
                          <?php print $row['field_time_period']; ?>
                        <?php endif; ?>
                    </span>
                </div>
              <?php endif; ?>


              <?php if (isset($row['description'])) : ?>
                <div class="description-timing mhide">
                    <p> <?php print html_entity_decode($row['description']); ?></p>
                </div>
              <?php endif; ?>
          </div>

          <?php if (isset($row['description'])) : ?>
            <div class="description-timing desktop-hide">
                <p><?php print html_entity_decode($row['description']); ?></p>
            </div>
          <?php endif; ?>

      </div>
      <div class="heading">
          <?php
          $episodes_text = $row['name'];
          print t("<h3>Latest episodes from " . $episodes_text . "</h3>");
          ?>
      </div>
      <?php print views_embed_view('programme_content' , 'block' , $row['tid']); ?>
    <?php endforeach; ?>
</div>
