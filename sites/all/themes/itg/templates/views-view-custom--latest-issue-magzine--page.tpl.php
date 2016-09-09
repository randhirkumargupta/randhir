<div class="magazin-lhs-top">
  <?php foreach ($rows as $index => $row): ?>
    <div class="magazin-top">
      <div class="magazin-top-left">
        <span class="web-excl">web exclusive</span>
        <?php
        $issue_attribute_date = strip_tags($row['field_issue_title_1']);
        print views_embed_view('magazine_top_story', 'block_1', $issue_attribute_date);
        ?>
      </div>


      <div class="magazin-subscribe">
        <span class="latest-issue">latest issue</span>
        <div class="issue-image"><?php print $row['field_issue_large_cover_image']; ?></div>
        <div class="issue-title"><?php print $row['field_issue_title']; ?></div>
        <?php
        $current_issues = itg_msi_get_current_issue();
        $current_issue = explode(' 00:', $current_issues);
        ?>
        <?php if ($current_issue[0] == $issue_attribute_date): ?>
          <div class="issue-subscribe-link"><?php print $row['nothing']; ?></div>
        <?php endif; ?>
        <div class="next-issue-out"><span class="text">Next issue out on </span><span class="issue-next-date"><?php print itg_msi_next_week_issue(); ?></span></div>
      </div>
    </div>

    <div class="magazin-bottom">
      <?php print views_embed_view('magazine_top_story', 'block', $issue_attribute_date); ?>
    </div>
  <?php endforeach; ?>
</div>