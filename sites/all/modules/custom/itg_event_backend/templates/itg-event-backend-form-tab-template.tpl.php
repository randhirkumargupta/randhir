<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */

?>
<div class="block-itg-story-list">
<?php echo l(t('Basic Details'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_first'))); ?>
<?php echo l(t('Registration, Sponsor'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_second'))); ?>
<?php echo l(t('Program Schedule'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_program_schedule'))); ?>
<?php echo l(t('Highlights, Media, Configuration'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_last'))); ?>

</div>
