<?php

/* 
 * @file
 *   Menu tab for personalized content. 
 */
?>
<?php $arg = arg(); ?>
<ul class="personal-menu-tab">    
  <li class="saved-items">   
  <?php 
    if ($arg[1] == 'saved-items' && isset($arg[2])) {
      echo l(t('Saved Items')  , 'personalization/saved-items', 
          array('attributes' => array('class' => array('active'))));
    }
    else {
      echo l(t('Saved Items')  , 'personalization/saved-items');
    }    
  ?>  
  </li>
  <li class="my-content">      
  <?php echo l(t('My Content')  , 'personalization/my-content'); ?>
  </li>
  <li class="my-Preferences">      
  <?php echo l(t('My Preferences'), 'personalization/my-preferences'); ?>    
  </li>
  <li class="following">
  <?php echo l(t('Following'), 'personalization/my-following'); ?>
  </li>    
  <li class="my-credits">
    <?php echo l(t('My Credits'), 'personalization/my-credits'); ?>      
  </li>
  <li class="edit-profile">
      <?php echo l(t('Edit Profile'), 'personalization/edit-profile/general-settings'); ?>      
  </li>
</ul>

