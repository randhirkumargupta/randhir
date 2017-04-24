<?php
/**
 * Manage Ads page 
 */
?>
  <h2 class="ads-title"> <?php print isset($data['title']) ? $data['title'] : ''; ?> </h2>
  <div class="ads-top"> 
    <?php
   foreach ($data['code']['Super Banner (Top Nav) 728x90'] as $ads_chunk) {
      print '<div class="ads-header-code-holder">';
      print '<div class="ads-header-code-holder-device">';
      //print ucfirst($ads_chunk['device']);
      print '</div>';
      print '<div class="ads-header-code-holder-code">';
      print $ads_chunk['code'];
      print '</div>';
      print '</div>';
    }
    ?> 
  </div>

   <div class="ads-rhs1"> 
    <?php
   foreach ($data['code']['Medium Rectangle-RHS1-300x250'] as $ads_chunk) {
      print '<div class="ads-header-code-holder">';
      print '<div class="ads-header-code-holder-device">';
      //print ucfirst($ads_chunk['device']);
      print '</div>';
      print '<div class="ads-header-code-holder-code">';
      print $ads_chunk['code'];
      print '</div>';
      print '</div>';
    }
    ?> 
  </div>
  
    <div class="ads-rhs2"> 
    <?php
   foreach ($data['code']['Medium Rectangle-RHS2-300x250'] as $ads_chunk) {
      print '<div class="ads-header-code-holder">';
      print '<div class="ads-header-code-holder-device">';
      //print ucfirst($ads_chunk['device']);
      print '</div>';
      print '<div class="ads-header-code-holder-code">';
      print $ads_chunk['code'];
      print '</div>';
      print '</div>';
    }
    ?> 
  </div>
  
 
    <div class="ads-bottom"> 
    <?php
   foreach ($data['code']['Super Banner (Bottom nav) 728x90'] as $ads_chunk) {
      print '<div class="ads-header-code-holder">';
      print '<div class="ads-header-code-holder-device">';
      //print ucfirst($ads_chunk['device']);
      print '</div>';
      print '<div class="ads-header-code-holder-code">';
      print $ads_chunk['code'];
      print '</div>';
      print '</div>';
    }
    ?> 
  </div>
  
 
  
    <div class="ads-page-pusher"> 
    <?php
   foreach ($data['code']['Page pusher 1x1'] as $ads_chunk) {
      print '<div class="ads-header-code-holder">';
      print '<div class="ads-header-code-holder-device">';
      //print ucfirst($ads_chunk['device']);
      print '</div>';
      print '<div class="ads-header-code-holder-code">';
      print $ads_chunk['code'];
      print '</div>';
      print '</div>';
    }
    ?> 
  </div>
  
   <div class="ads-overlay"> 
    <?php
   foreach ($data['code']['Overlay 1x1'] as $ads_chunk) {
      print '<div class="ads-header-code-holder">';
      print '<div class="ads-header-code-holder-device">';
      //print ucfirst($ads_chunk['device']);
      print '</div>';
      print '<div class="ads-header-code-holder-code">';
      print $ads_chunk['code'];
      print '</div>';
      print '</div>';
    }
    ?> 
  </div>
  
  
