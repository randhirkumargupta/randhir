
<?php
print 'fff';
pr(arg());
pr(menu_get_object());
die;
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

foreach($rows as $index => $row): 
  //p($rows);
  ?>
	<?php foreach($row as $index => $field): ?>
		<?php print $field . '<br />'; ?>
	<?php endforeach; ?>
	<?php print '<br />'; ?>
<?php endforeach; ?>