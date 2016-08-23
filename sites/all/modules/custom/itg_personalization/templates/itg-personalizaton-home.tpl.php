<?php

/* 
 * @file
 *   Template file for personalized content home page.
 */
?>
<div class="personalized-user-area">
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

