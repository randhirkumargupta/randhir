<?php
$episodes_text = '';
global $base_url;
?>
<div class="programe-container">
  <?php
  foreach ($rows as $row) :
    $status = itg_category_manager_term_state($row['tid']);
    if ($status) {
      $view = views_get_view('programme_content');
      $args = array($row['tid']);
      $view->preview('block', $args);
      $view_result = $view->result;
      $recent_video_under_cat = $view_result[0]->nid;
      ?>
      <div class="program-row">
        <?php if (!empty($row['field_sponser_logo'])) : ?>
          <div class="pic">
            <?php print l($row['field_sponser_logo'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
          </div>
        <?php else : ?>
          <div class="pic">
            <?php
            $img = "<img width='88' height='66'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />";
            ?>
            <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
          </div>
        <?php endif; ?>
        <div class="program-right">
          <?php if (isset($row['field_cm_display_title'])) : ?>
            <div class="programe-title">
              <?php print l($row['field_cm_display_title'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
            </div>
          <?php endif; ?>

          <?php if (isset($row['field_user_city'])) : ?>
            <div class="programe-timing">
              <?php print $row['field_user_city']; ?>
            </div>
          <?php endif; ?>

          <?php if (isset($row['description'])) : ?>
            <div class="description-timing">
              <?php print $row['description']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
<div class="program_data"><?php print views_embed_view('programme_content_live_tv', 'block', $row['tid']); ?></div>
    <?php } endforeach; ?>
</div>
