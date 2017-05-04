<?php
global $base_url;
foreach ($rows as $index => $row): ?>
  <div class="blog-row catagory-listing blog-nid-<?php print $row['nid'] ?>">
    
    <div class="pic blog-image-<?php print $key ?>">      
        <?php if ($row['field_story_extra_large_image'] == 'notFound') : ?>
          <?php
          $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt=''/>";
          print l($img, 'node/' . $row['nid'], array('html' => TRUE));
          ?>
        <?php else : ?>
          <?php print $row['field_story_extra_large_image']; ?>
        <?php endif; ?>      
    </div>

    <div class="detail">
      <span class="blog-anchor blog-title-<?php print $key ?>">
        <?php if (!empty($row['field_blog_bloggers'])) : ?>
          <?php print $row['field_blog_bloggers']; ?>
        <?php endif; ?>
      </span>
      
        <h3 title=" <?php print strip_tags($row['title']); ?>" class="blog-title blog-title-<?php print $key ?>">
        <?php if (!empty($row['title'])) : ?>
          <?php print $row['title']; ?>
        <?php endif; ?>
      </h3>
      

      <p class="blog-description blog-description-<?php print $key ?>">
        <?php if (!empty($row['field_common_short_description'])) : ?>
          <?php print $row['field_common_short_description']; ?>
        <?php endif; ?>
      </p>
      
    </div>
  </div>
<?php endforeach; ?>