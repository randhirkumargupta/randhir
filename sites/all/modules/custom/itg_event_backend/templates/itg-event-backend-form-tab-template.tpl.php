<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
$step_first = '';
$step_second = '';
$step_program_schedule = '';
$step_sponsor = '';
$step_highlights = '';
$step_media = '';
$step_configuration = '';
if(isset($_SESSION['current_step'])){
  if($_SESSION['current_step'] == 'step_first'){
    $step_first = 'current';
  }elseif($_SESSION['current_step'] == 'step_second'){
    $step_second = 'current';
  }elseif($_SESSION['current_step'] == 'step_program_schedule'){
    $step_program_schedule = 'current';
  }elseif($_SESSION['current_step'] == 'step_sponsor'){
    $step_sponsor = 'current';
  }elseif($_SESSION['current_step'] == 'step_highlights'){
    $step_highlights = 'current';
  }elseif($_SESSION['current_step'] == 'step_media'){
    $step_media = 'current';
  }elseif($_SESSION['current_step'] == 'step_configuration'){
    $step_configuration = 'current';
  }
}
?>
<div class="block-itg-story-list">

<?php echo l(t('Basic Details'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_first'), 'attributes' => array('class' => array($step_first)))); ?>
<?php echo l(t('Registration Fees'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_second'), 'attributes' => array('class' => array($step_second)))); ?>
<?php echo l(t('Program Schedule'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_program_schedule'), 'attributes' => array('class' => array($step_program_schedule)))); ?>
<?php echo l(t('Sponsor'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_sponsor'), 'attributes' => array('class' => array($step_sponsor)))); ?>
<?php echo l(t('Highlights'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_highlights'), 'attributes' => array('class' => array($step_highlights)))); ?>
<?php echo l(t('Media'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_media'), 'attributes' => array('class' => array($step_media)))); ?>
<?php echo l(t('Configuration'), 'node/'.arg(1).'/edit', array('query' => array('step' => 'step_configuration'), 'attributes' => array('class' => array($step_configuration)))); ?>
</div>
