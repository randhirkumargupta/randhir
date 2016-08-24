<?php

/* 
 * @file
 *   Menu tab for personalized content. 
 */
?>
<ul class="personal-menu-tab">    
    <li><?php print t('Saved Content'); ?></li>
    <li><?php print t('My Content'); ?></li>
    <li><?php print t('My Preferences'); ?></li>
    <li>
    <?php    
      echo l(t('Following'), 'itg-saved-content/author/nojs/', 
      array('attributes' => array('class' => array('use-ajax'))));
    ?>
    </li>    
    <li><?php print t('My Credits'); ?></li>
    <li><?php print t('Edit Profile'); ?></li>
</ul>

