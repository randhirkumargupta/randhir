<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function itg_election_block_refresh(){
  $arg = arg();
  if (!empty($arg[1]) && !empty($arg[2]) && !empty($arg[3]) ) {
    if(!empty($arg[4])){
      $_GET['offset'] = $arg[4];
    }
    $_GET['section'] = $arg[3];
    $block = block_load($arg[1], $arg[2]);
    $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
    echo render($render_array);
    drupal_exit();
  }
}

function itg_election_view_block_refresh(){
  $arg = arg();
  if (!empty($arg[1]) && !empty($arg[2]) && !empty($arg[3]) ) {
    $_GET['section'] = $arg[3];
    print views_embed_view($arg[1], $arg[2]);
    drupal_exit();
  }
}
