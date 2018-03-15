<ul class="photo-list">
  <?php foreach ($rows as $index => $row): ?>
    <?php
    if(!empty($row['field_story_small_image'])){
    $img = $row['field_story_small_image'];
    }else{
      global $base_url;
      $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
    }
    //$section_cat_id = $row['field_story_category'];
    ?>
    <li class="col-md-3">
      <div class="tile">
        <figure>
          
          <?php
          /*if (isset($_GET['category'])) {
           // print l($img, 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id), 'html' => TRUE));
            print l($img, 'node/' . $row['nid'], array('html' => TRUE));
          }
          else {
            print l($img, 'node/' . $row['nid'], array('html' => TRUE));
          }*/
          print l($img, 'node/' . $row['nid'], array('html' => TRUE));
          ?>
          <figcaption><i class="fa fa-play-circle" ></i> <?php print $row['field_video_duration']; ?></figcaption>

        </figure>

        <span class="posted-on"><?php print $row['created']; ?></span>
        <p title="<?php print strip_tags($row['title']); ?>">       
 <?php
        /*if (isset($_GET['category'])) {
          print html_entity_decode(l($row['title'], 'node/' . $row['nid'], array('query' => array('category' => $section_cat_id))));
        }
        else {
          print html_entity_decode(l($row['title'], 'node/' . $row['nid']));
        }*/
        print html_entity_decode(l($row['title'], 'node/' . $row['nid']));
        ?>
        </p>
      </div>
    </li>
<?php endforeach; ?>
</ul>


