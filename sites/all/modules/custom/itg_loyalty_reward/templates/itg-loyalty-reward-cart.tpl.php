<?php

/* 
 * @file
 *   Cart detail page template file. 
 */
?>
<div class="cart-detail">
    <?php foreach ($data as $key => $cart_detail): ?>
    <?php dpm($cart_detail); ?>
    <div class="row">
        <div class="cart-image">
          <?php 
            $product_pic = theme(
              'image_style',
              array(
                'style_name' => 'user_picture',
                'path' => $cart_detail['image']['uri'],
              )
            );
            print $product_pic;
          ?>
        </div>
        <div class="product-details">
            <span>Magzine ID: <?php print $cart_detail['nid']; ?></span>
            <span>Product Description: <?php print $cart_detail['description']; ?></span>
        </div>
        <div class="cart-action">
            <div class="cart-action-links">
                <span>Item (1)</span>
                <span><?php print l(t('Delete (X)'), 'cart/delete/' . $cart_detail['nid'], array('query' => array('destination' => arg(0)))); ?></span>
            </div>
            <div class="points"><?php print $cart_detail['points']; ?></div>
        </div>
    </div>
    <?php endforeach; ?>
</div>
