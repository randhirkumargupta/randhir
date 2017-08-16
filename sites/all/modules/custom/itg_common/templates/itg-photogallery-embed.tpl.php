<div class="itg-embed-wrapper">
  <h1 class="embed-title"><?php print $data->title; ?></h1>
  <div class="itg-embed-photo-wrapper">
    <div class="itg-embed-photo">
      <ul class="itg-embed-photo-slider">
        <?php
        foreach ($data->field_gallery_image['und'] as $index => $mega_item) {
          $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
          $byline_id = $ans_detail[$mega_item['value']]->field_images['und'][0]['uri'];
          ?>
          <li>
            <figure class="" data-img-fid=" <?php print $ans_detail[$mega_item['value']]->field_images['und'][0]['fid']; ?>">
              <img src=<?php print file_create_url($byline_id); ?> width="753" height="543" title="" alt="" />              
            </figure>
          </li>
        <?php } ?>
      </ul>
    </div>
    <div class="itg-embed-photo-thumb">
      <ul class="itg-embed-photo-thumb-slider">
        <?php
        foreach ($data->field_gallery_image['und'] as $index => $mega_item) {
          $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
          $byline_id = $ans_detail[$mega_item['value']]->field_images['und'][0]['uri'];
          ?>
          <li >
            <img src=<?php print file_create_url($byline_id); ?> width="88" height="66" title="" alt="" />
          </li>
<?php } ?>
      </ul>
    </div>
  </div>
</div>
