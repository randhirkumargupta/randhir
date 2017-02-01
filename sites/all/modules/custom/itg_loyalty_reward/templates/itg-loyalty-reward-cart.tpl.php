<?php
/*
 * @file
 *   Cart detail page template file. 
 */
?>
<div class="cart-detail shopping-cart">
    <?php if (count($data) > 0): ?>
      <?php $cart_total = 0; ?>
      <?php foreach ($data as $key => $cart_detail): ?> 
            <div class="cart-checkout-list">
                <div class="cart-image">
                    <?php
                    $product_pic = theme(
                        'image_style', array(
                      'style_name' => 'cart_172x240',
                      'path' => $cart_detail['product']['image']['uri'],
                        )
                    );
                    print $product_pic;
                    ?>
                </div>
                <div class="product-details">
                    <div><span>Title:</span><strong><?php print $cart_detail['product']['title']; ?></strong></div>
                    <div><span>Magzine ID:</span><strong><?php print $cart_detail['product']['nid']; ?></strong></div>              
                </div>
                <div class="cart-action">
                    <?php $item_total = $cart_detail['product']['points'] * $cart_detail['quantity']; ?>
                    <div class="cart-action-links">
                        <!-- <span>Item (<?php print $cart_detail['quantity']; ?>)</span> -->
                        <span>
                            Item 
                            <select name="quantity">
                                <?php
                                $node_id = $cart_detail['product']['nid'];
                                for ($i = 1; $i <= 10; ++$i) {
                                  // Encode original node id.                                  
                                  if ($cart_detail['quantity'] == $i) {
                                    echo '<option value="' . $node_id . '-'. $i . '" selected="selected">' . $i . '</option>';
                                  }
                                  else {
                                    echo '<option value="' . $node_id . '-'. $i . '">' . $i . '</option>';
                                  }
                                }
                                ?>
                            </select>
                            
                        </span>
                        <?php
                        print l(t('Delete (X)'), 'cart/delete/' .
                                $cart_detail['product']['nid'] . '/' .
                                str_replace(' ', '_', strtolower($cart_detail['product']['title']) .
                                    '/' . $item_total), array('attributes' => array('class' => array('itg-remove-product')), 'query' => array('destination' => arg(0))));
                        ?>
                    </div>                
                    <div class="points"><?php print $item_total . ' ' . t('Points'); ?></div>
                </div>
            </div>
    <?php $cart_total += $item_total; ?> 
  <?php endforeach; ?>
      <div class="cart-total-block">
          <div class="cart-total-inner">
              <div class="grand-total"><strong>GRAND TOTAL</strong><strong><?php print $cart_total; ?> Points</strong></div>
              <div class="checkout"><?php print l(t('REDEEM POINTS'), 'order-summary'); ?></div>
              <div class="points-balance"><span>Balance after redemption</span><span><?php print number_format($remain_point); ?> Points</span></div>
              <div class="continue-shopping"><?php print l('Continue Shopping', 'product'); ?></div>
          </div>
      </div>
    <?php else: ?>
      <?php print t('There are no items in this cart.') ?>
  <?php print l('Continue Shopping', 'product', array('attributes' => array('class' => array('button')))); ?>
<?php endif; ?>
</div>
