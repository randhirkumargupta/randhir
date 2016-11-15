<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


$nid = $row->nid;

?>

Lead&nbsp;<input type="radio" name="node-<?php print $nid ?>" value="Lead" <?php echo ($row->itg_widget_order_extra=='Lead')?'checked':'';?>>
Win&nbsp;<input type="radio" name="node-<?php print $nid ?>" value="Win" <?php echo ($row->itg_widget_order_extra=='Win')?'checked':'';?>>
Lost&nbsp;<input type="radio" name="node-<?php print $nid ?>" value="Lost" <?php echo ($row->itg_widget_order_extra=='Lost')?'checked':'';?>>