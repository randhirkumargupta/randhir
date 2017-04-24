<?php foreach ($rows as $row): ?>
  <?php if (!empty($row['view'])): ?>
    <div class="col-md-3 col-sm-4 col-xs-6"><?php print $row['view']; ?></div>
  <?php endif; ?>
<?php endforeach; ?>
