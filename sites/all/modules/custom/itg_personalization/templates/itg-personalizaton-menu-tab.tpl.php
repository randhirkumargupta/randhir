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
  <?php    
    echo l(t('Following'), 'itg-saved-content/author/nojs/', 
    array('attributes' => array('class' => array('use-ajax'))));
  ?>
  </li>    
  <li class="my-credits"><a href="javascript:;"><?php print t('My Credits'); ?></a></li>
  <li class="edit-profile"><a href="javascript:;"><?php print t('Edit Profile'); ?></a></li>
</ul>

