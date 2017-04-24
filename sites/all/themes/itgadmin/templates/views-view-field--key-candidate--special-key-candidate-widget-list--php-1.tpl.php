<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$nid = $row->nid.'-'.$row->itg_widget_order_cat_id.'-'.$row->itg_widget_order_state;

?>
<div class="key-radio-field"><input type="radio" class="key-radio" name="node-<?php print $nid ?>" value="Lead" <?php echo ($row->itg_widget_order_extra=='Lead')?'checked':'';?>> <label>Leading</label></div>
<div class="key-radio-field"><input type="radio" class="key-radio" name="node-<?php print $nid ?>" value="Win" <?php echo ($row->itg_widget_order_extra=='Win')?'checked':'';?>> <label>Won</label></div>
<div class="key-radio-field"><input type="radio" class="key-radio" name="node-<?php print $nid ?>" value="Lost" <?php echo ($row->itg_widget_order_extra=='Lost')?'checked':'';?>> <label>Lost</label></div>