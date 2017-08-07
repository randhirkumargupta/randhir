<?php
global $base_url;
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php ?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php foreach ($rows as $id => $row): 
  $video_class ="";
  if($row['type'] == 'videogallery') {
     $video_class = 'video-icon';
  }  
  // Check if it is sponsor category.
  $is_sponsor = _is_sponsored_category(arg(2));  
  ?>
  <div class="catagory-listing">
	<!-- If sponsor category then show big image of first row. -->
    <?php if(($is_sponsor) && ($id == 0)): ?>
      <div class="big-pic <?php echo $video_class;?> ">
        <?php if ($row['field_story_extra_large_image_1'] != ''): ?>        
          <?php print $row['field_story_extra_large_image_1']; ?>
        <?php else: ?>
          <!-- If large image not found then show big default image. -->
          <?php $image_link = "<img width='647' height='363'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image647x363.jpg' alt='' />"; ?>
            <?php print l($image_link, "node/" . $row['nid'], array("html" => true)); ?>
          <?php endif; ?>
          <div class="cat-heading">
              <h3 class="cat-heading-title" title="<?php echo strip_tags($row['title']);?>"><?php
                if (function_exists('itg_common_get_smiley_title')) {
                  print l(itg_common_get_smiley_title($row['nid'], 0, 100), "node/" . $row['nid'], array("html" => TRUE));
                }
                else {
                  print l(strip_tags(mb_strimwidth($row['title'], 0, 120, "..")), "node/" . $row['nid']);
                }
                ?></h3>
          </div>
      </div>
    <?php else: ?>
    <div class="pic <?php echo $video_class;?> ">
  <?php if ($row['field_story_small_image'] != ''): ?>
    <?php print $row['field_story_small_image']; ?>
  <?php else: ?>
        <?php if ($row['type'] == 'videogallery'): ?>
          <?php $image_link = "<img width='170' height='127'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' />"; ?>
        <?php else: ?>
          <?php $image_link = "<img width='170' height='127'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' />"; ?>
          <?php print l($image_link, "node/" . $row['nid'], array("html" => true)); ?>
        <?php endif; ?>    
      <?php endif; ?>
      <?php if(!empty($row['field_video_duration'])) { ?>
            <figcaption><i class="fa fa-play-circle"></i> <?php print $row['field_video_duration']; ?></figcaption>
      <?php } ?>
    </div>
    <div class="detail"><h3 title="<?php echo strip_tags($row['title']);?>"><?php
      if (function_exists('itg_common_get_smiley_title')) {
        print l(itg_common_get_smiley_title($row['nid'], 0, 100), "node/" . $row['nid'], array("html" => TRUE));
      }
      else {
        print l(strip_tags(mb_strimwidth($row['title'], 0, 120, "..")), "node/" . $row['nid']);
      }
      ?></h3>
        <?php if (strtolower($row['type']) == 'story'): ?>
        <p><?php if (isset($row['field_story_kicker_text'])) {
        print strip_tags($row['field_story_kicker_text']);
      } ?></p>
      <?php
      elseif ($row['type'] == 'photogallery'): ?>
        <p><?php if(!empty($row['field_gallery_kicer'])) { print strip_tags($row['field_gallery_kicer']); }?></p>
      <?php elseif ($row['type'] == 'photogallery'): ?>
        <p><?php print strip_tags($row['field_story_expert_description']); ?></p>
      <?php endif; ?>
      <?php
      if (!empty($row['field_video_kicker'])) {
        print '<p>' . strip_tags($row['field_video_kicker']) . '</p>';
      }
      ?>            </div>
      <?php endif; ?>
  </div>
<?php endforeach; ?>
