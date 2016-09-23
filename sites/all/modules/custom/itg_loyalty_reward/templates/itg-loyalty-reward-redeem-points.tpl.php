<?php

/* 
 * @file
 *   Redeem points template file.
 */
?>
<?php //p($data); ?>
<div class="personalized-wrapper">
  <div class="personalized-user-area">
    <div class="personalized-user">
      <div class="user-pic">
      <?php print $data['profile_pic']; ?>
      </div>
      <div class="user-name">
        <?php print $data['full_name']; ?>
      </div>
      <div class="logout-link">
        <?php print $data['logout']; ?>
      </div>
    </div>  
    <div class="personalized-user-info">
        <div id="my-cart-items">
          <?php print l(t('MY CART'), 'cart', array('attributes' => array('class' => array('button')))); ?>
          <span>0</span>
        </div>
        <div id="my-remaining-points">          
          <span></span>
          POINTS LEFT
        </div>
    </div>
  </div>
 </div> 

