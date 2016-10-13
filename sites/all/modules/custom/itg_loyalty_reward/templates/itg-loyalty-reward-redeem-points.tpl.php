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
          <span><?php print empty($data['remaining_point']) ? 0 : $data['remaining_point']; ?></span> POINTS LEFT
        </li>
    </ul>
    <div>
      <?php if ($data['item_after'] != 0): ?>
        <?php 
          $product_pic = theme(
            'image_style', array(
              'style_name' => 'user_picture',
              'path' => $data['item_after']['image']['uri'],
            )
          );
          // Print product Image.
          echo $product_pic;
          // Print title of the product.
          echo $data['item_after']['title'];
          // Print statis message.
          echo '<span> has been added to your cart</span>';
          // Print points.
          echo $data['item_after']['points'] . 'POINTS REDEEM';
          // Print link to cart page.
          print l(t('VIEW CART'), 'cart');
          unset($_SESSION['cart_after_popup']);
        ?>
      <?php endif; ?>
    </div>    
 </div> 

