<?php

/* 
 * @file
 *   Template file for personalized saved content. 
 */
?>
<ul class="saved-item-tab">
    <li class="active">
    <?php 
    echo l(t('All')  , 'itg-saved-content/all/nojs/', 
      array('attributes' => array('class' => array('use-ajax'))));
    ?>
    </li>
    <li>
    <?php 
    echo l(t('Articles')  , 'itg-saved-content/articles/nojs/', 
      array('attributes' => array('class' => array('use-ajax'))));
    ?>  
    </li>
    <li>
    <?php 
    echo l(t('Videos')  , 'itg-saved-content/videos/nojs/', 
      array('attributes' => array('class' => array('use-ajax'))));
    ?>  
    </li>
    <li>
    <?php 
    echo l(t('Photo Galleries')  , 'itg-saved-content/photogallery/nojs/', 
      array('attributes' => array('class' => array('use-ajax'))));
    ?>  
    </li>    
</ul>
