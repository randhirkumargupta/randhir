<?php

/* 
 * @file
 *   Redeem points template file.
 */
?>
<div class="container">
    <div class="cart-user">
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
    <ul class="header-cart">
        <li id="my-cart-items">          
          <?php
            $block = module_invoke('itg_loyalty_reward', 'block_view', 'itg_cart_block');
            print render($block['content']);
          ?>                      
        </li>
        <li id="my-remaining-points">          
          <span>1234</span> POINTS LEFT
        </li>
    </ul>
 </div> 

