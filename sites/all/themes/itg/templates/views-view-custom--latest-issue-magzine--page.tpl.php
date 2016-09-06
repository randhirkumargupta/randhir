<?php foreach ($rows as $index => $row): ?>
  <div class="issue-image"><?php print $row['field_issue_large_cover_image']; ?></div>
  <div class="issue-title"><?php print $row['field_issue_title']; ?></div>
  <div class="issue-subscribe-link"><?php print $row['nothing']; ?></div>
  <div class="next-issue-out"><span class="text">Next issue out on </span><span class="issue-next-date"><?php print itg_msi_next_week_issue(); ?></span></div>
    <?php
    $issue_attribute_date = strip_tags($row['field_issue_title_1']);
    print views_embed_view('magazine_top_story', 'block_1', $issue_attribute_date);
    ?>
    <?php print views_embed_view('magazine_top_story', 'block', $issue_attribute_date);
    ?>

<?php endforeach; ?>