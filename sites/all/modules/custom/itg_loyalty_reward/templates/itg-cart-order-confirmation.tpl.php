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
            <div class="cart-row">
                <div class="cart-checkout-list">
                    <div>
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
                    <div>
                        <div><?php print $cart_detail['product']['title']; ?></div>       
                        <div>Quantity (<?php print $cart_detail['quantity']; ?>)</div>       
                    </div>
                    <div>Standard Delivery by Mon, 3rd Oct</div>
                    <?php $item_total = $cart_detail['product']['points'] * $cart_detail['quantity']; ?>
                    <?php $cart_total += $item_total; ?>
                    <div>
                      <?php echo $item_total; ?>
                    </div>
                      
                </div>
            </div>
            <?php endforeach; ?>
            <?php unset($_SESSION['placed-item']); ?>
        </div>
    </div>
</div>

