<?php

/**
 * Function to delete flooded node from itg_widget_order table
 */
function itg_remove_flooded_nodes(){
  _delete_old_data_from_section_widget('itg_widget_order', 1206533, 'All');
}