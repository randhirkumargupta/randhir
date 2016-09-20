<?php // pr($form) ?>
  <h2>Log in</h2>
  <div class="login-wrapper">
    <?php print drupal_render($form['name']); ?>
    <?php print drupal_render($form['pass']); ?>
      <?php print drupal_render($form['remember_me']); ?>
    <div class="form-actions">
      <?php print drupal_render($form['actions']['submit']); ?>
      <?php print l('Forgot Password?','user/password', array('attributes' => array('class' => 'forgot-link'))); ?>
    </div>
    <?php print drupal_render_children($form) ?>
    
  </div>