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
      <?php if (isset($data['badge_detail']['earn']) && $data['badge_detail']['earn'] > 1): ?>
      <div class="total-point-wrapper">
        <!-- Total Points -->        
        <div class="total-points">
            <span class="total-point-value">
                <?php print t('TOTAL POINTS'); ?>
                <span><?php print $data['badge_detail']['total']; ?></span>
            </span>
          <?php print render($data['badge_detail']['badge_icon']); ?>
        </div>
        <div class="pregress-bar">            
            <span class="current-badge"><small><?php print $data['badge_detail']['earn']; ?></small>Current Level</span>
            <span class="pregress-bar-active"></span>
            <span class="next-badge"><small><?php print $data['badge_detail']['next']; ?></small>Next Level</span>
        </div>
        <div class="points-to-go">
          <?php print '<span>'.$data['badge_detail']['points_to_go'] . '</span> ' . t('Points to go'); ?>
        </div>
      </div>
      <?php endif; ?>
  </div>
 </div> 

