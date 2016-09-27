<?php
/*
 * @file
 *   Cart detail page template file. 
 */
?>
<div class="cart-detail">
    <?php if (count($data) > 0): ?>
      <?php $cart_total = 0; ?>
      <?php foreach ($data as $key => $cart_detail): ?>    
        <div class="row">
            <div class="cart-image">
                <?php
                $product_pic = theme(
                    'image_style', array(
                  'style_name' => 'magazine_rhs_100x140',
                  'path' => $cart_detail['image']['uri'],
                    )
                );
                print $product_pic;
                ?>
            </div>
            <div class="product-details">
                <span>Title: <?php print $cart_detail['title']; ?></span>
                <span>Magzine ID: <?php print $cart_detail['nid']; ?></span>                
            </div>
            <div class="cart-action">
                <div class="cart-action-links">
                    <span>Item (1)</span>
                    <span><?php print l(t('Delete (X)'), 'cart/delete/' . $cart_detail['nid'] . '/' . $cart_detail['title'], array('query' => array('destination' => arg(0)))); ?></span>
                </div>
                <div class="points"><?php print $cart_detail['points'] . t('Points'); ?></div>
            </div>
        </div>
        <?php $cart_total += $cart_detail['points']; ?> 
      <?php endforeach; ?>
      <div class="cart-total-block">
          <div class="grand-total">GRAND TOTAL <span><?php print $cart_total; ?> Points</span></div>
          <div class="checkout"><?php print l(t('REDEEM POINTS'), 'checkout'); ?></div>
          <div class="points-balance">Balance after redemption <span>2,000 Points</span>
      </div>
    <?php else: ?>
      <?php print t('There are no items in this cart.') ?>
      <?php print l('Continue Shopping', 'redeem-points', array('attributes' => array('class' => array('button')))); ?>
    <?php endif; ?>
</div>
