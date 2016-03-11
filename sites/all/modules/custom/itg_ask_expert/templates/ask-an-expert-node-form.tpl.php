<?php
/**
 * @file
 * Theme implementation for Ask an expert form display.
 * 
 */
 
?>
<?php if(isset($_SESSION['ask_an_expert_message'] )): ?>
 <div id='success' class="success-message">
<?php print $_SESSION['ask_an_expert_message'];
 unset($_SESSION['ask_an_expert_message']);
?>
</div>
<?php endif; ?>
 <?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
