<?php

/* 
 * @file
 *   Redeem points template file.
 */
?>
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
        <span>MY CART (3)</span>
        <span>2,000 POINTS LEFT</span>
    </div>
  </div>
 </div> 

