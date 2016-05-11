<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */

?>
<div class="block-itg-story-list">

<?php echo l(t('Basic Details'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_first'))); ?>
<?php echo l(t('Registration Fees'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_second'))); ?>
  <?php echo l(t('Program Schedule'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_program_schedule'))); ?>
<?php echo l(t('Sponsor'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_sponsor'))); ?>
<?php echo l(t('Highlights'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_highlights'))); ?>
<?php echo l(t('Media'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_media'))); ?>
<?php echo l(t('Configuration'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_configuration'))); ?>
</div>
