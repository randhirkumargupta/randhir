<?php
global $base_url;
foreach ($rows as $index => $row): ?>
  <div class="blog-row blog-nid-<?php print $row['nid'] ?>">
    
    <div class="pic">
      <div class="blog-image blog-image-<?php print $key ?>">
        <?php if ($row['field_story_extra_large_image'] == 'notFound') : ?>
          <?php
          $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />";
          print l($img, 'node/' . $row['nid'], array('html' => TRUE));
          ?>
        <?php else : ?>
          <?php print $row['field_story_extra_large_image']; ?>
        <?php endif; ?>
      </div>
    </div>

    <div class="details">
      <div class="blog-title blog-title-<?php print $key ?>">
        <?php if (!empty($row['field_blog_bloggers'])) : ?>
          <?php print $row['field_blog_bloggers']; ?>
        <?php endif; ?>
      </div>
      
      <div class="blog-title blog-title-<?php print $key ?>">
        <?php if (!empty($row['title'])) : ?>
          <?php print $row['title']; ?>
        <?php endif; ?>
      </div>
      

      <div class="blog-description blog-description-<?php print $key ?>">
        <?php if (!empty($row['field_blog_long_description'])) : ?>
          <?php print $row['field_blog_long_description']; ?>
        <?php endif; ?>
      </div>
      
    </div>
  </div>
<?php endforeach; ?>