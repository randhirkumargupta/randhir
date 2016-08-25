<?php

/* 
 * @file
 *   Template file for personalized content home page.
 */
?>
<div class="personalized-wrapper">
  <div class="personalized-user-area">
    <div class="personalized-user">
      <div class="user-pic">
      <?php print $data['profile_pic']; ?>
      </div>
      <div class="user-name">
        <?php print $data['full_name']; ?>
      </div>
      <div class="logout-link">
        <?php print $data['logout']; ?>
      </div>
    </div>  
    <div class="personalized-user-info">
      <span>
        <i class="fa fa-share" aria-hidden="true"></i>
        <dfn>235</dfn>
      </span>
      <span>
        <i class="fa fa-share-alt" aria-hidden="true"></i>
        <dfn>2536</dfn>
      </span>
      <span>
        <i class="fa fa-comment" aria-hidden="true"></i>
        <dfn>852</dfn>
      </span>
      <span>
        <i class="fa fa-bookmark" aria-hidden="true"></i>
        <dfn>55</dfn>
      </span>
      <span>
        <i class="fa fa-user" aria-hidden="true"></i>
        <dfn>26</dfn>
      </span>
    </div>
  </div>
 </div> 

