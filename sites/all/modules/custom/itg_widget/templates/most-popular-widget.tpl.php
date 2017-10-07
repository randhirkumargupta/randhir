<?php if (!empty($data)) : global $base_url; ?>
  <ul class="itg-listing">
    <?php
    foreach ($data as $entity) {
      if (!empty($entity['title'])) :
        ?>
        <li title="<?php echo $entity['title'];  ?>" class="most-popular-<?php print $entity['nid'] ?>">
          <?php
          if (_is_sponsor_story_article($entity['nid'])):?>
            <span class="itg-sponsor-title"><?php print t('SPONSORED'); ?></span>
          <?php 
          endif; ?>
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 110), "node/" . $entity['nid'], array("html" => TRUE , 'attributes' => array("title" => $entity['title'])));
          }
          else {
            echo l(mb_strimwidth($entity['title'], 0, 110, ".."), "node/" . $entity['nid'] , array('attributes' => array("title" => $entity['title'])));
          }
          ?>
        </li>
      <?php endif; ?>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
