<ul>
<?php foreach ($rows as $index => $row): ?>
  <li>
    <div class="row">
      <h2><?php print $row['title']; ?></h2>
      <div class="col-md-8">
        <figure>
          <?php print $row['field_images']; ?>
          <figcaption><?php print $row['field_photo_by']; ?></figcaption>
        </figure>
      </div>
      <div class="col-md-4">
        <div class="other-details">
          <div class="counter">
            <i class="fa fa-camera" aria-hidden="true"></i>
            <?php print $row['counter']; ?>
          </div>
          <div class="caption"><?php $row['field_image_caption']; ?></div>
        </div>
      </div>
    </div>
  </li>
<?php endforeach; ?>
</ul>

<ul>
<?php foreach ($rows as $index => $row): ?>
  <li>
    <?php print $row['field_images_1']; ?>
  </li>
<?php endforeach; ?>
</ul>

