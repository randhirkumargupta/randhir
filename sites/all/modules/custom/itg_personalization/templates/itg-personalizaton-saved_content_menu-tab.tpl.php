<?php

/* 
 * @file
 *   Template file for personalized saved content. 
 */
?>
<ul class="saved-item-tab">
    <li class="active">
      <?php echo l(t('All')  , 'personalization/saved-items/all'); ?>
    </li>
    <li>
      <?php echo l(t('Articles')  , 'personalization/saved-items/articles'); ?>  
    </li>
    <li>
      <?php echo l(t('Videos')  , 'personalization/saved-items/videos'); ?>  
    </li>
    <li>
      <?php echo l(t('Photo Galleries')  , 'personalization/saved-items/photogalleries'); ?>  
    </li>    
</ul>
