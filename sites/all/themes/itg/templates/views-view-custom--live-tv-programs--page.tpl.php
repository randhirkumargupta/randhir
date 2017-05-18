<h3><span><?php print t('Show videos'); ?></span></h3>
<?php
$episodes_text = '';
global $base_url;
$current_time_program_tid = itg_live_tv_page_video_category();
?>
<div class="programe-container">
  <?php
  foreach ($rows as $row) :
    if (function_exists('itg_category_manager_term_state')) {
      $status = itg_category_manager_term_state($row['tid']);
    }
    else {
      $status = 0;
    }
    if ($status) {
      $view = views_get_view('programme_content');
      $args = array($row['tid']);
      $view->preview('block', $args);
      $view_result = $view->result;
      $recent_video_under_cat = $view_result[0]->nid;
      if ($current_time_program_tid != $row['tid']) {
        ?>
        <div class="program-row">               
          <div class="program-right">
            <?php if (isset($row['field_cm_display_title'])) : ?>
              <div class="programe-title">
                <?php print l($row['field_cm_display_title'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
              </div>
            <?php endif; ?>
          </div>

          <div class="toggle-icon">
            <span class="plus"><i class="fa fa-plus-circle"></i></span>
            <span class="minus"><i class="fa fa-minus-circle"></i></span>
          </div>

        </div>
        <div class="program_data"><?php print views_embed_view('programme_content_live_tv', 'block', $row['tid']); ?></div>
      <?php }
    } endforeach; ?>
</div>
