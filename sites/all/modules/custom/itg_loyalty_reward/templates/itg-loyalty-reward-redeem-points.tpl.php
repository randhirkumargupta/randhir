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
    </div>  
    <ul class="header-cart">        
        <li id="my-cart-items"> 
          <?php
            $block = module_invoke('itg_loyalty_reward', 'block_view', 'itg_cart_block');
            print render($block['content']);
          ?> 
          <?php if ($data['item_after'] != 0): ?>
          <div class="cart-dropdown">
            <span class="cart-dropdown-close"><i class="fa fa-times" aria-hidden="true"></i></span>
              <?php 
                $product_pic = theme(
                  'image_style', array(
                    'style_name' => 'user_picture',
                    'path' => $data['item_after']['image']['uri'],
                  )
                ); 
              ?>
              <div class="cart-dropdown-pic">
                <?php  
                // Print product Image.
                echo $product_pic;
                // Print title of the product.
                ?>
              </div>
              <div class="cart-dropdown-details">
                <div class="cart-dropdown-title">  
                  <?php echo $data['item_after']['title']; ?>
                </div>
                <?php
                // Print statis message.
                echo '<span class="cart-dropdown-added"> has been added to your cart</span>';
                ?>
                <div class="btn-redeem-points no-loader">
                <?php
                // Print points.
                echo $data['item_after']['points'] . ' POINTS REDEEMED';
                ?>
                </div>
              </div>
              <div class="cart-dropdown-view-cart">
                <?php
                // Print link to cart page.
                print l(t('VIEW CART'), 'cart'); 
                ?>
              </div>  
                <?php
                unset($_SESSION['cart_after_popup']);
               ?>
            
          </div>
          <?php endif; ?>
        </li>
        <li id="my-remaining-points">          
          <span><?php print empty($data['remaining_point']) ? 0 : $data['remaining_point']; ?></span> POINTS LEFT
        </li>
        <li class="my-history-link"><?php print l(t('MY HISTORY'), 'order'); ?></li>
    </ul>
        
 </div> 

