<?php

/* 
 * @file
 *   Template file for personalized saved content. 
 */
?>
<?php $arg = arg(); ?>
<ul class="saved-item-tab">
    <li>
      <?php 
        if ($arg[1] == 'saved-items' && !isset($arg[2])) {
          echo l(t('All')  , 'personalization/saved-items/all',
              array('attributes' => array('class' => array('active'))));
        }
        else {
          echo l(t('All')  , 'personalization/saved-items/all');
        }
      ?>      
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
