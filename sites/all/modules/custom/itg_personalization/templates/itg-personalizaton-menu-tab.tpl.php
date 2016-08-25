<?php

/* 
 * @file
 *   Menu tab for personalized content. 
 */
?>
<ul class="personal-menu-tab">    
  <li class="saved-items"><a href="javascript:;"><?php print t('Saved Items'); ?></a></li>
  <li class="my-content"><a href="javascript:;"><?php print t('My Content'); ?></a></li>
  <li class="my-Preferences"><a href="javascript:;"><?php print t('My Preferences'); ?></a></li>
  <li class="following">
  <?php    
    echo l(t('Following'), 'itg-saved-content/author/nojs/', 
    array('attributes' => array('class' => array('use-ajax'))));
  ?>
  </li>    
  <li class="my-credits"><a href="javascript:;"><?php print t('My Credits'); ?></a></li>
  <li class="edit-profile"><a href="javascript:;"><?php print t('Edit Profile'); ?></a></li>
</ul>

