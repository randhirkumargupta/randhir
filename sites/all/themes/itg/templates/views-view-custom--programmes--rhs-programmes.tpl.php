<?php
global $base_url;
foreach ($rows as $row) :
  $view = views_get_view('programme_content');
  $args = array($row['tid']);
  $view->preview('block', $args);
  $view_result = $view->result;
  $recent_video_under_cat = $view_result[0]->nid;
  ?>
  <div class="title">
    <?php if (!empty($row['field_cm_display_title'])) : ?>
      <?php print l($row['field_cm_display_title'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
    <?php endif; ?>
  </div>

  <div class="timing">
    <?php if (!empty($row['field_user_city'])) : ?>
      <?php print $row['field_user_city']; ?>
    <?php endif; ?>
  </div>

  <div class="description">
    <?php if (!empty($row['description'])) : ?>
      <?php print $row['description']; ?>
    <?php endif; ?>
  </div>

  <div class="logo">
    <?php if (isset($row['field_sponser_logo'])) : ?>
      <?php
      $img = $row['field_sponser_logo'];
      ?>
      <div class="large-image">
        <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
      </div>
    <?php else : ?>
      <div class="large-image">
        <?php
        $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />";
        ?>
        <?php print l($img, 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
      </div>
    <?php endif; ?>
  </div>
<?php endforeach; ?>
