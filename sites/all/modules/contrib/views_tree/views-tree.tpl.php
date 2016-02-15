<?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
<?php endif; ?>

<div class="tree-items">
<?php $max = count($rows); $count = 0; ?>
<?php foreach ($rows as $id => $row): $count++; ?>
  <div id="ti-<?php print $row['pid']; ?>" class="tree-item<?php print intval($row['count']) > 0 ? " tree-closed" : " tree-leaf"; ?><?php print ($count >= $max) ? " tree-last" : "";?>">
    <div class="tree-collapse tree-icon"> 
    	
    </div>
    <div class="tree-inner">
      <?php print $row['data']; ?>
    </div>    
    <div class="tree-placeholder" style="clear:both"></div>
  </div>
<?php endforeach; ?>
</div>