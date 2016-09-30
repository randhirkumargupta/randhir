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
        <div id="my-cart-items">          
          <?php
            $block = module_invoke('itg_loyalty_reward', 'block_view', 'itg_cart_block');
            print render($block['content']);
          ?>                      
        </div>
        <div id="my-remaining-points">          
          <span>1234</span>
          POINTS LEFT
        </div>
    </div>
  </div>
 </div> 

