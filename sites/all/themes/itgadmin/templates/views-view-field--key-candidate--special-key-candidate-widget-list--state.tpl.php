<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */?>
<?php
$nid = $row->nid;
$term_data = taxonomy_term_load($row->itg_widget_order_state);
print $term_data->name;
?>
