<?php if (!empty($data)) : global $base_url; ?>
  <div class="how-made-it">
    <ul>
      <?php foreach ($data as $key => $entity) {
         
        ?>
        <li class="" id="dont-miss-<?php print $key ?>">
          <?php if (!empty($entity['esi_file_uri'])) { ?>
            <span class="dm-pic">
              <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$entity['nid']}") ?>">
                <?php $file_uri = file_create_url($entity['esi_file_uri']); ?>
                <img src="<?php print $file_uri; ?>" alt="<?php echo $entity['field_story_extra_small_image_alt'];?>" title="<?php echo $entity['field_story_extra_small_image_title'];?>" />
              </a>
            </span>
            <?php
          }
          else {
            ?>
            <span class="dm-pic">
              <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$entity['nid']}") ?>">
                <img height="66" width="88" src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg'); ?>/images/itg_image88x66.jpg" alt="" />
              </a>
            </span>
          <?php } ?>

          <span class="dm-detail">

            <?php if (!empty($entity['extra'])) : ?>
              <p class="title"><?php print $entity['extra']; ?></p>
            <?php endif; ?>

            <?php if (!empty($entity['title'])) : ?> 

              <p title="<?php echo $desc;?>">
                <?php
                $desc = $entity['title'];
                if (function_exists('itg_common_get_smiley_title')) {
                  echo l(itg_common_get_smiley_title($entity['nid'], 0, 70), "node/" . $entity['nid'], array('html' => TRUE));
                }
                else {
                  echo l(mb_strimwidth($desc, 0, 70, ".."), "node/" . $entity['nid']);
                }
                ?>
              </p>           
            <?php endif; ?>

          </span>
          <span class="more"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$entity['nid']}") ?>">More[+]</a></span>
        </li>
      <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>