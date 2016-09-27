<?php foreach($rows as $index => $row): ?>
	<?php foreach($row as $index => $field): ?>
		<?php print $field . '<br />'; ?>
	<?php endforeach; ?>
	<?php print '<br />'; ?>
<?php endforeach; ?>