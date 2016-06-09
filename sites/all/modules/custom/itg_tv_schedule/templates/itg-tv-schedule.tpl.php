<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
?>
<ul>
<?php foreach($output as $val): ?>

    <li>
     <?php print $val['time']; ?>   
     <?php print $val['day']; ?>   
     <?php print $val['program']; ?>   
    </li>    

<?php endforeach; ?>
</ul>