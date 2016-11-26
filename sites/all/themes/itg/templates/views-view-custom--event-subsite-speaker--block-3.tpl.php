<?php foreach ($rows as $row): ?>

    <div class="image-wrap">  
    <?php print $row['field_sponser_logo']; ?>
  </div>
  
    <h3><?php print $row['title']; ?></h3>
    <div class="body-content"><?php print $row['body']; ?></div>
 
<?php endforeach; ?>
