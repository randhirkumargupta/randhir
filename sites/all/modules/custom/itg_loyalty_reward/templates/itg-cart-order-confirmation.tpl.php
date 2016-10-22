<?php
/*
 * @file
 *   Order confirmation template file. 
 */
?>
<div class="order-confirmation">
    <div class="thankyou-block">
        <h2>Thank you for your order</h2>
        <p>Your order has been processed. Once the item is shipped, you will 
            receive an email with details.
        </p>
    </div>
    <div class="order-summary-block">
        <h3>Your order summary</h3>
        <div class="order-id">Order id: <span><?php print 12345; ?></span></div>
        <div class="order-detail">            
            <?php $cart_total = 0; ?>
            <?php foreach ($_SESSION['placed-item'] as $cart_detail): ?>
                <div class="cart-checkout-list">
                  <div class="col-md-4">
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
                    <div class="cart-details">
                        <h4><?php print $cart_detail['product']['title']; ?></h4>       
                        <span>Quantity (<?php print $cart_detail['quantity']; ?>)</span>       
                    </div>
                  </div>
                  <div class="col-md-5">
                    <div class="delivery-by">Standard delivery time is 5-7 business days.</div>
                  </div>  
                    <?php $item_total = $cart_detail['product']['points'] * $cart_detail['quantity']; ?>
                    <?php $cart_total += $item_total; ?>
                  <div class="col-md-3">
                    <div class="total-points"><?php echo $item_total; ?></div>
                  </div>
                </div>
            <?php endforeach; ?>
            <?php unset($_SESSION['placed-item']); ?>
        </div>
    </div>
</div>

