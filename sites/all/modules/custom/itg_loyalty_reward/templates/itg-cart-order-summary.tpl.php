<?php
/*
 * @file
 *   Cart order summary page template file. 
 */
?>

<div class="row">
  <div class="col-md-8">
    
  
<div class="cart-detail order-summary">
    <?php if (count($data['product_detail']) > 0): ?>
      <?php $cart_total = 0; ?>
      <?php foreach ($data['product_detail'] as $key => $cart_detail): ?>    
        
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
              <div class="prd-title"><?php print $cart_detail['product']['title']; ?></div> 
            <div class="cart-action">
                <?php $item_total = $cart_detail['product']['points'] * $cart_detail['quantity']; ?>
                <div class="cart-action-links">
                    <span>Item (<?php print $cart_detail['quantity']; ?>)</span>
                    <?php print l(t('Delete (X)'), 'cart/delete/' . 
                        $cart_detail['product']['nid'] . '/' . 
                        str_replace(' ', '_', strtolower($cart_detail['product']['title']) . 
                        '/' . $item_total), array('attributes' => array('class' => array('itg-remove-product')),'query' => array('destination' => arg(0)))); ?>
                </div>                
                <div class="points"><?php print $item_total . ' ' . t('Points'); ?></div>
            </div>
          </div>
        
        <?php $cart_total += $item_total; ?> 
      <?php endforeach; ?>
    
    <?php else: ?>
      <?php print t('There are no items in this cart.') ?>
      <?php print l('Continue Shopping', 'product', array('attributes' => array('class' => array('button')))); ?>
    <?php endif; ?>
  
   <?php if (count($data['product_detail']) > 0): ?>
    <div class="lhs-redeem-point">
      <div class="cart-total-block">
        <div class="cart-total-inner">
          <div class="grand-total"><strong>GRAND TOTAL</strong><strong><?php print $cart_total; ?> Points</strong></div>
          <div class="checkout"><?php print l(t('REDEEM POINTS'), 'place-order'); ?></div>
          <div class="points-balance"><span>Balance after redemption</span><span><?php print number_format($remain_point); ?> Points</span></div>
        </div>
      </div>  
    </div> 
  <?php endif; ?>
  
</div>
  </div>
  <div class="col-md-4">
    <?php if (count($data['product_detail']) > 0): ?>
      <div class="cart-total-block">
        <div class="cart-total-inner">
          <div class="grand-total"><strong>GRAND TOTAL</strong><strong><?php print $cart_total; ?> Points</strong></div>
          <div class="checkout"><?php print l(t('REDEEM POINTS'), 'place-order'); ?></div>
          <div class="points-balance"><span>Balance after redemption</span><span><?php print number_format($remain_point); ?> Points</span></div>
        </div>
      </div>
      
    <?php endif; ?>
      <div class="rhs-address">
      <div class="order-address-wrapper">
        <div class="order-address col-md-7">
            <h3>Address</h3>
            <address>
              <span><?php echo $data['user_detail']['name']; ?></span>
              <span><?php echo $data['user_detail']['mail']; ?></span>
              <span><?php echo $data['user_detail']['address']; ?></span>
              <span><?php echo $data['user_detail']['pincode']; ?></span>
            </address>
            
        </div>
        <div class="col-md-12">
          <div id="change-address"><?php echo t('Change Address') ?></div>
        </div>
      </div>
          
  <div class="sent-on-message">All the update regarding the order will be sent on <span><?php echo $data['user_detail']['mail']; ?></span></div>
  </div>
  <div class="itg-ads-block">
      <?php
        $block = module_invoke('itg_ads', 'block_view', 'ad_right_sidebar_1');      
        print render($block['content']);
      ?>
      </div>  
  
  </div>
</div>
<div id="change-address-popup">
  <div class="popup-inner">
    <a class="close-popup" href="javascript:;">
      <i class="fa fa-times" aria-hidden="true"></i>
    </a>

  <?php
    $block = module_invoke('itg_loyalty_reward', 'block_view', 'itg_loyalty_reward_address_form');
    print render($block['subject']);
    print render($block['content']);
  ?>
  </div>
</div>