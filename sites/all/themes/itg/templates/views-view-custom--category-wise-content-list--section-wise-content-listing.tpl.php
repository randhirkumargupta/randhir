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
  <h1><?php print $title; ?></h1>
<?php endif; ?>

<?php foreach ($rows as $id => $row):
  // code for add on story title and url
  if (function_exists('itg_common_get_addontitle_for_view')) {
    $add_on_data = itg_common_get_addontitle_for_view($row['nid']);
    $pipelinetext = "";
    $pipelineclass = "";
    if (!empty($add_on_data['ad_title']) && !empty($add_on_data['ad_url'])) {
      $pipelinetext = ' <span class="add-on-story-pipline">|</span> <a target="_blank" href="' . $add_on_data['ad_url'] . '" title="' . $add_on_data['ad_title'] . '">' . ucfirst($add_on_data['ad_title']) . '</a>';
      $pipelineclass = ' pipeline-added';
    }
  }
  $video_class ="";
  if($row['type'] == 'Video' || $row['type'] == 'videogallery') {
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
          <?php print l($row['field_story_extra_large_image_1'], "node/" . $row['nid'], array("html" => true)); ?>
        <?php else: ?>
          <!-- If large image not found then show big default image. -->
          <?php $image_link = "<img width='647' height='363'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image_770x432.jpg' alt='' title='' />"; ?>
            <?php print l($image_link, "node/" . $row['nid'], array("html" => true)); ?>
          <?php endif; ?>
          <div class="cat-heading">
              <h2 class="<?php echo $pipelineclass; ?> cat-heading-title" title="<?php echo strip_tags($row['title']);?>"><?php
                if (function_exists('itg_common_get_smiley_title')) {
                  print l(itg_common_get_smiley_title($row['nid'], 0, 100), "node/" . $row['nid'], array("html" => TRUE));
                  echo $pipelinetext;
                }
                else {
                  print l(strip_tags(mb_strimwidth($row['title'], 0, 120, "..")), "node/" . $row['nid']);
                  echo $pipelinetext;
                  
                }
                ?></h2>
          </div>
      </div>
    <?php else: ?>
    <?php if (arg(2) !== variable_get('pti_section_id', 1206640)) : ?>
    <div class="pic <?php echo $video_class;?> ">
      <?php if ($row['field_story_small_image'] != ''): ?>
        <?php print $row['field_story_small_image']; ?>
      <?php else: ?>
            <?php if ($row['type'] == 'Video' || $row['type'] == 'videogallery'): ?>
              <?php $image_link = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />"; ?>
            <?php else: ?>
              <?php $image_link = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />"; ?>
              <?php print l($image_link, "node/" . $row['nid'], array("html" => true)); ?>
            <?php endif; ?>    
          <?php endif; ?>
          <?php if(!empty($row['field_video_duration'])) { ?>
                <figcaption><i class="fa fa-play-circle"></i> <?php print $row['field_video_duration']; ?></figcaption>
          <?php } ?>
        </div>
    <?php endif; ?>
    <div class="detail"><h2 class="<?php echo $pipelineclass; ?>" title="<?php echo strip_tags($row['title']);?>"><?php
      if (function_exists('itg_common_get_smiley_title')) {
        print l(itg_common_get_smiley_title($row['nid'], 0, 100), "node/" . $row['nid'], array("html" => TRUE));
        echo $pipelinetext;
        
      }
      else {
        print l(__html_output_with_tags($row['title']), "node/" . $row['nid']);
        echo $pipelinetext;
      }
      ?></h2>
        <?php if (strtolower($row['type']) == 'story'): ?>
        <p><?php if (isset($row['field_story_kicker_text'])) {
        print __html_output_with_tags($row['field_story_kicker_text']);
      } ?></p>
      <?php
      elseif ($row['type'] == 'photogallery'): ?> 
        <p><?php print __html_output_with_tags($row['field_story_expert_description']); ?></p>
      <?php endif; ?>
      <?php
      if (!empty($row['field_video_kicker'])) {
        print '<p>' . __html_output_with_tags($row['field_video_kicker']) . '</p>';
      }
      ?>            </div>
      <?php endif; ?>
  </div>
<?php endforeach; ?>
