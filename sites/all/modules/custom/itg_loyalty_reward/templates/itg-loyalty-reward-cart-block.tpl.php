<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="cart-total">
    <?php print l(t('MY CART'), 'cart', array('attributes' => array('class' => array('button')))); ?>
    <span><?php print '(' . count($data) . ')'; ?></span>
</div>
