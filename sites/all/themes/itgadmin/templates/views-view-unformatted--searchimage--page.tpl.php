<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


 if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
  <div class="search-img-list">
<?php foreach ($rows as $id => $row){
  if(trim($row) !=""){ ?>
  
    <?php print $row; ?>
 

  <?php  } } ?> </div>
