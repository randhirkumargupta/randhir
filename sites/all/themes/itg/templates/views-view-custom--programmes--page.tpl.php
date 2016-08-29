<?php
$episodes_text = '';
?>
<div class="programe-container">
  <?php foreach ($rows as $row) : ?>
    <div class="program-row">
      <div class="program-left">
        <?php if (isset($row['field_sponser_logo'])) : ?>
          <div class="programe-logo">
            <?php print $row['field_sponser_logo']; ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="program-right">
        <?php if (isset($row['field_cm_display_title'])) : ?>
          <div class="programe-title">
            <?php print $row['field_cm_display_title']; ?>
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
    <div class="heading">
      <?php
      $episodes_text = $row['name'];
      print t("<h3>Last episodes from " . $episodes_text . "</h3>");
      ?>
    </div>
    <?php print views_embed_view('programme_content', 'block', $row['tid']); ?>
  <?php endforeach; ?>
</div>
