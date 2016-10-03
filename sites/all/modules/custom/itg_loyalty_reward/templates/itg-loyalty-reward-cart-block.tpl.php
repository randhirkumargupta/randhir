<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="cart-total">
    <?php print l(t('<i class="fa fa-shopping-cart" aria-hidden="true"></i> MY CART'), 'cart', array('html'=> true)); ?>
    <span><?php print '(' . $data . ')'; ?></span>
</div>
