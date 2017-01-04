<?php
global $base_url;
$anchor = $rows[0];
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$fb_title = strip_tags(addslashes($anchor['title']));
$image = '';
?>
<div class="anchor-landing">
  <div class="anchor">
    <div class="anchor-left">
      <?php
      if (isset($anchor['field_story_extra_large_image'])) {
        echo $anchor['field_story_extra_large_image'];
      }
      else {
        ?>
        <img width="370" height="208" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
      <?php } ?>
    </div>
    <div class="anchor-right">
      <?php echo $anchor['title']; ?>
      <div class="less-content">
        <?php 
          echo mb_strimwidth(strip_tags($anchor['body']), 0, 245, ".."); 
          $share_desc = mb_strimwidth(strip_tags($anchor['body']), 0, 245, "..");
        ?>
        <?php if (strlen($anchor['body']) > 245) { ?>
          <a href="javascript:void(0)" class="anchor-action read-more"> More[+]</a>
        </div>
        <div class="full-content" style="display: none">
          <?php echo $anchor['body']; ?>
          <a href="#" class="anchor-action read-less"> Less[-]</a>
        <?php } ?>
      </div>  
      <div class="social-icon">
        <ul>                
          <li>
            <a href="javascript:" onclick="twitter_popup('<?php print urlencode($fb_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>
          </li>
          <li>
            <a onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a>
          </li>
        </ul>
      </div>
    </div>
  </div>
</div>